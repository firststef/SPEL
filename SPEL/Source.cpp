#include <iostream>
#include "parser.h"
#include <vector>
#include <sstream>

//INPUT VARIABLES
extern FILE* yyin;

//Unit testing variables
extern bool enable_testing;
extern std::string test_description;

//Unit testing functions
extern void set_console_color(int color);

//Debug variables
extern bool enable_grammar_debug;
extern std::stringstream last_calls_stream;
extern std::stringstream parents_stream;

//Text control variables
extern int scan_lines;
extern int entry_line;
extern int scan_position;

//Text control functions
extern void yyswitch(char* str, unsigned size);
extern void yyerror(const char*);
extern void scan_string(char* str);
extern void yydelete();

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Arguments not provided" << std::endl;
		std::cout << "-t or /t for running on a test file" << std::endl;		std::cout << "-s or /s \"string\" for parsing a string" << std::endl;
		std::cout << "-v or /v for enabling debug info" << std::endl;
		#ifdef _WIN32
		system("pause");
#endif
		return 0;
	}

	//Check program parameters
	for (int i = 1; i < argc; ++i)
	{
		if (std::string(argv[i]) == "-s" || std::string(argv[i]) == "/s")
		{
			if (i == argc - 1)
			{
				std::cout << "String from input not found" << std::endl;
#ifdef _WIN32
				system("pause");
#endif
				return -1;
			}

			scan_string(argv[i + 1]);
			yyparse();
#ifdef _WIN32
			system("pause");
#endif
			return 0;
		}

		if (std::string(argv[i]) == "-v" || std::string(argv[i]) == "/v")
		{
			enable_grammar_debug = true;
		}

		if (std::string(argv[i]) == "-t" || std::string(argv[i]) == "/t")
		{
			enable_testing = true;
		}
	}

	FILE *f = fopen(argv[1], "r");

	if (f == nullptr)
	{
		std::cout << "File not found" << std::endl;
#ifdef _WIN32
		system("pause");
#endif
		return -1;
	}

	if (enable_testing) //TESTING
	{
		//Reading entire test file in memory
		fseek(f, 0, SEEK_END);
		long fsize = ftell(f);
		fseek(f, 0, SEEK_SET);

		std::vector<char> buff;
		buff.resize(fsize);
		char* data_ptr = &buff.front();

		fread(data_ptr, 1, fsize, f);

		while (true) {
			fseek(f, scan_position, SEEK_SET);

			//We look for TEST sections and pass it to the parser
			char* t_ptr = nullptr;
			char* e_ptr = nullptr;
			t_ptr = strstr(data_ptr + scan_position, "[TEST]");
			if (not t_ptr)
				break;

			for (char* i_ptr = data_ptr + scan_position; i_ptr <= t_ptr; ++i_ptr)
			{
				if (*i_ptr == '\n')
				{
					scan_lines++;
				}
			}

			bool should_fail = false;
			if (memcmp(t_ptr + 6, "[SHOULD FAIL]", 13) == 0)
			{
				should_fail = true;
			}

			//Skip after TEST name and save name
			char buffer[200] = { 0 };
			char* n_ptr = strstr(t_ptr + should_fail * 13, "\n");
			if (not n_ptr)
				break;
			scan_lines++;
			entry_line = scan_lines;

			memcpy(buffer, t_ptr, n_ptr - t_ptr + 1);
			test_description = buffer + 6;
			test_description[not test_description.empty() ? test_description.size() - 1 : 0] = '\0';

			//Look for TEST END
			e_ptr = strstr(n_ptr + 1, "[END]");
			if (not e_ptr)
				break;
			for (char* i_ptr = n_ptr + 1; i_ptr <= e_ptr; ++i_ptr)
			{
				if (*i_ptr == '\n')
				{
					scan_lines++;
				}
			}
			scan_position = e_ptr - data_ptr;

			//Create buffer for lexer
			const auto buf_size = e_ptr - n_ptr - 1;

			auto scan_buff = new char[buf_size + 2];
			memcpy(scan_buff, n_ptr + 1, buf_size);
			scan_buff[buf_size] = 0;
			scan_buff[buf_size + 1] = 0;

			//Switch to buffer and parse()
			yyswitch(scan_buff, buf_size + 2);
			const auto parse_result = yyparse();
			yydelete();

			//delete[] scan_buff;

			//Output result
			if (should_fail and parse_result)
			{

				set_console_color(10);
				std::cout << "[FAILS]";
				set_console_color(7);
				std::cout << test_description.c_str() << std::endl;
			}
			else if (parse_result) {
				if (enable_grammar_debug)
				{
					std::cout << "===\nRULE STACK\n===\n" << last_calls_stream.str() << std::endl;
					std::cout << "===\nNON-TERMINAL STACK\n===\n" << parents_stream.str() << std::endl;
				}
				set_console_color(12);
				std::cout << "[FAIL]";
				set_console_color(7);
				std::cout << test_description.c_str() << std::endl;
			}
			else
			{
				set_console_color(10);
				std::cout << "[PASS]";
				set_console_color(7);
				std::cout << test_description.c_str() << std::endl;
			}
		}
	}
	else { //RUN ON FILE
		yyin = f;
		const auto parse_result = yyparse();
	}

#ifdef _WIN32
	system("pause");
#endif
	fclose(f);

	return 1;
}