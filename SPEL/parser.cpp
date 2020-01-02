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
std::shared_ptr<VariableDeclaration> search_variable(std::string name, ParseState* parse_state);
std::shared_ptr<VariableDeclaration> search_variable_in_class(std::string name, std::string class_object, ParseState* parse_state);

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
#line 104 "parser.y"

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

#line 249 "parser.cpp"

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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   504

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  339

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
       0,   128,   128,   144,   148,   154,   160,   164,   170,   176,
     183,   204,   208,   215,   219,   228,   243,   260,   267,   271,
     275,   279,   283,   299,   304,   315,   323,   341,   350,   356,
     362,   368,   374,   380,   386,   395,   404,   413,   419,   425,
     431,   440,   443,   451,   459,   464,   475,   478,   489,   496,
     500,   511,   526,   542,   562,   567,   577,   588,   604,   607,
     614,   619,   629,   636,   643,   651,   664,   672,   680,   688,
     697,   705,   713,   719,   725,   726,   727,   733,   740,   748,
     751,   758,   761,   764,   771,   776,   781,   782,   783,   784,
     785,   786,   791,   792,   793,   794,   795,   796,   797,   798,
     803,   808,   809,   814,   819,   824,   829,   834,   839,   840,
     845,   846,   847,   848,   849,   850,   855,   860,   861,   873,
     876,   884,   885,   886,   887,   890,   897,   929,   957,   985,
    1009,  1029,  1049,  1059,  1067,  1074,  1081,  1087,  1094,  1101,
    1111,  1131,  1139,  1146,  1151,  1156,  1160,  1164,  1168,  1181,
    1195,  1198,  1207,  1211,  1215,  1221
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
  "vector_position", "const_class_id", "f_parameters", "class_f",
  "f_declaration_parameters", "declaration_parameters",
  "declaration_parameter", "function_body", "function_instruction",
  "while_instr", "while_condition", "boolean", "check", "while_body",
  "if_instr", "if_condition", "if_body", "elif_body", "for_instr",
  "for_sintax", "for_iterator", "for_1", "for_body", "eval_expr", "var",
  "expr", "no_return_function_body", "statement", YY_NULLPTR
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

#define YYPACT_NINF -152

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-152)))

#define YYTABLE_NINF -111

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -22,   268,     8,  -152,  -152,  -152,  -152,   319,   -18,  -152,
     -34,    45,    50,    16,    52,   232,    -5,    29,  -152,  -152,
     268,  -152,   110,   268,  -152,  -152,  -152,   268,  -152,    82,
     105,     7,  -152,  -152,  -152,  -152,  -152,  -152,   367,   367,
      98,  -152,   199,   141,   171,   116,   135,   171,   129,   -11,
     157,   140,     1,   145,  -152,   143,  -152,  -152,   148,   152,
     158,    92,  -152,   240,  -152,   367,   367,   367,   367,   367,
     160,   141,   141,   319,   219,  -152,     3,   137,  -152,    88,
     172,  -152,   146,  -152,   165,   147,   161,   163,   184,   -26,
     169,   186,   319,    92,   296,   209,   367,   296,   178,   215,
     208,  -152,   198,  -152,    97,    97,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,   205,    46,   171,   171,   254,   367,   367,
     367,   367,   367,   367,   201,   366,   306,   221,   222,  -152,
      -8,   223,   332,   241,  -152,   249,   233,   237,  -152,   258,
      -3,   174,   360,   365,   370,   375,   380,   242,   244,  -152,
    -152,   306,   199,   246,    92,   263,    92,   310,    80,  -152,
    -152,   366,   293,   199,   199,   199,   199,   199,   199,   275,
     -40,  -152,  -152,  -152,   270,   273,   332,   269,   303,   305,
     366,  -152,   366,  -152,   334,  -152,  -152,   157,  -152,   316,
     308,  -152,   309,  -152,  -152,   332,   327,  -152,  -152,  -152,
     322,   319,  -152,   346,   352,   354,    92,   332,   340,   337,
    -152,   339,   296,   341,   362,   171,   171,   378,   381,   377,
      92,   366,   348,   359,   382,    67,     2,   386,  -152,  -152,
    -152,   393,   398,   168,   313,  -152,   384,   414,   397,   319,
     296,   267,   399,  -152,  -152,   366,  -152,   400,  -152,   401,
    -152,  -152,  -152,   366,  -152,   296,   402,  -152,  -152,   404,
    -152,   366,   366,   403,   405,   407,   417,   319,    92,   296,
     406,   409,   168,   168,   456,  -152,   435,   412,  -152,   415,
     413,    92,    26,   462,  -152,    92,   450,   416,  -152,  -152,
    -152,   419,   421,  -152,   442,   423,   422,   420,   424,  -152,
    -152,  -152,  -152,   412,   332,  -152,  -152,   385,   425,   445,
    -152,   427,  -152,  -152,  -152,  -152,   319,  -152,   446,   431,
    -152,  -152,   432,   429,   390,   292,  -152,   434,   319,  -152,
     332,  -152,    92,  -152,   436,  -152,   437,  -152,   395
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,    18,    19,    20,    21,     0,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     2,
       7,   144,     0,     8,   146,   145,   147,     9,     1,     0,
       0,   119,   137,   134,   135,   136,   138,   139,     0,     0,
       0,   132,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     0,     5,     6,     0,     0,
       0,     0,   131,     0,   155,     0,     0,     0,     0,     0,
       0,    11,    12,     0,     0,   103,    86,     0,    93,   117,
       0,   106,     0,    85,     0,     0,     0,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
      48,    49,     0,   125,   126,   127,   128,   129,   130,    10,
      13,    14,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   152,
       0,     0,     0,    41,    15,     0,     0,     0,    46,     0,
     119,   137,   134,   135,   136,   138,   139,    54,     0,    47,
      40,     0,   118,     0,     0,     0,     0,   120,    90,    87,
      91,     0,   101,    99,    98,    97,    96,    95,    94,     0,
     108,   111,   112,   113,     0,     0,     0,     0,     0,     0,
      67,   100,    73,    81,     0,    82,    83,     0,    58,     0,
       0,    59,    60,   154,   153,     0,     0,    16,    24,    42,
       0,     0,   148,     0,     0,     0,     0,     0,     0,     0,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    66,    72,
      84,     0,    62,     0,     0,    52,     0,    25,     0,     0,
       0,   121,     0,    55,   151,     0,   123,     0,    51,   122,
      88,    89,   104,     0,   102,     0,     0,   116,   107,   110,
     109,    70,    71,     0,     0,     0,     0,     0,     0,     0,
      64,     0,   142,   143,     0,    61,     0,     0,   150,     0,
       0,     0,   120,     0,    50,     0,     0,     0,   115,    68,
      69,     0,     0,    74,     0,     0,     0,     0,     0,    63,
     140,   141,    57,     0,     0,    26,   149,   133,     0,     0,
      56,     0,   105,   114,    76,    75,     0,    77,     0,     0,
      65,    53,    44,     0,   123,   122,   124,     0,     0,    80,
       0,    43,     0,    79,     0,    45,     0,    78,   124
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,  -152,    -6,  -152,    35,     0,   -12,  -152,  -130,  -152,
     192,   167,   -93,   -86,  -152,   291,   -27,   350,   265,  -152,
     -64,  -151,     5,  -152,   -36,   428,  -152,    61,  -152,  -152,
    -152,   136,  -152,  -152,   281,  -152,    -7,   475,     9,  -102,
    -152
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    19,    20,    70,   180,    22,    90,   147,   200,
     305,   323,   148,   102,   131,   149,    23,   190,   191,   192,
     181,   182,   183,    82,    75,    76,   184,   185,    77,   162,
     254,   186,    46,   174,   175,   258,   150,    41,    42,   274,
      27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    21,   198,    51,   153,   205,    24,   137,    28,    91,
     266,    83,   132,     1,    54,    60,    72,    56,   115,   116,
      21,    57,   220,    21,  -110,    24,    43,    21,    24,    48,
     195,    44,    24,    85,   309,    86,   133,    78,    88,    52,
      78,    92,   267,    71,    72,    72,   223,    62,    63,   118,
     119,   120,   121,    79,   196,    87,    79,   -27,   -27,   206,
     -27,   -27,    25,    93,   268,   235,   112,    78,   211,    61,
     213,    71,    71,    53,   104,   105,   106,   107,   108,   159,
     160,    25,   273,   114,    25,   136,   -35,   -35,    25,   -35,
     -35,   118,   119,   120,   121,   215,   216,   217,   122,   123,
      65,    66,    67,    68,    69,   152,   110,   111,    78,    78,
      45,   263,   103,   264,   189,    47,   228,    49,   229,   247,
     242,   273,   273,    55,    79,    79,    31,   163,   164,   165,
     166,   167,   168,   265,   256,    99,   100,    26,   101,   189,
     122,   123,    65,    66,    67,    68,    69,   280,     3,    59,
       4,     5,     6,    67,    68,    69,    26,   257,    64,    26,
      80,     9,   287,    26,     3,    81,     4,     5,     6,   224,
     300,   301,    13,    84,   322,   231,   297,     9,    15,   250,
     251,   283,   296,    73,    89,    18,    94,    95,    96,   286,
      10,    11,    12,    97,   238,   308,   109,   289,   290,   311,
     322,    18,    98,   117,   124,    15,   126,   178,    78,    78,
      29,   179,   125,   127,    30,    31,    32,    33,    34,    35,
      36,    37,   189,   129,    79,    79,    38,   128,   130,   134,
     135,    73,   279,   272,   -31,   -31,    74,   -31,   -31,     3,
     154,     4,     5,     6,   169,   170,   336,   171,   172,   173,
     151,    50,     9,    65,    66,    67,    68,    69,    29,   155,
     295,   157,    30,    31,    32,    33,    34,    35,    36,    37,
     156,   158,   272,   272,    38,     3,    18,     4,     5,     6,
     161,   193,   194,   197,    39,     7,     8,   199,     9,   201,
      10,    11,    12,   202,    65,    66,    67,    68,    69,    13,
     203,    14,   204,   207,   212,    15,   103,    16,   208,   327,
     210,    17,    18,     3,   218,     4,     5,     6,   214,   219,
       3,   334,     4,     5,     6,   187,     9,   -36,   -36,   281,
     -36,   -36,   187,     9,   225,    29,   221,   222,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   226,   188,   227,
      18,    38,   -37,   -37,   332,   -37,   -37,    18,    29,   230,
     232,    39,    30,    31,    32,    33,    34,    35,    36,    37,
     234,    29,   233,   236,    38,   139,   140,   141,   142,   143,
     144,   145,   146,   176,    39,   237,   239,    38,    10,    11,
      12,   169,   259,   240,   171,   172,   173,    39,   241,   177,
     244,   245,   246,    15,   248,   178,   249,   252,   253,   179,
      30,    31,    32,    33,    34,    35,    36,    37,   255,   261,
     -28,   -28,    38,   -28,   -28,   -29,   -29,   269,   -29,   -29,
     -30,   -30,    39,   -30,   -30,   -32,   -32,   270,   -32,   -32,
     -33,   -33,   262,   -33,   -33,   -34,   -34,   276,   -34,   -34,
     -38,   -38,   277,   -38,   -38,   -39,   -39,   278,   -39,   -39,
     271,   294,   282,   285,   284,   288,   220,   293,   298,   291,
     302,   292,   299,   303,   304,   306,   310,   307,   312,   314,
     313,   315,   316,   317,   319,   318,   328,   320,   324,   325,
     326,   329,   331,   330,   333,   321,   337,   335,   243,   275,
     338,   209,   113,   260,    58
};

