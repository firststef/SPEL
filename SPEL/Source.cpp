#include <iostream>

#include "parser.h"

using namespace std;

extern int yyparse();


extern bool a;

int main(int argc, char** argv)
{
	FILE* yyin = fopen(argv[1], "r");
	while (not a) {
		yyparse();
	}

#ifdef _WIN32
	system("pause");
#endif
	return 0;
}

// we have to code this function
void yyerror(const char* msg)
{
	cout <<"Error: " <<msg << endl;
}