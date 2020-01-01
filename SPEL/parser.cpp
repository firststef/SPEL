/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include "Parser.hpp"
#include "Lexer.hpp"
#define inline

void yyerror(YYLTYPE *locp, ParseState* parse_state, yyscan_t scanner, const char *msg);
std::shared_ptr<VariableDeclaration> search_variable(std::string name);
std::shared_ptr<VariableDeclaration> search_variable_in_class(std::string name, std::string class_object);

void pop_stack_context(ParseState* parse_state);
#define POP_STACK_CONTEXT pop_stack_context(parse_state);

#define THROW_ERROR(msg) yyerror (&yylloc, parse_state, scanner, msg); YYERROR;

#line 85 "parser.cpp"

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 16 "parser.y"


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

#line 164 "parser.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LEQ = 258,
    BEQ = 259,
    EQ = 260,
    NEQ = 261,
    INT = 262,
    OF = 263,
    FLOAT = 264,
    CHAR = 265,
    STRING = 266,
    NOT = 267,
    BGNF = 268,
    ENDF = 269,
    AND = 270,
    OR = 271,
    RET = 272,
    CLASS = 273,
    CONST = 274,
    BOOL = 275,
    ELSE = 276,
    IF = 277,
    FOR = 278,
    WHILE = 279,
    ENDWHILE = 280,
    BEGINIF = 281,
    BEGINELSE = 282,
    ENDELSE = 283,
    ENDIF = 284,
    ENDFOR = 285,
    VOID = 286,
    IN = 287,
    EVAL = 288,
    BG = 289,
    BGNP = 290,
    ENDCLASS = 291,
    CRAFT = 292,
    BSTOW = 293,
    ENCH = 294,
    WITH = 295,
    SACRF = 296,
    TIME = 297,
    CHNT = 298,
    ID = 299,
    STR = 300,
    NR = 301,
    NRF = 302,
    CHR = 303,
    TRUE = 304,
    FALSE = 305,
    IFX = 306,
    UMINUS = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 103 "parser.y"

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
	Return* ret;

	std::vector< std::shared_ptr<Expression>>* exprs;

#line 250 "parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (ParseState* parse_state, yyscan_t scanner);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   505

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  158
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  342

#define YYUNDEFTOK  2
#define YYMAXUTOK   307

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    58,     2,     2,
      65,    66,    56,    54,    61,    55,    60,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,     2,
      52,     2,    53,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   128,   128,   146,   150,   156,   162,   166,   172,   178,
     185,   206,   210,   214,   220,   229,   244,   261,   268,   272,
     276,   280,   284,   300,   305,   316,   324,   342,   351,   357,
     363,   369,   375,   381,   387,   396,   405,   414,   420,   426,
     432,   441,   444,   452,   460,   465,   476,   479,   490,   497,
     501,   512,   527,   543,   562,   563,   568,   573,   574,   579,
     580,   585,   586,   591,   592,   593,   594,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   614,   615,
     616,   617,   618,   619,   620,   625,   630,   635,   636,   637,
     638,   639,   640,   645,   646,   647,   648,   649,   650,   651,
     652,   657,   662,   663,   668,   673,   678,   683,   688,   693,
     694,   699,   700,   701,   702,   703,   704,   709,   714,   715,
     727,   730,   738,   739,   740,   741,   744,   751,   782,   810,
     838,   862,   882,   902,   911,   919,   926,   933,   939,   946,
     953,   962,   977,   984,   991,   996,  1006,  1010,  1014,  1018,
    1022,  1035,  1049,  1052,  1061,  1065,  1069,  1075,  1087
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LEQ", "BEQ", "EQ", "NEQ", "INT", "OF",
  "FLOAT", "CHAR", "STRING", "NOT", "BGNF", "ENDF", "AND", "OR", "RET",
  "CLASS", "CONST", "BOOL", "ELSE", "IF", "FOR", "WHILE", "ENDWHILE",
  "BEGINIF", "BEGINELSE", "ENDELSE", "ENDIF", "ENDFOR", "VOID", "IN",
  "EVAL", "BG", "BGNP", "ENDCLASS", "CRAFT", "BSTOW", "ENCH", "WITH",
  "SACRF", "TIME", "CHNT", "ID", "STR", "NR", "NRF", "CHR", "TRUE",
  "FALSE", "IFX", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "UMINUS", "'.'", "','", "'['", "']'", "':'", "'('", "')'", "$accept",
  "sp", "compile_unit", "class_def", "class_body", "class_var", "type",
  "class_id", "class_id_initialization", "vector_size",
  "vector_initialization", "vector_body", "call_parameters",
  "vector_position", "const_class_id", "f_parameters", "f_parameter",
  "class_f", "f_declaration_parameters", "declaration_parameters",
  "declaration_parameter", "function_body", "function_instruction",
  "while_instr", "while_condition", "boolean", "check", "while_body",
  "if_instr", "if_condition", "if_body", "elif_body", "for_instr",
  "for_sintax", "for_iterator", "for_1", "for_body", "eval_expr", "var",
  "expr", "no_return_function_body", "function_def", "statement",
  "declaration", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    60,    62,    43,    45,    42,    47,    37,   307,
      46,    44,    91,    93,    58,    40,    41
};
# endif

#define YYPACT_NINF -225

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-225)))

