%{
#include "Parser.hpp"
#include "Lexer.hpp"
#define inline

void yyerror(YYLTYPE *locp, ParseState* parse_state, yyscan_t scanner, const char *msg);
std::shared_ptr<VariableDeclaration> search_variable(std::string name, ParseState* parse_state);
std::shared_ptr<VariableDeclaration> search_variable_in_class(std::string name, std::string class_object, ParseState* parse_state);
std::shared_ptr<ClassDefinition> search_class(std::string name, ParseState* parse_state);
std::shared_ptr<FunctionDeclaration> search_function(std::string name, std::vector<VariableDeclaration> params, ParseState* parse_state);
bool is_return_type_correct(Type ret_type, TypeValue value, Expression statement);
bool is_return_type_correct(Type ret_type, TypeValue value, IterationSelectionStatement statement);
bool is_return_type_correct(Type ret_type, TypeValue value, ComposedStatement statements);

void pop_stack_context(ParseState* parse_state);
#define POP_STACK_CONTEXT pop_stack_context(parse_state);

#define THROW_ERROR(msg) { yyerror (&yylloc, parse_state, scanner, msg); YYERROR; }
%}

%code requires{

#include "Memory.hpp"

#include <string>
#include <sstream>

#define YY_NO_UNISTD_H 1
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
	typedef void* yyscan_t;
#endif

typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
  const char* last_token;
};
#define YYLTYPE_IS_DECLARED 1

#define YYLLOC_DEFAULT(Current, Rhs, N)																\
	do																								\
		if (N)																						\
		{																							\
			(Current).first_line = YYRHSLOC (Rhs, 1).first_line;									\
			(Current).first_column = YYRHSLOC (Rhs, 1).first_column;								\
			(Current).last_line = YYRHSLOC (Rhs, N).last_line;										\
			(Current).last_column = YYRHSLOC (Rhs, N).last_column;									\
			(Current).last_token = YYRHSLOC (Rhs, N).last_token;									\
		}																							\
		else																						\
		{																							\
			(Current).first_line = (Current).last_line = YYRHSLOC (Rhs, 0).last_line;				\
			(Current).first_column = (Current).last_column = YYRHSLOC (Rhs, 0).last_column;			\
			(Current).last_token = YYRHSLOC (Rhs, 0).last_token;									\
		}																							\
	while (0)

void print_rule(int num, char* s);
#define  print_rule(__LINE__, nullptr);
}

%output  "parser.cpp"
%defines "parser.hpp"

%define api.pure
%locations
%lex-param { yyscan_t scanner }
%parse-param { ParseState* parse_state }
%parse-param { yyscan_t scanner }

%token LEQ BEQ EQ NEQ INT OF FLOAT CHAR STRING NOT
%token BGNF ENDF AND OR RET CLASS CONST BOOL ELSE IF
%token FOR WHILE ENDWHILE ENDELSE ENDIF ENDFOR VOID
%token IN EVAL BG BGNP ENDCLASS CRAFT BSTOW ENCH WITH SACRF TIME CHNT

%token <string_val> ID STR
%token <int_val> NR
%token <float_val> NRF
%token <char_val> CHR
%token <bool_val> TRUE FALSE

%nonassoc IFX
%nonassoc ELSE

%start sp

%left LEQ BEQ EQ NEQ '<' '>'
%left  '+'  '-'
%left  '*'  '/'  '%'
%left  UMINUS      /*  supplies  precedence  for  unary  minus  */


%type <class_def> class_def class_body
%type <func_decl> no_return_function_body f_declaration_parameters declaration_parameters class_f
%type <dec_holder> class_var
%type <variable_dec> type class_id const_class_id var declaration_parameter
%type <int_val> vector_size vector_position
%type <expr> class_id_initialization eval_expr expr check boolean
%type <func_call> call_parameters
%type <exprs> vector_initialization vector_body f_parameters
%type <stmt> statement function_instruction
%type <iter_sel_stmt> if_instr while_instr for_instr
%type <comp_stmt> function_body

%union {
	Node* node;
	DeclarationHolder* dec_holder;
	ClassDefinition* class_def;
	IntVal* int_val;
	FloatVal* float_val;
	CharVal* char_val;
	StringVal* string_val;
	BoolVal* bool_val;
	VariableDeclaration* variable_dec;
	ComposedStatement* comp_stmt;
	Statement* stmt;
	Expression* expr;
	IterationSelectionStatement* iter_sel_stmt;
	Assignment* asgmt;
	FunctionDeclaration* func_decl;
	FunctionCall* func_call;

	std::vector< std::shared_ptr<Expression>>* exprs;
};

%%

sp
  : BGNP compile_unit {

		auto x = 0;

		//parse_state->rootNode = std::make_shared<Node>();
		//parse_state->rootNode->c_unit = std::shared_ptr<CompileUnit>($2);
	}
  | BGNP {  }
  ;

compile_unit
  : class_def compile_unit {
		

		//$$ = new CompileUnit();
		//$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
	}
  | class_f compile_unit{

		//$$ = new CompileUnit();
		//$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
	}
  | statement compile_unit {
		/*$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));*/
	}
  | class_def {

		/*$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));  */
	}
  | class_f {

		/*$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));*/
	}
  | statement {
		/*$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));*/
	}
  ;

class_def
  : CLASS ID class_body ENDCLASS {
		$$ = $3;

		$$->name = $2->value;
		delete $2;

		std::ostringstream stream;
		stream << "Class with name " << $$->name << " already exists";
		auto string = stream.str();

		if (search_class($$->name, parse_state).get() != nullptr)
			THROW_ERROR(string.c_str());

		parse_state->classes.push_back(std::shared_ptr<ClassDefinition>($$));
		POP_STACK_CONTEXT;
	}
  ;

class_body
  : class_var {
		$$ = new ClassDefinition();
		$$->decl_holders.push_back(*$1);
	}
  | class_f {
		$$ = new ClassDefinition();

		DeclarationHolder dh;
		dh.func_dec = std::shared_ptr<FunctionDeclaration>($1);
		$$->decl_holders.push_back(dh);
	}
  | class_var class_body {
		$$ = $2;
		$$->decl_holders.push_back(*$1);
  }
  | class_f class_body {
		$$ = $2;
		DeclarationHolder dh;
		dh.func_dec = std::shared_ptr<FunctionDeclaration>($1);
		$$->decl_holders.push_back(dh);
	}
  ;

