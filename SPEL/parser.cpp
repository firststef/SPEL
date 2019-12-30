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

#line 78 "parser.cpp"

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
#line 9 "parser.y"


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

#line 157 "parser.cpp"

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
    CHR = 267,
    ID = 268,
    NR = 269,
    NRF = 270,
    NOT = 271,
    STR = 272,
    TRUE = 273,
    FALSE = 274,
    BGNF = 275,
    ENDF = 276,
    AND = 277,
    OR = 278,
    RET = 279,
    CLASS = 280,
    CONST = 281,
    BOOL = 282,
    ELSE = 283,
    IF = 284,
    FOR = 285,
    WHILE = 286,
    ENDWHILE = 287,
    BEGINIF = 288,
    BEGINELSE = 289,
    ENDELSE = 290,
    ENDIF = 291,
    ENDFOR = 292,
    VOID = 293,
    IN = 294,
    EVAL = 295,
    BG = 296,
    BGNP = 297,
    ENDCLASS = 298,
    CRAFT = 299,
    BSTOW = 300,
    ENCH = 301,
    WITH = 302,
    SACRF = 303,
    TIME = 304,
    CHNT = 305,
    IFX = 306,
    UMINUS = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 79 "parser.y"

	Node* node;
	CompileUnit* c_unit;
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

#line 241 "parser.cpp"

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
#define YYLAST   510

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  163
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  349

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
       0,   101,   101,   107,   111,   117,   121,   125,   126,   127,
     130,   135,   136,   137,   138,   143,   144,   149,   150,   151,
     152,   153,   154,   159,   160,   165,   166,   167,   168,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   191,   192,   197,   202,   203,   208,   209,
     214,   215,   216,   217,   222,   223,   228,   229,   234,   239,
     240,   245,   250,   251,   256,   257,   262,   263,   268,   269,
     270,   271,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   291,   292,   293,   294,   295,   296,   297,
     302,   307,   312,   313,   314,   315,   316,   317,   322,   323,
     324,   325,   326,   327,   328,   329,   334,   339,   340,   345,
     350,   355,   360,   365,   370,   371,   376,   377,   378,   379,
     380,   381,   386,   391,   392,   395,   396,   397,   398,   399,
     400,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   420,   421,   422,   423,
     428,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   449
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LEQ", "BEQ", "EQ", "NEQ", "INT", "OF",
  "FLOAT", "CHAR", "STRING", "CHR", "ID", "NR", "NRF", "NOT", "STR",
  "TRUE", "FALSE", "BGNF", "ENDF", "AND", "OR", "RET", "CLASS", "CONST",
  "BOOL", "ELSE", "IF", "FOR", "WHILE", "ENDWHILE", "BEGINIF", "BEGINELSE",
  "ENDELSE", "ENDIF", "ENDFOR", "VOID", "IN", "EVAL", "BG", "BGNP",
  "ENDCLASS", "CRAFT", "BSTOW", "ENCH", "WITH", "SACRF", "TIME", "CHNT",
  "IFX", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "'.'",
  "','", "'['", "']'", "':'", "'('", "')'", "$accept", "sp",
  "compile_unit", "class_def", "class_body", "class_var", "type",
  "class_ids", "class_id", "class_id_initialization", "vector_size",
  "vector_initialization", "vector_body", "call_parameters",
  "vector_position", "const_class_ids", "const_class_id",
  "const_vector_size", "f_parameters", "f_parameter", "class_f",
  "f_declaration_parameters", "declaration_parameters",
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

#define YYPACT_NINF -235

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-235)))

