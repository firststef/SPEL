#include <iostream>

#include "parser.h"

using namespace std;

extern int yyparse();


extern bool a;

// we have to code this function
void yyerror(const char* msg)
{
	cout << "Error: " << msg << endl;
}

int main(int argc, char** argv)
{
	FILE* yyin = fopen(argv[1], "r");
	while (true) {
		yyparse();
	}
	
	system("pause");
	return 1;
}