static const yytype_uint16 yycheck[] =
{
       7,     1,   132,    15,    97,     8,     1,    93,     0,     8,
       8,    47,    38,    35,    20,     8,    43,    23,    15,    16,
      20,    27,    62,    23,    64,    20,    44,    27,    23,    13,
      38,    65,    27,    44,     8,    46,    62,    44,    50,    44,
      47,    40,    40,    43,    71,    72,   176,    38,    39,     3,
       4,     5,     6,    44,    62,    66,    47,    60,    61,    62,
      63,    64,     1,    62,    62,   195,    73,    74,   154,    62,
     156,    71,    72,    44,    65,    66,    67,    68,    69,   115,
     116,    20,   233,    74,    23,    92,    60,    61,    27,    63,
      64,     3,     4,     5,     6,    15,    16,   161,    52,    53,
      54,    55,    56,    57,    58,    96,    71,    72,   115,   116,
      65,    44,    66,    46,   126,    65,   180,    65,   182,   212,
     206,   272,   273,    13,   115,   116,    44,   118,   119,   120,
     121,   122,   123,    66,   220,    43,    44,     1,    46,   151,
      52,    53,    54,    55,    56,    57,    58,   240,     7,    44,
       9,    10,    11,    56,    57,    58,    20,   221,    60,    23,
      44,    20,   255,    27,     7,    30,     9,    10,    11,   176,
     272,   273,    31,    44,   304,   187,   269,    20,    37,   215,
     216,   245,   268,    12,    44,    44,    41,    44,    40,   253,
      22,    23,    24,    41,   201,   281,    36,   261,   262,   285,
     330,    44,    44,    66,    32,    37,    41,    39,   215,   216,
      39,    43,    66,    66,    43,    44,    45,    46,    47,    48,
      49,    50,   234,    60,   215,   216,    55,    66,    44,    60,
      44,    12,   239,   233,    60,    61,    65,    63,    64,     7,
      62,     9,    10,    11,    43,    44,   332,    46,    47,    48,
      41,    19,    20,    54,    55,    56,    57,    58,    39,    44,
     267,    63,    43,    44,    45,    46,    47,    48,    49,    50,
      62,    66,   272,   273,    55,     7,    44,     9,    10,    11,
      26,    60,    60,    60,    65,    17,    18,    46,    20,    40,
      22,    23,    24,    60,    54,    55,    56,    57,    58,    31,
      63,    33,    44,    61,    41,    37,    66,    39,    64,   316,
      64,    43,    44,     7,    21,     9,    10,    11,     8,    44,
       7,   328,     9,    10,    11,    19,    20,    60,    61,    62,
      63,    64,    19,    20,    65,    39,    66,    64,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    44,    42,    44,
      44,    55,    60,    61,    62,    63,    64,    44,    39,    25,
      44,    65,    43,    44,    45,    46,    47,    48,    49,    50,
      61,    39,    64,    46,    55,    43,    44,    45,    46,    47,
      48,    49,    50,    17,    65,    63,    40,    55,    22,    23,
      24,    43,    44,    41,    46,    47,    48,    65,    44,    33,
      60,    64,    63,    37,    63,    39,    44,    29,    27,    43,
      43,    44,    45,    46,    47,    48,    49,    50,    41,    60,
      60,    61,    55,    63,    64,    60,    61,    41,    63,    64,
      60,    61,    65,    63,    64,    60,    61,    44,    63,    64,
      60,    61,    60,    63,    64,    60,    61,    63,    63,    64,
      60,    61,    38,    63,    64,    60,    61,    60,    63,    64,
      62,    44,    63,    62,    64,    63,    62,    60,    62,    66,
      14,    66,    63,    38,    62,    60,    14,    64,    28,    60,
      64,    60,    40,    60,    64,    63,    40,    63,    63,    44,
      63,    60,    63,    61,    60,   303,    60,   330,   207,   234,
      63,   151,    74,   222,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    35,    68,     7,     9,    10,    11,    17,    18,    20,
      22,    23,    24,    31,    33,    37,    39,    43,    44,    69,
      70,    72,    73,    83,    89,    94,    98,   107,     0,    39,
      43,    44,    45,    46,    47,    48,    49,    50,    55,    65,
     103,   104,   105,    44,    65,    65,    99,    65,    13,    65,
      19,    73,    44,    44,    69,    13,    69,    69,   104,    44,
       8,    62,   105,   105,    60,    54,    55,    56,    57,    58,
      71,    72,    83,    12,    65,    91,    92,    95,   103,   105,
      44,    30,    90,    91,    44,    44,    46,    66,    73,    44,
      74,     8,    40,    62,    41,    44,    40,    41,    44,    43,
      44,    46,    80,    66,   105,   105,   105,   105,   105,    36,
      71,    71,   103,    92,   105,    15,    16,    66,     3,     4,
       5,     6,    52,    53,    32,    66,    41,    66,    66,    60,
      44,    81,    38,    62,    60,    44,   103,    80,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    75,    79,    82,
     103,    41,   105,    79,    62,    44,    62,    63,    66,    91,
      91,    26,    96,   105,   105,   105,   105,   105,   105,    43,
      44,    46,    47,    48,   100,   101,    17,    33,    39,    43,
      72,    87,    88,    89,    93,    94,    98,    19,    42,    73,
      84,    85,    86,    60,    60,    38,    62,    60,    75,    46,
      76,    40,    60,    63,    44,     8,    62,    61,    64,    84,
      64,    80,    41,    80,     8,    15,    16,    87,    21,    44,
      62,    66,    64,    75,   103,    65,    44,    44,    87,    87,
      25,    73,    44,    64,    61,    75,    46,    63,   103,    40,
      41,    44,    80,    82,    60,    64,    63,    79,    63,    44,
      91,    91,    29,    27,    97,    41,    80,    87,   102,    44,
     101,    60,    60,    44,    46,    66,     8,    40,    62,    41,
      44,    62,    72,    88,   106,    85,    63,    38,    60,   103,
      79,    62,    63,    87,    64,    62,    87,    79,    63,    87,
      87,    66,    66,    60,    44,   103,    80,    79,    62,    63,
     106,   106,    14,    38,    62,    77,    60,    64,    80,     8,
      14,    80,    28,    64,    60,    60,    40,    60,    63,    64,
      63,    77,    75,    78,    63,    44,    63,   103,    40,    60,
      61,    63,    62,    60,   103,    78,    80,    60,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    68,    69,    69,    69,    69,    69,    69,
      70,    71,    71,    71,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    74,    74,    74,    74,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    76,    76,    77,    78,    78,    79,    79,    80,    80,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      85,    85,    86,    86,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    88,    88,    88,
      88,    88,    88,    88,    89,    90,    91,    91,    91,    91,
      91,    91,    92,    92,    92,    92,    92,    92,    92,    92,
      93,    94,    94,    95,    96,    97,    98,    99,   100,   100,
     101,   101,   101,   101,   101,   101,   102,   103,   103,   104,
     104,   104,   104,   104,   104,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     106,   106,   106,   106,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     2,     1,     1,     1,
       4,     1,     1,     2,     2,     4,     5,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     6,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     3,     6,     6,     9,
       1,     0,     1,     3,     1,     3,     1,     1,     1,     1,
       5,     4,     3,     6,     1,     3,     8,     8,     1,     1,
       1,     3,     2,     4,     3,     5,     2,     1,     4,     4,
       3,     3,     2,     1,     4,     5,     5,     5,     8,     7,
       6,     1,     1,     1,     6,     1,     1,     3,     5,     5,
       3,     3,     2,     1,     3,     3,     3,     3,     3,     3,
       1,     5,     7,     1,     3,     3,     3,     6,     1,     3,
       1,     1,     1,     1,     5,     4,     1,     1,     4,     1,
       4,     3,     6,     6,     9,     3,     3,     3,     3,     3,
       3,     2,     1,     5,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     5,     8,
       7,     6,     4,     5,     5,     3
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

		//parse_state->rootNode = std::make_shared<Node>();
		//parse_state->rootNode->c_unit = std::shared_ptr<CompileUnit>($2);
	}
