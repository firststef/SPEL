#include <iostream>

#include "parser.h"
#include <vector>
#include <regex>

//INPUT VARIABLES
extern FILE* yyin;

//Unit testing variables
extern std::string test_description;

//Unit testing functions
#ifdef _WIN32
extern void set_console_color(int color);
#endif

//Text control variables
extern int scan_lines;
extern int entry_line;
extern int scan_position;

//Text control functions
extern void yyswitch(char* str, unsigned size);
extern void yyerror(const char*);

int main(int argc, char** argv)
{
#ifndef TESTER_DEBUG //If not testing, run normally
	yyin = fopen(argv[1], "r");
	const auto parse_result = yyparse();
	fclose(yyin);
#else //If testing, check for [TEST] + [END] structures

	FILE *f = fopen(argv[1], "r");
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);

	std::vector<char> buff;
	buff.resize(fsize);
	char* data_ptr = &buff.front();

	fread(data_ptr, 1, fsize, f);
	
	while (true) {		
		fseek(f, scan_position, SEEK_SET);

		//We look for TEST entry
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

		//Skip after TEST name and save name
		char buffer[200] = { 0 };
		char* n_ptr = strstr(t_ptr, "\n");
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
		const int buf_size = e_ptr - n_ptr - 1;

		std::vector<char> scan_buff{'\0'};
		scan_buff.resize(buf_size + 2);
		char* scan_ptr = &scan_buff.front();
		memcpy(scan_ptr, n_ptr + 1, buf_size);
		scan_buff[buf_size] = 0;
		scan_buff[buf_size + 1] = 0;

		//Switch to buffer and parse
		yyswitch(scan_ptr, buf_size + 2);
		auto parse_result = yyparse();

		//Output result
		if (parse_result) {
#ifdef _WIN32
			set_console_color(12);
#endif
			std::cout << "[FAIL]";
#ifdef _WIN32
			set_console_color(7);
#endif
			std::cout << test_description.c_str()<< std::endl;
		}
		else
		{
#ifdef _WIN32
			set_console_color(10);
#endif
			std::cout << "[PASS]";
#ifdef _WIN32
			set_console_color(7);
#endif
			std::cout << test_description.c_str() << std::endl;
		}
	}
	fclose(f);
#endif
	
	system("pause");
	return 1;
}