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
struct ClassDefinition;
struct FunctionCall;
struct Return;


struct Context
{
	std::string name;

	Context* parent = nullptr;

	std::string get_context()
	{
		Context* current = this;
		std::string full_context;
		
		while(current != nullptr)
		{
			full_context = current->name + "." + full_context;
			current = current->parent;
		}

		return full_context;
	}
};

struct ContextUnit
{
	Context context;
};

struct Node{

	std::shared_ptr<CompileUnit> c_unit;
};

enum BlockType {
	CLASS_TYPE,
	DECLARATION_TYPE
};

struct BlockHolder {
	BlockType type;
	std::shared_ptr<ClassDefinition> class_dec;
	std::shared_ptr<DeclarationHolder> decl_dec;
};

struct CompileUnit
{
	std::vector<std::shared_ptr<BlockHolder>> block_holder;
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
	NONE,
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
	int size_of_vector = 0;
	int position_in_vector; //atunci cand accesam a[5]

	
	std::string context;
	
	//numele clasei daca ii tip obiect
	Identifier class_name = "if";

	std::shared_ptr<Expression> expr;
	std::vector<std::shared_ptr<Expression>> exprs;
	
};

//should be added type
struct Statement 
{
	std::shared_ptr<VariableDeclaration> var_dec;
	std::shared_ptr<IterationSelectionStatement> iter_sel_stmt;
	std::shared_ptr<Assignment> asgmt_stmt;
	std::shared_ptr<FunctionCall> func_call;
	std::shared_ptr<Return> ret_stmt;
};

struct ComposedStatement
{
	std::vector<Statement> statements;
};

enum ExpressionType
{
	VALUE,
	VECTOR_NAME,
	VARIABLE_NAME,
	REFERENCE,
	CALL
};

struct Expression
{
	ExpressionType e_type;
	
	std::shared_ptr<VariableDeclaration> var;
	std::shared_ptr<FunctionCall> call;

	Identifier name;
	int position;
	
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

struct IterationSelectionStatement : ContextUnit
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

struct FunctionDeclaration : ContextUnit
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
	Type return_type;
	TypeValue return_value;
	std::vector<std::shared_ptr<Expression>> params;
};

struct Return
{
	std::shared_ptr<Expression> ret;
};

inline int get_unique_id()
{
	static int id = 0;
	return id++;
}

//std::shared_ptr<VariableDeclaration> search_for_var()
//{
//	
//}
//
//


//if there is time, delete vector_position to expression

//something with ->name

//de scos class_ids