#line 1744 "parser.cpp"
    break;

  case 3:
#line 144 "parser.y"
    {  }
#line 1750 "parser.cpp"
    break;

  case 4:
#line 148 "parser.y"
    {
		parse_state->classes.push_back(std::shared_ptr<ClassDefinition>((yyvsp[-1].class_def)));

		//$$ = new CompileUnit();
		//$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
	}
#line 1761 "parser.cpp"
    break;

  case 5:
#line 154 "parser.y"
    {
		parse_state->functions.push_back(std::shared_ptr<FunctionDeclaration>((yyvsp[-1].func_decl)));

		//$$ = new CompileUnit();
		//$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
	}
#line 1772 "parser.cpp"
    break;

  case 6:
#line 160 "parser.y"
    {
		/*$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));*/
	}
#line 1781 "parser.cpp"
    break;

  case 7:
#line 164 "parser.y"
    {
		parse_state->classes.push_back(std::shared_ptr<ClassDefinition>((yyvsp[0].class_def)));

		/*$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));  */
	}
#line 1792 "parser.cpp"
    break;

  case 8:
#line 170 "parser.y"
    {
		parse_state->functions.push_back(std::shared_ptr<FunctionDeclaration>((yyvsp[0].func_decl)));

		/*$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));*/
	}
#line 1803 "parser.cpp"
    break;

  case 9:
#line 176 "parser.y"
    {
		/*$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));*/
	}
#line 1812 "parser.cpp"
    break;

  case 10:
#line 183 "parser.y"
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
#line 1835 "parser.cpp"
    break;

  case 11:
#line 204 "parser.y"
    {
		(yyval.class_def) = new ClassDefinition();
		(yyval.class_def)->decl_holders.push_back(*(yyvsp[0].dec_holder));
	}
#line 1844 "parser.cpp"
    break;

  case 12:
#line 208 "parser.y"
    {
		(yyval.class_def) = new ClassDefinition();

		DeclarationHolder dh;
		dh.func_dec = std::shared_ptr<FunctionDeclaration>((yyvsp[0].func_decl));
		(yyval.class_def)->decl_holders.push_back(dh);
	}