class_var
  : CRAFT type class_id '.' {
		$$=new DeclarationHolder();
		$$->type=VAR_DEC;

		$3->type = $2->type;
		//aici cauti tipe - ul

		//if($3->type!=NONE) if($3->type!=$2->type) yyerror();
		//cateodata tipul $3 nu este setat (cand nu am initializat)

		$3->class_name = $2->class_name;
		$$->var_dec = std::shared_ptr<VariableDeclaration>($3);
		delete $2;

		//validare daca exista
		parse_state->Stack.top().push_back($$->var_dec);
	}
  | CRAFT CONST type const_class_id '.' {

		  $$ = new DeclarationHolder();
		  $$->type = VAR_DEC;

		  $4->type = $3->type;
		  $4->class_name = $3->class_name;
		  $4->is_const = true;
		  $$->var_dec = std::shared_ptr<VariableDeclaration>($4);
		  delete $3;

		  //validare daca exista
		  parse_state->Stack.top().push_back($$->var_dec);
	}
  ;

type
  : ID {
		$$=new VariableDeclaration();
		$$->type = TYPE_OBJECT;
		
		TypeValue val;
		val.object_val = std::shared_ptr<ClassDefinition>(new ClassDefinition({ $1->value, std::vector < DeclarationHolder >() }));
		$$->value = val;

		delete $1;
	}
  | INT {
		$$=new VariableDeclaration();
		$$->type=TYPE_INT;
	}
  | FLOAT {
		$$=new VariableDeclaration();
		$$->type=TYPE_FLOAT;
	}
  | CHAR {
		$$=new VariableDeclaration();
		$$->type=TYPE_CHAR;
	}
  | STRING {
		$$=new VariableDeclaration();
		$$->type=TYPE_STRING;
	}
  | BOOL {
		$$=new VariableDeclaration();
		$$->type=TYPE_BOOL;
	}
  ;


  /* To be removed */
class_ids
  : class_id {  }
  | class_id ',' class_ids {  }
  ;



class_id
  : ID {
		$$ = new VariableDeclaration();
		$$->name = $1->value;
		delete $1;
	}
  | ID BSTOW class_id_initialization {
		$$=new VariableDeclaration();
		$$->name = $1->value;
		delete $1;
		$$->type = $3->type;
		$$->value = $3->value;
		//de verificat ca in class id_initialization toate
		//variabilele si constantele sunt type

		$$->expr = std::shared_ptr<Expression>($3);
	}
  | ID '[' vector_size ']' {
		$$=new VariableDeclaration();
		$$->name= $1->value;
		delete $1;

		$$->size_of_vector = $3->value;
		delete $3;
	}
  | ID '[' vector_size ']' BSTOW vector_initialization {
		$$=new VariableDeclaration();
		$$->name = $1->value;
		delete $1;

		$$->size_of_vector=$3->value;
		delete $3;

		//should do size validation
		//should do vector_init to ex
		$$->exprs = *$6;
		delete $6;
	}
  ;



class_id_initialization
  : ID {
		$$ = new Expression();
		$$->name = $1->value;
		$$->e_type = VARIABLE_NAME;

		//$$->value = search($$->name)->value;

		delete $1;
	}
  | NR {
		$$=new Expression();
		$$->type=TYPE_INT;
		$$->value.int_val = std::shared_ptr<IntVal>($1);
		$$->e_type = VALUE;
	}
  | NRF {
		$$=new Expression();
		$$->type = TYPE_FLOAT;
		$$->value.float_val = std::shared_ptr<FloatVal>($1);
		$$->e_type = VALUE;
	}
  | CHR {
		$$=new Expression();
		$$->type = TYPE_CHAR;
		$$->value.char_val = std::shared_ptr<CharVal>($1);
		$$->e_type = VALUE;
	}
  | STR {
		$$=new Expression();
		$$->type = TYPE_STRING;
		$$->value.string_val = std::shared_ptr<StringVal>($1);
		$$->e_type = VALUE;
	}
  | TRUE {
		$$=new Expression();
		$$->type = TYPE_BOOL;
		$$->value.bool_val = std::shared_ptr<BoolVal>($1);
		$$->e_type = VALUE;
	}
  | FALSE {
		$$=new Expression();
		$$->type = TYPE_BOOL;
		$$->value.bool_val = std::shared_ptr<BoolVal>($1);
		$$->e_type = VALUE;
	}
  | CHNT ID SACRF call_parameters ':' {
		$$ = new Expression();

		$$->call = std::shared_ptr<FunctionCall>($4);
		$$->call->name = $2->value;
		$$->e_type = CALL;
		//search for function template - validate name and params

	}
  | ID '[' vector_position ']' {
		$$=new Expression();
		$$->name = $1->value;
		$$->e_type = VECTOR_NAME;
		$$->position = $3->value; //trebuie evaluata aici poz
		delete $3;
		//to be implemented - need type deduction
		//by searching for variable
	}
  | ID OF ID { //ignore all OF statements
		$$=new Expression();

		$$->var = search_variable_in_class($1->value, $3->value, parse_state); //if null, fail
		$$->e_type = REFERENCE;

		//to be implemented - need type deduction
		//by searching for variable
	}
  | ID '[' vector_position ']' OF ID {
		$$=new Expression();

		//to be implemented - need type deduction
		//by searching for variable
	}
  | ID OF ID '[' vector_position ']' {
		$$=new Expression();

		//to be implemented - need type deduction
		//by searching for variable
	}
  | ID '[' vector_position ']' OF ID '[' vector_position ']' {
		$$=new Expression();

		//to be implemented - need type deduction
		//by searching for variable
	}
  | eval_expr {
		$$ = $1;
		//asta nu am facut-o noi?
	}
  ;



vector_size
  : {
	  $$ = new IntVal({ 0 });
	}
  | NR {
		$$ = new IntVal({$1->value});
		delete $1;
	}
  ;


vector_initialization
  : '[' vector_body ']' {
		$$ = $2;
	}
  ;



vector_body
  : class_id_initialization {
		$$ = new std::vector< std::shared_ptr<Expression>>();

		$$->push_back(std::shared_ptr<Expression>($1));
	}
  | class_id_initialization ',' vector_body {
		$$ = new std::vector< std::shared_ptr<Expression>>(*$3);
		delete $3;

		$$->push_back(std::shared_ptr<Expression>($1));
	}
  ;


  /*Call parameters ar putea fi eliminat*/
