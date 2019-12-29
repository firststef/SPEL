%{
#include "parser.hpp"

#define YY_USER_ACTION yylloc->first_column = yycolumn + 1; yylloc->first_line = yylineno + 1; yycolumn += (int)yyleng;
#define YY_USER_INIT yylineno = 0; yycolumn = 0;
%}

%option yylineno reentrant noyywrap nounistd bison-bridge bison-locations
%option outfile="lexer.cpp" header-file="lexer.hpp"
%option extra-type="struct ParseState *"

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

"The tale begins" {return BGNP; }

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
