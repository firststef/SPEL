%{
#include "Parser.hpp"
#include "Lexer.hpp"
#define inline

void yyerror(YYLTYPE *locp, ParseState* parse_state, yyscan_t scanner, const char *msg);
std::shared_ptr<VariableDeclaration> search_variable(std::string name, ParseState* parse_state);
std::shared_ptr<VariableDeclaration> search_variable_in_class(std::string name, std::string class_object, ParseState* parse_state);

void pop_stack_context(ParseState* parse_state);
#define POP_STACK_CONTEXT pop_stack_context(parse_state);

#define THROW_ERROR(msg) yyerror (&yylloc, parse_state, scanner, msg); YYERROR;
%}

%code requires{

#include "Memory.hpp"

#include <string>

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
%token FOR WHILE ENDWHILE BEGINIF BEGINELSE ENDELSE ENDIF ENDFOR VOID
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
%type <expr> class_id_initialization eval_expr expr
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
		/*for (auto& holder : $2->block_holder) {
			if (holder.type == DECLARATION_TYPE) {
				if (holder->decl_dec->type == VAR_FUNC) {

				}
			}
		}*/



		auto x = 0;

		//parse_state->rootNode = std::make_shared<Node>();
		//parse_state->rootNode->c_unit = std::shared_ptr<CompileUnit>($2);
	}
  | BGNP {  }
  ;

compile_unit
  : class_def compile_unit {
		parse_state->classes.push_back(std::shared_ptr<ClassDefinition>($1));

		//$$ = new CompileUnit();
		//$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
	}
  | class_f compile_unit{
		parse_state->functions.push_back(std::shared_ptr<FunctionDeclaration>($1));

		//$$ = new CompileUnit();
		//$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
	}
  | statement compile_unit {
		/*$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));*/
	}
  | class_def {
		parse_state->classes.push_back(std::shared_ptr<ClassDefinition>($1));

		/*$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));  */
	}
  | class_f {
		parse_state->functions.push_back(std::shared_ptr<FunctionDeclaration>($1));

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
	  	/*$$ = new BlockHolder();
		$$->type=CLASS_TYPE;

		$$->class_dec = std::shared_ptr<ClassDefinition>($3);

		$$->class_dec->name = $2->value;
		delete $2;*/

		$$ = $3;

		//verificare ca nu mai este o data definita clasa cu acelasi ID

		$3->name = $2->value;
		delete $2;

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
		$$->type=TYPE_OBJECT;
		$$->class_name = $1->value;
		//verificare daca ID este in vectorul de clase
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
		delete $3;
		$$->return_type = $1->type;
		delete $1;
		$$->function_body = *$7;
		delete $7;

		POP_STACK_CONTEXT;
	}
  | VOID BGNF ID SACRF f_declaration_parameters ':' no_return_function_body ENDF {
		$$ = $5;
		$$->name = $3->value;
		delete $3;
		$$->return_type = NONE;
		$$->is_void = true;
		//is_void should be equivalent to NONE
		$$->function_body = $7->function_body;
		delete $7;

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
		st.var_dec = $1->var_dec;

		$$->push_back(st);
	}
  | class_var {
		$$ = new ComposedStatement();

		Statement st;
		st.var_dec = $1->var_dec;

		$$->push_back(st);
	}
  | RET class_id_initialization '.' function_body {
		$$ = $4;

		Statement st;
		st.ret_stmt = std::shared_ptr<Expression>($2);

		$$->push_back(st);
	}
  | RET eval_expr '.' function_body {
		//redundanta eval_expr class_id_initialization
		$$ = $4;

		Statement st;
		st.ret_stmt = std::shared_ptr<Expression>($2);

		$$->push_back(st);
	}
  | RET class_id_initialization '.' {
		$$ = new ComposedStatement();

		Statement st;
		st.ret_stmt = std::shared_ptr<Expression>($2);

		$$->push_back(st);
	}
  | RET eval_expr '.' {
		$$ = new ComposedStatement();

		Statement st;
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

		$$->asgmt_stmt = std::make_shared<Assignment>(Assignment{ $2->value, false, -1, *$4 });
		delete $2;
		delete $4;
	}
  | ENCH ID '[' vector_position ']' WITH eval_expr '.' {
		$$ = new Statement();

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

		$4->name = $2->value;
		//trebuie cautata functia si intors tipul
		$$->func_call = std::shared_ptr<FunctionCall>($4);
	}
  | while_instr {
		$$ = new Statement();

		
	}
  | if_instr {
		$$ = new Statement();
	}
  | for_instr {
		$$ = new Statement();
	}
  ;



