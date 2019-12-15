#include <iostream>

#include "parser.h"

//INPUT VARIABLES
extern FILE* yyin;

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
extern bool ended_input;
extern int scan_position;
extern int yycolumn;

//Text control functions
extern int yyseek(long);
extern void yyerror(const char*);

int main(int argc, char** argv)
{
	yyin = fopen(argv[1], "r");

#ifndef TESTER_DEBUG //If not testing, run normally
	yyparse();
#else //If testing check for [TEST] + [END] structures
	bool overall_test_result = true;
	int last_state = NO_TEST;
	while (not ended_input) {
		auto parse_result = yyparse();

		if (char(parse_result) == '\0')
			parse_result = 0;

		if (test_state == TEST_STARTED)
		{
			overall_test_result = true;
		}
		else if (test_state == TEST_ENDED) {
			overall_test_result *= (not parse_result);
			
			if (parse_result) {
#ifdef _WIN32
				set_console_color(12);
#endif
				std::cout << "[FAIL]";
#ifdef _WIN32
				set_console_color(7);
#endif
				std::cout << test_description.c_str() + 6 << std::endl;
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
				std::cout << test_description.c_str() + 6 << std::endl;
			}
			
		}
		else if (last_state != NO_TEST && test_state == NO_TEST)
		{
			char check[6];
			bool found = false;
			while (fread(check, 1, 6, yyin) == 6)
			{
				if(memcmp(check, "[TEST]", 6) == 0)
				{
					found = true;
					break;
				}
				fseek(yyin, -5, SEEK_CUR);
			}
			if (found)
			{
				fpos_t p;
				fgetpos(yyin, &p);
				scan_position = p;
				printf("%d", scan_position);
				yyseek(scan_position);
			}
			else
				break;
		}

		last_state = test_state;
	}
#endif
	
	system("pause");
	return 1;
}