#include "Node.hpp"

#include <string>
#include <vector>
#include <stack>

struct ParseState
{
	std::shared_ptr<Node> rootNode;
	
	std::vector<std::shared_ptr<VariableDeclaration>> variableStack;
	std::vector<std::shared_ptr<ClassDefinition>> classes;
	std::vector<std::shared_ptr<FunctionDeclaration>> functions;
	
	int hasError = 0;
	int errorLine;

	int errorColumn;
	std::string errorMessage;
	std::string errorToken;
};