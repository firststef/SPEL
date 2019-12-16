#include <iostream>

#include "parser.h"
#include <vector>
#include <regex>
#include <fstream>

//INPUT VARIABLES
#ifdef _WIN32
extern FILE* yyin;
#endif

//Unit testing variables
extern std::string test_description;
extern int test_state;
extern int NO_TEST;
extern int TEST_STARTED;
extern int TEST_ENDED;

//Unit testing functions
#ifdef _WIN32
extern void set_console_color(int color);
#endif

//Text control variables
extern int yylineno;
extern int scan_lines;
extern bool ended_input;
extern int scan_position;
extern int yycolumn;

//Text control functions
extern void yyswitch(char* str, unsigned size);
extern void yyerror(const char*);

int main(int argc, char** argv)
{
#ifndef TESTER_DEBUG //If not testing, run normally
	yyin = fopen(argv[1], "r");
	const auto parse_result = yyparse();
	fclose(yyin);
#else //If testing check for [TEST] + [END] structures

	FILE *f = fopen(argv[1], "r");
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);  /* same as rewind(f); */

	std::vector<char> buff;
	buff.resize(fsize);
	char* data_ptr = &buff.front();

	fread(data_ptr, 1, fsize, f);
	
	while (true) {		
		fseek(f, scan_position, SEEK_SET);

		bool found_t_e = false;
		int t_pos = 0;
		int e_pos = 0;

		char buffer[200] = { 0 };
		while (fgets(buffer, 200, f) != nullptr)
		{
			fpos_t p;
			fgetpos(f, &p);
			
			if (memcmp(buffer, "[TEST]", 6) == 0)
			{
				found_t_e = true;
				test_description = buffer + 6;
				test_description[not test_description.empty() ? test_description.size() - 1 : 0] = '\0';

				scan_lines++;
				t_pos = p - 1;

				char check[6];
				bool found_e = false;
				while (fread(check, 1, 5, f) == 5)
				{
					
					if (memcmp(check, "[END]", 5) == 0)
					{
						found_e = true;
						break;
					}
					fseek(f, -4, SEEK_CUR);
				}
				if (found_e)
				{
					found_t_e = true;
					fgetpos(f, &p);
					e_pos = p - 9;
					scan_position = p;
				}
				
				break;
			}
		}

		if (found_t_e)
		{
			int buf_size = e_pos - t_pos;
			scan_position = e_pos;

			std::vector<char> scan_buff;
			scan_buff.resize(buf_size + 10);
			char* scan_ptr = &scan_buff.front();
			memcpy(scan_ptr, data_ptr + t_pos, buf_size);
			(scan_ptr)[buf_size] = 0;
			(scan_ptr)[buf_size + 1] = 0;

			yyswitch(scan_ptr, buf_size + 2);
			auto parse_result = yyparse();
				
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
		else
			break;
	}
#endif
	
	system("pause");
	return 1;
}