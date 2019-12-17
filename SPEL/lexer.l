%option noyywrap

%{
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>

#include "parser.h"

//Test variables
extern std::string test_description;

//Text control variables
extern int scan_lines;
extern int entry_line;
extern char* yytext;

static void update_loc();

static int curr_line = 1;
static int curr_col = 1;

#define YY_USER_ACTION update_loc(); 
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
}

//Resets yylex context to buffer
void yyswitch(char* str, unsigned size)
{
	curr_line = 1;
	curr_col = 1;
	auto bs = yy_scan_buffer(str, size);
	yy_switch_to_buffer(bs);
}

void yyerror(const char* msg)
{
	std::cout << "[Error]: " << msg << " line " << entry_line + yylloc.first_line << " column " << yylloc.first_column << " : " << yytext << std::endl;
}