#define YYTABLE_NINF -117

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -33,   357,    13,  -235,  -235,  -235,  -235,  -235,   287,     9,
    -235,   -48,   -32,   -25,    45,   -23,   399,    60,    83,  -235,
     357,  -235,    88,  -235,  -235,  -235,  -235,   357,   357,  -235,
    -235,  -235,    10,  -235,  -235,  -235,  -235,  -235,    92,   100,
     307,   307,    57,  -235,   109,   389,   220,   106,    96,   220,
     146,    11,   429,   149,     0,   128,  -235,   166,  -235,  -235,
     168,     6,   131,   129,  -235,   391,  -235,   307,   307,   307,
     307,   307,   141,   389,   389,   287,   243,  -235,    32,   132,
    -235,    85,   157,  -235,   133,  -235,   154,   139,   145,   137,
     199,   -39,   170,   153,   238,   287,     6,   231,   192,   190,
     201,  -235,   258,   209,   307,   231,  -235,    89,    89,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,   207,   165,   220,   220,
     241,   307,   307,   307,   307,   307,   307,    80,   163,   364,
     216,   218,  -235,   -35,   219,   221,   298,   278,  -235,   149,
     247,   235,   234,   204,    -3,   227,   268,   275,   286,   295,
    -235,   290,  -235,   245,  -235,   246,  -235,   364,     6,     6,
     266,   315,   109,   263,   104,  -235,  -235,   163,   306,   109,
     109,   109,   109,   109,   109,  -235,   -28,  -235,  -235,   327,
     277,   281,   298,   276,   338,   341,   163,  -235,   163,  -235,
     328,  -235,  -235,   429,  -235,   348,   301,  -235,   308,  -235,
    -235,   298,   362,  -235,   199,  -235,  -235,   316,  -235,   287,
    -235,   331,   367,     6,   335,   325,   298,   329,   326,   342,
     231,   379,  -235,   220,   220,   358,   370,     6,   363,   163,
     110,   354,   360,    18,     4,   374,  -235,  -235,  -235,   410,
     375,   160,   408,  -235,  -235,   361,  -235,   396,   383,   287,
     164,   381,   231,  -235,  -235,   163,  -235,  -235,   388,   393,
    -235,  -235,  -235,   163,  -235,   397,   231,  -235,  -235,   406,
    -235,   163,   163,   404,   405,   409,   452,   287,     6,   231,
     411,   412,   160,   160,   451,  -235,   431,   415,  -235,   414,
       6,    22,   416,   457,  -235,     6,   444,  -235,   417,  -235,
    -235,   422,   423,  -235,   437,   425,   424,   426,   428,  -235,
    -235,  -235,  -235,   415,   298,  -235,  -235,   430,   473,   390,
    -235,   432,  -235,  -235,  -235,  -235,   287,  -235,   441,   434,
    -235,  -235,   435,   436,   398,   368,  -235,   438,   287,  -235,
     298,  -235,     6,  -235,   440,  -235,   439,  -235,   403
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,    18,    19,    20,    21,    17,     0,     0,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       7,   163,     0,   150,   153,   152,   154,     8,     9,   151,
       1,   142,   125,   140,   141,   143,   144,   145,     0,     0,
       0,     0,     0,   138,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,     5,     6,
       0,     0,     0,     0,   137,     0,   162,     0,     0,     0,
       0,     0,     0,    11,    12,     0,     0,   109,    92,     0,
      99,   123,     0,   112,     0,    91,     0,     0,     0,     0,
       0,    25,     0,    23,     0,     0,     0,     0,     0,   127,
      50,    51,     0,     0,     0,     0,   131,   132,   133,   134,
     135,   136,    10,    13,    14,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,     0,     0,    54,     0,    43,    15,     0,
       0,     0,     0,   142,   125,   140,   141,   143,   144,   145,
      48,     0,    61,     0,    49,    59,    42,     0,     0,     0,
       0,   126,   124,     0,    96,    93,    97,     0,   107,   105,
     104,   103,   102,   101,   100,   119,   114,   117,   118,     0,
       0,     0,     0,     0,     0,     0,    76,   106,    79,    87,
       0,    88,    89,     0,    64,     0,     0,    65,    66,   161,
     160,     0,     0,    16,     0,    26,    44,     0,    24,     0,
     155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   139,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,    75,    90,     0,
      68,     0,     0,    56,    58,     0,    55,    27,     0,     0,
     127,     0,     0,   158,    60,     0,   129,    53,     0,   128,
      94,    95,   110,     0,   108,     0,     0,   122,   113,   116,
     115,    77,    78,     0,     0,     0,     0,     0,     0,     0,
      70,     0,   148,   149,     0,    67,     0,     0,   157,     0,
       0,   126,     0,     0,    52,     0,     0,   121,     0,    73,
      74,     0,     0,    80,     0,     0,     0,     0,     0,    69,
     146,   147,    63,     0,     0,    28,   156,     0,     0,   139,
      62,     0,   111,   120,    82,    81,     0,    83,     0,     0,
      71,    57,    46,     0,   129,   128,   130,     0,     0,    86,
       0,    45,     0,    85,     0,    47,     0,    84,   130
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -235,  -235,    87,  -235,    29,     1,   -13,   350,  -235,  -132,
    -235,   179,   161,   -91,   -95,   293,  -235,  -235,   288,  -235,
     -30,   346,   264,  -235,  -151,  -234,    25,  -235,   -38,   433,
    -235,   108,  -235,  -235,  -235,   130,  -235,  -235,   280,  -235,
      -8,   467,    30,  -110,  -235,  -235,  -235
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    19,    20,    72,   186,    22,    92,    93,   152,
     207,   315,   333,   153,   103,   134,   135,   245,   154,   155,
      23,   196,   197,   198,   187,   188,   189,    84,    77,    78,
     190,   191,    79,   168,   264,   192,    48,   180,   181,   268,
     156,    43,    44,   284,    27,    28,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,   142,    21,    53,   205,   212,   136,   283,    94,     1,
     201,    85,   276,    30,   163,    74,   225,    46,    60,   100,
     101,    21,    45,   137,    87,    88,    24,   202,    21,    21,
     318,   273,   274,    47,   227,   236,  -116,   237,    80,    90,
      49,    80,    51,    74,    74,    24,    73,    95,   283,   283,
     231,   277,    24,    24,   118,   119,   102,   -29,   -29,   213,
     -29,   -29,    96,   218,   219,    50,   278,   115,    80,   243,
      64,    65,    61,    54,    73,    73,    81,    89,   267,    81,
     165,   166,   -37,   -37,   275,   -37,   -37,   141,   121,   122,
     123,   124,   175,   176,   177,   178,    55,   107,   108,   109,
     110,   111,   113,   114,   293,    32,   117,    56,    57,    25,
      80,    80,   296,    63,    58,    59,   195,    66,   251,    82,
     299,   300,   175,   269,   177,   178,   223,   224,    25,   258,
     179,    26,   265,    83,   162,    25,    25,   125,   126,    67,
      68,    69,    70,    71,   195,    69,    70,    71,    81,    81,
      26,   169,   170,   171,   172,   173,   174,    26,    26,    86,
     179,   292,    91,    67,    68,    69,    70,    71,   121,   122,
     123,   124,   310,   311,   232,   298,    97,   105,   104,    98,
     239,    99,   332,   306,   112,   260,   261,   182,   307,    11,
      12,    13,    11,    12,    13,   317,   127,   132,   120,   128,
     321,   248,   129,   183,    16,   130,   184,    16,   332,   184,
     185,   131,   133,   185,   139,    80,    80,   125,   126,    67,
      68,    69,    70,    71,   -38,   -38,   290,   -38,   -38,   195,
     138,   106,    31,    32,    33,    34,    75,    35,    36,    37,
     157,   289,   282,   143,   144,   145,   146,   346,   147,   148,
     149,   140,   158,    81,    81,    31,    32,    33,    34,    75,
      35,    36,    37,   159,   -32,   -32,    38,   -32,   -32,   305,
      39,   160,   161,   164,   167,    40,   199,    38,   200,   203,
     150,   151,   204,   282,   282,    76,    40,   -30,   -30,    38,
     -30,   -30,   206,    39,   209,   210,    41,   211,    40,    31,
      32,    33,    34,   214,    35,    36,    37,   216,    41,   215,
     143,   144,   145,   146,   220,   147,   148,   149,   337,    31,
      32,    33,    34,   221,    35,    36,    37,   222,   -31,   -31,
     344,   -31,   -31,    38,   226,   -33,   -33,    39,   -33,   -33,
     228,   233,    40,   229,    38,   230,   -34,   -34,   151,   -34,
     -34,   234,    41,    40,   235,   -35,   -35,    39,   -35,   -35,
     238,   240,    40,    41,     3,   241,     4,     5,     6,   242,
       7,     3,    41,     4,     5,     6,   244,     7,   249,   247,
     250,     8,     9,   252,    10,   253,    11,    12,    13,   256,
     193,    10,   259,   255,   262,    14,     3,    15,     4,     5,
       6,    16,     7,    17,   263,   257,     3,    18,     4,     5,
       6,   266,     7,   194,   271,     3,    10,     4,     5,     6,
     272,     7,   279,   280,   286,    52,    10,    14,   -39,   -39,
     342,   -39,   -39,    16,   193,    10,     3,   281,     4,     5,
       6,   287,     7,   288,   291,    67,    68,    69,    70,    71,
     -36,   -36,   294,   -36,   -36,   295,    10,   106,   -40,   -40,
     297,   -40,   -40,   -41,   -41,   304,   -41,   -41,   227,   303,
     301,   302,   312,   308,   316,   309,   313,   314,   320,   322,
     319,   323,   324,   325,   326,   327,   335,   328,   338,   208,
     329,   330,   331,   334,   339,   336,   340,   246,   343,   341,
     347,   345,   348,   217,   254,    62,   285,     0,     0,   116,
     270
};

