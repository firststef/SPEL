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

%token INT, FLOAT, CHAR, STRING, CHR, ID, NR, NRF, STR, TRUE, FALSE, BGNF, ENDF, RET, CLASS, CONST, BOOL, ELSE, IF, FOR, WHILE, ENDWHILE, ENDFOR
%nonassoc IFX
%nonassoc ELSE
%start s

%%


s : statements {printf("accepted\n");}
  ;


statements : statement statements
		   | statement 
		   ;


statement : declarations
		  | instructions
		  ;

declarations : declaration declarations
			 | declaration
			 | func_declaration declarations
			 | func_declaration
			 | class_declaration declarations
			 | class_declaration
			 | instructions {printf("\nnu inteleg de ce nu merge daca las doar statement care sa treaca in ambele si trebuie sa le pun pe amandoua\n\n");}
			 ;


class_declaration : BGNF CLASS ID class_body ENDF
				  ;

class_body : declaration class_body
		   | declaration
		   | func_declaration class_body
		   | func_declaration
		   ;

declaration : type n_vars ';'
			| CONST type const_n_vars ';' 
			;

const_n_vars : const_n_var '=' value
			 | const_n_var '[' const_vector_size ']' '=' const_initialize_vec
			 | const_n_var '=' value const_n_vars
			 | const_n_var '[' const_vector_size ']' '=' const_initialize_vec const_n_vars
			 ;

n_vars : n_var
	   | n_var '=' value 
	   | n_var '[' vector_size ']' initialize_vec
	   | n_var n_vars
	   | n_var '=' value n_vars
	   | n_var '[' vector_size ']' initialize_vec n_vars
	   ;

func_declaration : BGNF type ID '(' parameters ')' function_body ENDF
				 ;

parameters : 
		   | parameter ',' parameters
		   | parameter
		   ;

parameter : type ID
		  | type ID '[' ']' 
		  ;

function_body : instructions function_body
			  | instructions
			  | declaration function_body
			  | declaration
			  | return function_body
			  | return
			  ;

instructions : instruction instructions
			 | instruction
			 ;

instruction : ID '(' call_parameters ')' ';'
			| while_stmt
			| if_stmt 
			| ID '=' expresie ';'
			;

while_stmt : WHILE '(' boolean ')' instructions ENDWHILE
		   ;

if_stmt : IF '(' boolean ')' if_body %prec IFX
		| IF '(' boolean ')' if_body ELSE if_body
		;

if_body : '{' instructions '}'
		| instruction
		;

boolean : bvalues
		;

bvalues : bvalue
		| bvalue '&''&' bvalues
		| bvalue '|''|' bvalues
		;

bvalue : value
	   | value '>' value
	   | value '>' '=' value
	   | value '<' value
	   | value '<' '=' value
	   | value '=' '=' value
	   | value '!' '=' value
	   ;

return : RET value ';'
	   | RET expresie {printf("aici trebuie construita o functie de evaluare a expresiilor\n");}
	   ;

vector_size : 
			| NR
			;

const_vector_size : NR
				  ;

vector_size : 
			| NR
			;

initialize_vec : 
			   | '[' values ']'
			   ;

const_initialize_vec : '[' values ']'
					 ;

values : value ',' values
	   | value
	   ;

type : INT
	 | FLOAT
	 | CHAR
	 | STRING
	 | BOOL
	 | ID
	 ;

const_n_var : ID
			;

n_var : ID
	  ;


value : NR
	  | NRF
	  | CHR
	  | STR
	  | TRUE
	  | FALSE
	  | ID
	  | ID '[' NR ']'
	  | ID '[' ID ']'
	  | ID '(' call_parameters ')'
	  | ID '.' ID
	  | expresie
	  ;

value2 : NR
	  | NRF
	  | CHR
	  | STR
	  | TRUE
	  | FALSE
	  | ID
	  | ID '[' NR ']'
	  | ID '[' ID ']'
	  | ID '.' ID
	  | ID '(' call_parameters ')'
	  ;

expresie : value2 {printf("\nexpresie trebuie modificat\n");}
		 | expresie '+' value2
		 | expresie '-' value2
		 | expresie '*' value2
		 | expresie '/' value2
		 | expresie '%' value2
		 | value2 '=' expresie
		 ;

call_parameters : call_parameter ',' call_parameters
				| call_parameter
				;

call_parameter : 
			   | value
			   ;
%%