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
	bool value;
};

enum Type
{
	NONE,
	VECTOR_NONE,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_CHAR,
	TYPE_STRING,
	TYPE_BOOL,
	TYPE_OBJECT,
	TYPE_INT_VECTOR,
	TYPE_FLOAT_VECTOR,
	TYPE_CHAR_VECTOR,
	TYPE_STRING_VECTOR,
	TYPE_BOOL_VECTOR,
	TYPE_OBJECT_VECTOR
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
	int size_of_vector = 0; //sizeul ar trebui pus in resize la initializare
	int position_in_vector; //atunci cand accesam a[5]
	
	std::string context;
	
	Identifier class_name;

	std::shared_ptr<Expression> expr;
	std::vector<std::shared_ptr<Expression>> exprs;
	
};

enum StatementType
{
	NO_STMT,
	VAR_DEC_STMT,
	ITER_SEL_STMT,
	ASGMT_STMT,
	FUNC_CALL_STMT,
	RET_STMT,
	EVAL_STMT
};

struct Statement 
{
	StatementType st_type;
	
	std::shared_ptr<VariableDeclaration> var_dec; //should be renamed with _stmt
	std::shared_ptr<IterationSelectionStatement> iter_sel_stmt;
	std::shared_ptr<Assignment> asgmt_stmt; 
	std::shared_ptr<FunctionCall> func_call; //should be renamed with _stmt
	std::shared_ptr<Expression> ret_stmt;
};

using ComposedStatement = std::vector<Statement>;

enum ExpressionType
{
	UNKNOWN,
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
	Type return_type;
	TypeValue value;

	Identifier name;
	std::string class_name;

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

//ComposedStatement -> CompoundStatement

//propun sa scoatem eval -> declaram ca functie cand incepem

//no_return_function_body -> comp_stmt change type

//function_instruction remove -> function_body -> to statement

//if beginif ar trebui scos

//expresiile din vector ar trebui calculate la init (scapat de ele)
//si pus valoare default daca nu se pot calcula -> values

//ar fi mai putea fi facut ca vectorul sa fie defapt un vector 
//de variabile si astfel se rezolva si enchnt de v[5]

//cast time in functie void care nu e in return statement nu se poate