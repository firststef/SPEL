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

#line 80 "parser.cpp"

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
#line 11 "parser.y"


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

#line 159 "parser.cpp"

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
#line 96 "parser.y"

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
	Expression* expr;
	IterationSelectionStatement* iter_sel_stmt;
	Assignment* asgmt;
	FunctionDeclaration* func_decl;
	FunctionCall* func_call;
	Return* ret;

	std::vector< std::shared_ptr<Expression>>* exprs;

#line 244 "parser.cpp"

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
#define YYLAST   504

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  343

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
       0,   120,   120,   132,   136,   142,   148,   152,   158,   164,
     171,   190,   194,   198,   204,   213,   228,   244,   251,   255,
     259,   263,   267,   283,   288,   299,   307,   325,   334,   340,
     346,   352,   358,   364,   370,   379,   388,   397,   403,   409,
     415,   425,   428,   435,   440,   441,   446,   447,   452,   453,
     454,   455,   466,   467,   472,   477,   478,   483,   488,   489,
     494,   495,   500,   501,   506,   507,   508,   509,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   529,
     530,   531,   532,   533,   534,   535,   540,   545,   550,   551,
     552,   553,   554,   555,   560,   561,   562,   563,   564,   565,
     566,   567,   572,   577,   578,   583,   588,   593,   598,   603,
     608,   609,   614,   615,   616,   617,   618,   619,   624,   629,
     630,   633,   634,   635,   636,   637,   638,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   652,   653,
     654,   655,   658,   659,   660,   661,   666,   671,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   681,   682,   687
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
  "vector_position", "const_class_id", "const_vector_size", "f_parameters",
  "f_parameter", "class_f", "f_declaration_parameters",
  "declaration_parameters", "declaration_parameter", "function_body",
  "function_instruction", "while_instr", "while_condition", "boolean",
  "check", "while_body", "if_instr", "if_condition", "if_body",
  "elif_body", "for_instr", "for_sintax", "for_iterator", "for_1",
  "for_body", "eval_expr", "var", "expr", "no_return_function_body",
  "function_def", "statement", "declaration", YY_NULLPTR
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

#define YYPACT_NINF -224

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-224)))

