%option noyywrap

%{
#pragma warning (disable: 4005)

#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

#include "parser.h"
%}

%%

[0 - 9]+ {yylval.intval = atoi(yytext); ECHO;  return NR; }
[a-zA-Z]+ {yylval.strval = _strdup(yytext); return STRING; }
[ \t]+ ;
\n { return 0; }
. {return yytext[0]; }