call_parameters
  : TIME {
		$$ = new FunctionCall();
	}
  | f_parameters {
		$$ = new FunctionCall();

		$$->params = *$1;
		delete $1;
	}
  ;



vector_position
  : ID {
		//asta e facut tot de mine, pentru ca am avut nevoie mai jos de unde am inceput

		$$ = new IntVal();
		$$->value=search_variable($1->value, parse_state)->value.int_val->value;
		delete $1;
	}
  | NR {
		$$ = new IntVal();
		$$ = $1;
	}
  | CHNT ID SACRF call_parameters ':' {
		$$=new IntVal();

		auto auxExpression = new Expression();
		auxExpression->call = std::shared_ptr<FunctionCall>($4);
		auxExpression->call->name = $2->value;
		auxExpression->e_type = CALL;

		//verificare daca functia e INT
		//if (auxExpression->call->return_type!=TYPE_INT) yyerror();
	}
  | ID '[' vector_position ']' {
	  $$ = new IntVal();

	  //to be implemented - search in vector
	}
  ;


  /* to be removed */
const_class_ids : const_class_id {  }
				| const_class_id ',' const_class_ids {  }
				;


const_class_id
  : ID BSTOW class_id_initialization {
		$$ = new VariableDeclaration();

		$$->name = $1->value;
		delete $1;
		$$->type = $3->type;
		$$->value = $3->value;
		$$->is_const = true;

		//de verificat ca in class id_initialization toate
		//variabilele si constantele sunt type

		//expresia trebuie musai sa aiba value, fiind const
		//altfel, arunca exceptie
		$$->expr = std::shared_ptr<Expression>($3);
	}
  | ID '[' NR ']' BSTOW vector_initialization {
		$$ = new VariableDeclaration();
		$$->name = $1->value;
		delete $1;

		$$->size_of_vector = $3->value;
		delete $3;

		//should do size validation
		//should do vector_init to ex

		//trebuie adaugat type vector
		$$->exprs = *$6;
		delete $6;
	}
  ;


  /* f_parameters ar putea fi eliminat - duplicat vector_body - lista de expr */
f_parameters
  : class_id_initialization {
		$$ = new std::vector< std::shared_ptr<Expression>>();

		$$->push_back(std::shared_ptr<Expression>($1));
	}
  | class_id_initialization ',' f_parameters {
		$$ = new std::vector< std::shared_ptr<Expression>>(*$3);
		delete $3;

		$$->push_back(std::shared_ptr<Expression>($1));
  }
  ;


class_f
  : type BGNF ID SACRF f_declaration_parameters ':' function_body ENDF {
		$$ = $5;
		$$->name = $3->value;
		$$->return_type = $1->type;
		$$->function_body = *$7;

		std::ostringstream stream1;
		stream1 << "Function " << $$->name << " already exists with this signature";
		auto string1 = stream1.str();

		if (search_function($$->name, $$->params, parse_state).get() != nullptr)
			THROW_ERROR(string1.c_str());

		std::ostringstream stream2;
		stream2 << "Illegal return type in function " << $$->name;
		auto string2 = stream2.str();

		if (!is_return_type_correct($$->return_type, $1->value, $$->function_body))
			THROW_ERROR(string2.c_str());

		delete $3;
		delete $1;
		delete $7;
		
		parse_state->functions.push_back(std::shared_ptr<FunctionDeclaration>($$));
		POP_STACK_CONTEXT;
	}
  | VOID BGNF ID SACRF f_declaration_parameters ':' no_return_function_body ENDF {
		$$ = $5;
		$$->name = $3->value;
		$$->return_type = NONE;
		$$->function_body = $7->function_body;

		std::ostringstream stream1;
		stream1 << "Function " << $$->name << " already exists with this signature";
		auto string1 = stream1.str();

		if (search_function($$->name, $$->params, parse_state).get() != nullptr)
			THROW_ERROR(string1.c_str());

		std::ostringstream stream2;
		stream2 << "Illegal return type in function " << $$->name;
		auto string2 = stream2.str();

		TypeValue val;
		if (!is_return_type_correct($$->return_type, val, $$->function_body))
			THROW_ERROR(string2.c_str());

		delete $3;
		delete $7;

		parse_state->functions.push_back(std::shared_ptr<FunctionDeclaration>($$));
		POP_STACK_CONTEXT;
	}
  ;


f_declaration_parameters
  : TIME {
		$$ = new FunctionDeclaration();
	}
  | declaration_parameters {
		$$ = $1;
	}
  ;


declaration_parameters
  : declaration_parameter {
		$$ = new FunctionDeclaration();
		$$->params.push_back(*$1);
		delete $1;
	}
  | declaration_parameter ',' declaration_parameters {
		$$ = $3;
		$$->params.push_back(*$1);
		delete $1;
	}
  ;



declaration_parameter
  : type ID {
		$$ = new VariableDeclaration();
		$$->type = $1->type;
		delete $1;
		$$->name = $2->value;
		delete $2;
	}
  | type ID '[' ']' {
		$$ = new VariableDeclaration();
		$$->type = Type($1->type + 6); //din TYPE_INT -> TYPE_INT_VECTOR
		delete $1;
		$$->name = $2->value;
		delete $2;
	}
  | CONST type ID {
		$$ = new VariableDeclaration();
		$$->type = $2->type;
		delete $2;
		$$->name = $3->value;
		delete $3;
		$$->is_const = true;
	}
  | CONST type ID '[' ']' {
		$$ = new VariableDeclaration();
		$$->type = Type($2->type + 6);
		delete $2;
		$$->name = $3->value;
		delete $3;
		$$->is_const = true;
	}
  ;