#define YYTABLE_NINF -113

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -18,   130,    27,  -224,  -224,  -224,  -224,   328,   -13,  -224,
     -30,   -20,   -16,    39,   -10,   301,    26,    65,  -224,  -224,
     130,  -224,   101,  -224,  -224,  -224,  -224,   130,   130,  -224,
    -224,    92,    94,     2,  -224,  -224,  -224,  -224,  -224,  -224,
     376,   376,    59,  -224,   201,   223,   226,   100,   112,   226,
     102,    54,   322,   105,     0,   104,  -224,   115,  -224,  -224,
     120,   121,   124,   -28,  -224,   159,  -224,   376,   376,   376,
     376,   376,   128,   223,   223,   328,   249,  -224,     9,    99,
    -224,   195,   138,  -224,   109,  -224,   135,   116,   126,   111,
     137,   -19,   127,   149,   328,   -28,   304,   153,   376,   304,
     134,   158,   165,  -224,   168,  -224,    49,    49,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,   155,   152,   226,   226,   209,
     376,   376,   376,   376,   376,   376,   142,   375,   296,   179,
     180,  -224,   -15,   181,   341,   198,  -224,   205,   186,   199,
    -224,   219,    28,   374,   379,   384,   389,   394,   399,  -224,
     202,  -224,   207,  -224,   296,   201,   215,   -28,   239,   -28,
     279,    57,  -224,  -224,   375,   268,   201,   201,   201,   201,
     201,   201,   246,   -42,  -224,  -224,  -224,   234,   237,   341,
     244,   258,   273,   375,  -224,   375,  -224,   293,  -224,  -224,
     322,  -224,   275,   259,  -224,   261,  -224,  -224,   341,   284,
    -224,  -224,  -224,   271,   328,  -224,   295,   298,   297,   -28,
     300,   341,   280,  -224,   292,   304,   294,   312,   226,   226,
     329,   335,   323,   -28,   375,   176,   303,   305,    55,     4,
     327,  -224,  -224,  -224,   326,   319,   393,   317,  -224,  -224,
     316,   344,   334,   328,   304,   222,   332,  -224,  -224,   375,
    -224,   343,  -224,   347,  -224,  -224,  -224,   375,  -224,   304,
     342,  -224,  -224,   348,  -224,   375,   375,   345,   361,   353,
     385,   328,   -28,   304,   366,   370,   393,   393,   432,  -224,
     413,   417,  -224,   396,   397,   -28,    -3,   452,  -224,   -28,
     443,   412,  -224,  -224,  -224,   420,   421,  -224,   442,   423,
     422,   424,   426,  -224,  -224,  -224,  -224,   417,   341,  -224,
    -224,   404,   427,   440,  -224,   428,  -224,  -224,  -224,  -224,
     328,  -224,   446,   433,  -224,  -224,   431,   434,   409,   340,
    -224,   435,   328,  -224,   341,  -224,   -28,  -224,   436,  -224,
     437,  -224,   414
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,    18,    19,    20,    21,     0,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     2,
       7,   159,     0,   146,   149,   148,   150,     8,     9,   147,
       1,     0,     0,   121,   139,   136,   137,   138,   140,   141,
       0,     0,     0,   134,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,     5,     6,
       0,     0,     0,     0,   133,     0,   158,     0,     0,     0,
       0,     0,     0,    11,    12,     0,     0,   105,    88,     0,
      95,   119,     0,   108,     0,    87,     0,     0,     0,     0,
       0,    23,     0,     0,     0,     0,     0,     0,     0,     0,
     123,     0,    48,    49,     0,   127,   128,   129,   130,   131,
     132,    10,    13,    14,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   155,     0,     0,     0,    41,    15,     0,     0,     0,
      46,     0,   121,   139,   136,   137,   138,   140,   141,    57,
       0,    47,    55,    40,     0,   120,     0,     0,     0,     0,
     122,    92,    89,    93,     0,   103,   101,   100,    99,    98,
      97,    96,     0,   110,   113,   114,   115,     0,     0,     0,
       0,     0,     0,    72,   102,    75,    83,     0,    84,    85,
       0,    60,     0,     0,    61,    62,   157,   156,     0,     0,
      16,    24,    42,     0,     0,   151,     0,     0,     0,     0,
       0,     0,     0,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    68,    71,    86,     0,    64,     0,     0,    52,    54,
       0,    25,     0,     0,     0,   123,     0,   154,    56,     0,
     125,     0,    51,   124,    90,    91,   106,     0,   104,     0,
       0,   118,   109,   112,   111,    73,    74,     0,     0,     0,
       0,     0,     0,     0,    66,     0,   144,   145,     0,    63,
       0,     0,   153,     0,     0,     0,   122,     0,    50,     0,
       0,     0,   117,    69,    70,     0,     0,    76,     0,     0,
       0,     0,     0,    65,   142,   143,    59,     0,     0,    26,
     152,   135,     0,     0,    58,     0,   107,   116,    78,    77,
       0,    79,     0,     0,    67,    53,    44,     0,   125,   124,
     126,     0,     0,    82,     0,    43,     0,    81,     0,    45,
       0,    80,   126
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -224,  -224,    98,  -224,    11,     1,   -11,  -224,  -131,  -224,
     187,   164,   -93,   -94,  -224,  -224,   276,  -224,   -36,   349,
     262,  -224,  -153,  -223,     6,  -224,   -35,   425,  -224,    75,
    -224,  -224,  -224,    96,  -224,  -224,   277,  -224,    -7,   473,
      10,  -183,  -224,  -224,  -224
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    19,    20,    72,   183,    22,    92,   149,   203,
     309,   327,   150,   104,   133,   240,   151,   152,    23,   193,
     194,   195,   184,   185,   186,    84,    77,    78,   187,   188,
      79,   165,   258,   189,    48,   177,   178,   262,   153,    43,
      44,   278,    27,    28,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,   139,    21,   201,    53,   313,   156,    24,    93,    74,
      62,   220,   270,   277,    85,   101,   102,     1,   103,   134,
     223,    21,  -112,   198,   117,   118,    24,    30,    21,    21,
     231,    45,   232,    24,    24,    46,   208,    74,    74,    80,
      94,    90,    80,   135,   271,    47,    73,   199,   226,    49,
      64,    65,    50,   277,   277,    51,    81,   -35,   -35,    81,
     -35,   -35,    95,   214,    63,   216,   272,   238,   114,    80,
      54,   261,   218,   219,    73,    73,    25,   106,   107,   108,
     109,   110,   162,   163,   112,   113,   116,   138,   -27,   -27,
     209,   -27,   -27,   304,   305,    25,   287,    26,    87,   267,
      88,   268,    25,    25,   290,    69,    70,    71,   155,    55,
      80,    80,   293,   294,    57,   246,    26,   192,    56,    66,
      89,   269,   251,    26,    26,    58,    59,    81,    81,   260,
     166,   167,   168,   169,   170,   171,    33,     3,    61,     4,
       5,     6,    83,   192,    82,    96,    86,     7,     8,    91,
       9,   284,    10,    11,    12,   120,   121,   122,   123,    97,
      98,    13,    99,    14,   111,   119,   291,    15,   100,    16,
     126,   131,   227,    17,    18,   127,   128,   326,   300,   234,
     301,   132,   129,   254,   255,   172,   173,   136,   174,   175,
     176,   312,   130,   137,   154,   315,   157,   242,   120,   121,
     122,   123,   158,   326,   124,   125,    67,    68,    69,    70,
      71,    80,    80,    67,    68,    69,    70,    71,   105,   172,
     263,   161,   174,   175,   176,   105,   192,   159,    81,    81,
       3,   160,     4,     5,     6,   164,   283,   276,    75,   196,
     197,   200,   340,     9,   202,   204,   205,   124,   125,    67,
      68,    69,    70,    71,    13,    67,    68,    69,    70,    71,
      15,    75,   206,   207,   299,    31,   210,    18,   211,    32,
      33,    34,    35,    36,    37,    38,    39,   276,   276,   213,
     215,    40,   -36,   -36,   285,   -36,   -36,   217,    31,   221,
     222,    76,    32,    33,    34,    35,    36,    37,    38,    39,
     224,   225,   229,     3,    40,     4,     5,     6,     3,   228,
       4,     5,     6,   331,    41,   190,     9,   230,   233,   235,
      52,     9,   237,   236,     3,   338,     4,     5,     6,     3,
     239,     4,     5,     6,   241,   243,   190,     9,   191,   244,
      18,   245,     9,    31,   249,    18,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   250,   253,   252,   256,    40,
     247,    18,   257,   265,   259,   266,    18,    31,   273,    41,
     274,    32,    33,    34,    35,    36,    37,    38,    39,   280,
      31,   275,   281,    40,   141,   142,   143,   144,   145,   146,
     147,   148,   179,    41,   282,   286,    40,    10,    11,    12,
     -37,   -37,   336,   -37,   -37,   292,    41,   288,   180,   289,
     223,   295,    15,   297,   181,    10,    11,    12,   182,    32,
      33,    34,    35,    36,    37,    38,    39,   296,   302,   298,
      15,    40,   181,   303,   -31,   -31,   182,   -31,   -31,   -28,
     -28,    41,   -28,   -28,   -29,   -29,   306,   -29,   -29,   -30,
     -30,   307,   -30,   -30,   -32,   -32,   310,   -32,   -32,   -33,
     -33,   311,   -33,   -33,   -34,   -34,   314,   -34,   -34,   -38,
     -38,   316,   -38,   -38,   -39,   -39,   317,   -39,   -39,   308,
     318,   319,   320,   321,   329,   322,   332,   248,   323,   324,
     328,   330,   334,   333,   325,   337,   341,   335,   339,   279,
     342,   115,   264,   212,    60
};

