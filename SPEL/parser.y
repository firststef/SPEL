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

%token PUBLIC PRIVATE PROTECTED INT FLOAT CHAR CLASS ID NR NRF DBLP RET

%start s
%%

s    : declarations { printf("Syntax is valid\n"); }
     | ;
	 ;

declarations: class_def declarations
	| func_def declarations
	| class_def
	| func_def
	;

class_def: CLASS ID '{' pub_sec prot_sec priv_sec '}' 
	     ;

pub_sec: PUBLIC ':' initializations
	   | 
	   ;

prot_sec: PROTECTED ':' initializations
        | 
	    ;

priv_sec: PRIVATE ':' initializations
	| 
	;
	

initializations: type attrib_id_list ';'initializations
	| type function_decl ';' initializations
	| type function_decl function_body ';' initializations
	| type attrib_id_list ';'
	| type function_decl ';'
	| type function_decl function_body ';'
	;

attrib_id_list: ID ',' attrib_id_list
	| ID '=' NR ',' attrib_id_list
	| ID '=' NRF ',' attrib_id_list
	| ID '=' ID ',' attrib_id_list
	| ID '[' NR ']' ',' attrib_id_list
	| ID '[' NR ']'
	| ID '=' ID
	| ID '=' NR
	| ID '=' NRF
	| ID
	;

function_decl: ID '(' typed_param_list ')'
	| ID '(' ')'
	;

type : INT
	 | FLOAT
	 | CHAR
	 ;

typed_param_list: type ID ',' typed_param_list
	| type ID '[' NR ']' ',' typed_param_list
	| type ID '[' NR ']'
	| type ID
	;

function_body: '{' RET ';' '}'
	| '{' RET ID ';' '}'
	| '{' RET NR ';' '}'
	| '{' RET NRF ';' '}'
	;

func_def: ID DBLP function_decl function_body ';'
	;

%%