#define YYTABLE_NINF -112

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -16,   271,    11,  -225,  -225,  -225,  -225,   346,   -19,  -225,
     -34,   -18,   -12,    73,    30,   316,    49,    84,  -225,  -225,
     271,  -225,   116,  -225,  -225,  -225,  -225,   271,   271,  -225,
    -225,    89,    97,     8,  -225,  -225,  -225,  -225,  -225,  -225,
     373,   373,    90,  -225,   242,   138,   175,   108,   123,   175,
     126,   -31,   330,   129,     9,   133,  -225,   137,  -225,  -225,
     143,   136,   140,   -14,  -225,   105,  -225,   373,   373,   373,
     373,   373,   158,   138,   138,   346,   222,  -225,    28,   130,
    -225,   195,   178,  -225,   147,  -225,   174,   150,   165,   177,
     197,   -29,   179,   202,   346,   -14,   333,   214,   373,   333,
     194,   213,   200,  -225,   196,  -225,   171,   171,  -225,  -225,
    -225,  -225,  -225,  -225,  -225,   207,   151,   175,   175,   248,
     373,   373,   373,   373,   373,   373,    32,   221,   309,   219,
     223,  -225,   -28,   224,   360,   239,  -225,   246,   230,   229,
    -225,   257,    38,   104,   301,   366,   371,   376,   381,  -225,
     241,  -225,   245,  -225,   309,   242,   243,   -14,   262,   -14,
     303,    41,  -225,  -225,   221,   288,   242,   242,   242,   242,
     242,   242,   269,   -24,  -225,  -225,  -225,   251,   258,   360,
     256,   287,   305,   221,  -225,   221,  -225,   313,  -225,  -225,
     330,  -225,   308,   295,  -225,   302,  -225,  -225,   360,   320,
    -225,  -225,  -225,   306,   346,  -225,   328,   329,   327,   -14,
     324,   360,   322,  -225,   310,   333,   334,   343,   175,   175,
     383,   375,   359,   -14,   221,   142,   353,   354,    78,    10,
     392,  -225,  -225,  -225,   380,   399,   103,   323,  -225,   385,
     405,   393,   346,   333,   284,   395,  -225,  -225,   221,  -225,
     398,  -225,   401,  -225,  -225,  -225,   221,  -225,   333,   402,
    -225,  -225,   404,  -225,   221,   221,   403,   406,   407,   420,
     346,   -14,   333,   408,   410,   103,   103,   454,  -225,   433,
     412,  -225,   415,   413,   -14,    -2,   462,  -225,   -14,   450,
     416,  -225,  -225,  -225,   419,   421,  -225,   442,   423,   422,
     424,   426,  -225,  -225,  -225,  -225,   412,   360,  -225,  -225,
     386,   427,   440,  -225,   428,  -225,  -225,  -225,  -225,   346,
    -225,   446,   432,  -225,  -225,   434,   430,   391,   294,  -225,
     436,   346,  -225,   360,  -225,   -14,  -225,   437,  -225,   431,
    -225,   396
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,    18,    19,    20,    21,     0,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     2,
       7,   158,     0,   145,   148,   147,   149,     8,     9,   146,
       1,     0,     0,   120,   138,   135,   136,   137,   139,   140,
       0,     0,     0,   133,   118,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,     5,     6,
       0,     0,     0,     0,   132,     0,   157,     0,     0,     0,
       0,     0,     0,    11,    12,     0,     0,   104,    87,     0,
      94,   118,     0,   107,     0,    86,     0,     0,     0,     0,
       0,    23,     0,     0,     0,     0,     0,     0,     0,     0,
     122,     0,    48,    49,     0,   126,   127,   128,   129,   130,
     131,    10,    13,    14,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   154,     0,     0,     0,    41,    15,     0,     0,     0,
      46,     0,   120,   138,   135,   136,   137,   139,   140,    56,
       0,    47,    54,    40,     0,   119,     0,     0,     0,     0,
     121,    91,    88,    92,     0,   102,   100,    99,    98,    97,
      96,    95,     0,   109,   112,   113,   114,     0,     0,     0,
       0,     0,     0,    71,   101,    74,    82,     0,    83,    84,
       0,    59,     0,     0,    60,    61,   156,   155,     0,     0,
      16,    24,    42,     0,     0,   150,     0,     0,     0,     0,
       0,     0,     0,   134,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,    70,    85,     0,    63,     0,     0,    52,     0,
      25,     0,     0,     0,   122,     0,   153,    55,     0,   124,
       0,    51,   123,    89,    90,   105,     0,   103,     0,     0,
     117,   108,   111,   110,    72,    73,     0,     0,     0,     0,
       0,     0,     0,    65,     0,   143,   144,     0,    62,     0,
       0,   152,     0,     0,     0,   121,     0,    50,     0,     0,
       0,   116,    68,    69,     0,     0,    75,     0,     0,     0,
       0,     0,    64,   141,   142,    58,     0,     0,    26,   151,
     134,     0,     0,    57,     0,   106,   115,    77,    76,     0,
      78,     0,     0,    66,    53,    44,     0,   124,   123,   125,
       0,     0,    81,     0,    43,     0,    80,     0,    45,     0,
      79,   125
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -225,  -225,    -6,  -225,    35,     0,   -11,  -225,  -131,  -225,
     181,   166,   -92,   -93,  -225,   289,  -225,   -37,   344,   264,
    -225,  -159,  -224,    76,  -225,   -26,   429,  -225,    87,  -225,
    -225,  -225,    93,  -225,  -225,   277,  -225,    -7,   472,    14,
    -157,  -225,  -225,  -225
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    19,    20,    72,   183,    22,    92,   149,   203,
     308,   326,   150,   104,   133,   151,   152,    23,   193,   194,
     195,   184,   185,   186,    84,    77,    78,   187,   188,    79,
     165,   257,   189,    48,   177,   178,   261,   153,    43,    44,
     277,    27,    28,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    21,   139,   201,    53,   220,   312,   156,    74,   134,
     198,    30,   276,    87,    56,    88,    62,    93,   269,     1,
      21,    58,    59,    85,   231,    45,   232,    21,    21,   101,
     102,    46,   103,   135,   199,    89,    74,    74,   223,    80,
    -111,    90,    80,   117,   118,    73,   208,    47,   226,    94,
     270,   276,   276,    49,    64,    65,   218,   219,   -35,   -35,
      81,   -35,   -35,    81,   214,   260,   216,   238,   114,    80,
      63,    95,   271,    73,    73,   172,   173,    24,   174,   175,
     176,   106,   107,   108,   109,   110,    50,   138,    25,   286,
     116,   162,   163,    54,    26,    51,    24,   289,   -27,   -27,
     209,   -27,   -27,    24,    24,   292,   293,    25,   112,   113,
      80,    80,   155,    26,    25,    25,   245,   192,   303,   304,
      26,    26,   266,   250,   267,    10,    11,    12,    55,    57,
     259,    81,    81,    33,   166,   167,   168,   169,   170,   171,
      15,    61,   181,   192,   268,     3,   182,     4,     5,     6,
      66,   283,    82,    83,   120,   121,   122,   123,     9,    67,
      68,    69,    70,    71,   -31,   -31,   290,   -31,   -31,    13,
      86,   105,   227,    91,    96,    15,   325,    99,   299,   234,
     300,    97,    18,    98,   100,   172,   262,    75,   174,   175,
     176,   311,   253,   254,   111,   314,   119,   241,   120,   121,
     122,   123,   325,   124,   125,    67,    68,    69,    70,    71,
     126,    80,    80,   127,    31,   128,   129,   105,    32,    33,
      34,    35,    36,    37,    38,    39,   192,    69,    70,    71,
      40,   130,    81,    81,    75,   282,   275,   131,   179,   136,
      76,   132,   339,    10,    11,    12,   137,   124,   125,    67,
      68,    69,    70,    71,   180,   154,   157,   158,    15,   160,
     181,    31,   159,   298,   182,    32,    33,    34,    35,    36,
      37,    38,    39,   161,   164,   275,   275,    40,     3,   196,
       4,     5,     6,   197,   200,   202,   204,    41,     7,     8,
     205,     9,   206,    10,    11,    12,    67,    68,    69,    70,
      71,   207,    13,   215,    14,   210,   211,   213,    15,   221,
      16,   217,   330,   222,    17,    18,     3,   224,     4,     5,
       6,   228,   225,     3,   337,     4,     5,     6,   190,     9,
       3,   229,     4,     5,     6,    52,     9,     3,   233,     4,
       5,     6,   190,     9,   -36,   -36,   284,   -36,   -36,   230,
       9,   191,   235,    18,   -37,   -37,   335,   -37,   -37,   236,
      18,   -28,   -28,   237,   -28,   -28,   239,    18,   242,   240,
     243,   244,    31,   249,    18,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   246,    31,   248,   252,    40,    32,
      33,    34,    35,    36,    37,    38,    39,   251,    41,    31,
     258,    40,   256,   141,   142,   143,   144,   145,   146,   147,
     148,    41,   255,   264,   265,    40,    32,    33,    34,    35,
      36,    37,    38,    39,   273,    41,   -29,   -29,    40,   -29,
     -29,   -30,   -30,   272,   -30,   -30,   -32,   -32,    41,   -32,
     -32,   -33,   -33,   280,   -33,   -33,   -34,   -34,   279,   -34,
     -34,   -38,   -38,   281,   -38,   -38,   -39,   -39,   285,   -39,
     -39,   274,   287,   288,   297,   291,   223,   296,   305,   294,
     301,   306,   295,   302,   307,   309,   313,   310,   315,   317,
     316,   318,   319,   320,   328,   321,   331,   324,   322,   323,
     327,   329,   332,   334,   341,   333,   336,   340,   212,   338,
     247,   278,   263,    60,     0,   115
};