static const yytype_uint16 yycheck[] =
{
       7,    95,     1,   134,    15,     8,    99,     1,     8,    45,
       8,   164,     8,   236,    49,    43,    44,    35,    46,    38,
      62,    20,    64,    38,    15,    16,    20,     0,    27,    28,
     183,    44,   185,    27,    28,    65,     8,    73,    74,    46,
      40,    52,    49,    62,    40,    65,    45,    62,   179,    65,
      40,    41,    13,   276,   277,    65,    46,    60,    61,    49,
      63,    64,    62,   157,    62,   159,    62,   198,    75,    76,
      44,   224,    15,    16,    73,    74,     1,    67,    68,    69,
      70,    71,   117,   118,    73,    74,    76,    94,    60,    61,
      62,    63,    64,   276,   277,    20,   249,     1,    44,    44,
      46,    46,    27,    28,   257,    56,    57,    58,    98,    44,
     117,   118,   265,   266,    13,   209,    20,   128,    20,    60,
      66,    66,   215,    27,    28,    27,    28,   117,   118,   223,
     120,   121,   122,   123,   124,   125,    44,     7,    44,     9,
      10,    11,    30,   154,    44,    41,    44,    17,    18,    44,
      20,   244,    22,    23,    24,     3,     4,     5,     6,    44,
      40,    31,    41,    33,    36,    66,   259,    37,    44,    39,
      32,    60,   179,    43,    44,    66,    41,   308,   272,   190,
     273,    44,    66,   218,   219,    43,    44,    60,    46,    47,
      48,   285,    66,    44,    41,   289,    62,   204,     3,     4,
       5,     6,    44,   334,    52,    53,    54,    55,    56,    57,
      58,   218,   219,    54,    55,    56,    57,    58,    66,    43,
      44,    66,    46,    47,    48,    66,   237,    62,   218,   219,
       7,    63,     9,    10,    11,    26,   243,   236,    12,    60,
      60,    60,   336,    20,    46,    40,    60,    52,    53,    54,
      55,    56,    57,    58,    31,    54,    55,    56,    57,    58,
      37,    12,    63,    44,   271,    39,    64,    44,    61,    43,
      44,    45,    46,    47,    48,    49,    50,   276,   277,    64,
      41,    55,    60,    61,    62,    63,    64,     8,    39,    21,
      44,    65,    43,    44,    45,    46,    47,    48,    49,    50,
      66,    64,    44,     7,    55,     9,    10,    11,     7,    65,
       9,    10,    11,   320,    65,    19,    20,    44,    25,    44,
      19,    20,    61,    64,     7,   332,     9,    10,    11,     7,
      46,     9,    10,    11,    63,    40,    19,    20,    42,    41,
      44,    44,    20,    39,    64,    44,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    63,    44,    63,    29,    55,
      60,    44,    27,    60,    41,    60,    44,    39,    41,    65,
      44,    43,    44,    45,    46,    47,    48,    49,    50,    63,
      39,    62,    38,    55,    43,    44,    45,    46,    47,    48,
      49,    50,    17,    65,    60,    63,    55,    22,    23,    24,
      60,    61,    62,    63,    64,    63,    65,    64,    33,    62,
      62,    66,    37,    60,    39,    22,    23,    24,    43,    43,
      44,    45,    46,    47,    48,    49,    50,    66,    62,    44,
      37,    55,    39,    63,    60,    61,    43,    63,    64,    60,
      61,    65,    63,    64,    60,    61,    14,    63,    64,    60,
      61,    38,    63,    64,    60,    61,    60,    63,    64,    60,
      61,    64,    63,    64,    60,    61,    14,    63,    64,    60,
      61,    28,    63,    64,    60,    61,    64,    63,    64,    62,
      60,    60,    40,    60,    44,    63,    40,   211,    64,    63,
      63,    63,    61,    60,   307,    60,    60,    63,   334,   237,
      63,    76,   225,   154,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    35,    68,     7,     9,    10,    11,    17,    18,    20,
      22,    23,    24,    31,    33,    37,    39,    43,    44,    69,
      70,    72,    73,    85,    91,    96,   100,   109,   110,   111,
       0,    39,    43,    44,    45,    46,    47,    48,    49,    50,
      55,    65,   105,   106,   107,    44,    65,    65,   101,    65,
      13,    65,    19,    73,    44,    44,    69,    13,    69,    69,
     106,    44,     8,    62,   107,   107,    60,    54,    55,    56,
      57,    58,    71,    72,    85,    12,    65,    93,    94,    97,
     105,   107,    44,    30,    92,    93,    44,    44,    46,    66,
      73,    44,    74,     8,    40,    62,    41,    44,    40,    41,
      44,    43,    44,    46,    80,    66,   107,   107,   107,   107,
     107,    36,    71,    71,   105,    94,   107,    15,    16,    66,
       3,     4,     5,     6,    52,    53,    32,    66,    41,    66,
      66,    60,    44,    81,    38,    62,    60,    44,   105,    80,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    75,
      79,    83,    84,   105,    41,   107,    79,    62,    44,    62,
      63,    66,    93,    93,    26,    98,   107,   107,   107,   107,
     107,   107,    43,    44,    46,    47,    48,   102,   103,    17,
      33,    39,    43,    72,    89,    90,    91,    95,    96,   100,
      19,    42,    73,    86,    87,    88,    60,    60,    38,    62,
      60,    75,    46,    76,    40,    60,    63,    44,     8,    62,
      64,    61,    86,    64,    80,    41,    80,     8,    15,    16,
      89,    21,    44,    62,    66,    64,    75,   105,    65,    44,
      44,    89,    89,    25,    73,    44,    64,    61,    75,    46,
      82,    63,   105,    40,    41,    44,    80,    60,    83,    64,
      63,    79,    63,    44,    93,    93,    29,    27,    99,    41,
      80,    89,   104,    44,   103,    60,    60,    44,    46,    66,
       8,    40,    62,    41,    44,    62,    72,    90,   108,    87,
      63,    38,    60,   105,    79,    62,    63,    89,    64,    62,
      89,    79,    63,    89,    89,    66,    66,    60,    44,   105,
      80,    79,    62,    63,   108,   108,    14,    38,    62,    77,
      60,    64,    80,     8,    14,    80,    28,    64,    60,    60,
      40,    60,    63,    64,    63,    77,    75,    78,    63,    44,
      63,   105,    40,    60,    61,    63,    62,    60,   105,    78,
      80,    60,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    68,    69,    69,    69,    69,    69,    69,
      70,    71,    71,    71,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    74,    74,    74,    74,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    76,    76,    77,    78,    78,    79,    79,    80,    80,
      80,    80,    81,    81,    82,    83,    83,    84,    85,    85,
      86,    86,    87,    87,    88,    88,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    90,
      90,    90,    90,    90,    90,    90,    91,    92,    93,    93,
      93,    93,    93,    93,    94,    94,    94,    94,    94,    94,
      94,    94,    95,    96,    96,    97,    98,    99,   100,   101,
     102,   102,   103,   103,   103,   103,   103,   103,   104,   105,
     105,   106,   106,   106,   106,   106,   106,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   108,   108,   108,   108,   109,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   111
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     2,     1,     1,     1,
       4,     1,     1,     2,     2,     4,     5,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     6,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     3,     6,     6,     9,
       1,     0,     1,     3,     1,     3,     1,     1,     1,     1,
       5,     4,     3,     6,     1,     1,     3,     1,     8,     8,
       1,     1,     1,     3,     2,     4,     3,     5,     2,     4,
       4,     2,     1,     3,     3,     1,     4,     5,     5,     5,
       8,     7,     6,     1,     1,     1,     6,     1,     1,     3,
       5,     5,     3,     3,     2,     1,     3,     3,     3,     3,
       3,     3,     1,     5,     7,     1,     3,     3,     3,     6,
       1,     3,     1,     1,     1,     1,     5,     4,     1,     1,
       4,     1,     4,     3,     6,     6,     9,     3,     3,     3,
       3,     3,     3,     2,     1,     5,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     5,     8,     7,     6,     4,     5,     5,     3,     1
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
#line 120 "parser.y"
    { 
		/*for (auto& holder : $2->block_holder) {
			if (holder.type == DECLARATION_TYPE) {
				if (holder->decl_dec->type == VAR_FUNC) {

				}
			}
		}*/

		//parse_state->rootNode = std::make_shared<Node>();
		//parse_state->rootNode->c_unit = std::shared_ptr<CompileUnit>($2);
	}
#line 1739 "parser.cpp"
    break;

  case 3:
#line 132 "parser.y"
    {  }
#line 1745 "parser.cpp"
    break;

  case 4:
#line 136 "parser.y"
    {
		parse_state->classes.push_back(std::shared_ptr<ClassDefinition>((yyvsp[-1].class_def)));

		//$$ = new CompileUnit();
		//$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
	}
#line 1756 "parser.cpp"
    break;

  case 5:
#line 142 "parser.y"
    {
		parse_state->functions.push_back(std::shared_ptr<FunctionDeclaration>((yyvsp[-1].func_decl)));
		
		//$$ = new CompileUnit();
		//$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));
	}
#line 1767 "parser.cpp"
    break;

  case 6:
#line 148 "parser.y"
    {
		/*$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));*/
	}
#line 1776 "parser.cpp"
    break;

  case 7:
#line 152 "parser.y"
    { 
		parse_state->classes.push_back(std::shared_ptr<ClassDefinition>((yyvsp[0].class_def)));

		/*$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));  */
	}
#line 1787 "parser.cpp"
    break;

  case 8:
#line 158 "parser.y"
    { 
		parse_state->functions.push_back(std::shared_ptr<FunctionDeclaration>((yyvsp[0].func_decl)));

		/*$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));*/
	}
#line 1798 "parser.cpp"
    break;

  case 9:
#line 164 "parser.y"
    { 
		/*$$ = new CompileUnit();
		$$->block_holder.push_back(std::shared_ptr<BlockHolder>($1));*/
	}
#line 1807 "parser.cpp"
    break;

  case 10:
#line 171 "parser.y"
    { 
	  	/*$$ = new BlockHolder(); 
		$$->type=CLASS_TYPE;

		$$->class_dec = std::shared_ptr<ClassDefinition>($3);

		$$->class_dec->name = $2->value;
		delete $2;*/
		
		(yyval.class_def) = (yyvsp[-1].class_def);

		(yyvsp[-1].class_def)->name = (yyvsp[-2].string_val)->value; 
		delete (yyvsp[-2].string_val);

		//verificare ca nu mai este o data definita clasa cu acelasi ID
	}
#line 1828 "parser.cpp"
    break;

  case 11:
#line 190 "parser.y"
    { 
		(yyval.class_def) = new ClassDefinition();
		(yyval.class_def)->decl_holders.push_back(*(yyvsp[0].dec_holder));
	}
#line 1837 "parser.cpp"
    break;

  case 12:
#line 194 "parser.y"
    { 
		(yyval.class_def) = new ClassDefinition();
		(yyval.class_def)->decl_holders.push_back(*(yyvsp[0].dec_holder));
	}
#line 1846 "parser.cpp"
    break;

  case 13:
#line 198 "parser.y"
    { 
		(yyval.class_def)=new ClassDefinition();
		(yyval.class_def)->decl_holders.push_back(*(yyvsp[-1].dec_holder));
		for (auto& holder : (yyvsp[0].class_def)->decl_holders)
			(yyval.class_def)->decl_holders.push_back(holder);
  }
#line 1857 "parser.cpp"
    break;

  case 14:
#line 204 "parser.y"
    { 
		(yyval.class_def) = new ClassDefinition();
		(yyval.class_def)->decl_holders.push_back(*(yyvsp[-1].dec_holder));
		for (auto& holder : (yyvsp[0].class_def)->decl_holders)
			(yyval.class_def)->decl_holders.push_back(holder);
	}
#line 1868 "parser.cpp"
    break;

  case 15:
#line 213 "parser.y"
    { 
		(yyval.dec_holder)=new DeclarationHolder();
		(yyval.dec_holder)->type=VAR_DEC;

		(yyvsp[-1].variable_dec)->type = (yyvsp[-2].variable_dec)->type;
		//if($3->type!=NONE) if($3->type!=$2->type) yyerror();
		//cateodata tipul $3 nu este setat (cand nu am initializat)
		
		(yyvsp[-1].variable_dec)->class_name = (yyvsp[-2].variable_dec)->class_name;
		(yyval.dec_holder)->var_dec = std::shared_ptr<VariableDeclaration>((yyvsp[-1].variable_dec));
		delete (yyvsp[-2].variable_dec);

		parse_state->variableStack.push_back((yyval.dec_holder)->var_dec);
		
	}
#line 1888 "parser.cpp"
    break;

  case 16:
#line 228 "parser.y"
    {  

		  (yyval.dec_holder) = new DeclarationHolder();
		  (yyval.dec_holder)->type = VAR_DEC;

		  (yyvsp[-1].variable_dec)->type = (yyvsp[-2].variable_dec)->type;
		  (yyvsp[-1].variable_dec)->class_name = (yyvsp[-2].variable_dec)->class_name;
		  (yyvsp[-1].variable_dec)->is_const = true;
		  (yyval.dec_holder)->var_dec = std::shared_ptr<VariableDeclaration>((yyvsp[-1].variable_dec));
		  delete (yyvsp[-2].variable_dec);

		  parse_state->variableStack.push_back((yyval.dec_holder)->var_dec);
	}
#line 1906 "parser.cpp"
    break;

  case 17:
#line 244 "parser.y"
    { 
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->type=TYPE_OBJECT;
		(yyval.variable_dec)->class_name = (yyvsp[0].string_val)->value;
		//verificare daca ID este in vectorul de clase
		delete (yyvsp[0].string_val);
	}
#line 1918 "parser.cpp"
    break;

  case 18:
#line 251 "parser.y"
    { 
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->type=TYPE_INT;
	}
#line 1927 "parser.cpp"
    break;

  case 19:
#line 255 "parser.y"
    { 
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->type=TYPE_FLOAT;	 
	}
#line 1936 "parser.cpp"
    break;

  case 20:
#line 259 "parser.y"
    { 
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->type=TYPE_CHAR;
	}
#line 1945 "parser.cpp"
    break;

  case 21:
#line 263 "parser.y"
    { 
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->type=TYPE_STRING;
	}
#line 1954 "parser.cpp"
    break;

  case 22:
#line 267 "parser.y"
    { 
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->type=TYPE_BOOL; 
	}
#line 1963 "parser.cpp"
    break;

  case 23:
#line 283 "parser.y"
    { 
		(yyval.variable_dec) = new VariableDeclaration();
		(yyval.variable_dec)->name = (yyvsp[0].string_val)->value;
		delete (yyvsp[0].string_val);
	}
#line 1973 "parser.cpp"
    break;

  case 24:
#line 288 "parser.y"
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
#line 1989 "parser.cpp"
    break;

  case 25:
#line 299 "parser.y"
    { 
		(yyval.variable_dec)=new VariableDeclaration();
		(yyval.variable_dec)->name= (yyvsp[-3].string_val)->value;
		delete (yyvsp[-3].string_val);

		(yyval.variable_dec)->size_of_vector = (yyvsp[-1].int_val)->value;
		delete (yyvsp[-1].int_val);
	}
#line 2002 "parser.cpp"
    break;

  case 26:
#line 307 "parser.y"
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
#line 2020 "parser.cpp"
    break;

  case 27:
#line 325 "parser.y"
    { 
		(yyval.expr) = new Expression();
		(yyval.expr)->name = (yyvsp[0].string_val)->value;
		(yyval.expr)->e_type = VARIABLE_NAME;

		//$$->value = search($$->name)->value;

		delete (yyvsp[0].string_val);
	}
#line 2034 "parser.cpp"
    break;

  case 28:
#line 334 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type=TYPE_INT;
		(yyval.expr)->value.int_val = std::shared_ptr<IntVal>((yyvsp[0].int_val));
		(yyval.expr)->e_type = VALUE;
	}
