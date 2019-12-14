%defines "parser.h"

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern FILE* yyin;
typedef struct expr_info {
	int intvalue;
	char* strvalue;
	int type;
} expr_info;

expr_info* create_int_expr(int value);
expr_info* create_str_expr(char* value1, char* value2);
void free_expr(expr_info* expr);
void print_expr(expr_info* expr);

#pragma warning (disable: 4005)

// this function will be generated
// by flex
extern int yylex(); // lexical analyzer

	// we have to code this function
extern void yyerror(const char*);

using namespace std;

bool a = false;
%}


%union {
	int intval;
	char* strval;
	struct expr_info* expr_ptr;
}
%token <strval>STRING
%token <intval>NR
%type <expr_ptr>e
%type <expr_ptr>str
%type <expr_ptr>s

%start s
%%

s			: e { print_expr($$); free_expr($$);}
			| str { print_expr($$); free_expr($$); }
			;

e			: e '+' e {$$ = create_int_expr($1->intvalue + $3->intvalue); free_expr($1); free_expr($3); if ($1->intvalue==3) a = true;}
			| NR { $$ = create_int_expr($1); }
			;

str			: str '+' str {$$ = create_str_expr($1->strvalue, $3->strvalue); free_expr($1); free_expr($3); }
			| STRING {$$ = create_str_expr($1, NULL); free($1);}
			;

%%

expr_info* create_int_expr(int value)
{

	expr_info* expr = (expr_info*)malloc(sizeof(expr_info));
	expr->intvalue = value;
	expr->type = 1;
	return expr;
}

expr_info* create_str_expr(char* value1, char* value2)
{
	expr_info* expr = (expr_info*)malloc(sizeof(expr_info));
	int len2 = value2 ? strlen(value2) : 0;
	expr->strvalue = (char*)malloc(sizeof(char)*(strlen(value1) + len2 + 1));
	strcpy(expr->strvalue, value1);
	if (value2)
	{
		strcat(expr->strvalue, value2);
	}
	expr->type = 2;
	return expr;

}

void free_expr(expr_info* expr)
{
	if (expr->type == 2)
	{
		free(expr->strvalue);
	}
	free(expr);
}


void print_expr(expr_info* expr)
{
	if (expr->type == 1)
	{
		printf("Int expr with value:%d", expr->intvalue);
	}
	else
	{
		printf("Str expr with value:%s", expr->strvalue);
	}
}
