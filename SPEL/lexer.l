%option noyywrap

%{
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>

#include "parser.h"

//Test variables
extern std::string test_description;
extern int test_state;
extern int NO_TEST;
extern int TEST_STARTED;
extern int TEST_ENDED;

//Text control variables
extern bool ended_input;
extern int scan_position;
extern int yycolumn;
extern char* yytext;

static void update_loc();
#define YY_USER_ACTION update_loc();
%}

%x test

%%

[.\n] { //If we are not testing, enter code section automatically
#ifndef TESTER_DEBUG
	static bool passed_here = false;
	if (not passed_here)
	{
		yyless(1);
		passed_here = true;
	}
	BEGIN(test);
#endif
}

<test>"/*"(.|\n)+"*/" ;
<test>"public" {return PUBLIC; }
<test>"private" {return PRIVATE; }
<test>"protected" {return PROTECTED; }
<test>"int" {return INT; }
<test>"float" {return FLOAT; }
<test>"char" {return CHAR; }
<test>"class" {return CLASS; }
<test>"return" {return RET; }
<test>"::" {return DBLP; }
<test>[A-Za-z][A-Za-z0-9]* { return ID; }
<test>[1-9][0-9]*|0 {return NR; }
<test>([1-9][0-9]*\.[0-9]+)|(0\.[0-9]+) { return NRF; }
<test>[ \t\n] ;
<test>. {return yytext[0]; }

\[TEST\].*\n { //If found this token, test context starts
	test_description = yytext;
	test_description[test_description.size() ? test_description.size() - 1 : 0] = '\0';
	test_state = TEST_STARTED;
	BEGIN(test); 
}
<test>\[END\] { //If found this token we exit the lexer
	test_state = TEST_ENDED;
	BEGIN(INITIAL);
	return 0;
}
(.|\n) ;

<<EOF>> {test_state = NO_TEST; ended_input = true; return 0; }

%%

// Runs at every action - updates line & col
static void update_loc() {
	static int curr_line = 1;
	static int curr_col = 1;

	yylloc.first_line = curr_line;
	yylloc.first_column = curr_col;

	{char * s; for (s = yytext; *s != '\0'; s++) {
		if (*s == '\n') {
			curr_line++;
			curr_col = 1;
		}
		else {
			curr_col++;
		}
	}}

	yylloc.last_line = curr_line;
	yylloc.last_column = curr_col - 1;

	yycolumn = curr_col - 1;
}

//resets yylex context
int yyseek(long offset)
{
	yy_flush_buffer(YY_CURRENT_BUFFER);
	return(fseek(yyin, offset, 0));
}

void yyerror(const char* msg)
{
	std::cout << "[Error]: " << msg << " line " << yylloc.last_line << " column " << yylloc.last_column << " : ";
	std::cout << yytext << std::endl;
}