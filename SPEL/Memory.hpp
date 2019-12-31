#include "Node.hpp"

#include <string>
#include <vector>
#include <stack>

struct ParseState
{
	std::shared_ptr<Node> rootNode;
	
	std::stack<std::vector<std::shared_ptr<VariableDeclaration>>> variableStack;

	int hasError = 0;
	int errorLine;

	int errorColumn;
	std::string errorMessage;
	std::string errorToken;
};