%{
#include "Parser.hpp"
#include "Lexer.hpp"
#define inline

void yyerror(YYLTYPE *locp, ParseState* parse_state, yyscan_t scanner, const char *msg);
%}

%code requires{

#include "Memory.hpp"

#include <string>

#define YY_NO_UNISTD_H 1
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
	typedef void* yyscan_t;
#endif

typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
  const char* last_token;
};
#define YYLTYPE_IS_DECLARED 1

#define YYLLOC_DEFAULT(Current, Rhs, N)																\
	do																								\
		if (N)																						\
		{																							\
			(Current).first_line = YYRHSLOC (Rhs, 1).first_line;									\
			(Current).first_column = YYRHSLOC (Rhs, 1).first_column;								\
			(Current).last_line = YYRHSLOC (Rhs, N).last_line;										\
			(Current).last_column = YYRHSLOC (Rhs, N).last_column;									\
			(Current).last_token = YYRHSLOC (Rhs, N).last_token;									\
		}																							\
		else																						\
		{																							\
			(Current).first_line = (Current).last_line = YYRHSLOC (Rhs, 0).last_line;				\
			(Current).first_column = (Current).last_column = YYRHSLOC (Rhs, 0).last_column;			\
			(Current).last_token = YYRHSLOC (Rhs, 0).last_token;									\
		}																							\
	while (0)

void print_rule(int num, char* s);
#define PRINT_RULE print_rule(__LINE__, nullptr);
}

%output  "parser.cpp"
%defines "parser.hpp"

%define api.pure
%locations
%lex-param { yyscan_t scanner }
%parse-param { ParseState* parse_state }
%parse-param { yyscan_t scanner }

%token LEQ BEQ EQ NEQ INT OF FLOAT CHAR STRING CHR NR NRF NOT ID
%token STR TRUE FALSE BGNF ENDF AND OR RET CLASS CONST BOOL ELSE IF
%token FOR WHILE ENDWHILE BEGINIF BEGINELSE ENDELSE ENDIF ENDFOR VOID
%token IN EVAL BG BGNP ENDCLASS CRAFT BSTOW ENCH WITH SACRF TIME CHNT
%nonassoc IFX
%nonassoc ELSE

%start spel

%left LEQ BEQ EQ NEQ '<' '>'
%left  '+'  '-'
%left  '*'  '/'  '%'
%left  UMINUS  /*  supplies  precedence  for  unary  minus  */

%union {
	Node* node;
	CompileUnit* c_unit;
	DeclarationHolder* dec_holder;
	ClassDefinition* class_def;
	IntVal* int_val;
	FloatVal* float_val;
	CharVal* char_val;
	StringVal* string_val;
	BoolVal* bool_val;
	VariableDeclaration* variable_dec;
	ComposedStatement* comp_stmt;
	Expression* expr;
	IterationSelectionStatement* iter_sel_stmt;
	Assignment* asgmt;
	FunctionDeclaration* func_decl;
	FunctionCall* func_call;
	Return* ret;
};

%%

spel
  : BGNP compile_unit { printf("Reached start symbol.\n"); }
  | BGNP { printf("Reached start symbol.\n"); }
  ;

compile_unit
  : class_def compile_unit
  | function_def compile_unit
  | statement compile_unit
  | class_def
  | function_def
  | statement
  ;

class_def
  : CLASS ID class_body ENDCLASS
  ;

class_body
  : declaration class_body
  | function_def class_body
  | declaration
  | function_def
  ;

declaration
  : CRAFT generic_type init_declarator_list '.'
  ;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator BSTOW initializer
	| declarator
	;

declarator
  : ID
  | ID '[' ']'
  | ID '[' NR ']'
  ;

initializer
  : '[' initializer_list ']'
  | value_expression
  ;

initializer_list
  : declarator BSTOW initializer ',' initializer_list
  | initializer ',' initializer_list
  | declarator BSTOW initializer
  | initializer
  ;

value_expression
  : NR
  | NRF
  | CHR
  | STR
  | TRUE
  | FALSE
  | CHNT ID SACRF call_parameters ':'
  | variable
  | eval_expr
  ;

eval_expr
  : expr
  | ENCH variable WITH expr
  ;

variable
  : ID
	| ID '[' vector_position ']'
	| ID OF ID
	| ID '[' vector_position ']' OF ID
	| ID OF ID '[' vector_position ']'
	| ID '[' vector_position ']' OF ID '[' vector_position ']'
	;

expr
  : '(' expr ')'
  | expr '+' expr
  | expr '-' expr
  | expr '*' expr
  | expr '/' expr
  | expr '%' expr
  | '-' expr %prec UMINUS
  | variable
  | NR
  | NRF
  | CHR
  | STR
  | TRUE
  | FALSE
  ;

call_parameters
  : value_expression ',' call_parameters
  | value_expression
  ;

vector_position
  : ID
  | NR
  | CHNT ID SACRF call_parameters ':'
  | CHNT ID SACRF TIME ':'
  | ID '[' vector_position ']'
  ;

function_def
  : type BGNF ID SACRF typed_params ':' compound_statement ENDF
  | type BGNF ID SACRF TIME ':' compound_statement ENDF
  ;

compound_statement
  : statement compound_statement
  | statement
  ;

typed_params
  : typed_param ',' typed_params
  | typed_param
  ;

typed_param
  : generic_type ID
  | generic_type ID '[' ']'
  ;

generic_type
  : CONST type
  | type
  ;

type
  : ID
  | INT
  | FLOAT
  | CHAR
  | STRING
  | BOOL
  | VOID
  ;

statement
  : declaration
  | if_instr
  | while_instr
  | for_instr
  | ENCH ID WITH eval_expr '.'
  | ENCH ID '[' vector_position ']'WITH eval_expr '.'
  | ENCH ID OF ID WITH eval_expr '.'
  | CHNT ID SACRF call_parameters ':' '.'
  | CHNT ID SACRF TIME ':' '.'
  | EVAL '(' ')' '.'
  | EVAL '(' NR ')' '.'
  | EVAL '(' ID ')' '.'
  | RET eval_expr '.'
  ;

while_instr
  : WHILE '(' boolean ')' compound_statement ENDWHILE
	;

boolean : check
	| check AND boolean
	| '(' check ')' AND boolean
	| '(' check ')' OR boolean
	| '(' check ')'
	| check OR boolean
	;

check : NOT eval_expr
  | eval_expr
 	| expr '>' expr
  | expr '<' expr
  | expr NEQ expr
  | expr EQ expr
  | expr BEQ expr
  | expr LEQ expr
  ;


if_instr : IF '(' boolean ')' if_body %prec IFX
	 | IF '(' boolean ')' if_body ELSE elif_body
	 ;


if_body : BEGINIF compound_statement ENDIF
	;


elif_body : BEGINELSE compound_statement ENDELSE
	  ;


for_instr : FOR for_sintax ENDFOR
	  ;


for_sintax : '(' ID IN for_iterator ')' compound_statement
	   ;


for_iterator
  : ID
	| iteratable_item ':' iteratable_item
	;

iteratable_item
  : ID
  | NR
  | NRF
  | CHR
  | CHNT  ID SACRF call_parameters ':'
  | ID '[' vector_position ']'
  ;

%%

void print_rule(int num, char* s)
{
}

void yyerror(YYLTYPE *locp, ParseState* parse_state, yyscan_t scanner, const char *msg)
{
	parse_state->hasError = 1;
	parse_state->errorLine = locp->first_line;
	parse_state->errorColumn = locp->first_column;
	parse_state->errorMessage = msg;
	parse_state->errorToken = locp->last_token;
}
