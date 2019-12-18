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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "parser.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

#include "SpelParserExternals.h"

//Debug variables
extern bool enable_grammar_debug;
extern std::stringstream last_calls_stream;
extern std::stringstream parents_stream;

extern int yylex();
extern void yyerror(const char*);

#define YYSTYPE char*

//Define for avoiding duplicated token enum
#define YYTOKENTYPE
void print_rule(int num, char* s);
#define PRINT_RULE print_rule(__LINE__, yylval);

#line 98 "parser.cpp"

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
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

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
    IFX = 296,
    UMINUS = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
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


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */



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
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   432

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  299

#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
       2,     2,     2,     2,     2,     2,     2,    48,     2,     2,
      55,    56,    46,    44,    51,    45,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,    50,
      42,    52,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    43,    43,    44,    47,    48,    49,    50,    51,    52,
      55,    60,    61,    62,    63,    68,    69,    74,    75,    76,
      77,    78,    79,    84,    85,    90,    91,    92,    93,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   116,   117,   122,   127,   128,   133,   134,
     139,   140,   141,   142,   147,   148,   153,   154,   159,   164,
     165,   170,   175,   176,   181,   182,   187,   188,   193,   194,
     195,   196,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   216,   217,   218,   219,   220,   221,   226,
     231,   236,   237,   238,   243,   244,   249,   254,   255,   260,
     265,   270,   275,   280,   285,   286,   291,   292,   293,   294,
     295,   296,   301,   306,   307,   310,   311,   312,   313,   314,
     315,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   340,   341,   342,   343,   348,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   366
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
  "ENDELSE", "ENDIF", "ENDFOR", "VOID", "IN", "EVAL", "IFX", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "';'", "','", "'='", "'['",
  "']'", "'('", "')'", "':'", "$accept", "sp", "s", "class_def",
  "class_body", "class_var", "type", "class_ids", "class_id",
  "class_id_initialization", "vector_size", "vector_initialization",
  "vector_body", "call_parameters", "vector_position", "const_class_ids",
  "const_class_id", "const_vector_size", "f_parameters", "f_parameter",
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
     295,   296,    60,    62,    43,    45,    42,    47,    37,   297,
      59,    44,    61,    91,    93,    40,    41,    58
};
# endif

#define YYPACT_NINF -207

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-207)))

