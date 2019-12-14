#include <iostream>

#include "parser.h"

using namespace std;

extern int yyparse();

extern bool a;

int main()
{

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