#line 2045 "parser.cpp"
    break;

  case 29:
#line 340 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type = TYPE_FLOAT;
		(yyval.expr)->value.float_val = std::shared_ptr<FloatVal>((yyvsp[0].float_val));
		(yyval.expr)->e_type = VALUE;
	}
#line 2056 "parser.cpp"
    break;

  case 30:
#line 346 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type = TYPE_CHAR;
		(yyval.expr)->value.char_val = std::shared_ptr<CharVal>((yyvsp[0].char_val));
		(yyval.expr)->e_type = VALUE;
	}
#line 2067 "parser.cpp"
    break;

  case 31:
#line 352 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type = TYPE_STRING;
		(yyval.expr)->value.string_val = std::shared_ptr<StringVal>((yyvsp[0].string_val));
		(yyval.expr)->e_type = VALUE;
	}
#line 2078 "parser.cpp"
    break;

  case 32:
#line 358 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type = TYPE_BOOL;
		(yyval.expr)->value.bool_val = std::shared_ptr<BoolVal>((yyvsp[0].bool_val));
		(yyval.expr)->e_type = VALUE;
	}
#line 2089 "parser.cpp"
    break;

  case 33:
#line 364 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->type = TYPE_BOOL;
		(yyval.expr)->value.bool_val = std::shared_ptr<BoolVal>((yyvsp[0].bool_val));
		(yyval.expr)->e_type = VALUE;
	}