#line 1856 "parser.cpp"
    break;

  case 13:
#line 215 "parser.y"
    {
		(yyval.class_def) = (yyvsp[0].class_def);
		(yyval.class_def)->decl_holders.push_back(*(yyvsp[-1].dec_holder));
  }
#line 1865 "parser.cpp"
    break;

  case 14:
#line 219 "parser.y"
    {
		(yyval.class_def) = (yyvsp[0].class_def);
		DeclarationHolder dh;
		dh.func_dec = std::shared_ptr<FunctionDeclaration>((yyvsp[-1].func_decl));
		(yyval.class_def)->decl_holders.push_back(dh);
	}
#line 1876 "parser.cpp"
    break;

  case 15:
#line 228 "parser.y"
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
#line 1896 "parser.cpp"
    break;

  case 16:
#line 243 "parser.y"
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
#line 1915 "parser.cpp"
    break;

  case 17:
#line 260 "parser.y"
    {
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->type=TYPE_OBJECT;
		(yyval.variable_dec)->class_name = (yyvsp[0].string_val)->value;
		//verificare daca ID este in vectorul de clase
		delete (yyvsp[0].string_val);
	}
#line 1927 "parser.cpp"
    break;

  case 18:
#line 267 "parser.y"
    {
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->type=TYPE_INT;
	}
#line 1936 "parser.cpp"
    break;

  case 19:
#line 271 "parser.y"
    {
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->type=TYPE_FLOAT;
	}
#line 1945 "parser.cpp"
    break;

  case 20:
#line 275 "parser.y"
    {
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->type=TYPE_CHAR;
	}
#line 1954 "parser.cpp"
    break;

  case 21:
#line 279 "parser.y"
    {
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->type=TYPE_STRING;
	}
#line 1963 "parser.cpp"
    break;

  case 22:
#line 283 "parser.y"
    {
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->type=TYPE_BOOL;
	}
#line 1972 "parser.cpp"
    break;

  case 23:
#line 299 "parser.y"
    {
		(yyval.variable_dec) = new VariableDeclaration();
		(yyval.variable_dec)->name = (yyvsp[0].string_val)->value;
		delete (yyvsp[0].string_val);
	}
#line 1982 "parser.cpp"
    break;

  case 24:
#line 304 "parser.y"
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
#line 1998 "parser.cpp"
    break;

  case 25:
#line 315 "parser.y"
    {
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->name= (yyvsp[-3].string_val)->value;
		delete (yyvsp[-3].string_val);

		(yyval.variable_dec)->size_of_vector = (yyvsp[-1].int_val)->value;
		delete (yyvsp[-1].int_val);
	}
#line 2011 "parser.cpp"
    break;

  case 26:
#line 323 "parser.y"
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
#line 2029 "parser.cpp"
    break;

  case 27:
#line 341 "parser.y"
    {
		(yyval.expr) = new Expression();
		(yyval.expr)->name = (yyvsp[0].string_val)->value;
		(yyval.expr)->e_type = VARIABLE_NAME;

		//$$->value = search($$->name)->value;

		delete (yyvsp[0].string_val);
	}
#line 2043 "parser.cpp"
    break;

  case 28:
#line 350 "parser.y"
    {
		(yyval.expr)=new Expression();
		(yyval.expr)->type=TYPE_INT;
		(yyval.expr)->value.int_val = std::shared_ptr<IntVal>((yyvsp[0].int_val));
		(yyval.expr)->e_type = VALUE;
	}
#line 2054 "parser.cpp"
    break;

  case 29:
#line 356 "parser.y"
    {
		(yyval.expr)=new Expression();
		(yyval.expr)->type = TYPE_FLOAT;
		(yyval.expr)->value.float_val = std::shared_ptr<FloatVal>((yyvsp[0].float_val));
		(yyval.expr)->e_type = VALUE;
	}
#line 2065 "parser.cpp"
    break;

  case 30:
#line 362 "parser.y"
    {
		(yyval.expr)=new Expression();
		(yyval.expr)->type = TYPE_CHAR;
		(yyval.expr)->value.char_val = std::shared_ptr<CharVal>((yyvsp[0].char_val));
		(yyval.expr)->e_type = VALUE;
	}
#line 2076 "parser.cpp"
    break;

  case 31:
#line 368 "parser.y"
    {
		(yyval.expr)=new Expression();
		(yyval.expr)->type = TYPE_STRING;
		(yyval.expr)->value.string_val = std::shared_ptr<StringVal>((yyvsp[0].string_val));
		(yyval.expr)->e_type = VALUE;
	}
#line 2087 "parser.cpp"
    break;

  case 32:
#line 374 "parser.y"
    {
		(yyval.expr)=new Expression();
		(yyval.expr)->type = TYPE_BOOL;
		(yyval.expr)->value.bool_val = std::shared_ptr<BoolVal>((yyvsp[0].bool_val));
		(yyval.expr)->e_type = VALUE;
	}
#line 2098 "parser.cpp"
    break;

  case 33:
#line 380 "parser.y"
    {
		(yyval.expr)=new Expression();
		(yyval.expr)->type = TYPE_BOOL;
		(yyval.expr)->value.bool_val = std::shared_ptr<BoolVal>((yyvsp[0].bool_val));
		(yyval.expr)->e_type = VALUE;
	}
#line 2109 "parser.cpp"
    break;

  case 34:
#line 386 "parser.y"
    {
		(yyval.expr) = new Expression();

		(yyval.expr)->call = std::shared_ptr<FunctionCall>((yyvsp[-1].func_call));
		(yyval.expr)->call->name = (yyvsp[-3].string_val)->value;
		(yyval.expr)->e_type = CALL;
		//search for function template - validate name and params

	}
#line 2123 "parser.cpp"
    break;

  case 35:
#line 395 "parser.y"
    {
		(yyval.expr)=new Expression();
		(yyval.expr)->name = (yyvsp[-3].string_val)->value;
		(yyval.expr)->e_type = VECTOR_NAME;
		(yyval.expr)->position = (yyvsp[-1].int_val)->value; //trebuie evaluata aici poz
		delete (yyvsp[-1].int_val);
		//to be implemented - need type deduction
		//by searching for variable
	}
#line 2137 "parser.cpp"
    break;

  case 36:
#line 404 "parser.y"
    { //ignore all OF statements
		(yyval.expr)=new Expression();

		(yyval.expr)->var = search_variable_in_class((yyvsp[-2].string_val)->value, (yyvsp[0].string_val)->value, parse_state); //if null, fail
		(yyval.expr)->e_type = REFERENCE;

		//to be implemented - need type deduction
		//by searching for variable
	}
#line 2151 "parser.cpp"
    break;

  case 37:
#line 413 "parser.y"
    {
		(yyval.expr)=new Expression();

		//to be implemented - need type deduction
		//by searching for variable
	}
#line 2162 "parser.cpp"
    break;

  case 38:
#line 419 "parser.y"
    {
		(yyval.expr)=new Expression();

		//to be implemented - need type deduction
		//by searching for variable
	}
#line 2173 "parser.cpp"
    break;

  case 39:
#line 425 "parser.y"
    {
		(yyval.expr)=new Expression();

		//to be implemented - need type deduction
		//by searching for variable
	}
#line 2184 "parser.cpp"
    break;

  case 40:
