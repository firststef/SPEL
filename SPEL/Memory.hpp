#include "Node.hpp"

#include <string>
#include <vector>
#include <stack>
#include <map>

struct Context
{
	std::string name;

	int parent_idx = -1;
	std::vector<Context>& contexts;

	std::string get_context()
	{
		std::string full_context = name;
		
		int current = parent_idx;

		while (current != -1)
		{
			full_context = contexts[current].name + "::" + full_context;
			current = contexts[current].parent_idx;
		}

		return full_context;
	}
};

struct VariableRegister
{
	int index_in_vector;
	Identifier name;
	Type type;
	std::string class_name;
};

struct ParseState
{
	std::shared_ptr<Node> rootNode;
	
	std::vector<std::vector<std::shared_ptr<VariableDeclaration>>> stack;

	std::vector<VariableRegister> varRegister;
	std::vector<Context> contexts;
	std::stack<int> contextStack;
	
	std::vector<std::shared_ptr<ClassDefinition>> classes;
	std::vector<std::shared_ptr<FunctionDeclaration>> functions;
	
	int hasError = 0;
	int errorLine;

	int errorColumn;
	std::string errorMessage;
	std::string errorToken;
};