#line 2100 "parser.cpp"
    break;

  case 34:
#line 370 "parser.y"
    { 
		(yyval.expr) = new Expression();

		(yyval.expr)->call = std::shared_ptr<FunctionCall>((yyvsp[-1].func_call));
		(yyval.expr)->call->name = (yyvsp[-3].string_val)->value;
		(yyval.expr)->e_type = CALL;
		//search for function template - validate name and params
		
	}
#line 2114 "parser.cpp"
    break;

  case 35:
#line 379 "parser.y"
    { 
		(yyval.expr)=new Expression();
		(yyval.expr)->name = (yyvsp[-3].string_val)->value;
		(yyval.expr)->e_type = VECTOR_NAME;
		(yyval.expr)->position = (yyvsp[-1].expr)->value.int_val->value; //trebuie evaluata aici poz
		delete (yyvsp[-1].expr);
		//to be implemented - need type deduction
		//by searching for variable
	}
#line 2128 "parser.cpp"
    break;

  case 36:
#line 388 "parser.y"
    { //ignore all OF statements
		(yyval.expr)=new Expression();

		(yyval.expr)->var = search_variable_in_class((yyvsp[-2].string_val)->value, (yyvsp[0].string_val)->value); //if null, fail
		(yyval.expr)->e_type = REFERENCE;
		
		//to be implemented - need type deduction
		//by searching for variable
	}
