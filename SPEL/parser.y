%{
#include "Parser.hpp"
#include "Lexer.hpp"
#define inline

void yyerror(YYLTYPE *locp, ParseState* parse_state, yyscan_t scanner, const char *msg);
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

%type <node> sp
%type <c_unit> compile_unit
%type <bl_holder> class_def, function_def, statement
%type <class_def> class_body
%type <dec_holder> class_var, class_f
%type <variable_dec> type, class_id
%type <int_val> vector_size
%type <expr> class_id_initialization

%union {
	Node* node;
	CompileUnit* c_unit;
	BlockHolder* bl_holder;
	DeclarationHolder* dec_holder;
	ClassDefinition* class_def;
	IntVal* int_val;
	FloatVal* float_val;
	CharVal* char_val;
	StringVal* string_val;
	BoolVal* bool_val;
	VariableDeclaration* variable_dec;
	ComposedStatement* comp_stmt;
	Expression* expr;
	IterationSelectionStatement* iter_sel_stmt;
	Assignment* asgmt;
	FunctionDeclaration* func_decl;
	FunctionCall* func_call;
	Return* ret;
};

%%

sp 
  : BGNP compile_unit { 
		parse_state->rootNode = std::make_shared<Node>();
		parse_state->rootNode->c_unit = std::shared_ptr<CompileUnit>($2);
	}
  | BGNP {  }
  ;

compile_unit 
  : class_def compile_unit {
		$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
		//$$->block_holder.push_back($2->dec_holder.front()); //dedesubt ii inlocuitoarea
		//$$->block_holder.push_back(nullptr);
	}
  | function_def compile_unit{
		$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
		//$$->block_holder.push_back($2->dec_holder.front()); //dedesubt ii inlocuitoarea
		//$$->block_holder.push_back(nullptr);
	}
  | statement compile_unit {
		$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
		//$$->block_holder.push_back($2->dec_holder.front()); //dedesubt ii inlocuitoarea
		//$$->block_holder.push_back(nullptr);
	}
  | class_def { 
		$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));  
	}
  | function_def { 
		$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
	}
  | statement { 
		$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
	}
  ;

class_def 
  : CLASS ID class_body ENDCLASS { 
	  	$$ = new BlockHolder(); 
		$$->type=CLASS_TYPE;
	
		//aici cred ca nu trebuie asa cum ii mai jos, ci cum e dedesubt
		//$$->class_dec=std::make_shared<ClassDefinition>();
		//$$->class_dec=$3; //asta nu merge nu stiu de ce

		$$->class_dec = std::shared_ptr<ClassDefinition>($3);

		$$->class_dec->name = $2->value; // $2 ID StringVal
		delete $2;
		//printf("\n\n%s\n\n", $$->class_dec->name);
		//nu afiseaza ce trebuie (sau ce as vrea eu), iar pe release da eroare
	}
  ;

class_body 
  : class_var { 
		//as fi vrut asa: //$$=&std::make_shared<ClassDefinition>();
		$$ = new ClassDefinition();
		$$->decl_holders.push_back(*$1);//de decomentat cand e definit $1
	}
  | class_f { 
		$$ = new ClassDefinition();
		$$->decl_holders.push_back(*$1);//de decomentat cand e definit $1
	}
  | class_var class_body { 
		$$=new ClassDefinition();
		$$->decl_holders.push_back(*$1);//de decomentat cand e definit $1
		for (auto& holder : $2->decl_holders)
			$$->decl_holders.push_back(holder);
  }
  | class_f class_body { 
		$$ = new ClassDefinition();
		$$->decl_holders.push_back(*$1);
		for (auto& holder : $2->decl_holders)
			$$->decl_holders.push_back(holder);
	}
  ;

class_var 
  : CRAFT type class_id '.' { 
		$$=new DeclarationHolder();
		$$->type=VAR_DEC;
		$$->var_dec = std::shared_ptr<VariableDeclaration>($2);
	}
  | CRAFT CONST type const_class_id '.' {  }
;

type 
  : ID { 
		$$=new VariableDeclaration();
		$$->type=TYPE_OBJECT;
		$$->class_name = $1->value;
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
		$$=new VariableDeclaration();
		$$->name = $1->value;
		delete $1;
	}
  | ID BSTOW class_id_initialization { 
		$$=new VariableDeclaration();
		$$->name = $1->value;
		delete $1;

		//de verificat daca aici ID are acelasi tip cu tipul class_id_initiaization

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

		//ceva de rezolvat initializarea ca mai jos
		//$$->exprs=$6;
		//initializarea mai trebuie facuta

		$$->size_of_vector=$3->value;
		delete $3;
	}
  ;



