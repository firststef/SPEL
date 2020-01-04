%{
#include "parser.hpp"

void update_loc(yyscan_t scanner);
#define YY_USER_ACTION update_loc(yyscanner);

int lineno;
int column;
#define YY_USER_INIT lineno = 1; column = 1;

void push_stack_context(yyscan_t scanner);
#define PUSH_STACK_CONTEXT push_stack_context(yyscanner);
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

"The tale begins." { PUSH_STACK_CONTEXT;  return BGNP; }

 /* Default Types */
points {return INT; }
precise {return FLOAT;}
rune {return CHAR; }
tome {return STRING; }
absolute {return BOOL; }

artifact { return CONST; }

 /* Values */
true { yylval->bool_val = new BoolVal({ true }); return TRUE; }
false { yylval->bool_val = new BoolVal({ false }); return FALSE; }
{CHAR} { yylval->char_val = new CharVal({ yytext[0] }); return CHR; }
{STRING} { yylval->string_val = new StringVal({ std::string(yytext,yyleng) }); return STR; }

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
"I summon thy name" { PUSH_STACK_CONTEXT; return CLASS; }
"and thy brethren." { return ENDCLASS; }

 /* Language specific*/
of {return OF; }
spell { PUSH_STACK_CONTEXT; return BGNF; }
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
if { PUSH_STACK_CONTEXT; return IF; }
else { PUSH_STACK_CONTEXT; return ELSE; }
while { PUSH_STACK_CONTEXT; return WHILE; }
endif {return ENDIF; }
endelse {return ENDELSE; }
endwhile {return ENDWHILE; }
endfor {return ENDFOR; }
for { PUSH_STACK_CONTEXT; return FOR; }

EVAL {return EVAL; }

{IDENTIFIER} {
	yylval->string_val = new StringVal({ std::string(yytext,yyleng) });
	return ID; 
}
{INTEGER} {
	std::string store(yytext, yyleng);
	yylval->int_val = new IntVal({ atoi(store.c_str()) });
	return NR; 
}
{FLOAT} {
	std::string store(yytext, yyleng);
	yylval->float_val = new FloatVal({ float(atof(store.c_str())) });
	return NRF; 
}

 /* Consume the rest */
{COMMENT} { }
{MULTICOMMENT} { }
[ \t\n\r] { }
. {return yytext[0]; }

%%

void update_loc(yyscan_t scanner) {
	
	struct yyguts_t * yyg = (struct yyguts_t*)scanner;

	yylloc->first_line = lineno;
	yylloc->first_column = column;

	{char * s; for (s = yytext; *s != '\0'; s++) {
		if (*s == '\n') {
			lineno++;
			column = 1;
		}
		else {
			column++;
		}
	}}

	yylloc->last_line = lineno;
	yylloc->last_column = column - 1;

	static std::string saved_token;
	saved_token = yytext;
	yylloc->last_token = saved_token.c_str();
}

void push_stack_context(yyscan_t scanner) {
	struct yyguts_t * yyg = (struct yyguts_t*)scanner;

	yyextra->stack.push_back(std::vector<std::shared_ptr<VariableDeclaration>>());

	int last_idx = -1;
	if (! yyextra->contextStack.empty()) {
		last_idx = yyextra->contextStack.top();
	}

	yyextra->contexts.push_back(Context{ "", last_idx, yyextra->contexts });
	yyextra->contextStack.push(yyextra->contexts.size() - 1);
}