#line 2142 "parser.cpp"
    break;

  case 37:
#line 397 "parser.y"
    { 
		(yyval.expr)=new Expression();

		//to be implemented - need type deduction
		//by searching for variable
	}
#line 2153 "parser.cpp"
    break;

  case 38:
#line 403 "parser.y"
    { 
		(yyval.expr)=new Expression(); 

		//to be implemented - need type deduction
		//by searching for variable
	}
#line 2164 "parser.cpp"
    break;

  case 39:
#line 409 "parser.y"
    { 
		(yyval.expr)=new Expression();

		//to be implemented - need type deduction
		//by searching for variable
	}
#line 2175 "parser.cpp"
    break;

  case 40:
#line 415 "parser.y"
    { 
		(yyval.expr)=new Expression();
		//$$->type = $1->type;
		//$$->value = $1->value;
	}
#line 2185 "parser.cpp"
    break;

  case 41:
#line 425 "parser.y"
    {
	  (yyval.int_val) = new IntVal({ 0 });
	}
#line 2193 "parser.cpp"
    break;

  case 42:
#line 428 "parser.y"
    {
		(yyval.int_val) = new IntVal({(yyvsp[0].int_val)->value});
		delete (yyvsp[0].int_val);
	}
#line 2202 "parser.cpp"
    break;

  case 43:
#line 435 "parser.y"
    {  }
#line 2208 "parser.cpp"
    break;

  case 44:
#line 440 "parser.y"
    {  }
#line 2214 "parser.cpp"
    break;

  case 45:
#line 441 "parser.y"
    {  }
#line 2220 "parser.cpp"
    break;

  case 46:
#line 446 "parser.y"
    {  }
#line 2226 "parser.cpp"
    break;

  case 47:
#line 447 "parser.y"
    {  }
#line 2232 "parser.cpp"
    break;

  case 48:
#line 452 "parser.y"
    {  }
#line 2238 "parser.cpp"
    break;

  case 49:
#line 453 "parser.y"
    {  }
#line 2244 "parser.cpp"
    break;

  case 50:
#line 454 "parser.y"
    {  }
#line 2250 "parser.cpp"
    break;

  case 51:
#line 455 "parser.y"
    {  }
#line 2256 "parser.cpp"
    break;

  case 52:
#line 466 "parser.y"
    {  }
#line 2262 "parser.cpp"
    break;

  case 53:
#line 467 "parser.y"
    {  }
#line 2268 "parser.cpp"
    break;

  case 54:
#line 472 "parser.y"
    {  }
#line 2274 "parser.cpp"
    break;

  case 55:
#line 477 "parser.y"
    {  }
#line 2280 "parser.cpp"
    break;

  case 56:
#line 478 "parser.y"
    {  }
#line 2286 "parser.cpp"
    break;

  case 57:
#line 483 "parser.y"
    {/*nu stiu daca aici este corect, dar eu presupun ca da*/  }
#line 2292 "parser.cpp"
    break;

  case 58:
#line 488 "parser.y"
    {  }
#line 2298 "parser.cpp"
    break;

  case 59:
#line 489 "parser.y"
    {  }
#line 2304 "parser.cpp"
    break;

  case 60:
#line 494 "parser.y"
    {  }
#line 2310 "parser.cpp"
    break;

  case 61:
#line 495 "parser.y"
    {  }
#line 2316 "parser.cpp"
    break;

  case 62:
#line 500 "parser.y"
    {  }
#line 2322 "parser.cpp"
    break;

  case 63:
#line 501 "parser.y"
    {  }
#line 2328 "parser.cpp"
    break;

  case 64:
#line 506 "parser.y"
    {  }
#line 2334 "parser.cpp"
    break;

  case 65:
#line 507 "parser.y"
    {  }
#line 2340 "parser.cpp"
    break;

  case 66:
#line 508 "parser.y"
    {  }
#line 2346 "parser.cpp"
    break;

  case 67:
#line 509 "parser.y"
    {  }
#line 2352 "parser.cpp"
    break;

  case 68:
#line 514 "parser.y"
    {  }
#line 2358 "parser.cpp"
    break;

  case 69:
#line 515 "parser.y"
    {  }
#line 2364 "parser.cpp"
    break;

  case 70:
#line 516 "parser.y"
    {  }
#line 2370 "parser.cpp"
    break;

  case 71:
#line 517 "parser.y"
    {  }
#line 2376 "parser.cpp"
    break;

  case 72:
#line 518 "parser.y"
    {  }
#line 2382 "parser.cpp"
    break;

  case 73:
#line 519 "parser.y"
    {  }
#line 2388 "parser.cpp"
    break;

  case 74:
#line 520 "parser.y"
    {  }
#line 2394 "parser.cpp"
    break;

  case 75:
#line 521 "parser.y"
    {  }
#line 2400 "parser.cpp"
    break;

  case 76:
#line 522 "parser.y"
    {  }
#line 2406 "parser.cpp"
    break;

  case 77:
#line 523 "parser.y"
    {  }
#line 2412 "parser.cpp"
    break;

  case 78:
#line 524 "parser.y"
    {  }
#line 2418 "parser.cpp"
    break;

  case 79:
#line 529 "parser.y"
    {  }
#line 2424 "parser.cpp"
    break;

  case 80:
#line 530 "parser.y"
    {  }
#line 2430 "parser.cpp"
    break;

  case 81:
#line 531 "parser.y"
    {  }
#line 2436 "parser.cpp"
    break;

  case 82:
#line 532 "parser.y"
    {  }
#line 2442 "parser.cpp"
    break;

  case 83:
#line 533 "parser.y"
    {  }
#line 2448 "parser.cpp"
    break;

  case 84:
#line 534 "parser.y"
    {  }
#line 2454 "parser.cpp"
    break;

  case 85:
#line 535 "parser.y"
    {  }
#line 2460 "parser.cpp"
    break;

  case 86:
#line 540 "parser.y"
    {  }
#line 2466 "parser.cpp"
    break;

  case 87:
#line 545 "parser.y"
    {  }
#line 2472 "parser.cpp"
    break;

  case 88:
#line 550 "parser.y"
    {  }
#line 2478 "parser.cpp"
    break;

  case 89:
#line 551 "parser.y"
    {  }
#line 2484 "parser.cpp"
    break;

  case 93:
#line 555 "parser.y"
    {  }
#line 2490 "parser.cpp"
    break;

  case 94:
#line 560 "parser.y"
    {  }
#line 2496 "parser.cpp"
    break;

  case 95:
#line 561 "parser.y"
    {  }
#line 2502 "parser.cpp"
    break;

  case 96:
#line 562 "parser.y"
    {  }
#line 2508 "parser.cpp"
    break;

  case 97:
#line 563 "parser.y"
    {  }
#line 2514 "parser.cpp"
    break;

  case 98:
#line 564 "parser.y"
    {  }
#line 2520 "parser.cpp"
    break;

  case 99:
#line 565 "parser.y"
    {  }
#line 2526 "parser.cpp"
    break;

  case 100:
#line 566 "parser.y"
    {  }
#line 2532 "parser.cpp"
    break;

  case 101:
#line 567 "parser.y"
    {  }
#line 2538 "parser.cpp"
    break;

  case 102:
#line 572 "parser.y"
    {/*de asemenea nu stiu daca este ok ce fac aicea*/  }
#line 2544 "parser.cpp"
    break;

  case 103:
#line 577 "parser.y"
    {  }
#line 2550 "parser.cpp"
    break;

  case 104:
#line 578 "parser.y"
    {  }
#line 2556 "parser.cpp"
    break;

  case 105:
#line 583 "parser.y"
    {  }
#line 2562 "parser.cpp"
    break;

  case 106:
#line 588 "parser.y"
    {  }
#line 2568 "parser.cpp"
    break;

  case 107:
#line 593 "parser.y"
    {  }
#line 2574 "parser.cpp"
    break;

  case 108:
#line 598 "parser.y"
    {  }
#line 2580 "parser.cpp"
    break;

  case 109:
#line 603 "parser.y"
    {  }
#line 2586 "parser.cpp"
    break;

  case 110:
#line 608 "parser.y"
    {  }
#line 2592 "parser.cpp"
    break;

  case 111:
#line 609 "parser.y"
    {  }
#line 2598 "parser.cpp"
    break;

  case 112:
#line 614 "parser.y"
    {  }
#line 2604 "parser.cpp"
    break;

  case 113:
#line 615 "parser.y"
    {  }
#line 2610 "parser.cpp"
    break;

  case 114:
#line 616 "parser.y"
    {  }
#line 2616 "parser.cpp"
    break;

  case 115:
#line 617 "parser.y"
    {  }
#line 2622 "parser.cpp"
    break;

  case 116:
#line 618 "parser.y"
    {  }
#line 2628 "parser.cpp"
    break;

  case 117:
#line 619 "parser.y"
    {  }
#line 2634 "parser.cpp"
    break;

  case 118:
#line 624 "parser.y"
    {  }
#line 2640 "parser.cpp"
    break;

  case 119:
#line 629 "parser.y"
    {  }
#line 2646 "parser.cpp"
    break;

  case 120:
#line 630 "parser.y"
    {  }
#line 2652 "parser.cpp"
    break;

  case 121:
#line 633 "parser.y"
    {  }
#line 2658 "parser.cpp"
    break;

  case 122:
#line 634 "parser.y"
    {  }
#line 2664 "parser.cpp"
    break;

  case 123:
#line 635 "parser.y"
    {  }
#line 2670 "parser.cpp"
    break;

  case 124:
#line 636 "parser.y"
    {  }
#line 2676 "parser.cpp"
    break;

  case 125:
#line 637 "parser.y"
    {  }
#line 2682 "parser.cpp"
    break;

  case 126:
#line 638 "parser.y"
    {  }
#line 2688 "parser.cpp"
    break;

  case 127:
#line 641 "parser.y"
    {  }
#line 2694 "parser.cpp"
    break;

  case 128:
#line 642 "parser.y"
    {  }
#line 2700 "parser.cpp"
    break;

  case 129:
#line 643 "parser.y"
    {  }
#line 2706 "parser.cpp"
    break;

  case 130:
#line 644 "parser.y"
    {  }
#line 2712 "parser.cpp"
    break;

  case 131:
#line 645 "parser.y"
    {  }
#line 2718 "parser.cpp"
    break;

  case 132:
#line 646 "parser.y"
    {  }
#line 2724 "parser.cpp"
    break;

  case 133:
#line 647 "parser.y"
    {  }
#line 2730 "parser.cpp"
    break;

  case 134:
#line 648 "parser.y"
    {  }
#line 2736 "parser.cpp"
    break;

  case 135:
#line 649 "parser.y"
    {  }
#line 2742 "parser.cpp"
    break;

  case 136:
#line 650 "parser.y"
    {  }
#line 2748 "parser.cpp"
    break;

  case 137:
#line 651 "parser.y"
    {  }
#line 2754 "parser.cpp"
    break;

  case 138:
#line 652 "parser.y"
    {  }
#line 2760 "parser.cpp"
    break;

  case 139:
#line 653 "parser.y"
    {  }
#line 2766 "parser.cpp"
    break;

  case 140:
#line 654 "parser.y"
    {  }
#line 2772 "parser.cpp"
    break;

  case 141:
#line 655 "parser.y"
    {  }
#line 2778 "parser.cpp"
    break;

  case 142:
#line 658 "parser.y"
    {  }
#line 2784 "parser.cpp"
    break;

  case 143:
#line 659 "parser.y"
    {  }
#line 2790 "parser.cpp"
    break;

  case 144:
#line 660 "parser.y"
    {  }
#line 2796 "parser.cpp"
    break;

  case 145:
#line 661 "parser.y"
    {  }
#line 2802 "parser.cpp"
    break;

  case 146:
#line 666 "parser.y"
    {  }
#line 2808 "parser.cpp"
    break;

  case 147:
#line 671 "parser.y"
    {  }
#line 2814 "parser.cpp"
    break;

  case 148:
#line 672 "parser.y"
    {  }
#line 2820 "parser.cpp"
    break;

  case 149:
#line 673 "parser.y"
    {  }
#line 2826 "parser.cpp"
    break;

  case 150:
#line 674 "parser.y"
    {  }
#line 2832 "parser.cpp"
    break;

  case 151:
#line 675 "parser.y"
    {  }
#line 2838 "parser.cpp"
    break;

  case 152:
#line 676 "parser.y"
    {  }
#line 2844 "parser.cpp"
    break;

  case 153:
#line 677 "parser.y"
    {  }
#line 2850 "parser.cpp"
    break;

  case 154:
#line 678 "parser.y"
    {  }
#line 2856 "parser.cpp"
    break;

  case 155:
#line 679 "parser.y"
    {  }
#line 2862 "parser.cpp"
    break;

  case 156:
#line 680 "parser.y"
    {  }
#line 2868 "parser.cpp"
    break;

  case 157:
#line 681 "parser.y"
    {  }
#line 2874 "parser.cpp"
    break;

  case 158:
#line 682 "parser.y"
    {  }
#line 2880 "parser.cpp"
    break;

  case 159:
#line 687 "parser.y"
    {  }
#line 2886 "parser.cpp"
    break;


#line 2890 "parser.cpp"

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
#line 690 "parser.y"


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
(std::string name)
{
	return nullptr;
}

std::shared_ptr<VariableDeclaration> search_variable_in_class
(std::string name, std::string class_object)
{
	return nullptr;
}