static const yytype_int16 yycheck[] =
{
       7,     1,    95,   134,    15,   164,     8,    99,    45,    38,
      38,     0,   236,    44,    20,    46,     8,     8,     8,    35,
      20,    27,    28,    49,   183,    44,   185,    27,    28,    43,
      44,    65,    46,    62,    62,    66,    73,    74,    62,    46,
      64,    52,    49,    15,    16,    45,     8,    65,   179,    40,
      40,   275,   276,    65,    40,    41,    15,    16,    60,    61,
      46,    63,    64,    49,   157,   224,   159,   198,    75,    76,
      62,    62,    62,    73,    74,    43,    44,     1,    46,    47,
      48,    67,    68,    69,    70,    71,    13,    94,     1,   248,
      76,   117,   118,    44,     1,    65,    20,   256,    60,    61,
      62,    63,    64,    27,    28,   264,   265,    20,    73,    74,
     117,   118,    98,    20,    27,    28,   209,   128,   275,   276,
      27,    28,    44,   215,    46,    22,    23,    24,    44,    13,
     223,   117,   118,    44,   120,   121,   122,   123,   124,   125,
      37,    44,    39,   154,    66,     7,    43,     9,    10,    11,
      60,   243,    44,    30,     3,     4,     5,     6,    20,    54,
      55,    56,    57,    58,    60,    61,   258,    63,    64,    31,
      44,    66,   179,    44,    41,    37,   307,    41,   271,   190,
     272,    44,    44,    40,    44,    43,    44,    12,    46,    47,
      48,   284,   218,   219,    36,   288,    66,   204,     3,     4,
       5,     6,   333,    52,    53,    54,    55,    56,    57,    58,
      32,   218,   219,    66,    39,    41,    66,    66,    43,    44,
      45,    46,    47,    48,    49,    50,   237,    56,    57,    58,
      55,    66,   218,   219,    12,   242,   236,    60,    17,    60,
      65,    44,   335,    22,    23,    24,    44,    52,    53,    54,
      55,    56,    57,    58,    33,    41,    62,    44,    37,    63,
      39,    39,    62,   270,    43,    43,    44,    45,    46,    47,
      48,    49,    50,    66,    26,   275,   276,    55,     7,    60,
       9,    10,    11,    60,    60,    46,    40,    65,    17,    18,
      60,    20,    63,    22,    23,    24,    54,    55,    56,    57,
      58,    44,    31,    41,    33,    64,    61,    64,    37,    21,
      39,     8,   319,    44,    43,    44,     7,    66,     9,    10,
      11,    65,    64,     7,   331,     9,    10,    11,    19,    20,
       7,    44,     9,    10,    11,    19,    20,     7,    25,     9,
      10,    11,    19,    20,    60,    61,    62,    63,    64,    44,
      20,    42,    44,    44,    60,    61,    62,    63,    64,    64,
      44,    60,    61,    61,    63,    64,    46,    44,    40,    63,
      41,    44,    39,    63,    44,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    60,    39,    64,    44,    55,    43,
      44,    45,    46,    47,    48,    49,    50,    63,    65,    39,
      41,    55,    27,    43,    44,    45,    46,    47,    48,    49,
      50,    65,    29,    60,    60,    55,    43,    44,    45,    46,
      47,    48,    49,    50,    44,    65,    60,    61,    55,    63,
      64,    60,    61,    41,    63,    64,    60,    61,    65,    63,
      64,    60,    61,    38,    63,    64,    60,    61,    63,    63,
      64,    60,    61,    60,    63,    64,    60,    61,    63,    63,
      64,    62,    64,    62,    44,    63,    62,    60,    14,    66,
      62,    38,    66,    63,    62,    60,    14,    64,    28,    60,
      64,    60,    40,    60,    44,    63,    40,   306,    64,    63,
      63,    63,    60,    63,    63,    61,    60,    60,   154,   333,
     211,   237,   225,    31,    -1,    76
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    35,    68,     7,     9,    10,    11,    17,    18,    20,
      22,    23,    24,    31,    33,    37,    39,    43,    44,    69,
      70,    72,    73,    84,    90,    95,    99,   108,   109,   110,
       0,    39,    43,    44,    45,    46,    47,    48,    49,    50,
      55,    65,   104,   105,   106,    44,    65,    65,   100,    65,
      13,    65,    19,    73,    44,    44,    69,    13,    69,    69,
     105,    44,     8,    62,   106,   106,    60,    54,    55,    56,
      57,    58,    71,    72,    84,    12,    65,    92,    93,    96,
     104,   106,    44,    30,    91,    92,    44,    44,    46,    66,
      73,    44,    74,     8,    40,    62,    41,    44,    40,    41,
      44,    43,    44,    46,    80,    66,   106,   106,   106,   106,
     106,    36,    71,    71,   104,    93,   106,    15,    16,    66,
       3,     4,     5,     6,    52,    53,    32,    66,    41,    66,
      66,    60,    44,    81,    38,    62,    60,    44,   104,    80,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    75,
      79,    82,    83,   104,    41,   106,    79,    62,    44,    62,
      63,    66,    92,    92,    26,    97,   106,   106,   106,   106,
     106,   106,    43,    44,    46,    47,    48,   101,   102,    17,
      33,    39,    43,    72,    88,    89,    90,    94,    95,    99,
      19,    42,    73,    85,    86,    87,    60,    60,    38,    62,
      60,    75,    46,    76,    40,    60,    63,    44,     8,    62,
      64,    61,    85,    64,    80,    41,    80,     8,    15,    16,
      88,    21,    44,    62,    66,    64,    75,   104,    65,    44,
      44,    88,    88,    25,    73,    44,    64,    61,    75,    46,
      63,   104,    40,    41,    44,    80,    60,    82,    64,    63,
      79,    63,    44,    92,    92,    29,    27,    98,    41,    80,
      88,   103,    44,   102,    60,    60,    44,    46,    66,     8,
      40,    62,    41,    44,    62,    72,    89,   107,    86,    63,
      38,    60,   104,    79,    62,    63,    88,    64,    62,    88,
      79,    63,    88,    88,    66,    66,    60,    44,   104,    80,
      79,    62,    63,   107,   107,    14,    38,    62,    77,    60,
      64,    80,     8,    14,    80,    28,    64,    60,    60,    40,
      60,    63,    64,    63,    77,    75,    78,    63,    44,    63,
     104,    40,    60,    61,    63,    62,    60,   104,    78,    80,
      60,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    68,    69,    69,    69,    69,    69,    69,
      70,    71,    71,    71,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    74,    74,    74,    74,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    76,    76,    77,    78,    78,    79,    79,    80,    80,
      80,    80,    81,    81,    82,    82,    83,    84,    84,    85,
      85,    86,    86,    87,    87,    87,    87,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    90,    91,    92,    92,    92,
      92,    92,    92,    93,    93,    93,    93,    93,    93,    93,
      93,    94,    95,    95,    96,    97,    98,    99,   100,   101,
     101,   102,   102,   102,   102,   102,   102,   103,   104,   104,
     105,   105,   105,   105,   105,   105,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   107,   107,   107,   107,   108,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   110
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     2,     1,     1,     1,
       4,     1,     1,     2,     2,     4,     5,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     6,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     3,     6,     6,     9,
       1,     0,     1,     3,     1,     3,     1,     1,     1,     1,
       5,     4,     3,     6,     1,     3,     1,     8,     8,     1,
       1,     1,     3,     2,     4,     3,     5,     2,     4,     4,
       2,     1,     3,     3,     1,     4,     5,     5,     5,     8,
       7,     6,     1,     1,     1,     6,     1,     1,     3,     5,
       5,     3,     3,     2,     1,     3,     3,     3,     3,     3,
       3,     1,     5,     7,     1,     3,     3,     3,     6,     1,
       3,     1,     1,     1,     1,     5,     4,     1,     1,     4,
       1,     4,     3,     6,     6,     9,     3,     3,     3,     3,
       3,     3,     2,     1,     5,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       5,     8,     7,     6,     4,     5,     5,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, parse_state, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, parse_state, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, ParseState* parse_state, yyscan_t scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  YYUSE (parse_state);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, ParseState* parse_state, yyscan_t scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp, parse_state, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, ParseState* parse_state, yyscan_t scanner)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , parse_state, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, parse_state, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, ParseState* parse_state, yyscan_t scanner)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (parse_state);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (ParseState* parse_state, yyscan_t scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 128 "parser.y"
    { 
		/*for (auto& holder : $2->block_holder) {
			if (holder.type == DECLARATION_TYPE) {
				if (holder->decl_dec->type == VAR_FUNC) {

				}
			}
		}*/

		

		auto x = 0;

		THROW_ERROR("da");

		//parse_state->rootNode = std::make_shared<Node>();
		//parse_state->rootNode->c_unit = std::shared_ptr<CompileUnit>($2);
	}
#line 1751 "parser.cpp"
    break;

  case 3:
#line 146 "parser.y"
    {  }
#line 1757 "parser.cpp"
    break;

  case 4:
#line 150 "parser.y"
    {
		parse_state->classes.push_back(std::shared_ptr<ClassDefinition>((yyvsp[-1].class_def)));

		//$$ = new CompileUnit();
		//$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
	}
#line 1768 "parser.cpp"
    break;

  case 5:
#line 156 "parser.y"
    {
		parse_state->functions.push_back(std::shared_ptr<FunctionDeclaration>((yyvsp[-1].func_decl)));
		
		//$$ = new CompileUnit();
		//$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
	}
#line 1779 "parser.cpp"
    break;

  case 6:
#line 162 "parser.y"
    {
		/*$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));*/
	}
#line 1788 "parser.cpp"
    break;

  case 7:
#line 166 "parser.y"
    { 
		parse_state->classes.push_back(std::shared_ptr<ClassDefinition>((yyvsp[0].class_def)));

		/*$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));  */
	}
#line 1799 "parser.cpp"
    break;

  case 8:
#line 172 "parser.y"
    { 
		parse_state->functions.push_back(std::shared_ptr<FunctionDeclaration>((yyvsp[0].func_decl)));

		/*$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));*/
	}
#line 1810 "parser.cpp"
    break;

  case 9:
#line 178 "parser.y"
    { 
		/*$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));*/
	}
#line 1819 "parser.cpp"
    break;

  case 10:
#line 185 "parser.y"
    { 
	  	/*$$ = new BlockHolder(); 
		$$->type=CLASS_TYPE;

		$$->class_dec = std::shared_ptr<ClassDefinition>($3);

		$$->class_dec->name = $2->value;
		delete $2;*/
		
		(yyval.class_def) = (yyvsp[-1].class_def);

		//verificare ca nu mai este o data definita clasa cu acelasi ID

		(yyvsp[-1].class_def)->name = (yyvsp[-2].string_val)->value; 
		delete (yyvsp[-2].string_val);

		POP_STACK_CONTEXT;
	}
#line 1842 "parser.cpp"
    break;

  case 11:
#line 206 "parser.y"
    { 
		(yyval.class_def) = new ClassDefinition();
		(yyval.class_def)->decl_holders.push_back(*(yyvsp[0].dec_holder));
	}
#line 1851 "parser.cpp"
    break;

  case 12:
#line 210 "parser.y"
    { 
		(yyval.class_def) = new ClassDefinition();
		(yyval.class_def)->decl_holders.push_back(*(yyvsp[0].dec_holder));
	}
#line 1860 "parser.cpp"
    break;

  case 13:
#line 214 "parser.y"
    { 
		(yyval.class_def)=new ClassDefinition();
		(yyval.class_def)->decl_holders.push_back(*(yyvsp[-1].dec_holder));
		for (auto& holder : (yyvsp[0].class_def)->decl_holders)
			(yyval.class_def)->decl_holders.push_back(holder);
  }
#line 1871 "parser.cpp"
    break;

  case 14:
#line 220 "parser.y"
    { 
		(yyval.class_def) = new ClassDefinition();
		(yyval.class_def)->decl_holders.push_back(*(yyvsp[-1].dec_holder));
		for (auto& holder : (yyvsp[0].class_def)->decl_holders)
			(yyval.class_def)->decl_holders.push_back(holder);
	}
#line 1882 "parser.cpp"
    break;

  case 15:
#line 229 "parser.y"
    { 
		(yyval.dec_holder)=new DeclarationHolder();
		(yyval.dec_holder)->type=VAR_DEC;

		(yyvsp[-1].variable_dec)->type = (yyvsp[-2].variable_dec)->type;
		//if($3->type!=NONE) if($3->type!=$2->type) yyerror();
		//cateodata tipul $3 nu este setat (cand nu am initializat)
		
		(yyvsp[-1].variable_dec)->class_name = (yyvsp[-2].variable_dec)->class_name;
		(yyval.dec_holder)->var_dec = std::shared_ptr<VariableDeclaration>((yyvsp[-1].variable_dec));
		delete (yyvsp[-2].variable_dec);

		//validare daca exista
		parse_state->Stack.top().push_back((yyval.dec_holder)->var_dec);
	}
#line 1902 "parser.cpp"
    break;

  case 16:
#line 244 "parser.y"
    {  

		  (yyval.dec_holder) = new DeclarationHolder();
		  (yyval.dec_holder)->type = VAR_DEC;

		  (yyvsp[-1].variable_dec)->type = (yyvsp[-2].variable_dec)->type;
		  (yyvsp[-1].variable_dec)->class_name = (yyvsp[-2].variable_dec)->class_name;
		  (yyvsp[-1].variable_dec)->is_const = true;
		  (yyval.dec_holder)->var_dec = std::shared_ptr<VariableDeclaration>((yyvsp[-1].variable_dec));
		  delete (yyvsp[-2].variable_dec);

		  //validare daca exista
		  parse_state->Stack.top().push_back((yyval.dec_holder)->var_dec);
	}
#line 1921 "parser.cpp"
    break;

  case 17:
#line 261 "parser.y"
    { 
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->type=TYPE_OBJECT;
		(yyval.variable_dec)->class_name = (yyvsp[0].string_val)->value;
		//verificare daca ID este in vectorul de clase
		delete (yyvsp[0].string_val);
	}
#line 1933 "parser.cpp"
    break;

  case 18:
#line 268 "parser.y"
    { 
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->type=TYPE_INT;
	}
#line 1942 "parser.cpp"
    break;

  case 19:
#line 272 "parser.y"
    { 
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->type=TYPE_FLOAT;	 
	}
#line 1951 "parser.cpp"
    break;

  case 20:
#line 276 "parser.y"
    { 
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->type=TYPE_CHAR;
	}
#line 1960 "parser.cpp"
    break;

  case 21:
#line 280 "parser.y"
    { 
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->type=TYPE_STRING;
	}
#line 1969 "parser.cpp"
    break;

  case 22:
#line 284 "parser.y"
    { 
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->type=TYPE_BOOL; 
	}
#line 1978 "parser.cpp"
    break;

  case 23:
#line 300 "parser.y"
    { 
		(yyval.variable_dec) = new VariableDeclaration();
		(yyval.variable_dec)->name = (yyvsp[0].string_val)->value;
		delete (yyvsp[0].string_val);
	}
#line 1988 "parser.cpp"
    break;

  case 24:
#line 305 "parser.y"
    { 
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->name = (yyvsp[-2].string_val)->value;
		delete (yyvsp[-2].string_val);
		(yyval.variable_dec)->type = (yyvsp[0].expr)->type;
		(yyval.variable_dec)->value = (yyvsp[0].expr)->value;
		//de verificat ca in class id_initialization toate 
		//variabilele si constantele sunt type

		(yyval.variable_dec)->expr = std::shared_ptr<Expression>((yyvsp[0].expr));
	}
#line 2004 "parser.cpp"
    break;

  case 25:
#line 316 "parser.y"
    { 
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->name= (yyvsp[-3].string_val)->value;
		delete (yyvsp[-3].string_val);

		(yyval.variable_dec)->size_of_vector = (yyvsp[-1].int_val)->value;
		delete (yyvsp[-1].int_val);
	}
#line 2017 "parser.cpp"
    break;

  case 26:
#line 324 "parser.y"
    {
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->name = (yyvsp[-5].string_val)->value;
		delete (yyvsp[-5].string_val);

		(yyval.variable_dec)->size_of_vector=(yyvsp[-3].int_val)->value;
		delete (yyvsp[-3].int_val);

		//should do size validation
		//should do vector_init to ex
		(yyval.variable_dec)->exprs = *(yyvsp[0].exprs);
		delete (yyvsp[0].exprs);
	}
#line 2035 "parser.cpp"
    break;

  case 27:
#line 342 "parser.y"
    { 
		(yyval.expr) = new Expression();
		(yyval.expr)->name = (yyvsp[0].string_val)->value;
		(yyval.expr)->e_type = VARIABLE_NAME;

		//$$->value = search($$->name)->value;

		delete (yyvsp[0].string_val);
	}
#line 2049 "parser.cpp"
    break;

  case 28:
#line 351 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type=TYPE_INT;
		(yyval.expr)->value.int_val = std::shared_ptr<IntVal>((yyvsp[0].int_val));
		(yyval.expr)->e_type = VALUE;
	}
