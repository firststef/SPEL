%option noyywrap

%{
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>

#define YYSTYPE char*

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

extern YYSTYPE yylval;
#define YY_USER_ACTION update_loc(); yylval=_strdup(yytext);
%}

INTEGER			-?([1-9][0-9]*|0)
FLOAT           ([1-9][0-9]*|0)\.[0-9]+
IDENTIFIER		[a-zA-Z][_a-zA-Z0-9]*
STRING			\"[^\"\n]*\"
CHAR			"'"(\\)?."'"
SPACE			[ \t]
ENDLINE			[\r\n]
WS				[ \r\n\t]*
SINGLEWS		[ \r\n\t]
COMMENT			\/\/[^\n]*
MULTICOMMENT	"/*"(.|\n)*"*/"

%x comment

%%

"The tale begins\n" {return BGNP; }

 /* Default Types */
points {return INT; }
precise {return FLOAT;}
rune {return CHAR; }
tome {return STRING; }
absolute {return BOOL; }

artifact { return CONST; }

 /* Values */
true {return TRUE; }
false {return FALSE; }
{CHAR} {return CHR; }
{STRING} {return STR; }

 /* Operators */
"<=" {return LEQ; }
">=" {return BEQ; }
"==" {return EQ; }
"!=" {return NEQ; }
"&&" {return AND; }
"||" {return OR; }
not {return NOT; }

 /* Functions and classes */
void {return VOID;}
"I summon thy name" {return CLASS; }
"and thy brethren." {return ENDCLASS; }

 /* Language specific*/
of {return OF; }
spell {return BGNF; }
terminus {return ENDF; }
cast {return RET; }
sacrifice {return SACRF;}
time {return TIME; }
in {return IN; }
craft {return CRAFT; }
bestow {return BSTOW; }
enchant {return ENCH; }
chant {return CHNT; }
with {return WITH; }

 /* Loops */
if {return IF; }
else {return ELSE; }
while {return WHILE; }
beginif {return BEGINIF; }
endif {return ENDIF; }
beginelse {return BEGINELSE;}
endelse {return ENDELSE; }
endwhile {return ENDWHILE; }
endfor {return ENDFOR; }
for {return FOR; }

EVAL {return EVAL; }

{IDENTIFIER} { return ID; }
{INTEGER} {return NR; }
{FLOAT} {return NRF; }

 /* Consume the rest */
{COMMENT} { }
{MULTICOMMENT} { }
[ \t\n\r] { }
. {return yytext[0]; }

<<EOF>> { //If found this token we exit the lexer
	BEGIN(INITIAL);
	return 0;
}
%%

YY_BUFFER_STATE last_buffer = nullptr;

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
	last_buffer = bs;
}

void yydelete() {
	yy_delete_buffer(last_buffer);
}

void scan_string(char* str) {
	auto bs = yy_scan_string(str);
	last_buffer = bs;
}

void yyerror(const char* msg)
{
	std::cout << "[Error]: " << msg << " line " << entry_line + yylloc.first_line << " column " << yylloc.first_column << " : " << yytext << std::endl;
}