function_body
  : class_var function_body {
		$$ = $2;

		Statement st;
		st.st_type = VAR_DEC_STMT;
		st.var_dec = $1->var_dec;

		$$->push_back(st);
	}
  | class_var {
		$$ = new ComposedStatement();

		Statement st;
		st.st_type = VAR_DEC_STMT;
		st.var_dec = $1->var_dec;

		$$->push_back(st);
	}
  | RET class_id_initialization '.' function_body {
		$$ = $4;

		Statement st;
		st.st_type = RET_STMT;
		st.ret_stmt = std::shared_ptr<Expression>($2);

		$$->push_back(st);
	}
  | RET eval_expr '.' function_body {
		//redundanta eval_expr class_id_initialization
		$$ = $4;

		Statement st;
		st.st_type = RET_STMT;
		st.ret_stmt = std::shared_ptr<Expression>($2);

		$$->push_back(st);
	}
  | RET class_id_initialization '.' {
		$$ = new ComposedStatement();

		Statement st;
		st.st_type = RET_STMT;
		st.ret_stmt = std::shared_ptr<Expression>($2);

		$$->push_back(st);
	}
  | RET eval_expr '.' {
		$$ = new ComposedStatement();

		Statement st;
		st.st_type = RET_STMT;
		st.ret_stmt = std::shared_ptr<Expression>($2);

		$$->push_back(st);
    }
  | function_instruction function_body {
		$$ = $2;

		$$->push_back(*$1);
		delete $1;
	}
  | function_instruction {
		$$ = new ComposedStatement();

		$$->push_back(*$1);
		delete $1;
	}
  | EVAL '(' ')' '.' {  }
  | EVAL '(' NR ')' '.' {  }
  | EVAL '(' ID ')' '.' {  }
  ;



function_instruction
  : ENCH ID WITH eval_expr '.' {
		$$ = new Statement();
		$$->st_type = ASGMT_STMT;

		$$->asgmt_stmt = std::make_shared<Assignment>(Assignment{ $2->value, false, -1, *$4 });
		delete $2;
		delete $4;
	}
  | ENCH ID '[' vector_position ']' WITH eval_expr '.' {
		$$ = new Statement();
		$$->st_type = ASGMT_STMT;

		$$->asgmt_stmt = std::make_shared<Assignment>(Assignment{ $2->value, true, $4->value, *$7 });
		delete $2;
		delete $4;
		delete $7;
	}
  | ENCH ID OF ID WITH eval_expr '.' {
	  //no longer supported
	}
  | CHNT ID SACRF call_parameters ':' '.' {
		$$ = new Statement();
		$$->st_type = FUNC_CALL_STMT;

		$4->name = $2->value;
		//trebuie cautata functia si intors tipul
		$$->func_call = std::shared_ptr<FunctionCall>($4);
	}
  | while_instr {
		$$ = new Statement();
		$$->st_type = ITER_SEL_STMT;
		$$->iter_sel_stmt = std::shared_ptr<IterationSelectionStatement>($1);
	}
  | if_instr {
		$$ = new Statement();
		$$->st_type = ITER_SEL_STMT;
		$$->iter_sel_stmt = std::shared_ptr<IterationSelectionStatement>($1);
	}
  | for_instr {
		$$ = new Statement();
		$$->st_type = ITER_SEL_STMT;
		$$->iter_sel_stmt = std::shared_ptr<IterationSelectionStatement>($1);
	}
  ;


while_instr 
  : WHILE '(' boolean ')' function_body ENDWHILE { 
		$$ = new IterationSelectionStatement();
		$$->type = TYPE_WHILE;
		
		$$->expr = *$3;
		delete $3;

		$$->primary_body = *$5;
		delete $5;
	}
  ;