while_instr : WHILE '(' while_condition ')' while_body ENDWHILE {  }
			;



while_condition : boolean {  }
				;



boolean : check {  }
		| check AND boolean {  }
		| '(' check ')' AND boolean
		| '(' check ')' OR boolean
		| '(' check ')'
		| check OR boolean {  }
		;



check : NOT eval_expr {  }
	  | eval_expr {  }
   	  | expr '>' expr{  }
	  | expr '<' expr{  }
	  | expr NEQ expr{  }
	  | expr EQ expr{  }
	  | expr BEQ expr{  }
	  | expr LEQ expr{  }
	  ;


  /*de asemenea nu stiu daca este ok ce fac aicea*/
while_body : function_body {  }
		   ;



if_instr : IF '(' if_condition ')' if_body %prec IFX {  }
		 | IF '(' if_condition ')' if_body ELSE elif_body {  }
		 ;



if_condition : boolean {  }
			 ;



if_body : BEGINIF function_body ENDIF {  }
		;



elif_body : BEGINELSE function_body ENDELSE {  }
		  ;



for_instr : FOR for_sintax ENDFOR {  }
		  ;



for_sintax : '(' ID IN for_iterator ')' for_body {  }
		   ;



for_iterator : ID {  }
			| for_1 ':' for_1 {  }
			;



for_1 : ID {  }
	  | NR {  }
	  | NRF {  }
	  | CHR {  }
	  | CHNT  ID SACRF call_parameters ':' {  }
	  | ID '[' vector_position ']' {  }
	  ;