#line 2060 "parser.cpp"
    break;

  case 29:
#line 357 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type = TYPE_FLOAT;
		(yyval.expr)->value.float_val = std::shared_ptr<FloatVal>((yyvsp[0].float_val));
		(yyval.expr)->e_type = VALUE;
	}
#line 2071 "parser.cpp"
    break;

  case 30:
#line 363 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type = TYPE_CHAR;
		(yyval.expr)->value.char_val = std::shared_ptr<CharVal>((yyvsp[0].char_val));
		(yyval.expr)->e_type = VALUE;
	}
#line 2082 "parser.cpp"
    break;

  case 31:
#line 369 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type = TYPE_STRING;
		(yyval.expr)->value.string_val = std::shared_ptr<StringVal>((yyvsp[0].string_val));
		(yyval.expr)->e_type = VALUE;
	}
#line 2093 "parser.cpp"
    break;

  case 32:
#line 375 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type = TYPE_BOOL;
		(yyval.expr)->value.bool_val = std::shared_ptr<BoolVal>((yyvsp[0].bool_val));
		(yyval.expr)->e_type = VALUE;
	}
#line 2104 "parser.cpp"
    break;

  case 33:
#line 381 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type = TYPE_BOOL;
		(yyval.expr)->value.bool_val = std::shared_ptr<BoolVal>((yyvsp[0].bool_val));
		(yyval.expr)->e_type = VALUE;
	}
