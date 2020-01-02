#define YY_NO_UNISTD_H 1
#include "Misc.hpp"

#include "parser.hpp"
#include "lexer.hpp"
#include <iostream>
#include <sstream>

bool enable_grammar_debug = false;
bool enable_testing = false;
bool integrated_debug = false;

std::stringstream last_calls_stream;
std::stringstream parents_stream;

//DOCS: Parse a string with a provided context
//Note: Make sure ParseState is initialized (previous errors have been cleared)
void scompile(ParseState* parseState, const char* source){
	yyscan_t scanner;

	if (yylex_init_extra(parseState, &scanner))
	{
		parseState->hasError = 1;
		parseState->errorMessage = "Internal error: Lexer failed to initialize.";
		return;
	}

	YY_BUFFER_STATE state = yy_scan_string(source, scanner);

	yydebug = integrated_debug;

	bool parsingFailed = yyparse(parseState, scanner) > 0;

	if(parseState->hasError == 0 && parsingFailed)
	{
		parseState->hasError = 1;
		parseState->errorMessage = "Internal error: Parsing failed.";
		parseState->errorLine = -1;
		parseState->errorColumn = -1;
	}

	yy_delete_buffer(state, scanner);
	yylex_destroy(scanner);
}

//DOCS: Parse a string with a provided context
//Note: Make sure ParseState is initialized (previous errors have been cleared)
void fcompile(ParseState* parseState, FILE* source) {
	yyscan_t scanner;

	if (yylex_init_extra(parseState, &scanner))
	{
		parseState->hasError = 1;
		parseState->errorMessage = "Internal error: Lexer failed to initialize.";
		return;
	}

	yydebug = integrated_debug;

	yyset_in(source, scanner);
	bool parsingFailed = yyparse(parseState, scanner) > 0;

	if (parseState->hasError == 0 && parsingFailed)
	{
		parseState->hasError = 1;
		parseState->errorMessage = "Internal error: Parsing failed.";
		parseState->errorLine = -1;
		parseState->errorColumn = -1;
	}
	
	yylex_destroy(scanner);
}

void output_result(ParseState& parse_state, std::string test_description = "", int entry_line = 0, bool should_fail = false)
{
	auto pass = [&](const char* str)
	{
		set_console_color(10);
		std::cout << str;
		set_console_color(7);
		std::cout << test_description.c_str() << std::endl;
	};

	auto fail = [&](const char* str)
	{
		/*if (enable_grammar_debug)
		{
			std::cout << "===\nRULE STACK\n===\n" << last_calls_stream.str() << std::endl;
			std::cout << "===\nNON-TERMINAL STACK\n===\n" << parents_stream.str() << std::endl;
		}*/
		set_console_color(12);
		std::cout << str;
		set_console_color(7);
		std::cout << test_description.c_str() << std::endl;
	};

	auto warn = [&](const char* str)
	{
		/*if (enable_grammar_debug)
		{
			std::cout << "===\nRULE STACK\n===\n" << last_calls_stream.str() << std::endl;
			std::cout << "===\nNON-TERMINAL STACK\n===\n" << parents_stream.str() << std::endl;
		}*/
		set_console_color(14);
		std::cout << str;
		set_console_color(7);
		std::cout << test_description.c_str() << std::endl;
	};

	if (should_fail)
	{
		if (parse_state.hasError == 0)
		{
			fail("[PASSES]");
		}
		else
		{
			if (parse_state.errorMessage == "syntax is ambiguous")
			{
				warn("[WARN]");
			}
			else
			{
				pass("[FAILS]");
			}

			std::cout << "Error: " << parse_state.errorMessage << " line " << entry_line + parse_state.errorLine << " column " << parse_state.errorColumn << " : " << parse_state.errorToken << std::endl;
		}
	}
	else
	{
		if (parse_state.hasError == 0)
		{
			pass("[PASS]");
		}
		else
		{
			if (parse_state.errorMessage == "syntax is ambiguous")
			{
				warn("[WARN]");
			}
			else
			{
				fail("[FAIL]");
			}

			std::cout << "Error: " << parse_state.errorMessage << " line " << entry_line + parse_state.errorLine << " column " << parse_state.errorColumn << " : " << parse_state.errorToken << std::endl;
		}
	}
}

int main(int argc, char** argv){

	//Test variables
	std::string test_description;

	//Text control variables
	int scan_lines = 0;
	int entry_line = 1;
	int scan_position = 0;

	//Program options variables
	bool scan_str = false;
	int string_idx = 0;

	if (argc < 2)
	{
		std::cout << "Arguments not provided" << std::endl;
		std::cout << "--test or /test for running on a test file" << std::endl;
		std::cout << "-s or /s \"string\" for parsing a string" << std::endl;
		std::cout << "-v or /v for enabling debug info" << std::endl;
#ifdef _WIN32
		system("pause");
#endif
		return 0;
	}

	//Check program parameters
	for (int i = 1; i < argc; ++i)
	{
		if (std::string(argv[i]) == "-v" || std::string(argv[i]) == "/v")
		{
			enable_grammar_debug = true;
		}

		if (std::string(argv[i]) == "--test" || std::string(argv[i]) == "/test")
		{
			enable_testing = true;
		}

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

			scan_str = true;
			string_idx = i + 1;
		}

		if (std::string(argv[i]) == "-d" || std::string(argv[i]) == "/d")
		{
			integrated_debug = true;
		}
	}

	//Scan string
	if (scan_str)
	{
		ParseState parse_state;
		
		scompile(&parse_state, argv[string_idx]);
		
		if (enable_grammar_debug)
		{
			std::cout << "===\nRULE STACK\n===\n" << last_calls_stream.str() << std::endl;
			std::cout << "===\nNON-TERMINAL STACK\n===\n" << parents_stream.str() << std::endl;
		}

		output_result(parse_state);
		
#ifdef _WIN32
		system("pause");
#endif
		return 0;
	}

	//Or scan from file
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
			char* n_ptr = strstr(t_ptr + 6 + should_fail * 13, ":");
			if (not n_ptr)
				break;
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
			ParseState parse_state;
			scompile(&parse_state, scan_buff);

			delete[] scan_buff;

			output_result(parse_state, test_description, entry_line, should_fail);
		}
	}
	else { //Single run on file

		ParseState parse_state;
		fcompile(&parse_state, f);
		
		if (parse_state.hasError == 0 && enable_grammar_debug)
		{
			std::cout << "===\nRULE STACK\n===\n" << last_calls_stream.str() << std::endl;
			std::cout << "===\nNON-TERMINAL STACK\n===\n" << parents_stream.str() << std::endl;
		}

		output_result(parse_state);
	}

#ifdef _WIN32
	system("pause");
#endif
	fclose(f);
	
	return 1;
}