#define YYTABLE_NINF -107

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     253,  -207,  -207,  -207,  -207,   -38,   136,   335,  -207,   -26,
      -8,    11,    35,    74,  -207,   253,  -207,    73,  -207,  -207,
    -207,  -207,   253,   253,  -207,   223,   232,  -207,    89,    91,
      96,   109,   179,   128,   105,   179,     7,  -207,  -207,     4,
      98,   115,  -207,  -207,  -207,     2,  -207,  -207,  -207,  -207,
    -207,   223,   223,   122,   121,   108,   -23,    -2,   151,   320,
     327,   334,   341,  -207,   119,  -207,   132,  -207,   314,   129,
     130,    65,   138,   135,   223,  -207,    38,   133,  -207,   161,
    -207,   150,  -207,   165,   166,   178,   232,   217,  -207,    73,
     226,   107,  -207,  -207,   134,  -207,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   239,   107,
     232,   203,   232,   216,   237,   314,   314,   326,   326,   232,
     245,  -207,   109,  -207,   179,   179,   228,    83,   287,   215,
     219,  -207,  -207,  -207,   213,  -207,   218,   -17,  -207,   220,
    -207,   108,   368,   368,   368,   368,   368,   368,    31,    31,
    -207,  -207,  -207,   304,   227,   214,  -207,  -207,  -207,  -207,
    -207,   335,   259,   229,  -207,   240,   243,  -207,  -207,   241,
    -207,  -207,  -207,   287,   273,  -207,    30,  -207,  -207,   246,
     247,    -9,   287,   287,  -207,   280,  -207,  -207,  -207,  -207,
    -207,   263,   107,   107,   232,   303,   107,     8,  -207,   315,
     267,   287,   326,   279,   274,   295,   298,   107,   232,   287,
     145,   223,   107,   232,  -207,  -207,  -207,   285,   289,   293,
     294,   336,   297,   343,   306,   311,   340,  -207,   232,   317,
     279,   347,   279,   285,  -207,   287,  -207,   319,   323,  -207,
    -207,    12,  -207,   325,   328,   324,   232,  -207,  -207,  -207,
    -207,   333,   348,   313,   339,  -207,  -207,   337,   344,    26,
    -207,  -207,  -207,  -207,   354,  -207,  -207,  -207,   349,   346,
     352,   353,   107,   107,  -207,   279,   279,   361,   362,   350,
    -207,   223,  -207,   232,  -207,   356,   365,  -207,  -207,   358,
     370,  -207,   371,  -207,  -207,   355,  -207,  -207,  -207
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    18,    19,    20,    21,    17,     0,     0,    22,     0,
       0,     0,     0,     0,     2,     7,   155,     0,   145,   148,
     147,   149,     8,     9,   146,     0,    48,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     4,    25,
       0,    23,     5,     6,   131,   115,   129,   130,   132,   133,
     134,     0,     0,     0,   128,   113,   131,   115,   129,   130,
     132,   133,   134,    61,     0,    49,    59,    42,     0,     0,
       0,     0,     0,    54,     0,    99,    91,     0,    95,     0,
     102,     0,    90,     0,     0,     0,     0,    43,    15,     0,
       0,     0,   128,   127,     0,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,     0,     0,    11,    12,    64,    64,     0,
       0,    16,     0,    94,     0,     0,     0,     0,     0,     0,
       0,   152,    26,    44,     0,    24,   117,    50,    51,     0,
     121,   114,   140,   139,   138,   137,   136,   135,   122,   123,
     124,   125,   126,   117,     0,     0,   151,    60,    10,    13,
      14,     0,     0,     0,    65,    66,     0,    56,    58,     0,
      55,    92,    93,     0,    97,   109,   104,   107,   108,     0,
       0,    17,   143,   144,    86,     0,    87,    88,    96,   154,
     153,    27,     0,     0,    48,   116,     0,   116,    36,     0,
      68,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,     0,     0,    48,   141,   142,    89,     0,     0,     0,
       0,     0,     0,     0,    70,     0,     0,    67,     0,     0,
      76,     0,    79,     0,   100,     0,    98,     0,     0,   103,
     112,   106,   105,     0,     0,     0,     0,    28,   119,    53,
      52,   118,   119,   118,     0,    69,    63,     0,     0,     0,
      72,    62,    75,    57,     0,   111,   110,    83,     0,     0,
      46,     0,     0,     0,    71,    77,    78,     0,     0,     0,
     101,     0,    85,     0,    45,     0,     0,    73,    74,     0,
       0,    80,     0,    47,   120,   120,    82,    81,    84
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -207,  -207,    19,  -207,    55,     0,     6,   338,  -207,   -84,
    -207,   189,   140,  -103,  -104,   302,  -207,  -207,   316,  -207,
     -43,   308,   230,  -207,  -206,  -200,    84,  -207,   -31,  -207,
    -207,   233,  -207,  -207,  -207,   307,  -207,  -207,   221,  -207,
     -24,    29,   113,  -164,  -207,  -207,  -207
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,   114,   182,    17,    40,    41,    63,
     134,   247,   271,    64,   139,    72,    73,   169,    65,    66,
      18,   163,   164,   165,   231,   183,   184,    81,    75,    76,
     185,   186,    77,   174,   236,   187,    34,   179,   180,   239,
      67,    54,    55,   188,    22,    23,    24
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      16,    53,   132,   232,    82,   154,   108,   155,    78,   205,
      90,    78,    30,    31,    25,    16,   223,    26,   214,   215,
      83,    84,    16,    16,   260,   116,   262,   -32,   -32,    32,
     232,   -32,   232,   -32,    38,   167,   193,   226,   194,   277,
     278,    42,    43,   211,   212,   240,   213,    33,   -29,   -29,
     123,   109,   -29,   110,   -29,    91,    86,    87,   -37,   -37,
     124,   125,   -37,    85,   -37,   207,    35,   208,   115,   287,
     288,   264,   116,   116,    37,   232,   232,   105,   106,   107,
      92,    92,   279,   207,    19,   208,    39,  -106,   218,   219,
      36,   220,   222,   171,   172,   175,   176,   177,   178,    19,
      78,    78,    68,   237,    69,   238,    19,    19,   244,    70,
     245,    97,    98,    99,   100,   115,   115,   119,   120,    30,
     137,   138,    71,   162,   162,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    97,    98,    99,
     100,    79,    80,     1,   257,     2,     3,     4,    88,    27,
     101,   102,   103,   104,   105,   106,   107,   175,   241,   177,
     178,    28,   270,     8,    93,    94,    89,   199,   285,   286,
     159,   160,    95,    96,    29,   111,   101,   102,   103,   104,
     105,   106,   107,   112,   117,   118,   122,   243,   121,   126,
     140,    44,    45,    46,    47,    74,    48,    49,    50,   270,
     127,   -30,   -30,   230,   258,   -30,   128,   -30,   162,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   129,   130,     1,    51,     2,     3,     4,   131,    27,
     230,   133,   230,    20,    52,    44,    45,    46,    47,   136,
      48,    49,    50,     8,    56,    57,    58,    59,    20,    60,
      61,    62,   153,   156,    29,    20,    20,   292,   158,   168,
       1,   173,     2,     3,     4,   189,     5,   191,    51,   190,
     198,   192,   200,     6,   195,   230,   230,    51,    52,     7,
       8,   197,     9,    10,    11,   201,     1,    52,     2,     3,
       4,   202,   181,    12,     1,   204,     2,     3,     4,   203,
     181,   206,   209,   228,   210,     7,     8,    21,     9,    10,
      11,   221,   216,     7,     8,   217,     9,    10,    11,   229,
     225,     1,    21,     2,     3,     4,   233,    27,   224,    21,
      21,   234,   235,     1,   113,     2,     3,     4,   246,    27,
       7,     8,     1,   248,     2,     3,     4,   249,    27,   251,
     250,   252,   161,     8,   -38,   -38,   253,   196,   -38,   254,
     -38,   256,     8,   -39,   -39,   255,   273,   -39,   261,   -39,
     -31,   -31,   259,   265,   -31,   267,   -31,   -33,   -33,   266,
     269,   -33,   268,   -33,   -34,   -34,   272,   275,   -34,   280,
     -34,   -35,   -35,   274,   276,   -35,   282,   -35,   -40,   -40,
     291,   281,   -40,   283,   -40,   -41,   -41,   284,   296,   -41,
     294,   -41,   103,   104,   105,   106,   107,   289,   290,   295,
     297,   298,   263,   293,   170,     0,   166,   135,   157,     0,
       0,   242,   227
};