#line 2115 "parser.cpp"
    break;

  case 34:
#line 387 "parser.y"
    { 
		(yyval.expr) = new Expression();

		(yyval.expr)->call = std::shared_ptr<FunctionCall>((yyvsp[-1].func_call));
		(yyval.expr)->call->name = (yyvsp[-3].string_val)->value;
		(yyval.expr)->e_type = CALL;
		//search for function template - validate name and params
		
	}
#line 2129 "parser.cpp"
    break;

  case 35:
#line 396 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->name = (yyvsp[-3].string_val)->value;
		(yyval.expr)->e_type = VECTOR_NAME;
		(yyval.expr)->position = (yyvsp[-1].int_val)->value; //trebuie evaluata aici poz
		delete (yyvsp[-1].int_val);
		//to be implemented - need type deduction
		//by searching for variable
	}
#line 2143 "parser.cpp"
    break;

  case 36:
#line 405 "parser.y"
    { //ignore all OF statements
		(yyval.expr)=new Expression();

		(yyval.expr)->var = search_variable_in_class((yyvsp[-2].string_val)->value, (yyvsp[0].string_val)->value); //if null, fail
		(yyval.expr)->e_type = REFERENCE;
		
		//to be implemented - need type deduction
		//by searching for variable
	}
#line 2157 "parser.cpp"
    break;

  case 37:
#line 414 "parser.y"
    { 
		(yyval.expr)=new Expression();

		//to be implemented - need type deduction
		//by searching for variable
	}
#line 2168 "parser.cpp"
    break;

  case 38:
#line 420 "parser.y"
    { 
		(yyval.expr)=new Expression(); 

		//to be implemented - need type deduction
		//by searching for variable
	}
#line 2179 "parser.cpp"
    break;

  case 39:
#line 426 "parser.y"
    { 
		(yyval.expr)=new Expression();

		//to be implemented - need type deduction
		//by searching for variable
	}
#line 2190 "parser.cpp"
    break;

  case 40:
#line 432 "parser.y"
    { 
		(yyval.expr) = (yyvsp[0].expr);
		//asta nu am facut-o noi?
	}
#line 2199 "parser.cpp"
    break;

  case 41:
#line 441 "parser.y"
    {
	  (yyval.int_val) = new IntVal({ 0 });
	}
#line 2207 "parser.cpp"
    break;

  case 42:
#line 444 "parser.y"
    {
		(yyval.int_val) = new IntVal({(yyvsp[0].int_val)->value});
		delete (yyvsp[0].int_val);
	}
#line 2216 "parser.cpp"
    break;

  case 43:
#line 452 "parser.y"
    {
		(yyval.exprs) = (yyvsp[-1].exprs);
	}
#line 2224 "parser.cpp"
    break;

  case 44:
#line 460 "parser.y"
    { 
		(yyval.exprs) = new std::vector< std::shared_ptr<Expression>>();
		
		(yyval.exprs)->push_back(std::shared_ptr<Expression>((yyvsp[0].expr)));
	}
#line 2234 "parser.cpp"
    break;

  case 45:
#line 465 "parser.y"
    { 
		(yyval.exprs) = new std::vector< std::shared_ptr<Expression>>(*(yyvsp[0].exprs));
		delete (yyvsp[0].exprs);

		(yyval.exprs)->push_back(std::shared_ptr<Expression>((yyvsp[-2].expr)));
	}
#line 2245 "parser.cpp"
    break;

  case 46:
#line 476 "parser.y"
    {
		(yyval.func_call) = new FunctionCall();
	}
#line 2253 "parser.cpp"
    break;

  case 47:
#line 479 "parser.y"
    { 
		(yyval.func_call) = new FunctionCall();

		(yyval.func_call)->params = *(yyvsp[0].exprs);
		delete (yyvsp[0].exprs);
	}
#line 2264 "parser.cpp"
    break;

  case 48:
#line 490 "parser.y"
    { 
		//asta e facut tot de mine, pentru ca am avut nevoie mai jos de unde am inceput

		(yyval.int_val) = new IntVal();
		(yyval.int_val)->value=search_variable((yyvsp[0].string_val)->value)->value.int_val->value;
		delete (yyvsp[0].string_val);
	}
#line 2276 "parser.cpp"
    break;

  case 49:
#line 497 "parser.y"
    { 
		(yyval.int_val) = new IntVal();
		(yyval.int_val) = (yyvsp[0].int_val);
	}
#line 2285 "parser.cpp"
    break;

  case 50:
#line 501 "parser.y"
    { 
		(yyval.int_val)=new IntVal();

		auto auxExpression = new Expression();
		auxExpression->call = std::shared_ptr<FunctionCall>((yyvsp[-1].func_call));
		auxExpression->call->name = (yyvsp[-3].string_val)->value;
		auxExpression->e_type = CALL;
		
		//verificare daca functia e INT
		//if (auxExpression->call->return_type!=TYPE_INT) yyerror();
	}
#line 2301 "parser.cpp"
    break;

  case 51:
#line 512 "parser.y"
    { 
	  (yyval.int_val) = new IntVal();

	  //to be implemented - search in vector
	}
#line 2311 "parser.cpp"
    break;

  case 52:
#line 527 "parser.y"
    { 
		(yyval.variable_dec) = new VariableDeclaration();

		(yyval.variable_dec)->name = (yyvsp[-2].string_val)->value;
		delete (yyvsp[-2].string_val);
		(yyval.variable_dec)->type = (yyvsp[0].expr)->type;
		(yyval.variable_dec)->value = (yyvsp[0].expr)->value;
		(yyval.variable_dec)->is_const = true;

		//de verificat ca in class id_initialization toate 
		//variabilele si constantele sunt type

		//expresia trebuie musai sa aiba value, fiind const
		//altfel, arunca exceptie
		(yyval.variable_dec)->expr = std::shared_ptr<Expression>((yyvsp[0].expr));
	}
#line 2332 "parser.cpp"
    break;

  case 53:
#line 543 "parser.y"
    {
		(yyval.variable_dec) = new VariableDeclaration();
		(yyval.variable_dec)->name = (yyvsp[-5].string_val)->value;
		delete (yyvsp[-5].string_val);

		(yyval.variable_dec)->size_of_vector = (yyvsp[-3].int_val)->value;
		delete (yyvsp[-3].int_val);

		//should do size validation
		//should do vector_init to ex

		//trebuie adaugat type TYPE_VECTOR
		(yyval.variable_dec)->exprs = *(yyvsp[0].exprs);
		delete (yyvsp[0].exprs);
	}
#line 2352 "parser.cpp"
    break;

  case 54:
#line 562 "parser.y"
    {  }
#line 2358 "parser.cpp"
    break;

  case 55:
#line 563 "parser.y"
    {  }
#line 2364 "parser.cpp"
    break;

  case 56:
#line 568 "parser.y"
    {/*nu stiu daca aici este corect, dar eu presupun ca da*/  }
#line 2370 "parser.cpp"
    break;

  case 57:
#line 573 "parser.y"
    {  }
#line 2376 "parser.cpp"
    break;

  case 58:
#line 574 "parser.y"
    {  }
#line 2382 "parser.cpp"
    break;

  case 59:
#line 579 "parser.y"
    {  }
#line 2388 "parser.cpp"
    break;

  case 60:
#line 580 "parser.y"
    {  }
#line 2394 "parser.cpp"
    break;

  case 61:
#line 585 "parser.y"
    {  }
#line 2400 "parser.cpp"
    break;

  case 62:
#line 586 "parser.y"
    {  }
#line 2406 "parser.cpp"
    break;

  case 63:
#line 591 "parser.y"
    {  }
#line 2412 "parser.cpp"
    break;

  case 64:
#line 592 "parser.y"
    {  }
#line 2418 "parser.cpp"
    break;

  case 65:
