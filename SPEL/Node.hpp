#include <memory>
#include <vector>
#include <string>

using Identifier = std::string;

struct CompileUnit;
struct VariableDeclaration;
struct FunctionDeclaration;
struct IterationSelectionStatement;
struct Expression;
struct Assignment;
struct DeclarationHolder;

struct Node{

	std::shared_ptr<CompileUnit> c_unit;
};

struct CompileUnit
{
	std::vector<std::shared_ptr<DeclarationHolder>> dec_holder;
};

enum DeclarationType
{
	VAR_DEC,
	FUNC_DEC
};

struct DeclarationHolder
{
	DeclarationType type;

	std::shared_ptr<VariableDeclaration> var_dec;
	std::shared_ptr<FunctionDeclaration> func_dec;
};

struct ClassDefinition
{
	Identifier name;

	std::vector<DeclarationHolder> decl_holders;
};

struct IntVal
{
	int value;
};

struct  FloatVal
{
	float value;
};

struct CharVal
{
	char value;
};

struct StringVal
{
	std::string value;
};

struct BoolVal
{
	char value;
};

enum Type
{
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_CHAR,
	TYPE_STRING,
	TYPE_BOOL,
	TYPE_OBJECT
};

struct TypeValue
{
	std::shared_ptr<IntVal> int_val;
	std::shared_ptr<FloatVal> float_val;
	std::shared_ptr<CharVal> char_val;
	std::shared_ptr<StringVal> string_val;
	std::shared_ptr<BoolVal> bool_val;
	std::shared_ptr<ClassDefinition> object_val;
};

struct VariableDeclaration
{
	Identifier name;

	bool is_const = false;

	Type type;

	//union sau cv
	TypeValue value;
	std::vector<TypeValue> values;

	std::shared_ptr<Expression> expr;
};

struct Statement
{
	std::shared_ptr<VariableDeclaration> var_dec;
	std::shared_ptr<IterationSelectionStatement> iter_sel_stmt;
	std::shared_ptr<Assignment> asgmt_stmt;
};

struct ComposedStatement
{
	std::vector<Statement> statements;
};

struct Expression
{
	Identifier name;
	
	Type type;
	TypeValue value;
};

enum IterationSelectionType
{
	TYPE_IF,
	TYPE_IF_ELSE,
	TYPE_WHILE,
	TYPE_FOR
};

struct IterationSelectionStatement
{
	IterationSelectionType type;
	
	Expression expr;

	ComposedStatement primary_body;

	ComposedStatement secondary_body;
};

struct Assignment
{
	Identifier name;

	//Instead of writing 5.id we check this field if it matches the vector type
	bool is_vector = false;
	int position;

	Expression expr;
};

struct FunctionDeclaration
{
	bool is_void = false;
	Type return_val;

	Identifier name;

	std::vector<VariableDeclaration> params;

	ComposedStatement function_body;
};

struct FunctionCall
{
	Identifier name;

	std::vector<Expression> params;
};

struct Return
{
	std::shared_ptr<Expression> ret;
};