boolean : check { 
		$$=new Expression();
		$$->e_type=VALUE;
		$$->type=TYPE_BOOL;
		$$->value.bool_val->value=false;
		switch($1->type){
			case TYPE_INT: if ($1->value.int_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_FLOAT: if ($1->value.float_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_BOOL: if ($1->value.bool_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_CHAR: if ($1->value.char_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_STRING: if ($1->value.string_val->value!="") $$->value.bool_val->value=true; break;
			default : $$->value.bool_val->value=false; break;
		}
	}
  | check AND boolean { 
		$$=new Expression();
		$$->e_type=VALUE;
		$$->type=TYPE_BOOL;
		$$->value.bool_val->value=false;
		switch($1->type){
			case TYPE_INT: if ($1->value.int_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_FLOAT: if ($1->value.float_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_BOOL: if ($1->value.bool_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_CHAR: if ($1->value.char_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_STRING: if ($1->value.string_val->value!="") $$->value.bool_val->value=true; break;
			default : $$->value.bool_val->value=false; break;
		}
		if ($$->value.bool_val->value==true)
			$$=$3;
	}
  | '(' check ')' AND boolean { 
		$$=new Expression();
		$$->e_type=VALUE;
		$$->type=TYPE_BOOL;
		$$->value.bool_val->value=false;
		switch($2->type){
			case TYPE_INT: if ($2->value.int_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_FLOAT: if ($2->value.float_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_BOOL: if ($2->value.bool_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_CHAR: if ($2->value.char_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_STRING: if ($2->value.string_val->value!="") $$->value.bool_val->value=true; break;
			default : $$->value.bool_val->value=false; break;
		}
		if ($$->value.bool_val->value==true)
			$$=$5;
	}
  | '(' check ')' OR boolean  { 
		$$=new Expression();
		$$->e_type=VALUE;
		$$->type=TYPE_BOOL;
		$$->value.bool_val->value=false;
		switch($2->type){
			case TYPE_INT: if ($2->value.int_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_FLOAT: if ($2->value.float_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_BOOL: if ($2->value.bool_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_CHAR: if ($2->value.char_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_STRING: if ($2->value.string_val->value!="") $$->value.bool_val->value=true; break;
			default : $$->value.bool_val->value=false; break;
		}
		if ($$->value.bool_val->value==false)
			$$=$5;
	}
  | '(' check ')' { 
		$$=new Expression();
		$$->e_type=VALUE;
		$$->type=TYPE_BOOL;
		$$->value.bool_val->value=false;
		switch($2->type){
			case TYPE_INT: if ($2->value.int_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_FLOAT: if ($2->value.float_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_BOOL: if ($2->value.bool_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_CHAR: if ($2->value.char_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_STRING: if ($2->value.string_val->value!="") $$->value.bool_val->value=true; break;
			default : $$->value.bool_val->value=false; break;
		}
	}
  | check OR boolean  { 
		$$=new Expression();
		$$->e_type=VALUE;
		$$->type=TYPE_BOOL;
		$$->value.bool_val->value=false;
		switch($1->type){
			case TYPE_INT: if ($1->value.int_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_FLOAT: if ($1->value.float_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_BOOL: if ($1->value.bool_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_CHAR: if ($1->value.char_val->value!=0) $$->value.bool_val->value=true; break;
			case TYPE_STRING: if ($1->value.string_val->value!="") $$->value.bool_val->value=true; break;
			default : $$->value.bool_val->value=false; break;
		}
		if ($$->value.bool_val->value==false)
			$$=$3;
	}
  ;



check : NOT eval_expr { 
		$$=new Expression();
		$$->e_type=VALUE;
		$$->type=TYPE_BOOL;
		$$->value.bool_val->value=true;
		switch($2->type){
			case TYPE_INT: if ($2->value.int_val->value!=0) $$->value.bool_val->value=false; break;
			case TYPE_FLOAT: if ($2->value.float_val->value!=0) $$->value.bool_val->value=false; break;
			case TYPE_BOOL: if ($2->value.bool_val->value!=0) $$->value.bool_val->value=false; break;
			case TYPE_CHAR: if ($2->value.char_val->value!=0) $$->value.bool_val->value=false; break;
			case TYPE_STRING: if ($2->value.string_val->value!="") $$->value.bool_val->value=false; break;
			default : $$->value.bool_val->value=true; break;
		}
	}
  | eval_expr { 
		$$=$1;
	}
  | expr '>' expr { 
		$$=new Expression();
		$$->e_type=VALUE;
		$$->type=TYPE_BOOL;
		$$->value.bool_val->value=true;
		//if ($1->type!=$1->type) yyerror();
		switch($1->type) {
			case TYPE_INT: if ($1->value.int_val->value<$3->value.int_val->value) $$->value.bool_val->value=false; break;
			case TYPE_FLOAT: if ($1->value.float_val->value<$3->value.float_val->value) $$->value.bool_val->value=false; break;
			case TYPE_BOOL: if ($1->value.bool_val->value<$3->value.bool_val->value) $$->value.bool_val->value=false; break;
			case TYPE_CHAR: if ($1->value.char_val->value<$3->value.char_val->value) $$->value.bool_val->value=false; break;
			case TYPE_STRING: if ($1->value.string_val->value<$3->value.string_val->value) $$->value.bool_val->value=false; break;
			default : $$->value.bool_val->value=true; break;
		}
	}
  | expr '<' expr { 
		$$=new Expression();
		$$->e_type=VALUE;
		$$->type=TYPE_BOOL;
		$$->value.bool_val->value=false;
		//if ($1->type!=$1->type) yyerror();
		switch($1->type){
			case TYPE_INT: if ($1->value.int_val->value<$3->value.int_val->value) $$->value.bool_val->value=true; break;
			case TYPE_FLOAT: if ($1->value.float_val->value<$3->value.float_val->value) $$->value.bool_val->value=true; break;
			case TYPE_BOOL: if ($1->value.bool_val->value<$3->value.bool_val->value) $$->value.bool_val->value=true; break;
			case TYPE_CHAR: if ($1->value.char_val->value<$3->value.char_val->value) $$->value.bool_val->value=true; break;
			case TYPE_STRING: if ($1->value.string_val->value<$3->value.string_val->value) $$->value.bool_val->value=true; break;
			default : $$->value.bool_val->value=false; break;
		}
	}
  | expr NEQ expr { 
		$$=new Expression();
		$$->e_type=VALUE;
		$$->type=TYPE_BOOL;
		$$->value.bool_val->value=true;
		//if ($1->type!=$1->type) yyerror();
		switch($1->type) {
			case TYPE_INT: if ($1->value.int_val->value==$3->value.int_val->value) $$->value.bool_val->value=false; break;
			case TYPE_FLOAT: if ($1->value.float_val->value==$3->value.float_val->value) $$->value.bool_val->value=false; break;
			case TYPE_BOOL: if ($1->value.bool_val->value==$3->value.bool_val->value) $$->value.bool_val->value=false; break;
			case TYPE_CHAR: if ($1->value.char_val->value==$3->value.char_val->value) $$->value.bool_val->value=false; break;
			case TYPE_STRING: if ($1->value.string_val->value==$3->value.string_val->value) $$->value.bool_val->value=false; break;
			default : $$->value.bool_val->value=true; break;
		}
	}
  | expr EQ expr { 
		$$=new Expression();
		$$->e_type=VALUE;
		$$->type=TYPE_BOOL;
		$$->value.bool_val->value=false;
		//if ($1->type!=$1->type) yyerror();
		switch($1->type) {
			case TYPE_INT: if ($1->value.int_val->value==$3->value.int_val->value) $$->value.bool_val->value=true; break;
			case TYPE_FLOAT: if ($1->value.float_val->value==$3->value.float_val->value) $$->value.bool_val->value=true; break;
			case TYPE_BOOL: if ($1->value.bool_val->value==$3->value.bool_val->value) $$->value.bool_val->value=true; break;
			case TYPE_CHAR: if ($1->value.char_val->value==$3->value.char_val->value) $$->value.bool_val->value=true; break;
			case TYPE_STRING: if ($1->value.string_val->value==$3->value.string_val->value) $$->value.bool_val->value=true; break;
			default : $$->value.bool_val->value=false; break;
		}
	}
  | expr BEQ expr { 
		$$=new Expression();
		$$->e_type=VALUE;
		$$->type=TYPE_BOOL;
		$$->value.bool_val->value=false;
		//if ($1->type!=$1->type) yyerror();
		switch($1->type) {
			case TYPE_INT: if ($1->value.int_val->value>=$3->value.int_val->value) $$->value.bool_val->value=true; break;
			case TYPE_FLOAT: if ($1->value.float_val->value>=$3->value.float_val->value) $$->value.bool_val->value=true; break;
			case TYPE_BOOL: if ($1->value.bool_val->value>=$3->value.bool_val->value) $$->value.bool_val->value=true; break;
			case TYPE_CHAR: if ($1->value.char_val->value>=$3->value.char_val->value) $$->value.bool_val->value=true; break;
			case TYPE_STRING: if ($1->value.string_val->value>=$3->value.string_val->value) $$->value.bool_val->value=true; break;
			default : $$->value.bool_val->value=false; break;
		}
	}
  | expr LEQ expr { 
		$$=new Expression();
		$$->e_type=VALUE;
		$$->type=TYPE_BOOL;
		$$->value.bool_val->value=false;
		//if ($1->type!=$1->type) yyerror();
		switch($1->type) {
			case TYPE_INT: if ($1->value.int_val->value<=$3->value.int_val->value) $$->value.bool_val->value=true; break;
			case TYPE_FLOAT: if ($1->value.float_val->value<=$3->value.float_val->value) $$->value.bool_val->value=true; break;
			case TYPE_BOOL: if ($1->value.bool_val->value<=$3->value.bool_val->value) $$->value.bool_val->value=true; break;
			case TYPE_CHAR: if ($1->value.char_val->value<=$3->value.char_val->value) $$->value.bool_val->value=true; break;
			case TYPE_STRING: if ($1->value.string_val->value<=$3->value.string_val->value) $$->value.bool_val->value=true; break;
			default : $$->value.bool_val->value=false; break;
		}
	}
  ;



if_instr 
  : IF '(' boolean ')' function_body ENDIF %prec IFX {
		$$ = new IterationSelectionStatement();
		$$->type = TYPE_IF;

		$$->expr = *$3;
		delete $3;

		$$->primary_body = *$5;
		delete $5;
	}
  | IF '(' boolean ')' function_body ENDIF ELSE function_body ENDELSE {
		$$ = new IterationSelectionStatement();
		$$->type = TYPE_IF_ELSE;

		$$->expr = *$3;
		delete $3;

		$$->primary_body = *$5;
		delete $5;

		$$->secondary_body = *$8;
		delete $8;
	}
  ;


for_instr 
  : FOR '(' ID IN ID ')' function_body ENDFOR {
		$$ = new IterationSelectionStatement();
		$$->type = TYPE_FOR;

		$$->primary_body = *$7;
		delete $7;
	}
  | FOR '(' ID IN for_1 ':' for_1 ')' function_body ENDFOR {
		$$ = new IterationSelectionStatement();
		$$->type = TYPE_FOR;

		$$->primary_body = *$9;
		delete $9;
	}
  ;

for_1 : ID {  }
	  | NR {  }
	  | NRF {  }
	  | CHR {  }
	  | CHNT  ID SACRF call_parameters ':' {  }
	  | ID '[' vector_position ']' {  }
	  ;


eval_expr : expr {  }
  | ENCH var WITH expr {
		//de aici in jos facut-am eu

		$$=new Expression();
		//$2->value=$4->value; //asta daca calculam expr
		$2->expr=std::shared_ptr<Expression>($4);
		//$$->e_type = VALUE;
		///R:nu cred ca aici trebuie setat VALUE, asa orice vine de sus o sa devina VALUE si nu ai calculat-o daca era altceva
	}
  ;

var
  : ID {
		$$ = search_variable($1->value, parse_state).get();
	}
  | ID '[' vector_position ']' {
		$$=search_variable($1->value, parse_state).get();
		//validare gasire
		$$->position_in_vector=$3->value;
		//validare marime

		//vezi coment variable declaration
	}
  | ID OF ID { /*cum asta nu mai e posibila la noi nu o mai facem, nici celelalte de mai jos*/ }
  | ID '[' vector_position ']' OF ID {  }
  | ID OF ID '[' vector_position ']' {  }
  | ID '[' vector_position ']' OF ID '[' vector_position ']' {  }
  ;

expr: '(' expr ')' {
		$$=new Expression();
		$$=$2;
		//$$->e_type = VALUE;
		///R:nici aici
		//delete $2;
	}
  | expr '+' expr {
		
		$$=new Expression();
		//if ($1->type!=$3->type) yyerror();
		// validare if cu VALUE de sus
		$$->type=$1->type;
		$$->e_type = VALUE;
		///R:aici da pentru ca o calculezi manual

		switch($$->type){
			case TYPE_INT:
				$$->value.int_val = std::shared_ptr<IntVal>(new IntVal({ $1->value.int_val->value+$3->value.int_val->value }));
				break;
			case TYPE_FLOAT:
				$$->value.float_val = std::shared_ptr<FloatVal>(new FloatVal({ $1->value.float_val->value+$3->value.float_val->value }));
				break;
			case TYPE_CHAR:
				$$->value.char_val = std::shared_ptr<CharVal>(new CharVal({ $1->value.char_val->value+$3->value.char_val->value }));
				break;
			case TYPE_STRING:
				$$->value.string_val = std::shared_ptr<StringVal>(new StringVal({ $1->value.string_val->value+$3->value.string_val->value }));
				break;

			case TYPE_BOOL:
				$$->value.bool_val = std::shared_ptr<BoolVal>(new BoolVal({ $1->value.bool_val->value+$3->value.bool_val->value }));
				break;
			default:
				//pt none si type_object(nu avem overloaded operators)
				//yyerror();
				break;
		}

	}
  | expr '-' expr {
		$$=new Expression();
		//if ($1->type!=$3->type) yyerror();
		$$->type=$1->type;
		$$->e_type = VALUE;

		switch($$->type){
			case TYPE_INT:
				$$->value.int_val = std::shared_ptr<IntVal>(new IntVal({ $1->value.int_val->value-$3->value.int_val->value }));
				break;
			case TYPE_FLOAT:
				$$->value.float_val = std::shared_ptr<FloatVal>(new FloatVal({ $1->value.float_val->value-$3->value.float_val->value }));
				break;
			case TYPE_CHAR:
				$$->value.char_val = std::shared_ptr<CharVal>(new CharVal({ $1->value.char_val->value-$3->value.char_val->value }));
				break;
			case TYPE_STRING:
				$$->value.string_val = std::shared_ptr<StringVal>(new StringVal({ $1->value.string_val->value-$3->value.string_val->value }));
				break;

			case TYPE_BOOL:
				$$->value.bool_val = std::shared_ptr<BoolVal>(new BoolVal({ $1->value.bool_val->value-$3->value.bool_val->value }));
				break;
			default:
				//pt none si type_object(nu avem overloaded operators)
				//yyerror();
				break;
		}
	}
  | expr '*' expr {
		$$=new Expression();
		//if ($1->type!=$3->type) yyerror();
		$$->type=$1->type;
		$$->e_type = VALUE;

		switch($$->type){
			case TYPE_INT:
				$$->value.int_val = std::shared_ptr<IntVal>(new IntVal({ $1->value.int_val->value*$3->value.int_val->value }));
				break;
			case TYPE_FLOAT:
				$$->value.float_val = std::shared_ptr<FloatVal>(new FloatVal({ $1->value.float_val->value*$3->value.float_val->value }));
				break;
			case TYPE_CHAR:
				$$->value.char_val = std::shared_ptr<CharVal>(new CharVal({ $1->value.char_val->value*$3->value.char_val->value }));
				break;


			case TYPE_BOOL:
				$$->value.bool_val = std::shared_ptr<bool_val>(new BoolVal({ $1->value.bool_val->value*$3->value.bool_val->value }));
				break;
			default:
				//pt none si type_object(nu avem overloaded operators)
				//pt string nu are sens sa faci "*". Daca vrei putem pune.
				//yyerror();
				break;
		}
	}
  | expr '/' expr {
		$$=new Expression();
		//if ($1->type!=$3->type) yyerror();
		$$->type=$1->type;
		$$->e_type = VALUE;

		switch($$->type){
			case TYPE_INT:
				$$->value.int_val = std::shared_ptr<IntVal>(new IntVal({ $1->value.int_val->value*$3->value.int_val->value }));
				break;
			case TYPE_FLOAT:
				$$->value.float_val = std::shared_ptr<FloatVal>(new FloatVal({ $1->value.float_val->value*$3->value.float_val->value }));
				break;
			case TYPE_CHAR:
				$$->value.char_val = std::shared_ptr<CharVal>(new CharVal({ $1->value.char_val->value*$3->value.char_val->value }));
				break;

			default:
				//pt none si type_object(nu avem overloaded operators)
				//pt string nu are sens sa faci "*". Daca vrei putem pune.
				//yyerror();
				break;
		}
	}
  | expr '%' expr {
		$$=new Expression();
		//if ($1->type!=$3->type) yyerror();
		$$->type=$1->type;
		$$->e_type = VALUE;

		switch($$->type){
			case TYPE_INT:
				$$->value.int_val = std::shared_ptr<IntVal>(new IntVal({ $1->value.int_val->value*$3->value.int_val->value }));
				break;
			case TYPE_CHAR:
				$$->value.char_val = std::shared_ptr<CharVal>(new CharVal({ $1->value.char_val->value*$3->value.char_val->value }));
				break;

			default:
				//pt none si type_object(nu avem overloaded operators)
				//pt string nu are sens sa faci "*". Daca vrei putem pune.
				//yyerror();
				break;
		}
	}
  | '-' expr %prec UMINUS {
		$$=new Expression();
		$$->type=$2->type;
		$$->e_type = VALUE;

		switch($$->type){
			case TYPE_INT:
				$$->value.int_val = std::shared_ptr<IntVal>(new IntVal({ -$2->value.int_val->value }));
				break;
			case TYPE_FLOAT:
				$$->value.float_val = std::shared_ptr<FloatVal>(new FloatVal({ -$2->value.float_val->value }));
				break;
			case TYPE_CHAR:
				$$->value.char_val = std::shared_ptr<CharVal>(new CharVal({ -$2->value.char_val->value }));

				break;
			default:
				//yyerror();
				break;
		}
	}
  | var {
		//aici nu stiu exact cum sa aloc si daca sa aloc sau nu.
		$$=new Expression();
		$$->type=$1->type;
		$$->value=$1->value;
		//value ar trebui sa fie implicit 0 daca nu o putem calcula
		//$$->e_type = $1->e_type;
		///R: pai aici variabila daca nu e calculata deja ar trebui calculata / sau daca nu se poate trebuie lasat tipul diferit de valoare

		//delete $1;
	}
  | CHNT ID SACRF call_parameters ':' {
		$$=new Expression();
		$$->call=std::shared_ptr<FunctionCall>($4);
		$$->call->name = $2->value;
		$$->e_type = CALL;
		$$->type=$$->call->return_type;
		$$->value=$$->call->return_value;
	}
  | NR {
		$$=new Expression();
		$$->type=TYPE_INT;
		$$->value.int_val->value=$1->value;
		$$->e_type = VALUE;
		delete $1;
	}
  | NRF {
		$$=new Expression();
		$$->type=TYPE_FLOAT;
		$$->value.float_val->value=$1->value;
		$$->e_type = VALUE;
		delete $1;
	}
  | CHR {
		$$=new Expression();
		$$->type=TYPE_CHAR;
		$$->value.char_val->value=$1->value;
		delete $1;
	}
  | STR {
		$$=new Expression();
		$$->type=TYPE_STRING;
		$$->value.string_val->value=$1->value;
		$$->e_type = VALUE;
		delete $1;
	}
  | TRUE {
		$$=new Expression();
		$$->type=TYPE_BOOL;
		$$->value.bool_val = std::shared_ptr<BoolVal>($1);
		$$->e_type = VALUE;
		delete $1;
	}
  | FALSE {
		$$=new Expression();
		$$->type=TYPE_BOOL;
		$$->value.bool_val->value=false;//asa?
		$$->e_type = VALUE;
		delete $1;
	}
  ;

	/* Aici ar trebui sa fie Compound Statement */
no_return_function_body 
  : class_var no_return_function_body {
		$$ = $2;
		Statement statement;
		statement.st_type = VAR_DEC_STMT;
		statement.var_dec=std::shared_ptr<VariableDeclaration>($1->var_dec);
		delete $1;

		$$->function_body.push_back(statement); 
	}
  | function_instruction no_return_function_body {
		$$ = $2;

		$$->function_body.push_back(*$1);
		delete $1;
	}
  | class_var {
		$$ = new FunctionDeclaration();
		Statement statement;
		statement.st_type = VAR_DEC_STMT;
		statement.var_dec=std::shared_ptr<VariableDeclaration>($1->var_dec);
		delete $1; 
		
		$$->function_body.push_back(statement);
	}
  | function_instruction { 
		$$ = new FunctionDeclaration();
		
		$$->function_body.push_back(*$1);
		delete $1;
	}
  ;


statement
  : class_var {
		$$=new Statement();
		$$->st_type = VAR_DEC_STMT;
		$$->var_dec=$1->var_dec;
		delete $1;
	}
  | if_instr {
		$$=new Statement();
		$$->st_type = ITER_SEL_STMT;
		$$->iter_sel_stmt=std::shared_ptr<IterationSelectionStatement>($1);
	}
  | while_instr {
		$$=new Statement();
		$$->st_type = ITER_SEL_STMT;
		$$->iter_sel_stmt=std::shared_ptr<IterationSelectionStatement>($1);
	}
  | for_instr {
		$$=new Statement();
		$$->st_type = ITER_SEL_STMT;
		$$->iter_sel_stmt=std::shared_ptr<IterationSelectionStatement>($1);
	}
  | ENCH ID WITH eval_expr '.' {
		$$=new Statement();
		$$->st_type = ASGMT_STMT;
		Assignment* assignment=new Assignment();
		assignment->name=$2->value;
		assignment->expr=*$4;
		VariableDeclaration* variable;
		variable=search_variable($2->value, parse_state).get();
		variable->type=assignment->expr.type;
		variable->value=assignment->expr.value;
		///R:aici doar daca expresia e calculata deja (are tip value)
		//oare se modifica varibila? cred ca da, pt ca returneaza pointer spre ea;
		$$->asgmt_stmt=std::shared_ptr<Assignment>(assignment);
	}
  | ENCH ID '[' vector_position ']' WITH eval_expr '.' {
		$$=new Statement();
		$$->st_type = ASGMT_STMT;
		Assignment* assignment=new Assignment();
		assignment->name=$2->value;
		assignment->is_vector=true;
		assignment->position=$4->value;
		assignment->expr=*$7;
		VariableDeclaration* variable;
		variable=search_variable($2->value, parse_state).get();
		variable->type=assignment->expr.type;
		variable->value=assignment->expr.value;

		$$->asgmt_stmt=std::shared_ptr<Assignment>(assignment);
	}
  | ENCH ID OF ID WITH eval_expr '.' {
		//asta nu mai exista la noi.
	}
  | CHNT ID SACRF call_parameters ':' '.' {
		$$=new Statement();
		$$->st_type = FUNC_CALL_STMT;
		//FunctionCall* function_call=search_function($2->value, call_parameters);
		//trebuie implementata functia de cautat signatura unei functii sa vezi daca exista

		//$$->func_call=std::shared_ptr<FunctionCall>(function_call);

		///R:S-ar putea aici sa trebuiasca facuta o distinctie intre function call si valoarea de return a unei function call
	}
  | EVAL '(' ')' '.' {
		$$=new Statement();
		$$->st_type = FUNC_CALL_STMT;
		printf("statement vid\n");
	}
  | EVAL '(' NR ')' '.' {
		$$=new Statement();
		$$->st_type = FUNC_CALL_STMT;
		printf("%d\n", $3->value);
	}
  | EVAL '(' ID ')' '.' {
		$$=new Statement();
		$$->st_type = FUNC_CALL_STMT;
		//validare ca ID este int
		printf("Variable found: %s. Value: %d\n", $3->value, search_variable($3->value, parse_state)->value.int_val->value);
		///R:Daca ID are o valoare si nu altceva (o expresie -> function call etc), printam
	}
  | RET eval_expr '.'  {
		$$=new Statement();
		$$->st_type = RET_STMT;
		//aici ar trebuie verificat daca dam return la ce type trebuie (dar e destul de greu, ar trebuii sa stim contextul)
		$$->ret_stmt=std::shared_ptr<Expression>($2);
	}
  ;

%%
//NOTE: for context being accessible entirely and not just from a point upwards,
//the validation should be made in the Source file, by iterating through declarations
//and checking the parse_state

//void print_rule(int num, char* s)
//{
//}

void yyerror(YYLTYPE *locp, ParseState* parse_state, yyscan_t scanner, const char *msg)
{
	parse_state->hasError = 1;
	parse_state->errorLine = locp->first_line;
	parse_state->errorColumn = locp->first_column;
	parse_state->errorMessage = msg;
	parse_state->errorToken = locp->last_token;
}

std::shared_ptr<VariableDeclaration> search_variable
(std::string name, ParseState* parse_state)
{
	for (auto& variable : parse_state->Stack.top()) {
		if (variable->name == name)
			return variable;
	}

	return nullptr;
}

std::shared_ptr<VariableDeclaration> search_variable_in_class
(std::string name, std::string class_object, ParseState* parse_state)
{
	return nullptr;
}

std::shared_ptr<ClassDefinition> search_class(std::string name, ParseState* parse_state)
{
	for (auto& cls : parse_state->classes) {
		if (name == cls->name) {
			return cls;
		}
	}

	return nullptr;
}

std::shared_ptr<FunctionDeclaration> search_function(std::string name, std::vector<VariableDeclaration> params, ParseState* parse_state){
	for (auto& f : parse_state->functions) {
		if (name != f->name)
			continue;
		
		if (params.size() != f->params.size())
			continue;

		bool different = false;
		for (unsigned i = 0; i < params.size(); i++)
		{
			if (params[i].type != f->params[i].type)
			{
				different = true;
				break;
			}
		}

		if (! different)
			return f;
	}

	return nullptr;
}

void pop_stack_context(ParseState* parse_state) {
	if (! parse_state->Stack.empty())
		parse_state->Stack.pop();
}

bool is_return_type_correct(Type ret_type, TypeValue value, Expression statement) {
	if (ret_type == statement.type && ret_type != TYPE_OBJECT && ret_type != TYPE_OBJECT_VECTOR)
		return true;
	else if (ret_type == TYPE_OBJECT || ret_type == TYPE_OBJECT_VECTOR) {
		return ret_type == statement.type && value.object_val->name == statement.value.object_val->name;
	}
	
	return false;
}

bool is_return_type_correct(Type ret_type, TypeValue value, IterationSelectionStatement statement) {
	for (auto& st : statement.primary_body) {
		switch (st.st_type) {
			case RET_STMT:
				if (!is_return_type_correct(ret_type, value, *st.ret_stmt))
					return false;
				break;
			case ITER_SEL_STMT:
				if (!is_return_type_correct(ret_type, value, *st.ret_stmt))
					return false;
				break;
			default:
				break;
		}
	}

	for (auto& st : statement.secondary_body) {
		switch (st.st_type) {
		case RET_STMT:
			if (!is_return_type_correct(ret_type, value, *st.ret_stmt))
				return false;
			break;
		case ITER_SEL_STMT:
			if (!is_return_type_correct(ret_type, value, *st.ret_stmt))
				return false;
			break;
		default:
			break;
		}
	}

	return true;
}

bool is_return_type_correct(Type ret_type, TypeValue value, ComposedStatement statements) {
	for (auto& st : statements) {
		switch (st.st_type) {
		case RET_STMT:
			if (!is_return_type_correct(ret_type, value, *st.ret_stmt))
				return false;
			break;
		case ITER_SEL_STMT:
			if (!is_return_type_correct(ret_type, value, *st.ret_stmt))
				return false;
			break;
		default:
			break;
		}
	}

	return true;
}