#line 593 "parser.y"
    {  }
#line 2424 "parser.cpp"
    break;

  case 66:
#line 594 "parser.y"
    {  }
#line 2430 "parser.cpp"
    break;

  case 67:
#line 599 "parser.y"
    {  }
#line 2436 "parser.cpp"
    break;

  case 68:
#line 600 "parser.y"
    {  }
#line 2442 "parser.cpp"
    break;

  case 69:
#line 601 "parser.y"
    {  }
#line 2448 "parser.cpp"
    break;

  case 70:
#line 602 "parser.y"
    {  }
#line 2454 "parser.cpp"
    break;

  case 71:
#line 603 "parser.y"
    {  }
#line 2460 "parser.cpp"
    break;

  case 72:
#line 604 "parser.y"
    {  }
#line 2466 "parser.cpp"
    break;

  case 73:
#line 605 "parser.y"
    {  }
#line 2472 "parser.cpp"
    break;

  case 74:
#line 606 "parser.y"
    {  }
#line 2478 "parser.cpp"
    break;

  case 75:
#line 607 "parser.y"
    {  }
#line 2484 "parser.cpp"
    break;

  case 76:
#line 608 "parser.y"
    {  }
#line 2490 "parser.cpp"
    break;

  case 77:
#line 609 "parser.y"
    {  }
#line 2496 "parser.cpp"
    break;

  case 78:
#line 614 "parser.y"
    {  }
#line 2502 "parser.cpp"
    break;

  case 79:
#line 615 "parser.y"
    {  }
#line 2508 "parser.cpp"
    break;

  case 80:
#line 616 "parser.y"
    {  }
#line 2514 "parser.cpp"
    break;

  case 81:
#line 617 "parser.y"
    {  }
#line 2520 "parser.cpp"
    break;

  case 82:
#line 618 "parser.y"
    {  }
#line 2526 "parser.cpp"
    break;

  case 83:
#line 619 "parser.y"
    {  }
#line 2532 "parser.cpp"
    break;

  case 84:
#line 620 "parser.y"
    {  }
#line 2538 "parser.cpp"
    break;

  case 85:
#line 625 "parser.y"
    {  }
#line 2544 "parser.cpp"
    break;

  case 86:
#line 630 "parser.y"
    {  }
#line 2550 "parser.cpp"
    break;

  case 87:
#line 635 "parser.y"
    {  }
#line 2556 "parser.cpp"
    break;

  case 88:
#line 636 "parser.y"
    {  }
#line 2562 "parser.cpp"
    break;

  case 92:
#line 640 "parser.y"
    {  }
#line 2568 "parser.cpp"
    break;

  case 93:
#line 645 "parser.y"
    {  }
#line 2574 "parser.cpp"
    break;

  case 94:
#line 646 "parser.y"
    {  }
#line 2580 "parser.cpp"
    break;

  case 95:
#line 647 "parser.y"
    {  }
#line 2586 "parser.cpp"
    break;

  case 96:
#line 648 "parser.y"
    {  }
#line 2592 "parser.cpp"
    break;

  case 97:
#line 649 "parser.y"
    {  }
#line 2598 "parser.cpp"
    break;

  case 98:
#line 650 "parser.y"
    {  }
#line 2604 "parser.cpp"
    break;

  case 99:
#line 651 "parser.y"
    {  }
#line 2610 "parser.cpp"
    break;

  case 100:
#line 652 "parser.y"
    {  }
#line 2616 "parser.cpp"
    break;

  case 101:
#line 657 "parser.y"
    {/*de asemenea nu stiu daca este ok ce fac aicea*/  }
#line 2622 "parser.cpp"
    break;

  case 102:
#line 662 "parser.y"
    {  }
#line 2628 "parser.cpp"
    break;

  case 103:
#line 663 "parser.y"
    {  }
#line 2634 "parser.cpp"
    break;

  case 104:
#line 668 "parser.y"
    {  }
#line 2640 "parser.cpp"
    break;

  case 105:
#line 673 "parser.y"
    {  }
#line 2646 "parser.cpp"
    break;

  case 106:
#line 678 "parser.y"
    {  }
#line 2652 "parser.cpp"
    break;

  case 107:
#line 683 "parser.y"
    {  }
#line 2658 "parser.cpp"
    break;

  case 108:
#line 688 "parser.y"
    {  }
#line 2664 "parser.cpp"
    break;

  case 109:
#line 693 "parser.y"
    {  }
#line 2670 "parser.cpp"
    break;

  case 110:
#line 694 "parser.y"
    {  }
#line 2676 "parser.cpp"
    break;

  case 111:
#line 699 "parser.y"
    {  }
#line 2682 "parser.cpp"
    break;

  case 112:
#line 700 "parser.y"
    {  }
#line 2688 "parser.cpp"
    break;

  case 113:
#line 701 "parser.y"
    {  }
#line 2694 "parser.cpp"
    break;

  case 114:
#line 702 "parser.y"
    {  }
#line 2700 "parser.cpp"
    break;

  case 115:
#line 703 "parser.y"
    {  }
#line 2706 "parser.cpp"
    break;

  case 116:
#line 704 "parser.y"
    {  }
#line 2712 "parser.cpp"
    break;

  case 117:
#line 709 "parser.y"
    {  }
#line 2718 "parser.cpp"
    break;

  case 118:
#line 714 "parser.y"
    {  }
#line 2724 "parser.cpp"
    break;

  case 119:
#line 715 "parser.y"
    {
		//de aici in jos facut-am eu 

		(yyval.expr)=new Expression();
		//$2->value=$4->value; //asta daca calculam expr
		(yyvsp[-2].variable_dec)->expr=std::shared_ptr<Expression>((yyvsp[0].expr));
		(yyval.expr)->e_type = VALUE;
		///R:nu cred ca aici trebuie setat VALUE, asa orice vine de sus o sa devina VALUE si nu ai calculat-o daca era altceva
	}
#line 2738 "parser.cpp"
    break;

  case 120:
#line 727 "parser.y"
    { 		
		(yyval.variable_dec) = search_variable((yyvsp[0].string_val)->value).get();
	}
#line 2746 "parser.cpp"
    break;

  case 121:
#line 730 "parser.y"
    {
		(yyval.variable_dec)=search_variable((yyvsp[-3].string_val)->value).get();
		//validare gasire
		(yyval.variable_dec)->position_in_vector=(yyvsp[-1].int_val)->value;
		//validare marime

		//vezi coment variable declaration
	}
#line 2759 "parser.cpp"
    break;

  case 122:
#line 738 "parser.y"
    { /*cum asta nu mai e posibila la noi nu o mai facem, nici celelalte de mai jos*/ }
#line 2765 "parser.cpp"
    break;

  case 123:
#line 739 "parser.y"
    {  }
#line 2771 "parser.cpp"
    break;

  case 124:
#line 740 "parser.y"
    {  }
#line 2777 "parser.cpp"
    break;

  case 125:
#line 741 "parser.y"
    {  }
#line 2783 "parser.cpp"
    break;

  case 126:
#line 744 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)=(yyvsp[-1].expr);
		(yyval.expr)->e_type = VALUE;
		///R:nici aici
		//delete $2;
	}
#line 2795 "parser.cpp"
    break;

  case 127:
#line 751 "parser.y"
    { 
		(yyval.expr)=new Expression();
		//if ($1->type!=$3->type) yyerror();
		(yyval.expr)->type=(yyvsp[-2].expr)->type;
		(yyval.expr)->e_type = VALUE;
		///R:aici da pentru ca o calculezi manual

		switch((yyval.expr)->type){
			case TYPE_INT:
				(yyval.expr)->value.int_val->value=(yyvsp[-2].expr)->value.int_val->value+(yyvsp[0].expr)->value.int_val->value;
				break;
			case TYPE_FLOAT:
				(yyval.expr)->value.float_val->value=(yyvsp[-2].expr)->value.float_val->value+(yyvsp[0].expr)->value.float_val->value;
				break;
			case TYPE_CHAR:
				(yyval.expr)->value.char_val->value=(yyvsp[-2].expr)->value.char_val->value+(yyvsp[0].expr)->value.char_val->value;
				break;
			case TYPE_STRING:
				(yyval.expr)->value.string_val->value=(yyvsp[-2].expr)->value.string_val->value+(yyvsp[0].expr)->value.string_val->value;
				break;

			case TYPE_BOOL:
				(yyval.expr)->value.bool_val->value=(yyvsp[-2].expr)->value.bool_val->value+(yyvsp[0].expr)->value.bool_val->value;
				break;
			default: 
				//pt none si type_object(nu avem overloaded operators)
				//yyerror();
				break;
		}
		
	}
