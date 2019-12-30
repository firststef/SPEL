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
#define PRINT_RULE print_rule(__LINE__, nullptr);
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
%token <str> ID STR
%token <integer> NR
%token <floating> NRF
%token <chr> CHR
%token <booling> TRUE FALSE

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
%type <integer> vector_size
%type <expr> class_id_initialization

%union {
	bool* booling;
	char* chr;
	float* floating;
	std::string* str;
	int* integer;
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

sp : BGNP compile_unit 
   | BGNP { printf("Reached start symbol.\n"); }
   ;

compile_unit 
  : class_def compile_unit{
	PRINT_RULE 
	$$ = new CompileUnit();
	$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
	//$$->block_holder.push_back($2->dec_holder.front()); //dedesubt ii inlocuitoarea
	$$->block_holder.push_back(nullptr);
}
  | function_def compile_unit{
	$$ = new CompileUnit();
	$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
	//$$->block_holder.push_back($2->dec_holder.front()); //dedesubt ii inlocuitoarea
	$$->block_holder.push_back(nullptr);
	PRINT_RULE
}
  | statement compile_unit {
	$$ = new CompileUnit();
	$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
	//$$->block_holder.push_back($2->dec_holder.front()); //dedesubt ii inlocuitoarea
	$$->block_holder.push_back(nullptr);
	PRINT_RULE
}
  | class_def { 
  $$ = new CompileUnit();
  $$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
  PRINT_RULE 
}
  | function_def { 
  $$ = new CompileUnit();
  $$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
  PRINT_RULE 
}
  | statement { 
  $$ = new CompileUnit();
  $$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
  PRINT_RULE 
}
  ;

class_def : CLASS ID class_body ENDCLASS { 
	$$ = new BlockHolder(); 
	$$->type=CLASS_TYPE;
	
	//aici cred ca nu trebuie asa cum ii mai jos, ci cum e dedesubt
	$$->class_dec=std::make_shared<ClassDefinition>();
	//$$->class_dec=$3; //asta nu merge nu stiu de ce


	$$->class_dec->name=ID;
	//printf("\n\n%s\n\n", $$->class_dec->name);
	//nu afiseaza ce trebuie (sau ce as vrea eu), iar pe release da eroare
	PRINT_RULE 
}
		  ;



class_body : class_var { 
	//as fi vrut asa: //$$=&std::make_shared<ClassDefinition>();
	$$=new ClassDefinition();
	$$->decl_holders.push_back(*$1);//de decomentat cand e definit $1
	PRINT_RULE 
}
		   | class_f { 
	$$=new ClassDefinition();
//	$$->decl_holders.push_back(*$1);//de decomentat cand e definit $1
	PRINT_RULE 
}
		   | class_var class_body { 
	$$=new ClassDefinition();
	$$->decl_holders.push_back(*$1);//de decomentat cand e definit $1
//	$$->decl_holders..push_back($2->dec_holder.front());
	PRINT_RULE 
}
		   | class_f class_body { 
	$$=new ClassDefinition();
	
//	$$->decl_holders.push_back(*$1);//de decomentat cand e definit $1
//	$$->decl_holders..push_back($2->dec_holder.front());
	PRINT_RULE 
}
		   ;



class_var : CRAFT type class_id '.' { 
	$$=new DeclarationHolder();
	$$->type=VAR_DEC;
	$$->var_dec=std::make_shared<VariableDeclaration>();
	$$->var_dec->type=$2->type;
	$$->var_dec->class_name=$2->class_name;

	PRINT_RULE 
}
		  | CRAFT CONST type const_class_id '.'{ PRINT_RULE }
		  ;



type : ID { 
	$$=new VariableDeclaration();
	$$->type=TYPE_OBJECT;
	$$->class_name=ID;
	PRINT_RULE 
}
	 | INT { 
	$$=new VariableDeclaration();
	$$->type=TYPE_INT;
	PRINT_RULE 
}
	 | FLOAT { 
	$$=new VariableDeclaration();
	$$->type=TYPE_FLOAT;
	PRINT_RULE 
}
	 | CHAR { 
	$$=new VariableDeclaration();
	$$->type=TYPE_CHAR;
	PRINT_RULE 
}
	 | STRING { 
	$$=new VariableDeclaration();
	$$->type=TYPE_STRING;
	PRINT_RULE 
}
	 | BOOL { 
	$$=new VariableDeclaration();
	$$->type=TYPE_BOOL;
	PRINT_RULE 
}
	 ;



class_ids : class_id { PRINT_RULE }
		  | class_id ',' class_ids { PRINT_RULE }
		  ;



class_id : ID { 
	$$=new VariableDeclaration();
	$$->name=ID;
	PRINT_RULE 
}
		 | ID BSTOW class_id_initialization { 
	$$=new VariableDeclaration();
	$$->name=ID;
	$$->expr=std::shared_ptr<Expression>($3);
	//initializarea mai trebuie facuta
	PRINT_RULE 
}
		 | ID '[' vector_size ']' { 
	$$=new VariableDeclaration();
	$$->name=ID;
	
	$$->size_of_vector=*$3;
	PRINT_RULE
}
		 | ID '[' vector_size ']' BSTOW vector_initialization { 
	$$=new VariableDeclaration();
	$$->name=ID;
	//ceva de rezolvat initializarea ca mai jos
	//$$->exprs=$6;
	//initializarea mai trebuie facuta
	
	$$->size_of_vector=*$3;
	PRINT_RULE
}
		 ;



class_id_initialization : ID { 
	$$=new Expression();
	$$->name=*$1;
	printf("\n\n%s\n\n", $$->name.c_str());//??
	PRINT_RULE 
}
						| NR { 
	$$=new Expression();
	$$->type=TYPE_INT;
	//$$->value=$1;//??
	printf("\n\n%d\n\n", $1);//??
	PRINT_RULE 
}
						| NRF { 
	$$=new Expression();

	PRINT_RULE 
}
						| CHR { 
	$$=new Expression();

	PRINT_RULE 
}
						| STR { 
	$$=new Expression();

	PRINT_RULE 
}
						| TRUE { 
	$$=new Expression();

	PRINT_RULE 
}
						| FALSE { 
	$$=new Expression();

	PRINT_RULE 
}
						| CHNT ID SACRF call_parameters ':' { 
	$$=new Expression();

	PRINT_RULE 
}
						| ID '[' vector_position ']' { 
	$$=new Expression();

	PRINT_RULE 
}
						| ID OF ID { 
	$$=new Expression();

	PRINT_RULE 
}
						| ID '[' vector_position ']' OF ID { 
	$$=new Expression();

	PRINT_RULE 
}
						| ID OF ID '[' vector_position ']' { 
	$$=new Expression();

	PRINT_RULE 
}
						| ID '[' vector_position ']' OF ID '[' vector_position ']' { 
	$$=new Expression();

	PRINT_RULE 
}
						| eval_expr { 
	$$=new Expression();

	PRINT_RULE 
}
						;



vector_size : {
	$$=new int();
	*$$=0;
	PRINT_RULE 
}
			| NR {
	$$=new int();
	*$$=NR;
	PRINT_RULE 
}
			;



vector_initialization : '[' vector_body ']' { PRINT_RULE }
					  ;



vector_body : class_id_initialization { PRINT_RULE }
			| class_id_initialization ',' vector_body { PRINT_RULE }
			;



call_parameters : TIME { PRINT_RULE }
				| f_parameters { PRINT_RULE }
				;



vector_position : ID { PRINT_RULE }
				| NR { PRINT_RULE }
				| CHNT ID SACRF call_parameters ':' { PRINT_RULE }
				| ID '[' vector_position ']' { PRINT_RULE }
				;



const_class_ids : const_class_id { PRINT_RULE }
				| const_class_id ',' const_class_ids { PRINT_RULE }
				;



const_class_id : ID BSTOW class_id_initialization { PRINT_RULE }
			   | ID '[' const_vector_size ']' BSTOW vector_initialization { PRINT_RULE }
			   ;



const_vector_size : NR { PRINT_RULE }
				  ;



f_parameters : f_parameter { PRINT_RULE }
			 | f_parameter ',' f_parameters { PRINT_RULE }
			 ;



f_parameter : class_id_initialization {/*nu stiu daca aici este corect, dar eu presupun ca da*/ PRINT_RULE }
			;



class_f : type BGNF ID SACRF f_declaration_parameters ':' function_body ENDF { PRINT_RULE }
		| VOID BGNF ID SACRF f_declaration_parameters ':' no_return_function_body ENDF { PRINT_RULE }
		;



f_declaration_parameters : TIME { PRINT_RULE }
						 | declaration_parameters { PRINT_RULE }
						 ;



declaration_parameters : declaration_parameter { PRINT_RULE }
					   | declaration_parameter ',' declaration_parameters { PRINT_RULE }
					   ;



declaration_parameter : type ID { PRINT_RULE }
					  | type ID '[' ']' { PRINT_RULE }
					  | CONST type ID { PRINT_RULE }
					  | CONST type ID '[' ']' { PRINT_RULE }
					  ;



function_body : class_var function_body { PRINT_RULE }
			  | RET class_id_initialization '.' function_body { PRINT_RULE }
			  | RET eval_expr '.' function_body { PRINT_RULE }
			  | function_instruction function_body { PRINT_RULE }
			  | class_var { PRINT_RULE }
			  | RET class_id_initialization '.' { PRINT_RULE }
			  | RET eval_expr '.' { PRINT_RULE }
			  | function_instruction { PRINT_RULE }
		      | EVAL '(' ')' '.' { PRINT_RULE }
			  | EVAL '(' NR ')' '.' { PRINT_RULE }
			  | EVAL '(' ID ')' '.' { PRINT_RULE }
			  ;



function_instruction : ENCH ID WITH eval_expr '.' { PRINT_RULE }
					 | ENCH ID '[' vector_position ']' WITH eval_expr '.' { PRINT_RULE }
					 | ENCH ID OF ID WITH eval_expr '.' { PRINT_RULE }
					 | CHNT ID SACRF call_parameters ':' '.' { PRINT_RULE }
					 | while_instr { PRINT_RULE }
					 | if_instr { PRINT_RULE }
					 | for_instr { PRINT_RULE }
					 ;



while_instr : WHILE '(' while_condition ')' while_body ENDWHILE { PRINT_RULE }
			;



while_condition : boolean { PRINT_RULE }
				;



boolean : check { PRINT_RULE }
		| check AND boolean { PRINT_RULE }
		| '(' check ')' AND boolean
		| '(' check ')' OR boolean
		| '(' check ')'
		| check OR boolean { PRINT_RULE }
		;



check : NOT eval_expr { PRINT_RULE }
	  | eval_expr { PRINT_RULE }
   	  | expr '>' expr{ PRINT_RULE }
	  | expr '<' expr{ PRINT_RULE }
	  | expr NEQ expr{ PRINT_RULE }
	  | expr EQ expr{ PRINT_RULE }
	  | expr BEQ expr{ PRINT_RULE }
	  | expr LEQ expr{ PRINT_RULE }
	  ;



while_body : function_body {/*de asemenea nu stiu daca este ok ce fac aicea*/ PRINT_RULE }
		   ;



if_instr : IF '(' if_condition ')' if_body %prec IFX { PRINT_RULE }
		 | IF '(' if_condition ')' if_body ELSE elif_body { PRINT_RULE }
		 ;



if_condition : boolean { PRINT_RULE }
			 ;



if_body : BEGINIF function_body ENDIF { PRINT_RULE }
		;



elif_body : BEGINELSE function_body ENDELSE { PRINT_RULE }
		  ;



for_instr : FOR for_sintax ENDFOR { PRINT_RULE }
		  ;



for_sintax : '(' ID IN for_iterator ')' for_body { PRINT_RULE }
		   ;



for_iterator : ID { PRINT_RULE }
			| for_1 ':' for_1 { PRINT_RULE }
			;



for_1 : ID { PRINT_RULE }
	  | NR { PRINT_RULE }
	  | NRF { PRINT_RULE }
	  | CHR { PRINT_RULE }
	  | CHNT  ID SACRF call_parameters ':' { PRINT_RULE }
	  | ID '[' vector_position ']' { PRINT_RULE }
	  ;



for_body : function_body { PRINT_RULE }
		 ;



eval_expr : expr { PRINT_RULE }
		  | ENCH var WITH expr { PRINT_RULE }
		  ;

var : ID { PRINT_RULE }
	| ID '[' vector_position ']' { PRINT_RULE }
	| ID OF ID { PRINT_RULE }
	| ID '[' vector_position ']' OF ID { PRINT_RULE }
	| ID OF ID '[' vector_position ']' { PRINT_RULE }
	| ID '[' vector_position ']' OF ID '[' vector_position ']' { PRINT_RULE }
	;

expr: '(' expr ')' { PRINT_RULE }
	 | expr '+' expr { PRINT_RULE }
	 | expr '-' expr { PRINT_RULE }
	 | expr '*' expr { PRINT_RULE }
	 | expr '/' expr { PRINT_RULE }
	 | expr '%' expr { PRINT_RULE }
	 | '-' expr %prec UMINUS { PRINT_RULE }
	 | var { PRINT_RULE }
     | CHNT ID SACRF call_parameters ':' { PRINT_RULE }
	 | NR { PRINT_RULE }
	 | NRF { PRINT_RULE }
	 | CHR { PRINT_RULE }
	 | STR { PRINT_RULE }
	 | TRUE { PRINT_RULE }
	 | FALSE { PRINT_RULE }
	 ;

no_return_function_body : class_var no_return_function_body { PRINT_RULE }
						| function_instruction no_return_function_body { PRINT_RULE }
						| class_var { PRINT_RULE }
						| function_instruction { PRINT_RULE }
						;



function_def : class_f { PRINT_RULE }
			 ;



statement : declaration { PRINT_RULE }
		  | if_instr { PRINT_RULE }
		  | while_instr { PRINT_RULE }
		  | for_instr { PRINT_RULE }
		  | ENCH ID WITH eval_expr '.' { PRINT_RULE }
		  | ENCH ID '[' vector_position ']'WITH eval_expr '.' { PRINT_RULE }
		  | ENCH ID OF ID WITH eval_expr '.' { PRINT_RULE }
		  | CHNT ID SACRF call_parameters ':' '.' { PRINT_RULE }
		  | EVAL '(' ')' '.' { PRINT_RULE }
	      | EVAL '(' NR ')' '.' { PRINT_RULE }
		  | EVAL '(' ID ')' '.' { PRINT_RULE }
		  | RET eval_expr '.'  { PRINT_RULE }
		  ;



declaration : class_var { PRINT_RULE }
			;

%%

void print_rule(int num, char* s)
{
}

void yyerror(YYLTYPE *locp, ParseState* parse_state, yyscan_t scanner, const char *msg)
{
	parse_state->hasError = 1;
	parse_state->errorLine = locp->first_line;
	parse_state->errorColumn = locp->first_column;
	parse_state->errorMessage = msg;
	parse_state->errorToken = locp->last_token;
}