static const yytype_int16 yycheck[] =
{
       0,    25,    86,   203,    35,   109,     8,   110,    32,   173,
       8,    35,     6,     7,    52,    15,     8,    55,   182,   183,
      13,    14,    22,    23,   230,    68,   232,    50,    51,    55,
     230,    54,   232,    56,    15,   119,    53,   201,    55,    13,
      14,    22,    23,    52,    53,   209,    55,    55,    50,    51,
      74,    53,    54,    55,    56,    53,    52,    53,    50,    51,
      22,    23,    54,    56,    56,    53,    55,    55,    68,   275,
     276,   235,   115,   116,     0,   275,   276,    46,    47,    48,
      51,    52,    56,    53,     0,    55,    13,    57,   192,   193,
      55,   194,   196,   124,   125,    12,    13,    14,    15,    15,
     124,   125,    13,   207,    13,   208,    22,    23,   212,    13,
     213,     3,     4,     5,     6,   115,   116,    52,    53,   113,
      13,    14,    13,   117,   118,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,     3,     4,     5,
       6,    13,    37,     7,   228,     9,    10,    11,    50,    13,
      42,    43,    44,    45,    46,    47,    48,    12,    13,    14,
      15,    25,   246,    27,    51,    52,    51,   161,   272,   273,
     115,   116,    50,    52,    38,    56,    42,    43,    44,    45,
      46,    47,    48,    51,    55,    55,    51,   211,    50,    56,
      56,    12,    13,    14,    15,    16,    17,    18,    19,   283,
      39,    50,    51,   203,   228,    54,    56,    56,   202,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    56,    56,     7,    45,     9,    10,    11,    50,    13,
     230,    14,   232,     0,    55,    12,    13,    14,    15,    13,
      17,    18,    19,    27,    12,    13,    14,    15,    15,    17,
      18,    19,    13,    50,    38,    22,    23,   281,    21,    14,
       7,    33,     9,    10,    11,    50,    13,    54,    45,    50,
      56,    53,    13,    20,    54,   275,   276,    45,    55,    26,
      27,    54,    29,    30,    31,    56,     7,    55,     9,    10,
      11,    51,    13,    40,     7,    54,     9,    10,    11,    56,
      13,    28,    56,    24,    57,    26,    27,     0,    29,    30,
      31,     8,    32,    26,    27,    52,    29,    30,    31,    40,
      53,     7,    15,     9,    10,    11,    52,    13,    13,    22,
      23,    36,    34,     7,    20,     9,    10,    11,    53,    13,
      26,    27,     7,    54,     9,    10,    11,    54,    13,    13,
      56,    54,    26,    27,    50,    51,    13,    53,    54,    53,
      56,    21,    27,    50,    51,    54,    53,    54,    21,    56,
      50,    51,    55,    54,    54,    50,    56,    50,    51,    56,
      56,    54,    54,    56,    50,    51,    53,    50,    54,    35,
      56,    50,    51,    54,    50,    54,    50,    56,    50,    51,
      50,    52,    54,    51,    56,    50,    51,    54,    50,    54,
      54,    56,    44,    45,    46,    47,    48,    56,    56,    54,
      50,    50,   233,   283,   122,    -1,   118,    89,   112,    -1,
      -1,   210,   202
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     9,    10,    11,    13,    20,    26,    27,    29,
      30,    31,    40,    59,    60,    61,    63,    64,    78,    84,
      89,    93,   102,   103,   104,    52,    55,    13,    25,    38,
      64,    64,    55,    55,    94,    55,    55,     0,    60,    13,
      65,    66,    60,    60,    12,    13,    14,    15,    17,    18,
      19,    45,    55,    98,    99,   100,    12,    13,    14,    15,
      17,    18,    19,    67,    71,    76,    77,    98,    13,    13,
      13,    13,    73,    74,    16,    86,    87,    90,    98,    13,
      37,    85,    86,    13,    14,    56,    52,    53,    50,    51,
       8,    53,    99,   100,   100,    50,    52,     3,     4,     5,
       6,    42,    43,    44,    45,    46,    47,    48,     8,    53,
      55,    56,    51,    20,    62,    63,    78,    55,    55,    52,
      53,    50,    51,    98,    22,    23,    56,    39,    56,    56,
      56,    50,    67,    14,    68,    65,    13,    13,    14,    72,
      56,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,    13,    72,    71,    50,    76,    21,    62,
      62,    26,    64,    79,    80,    81,    79,    67,    14,    75,
      73,    86,    86,    33,    91,    12,    13,    14,    15,    95,
      96,    13,    63,    83,    84,    88,    89,    93,   101,    50,
      50,    54,    53,    53,    55,    54,    53,    54,    56,    64,
      13,    56,    51,    56,    54,   101,    28,    53,    55,    56,
      57,    52,    53,    55,   101,   101,    32,    52,    72,    72,
      71,     8,    72,     8,    13,    53,   101,    80,    24,    40,
      63,    82,    83,    52,    36,    34,    92,    72,    71,    97,
     101,    13,    96,    98,    72,    71,    53,    69,    54,    54,
      56,    13,    54,    13,    53,    54,    21,    67,    98,    55,
      82,    21,    82,    69,   101,    54,    56,    50,    54,    56,
      67,    70,    53,    53,    54,    50,    50,    13,    14,    56,
      35,    52,    50,    51,    54,    72,    72,    82,    82,    56,
      56,    50,    98,    70,    54,    54,    50,    50,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    60,    60,    60,    60,
      61,    62,    62,    62,    62,    63,    63,    64,    64,    64,
      64,    64,    64,    65,    65,    66,    66,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    68,    68,    69,    70,    70,    71,    71,
      72,    72,    72,    72,    73,    73,    74,    74,    75,    76,
      76,    77,    78,    78,    79,    79,    80,    80,    81,    81,
      81,    81,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    83,    83,    83,    83,    84,
      85,    86,    86,    86,    87,    87,    88,    89,    89,    90,
      91,    92,    93,    94,    95,    95,    96,    96,    96,    96,
      96,    96,    97,    98,    98,    99,    99,    99,    99,    99,
      99,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   101,   101,   101,   101,   102,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     2,     1,     1,     1,
       5,     1,     1,     2,     2,     3,     4,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     4,     6,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     3,     6,
       6,     9,     1,     0,     1,     3,     1,     3,     0,     1,
       1,     1,     4,     4,     1,     3,     3,     6,     1,     1,
       3,     1,     8,     8,     0,     1,     1,     3,     2,     4,
       3,     5,     2,     4,     4,     2,     1,     3,     3,     1,
       4,     5,     5,     4,     7,     5,     1,     1,     1,     6,
       1,     1,     3,     3,     2,     1,     1,     5,     7,     1,
       3,     3,     3,     6,     1,     3,     1,     1,     1,     1,
       4,     4,     1,     1,     3,     1,     4,     3,     6,     6,
       9,     3,     3,     3,     3,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     4,     5,     5,     1
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
        yyerror (YY_("syntax error: cannot back up")); \
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
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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
      yychar = yylex ();
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
#line 43 "parser.y"
    { printf("Reached start symbol.\n"); }
#line 1622 "parser.cpp"
    break;

  case 3:
#line 44 "parser.y"
    { printf("Reached start symbol.\n"); }
#line 1628 "parser.cpp"
    break;

  case 4:
#line 47 "parser.y"
    { PRINT_RULE }
#line 1634 "parser.cpp"
    break;

  case 5:
#line 48 "parser.y"
    { PRINT_RULE }
#line 1640 "parser.cpp"
    break;

  case 6:
#line 49 "parser.y"
    { PRINT_RULE }
#line 1646 "parser.cpp"
    break;

  case 7:
#line 50 "parser.y"
    { PRINT_RULE }
#line 1652 "parser.cpp"
    break;

  case 8:
#line 51 "parser.y"
    { PRINT_RULE }
#line 1658 "parser.cpp"
    break;

  case 9:
#line 52 "parser.y"
    { PRINT_RULE }
#line 1664 "parser.cpp"
    break;

  case 10:
#line 55 "parser.y"
    { PRINT_RULE }
#line 1670 "parser.cpp"
    break;

  case 11:
#line 60 "parser.y"
    { PRINT_RULE }
#line 1676 "parser.cpp"
    break;

  case 12:
#line 61 "parser.y"
    { PRINT_RULE }
#line 1682 "parser.cpp"
    break;

  case 13:
#line 62 "parser.y"
    { PRINT_RULE }
#line 1688 "parser.cpp"
    break;

  case 14:
#line 63 "parser.y"
    { PRINT_RULE }
#line 1694 "parser.cpp"
    break;

  case 15:
#line 68 "parser.y"
    { PRINT_RULE }
#line 1700 "parser.cpp"
    break;

  case 16:
#line 69 "parser.y"
    { PRINT_RULE }
#line 1706 "parser.cpp"
    break;

  case 17:
#line 74 "parser.y"
    { PRINT_RULE }
#line 1712 "parser.cpp"
    break;

  case 18:
#line 75 "parser.y"
    { PRINT_RULE }
#line 1718 "parser.cpp"
    break;

  case 19:
#line 76 "parser.y"
    { PRINT_RULE }
#line 1724 "parser.cpp"
    break;

  case 20:
#line 77 "parser.y"
    { PRINT_RULE }
#line 1730 "parser.cpp"
    break;

  case 21:
#line 78 "parser.y"
    { PRINT_RULE }
#line 1736 "parser.cpp"
    break;

  case 22:
#line 79 "parser.y"
    { PRINT_RULE }
#line 1742 "parser.cpp"
    break;

  case 23:
#line 84 "parser.y"
    { PRINT_RULE }
#line 1748 "parser.cpp"
    break;

  case 24:
#line 85 "parser.y"
    { PRINT_RULE }
#line 1754 "parser.cpp"
    break;

  case 25:
#line 90 "parser.y"
    { PRINT_RULE }
#line 1760 "parser.cpp"
    break;

  case 26:
#line 91 "parser.y"
    { PRINT_RULE }
#line 1766 "parser.cpp"
    break;

  case 27:
#line 92 "parser.y"
    { PRINT_RULE }
#line 1772 "parser.cpp"
    break;

  case 28:
#line 93 "parser.y"
    { PRINT_RULE }
#line 1778 "parser.cpp"
    break;

  case 29:
#line 98 "parser.y"
    { PRINT_RULE }
#line 1784 "parser.cpp"
    break;

  case 30:
#line 99 "parser.y"
    { PRINT_RULE }
#line 1790 "parser.cpp"
    break;

  case 31:
#line 100 "parser.y"
    { PRINT_RULE }
#line 1796 "parser.cpp"
    break;

  case 32:
#line 101 "parser.y"
    { PRINT_RULE }
#line 1802 "parser.cpp"
    break;

  case 33:
#line 102 "parser.y"
    { PRINT_RULE }
#line 1808 "parser.cpp"
    break;

  case 34:
#line 103 "parser.y"
    { PRINT_RULE }
#line 1814 "parser.cpp"
    break;

  case 35:
#line 104 "parser.y"
    { PRINT_RULE }
#line 1820 "parser.cpp"
    break;

  case 36:
#line 105 "parser.y"
    { PRINT_RULE }
#line 1826 "parser.cpp"
    break;

  case 37:
#line 106 "parser.y"
    { PRINT_RULE }
#line 1832 "parser.cpp"
    break;

  case 38:
#line 107 "parser.y"
    { PRINT_RULE }
#line 1838 "parser.cpp"
    break;

  case 39:
#line 108 "parser.y"
    { PRINT_RULE }
#line 1844 "parser.cpp"
    break;

  case 40:
#line 109 "parser.y"
    { PRINT_RULE }
#line 1850 "parser.cpp"
    break;

  case 41:
#line 110 "parser.y"
    { PRINT_RULE }
#line 1856 "parser.cpp"
    break;

  case 42:
#line 111 "parser.y"
    { PRINT_RULE }
#line 1862 "parser.cpp"
    break;

  case 43:
#line 116 "parser.y"
    { PRINT_RULE /*s-ar putea sa ne vina mai usor daca facem vector size nul direct din regula fara eps pentru ca sa identificam noi nr de param*/}
#line 1868 "parser.cpp"
    break;

  case 44:
#line 117 "parser.y"
    { PRINT_RULE }
#line 1874 "parser.cpp"
    break;

  case 45:
#line 122 "parser.y"
    { PRINT_RULE }
#line 1880 "parser.cpp"
    break;

  case 46:
#line 127 "parser.y"
    { PRINT_RULE }
#line 1886 "parser.cpp"
    break;

  case 47:
#line 128 "parser.y"
    { PRINT_RULE }
#line 1892 "parser.cpp"
    break;

  case 48:
#line 133 "parser.y"
    { PRINT_RULE }
#line 1898 "parser.cpp"
    break;

  case 49:
#line 134 "parser.y"
    { PRINT_RULE }
#line 1904 "parser.cpp"
    break;

  case 50:
#line 139 "parser.y"
    { PRINT_RULE }
#line 1910 "parser.cpp"
    break;

  case 51:
#line 140 "parser.y"
    { PRINT_RULE }
#line 1916 "parser.cpp"
    break;

  case 52:
#line 141 "parser.y"
    { PRINT_RULE }
#line 1922 "parser.cpp"
    break;

  case 53:
#line 142 "parser.y"
    { PRINT_RULE }
#line 1928 "parser.cpp"
    break;

  case 54:
#line 147 "parser.y"
    { PRINT_RULE }
#line 1934 "parser.cpp"
    break;

  case 55:
#line 148 "parser.y"
    { PRINT_RULE }
#line 1940 "parser.cpp"
    break;

  case 56:
#line 153 "parser.y"
    { PRINT_RULE }
#line 1946 "parser.cpp"
    break;

  case 57:
#line 154 "parser.y"
    { PRINT_RULE }
#line 1952 "parser.cpp"
    break;

  case 58:
#line 159 "parser.y"
    { PRINT_RULE }
#line 1958 "parser.cpp"
    break;

  case 59:
#line 164 "parser.y"
    { PRINT_RULE }
#line 1964 "parser.cpp"
    break;

  case 60:
#line 165 "parser.y"
    { PRINT_RULE }
#line 1970 "parser.cpp"
    break;

  case 61:
#line 170 "parser.y"
    {/*nu stiu daca aici este corect, dar eu presupun ca da*/ PRINT_RULE }
#line 1976 "parser.cpp"
    break;

  case 62:
#line 175 "parser.y"
    { PRINT_RULE }
#line 1982 "parser.cpp"
    break;

  case 63:
#line 176 "parser.y"
    { PRINT_RULE }
#line 1988 "parser.cpp"
    break;

  case 64:
#line 181 "parser.y"
    { PRINT_RULE }
#line 1994 "parser.cpp"
    break;

  case 65:
#line 182 "parser.y"
    { PRINT_RULE }
#line 2000 "parser.cpp"
    break;

  case 66:
#line 187 "parser.y"
    { PRINT_RULE }
#line 2006 "parser.cpp"
    break;

  case 67:
#line 188 "parser.y"
    { PRINT_RULE }
#line 2012 "parser.cpp"
    break;

  case 68:
#line 193 "parser.y"
    { PRINT_RULE }
#line 2018 "parser.cpp"
    break;

  case 69:
#line 194 "parser.y"
    { PRINT_RULE }
#line 2024 "parser.cpp"
    break;

  case 70:
#line 195 "parser.y"
    { PRINT_RULE }
#line 2030 "parser.cpp"
    break;

  case 71:
#line 196 "parser.y"
    { PRINT_RULE }
#line 2036 "parser.cpp"
    break;

  case 72:
#line 201 "parser.y"
    { PRINT_RULE }
#line 2042 "parser.cpp"
    break;

  case 73:
#line 202 "parser.y"
    { PRINT_RULE }
#line 2048 "parser.cpp"
    break;

  case 74:
#line 203 "parser.y"
    { PRINT_RULE }
#line 2054 "parser.cpp"
    break;

  case 75:
#line 204 "parser.y"
    { PRINT_RULE }
#line 2060 "parser.cpp"
    break;

  case 76:
#line 205 "parser.y"
    { PRINT_RULE }
#line 2066 "parser.cpp"
    break;

  case 77:
#line 206 "parser.y"
    { PRINT_RULE }
#line 2072 "parser.cpp"
    break;

  case 78:
#line 207 "parser.y"
    { PRINT_RULE }
#line 2078 "parser.cpp"
    break;

  case 79:
#line 208 "parser.y"
    { PRINT_RULE }
#line 2084 "parser.cpp"
    break;

  case 80:
#line 209 "parser.y"
    { PRINT_RULE }
#line 2090 "parser.cpp"
    break;

  case 81:
#line 210 "parser.y"
    { PRINT_RULE }
#line 2096 "parser.cpp"
    break;

  case 82:
#line 211 "parser.y"
    { PRINT_RULE }
#line 2102 "parser.cpp"
    break;

  case 83:
#line 216 "parser.y"
    { PRINT_RULE }
#line 2108 "parser.cpp"
    break;

  case 84:
#line 217 "parser.y"
    { PRINT_RULE }
#line 2114 "parser.cpp"
    break;

  case 85:
#line 218 "parser.y"
    { PRINT_RULE }
#line 2120 "parser.cpp"
    break;

  case 86:
#line 219 "parser.y"
    { PRINT_RULE }
#line 2126 "parser.cpp"
    break;

  case 87:
#line 220 "parser.y"
    { PRINT_RULE }
#line 2132 "parser.cpp"
    break;

  case 88:
#line 221 "parser.y"
    { PRINT_RULE }
#line 2138 "parser.cpp"
    break;

  case 89:
#line 226 "parser.y"
    { PRINT_RULE }
#line 2144 "parser.cpp"
    break;

  case 90:
#line 231 "parser.y"
    { PRINT_RULE }
#line 2150 "parser.cpp"
    break;

  case 91:
#line 236 "parser.y"
    { PRINT_RULE }
#line 2156 "parser.cpp"
    break;

  case 92:
#line 237 "parser.y"
    { PRINT_RULE }
#line 2162 "parser.cpp"
    break;

  case 93:
#line 238 "parser.y"
    { PRINT_RULE }
#line 2168 "parser.cpp"
    break;

  case 94:
#line 243 "parser.y"
    { PRINT_RULE }
#line 2174 "parser.cpp"
    break;

  case 95:
#line 244 "parser.y"
    { PRINT_RULE }
#line 2180 "parser.cpp"
    break;

  case 96:
#line 249 "parser.y"
    {/*de asemenea nu stiu daca este ok ce fac aicea*/ PRINT_RULE }
#line 2186 "parser.cpp"
    break;

  case 97:
#line 254 "parser.y"
    { PRINT_RULE }
#line 2192 "parser.cpp"
    break;

  case 98:
#line 255 "parser.y"
    { PRINT_RULE }
#line 2198 "parser.cpp"
    break;

  case 99:
#line 260 "parser.y"
    { PRINT_RULE }
#line 2204 "parser.cpp"
    break;

  case 100:
#line 265 "parser.y"
    { PRINT_RULE }
#line 2210 "parser.cpp"
    break;

  case 101:
#line 270 "parser.y"
    { PRINT_RULE }
#line 2216 "parser.cpp"
    break;

  case 102:
#line 275 "parser.y"
    { PRINT_RULE }
#line 2222 "parser.cpp"
    break;

  case 103:
#line 280 "parser.y"
    { PRINT_RULE }
#line 2228 "parser.cpp"
    break;

  case 104:
#line 285 "parser.y"
    { PRINT_RULE }
#line 2234 "parser.cpp"
    break;

  case 105:
#line 286 "parser.y"
    { PRINT_RULE }
#line 2240 "parser.cpp"
    break;

  case 106:
#line 291 "parser.y"
    { PRINT_RULE }
#line 2246 "parser.cpp"
    break;

  case 107:
#line 292 "parser.y"
    { PRINT_RULE }
#line 2252 "parser.cpp"
    break;

  case 108:
#line 293 "parser.y"
    { PRINT_RULE }
#line 2258 "parser.cpp"
    break;

  case 109:
#line 294 "parser.y"
    { PRINT_RULE }
#line 2264 "parser.cpp"
    break;

  case 110:
#line 295 "parser.y"
    { PRINT_RULE }
#line 2270 "parser.cpp"
    break;

  case 111:
#line 296 "parser.y"
    { PRINT_RULE }
#line 2276 "parser.cpp"
    break;

  case 112:
#line 301 "parser.y"
    { PRINT_RULE }
#line 2282 "parser.cpp"
    break;

  case 113:
#line 306 "parser.y"
    { PRINT_RULE }
#line 2288 "parser.cpp"
    break;

  case 114:
#line 307 "parser.y"
    { PRINT_RULE }
#line 2294 "parser.cpp"
    break;

  case 115:
#line 310 "parser.y"
    { PRINT_RULE }
#line 2300 "parser.cpp"
    break;

  case 116:
#line 311 "parser.y"
    { PRINT_RULE }
#line 2306 "parser.cpp"
    break;

  case 117:
#line 312 "parser.y"
    { PRINT_RULE }
#line 2312 "parser.cpp"
    break;

  case 118:
#line 313 "parser.y"
    { PRINT_RULE }
#line 2318 "parser.cpp"
    break;

  case 119:
#line 314 "parser.y"
    { PRINT_RULE }
#line 2324 "parser.cpp"
    break;

  case 120:
#line 315 "parser.y"
    { PRINT_RULE }
#line 2330 "parser.cpp"
    break;

  case 121:
#line 318 "parser.y"
    { PRINT_RULE }
#line 2336 "parser.cpp"
    break;

  case 122:
#line 319 "parser.y"
    { PRINT_RULE }
#line 2342 "parser.cpp"
    break;

  case 123:
#line 320 "parser.y"
    { PRINT_RULE }
#line 2348 "parser.cpp"
    break;

  case 124:
#line 321 "parser.y"
    { PRINT_RULE }
#line 2354 "parser.cpp"
    break;

  case 125:
#line 322 "parser.y"
    { PRINT_RULE }
#line 2360 "parser.cpp"
    break;

  case 126:
#line 323 "parser.y"
    { PRINT_RULE }
#line 2366 "parser.cpp"
    break;

  case 127:
#line 324 "parser.y"
    { PRINT_RULE }
#line 2372 "parser.cpp"
    break;

  case 128:
#line 325 "parser.y"
    { PRINT_RULE }
#line 2378 "parser.cpp"
    break;

  case 129:
#line 326 "parser.y"
    { PRINT_RULE }
#line 2384 "parser.cpp"
    break;

  case 130:
#line 327 "parser.y"
    { PRINT_RULE }
#line 2390 "parser.cpp"
    break;

  case 131:
#line 328 "parser.y"
    { PRINT_RULE }
#line 2396 "parser.cpp"
    break;

  case 132:
#line 329 "parser.y"
    { PRINT_RULE }
#line 2402 "parser.cpp"
    break;

  case 133:
#line 330 "parser.y"
    { PRINT_RULE }
#line 2408 "parser.cpp"
    break;

  case 134:
#line 331 "parser.y"
    { PRINT_RULE }
#line 2414 "parser.cpp"
    break;

  case 135:
#line 332 "parser.y"
    { PRINT_RULE }
#line 2420 "parser.cpp"
    break;

  case 136:
#line 333 "parser.y"
    { PRINT_RULE }
#line 2426 "parser.cpp"
    break;

  case 137:
#line 334 "parser.y"
    { PRINT_RULE }
#line 2432 "parser.cpp"
    break;

  case 138:
#line 335 "parser.y"
    { PRINT_RULE }
#line 2438 "parser.cpp"
    break;

  case 139:
#line 336 "parser.y"
    { PRINT_RULE }
#line 2444 "parser.cpp"
    break;

  case 140:
#line 337 "parser.y"
    { PRINT_RULE }
#line 2450 "parser.cpp"
    break;

  case 141:
#line 340 "parser.y"
    { PRINT_RULE }
#line 2456 "parser.cpp"
    break;

  case 142:
#line 341 "parser.y"
    { PRINT_RULE }
#line 2462 "parser.cpp"
    break;

  case 143:
#line 342 "parser.y"
    { PRINT_RULE }
#line 2468 "parser.cpp"
    break;

  case 144:
#line 343 "parser.y"
    { PRINT_RULE }
#line 2474 "parser.cpp"
    break;

  case 145:
#line 348 "parser.y"
    { PRINT_RULE }
#line 2480 "parser.cpp"
    break;

  case 146:
#line 353 "parser.y"
    { PRINT_RULE }
#line 2486 "parser.cpp"
    break;

  case 147:
#line 354 "parser.y"
    { PRINT_RULE }
#line 2492 "parser.cpp"
    break;

  case 148:
#line 355 "parser.y"
    { PRINT_RULE }
#line 2498 "parser.cpp"
    break;

  case 149:
#line 356 "parser.y"
    { PRINT_RULE }
#line 2504 "parser.cpp"
    break;

  case 150:
#line 357 "parser.y"
    { PRINT_RULE }
#line 2510 "parser.cpp"
    break;

  case 151:
#line 358 "parser.y"
    { PRINT_RULE }
#line 2516 "parser.cpp"
    break;

  case 152:
#line 359 "parser.y"
    { PRINT_RULE }
#line 2522 "parser.cpp"
    break;

  case 153:
#line 360 "parser.y"
    { PRINT_RULE }
#line 2528 "parser.cpp"
    break;

  case 154:
#line 361 "parser.y"
    { PRINT_RULE }
#line 2534 "parser.cpp"
    break;

  case 155:
#line 366 "parser.y"
    { PRINT_RULE }
#line 2540 "parser.cpp"
    break;


#line 2544 "parser.cpp"

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
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
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
                      yytoken, &yylval, &yylloc);
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
                  yystos[yystate], yyvsp, yylsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 371 "parser.y"