#line 2831 "parser.cpp"
    break;

  case 128:
#line 782 "parser.y"
    { 
		(yyval.expr)=new Expression();
		//if ($1->type!=$3->type) yyerror();
		(yyval.expr)->type=(yyvsp[-2].expr)->type;
		(yyval.expr)->e_type = VALUE;

		switch((yyval.expr)->type){
			case TYPE_INT:
				(yyval.expr)->value.int_val->value=(yyvsp[-2].expr)->value.int_val->value-(yyvsp[0].expr)->value.int_val->value;
				break;
			case TYPE_FLOAT:
				(yyval.expr)->value.float_val->value=(yyvsp[-2].expr)->value.float_val->value-(yyvsp[0].expr)->value.float_val->value;
				break;
			case TYPE_CHAR:
				(yyval.expr)->value.char_val->value=(yyvsp[-2].expr)->value.char_val->value-(yyvsp[0].expr)->value.char_val->value;
				break;


			case TYPE_BOOL:
				(yyval.expr)->value.bool_val->value=(yyvsp[-2].expr)->value.bool_val->value-(yyvsp[0].expr)->value.bool_val->value;
				break;
			default: 
				//pt none si type_object(nu avem overloaded operators)
				//pt string nu are sens sa faci "-". Daca vrei putem pune.
				//yyerror();
				break;
		}
	}
#line 2864 "parser.cpp"
    break;

  case 129:
#line 810 "parser.y"
    { 
		(yyval.expr)=new Expression();
		//if ($1->type!=$3->type) yyerror();
		(yyval.expr)->type=(yyvsp[-2].expr)->type;
		(yyval.expr)->e_type = VALUE;

		switch((yyval.expr)->type){
			case TYPE_INT:
				(yyval.expr)->value.int_val->value=(yyvsp[-2].expr)->value.int_val->value*(yyvsp[0].expr)->value.int_val->value;
				break;
			case TYPE_FLOAT:
				(yyval.expr)->value.float_val->value=(yyvsp[-2].expr)->value.float_val->value*(yyvsp[0].expr)->value.float_val->value;
				break;
			case TYPE_CHAR:
				(yyval.expr)->value.char_val->value=(yyvsp[-2].expr)->value.char_val->value*(yyvsp[0].expr)->value.char_val->value;
				break;


			case TYPE_BOOL:
				(yyval.expr)->value.bool_val->value=(yyvsp[-2].expr)->value.bool_val->value*(yyvsp[0].expr)->value.bool_val->value;
				break;
			default: 
				//pt none si type_object(nu avem overloaded operators)
				//pt string nu are sens sa faci "*". Daca vrei putem pune.
				//yyerror();
				break;
		}
	}
#line 2897 "parser.cpp"
    break;

  case 130:
#line 838 "parser.y"
    { 
		(yyval.expr)=new Expression();
		//if ($1->type!=$3->type) yyerror();
		(yyval.expr)->type=(yyvsp[-2].expr)->type;
		(yyval.expr)->e_type = VALUE;


		switch((yyval.expr)->type){
			case TYPE_INT:
				(yyval.expr)->value.int_val->value=(yyvsp[-2].expr)->value.int_val->value/(yyvsp[0].expr)->value.int_val->value;
				break;
			case TYPE_FLOAT:
				(yyval.expr)->value.float_val->value=(yyvsp[-2].expr)->value.float_val->value/(yyvsp[0].expr)->value.float_val->value;
				break;
			case TYPE_CHAR:
				(yyval.expr)->value.char_val->value=(yyvsp[-2].expr)->value.char_val->value/(yyvsp[0].expr)->value.char_val->value;
				break;
			default: 
				//pt none si type_object(nu avem overloaded operators)
				//nici string nici bool nu ii facut
				//yyerror();
				break;
		}
	}
#line 2926 "parser.cpp"
    break;

  case 131:
#line 862 "parser.y"
    { 
		(yyval.expr)=new Expression();
		//if ($1->type!=$3->type) yyerror();
		(yyval.expr)->type=(yyvsp[-2].expr)->type;
		(yyval.expr)->e_type = VALUE;
		
		switch((yyval.expr)->type){
			case TYPE_INT:
				(yyval.expr)->value.int_val->value=(yyvsp[-2].expr)->value.int_val->value%(yyvsp[0].expr)->value.int_val->value;
				break;
			case TYPE_CHAR:
				(yyval.expr)->value.char_val->value=(yyvsp[-2].expr)->value.char_val->value%(yyvsp[0].expr)->value.char_val->value;
				break;
			default: 
				//pt none si type_object(nu avem overloaded operators)
				//nici string nici bool nu ii facut
				//yyerror();
				break;
		}
	}
#line 2951 "parser.cpp"
    break;

  case 132:
#line 882 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type=(yyvsp[0].expr)->type;
		(yyval.expr)->e_type = VALUE;

		switch((yyval.expr)->type){
			case TYPE_INT:
				(yyval.expr)->value.int_val->value=-(yyvsp[0].expr)->value.int_val->value;
				break;
			case TYPE_FLOAT:
				(yyval.expr)->value.float_val->value=-(yyvsp[0].expr)->value.float_val->value;
				break;
			case TYPE_CHAR:
				(yyval.expr)->value.char_val->value=-(yyvsp[0].expr)->value.char_val->value;
				break;
			default: 
				//yyerror();
				break;
		}
	}
#line 2976 "parser.cpp"
    break;

  case 133:
#line 902 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type=(yyvsp[0].variable_dec)->type;
		(yyval.expr)->value=(yyvsp[0].variable_dec)->value;
		(yyval.expr)->e_type = VALUE;
		///R: pai aici variabila daca nu e calculata deja ar trebui calculata / sau daca nu se poate trebuie lasat tipul diferit de valoare

		//delete $1;
	}
#line 2990 "parser.cpp"
    break;

  case 134:
#line 911 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->call=std::shared_ptr<FunctionCall>((yyvsp[-1].func_call));
		(yyval.expr)->call->name = (yyvsp[-3].string_val)->value;
		(yyval.expr)->e_type = CALL;
		(yyval.expr)->type=(yyval.expr)->call->return_type;
		(yyval.expr)->value=(yyval.expr)->call->return_value;
	}
#line 3003 "parser.cpp"
    break;

  case 135:
#line 919 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type=TYPE_INT;
		(yyval.expr)->value.int_val->value=(yyvsp[0].int_val)->value;
		(yyval.expr)->e_type = VALUE;
		delete (yyvsp[0].int_val);
	}
#line 3015 "parser.cpp"
    break;

  case 136:
#line 926 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type=TYPE_FLOAT;
		(yyval.expr)->value.float_val->value=(yyvsp[0].float_val)->value;
		(yyval.expr)->e_type = VALUE;
		delete (yyvsp[0].float_val);
	}
#line 3027 "parser.cpp"
    break;

  case 137:
#line 933 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type=TYPE_CHAR;
		(yyval.expr)->value.char_val->value=(yyvsp[0].char_val)->value;
		delete (yyvsp[0].char_val);
	}
#line 3038 "parser.cpp"
    break;

  case 138:
#line 939 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type=TYPE_STRING;
		(yyval.expr)->value.string_val->value=(yyvsp[0].string_val)->value;
		(yyval.expr)->e_type = VALUE;
		delete (yyvsp[0].string_val);
	}
#line 3050 "parser.cpp"
    break;

  case 139:
#line 946 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type=TYPE_BOOL;
		(yyval.expr)->value.bool_val->value=true;//asa?
		(yyval.expr)->e_type = VALUE;
		delete (yyvsp[0].bool_val);
	}
#line 3062 "parser.cpp"
    break;

  case 140:
#line 953 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type=TYPE_BOOL;
		(yyval.expr)->value.bool_val->value=false;//asa?
		(yyval.expr)->e_type = VALUE;
		delete (yyvsp[0].bool_val);
	}
#line 3074 "parser.cpp"
    break;

  case 141:
