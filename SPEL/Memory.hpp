#include "Node.hpp"

#include <string>
#include <vector>

struct ParseState
{
	TNode* rootNode;
	//TNode* topNode;
	void* memContext;

	int hasError = 0;
	int errorLine;

	int errorColumn;
	std::string errorMessage;
	std::string errorToken;

	//NodeLink* nodeStack;
	//int numRawCodeBlocks[RCT_Count];
	int numOpenBrackets;
};