#line 431 "parser.y"
    {
		(yyval.expr) = (yyvsp[0].expr);
		//asta nu am facut-o noi?
	}
#line 2193 "parser.cpp"
    break;

  case 41:
#line 440 "parser.y"
    {
	  (yyval.int_val) = new IntVal({ 0 });
	}
#line 2201 "parser.cpp"
    break;

  case 42:
#line 443 "parser.y"
    {
		(yyval.int_val) = new IntVal({(yyvsp[0].int_val)->value});
		delete (yyvsp[0].int_val);
	}
#line 2210 "parser.cpp"
    break;

  case 43:
#line 451 "parser.y"
    {
		(yyval.exprs) = (yyvsp[-1].exprs);
	}
#line 2218 "parser.cpp"
    break;

  case 44:
#line 459 "parser.y"
    {
		(yyval.exprs) = new std::vector< std::shared_ptr<Expression>>();

		(yyval.exprs)->push_back(std::shared_ptr<Expression>((yyvsp[0].expr)));
	}
#line 2228 "parser.cpp"
    break;

  case 45:
#line 464 "parser.y"
    {
		(yyval.exprs) = new std::vector< std::shared_ptr<Expression>>(*(yyvsp[0].exprs));
		delete (yyvsp[0].exprs);

		(yyval.exprs)->push_back(std::shared_ptr<Expression>((yyvsp[-2].expr)));
	}
#line 2239 "parser.cpp"
    break;

  case 46:
#line 475 "parser.y"
    {
		(yyval.func_call) = new FunctionCall();
	}
#line 2247 "parser.cpp"
    break;

  case 47:
#line 478 "parser.y"
    {
		(yyval.func_call) = new FunctionCall();

		(yyval.func_call)->params = *(yyvsp[0].exprs);
		delete (yyvsp[0].exprs);
	}
#line 2258 "parser.cpp"
    break;

  case 48:
#line 489 "parser.y"
    {
		//asta e facut tot de mine, pentru ca am avut nevoie mai jos de unde am inceput

		(yyval.int_val) = new IntVal();
		(yyval.int_val)->value=search_variable((yyvsp[0].string_val)->value, parse_state)->value.int_val->value;
		delete (yyvsp[0].string_val);
	}
#line 2270 "parser.cpp"
    break;

  case 49:
#line 496 "parser.y"
    {
		(yyval.int_val) = new IntVal();
		(yyval.int_val) = (yyvsp[0].int_val);
	}
#line 2279 "parser.cpp"
    break;

  case 50:
#line 500 "parser.y"
    {
		(yyval.int_val)=new IntVal();

		auto auxExpression = new Expression();
		auxExpression->call = std::shared_ptr<FunctionCall>((yyvsp[-1].func_call));
		auxExpression->call->name = (yyvsp[-3].string_val)->value;
		auxExpression->e_type = CALL;

		//verificare daca functia e INT
		//if (auxExpression->call->return_type!=TYPE_INT) yyerror();
	}
#line 2295 "parser.cpp"
    break;

  case 51:
#line 511 "parser.y"
    {
	  (yyval.int_val) = new IntVal();

	  //to be implemented - search in vector
	}
#line 2305 "parser.cpp"
    break;

  case 52:
#line 526 "parser.y"
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
#line 2326 "parser.cpp"
    break;

  case 53:
#line 542 "parser.y"
    {
		(yyval.variable_dec) = new VariableDeclaration();
		(yyval.variable_dec)->name = (yyvsp[-5].string_val)->value;
		delete (yyvsp[-5].string_val);

		(yyval.variable_dec)->size_of_vector = (yyvsp[-3].int_val)->value;
		delete (yyvsp[-3].int_val);

		//should do size validation
		//should do vector_init to ex

		//trebuie adaugat type vector
		(yyval.variable_dec)->exprs = *(yyvsp[0].exprs);
		delete (yyvsp[0].exprs);
	}
#line 2346 "parser.cpp"
    break;

  case 54:
#line 562 "parser.y"
    {
		(yyval.exprs) = new std::vector< std::shared_ptr<Expression>>();

		(yyval.exprs)->push_back(std::shared_ptr<Expression>((yyvsp[0].expr)));
	}
#line 2356 "parser.cpp"
    break;

  case 55:
#line 567 "parser.y"
    {
		(yyval.exprs) = new std::vector< std::shared_ptr<Expression>>(*(yyvsp[0].exprs));
		delete (yyvsp[0].exprs);

		(yyval.exprs)->push_back(std::shared_ptr<Expression>((yyvsp[-2].expr)));
  }
#line 2367 "parser.cpp"
    break;

  case 56:
#line 577 "parser.y"
    {
		(yyval.func_decl) = (yyvsp[-3].func_decl);
		(yyval.func_decl)->name = (yyvsp[-5].string_val)->value;
		delete (yyvsp[-5].string_val);
		(yyval.func_decl)->return_type = (yyvsp[-7].variable_dec)->type;
		delete (yyvsp[-7].variable_dec);
		(yyval.func_decl)->function_body = *(yyvsp[-1].comp_stmt);
		delete (yyvsp[-1].comp_stmt);

		POP_STACK_CONTEXT;
	}
#line 2383 "parser.cpp"
    break;

  case 57:
#line 588 "parser.y"
    {
		(yyval.func_decl) = (yyvsp[-3].func_decl);
		(yyval.func_decl)->name = (yyvsp[-5].string_val)->value;
		delete (yyvsp[-5].string_val);
		(yyval.func_decl)->return_type = NONE;
		(yyval.func_decl)->is_void = true;
		//is_void should be equivalent to NONE
		(yyval.func_decl)->function_body = (yyvsp[-1].func_decl)->function_body;
		delete (yyvsp[-1].func_decl);

		POP_STACK_CONTEXT;
	}
#line 2400 "parser.cpp"
    break;

  case 58:
#line 604 "parser.y"
    {
		(yyval.func_decl) = new FunctionDeclaration();
	}
#line 2408 "parser.cpp"
    break;

  case 59:
#line 607 "parser.y"
    {
		(yyval.func_decl) = (yyvsp[0].func_decl);
	}
#line 2416 "parser.cpp"
    break;

  case 60:
#line 614 "parser.y"
    {
		(yyval.func_decl) = new FunctionDeclaration();
		(yyval.func_decl)->params.push_back(*(yyvsp[0].variable_dec));
		delete (yyvsp[0].variable_dec);
	}
#line 2426 "parser.cpp"
    break;

  case 61:
#line 619 "parser.y"
    {
		(yyval.func_decl) = (yyvsp[0].func_decl);
		(yyval.func_decl)->params.push_back(*(yyvsp[-2].variable_dec));
		delete (yyvsp[-2].variable_dec);
	}
#line 2436 "parser.cpp"
    break;

  case 62:
#line 629 "parser.y"
    {
		(yyval.variable_dec) = new VariableDeclaration();
		(yyval.variable_dec)->type = (yyvsp[-1].variable_dec)->type;
		delete (yyvsp[-1].variable_dec);
		(yyval.variable_dec)->name = (yyvsp[0].string_val)->value;
		delete (yyvsp[0].string_val);
	}
#line 2448 "parser.cpp"
    break;

  case 63:
#line 636 "parser.y"
    {
		(yyval.variable_dec) = new VariableDeclaration();
		(yyval.variable_dec)->type = Type((yyvsp[-3].variable_dec)->type + 6); //din TYPE_INT -> TYPE_INT_VECTOR
		delete (yyvsp[-3].variable_dec);
		(yyval.variable_dec)->name = (yyvsp[-2].string_val)->value;
		delete (yyvsp[-2].string_val);
	}
#line 2460 "parser.cpp"
    break;

  case 64:
#line 643 "parser.y"
    {
		(yyval.variable_dec) = new VariableDeclaration();
		(yyval.variable_dec)->type = (yyvsp[-1].variable_dec)->type;
		delete (yyvsp[-1].variable_dec);
		(yyval.variable_dec)->name = (yyvsp[0].string_val)->value;
		delete (yyvsp[0].string_val);
		(yyval.variable_dec)->is_const = true;
	}
#line 2473 "parser.cpp"
    break;

  case 65:
#line 651 "parser.y"
    {
		(yyval.variable_dec) = new VariableDeclaration();
		(yyval.variable_dec)->type = Type((yyvsp[-3].variable_dec)->type + 6);
		delete (yyvsp[-3].variable_dec);
		(yyval.variable_dec)->name = (yyvsp[-2].string_val)->value;
		delete (yyvsp[-2].string_val);
		(yyval.variable_dec)->is_const = true;
	}
#line 2486 "parser.cpp"
    break;

  case 66:
#line 664 "parser.y"
    {
		(yyval.comp_stmt) = (yyvsp[0].comp_stmt);

		Statement st;
		st.var_dec = (yyvsp[-1].dec_holder)->var_dec;

		(yyval.comp_stmt)->push_back(st);
	}
#line 2499 "parser.cpp"
    break;

  case 67:
#line 672 "parser.y"
    {
		(yyval.comp_stmt) = new ComposedStatement();

		Statement st;
		st.var_dec = (yyvsp[0].dec_holder)->var_dec;

		(yyval.comp_stmt)->push_back(st);
	}
#line 2512 "parser.cpp"
    break;

  case 68:
#line 680 "parser.y"
    {
		(yyval.comp_stmt) = (yyvsp[0].comp_stmt);

		Statement st;
		st.ret_stmt = std::shared_ptr<Expression>((yyvsp[-2].expr));

		(yyval.comp_stmt)->push_back(st);
	}
#line 2525 "parser.cpp"
    break;

  case 69:
#line 688 "parser.y"
    {
		//redundanta eval_expr class_id_initialization
		(yyval.comp_stmt) = (yyvsp[0].comp_stmt);

		Statement st;
		st.ret_stmt = std::shared_ptr<Expression>((yyvsp[-2].expr));

		(yyval.comp_stmt)->push_back(st);
	}
#line 2539 "parser.cpp"
    break;

  case 70:
#line 697 "parser.y"
    {
		(yyval.comp_stmt) = new ComposedStatement();

		Statement st;
		st.ret_stmt = std::shared_ptr<Expression>((yyvsp[-1].expr));

		(yyval.comp_stmt)->push_back(st);
	}
#line 2552 "parser.cpp"
    break;

  case 71:
#line 705 "parser.y"
    {
		(yyval.comp_stmt) = new ComposedStatement();

		Statement st;
		st.ret_stmt = std::shared_ptr<Expression>((yyvsp[-1].expr));

		(yyval.comp_stmt)->push_back(st);
    }
#line 2565 "parser.cpp"
    break;

  case 72:
#line 713 "parser.y"
    {
		(yyval.comp_stmt) = (yyvsp[0].comp_stmt);

		(yyval.comp_stmt)->push_back(*(yyvsp[-1].stmt));
		delete (yyvsp[-1].stmt);
	}
#line 2576 "parser.cpp"
    break;

  case 73:
#line 719 "parser.y"
    {
		(yyval.comp_stmt) = new ComposedStatement();

		(yyval.comp_stmt)->push_back(*(yyvsp[0].stmt));
		delete (yyvsp[0].stmt);
	}
#line 2587 "parser.cpp"
    break;

  case 74:
#line 725 "parser.y"
    {  }
#line 2593 "parser.cpp"
    break;

  case 75:
#line 726 "parser.y"
    {  }
#line 2599 "parser.cpp"
    break;

  case 76:
#line 727 "parser.y"
    {  }
#line 2605 "parser.cpp"
    break;

  case 77:
#line 733 "parser.y"
    {
		(yyval.stmt) = new Statement();

		(yyval.stmt)->asgmt_stmt = std::make_shared<Assignment>(Assignment{ (yyvsp[-3].string_val)->value, false, -1, *(yyvsp[-1].expr) });
		delete (yyvsp[-3].string_val);
		delete (yyvsp[-1].expr);
	}
#line 2617 "parser.cpp"
    break;

  case 78:
#line 740 "parser.y"
    {
		(yyval.stmt) = new Statement();

		(yyval.stmt)->asgmt_stmt = std::make_shared<Assignment>(Assignment{ (yyvsp[-6].string_val)->value, true, (yyvsp[-4].int_val)->value, *(yyvsp[-1].expr) });
		delete (yyvsp[-6].string_val);
		delete (yyvsp[-4].int_val);
		delete (yyvsp[-1].expr);
	}
#line 2630 "parser.cpp"
    break;

  case 79:
#line 748 "parser.y"
    {
	  //no longer supported
	}
#line 2638 "parser.cpp"
    break;

  case 80:
#line 751 "parser.y"
    {
		(yyval.stmt) = new Statement();

		(yyvsp[-2].func_call)->name = (yyvsp[-4].string_val)->value;
		//trebuie cautata functia si intors tipul
		(yyval.stmt)->func_call = std::shared_ptr<FunctionCall>((yyvsp[-2].func_call));
	}
#line 2650 "parser.cpp"
    break;

  case 81:
#line 758 "parser.y"
    {
		(yyval.stmt) = new Statement();
	}
#line 2658 "parser.cpp"
    break;

  case 82:
#line 761 "parser.y"
    {
		(yyval.stmt) = new Statement();
	}
#line 2666 "parser.cpp"
    break;

  case 83:
#line 764 "parser.y"
    {
		(yyval.stmt) = new Statement();
	}
#line 2674 "parser.cpp"
    break;

  case 84:
#line 771 "parser.y"
    {  }
#line 2680 "parser.cpp"
    break;

  case 85:
#line 776 "parser.y"
    {  }
#line 2686 "parser.cpp"
    break;

  case 86:
#line 781 "parser.y"
    {  }
#line 2692 "parser.cpp"
    break;

  case 87:
#line 782 "parser.y"
    {  }
#line 2698 "parser.cpp"
    break;

  case 91:
#line 786 "parser.y"
    {  }
#line 2704 "parser.cpp"
    break;

  case 92:
#line 791 "parser.y"
    {  }
#line 2710 "parser.cpp"
    break;

  case 93:
#line 792 "parser.y"
    {  }
#line 2716 "parser.cpp"
    break;

  case 94:
#line 793 "parser.y"
    {  }
#line 2722 "parser.cpp"
    break;

  case 95:
#line 794 "parser.y"
    {  }
#line 2728 "parser.cpp"
    break;

  case 96:
#line 795 "parser.y"
    {  }
#line 2734 "parser.cpp"
    break;

  case 97:
#line 796 "parser.y"
    {  }
#line 2740 "parser.cpp"
    break;

  case 98:
