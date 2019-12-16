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
static bool passed_here = false;

#ifdef TESTER_DEBUG
#define YY_USER_ACTION update_loc();
#else 
#define YY_USER_ACTION update_loc();
#endif
%}

%x test

%%

"//"(.)*\n ;
"/*"(.|\n)*"*/" ;
"int" {return INT; }
"float" {return FLOAT; }
"char" {return CHAR; }
"string" {return STRING; } 
"bool" {return BOOL; }
"'"(\\)?."'" {return CHR; }
\".*\" {return STR; } 	
"true" {return TRUE; }
"false" {return FALSE; }
"begin" {return BGNF; }	
"end"	{return ENDF; }	
"return" {return RET; }
"class" {return CLASS; }
"const" {return CONST; }
"if" {return IF; }
"else" {return ELSE; }
"while" {return WHILE; }
"endwhile" {return ENDWHILE; }
"endfor" {return ENDFOR; };
"for" {return FOR; }
[_A-Za-z][_A-Za-z0-9]* { return ID; }	
[1-9][0-9]*|0 {return NR; }
([1-9][0-9]*\.[0-9]+)|(0\.[0-9]+) {return NRF; }
[ \t] ;
\n {yylineno++;}
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