#include "Node.hpp"

#include <string>
#include <vector>

struct ParseState
{
	TNode* rootNode;
	//TNode* topNode;
	void* memContext;

	int hasError;
	int errorLine;
	int errorColumn;
	std::string errorMessage;
	std::string errorToken;

	//NodeLink* nodeStack;
	//int numRawCodeBlocks[RCT_Count];
	int numOpenBrackets;
};

struct CompilerResult{
  std::string errorMessage;
  int errorLine;
  int errorColumn;
};

inline const char* dup_str(void* context, const char* s)
{
	static std::vector<std::string> allocator;

	allocator.emplace_back(s);

	return allocator.back().c_str();
}