void print_rule(int num, char* s)
{
	static bool read_once = false;
	static bool valid_file = false;
	static std::vector<char> grammar_file;
	static std::map<int, char*> file_map;
	if (not read_once) {
		FILE *f = fopen("parser.y", "r");
		valid_file = (f != nullptr);
		if (valid_file) {
			fseek(f, 0, SEEK_END);
			long fsize = ftell(f);
			fseek(f, 0, SEEK_SET);

			grammar_file.resize(fsize);
			char* data_ptr = &grammar_file.front();

			fread(data_ptr, 1, fsize, f);

			unsigned last_pos = 0;
			unsigned pos = 0;
			unsigned line = 1;

			while (pos < fsize) {
				if (grammar_file[pos] == '\n')
				{
					file_map[line++] = data_ptr + last_pos;
					for (unsigned i = last_pos; i < pos; i++) {
						if (grammar_file[i] == '\t')
							grammar_file[i] = ' ';
					}
					last_pos = pos + 1;
					grammar_file[pos] = '\0';
				}
				++pos;
			}
			file_map[line] = data_ptr + last_pos;
			fclose(f);
		}
		else
			printf("File of grammar for debugging not found.\n");
		read_once = true;
	}
	if (valid_file) {
		last_calls_stream << "(" << num << ") " << file_map[num] << "\n";
		std::string parent("");
		unsigned i = num;
		auto npos = std::string::npos;
		for (; i >= 1; --i) {
			std::string str(file_map[i]);
			auto dblp = str.find(':');
			if (dblp != npos) {
				unsigned o_sz = parent.size();
				parent = parent + str;
				if (o_sz)
					parent[o_sz - 1] = ' ';
				dblp += o_sz;
				parent[dblp] = '\0';
				parent.resize(dblp + 1);
				if (std::count(str.begin(), str.end(), '|') != 0)
				{
					parent = "[warning]" + parent;
					if (str[0] == ' ')
						continue;
				}
				break;
			}
			else
				continue;
		}
		if (parent == "" and i == -1)
			parent = "[error]";
		parents_stream << "(" << num << ") -> " << parent << " == " << s << "\n";
	}
}
