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
extern std::string syy_text;
extern int scan_lines;
extern int scan_position;
extern int yycolumn;
extern char* yytext;

static void update_loc();
static bool passed_here = false;

#define YY_USER_ACTION update_loc(); syy_text = yytext; scan_lines += std::count(syy_text.begin(), syy_text.end(), '\n'); ECHO;
%}

%x comment

%%

<<EOF>> { //If found this token we exit the lexer
	BEGIN(INITIAL);
	return 0;
}
"/*"(.|\n)+"*/" ;
"public" {return PUBLIC; }
"private" {return PRIVATE; }
"protected" {return PROTECTED; }
"int" {return INT; }
"float" {return FLOAT; }
"char" {return CHAR; }
"class" {return CLASS; }
"return" {return RET; }
"::" {return DBLP; }
[A-Za-z][A-Za-z0-9]* { return ID; }
[1-9][0-9]*|0 {return NR; }
([1-9][0-9]*\.[0-9]+)|(0\.[0-9]+) {return NRF; }
[ \t\n] ;
. {return yytext[0]; }

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
void yyswitch(char* str, unsigned size)
{
	auto bs = yy_scan_buffer(str, size);
	yy_switch_to_buffer(bs);
}

void yyerror(const char* msg)
{
	std::cout << "[Error]: " << msg << " line " << scan_lines << " column " << yylloc.last_column << " : ";
	std::cout << yytext << std::endl;
}