static const yytype_int16 yycheck[] =
{
       8,    96,     1,    16,   136,     8,    45,   241,     8,    42,
      45,    49,     8,     0,   105,    45,   167,    65,     8,    13,
      14,    20,    13,    62,    13,    14,     1,    62,    27,    28,
       8,    13,    14,    65,    62,   186,    64,   188,    46,    52,
      65,    49,    65,    73,    74,    20,    45,    47,   282,   283,
     182,    47,    27,    28,    22,    23,    50,    60,    61,    62,
      63,    64,    62,   158,   159,    20,    62,    75,    76,   201,
      40,    41,    62,    13,    73,    74,    46,    66,   229,    49,
     118,   119,    60,    61,    66,    63,    64,    95,     3,     4,
       5,     6,    12,    13,    14,    15,    13,    67,    68,    69,
      70,    71,    73,    74,   255,    13,    76,    20,    20,     1,
     118,   119,   263,    13,    27,    28,   129,    60,   213,    13,
     271,   272,    12,    13,    14,    15,    22,    23,    20,   220,
      50,     1,   227,    37,   104,    27,    28,    52,    53,    54,
      55,    56,    57,    58,   157,    56,    57,    58,   118,   119,
      20,   121,   122,   123,   124,   125,   126,    27,    28,    13,
      50,   252,    13,    54,    55,    56,    57,    58,     3,     4,
       5,     6,   282,   283,   182,   266,    48,    48,    47,    13,
     193,    13,   314,   278,    43,   223,   224,    24,   279,    29,
      30,    31,    29,    30,    31,   290,    39,    60,    66,    66,
     295,   209,    48,    40,    44,    66,    46,    44,   340,    46,
      50,    66,    13,    50,    61,   223,   224,    52,    53,    54,
      55,    56,    57,    58,    60,    61,    62,    63,    64,   242,
      60,    66,    12,    13,    14,    15,    16,    17,    18,    19,
      48,   249,   241,    12,    13,    14,    15,   342,    17,    18,
      19,    13,    62,   223,   224,    12,    13,    14,    15,    16,
      17,    18,    19,    62,    60,    61,    46,    63,    64,   277,
      50,    13,    63,    66,    33,    55,    60,    46,    60,    60,
      49,    50,    61,   282,   283,    65,    55,    60,    61,    46,
      63,    64,    14,    50,    47,    60,    65,    63,    55,    12,
      13,    14,    15,    13,    17,    18,    19,    61,    65,    64,
      12,    13,    14,    15,    48,    17,    18,    19,   326,    12,
      13,    14,    15,     8,    17,    18,    19,    64,    60,    61,
     338,    63,    64,    46,    28,    60,    61,    50,    63,    64,
      13,    65,    55,    66,    46,    64,    60,    61,    50,    63,
      64,    13,    65,    55,    13,    60,    61,    50,    63,    64,
      32,    13,    55,    65,     7,    64,     9,    10,    11,    61,
      13,     7,    65,     9,    10,    11,    14,    13,    47,    63,
      13,    24,    25,    48,    27,    60,    29,    30,    31,    63,
      26,    27,    13,    64,    36,    38,     7,    40,     9,    10,
      11,    44,    13,    46,    34,    63,     7,    50,     9,    10,
      11,    48,    13,    49,    60,     7,    27,     9,    10,    11,
      60,    13,    48,    13,    63,    26,    27,    38,    60,    61,
      62,    63,    64,    44,    26,    27,     7,    62,     9,    10,
      11,    45,    13,    60,    63,    54,    55,    56,    57,    58,
      60,    61,    64,    63,    64,    62,    27,    66,    60,    61,
      63,    63,    64,    60,    61,    13,    63,    64,    62,    60,
      66,    66,    21,    62,    60,    63,    45,    62,    21,    35,
      64,    64,    60,    60,    47,    60,    13,    63,    47,   139,
      64,    63,   313,    63,    60,    63,    61,   204,    60,    63,
      60,   340,    63,   157,   216,    38,   242,    -1,    -1,    76,
     230
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    68,     7,     9,    10,    11,    13,    24,    25,
      27,    29,    30,    31,    38,    40,    44,    46,    50,    69,
      70,    72,    73,    87,    93,    98,   102,   111,   112,   113,
       0,    12,    13,    14,    15,    17,    18,    19,    46,    50,
      55,    65,   107,   108,   109,    13,    65,    65,   103,    65,
      20,    65,    26,    73,    13,    13,    69,    20,    69,    69,
       8,    62,   108,    13,   109,   109,    60,    54,    55,    56,
      57,    58,    71,    72,    87,    16,    65,    95,    96,    99,
     107,   109,    13,    37,    94,    95,    13,    13,    14,    66,
      73,    13,    74,    75,     8,    47,    62,    48,    13,    13,
      13,    14,    50,    81,    47,    48,    66,   109,   109,   109,
     109,   109,    43,    71,    71,   107,    96,   109,    22,    23,
      66,     3,     4,     5,     6,    52,    53,    39,    66,    48,
      66,    66,    60,    13,    82,    83,    45,    62,    60,    61,
      13,   107,    81,    12,    13,    14,    15,    17,    18,    19,
      49,    50,    76,    80,    85,    86,   107,    48,    62,    62,
      13,    63,   109,    80,    66,    95,    95,    33,   100,   109,
     109,   109,   109,   109,   109,    12,    13,    14,    15,    50,
     104,   105,    24,    40,    46,    50,    72,    91,    92,    93,
      97,    98,   102,    26,    49,    73,    88,    89,    90,    60,
      60,    45,    62,    60,    61,    76,    14,    77,    74,    47,
      60,    63,     8,    62,    13,    64,    61,    88,    81,    81,
      48,     8,    64,    22,    23,    91,    28,    62,    13,    66,
      64,    76,   107,    65,    13,    13,    91,    91,    32,    73,
      13,    64,    61,    76,    14,    84,    82,    63,   107,    47,
      13,    81,    48,    60,    85,    64,    63,    63,    80,    13,
      95,    95,    36,    34,   101,    81,    48,    91,   106,    13,
     105,    60,    60,    13,    14,    66,     8,    47,    62,    48,
      13,    62,    72,    92,   110,    89,    63,    45,    60,   107,
      62,    63,    80,    91,    64,    62,    91,    63,    80,    91,
      91,    66,    66,    60,    13,   107,    81,    80,    62,    63,
     110,   110,    21,    45,    62,    78,    60,    81,     8,    64,
      21,    81,    35,    64,    60,    60,    47,    60,    63,    64,
      63,    78,    76,    79,    63,    13,    63,   107,    47,    60,
      61,    63,    62,    60,   107,    79,    81,    60,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    68,    69,    69,    69,    69,    69,    69,
      70,    71,    71,    71,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    74,    74,    75,    75,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    77,    77,    78,    79,    79,    80,    80,
      81,    81,    81,    81,    82,    82,    83,    83,    84,    85,
      85,    86,    87,    87,    88,    88,    89,    89,    90,    90,
      90,    90,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    92,    92,    92,    92,    92,    92,    92,
      93,    94,    95,    95,    95,    95,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    96,    97,    98,    98,    99,
     100,   101,   102,   103,   104,   104,   105,   105,   105,   105,
     105,   105,   106,   107,   107,   108,   108,   108,   108,   108,
     108,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   110,   110,   110,   110,
     111,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   113
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     2,     1,     1,     1,
       4,     1,     1,     2,     2,     4,     5,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     4,     6,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     3,     6,
       6,     9,     1,     0,     1,     3,     1,     3,     1,     1,
       1,     1,     5,     4,     1,     3,     3,     6,     1,     1,
       3,     1,     8,     8,     1,     1,     1,     3,     2,     4,
       3,     5,     2,     4,     4,     2,     1,     3,     3,     1,
       4,     5,     5,     5,     8,     7,     6,     1,     1,     1,
       6,     1,     1,     3,     5,     5,     3,     3,     2,     1,
       3,     3,     3,     3,     3,     3,     1,     5,     7,     1,
       3,     3,     3,     6,     1,     3,     1,     1,     1,     1,
       5,     4,     1,     1,     4,     1,     4,     3,     6,     6,
       9,     3,     3,     3,     3,     3,     3,     2,     1,     5,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     5,     8,     7,     6,     4,
       5,     5,     3,     1
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
#line 101 "parser.y"
    {
	printf("Reached start symbol.\n");
	parse_state->rootNode = std::make_shared<Node>();
	(yyval.node) = parse_state->rootNode.get();
	(yyval.node)->c_unit = std::make_shared<CompileUnit>(); 
}
#line 1736 "parser.cpp"
    break;

  case 3:
#line 107 "parser.y"
    { printf("Reached start symbol.\n"); }
#line 1742 "parser.cpp"
    break;

  case 4:
#line 111 "parser.y"
    {
	PRINT_RULE 
	(yyval.c_unit) = new CompileUnit();
	(yyval.c_unit)->dec_holder.push_back(std::shared_ptr<DeclarationHolder>((yyvsp[-1].dec_holder)));
	(yyval.c_unit)->dec_holder.push_back((yyvsp[0].c_unit)->dec_holder.front());
}
#line 1753 "parser.cpp"
    break;

  case 5:
#line 117 "parser.y"
    {
	(yyval.c_unit) = new CompileUnit();
	PRINT_RULE
}
#line 1762 "parser.cpp"
    break;

  case 6:
#line 121 "parser.y"
    {
	(yyval.c_unit) = new CompileUnit();
	PRINT_RULE
}
#line 1771 "parser.cpp"
    break;

  case 7:
#line 125 "parser.y"
    { (yyval.c_unit) = new CompileUnit(); PRINT_RULE }
#line 1777 "parser.cpp"
    break;

  case 8:
#line 126 "parser.y"
    { (yyval.c_unit) = new CompileUnit(); PRINT_RULE }
#line 1783 "parser.cpp"
    break;

  case 9:
#line 127 "parser.y"
    { (yyval.c_unit) = new CompileUnit(); PRINT_RULE }
#line 1789 "parser.cpp"
    break;

  case 10:
#line 130 "parser.y"
    { (yyval.dec_holder) = new DeclarationHolder(); PRINT_RULE }
#line 1795 "parser.cpp"
    break;

  case 11:
#line 135 "parser.y"
    { PRINT_RULE }
#line 1801 "parser.cpp"
    break;

  case 12:
#line 136 "parser.y"
    { PRINT_RULE }
#line 1807 "parser.cpp"
    break;

  case 13:
#line 137 "parser.y"
    { PRINT_RULE }
#line 1813 "parser.cpp"
    break;

  case 14:
#line 138 "parser.y"
    { PRINT_RULE }
#line 1819 "parser.cpp"
    break;

  case 15:
#line 143 "parser.y"
    { PRINT_RULE }
#line 1825 "parser.cpp"
    break;

  case 16:
#line 144 "parser.y"
    { PRINT_RULE }
#line 1831 "parser.cpp"
    break;

  case 17:
#line 149 "parser.y"
    { PRINT_RULE }
#line 1837 "parser.cpp"
    break;

  case 18:
#line 150 "parser.y"
    { PRINT_RULE }
#line 1843 "parser.cpp"
    break;

  case 19:
#line 151 "parser.y"
    { PRINT_RULE }
#line 1849 "parser.cpp"
    break;

  case 20:
#line 152 "parser.y"
    { PRINT_RULE }
#line 1855 "parser.cpp"
    break;

  case 21:
#line 153 "parser.y"
    { PRINT_RULE }
#line 1861 "parser.cpp"
    break;

  case 22:
#line 154 "parser.y"
    { PRINT_RULE }
#line 1867 "parser.cpp"
    break;

  case 23:
#line 159 "parser.y"
    { PRINT_RULE }
#line 1873 "parser.cpp"
    break;

  case 24:
#line 160 "parser.y"
    { PRINT_RULE }
#line 1879 "parser.cpp"
    break;

  case 25:
#line 165 "parser.y"
    { PRINT_RULE }
#line 1885 "parser.cpp"
    break;

  case 26:
#line 166 "parser.y"
    { PRINT_RULE }
#line 1891 "parser.cpp"
    break;

  case 27:
#line 167 "parser.y"
    { PRINT_RULE }
#line 1897 "parser.cpp"
    break;

  case 28:
#line 168 "parser.y"
    { PRINT_RULE }
#line 1903 "parser.cpp"
    break;

  case 29:
#line 173 "parser.y"
    { PRINT_RULE }
#line 1909 "parser.cpp"
    break;

  case 30:
#line 174 "parser.y"
    { PRINT_RULE }
#line 1915 "parser.cpp"
    break;

  case 31:
#line 175 "parser.y"
    { PRINT_RULE }
#line 1921 "parser.cpp"
    break;

  case 32:
#line 176 "parser.y"
    { PRINT_RULE }
#line 1927 "parser.cpp"
    break;

  case 33:
#line 177 "parser.y"
    { PRINT_RULE }
#line 1933 "parser.cpp"
    break;

  case 34:
#line 178 "parser.y"
    { PRINT_RULE }
#line 1939 "parser.cpp"
    break;

  case 35:
#line 179 "parser.y"
    { PRINT_RULE }
#line 1945 "parser.cpp"
    break;

  case 36:
#line 180 "parser.y"
    { PRINT_RULE }
#line 1951 "parser.cpp"
    break;

  case 37:
#line 181 "parser.y"
    { PRINT_RULE }
#line 1957 "parser.cpp"
    break;

  case 38:
#line 182 "parser.y"
    { PRINT_RULE }
#line 1963 "parser.cpp"
    break;

  case 39:
#line 183 "parser.y"
    { PRINT_RULE }
#line 1969 "parser.cpp"
    break;

  case 40:
#line 184 "parser.y"
    { PRINT_RULE }
#line 1975 "parser.cpp"
    break;

  case 41:
#line 185 "parser.y"
    { PRINT_RULE }
#line 1981 "parser.cpp"
    break;

  case 42:
#line 186 "parser.y"
    { PRINT_RULE }
#line 1987 "parser.cpp"
    break;

  case 43:
#line 191 "parser.y"
    { PRINT_RULE /*s-ar putea sa ne vina mai usor daca facem vector size nul direct din regula fara eps pentru ca sa identificam noi nr de param*/}
#line 1993 "parser.cpp"
    break;

  case 44:
#line 192 "parser.y"
    { PRINT_RULE }
#line 1999 "parser.cpp"
    break;

  case 45:
#line 197 "parser.y"
    { PRINT_RULE }
#line 2005 "parser.cpp"
    break;

  case 46:
#line 202 "parser.y"
    { PRINT_RULE }
#line 2011 "parser.cpp"
    break;

  case 47:
#line 203 "parser.y"
    { PRINT_RULE }
#line 2017 "parser.cpp"
    break;

  case 48:
#line 208 "parser.y"
    { PRINT_RULE }
#line 2023 "parser.cpp"
    break;

  case 49:
#line 209 "parser.y"
    { PRINT_RULE }
#line 2029 "parser.cpp"
    break;

  case 50:
#line 214 "parser.y"
    { PRINT_RULE }
#line 2035 "parser.cpp"
    break;

  case 51:
#line 215 "parser.y"
    { PRINT_RULE }
#line 2041 "parser.cpp"
    break;

  case 52:
#line 216 "parser.y"
    { PRINT_RULE }
#line 2047 "parser.cpp"
    break;

  case 53:
#line 217 "parser.y"
    { PRINT_RULE }
#line 2053 "parser.cpp"
    break;

  case 54:
#line 222 "parser.y"
    { PRINT_RULE }
#line 2059 "parser.cpp"
    break;

  case 55:
#line 223 "parser.y"
    { PRINT_RULE }
#line 2065 "parser.cpp"
    break;

  case 56:
#line 228 "parser.y"
    { PRINT_RULE }
#line 2071 "parser.cpp"
    break;

  case 57:
#line 229 "parser.y"
    { PRINT_RULE }
#line 2077 "parser.cpp"
    break;

  case 58:
#line 234 "parser.y"
    { PRINT_RULE }
#line 2083 "parser.cpp"
    break;

  case 59:
#line 239 "parser.y"
    { PRINT_RULE }
#line 2089 "parser.cpp"
    break;

  case 60:
#line 240 "parser.y"
    { PRINT_RULE }
#line 2095 "parser.cpp"
    break;

  case 61:
#line 245 "parser.y"
    {/*nu stiu daca aici este corect, dar eu presupun ca da*/ PRINT_RULE }
#line 2101 "parser.cpp"
    break;

  case 62:
#line 250 "parser.y"
    { PRINT_RULE }
#line 2107 "parser.cpp"
    break;

  case 63:
#line 251 "parser.y"
    { PRINT_RULE }
#line 2113 "parser.cpp"
    break;

  case 64:
#line 256 "parser.y"
    { PRINT_RULE }
#line 2119 "parser.cpp"
    break;

  case 65:
#line 257 "parser.y"
    { PRINT_RULE }
#line 2125 "parser.cpp"
    break;

  case 66:
#line 262 "parser.y"
    { PRINT_RULE }
#line 2131 "parser.cpp"
    break;

  case 67:
#line 263 "parser.y"
    { PRINT_RULE }
#line 2137 "parser.cpp"
    break;

  case 68:
#line 268 "parser.y"
    { PRINT_RULE }
#line 2143 "parser.cpp"
    break;

  case 69:
#line 269 "parser.y"
    { PRINT_RULE }
#line 2149 "parser.cpp"
    break;

  case 70:
#line 270 "parser.y"
    { PRINT_RULE }
#line 2155 "parser.cpp"
    break;

  case 71:
#line 271 "parser.y"
    { PRINT_RULE }
#line 2161 "parser.cpp"
    break;

  case 72:
#line 276 "parser.y"
    { PRINT_RULE }
#line 2167 "parser.cpp"
    break;

  case 73:
#line 277 "parser.y"
    { PRINT_RULE }
#line 2173 "parser.cpp"
    break;

  case 74:
#line 278 "parser.y"
    { PRINT_RULE }
#line 2179 "parser.cpp"
    break;

  case 75:
#line 279 "parser.y"
    { PRINT_RULE }
#line 2185 "parser.cpp"
    break;

  case 76:
#line 280 "parser.y"
    { PRINT_RULE }
#line 2191 "parser.cpp"
    break;

  case 77:
#line 281 "parser.y"
    { PRINT_RULE }
#line 2197 "parser.cpp"
    break;

  case 78:
#line 282 "parser.y"
    { PRINT_RULE }
#line 2203 "parser.cpp"
    break;

  case 79:
#line 283 "parser.y"
    { PRINT_RULE }
#line 2209 "parser.cpp"
    break;

  case 80:
#line 284 "parser.y"
    { PRINT_RULE }
#line 2215 "parser.cpp"
    break;

  case 81:
#line 285 "parser.y"
    { PRINT_RULE }
#line 2221 "parser.cpp"
    break;

  case 82:
#line 286 "parser.y"
    { PRINT_RULE }
#line 2227 "parser.cpp"
    break;

  case 83:
#line 291 "parser.y"
    { PRINT_RULE }
#line 2233 "parser.cpp"
    break;

  case 84:
#line 292 "parser.y"
    { PRINT_RULE }
#line 2239 "parser.cpp"
    break;

  case 85:
#line 293 "parser.y"
    { PRINT_RULE }
#line 2245 "parser.cpp"
    break;

  case 86:
#line 294 "parser.y"
    { PRINT_RULE }
#line 2251 "parser.cpp"
    break;

  case 87:
#line 295 "parser.y"
    { PRINT_RULE }
#line 2257 "parser.cpp"
    break;

  case 88:
#line 296 "parser.y"
    { PRINT_RULE }
#line 2263 "parser.cpp"
    break;

  case 89:
#line 297 "parser.y"
    { PRINT_RULE }
#line 2269 "parser.cpp"
    break;

  case 90:
#line 302 "parser.y"
    { PRINT_RULE }
#line 2275 "parser.cpp"
    break;

  case 91:
#line 307 "parser.y"
    { PRINT_RULE }
#line 2281 "parser.cpp"
    break;

  case 92:
#line 312 "parser.y"
    { PRINT_RULE }
#line 2287 "parser.cpp"
    break;

  case 93:
#line 313 "parser.y"
    { PRINT_RULE }
#line 2293 "parser.cpp"
    break;

  case 97:
#line 317 "parser.y"
    { PRINT_RULE }
#line 2299 "parser.cpp"
    break;

  case 98:
#line 322 "parser.y"
    { PRINT_RULE }
#line 2305 "parser.cpp"
    break;

  case 99:
#line 323 "parser.y"
    { PRINT_RULE }
#line 2311 "parser.cpp"
    break;

  case 100:
#line 324 "parser.y"
    { PRINT_RULE }
#line 2317 "parser.cpp"
    break;

  case 101:
#line 325 "parser.y"
    { PRINT_RULE }
#line 2323 "parser.cpp"
    break;

  case 102:
#line 326 "parser.y"
    { PRINT_RULE }
#line 2329 "parser.cpp"
    break;

  case 103:
#line 327 "parser.y"
    { PRINT_RULE }
#line 2335 "parser.cpp"
    break;

  case 104:
#line 328 "parser.y"
    { PRINT_RULE }
#line 2341 "parser.cpp"
    break;

  case 105:
#line 329 "parser.y"
    { PRINT_RULE }
#line 2347 "parser.cpp"
    break;

  case 106:
#line 334 "parser.y"
    {/*de asemenea nu stiu daca este ok ce fac aicea*/ PRINT_RULE }
#line 2353 "parser.cpp"
    break;

  case 107:
#line 339 "parser.y"
    { PRINT_RULE }
#line 2359 "parser.cpp"
    break;

  case 108:
#line 340 "parser.y"
    { PRINT_RULE }
#line 2365 "parser.cpp"
    break;

  case 109:
#line 345 "parser.y"
    { PRINT_RULE }
#line 2371 "parser.cpp"
    break;

  case 110:
#line 350 "parser.y"
    { PRINT_RULE }
#line 2377 "parser.cpp"
    break;

  case 111:
#line 355 "parser.y"
    { PRINT_RULE }
#line 2383 "parser.cpp"
    break;

  case 112:
#line 360 "parser.y"
    { PRINT_RULE }
#line 2389 "parser.cpp"
    break;

  case 113:
#line 365 "parser.y"
    { PRINT_RULE }
#line 2395 "parser.cpp"
    break;

  case 114:
#line 370 "parser.y"
    { PRINT_RULE }
#line 2401 "parser.cpp"
    break;

  case 115:
#line 371 "parser.y"
    { PRINT_RULE }
#line 2407 "parser.cpp"
    break;

  case 116:
#line 376 "parser.y"
    { PRINT_RULE }
#line 2413 "parser.cpp"
    break;

  case 117:
#line 377 "parser.y"
    { PRINT_RULE }
#line 2419 "parser.cpp"
    break;

  case 118:
#line 378 "parser.y"
    { PRINT_RULE }
#line 2425 "parser.cpp"
    break;

  case 119:
#line 379 "parser.y"
    { PRINT_RULE }
#line 2431 "parser.cpp"
    break;

  case 120:
#line 380 "parser.y"
    { PRINT_RULE }
#line 2437 "parser.cpp"
    break;

  case 121:
#line 381 "parser.y"
    { PRINT_RULE }
#line 2443 "parser.cpp"
    break;

  case 122:
#line 386 "parser.y"
    { PRINT_RULE }
#line 2449 "parser.cpp"
    break;

  case 123:
#line 391 "parser.y"
    { PRINT_RULE }
#line 2455 "parser.cpp"
    break;

  case 124:
#line 392 "parser.y"
    { PRINT_RULE }
#line 2461 "parser.cpp"
    break;

  case 125:
#line 395 "parser.y"
    { PRINT_RULE }
#line 2467 "parser.cpp"
    break;

  case 126:
#line 396 "parser.y"
    { PRINT_RULE }
#line 2473 "parser.cpp"
    break;

  case 127:
#line 397 "parser.y"
    { PRINT_RULE }
#line 2479 "parser.cpp"
    break;

  case 128:
#line 398 "parser.y"
    { PRINT_RULE }
#line 2485 "parser.cpp"
    break;

  case 129:
#line 399 "parser.y"
    { PRINT_RULE }
#line 2491 "parser.cpp"
    break;

  case 130:
#line 400 "parser.y"
    { PRINT_RULE }
#line 2497 "parser.cpp"
    break;

  case 131:
#line 403 "parser.y"
    { PRINT_RULE }
#line 2503 "parser.cpp"
    break;

  case 132:
#line 404 "parser.y"
    { PRINT_RULE }
#line 2509 "parser.cpp"
    break;

  case 133:
#line 405 "parser.y"
    { PRINT_RULE }
#line 2515 "parser.cpp"
    break;

  case 134:
#line 406 "parser.y"
    { PRINT_RULE }
#line 2521 "parser.cpp"
    break;

  case 135:
#line 407 "parser.y"
    { PRINT_RULE }
#line 2527 "parser.cpp"
    break;

  case 136:
#line 408 "parser.y"
    { PRINT_RULE }
#line 2533 "parser.cpp"
    break;

  case 137:
#line 409 "parser.y"
    { PRINT_RULE }
#line 2539 "parser.cpp"
    break;

  case 138:
#line 410 "parser.y"
    { PRINT_RULE }
#line 2545 "parser.cpp"
    break;

  case 139:
#line 411 "parser.y"
    { PRINT_RULE }
#line 2551 "parser.cpp"
    break;

  case 140:
#line 412 "parser.y"
    { PRINT_RULE }
#line 2557 "parser.cpp"
    break;

  case 141:
#line 413 "parser.y"
    { PRINT_RULE }
#line 2563 "parser.cpp"
    break;

  case 142:
#line 414 "parser.y"
    { PRINT_RULE }
#line 2569 "parser.cpp"
    break;

  case 143:
#line 415 "parser.y"
    { PRINT_RULE }
#line 2575 "parser.cpp"
    break;

  case 144:
#line 416 "parser.y"
    { PRINT_RULE }
#line 2581 "parser.cpp"
    break;

  case 145:
#line 417 "parser.y"
    { PRINT_RULE }
#line 2587 "parser.cpp"
    break;

  case 146:
#line 420 "parser.y"
    { PRINT_RULE }
#line 2593 "parser.cpp"
    break;

  case 147:
#line 421 "parser.y"
    { PRINT_RULE }
#line 2599 "parser.cpp"
    break;

  case 148:
#line 422 "parser.y"
    { PRINT_RULE }
#line 2605 "parser.cpp"
    break;

  case 149:
#line 423 "parser.y"
    { PRINT_RULE }
#line 2611 "parser.cpp"
    break;

  case 150:
#line 428 "parser.y"
    { PRINT_RULE }
#line 2617 "parser.cpp"
    break;

  case 151:
#line 433 "parser.y"
    { PRINT_RULE }
#line 2623 "parser.cpp"
    break;

  case 152:
#line 434 "parser.y"
    { PRINT_RULE }
#line 2629 "parser.cpp"
    break;

  case 153:
#line 435 "parser.y"
    { PRINT_RULE }
#line 2635 "parser.cpp"
    break;

  case 154:
#line 436 "parser.y"
    { PRINT_RULE }
#line 2641 "parser.cpp"
    break;

  case 155:
#line 437 "parser.y"
    { PRINT_RULE }
#line 2647 "parser.cpp"
    break;

  case 156:
#line 438 "parser.y"
    { PRINT_RULE }
#line 2653 "parser.cpp"
    break;

  case 157:
#line 439 "parser.y"
    { PRINT_RULE }
#line 2659 "parser.cpp"
    break;

  case 158:
#line 440 "parser.y"
    { PRINT_RULE }
#line 2665 "parser.cpp"
    break;

  case 159:
#line 441 "parser.y"
    { PRINT_RULE }
#line 2671 "parser.cpp"
    break;

  case 160:
#line 442 "parser.y"
    { PRINT_RULE }
#line 2677 "parser.cpp"
    break;

  case 161:
#line 443 "parser.y"
    { PRINT_RULE }
#line 2683 "parser.cpp"
    break;

  case 162:
#line 444 "parser.y"
    { PRINT_RULE }
#line 2689 "parser.cpp"
    break;

  case 163:
#line 449 "parser.y"
    { PRINT_RULE }
#line 2695 "parser.cpp"
    break;


#line 2699 "parser.cpp"

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
#line 452 "parser.y"


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