#line 962 "parser.y"
    { 
		(yyval.func_decl)=new FunctionDeclaration();
		Statement statement;
		statement.var_dec=std::shared_ptr<VariableDeclaration>((yyvsp[-1].dec_holder)->var_dec);
		(yyval.func_decl)->function_body.statements.push_back(statement);
		//de creat contextul
		for (auto& holder : (yyvsp[0].func_decl)->function_body.statements){
				(yyval.func_decl)->function_body.statements.push_back(holder);
		}
		/*
		nu trebuie pus tipul statementului aici?

		EDIT: vad acum ca nu am facut un enum cu tipul statementului - intr-adevar nu ne trebuie momentan, dar ar putea fi facut
		*/
	}
#line 3094 "parser.cpp"
    break;

  case 142:
#line 977 "parser.y"
    { /*aici nu cred ca trebuie scris nimic in afara de*/ 
		(yyval.func_decl)=new FunctionDeclaration();
		for (auto& holder : (yyvsp[0].func_decl)->function_body.statements){
				(yyval.func_decl)->function_body.statements.push_back(holder);
		}
		///R:Cred ca trebuie pus statementul respectiv in vector (function_instruction e defapt nenecesara ca e practic statement fara return)
	}
#line 3106 "parser.cpp"
    break;

  case 143:
#line 984 "parser.y"
    { 
		(yyval.func_decl)=new FunctionDeclaration();
		Statement statement;
		statement.var_dec=std::shared_ptr<VariableDeclaration>((yyvsp[0].dec_holder)->var_dec);
		(yyval.func_decl)->function_body.statements.push_back(statement);
		//de creat contextul
	}
#line 3118 "parser.cpp"
    break;

  case 144:
#line 991 "parser.y"
    {  }
#line 3124 "parser.cpp"
    break;

  case 145:
#line 996 "parser.y"
    { 
		(yyval.func_decl)=new FunctionDeclaration();
		//de facut legatura cu $1->func_dec;
		
		///R:Aici trebuie defapt dat pointerul mai departe, regula e inutila $$ = $1;
	}
#line 3135 "parser.cpp"
    break;

  case 146:
#line 1006 "parser.y"
    { 
		(yyval.stmt)=new Statement();
		(yyval.stmt)->var_dec=std::shared_ptr<VariableDeclaration>((yyvsp[0].variable_dec));
	}
#line 3144 "parser.cpp"
    break;

  case 147:
#line 1010 "parser.y"
    { 
		(yyval.stmt)=new Statement();
		(yyval.stmt)->iter_sel_stmt=std::shared_ptr<IterationSelectionStatement>((yyvsp[0].iter_sel_stmt));
	}
#line 3153 "parser.cpp"
    break;

  case 148:
#line 1014 "parser.y"
    { 
		(yyval.stmt)=new Statement();
		(yyval.stmt)->iter_sel_stmt=std::shared_ptr<IterationSelectionStatement>((yyvsp[0].iter_sel_stmt));
	}
#line 3162 "parser.cpp"
    break;

  case 149:
#line 1018 "parser.y"
    { 
		(yyval.stmt)=new Statement();
		(yyval.stmt)->iter_sel_stmt=std::shared_ptr<IterationSelectionStatement>((yyvsp[0].iter_sel_stmt));
	}
#line 3171 "parser.cpp"
    break;

  case 150:
#line 1022 "parser.y"
    { 
		(yyval.stmt)=new Statement();
		Assignment* assignment=new Assignment();
		assignment->name=(yyvsp[-3].string_val)->value;
		assignment->expr=*(yyvsp[-1].expr);
		VariableDeclaration* variable;
		variable=search_variable((yyvsp[-3].string_val)->value).get();
		variable->type=assignment->expr.type;
		variable->value=assignment->expr.value;
		///R:aici doar daca expresia e calculata deja (are tip value)
		//oare se modifica varibila? cred ca da, pt ca returneaza pointer spre ea;
		(yyval.stmt)->asgmt_stmt=std::shared_ptr<Assignment>(assignment);
	}
#line 3189 "parser.cpp"
    break;

  case 151:
#line 1035 "parser.y"
    { 
		(yyval.stmt)=new Statement();
		Assignment* assignment=new Assignment();
		assignment->name=(yyvsp[-6].string_val)->value;
		assignment->is_vector=true;
		assignment->position=(yyvsp[-4].int_val)->value;
		assignment->expr=*(yyvsp[-1].expr);
		VariableDeclaration* variable;
		variable=search_variable((yyvsp[-6].string_val)->value).get();
		variable->type=assignment->expr.type;
		variable->value=assignment->expr.value;
		
		(yyval.stmt)->asgmt_stmt=std::shared_ptr<Assignment>(assignment);
	}
#line 3208 "parser.cpp"
    break;

  case 152:
#line 1049 "parser.y"
    { 
		//asta nu mai exista la noi.
	}
#line 3216 "parser.cpp"
    break;

  case 153:
#line 1052 "parser.y"
    { 
		(yyval.stmt)=new Statement();
		//FunctionCall* function_call=search_function($2->value, call_parameters);
		//trebuie implementata functia de cautat signatura unei functii sa vezi daca exista

		//$$->func_call=std::shared_ptr<FunctionCall>(function_call);

		///R:S-ar putea aici sa trebuiasca facuta o distinctie intre function call si valoarea de return a unei function call
	}
#line 3230 "parser.cpp"
    break;

  case 154:
#line 1061 "parser.y"
    { 
		(yyval.stmt)=new Statement();
		printf("statement vid\n");
	}
#line 3239 "parser.cpp"
    break;

  case 155:
#line 1065 "parser.y"
    { 
		(yyval.stmt)=new Statement();
		printf("%d\n", (yyvsp[-2].int_val)->value);
	}
#line 3248 "parser.cpp"
    break;

  case 156:
#line 1069 "parser.y"
    { 
		(yyval.stmt)=new Statement();
		//validare ca ID este int
		printf("Variable found: %s. Value: %d\n", (yyvsp[-2].string_val)->value, search_variable((yyvsp[-2].string_val)->value)->value.int_val->value);
		///R:Daca ID are o valoare si nu altceva (o expresie -> function call etc), printam
	}
#line 3259 "parser.cpp"
    break;

  case 157:
#line 1075 "parser.y"
    { 
		(yyval.stmt)=new Statement();
		Return* return_val=new Return();
		return_val->ret=std::shared_ptr<Expression>((yyvsp[-1].expr));
		//aici ar trebuie verificat daca dam return la ce type trebuie (dar e destul de greu, ar trebuii sa stim contextul)
		(yyval.stmt)->ret_stmt=std::shared_ptr<Return>(return_val);
	}
#line 3271 "parser.cpp"
    break;

  case 158:
#line 1087 "parser.y"
    { 
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->name=(yyvsp[0].dec_holder)->var_dec->name;
		(yyval.variable_dec)->is_const=(yyvsp[0].dec_holder)->var_dec->is_const;
		(yyval.variable_dec)->type=(yyvsp[0].dec_holder)->var_dec->type;
		(yyval.variable_dec)->value=(yyvsp[0].dec_holder)->var_dec->value;
		(yyval.variable_dec)->values=(yyvsp[0].dec_holder)->var_dec->values;
		(yyval.variable_dec)->size_of_vector=(yyvsp[0].dec_holder)->var_dec->size_of_vector;
		(yyval.variable_dec)->context=(yyvsp[0].dec_holder)->var_dec->context;
		(yyval.variable_dec)->class_name=(yyvsp[0].dec_holder)->var_dec->class_name;
		(yyval.variable_dec)->expr=(yyvsp[0].dec_holder)->var_dec->expr;
		(yyval.variable_dec)->exprs=(yyvsp[0].dec_holder)->var_dec->exprs;

		///R:aici se copie pointerul efectiv, regula este redundanta
	}
#line 3291 "parser.cpp"
    break;


#line 3295 "parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, parse_state, scanner, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, parse_state, scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, parse_state, scanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, parse_state, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, parse_state, scanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, parse_state, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, parse_state, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1104 "parser.y"

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
(std::string name)
{
	return nullptr;
}

std::shared_ptr<VariableDeclaration> search_variable_in_class
(std::string name, std::string class_object)
{
	return nullptr;
}

void pop_stack_context(ParseState* parse_state) {
	if (! parse_state->Stack.empty())
		parse_state->Stack.pop();
}