for_body : function_body {  }
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
				$$->value.int_val->value=$1->value.int_val->value+$3->value.int_val->value;
				break;
			case TYPE_FLOAT:
				$$->value.float_val->value=$1->value.float_val->value+$3->value.float_val->value;
				break;
			case TYPE_CHAR:
				$$->value.char_val->value=$1->value.char_val->value+$3->value.char_val->value;
				break;
			case TYPE_STRING:
				$$->value.string_val->value=$1->value.string_val->value+$3->value.string_val->value;
				break;

			case TYPE_BOOL:
				$$->value.bool_val->value=$1->value.bool_val->value+$3->value.bool_val->value;
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
				$$->value.int_val->value=$1->value.int_val->value-$3->value.int_val->value;
				break;
			case TYPE_FLOAT:
				$$->value.float_val->value=$1->value.float_val->value-$3->value.float_val->value;
				break;
			case TYPE_CHAR:
				$$->value.char_val->value=$1->value.char_val->value-$3->value.char_val->value;
				break;


			case TYPE_BOOL:
				$$->value.bool_val->value=$1->value.bool_val->value-$3->value.bool_val->value;
				break;
			default:
				//pt none si type_object(nu avem overloaded operators)
				//pt string nu are sens sa faci "-". Daca vrei putem pune.
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
				$$->value.int_val->value=$1->value.int_val->value*$3->value.int_val->value;
				break;
			case TYPE_FLOAT:
				$$->value.float_val->value=$1->value.float_val->value*$3->value.float_val->value;
				break;
			case TYPE_CHAR:
				$$->value.char_val->value=$1->value.char_val->value*$3->value.char_val->value;
				break;


			case TYPE_BOOL:
				$$->value.bool_val->value=$1->value.bool_val->value*$3->value.bool_val->value;
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
				$$->value.int_val->value=$1->value.int_val->value/$3->value.int_val->value;
				break;
			case TYPE_FLOAT:
				$$->value.float_val->value=$1->value.float_val->value/$3->value.float_val->value;
				break;
			case TYPE_CHAR:
				$$->value.char_val->value=$1->value.char_val->value/$3->value.char_val->value;
				break;
			default:
				//pt none si type_object(nu avem overloaded operators)
				//nici string nici bool nu ii facut
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
				$$->value.int_val->value=$1->value.int_val->value%$3->value.int_val->value;
				break;
			case TYPE_CHAR:
				$$->value.char_val->value=$1->value.char_val->value%$3->value.char_val->value;
				break;
			default:
				//pt none si type_object(nu avem overloaded operators)
				//nici string nici bool nu ii facut
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
				$$->value.int_val->value=-$2->value.int_val->value;
				break;
			case TYPE_FLOAT:
				$$->value.float_val->value=-$2->value.float_val->value;
				break;
			case TYPE_CHAR:
				$$->value.char_val->value=-$2->value.char_val->value;
				break;
			default:
				//yyerror();
				break;
		}
	}
  | var {
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
		$$->value.bool_val->value=true;//asa?
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
no_return_function_body : class_var no_return_function_body {
		$$=new FunctionDeclaration();
		//modificat, copiat ptr
		Statement statement;
		statement.var_dec=std::shared_ptr<VariableDeclaration>($1->var_dec);
		$$->function_body.push_back(statement);
		//de creat contextul
		for (auto& holder : $2->function_body){
				$$->function_body.push_back(holder);
		}
		/*
		nu trebuie pus tipul statementului aici?

		EDIT: vad acum ca nu am facut un enum cu tipul statementului - intr-adevar nu ne trebuie momentan, dar ar putea fi facut
		*/

		//nu stergi ce ai alocat nou 
		delete $1;
		delete $2;
	}
  | function_instruction no_return_function_body { /*aici nu cred ca trebuie scris nimic in afara de*/
		$$=new FunctionDeclaration();
		for (auto& holder : $2->function_body){
				$$->function_body.push_back(holder);
		}
		//trebuie pus in vector
		///R:Cred ca trebuie pus statementul respectiv in vector (function_instruction e defapt nenecesara ca e practic statement fara return)
	}
  | class_var {
		$$=new FunctionDeclaration();
		Statement statement;
		statement.var_dec=std::shared_ptr<VariableDeclaration>($1->var_dec);
		$$->function_body.push_back(statement);
		delete $1; 
	}
  | function_instruction {  }
  ;


statement
  : class_var {
		$$=new Statement();
		$$->var_dec=$1->var_dec;
		delete $1;
	}
  | if_instr {
		$$=new Statement();
		$$->iter_sel_stmt=std::shared_ptr<IterationSelectionStatement>($1);
	}
  | while_instr {
		$$=new Statement();
		$$->iter_sel_stmt=std::shared_ptr<IterationSelectionStatement>($1);
	}
  | for_instr {
		$$=new Statement();
		$$->iter_sel_stmt=std::shared_ptr<IterationSelectionStatement>($1);
	}
  | ENCH ID WITH eval_expr '.' {
		$$=new Statement();
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
		//FunctionCall* function_call=search_function($2->value, call_parameters);
		//trebuie implementata functia de cautat signatura unei functii sa vezi daca exista

		//$$->func_call=std::shared_ptr<FunctionCall>(function_call);

		///R:S-ar putea aici sa trebuiasca facuta o distinctie intre function call si valoarea de return a unei function call
	}
  | EVAL '(' ')' '.' {
		$$=new Statement();
		printf("statement vid\n");
	}
  | EVAL '(' NR ')' '.' {
		$$=new Statement();
		printf("%d\n", $3->value);
	}
  | EVAL '(' ID ')' '.' {
		$$=new Statement();
		//validare ca ID este int
		printf("Variable found: %s. Value: %d\n", $3->value, search_variable($3->value, parse_state)->value.int_val->value);
		///R:Daca ID are o valoare si nu altceva (o expresie -> function call etc), printam
	}
  | RET eval_expr '.'  {
		$$=new Statement();
		//aici ar trebuie verificat daca dam return la ce type trebuie (dar e destul de greu, ar trebuii sa stim contextul)
		$$->ret_stmt=std::shared_ptr<Expression>($2);
	}
  ;

%%
//putem sa facem toate verificarile de tipuri lacunar, sa dea eroare daca nu is int.




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

//modificat pentru ca am nevoie sa fie tipul asta
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

void pop_stack_context(ParseState* parse_state) {
	if (! parse_state->Stack.empty())
		parse_state->Stack.pop();
}