class_id_initialization 
  : ID { 
		$$=new Expression();
		$$->name= $1->value;
		delete $1;
	}
  | NR { 
		$$=new Expression();
		$$->type=TYPE_INT;
		$$->value.int_val = std::shared_ptr<IntVal>($1);
	}
  | NRF { 
		$$=new Expression();
		$$->type = TYPE_FLOAT;
		$$->value.float_val = std::shared_ptr<FloatVal>($1);
	}
  | CHR { 
		$$=new Expression();
		$$->type = TYPE_CHAR;
		$$->value.char_val = std::shared_ptr<CharVal>($1);
	}
  | STR { 
		$$=new Expression();
		$$->type = TYPE_STRING;
		$$->value.string_val = std::shared_ptr<StringVal>($1);
	}
  | TRUE { 
		$$=new Expression();
		$$->type = TYPE_BOOL;
		$$->value.bool_val = std::shared_ptr<BoolVal>($1);
	}
  | FALSE { 
		$$=new Expression();
		$$->type = TYPE_BOOL;
		$$->value.bool_val = std::shared_ptr<BoolVal>($1);
	}
  | CHNT ID SACRF call_parameters ':' { 
		$$ = new Expression();

		//to be implemented - need type deduction
		//by searching for variable
	}
  | ID '[' vector_position ']' { 
		$$=new Expression();

		//to be implemented - need type deduction
		//by searching for variable
	}
  | ID OF ID { 
		$$=new Expression();

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
		$$=new Expression();
		//$$->type = $1->type;
		//$$->value = $1->value;
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


vector_initialization : '[' vector_body ']' {  }
					  ;



vector_body : class_id_initialization {  }
			| class_id_initialization ',' vector_body {  }
			;



call_parameters : TIME {  }
				| f_parameters {  }
				;



vector_position : ID {  }
				| NR {  }
				| CHNT ID SACRF call_parameters ':' {  }
				| ID '[' vector_position ']' {  }
				;



const_class_ids : const_class_id {  }
				| const_class_id ',' const_class_ids {  }
				;



const_class_id : ID BSTOW class_id_initialization {  }
			   | ID '[' const_vector_size ']' BSTOW vector_initialization {  }
			   ;



const_vector_size : NR {  }
				  ;



f_parameters : f_parameter {  }
			 | f_parameter ',' f_parameters {  }
			 ;



f_parameter : class_id_initialization {/*nu stiu daca aici este corect, dar eu presupun ca da*/  }
			;



class_f : type BGNF ID SACRF f_declaration_parameters ':' function_body ENDF {  }
		| VOID BGNF ID SACRF f_declaration_parameters ':' no_return_function_body ENDF {  }
		;



f_declaration_parameters : TIME {  }
						 | declaration_parameters {  }
						 ;



declaration_parameters : declaration_parameter {  }
					   | declaration_parameter ',' declaration_parameters {  }
					   ;



declaration_parameter : type ID {  }
					  | type ID '[' ']' {  }
					  | CONST type ID {  }
					  | CONST type ID '[' ']' {  }
					  ;



function_body : class_var function_body {  }
			  | RET class_id_initialization '.' function_body {  }
			  | RET eval_expr '.' function_body {  }
			  | function_instruction function_body {  }
			  | class_var {  }
			  | RET class_id_initialization '.' {  }
			  | RET eval_expr '.' {  }
			  | function_instruction {  }
		      | EVAL '(' ')' '.' {  }
			  | EVAL '(' NR ')' '.' {  }
			  | EVAL '(' ID ')' '.' {  }
			  ;



function_instruction : ENCH ID WITH eval_expr '.' {  }
					 | ENCH ID '[' vector_position ']' WITH eval_expr '.' {  }
					 | ENCH ID OF ID WITH eval_expr '.' {  }
					 | CHNT ID SACRF call_parameters ':' '.' {  }
					 | while_instr {  }
					 | if_instr {  }
					 | for_instr {  }
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



while_body : function_body {/*de asemenea nu stiu daca este ok ce fac aicea*/  }
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
		  | ENCH var WITH expr {  }
		  ;

var : ID {  }
	| ID '[' vector_position ']' {  }
	| ID OF ID {  }
	| ID '[' vector_position ']' OF ID {  }
	| ID OF ID '[' vector_position ']' {  }
	| ID '[' vector_position ']' OF ID '[' vector_position ']' {  }
	;

expr: '(' expr ')' {  }
	 | expr '+' expr {  }
	 | expr '-' expr {  }
	 | expr '*' expr {  }
	 | expr '/' expr {  }
	 | expr '%' expr {  }
	 | '-' expr %prec UMINUS {  }
	 | var {  }
     | CHNT ID SACRF call_parameters ':' {  }
	 | NR {  }
	 | NRF {  }
	 | CHR {  }
	 | STR {  }
	 | TRUE {  }
	 | FALSE {  }
	 ;

no_return_function_body : class_var no_return_function_body {  }
						| function_instruction no_return_function_body {  }
						| class_var {  }
						| function_instruction {  }
						;



function_def : class_f {  }
			 ;



statement : declaration {  }
		  | if_instr {  }
		  | while_instr {  }
		  | for_instr {  }
		  | ENCH ID WITH eval_expr '.' {  }
		  | ENCH ID '[' vector_position ']'WITH eval_expr '.' {  }
		  | ENCH ID OF ID WITH eval_expr '.' {  }
		  | CHNT ID SACRF call_parameters ':' '.' {  }
		  | EVAL '(' ')' '.' {  }
	      | EVAL '(' NR ')' '.' {  }
		  | EVAL '(' ID ')' '.' {  }
		  | RET eval_expr '.'  {  }
		  ;



declaration : class_var {  }
			;

%%

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
