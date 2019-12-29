%{
#include "Parser.hpp"
#include "Lexer.hpp"
#define inline

void yyerror(YYLTYPE *locp, ParseState* parse_state, yyscan_t scanner, const char *msg);
%}

%code requires{

#include "Memory.hpp"

#define YY_NO_UNISTD_H 1
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
	typedef void* yyscan_t;
#endif

#define YYLLOC_DEFAULT(Current, Rhs, N)																\
	do																								\
		if (N)																						\
		{																							\
			(Current).first_line = YYRHSLOC (Rhs, 1).first_line;									\
			(Current).first_column = YYRHSLOC (Rhs, 1).first_column;								\
			(Current).last_line = YYRHSLOC (Rhs, N).last_line;										\
			(Current).last_column = YYRHSLOC (Rhs, N).last_column;									\
		}																							\
		else																						\
		{																							\
			(Current).first_line = (Current).last_line = YYRHSLOC (Rhs, 0).last_line;				\
			(Current).first_column = (Current).last_column = YYRHSLOC (Rhs, 0).last_column;	  \
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
%glr-parser

%token LEQ BEQ EQ NEQ INT OF FLOAT CHAR STRING CHR ID NR NRF NOT
%token STR TRUE FALSE BGNF ENDF AND OR RET CLASS CONST BOOL ELSE IF
%token FOR WHILE ENDWHILE BEGINIF BEGINELSE ENDELSE ENDIF ENDFOR VOID
%token IN EVAL BG BGNP ENDCLASS CRAFT BSTOW ENCH WITH SACRF TIME CHNT
%nonassoc IFX
%nonassoc ELSE
%start sp
%left LEQ BEQ EQ NEQ '<' '>'
%left  '+'  '-'
%left  '*'  '/'  '%'
%left  UMINUS      /*  supplies  precedence  for  unary  minus  */
%%

sp : BGNP s { printf("Reached start symbol.\n"); }
   | BGNP { printf("Reached start symbol.\n"); }
   ;

s : class_def s { PRINT_RULE }
  | function_def s { PRINT_RULE }
  | statement s { PRINT_RULE }
  | class_def { PRINT_RULE }
  | function_def { PRINT_RULE }
  | statement { PRINT_RULE }
  ;

class_def : CLASS ID class_body ENDCLASS { PRINT_RULE }
		  ;



class_body : class_var { PRINT_RULE }
		   | class_f { PRINT_RULE }
		   | class_var class_body { PRINT_RULE }
		   | class_f class_body { PRINT_RULE }
		   ;



class_var : CRAFT type class_ids '.' { PRINT_RULE }
		  | CRAFT CONST type const_class_ids '.'{ PRINT_RULE }
		  ;



type : ID { PRINT_RULE }
	 | INT { PRINT_RULE }
	 | FLOAT { PRINT_RULE }
	 | CHAR { PRINT_RULE }
	 | STRING { PRINT_RULE }
	 | BOOL { PRINT_RULE }
	 ;



class_ids : class_id { PRINT_RULE }
		  | class_id ',' class_ids { PRINT_RULE }
		  ;



class_id : ID { PRINT_RULE }
		 | ID BSTOW class_id_initialization { PRINT_RULE }
		 | ID '[' vector_size ']' { PRINT_RULE }
		 | ID '[' vector_size ']' BSTOW vector_initialization { PRINT_RULE }
		 ;



class_id_initialization : ID { PRINT_RULE }
						| NR { PRINT_RULE }
						| NRF { PRINT_RULE }
						| CHR { PRINT_RULE }
						| STR { PRINT_RULE }
						| TRUE { PRINT_RULE }
						| FALSE { PRINT_RULE }
						| CHNT ID SACRF call_parameters ':' { PRINT_RULE }
						| ID '[' vector_position ']' { PRINT_RULE }
						| ID OF ID { PRINT_RULE }
						| ID '[' vector_position ']' OF ID { PRINT_RULE }
						| ID OF ID '[' vector_position ']' { PRINT_RULE }
						| ID '[' vector_position ']' OF ID '[' vector_position ']' { PRINT_RULE }
						| eval_expr { PRINT_RULE }
						;



vector_size : { PRINT_RULE /*s-ar putea sa ne vina mai usor daca facem vector size nul direct din regula fara eps pentru ca sa identificam noi nr de param*/}
			| NR { PRINT_RULE }
			;



vector_initialization : '[' vector_body ']' { PRINT_RULE }
					  ;



vector_body : class_id_initialization { PRINT_RULE }
			| class_id_initialization ',' vector_body { PRINT_RULE }
			;



call_parameters : TIME { PRINT_RULE }
				| f_parameters { PRINT_RULE }
				;



vector_position : ID { PRINT_RULE }
				| NR { PRINT_RULE }
				| CHNT ID SACRF call_parameters ':' { PRINT_RULE }
				| ID '[' vector_position ']' { PRINT_RULE }
				;



const_class_ids : const_class_id { PRINT_RULE }
				| const_class_id ',' const_class_ids { PRINT_RULE }
				;



const_class_id : ID BSTOW class_id_initialization { PRINT_RULE }
			   | ID '[' const_vector_size ']' BSTOW vector_initialization { PRINT_RULE }
			   ;



const_vector_size : NR { PRINT_RULE }
				  ;



f_parameters : f_parameter { PRINT_RULE }
			 | f_parameter ',' f_parameters { PRINT_RULE }
			 ;



f_parameter : class_id_initialization {/*nu stiu daca aici este corect, dar eu presupun ca da*/ PRINT_RULE }
			;



class_f : type BGNF ID SACRF f_declaration_parameters ':' function_body ENDF { PRINT_RULE }
		| VOID BGNF ID SACRF f_declaration_parameters ':' no_return_function_body ENDF { PRINT_RULE }
		;



f_declaration_parameters : TIME { PRINT_RULE }
						 | declaration_parameters { PRINT_RULE }
						 ;



declaration_parameters : declaration_parameter { PRINT_RULE }
					   | declaration_parameter ',' declaration_parameters { PRINT_RULE }
					   ;



declaration_parameter : type ID { PRINT_RULE }
					  | type ID '[' ']' { PRINT_RULE }
					  | CONST type ID { PRINT_RULE }
					  | CONST type ID '[' ']' { PRINT_RULE }
					  ;



function_body : class_var function_body { PRINT_RULE }
			  | RET class_id_initialization '.' function_body { PRINT_RULE }
			  | RET eval_expr '.' function_body { PRINT_RULE }
			  | function_instruction function_body { PRINT_RULE }
			  | class_var { PRINT_RULE }
			  | RET class_id_initialization '.' { PRINT_RULE }
			  | RET eval_expr '.' { PRINT_RULE }
			  | function_instruction { PRINT_RULE }
		      | EVAL '(' ')' '.' { PRINT_RULE }
			  | EVAL '(' NR ')' '.' { PRINT_RULE }
			  | EVAL '(' ID ')' '.' { PRINT_RULE }
			  ;



function_instruction : ENCH ID WITH eval_expr '.' { PRINT_RULE }
					 | ENCH ID '[' vector_position ']' WITH eval_expr '.' { PRINT_RULE }
					 | ENCH ID OF ID WITH eval_expr '.' { PRINT_RULE }
					 | CHNT ID SACRF call_parameters ':' '.' { PRINT_RULE }
					 | while_instr { PRINT_RULE }
					 | if_instr { PRINT_RULE }
					 | for_instr { PRINT_RULE }
					 ;



while_instr : WHILE '(' while_condition ')' while_body ENDWHILE { PRINT_RULE }
			;



while_condition : boolean { PRINT_RULE }
				;



boolean : check { PRINT_RULE }
		| check AND boolean { PRINT_RULE }
		| check OR boolean { PRINT_RULE }
		;



check : NOT eval_expr { PRINT_RULE }
	  | eval_expr { PRINT_RULE }
	  ;



while_body : function_body {/*de asemenea nu stiu daca este ok ce fac aicea*/ PRINT_RULE }
		   ;



if_instr : IF '(' if_condition ')' if_body %prec IFX { PRINT_RULE }
		 | IF '(' if_condition ')' if_body ELSE elif_body { PRINT_RULE }
		 ;



if_condition : boolean { PRINT_RULE }
			 ;



if_body : BEGINIF function_body ENDIF { PRINT_RULE }
		;



elif_body : BEGINELSE function_body ENDELSE { PRINT_RULE }
		  ;



for_instr : FOR for_sintax ENDFOR { PRINT_RULE }
		  ;



for_sintax : '(' ID IN for_iterator ')' for_body { PRINT_RULE }
		   ;



for_iterator : ID { PRINT_RULE }
			| for_1 ':' for_1 { PRINT_RULE }
			;



for_1 : ID { PRINT_RULE }
	  | NR { PRINT_RULE }
	  | NRF { PRINT_RULE }
	  | CHR { PRINT_RULE }
	  | CHNT  ID SACRF call_parameters ':' { PRINT_RULE }
	  | ID '[' vector_position ']' { PRINT_RULE }
	  ;



for_body : function_body { PRINT_RULE }
		 ;



eval_expr : expr { PRINT_RULE }
		  | ENCH var WITH expr { PRINT_RULE }
		  ;

var : ID { PRINT_RULE }
	| ID '[' vector_position ']' { PRINT_RULE }
	| ID OF ID { PRINT_RULE }
	| ID '[' vector_position ']' OF ID { PRINT_RULE }
	| ID OF ID '[' vector_position ']' { PRINT_RULE }
	| ID '[' vector_position ']' OF ID '[' vector_position ']' { PRINT_RULE }
	;

expr : '(' expr ')' { PRINT_RULE }
	 | expr '+' expr { PRINT_RULE }
	 | expr '-' expr { PRINT_RULE }
	 | expr '*' expr { PRINT_RULE }
	 | expr '/' expr { PRINT_RULE }
	 | expr '%' expr { PRINT_RULE }
	 | '-' expr %prec UMINUS { PRINT_RULE }
	 | var { PRINT_RULE }
	 | NR { PRINT_RULE }
	 | NRF { PRINT_RULE }
	 | CHR { PRINT_RULE }
	 | STR { PRINT_RULE }
	 | TRUE { PRINT_RULE }
	 | FALSE { PRINT_RULE }
	 | expr '>' expr { PRINT_RULE }
	 | expr '<' expr { PRINT_RULE }
	 | expr NEQ expr { PRINT_RULE }
	 | expr EQ expr { PRINT_RULE }
	 | expr BEQ expr { PRINT_RULE }
	 | expr LEQ expr { PRINT_RULE }
	 ;

no_return_function_body : class_var no_return_function_body { PRINT_RULE }
						| function_instruction no_return_function_body { PRINT_RULE }
						| class_var { PRINT_RULE }
						| function_instruction { PRINT_RULE }
						;



function_def : class_f { PRINT_RULE }
			 ;



statement : declaration { PRINT_RULE }
		  | if_instr { PRINT_RULE }
		  | while_instr { PRINT_RULE }
		  | for_instr { PRINT_RULE }
		  | ENCH ID WITH eval_expr '.' { PRINT_RULE }
		  | ENCH ID '[' vector_position ']'WITH eval_expr '.' { PRINT_RULE }
		  | ENCH ID OF ID WITH eval_expr '.' { PRINT_RULE }
		  | CHNT ID SACRF call_parameters ':' '.' { PRINT_RULE }
		  | EVAL '(' ')' '.' { PRINT_RULE }
	      | EVAL '(' NR ')' '.' { PRINT_RULE }
		  | EVAL '(' ID ')' '.' { PRINT_RULE }
		  | RET eval_expr '.'  { PRINT_RULE }
		  ;



declaration : class_var { PRINT_RULE }
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
	//parse_state->errorToken = $$;
}
