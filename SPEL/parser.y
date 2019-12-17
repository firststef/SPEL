%defines "parser.h"

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>

#include "SpelParserExternals.h"

//Lex vaiables
extern FILE* yyin;

extern int yylex();
extern void yyerror(const char*);

//Define for avoiding duplicated token enum
#define YYTOKENTYPE

%}

%locations

%token LEQ,  BEQ, EQ, NEQ, INT, OF, FLOAT, CHAR, STRING, CHR, ID, NR, NRF, NOT, STR, TRUE, FALSE, BGNF, ENDF, AND, OR, RET, CLASS, CONST, BOOL, ELSE, IF, FOR, WHILE, ENDWHILE, BEGINIF, BEGINELSE, ENDELSE, ENDIF, ENDFOR, VOID, IN
%nonassoc IFX
%nonassoc ELSE
%start s
%left LEQ BEQ EQ NEQ '<' '>'
%left  '+'  '-'
%left  '*'  '/'  '%'
%left  UMINUS      /*  supplies  precedence  for  unary  minus  */
%%

s : class_def s
  | function_def s
  | statement s
  | class_def
  | function_def
  | statement
  ;


class_def : BGNF CLASS ID class_body ENDF
		  ;



class_body : class_var
		   | class_f
		   | class_var class_body
		   | class_f class_body
		   ;



class_var : type class_ids ';'
		  | CONST type const_class_ids ';'
		  ;



type : ID
	 | INT
	 | FLOAT
	 | CHAR
	 | STRING
	 | BOOL
	 ;



class_ids : class_id
		  | class_id ',' class_ids
		  ;



class_id : ID
		 | ID '=' class_id_initialization
		 | ID '[' vector_size ']'
		 | ID '[' vector_size ']' '=' vector_initialization
		 ;



class_id_initialization : ID
						| NR
						| NRF
						| CHR
						| STR
						| TRUE
						| FALSE
						| ID '(' call_parameters ')'
						| ID '[' vector_position ']'
						| ID OF ID
						| ID '[' vector_position ']' OF ID
						| ID OF ID '[' vector_position ']'
						| ID '[' vector_position ']' OF ID '[' vector_position ']'
						| eval_expr
						;



vector_size : 
			| NR
			;



vector_initialization : '[' vector_body ']'
					  ;



vector_body : class_id_initialization
			| class_id_initialization ',' vector_body
			;



call_parameters : 
				| f_parameters
				;



vector_position : ID
				| NR
				| ID '(' call_parameters ')'
				| ID '[' vector_position ']'
				;



const_class_ids : const_class_id
				| const_class_id ',' const_class_ids
				;



const_class_id : ID '=' class_id_initialization
			   | ID '[' const_vector_size ']' '=' vector_initialization
			   ;



const_vector_size : NR
				  ;



f_parameters : f_parameter
			 | f_parameter ',' f_parameters
			 ;



f_parameter : class_id_initialization {/*nu stiu daca aici este corect, dar eu presupun ca da*/}
			;



class_f : BGNF type ID '(' f_declaration_parameters ')' function_body ENDF
		| BGNF VOID ID '(' f_declaration_parameters ')' no_return_function_body ENDF
		;



f_declaration_parameters : 
						 | declaration_parameters
						 ;



declaration_parameters : declaration_parameter
					   | declaration_parameter ',' declaration_parameters
					   ;



declaration_parameter : type ID
					  | type ID '[' ']'
					  | CONST type ID
					  | CONST type ID '[' ']'
					  ;



function_body : class_var function_body 
			  | RET class_id_initialization ';' function_body
			  | RET eval_expr ';' function_body
			  | function_instruction function_body
			  | class_var  
			  | RET class_id_initialization ';'
			  | RET eval_expr ';'
			  | function_instruction
			  ;



function_instruction : ID '=' eval_expr ';'
					 | ID '[' vector_position ']' '=' eval_expr ';'
					 | ID '(' call_parameters ')' ';'
					 | while_instr
					 | if_instr
					 | for_instr
					 ;



while_instr : WHILE '(' while_condition ')' while_body ENDWHILE
			;



while_condition : boolean
				;



boolean : check
		| check AND boolean
		| check OR boolean
		;



check : NOT eval_expr
	  | eval_expr
	  ;



while_body : no_return_function_body {/*de asemenea nu stiu daca este ok ce fac aicea*/}
		   ;



if_instr : IF '(' if_condition ')' if_body %prec IFX
		 | IF '(' if_condition ')' if_body ELSE elif_body
		 ;



if_condition : boolean
			 ;



if_body : BEGINIF no_return_function_body ENDIF
		;



elif_body : BEGINELSE no_return_function_body ENDELSE
		  ;



for_instr : FOR for_sintax ENDFOR
		  ;



for_sintax : '(' ID IN for_iterator ')' for_body
		   ;



for_iterator : ID
			| for_1 ':' for_1
			;



for_1 : ID
	  | NR
	  | NRF
	  | CHR
	  | ID '(' call_parameters ')'
	  | ID '[' vector_position ']'
	  ;



for_body : no_return_function_body 
		 ;



eval_expr : expr
		  | var '=' expr
		  ;

var : ID
	| ID '[' vector_position ']'
	| ID OF ID
	| ID '[' vector_position ']' OF ID
	| ID OF ID '[' vector_position ']'
	| ID '[' vector_position ']' OF ID '[' vector_position ']'
	;

expr : '(' expr ')'
	 | expr '+' expr
	 | expr '-' expr
	 | expr '*' expr
	 | expr '/' expr
	 | expr '%' expr
	 | '-' expr %prec UMINUS
	 | var
	 | NR
	 | NRF
	 | CHR
	 | STR
	 | TRUE
	 | FALSE
	 | expr '>' expr
	 | expr '<' expr
	 | expr NEQ expr
	 | expr EQ expr
	 | expr BEQ expr
	 | expr LEQ expr
	 ;

no_return_function_body : class_var no_return_function_body 
						| function_instruction no_return_function_body
						| class_var  
						| function_instruction
						;



function_def : class_f 
			 ;



statement : declaration
		  | if_instr
		  | while_instr
		  | for_instr
		  | ID '=' eval_expr ';'
		  | ID '(' call_parameters ')' ';'
		  ;



declaration : class_var
			;



%%