#line 797 "parser.y"
    {  }
#line 2746 "parser.cpp"
    break;

  case 99:
#line 798 "parser.y"
    {  }
#line 2752 "parser.cpp"
    break;

  case 100:
#line 803 "parser.y"
    {  }
#line 2758 "parser.cpp"
    break;

  case 101:
#line 808 "parser.y"
    {  }
#line 2764 "parser.cpp"
    break;

  case 102:
#line 809 "parser.y"
    {  }
#line 2770 "parser.cpp"
    break;

  case 103:
#line 814 "parser.y"
    {  }
#line 2776 "parser.cpp"
    break;

  case 104:
#line 819 "parser.y"
    {  }
#line 2782 "parser.cpp"
    break;

  case 105:
#line 824 "parser.y"
    {  }
#line 2788 "parser.cpp"
    break;

  case 106:
#line 829 "parser.y"
    {  }
#line 2794 "parser.cpp"
    break;

  case 107:
#line 834 "parser.y"
    {  }
#line 2800 "parser.cpp"
    break;

  case 108:
#line 839 "parser.y"
    {  }
#line 2806 "parser.cpp"
    break;

  case 109:
#line 840 "parser.y"
    {  }
#line 2812 "parser.cpp"
    break;

  case 110:
#line 845 "parser.y"
    {  }
#line 2818 "parser.cpp"
    break;

  case 111:
#line 846 "parser.y"
    {  }
#line 2824 "parser.cpp"
    break;

  case 112:
#line 847 "parser.y"
    {  }
#line 2830 "parser.cpp"
    break;

  case 113:
#line 848 "parser.y"
    {  }
#line 2836 "parser.cpp"
    break;

  case 114:
#line 849 "parser.y"
    {  }
#line 2842 "parser.cpp"
    break;

  case 115:
#line 850 "parser.y"
    {  }
#line 2848 "parser.cpp"
    break;

  case 116:
#line 855 "parser.y"
    {  }
#line 2854 "parser.cpp"
    break;

  case 117:
#line 860 "parser.y"
    {  }
#line 2860 "parser.cpp"
    break;

  case 118:
#line 861 "parser.y"
    {
		//de aici in jos facut-am eu

		(yyval.expr)=new Expression();
		//$2->value=$4->value; //asta daca calculam expr
		(yyvsp[-2].variable_dec)->expr=std::shared_ptr<Expression>((yyvsp[0].expr));
		//$$->e_type = VALUE;
		///R:nu cred ca aici trebuie setat VALUE, asa orice vine de sus o sa devina VALUE si nu ai calculat-o daca era altceva
	}
#line 2874 "parser.cpp"
    break;

  case 119:
#line 873 "parser.y"
    {
		(yyval.variable_dec) = search_variable((yyvsp[0].string_val)->value, parse_state).get();
	}
#line 2882 "parser.cpp"
    break;

  case 120:
#line 876 "parser.y"
    {
		(yyval.variable_dec)=search_variable((yyvsp[-3].string_val)->value, parse_state).get();
		//validare gasire
		(yyval.variable_dec)->position_in_vector=(yyvsp[-1].int_val)->value;
		//validare marime

		//vezi coment variable declaration
	}
#line 2895 "parser.cpp"
    break;

  case 121:
#line 884 "parser.y"
    { /*cum asta nu mai e posibila la noi nu o mai facem, nici celelalte de mai jos*/ }
#line 2901 "parser.cpp"
    break;

  case 122:
#line 885 "parser.y"
    {  }
#line 2907 "parser.cpp"
    break;

  case 123:
#line 886 "parser.y"
    {  }
#line 2913 "parser.cpp"
    break;

  case 124:
#line 887 "parser.y"
    {  }
#line 2919 "parser.cpp"
    break;

  case 125:
#line 890 "parser.y"
    {
		(yyval.expr)=new Expression();
		(yyval.expr)=(yyvsp[-1].expr);
		//$$->e_type = VALUE;
		///R:nici aici
		//delete $2;
	}
#line 2931 "parser.cpp"
    break;

  case 126:
#line 897 "parser.y"
    {
		(yyval.expr)=new Expression();
		//if ($1->type!=$3->type) yyerror();
		// validare if cu VALUE de sus
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
#line 2968 "parser.cpp"
    break;

  case 127:
#line 929 "parser.y"
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
#line 3001 "parser.cpp"
    break;

  case 128:
#line 957 "parser.y"
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
#line 3034 "parser.cpp"
    break;

  case 129:
#line 985 "parser.y"
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
#line 3063 "parser.cpp"
    break;

  case 130:
#line 1009 "parser.y"
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
#line 3088 "parser.cpp"
    break;

  case 131:
#line 1029 "parser.y"
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
#line 3113 "parser.cpp"
    break;

  case 132:
#line 1049 "parser.y"
    {
		(yyval.expr)=new Expression();
		(yyval.expr)->type=(yyvsp[0].variable_dec)->type;
		(yyval.expr)->value=(yyvsp[0].variable_dec)->value;
		//value ar trebui sa fie implicit 0 daca nu o putem calcula
		//$$->e_type = $1->e_type;
		///R: pai aici variabila daca nu e calculata deja ar trebui calculata / sau daca nu se poate trebuie lasat tipul diferit de valoare

		//delete $1;
	}
#line 3128 "parser.cpp"
    break;

  case 133:
#line 1059 "parser.y"
    {
		(yyval.expr)=new Expression();
		(yyval.expr)->call=std::shared_ptr<FunctionCall>((yyvsp[-1].func_call));
		(yyval.expr)->call->name = (yyvsp[-3].string_val)->value;
		(yyval.expr)->e_type = CALL;
		(yyval.expr)->type=(yyval.expr)->call->return_type;
		(yyval.expr)->value=(yyval.expr)->call->return_value;
	}
#line 3141 "parser.cpp"
    break;

  case 134:
#line 1067 "parser.y"
    {
		(yyval.expr)=new Expression();
		(yyval.expr)->type=TYPE_INT;
		(yyval.expr)->value.int_val->value=(yyvsp[0].int_val)->value;
		(yyval.expr)->e_type = VALUE;
		delete (yyvsp[0].int_val);
	}
#line 3153 "parser.cpp"
    break;

  case 135:
#line 1074 "parser.y"
    {
		(yyval.expr)=new Expression();
		(yyval.expr)->type=TYPE_FLOAT;
		(yyval.expr)->value.float_val->value=(yyvsp[0].float_val)->value;
		(yyval.expr)->e_type = VALUE;
		delete (yyvsp[0].float_val);
	}
#line 3165 "parser.cpp"
    break;

  case 136:
#line 1081 "parser.y"
    {
		(yyval.expr)=new Expression();
		(yyval.expr)->type=TYPE_CHAR;
		(yyval.expr)->value.char_val->value=(yyvsp[0].char_val)->value;
		delete (yyvsp[0].char_val);
	}
#line 3176 "parser.cpp"
    break;

  case 137:
#line 1087 "parser.y"
    {
		(yyval.expr)=new Expression();
		(yyval.expr)->type=TYPE_STRING;
		(yyval.expr)->value.string_val->value=(yyvsp[0].string_val)->value;
		(yyval.expr)->e_type = VALUE;
		delete (yyvsp[0].string_val);
	}
#line 3188 "parser.cpp"
    break;

  case 138:
#line 1094 "parser.y"
    {
		(yyval.expr)=new Expression();
		(yyval.expr)->type=TYPE_BOOL;
		(yyval.expr)->value.bool_val->value=true;//asa?
		(yyval.expr)->e_type = VALUE;
		delete (yyvsp[0].bool_val);
	}
#line 3200 "parser.cpp"
    break;

  case 139:
#line 1101 "parser.y"
    {
		(yyval.expr)=new Expression();
		(yyval.expr)->type=TYPE_BOOL;
		(yyval.expr)->value.bool_val->value=false;//asa?
		(yyval.expr)->e_type = VALUE;
		delete (yyvsp[0].bool_val);
	}
#line 3212 "parser.cpp"
    break;

  case 140:
#line 1111 "parser.y"
    {
		(yyval.func_decl)=new FunctionDeclaration();
		//modificat, copiat ptr
		Statement statement;
		statement.var_dec=std::shared_ptr<VariableDeclaration>((yyvsp[-1].dec_holder)->var_dec);
		(yyval.func_decl)->function_body.push_back(statement);
		//de creat contextul
		for (auto& holder : (yyvsp[0].func_decl)->function_body){
				(yyval.func_decl)->function_body.push_back(holder);
		}
		/*
		nu trebuie pus tipul statementului aici?

		EDIT: vad acum ca nu am facut un enum cu tipul statementului - intr-adevar nu ne trebuie momentan, dar ar putea fi facut
		*/

		//nu stergi ce ai alocat nou 
		delete (yyvsp[-1].dec_holder);
		delete (yyvsp[0].func_decl);
	}
#line 3237 "parser.cpp"
    break;

  case 141:
#line 1131 "parser.y"
    { /*aici nu cred ca trebuie scris nimic in afara de*/
		(yyval.func_decl)=new FunctionDeclaration();
		for (auto& holder : (yyvsp[0].func_decl)->function_body){
				(yyval.func_decl)->function_body.push_back(holder);
		}
		//trebuie pus in vector
		///R:Cred ca trebuie pus statementul respectiv in vector (function_instruction e defapt nenecesara ca e practic statement fara return)
	}
#line 3250 "parser.cpp"
    break;

  case 142:
#line 1139 "parser.y"
    {
		(yyval.func_decl)=new FunctionDeclaration();
		Statement statement;
		statement.var_dec=std::shared_ptr<VariableDeclaration>((yyvsp[0].dec_holder)->var_dec);
		(yyval.func_decl)->function_body.push_back(statement);
		delete (yyvsp[0].dec_holder); 
	}
#line 3262 "parser.cpp"
    break;

  case 143:
#line 1146 "parser.y"
    {  }
#line 3268 "parser.cpp"
    break;

  case 144:
#line 1151 "parser.y"
    {
		(yyval.stmt)=new Statement();
		(yyval.stmt)->var_dec=(yyvsp[0].dec_holder)->var_dec;
		delete (yyvsp[0].dec_holder);
	}
#line 3278 "parser.cpp"
    break;

  case 145:
#line 1156 "parser.y"
    {
		(yyval.stmt)=new Statement();
		(yyval.stmt)->iter_sel_stmt=std::shared_ptr<IterationSelectionStatement>((yyvsp[0].iter_sel_stmt));
	}
#line 3287 "parser.cpp"
    break;

  case 146:
#line 1160 "parser.y"
    {
		(yyval.stmt)=new Statement();
		(yyval.stmt)->iter_sel_stmt=std::shared_ptr<IterationSelectionStatement>((yyvsp[0].iter_sel_stmt));
	}
#line 3296 "parser.cpp"
    break;

  case 147:
#line 1164 "parser.y"
    {
		(yyval.stmt)=new Statement();
		(yyval.stmt)->iter_sel_stmt=std::shared_ptr<IterationSelectionStatement>((yyvsp[0].iter_sel_stmt));
	}
#line 3305 "parser.cpp"
    break;

  case 148:
#line 1168 "parser.y"
    {
		(yyval.stmt)=new Statement();
		Assignment* assignment=new Assignment();
		assignment->name=(yyvsp[-3].string_val)->value;
		assignment->expr=*(yyvsp[-1].expr);
		VariableDeclaration* variable;
		variable=search_variable((yyvsp[-3].string_val)->value, parse_state).get();
		variable->type=assignment->expr.type;
		variable->value=assignment->expr.value;
		///R:aici doar daca expresia e calculata deja (are tip value)
		//oare se modifica varibila? cred ca da, pt ca returneaza pointer spre ea;
		(yyval.stmt)->asgmt_stmt=std::shared_ptr<Assignment>(assignment);
	}
#line 3323 "parser.cpp"
    break;

  case 149:
#line 1181 "parser.y"
    {
		(yyval.stmt)=new Statement();
		Assignment* assignment=new Assignment();
		assignment->name=(yyvsp[-6].string_val)->value;
		assignment->is_vector=true;
		assignment->position=(yyvsp[-4].int_val)->value;
		assignment->expr=*(yyvsp[-1].expr);
		VariableDeclaration* variable;
		variable=search_variable((yyvsp[-6].string_val)->value, parse_state).get();
		variable->type=assignment->expr.type;
		variable->value=assignment->expr.value;

		(yyval.stmt)->asgmt_stmt=std::shared_ptr<Assignment>(assignment);
	}
#line 3342 "parser.cpp"
    break;

  case 150:
#line 1195 "parser.y"
    {
		//asta nu mai exista la noi.
	}
#line 3350 "parser.cpp"
    break;

  case 151:
#line 1198 "parser.y"
    {
		(yyval.stmt)=new Statement();
		//FunctionCall* function_call=search_function($2->value, call_parameters);
		//trebuie implementata functia de cautat signatura unei functii sa vezi daca exista

		//$$->func_call=std::shared_ptr<FunctionCall>(function_call);

		///R:S-ar putea aici sa trebuiasca facuta o distinctie intre function call si valoarea de return a unei function call
	}
#line 3364 "parser.cpp"
    break;

  case 152:
#line 1207 "parser.y"
    {
		(yyval.stmt)=new Statement();
		printf("statement vid\n");
	}
#line 3373 "parser.cpp"
    break;

  case 153:
#line 1211 "parser.y"
    {
		(yyval.stmt)=new Statement();
		printf("%d\n", (yyvsp[-2].int_val)->value);
	}
#line 3382 "parser.cpp"
    break;

  case 154:
#line 1215 "parser.y"
    {
		(yyval.stmt)=new Statement();
		//validare ca ID este int
		printf("Variable found: %s. Value: %d\n", (yyvsp[-2].string_val)->value, search_variable((yyvsp[-2].string_val)->value, parse_state)->value.int_val->value);
		///R:Daca ID are o valoare si nu altceva (o expresie -> function call etc), printam
	}
#line 3393 "parser.cpp"
    break;

  case 155:
#line 1221 "parser.y"
    {
		(yyval.stmt)=new Statement();
		//aici ar trebuie verificat daca dam return la ce type trebuie (dar e destul de greu, ar trebuii sa stim contextul)
		(yyval.stmt)->ret_stmt=std::shared_ptr<Expression>((yyvsp[-1].expr));
	}
#line 3403 "parser.cpp"
    break;


#line 3407 "parser.cpp"

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
#line 1228 "parser.y"

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
