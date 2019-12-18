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
    BG = 296,
    BGNP = 297,
    ENDCLASS = 298,
    CRAFT = 299,
    IFX = 300,
    UMINUS = 301
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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   407

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  300

#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
       2,     2,     2,     2,     2,     2,     2,    52,     2,     2,
      59,    60,    50,    48,    55,    49,     2,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    54,
      46,    56,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
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
      45,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    46,    46,    47,    50,    51,    52,    53,    54,    55,
      58,    63,    64,    65,    66,    71,    72,    77,    78,    79,
      80,    81,    82,    87,    88,    93,    94,    95,    96,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   119,   120,   125,   130,   131,   136,   137,
     142,   143,   144,   145,   150,   151,   156,   157,   162,   167,
     168,   173,   178,   179,   184,   185,   190,   191,   196,   197,
     198,   199,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   219,   220,   221,   222,   223,   224,   229,
     234,   239,   240,   241,   246,   247,   252,   257,   258,   263,
     268,   273,   278,   283,   288,   289,   294,   295,   296,   297,
     298,   299,   304,   309,   310,   313,   314,   315,   316,   317,
     318,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   343,   344,   345,   346,   351,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   369
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
  "ENDCLASS", "CRAFT", "IFX", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "UMINUS", "';'", "','", "'='", "'['", "']'", "'('", "')'", "':'",
  "$accept", "sp", "s", "class_def", "class_body", "class_var", "type",
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
     295,   296,   297,   298,   299,   300,    60,    62,    43,    45,
      42,    47,    37,   301,    59,    44,    61,    91,    93,    40,
      41,    58
};
# endif

#define YYPACT_NINF -180

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-180)))

#define YYTABLE_NINF -107

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,   206,    38,   -40,   211,    40,   -10,    80,    95,    98,
     250,  -180,   206,  -180,  -180,  -180,  -180,  -180,   206,   206,
    -180,  -180,    15,   196,  -180,  -180,  -180,  -180,  -180,  -180,
      64,   138,     3,   158,   152,   131,   158,    11,   276,   167,
    -180,  -180,  -180,  -180,     2,  -180,  -180,  -180,  -180,  -180,
      15,    15,    45,   127,   112,    86,   145,   220,   251,   258,
     265,   272,  -180,   141,  -180,   157,  -180,   170,   189,   213,
       3,     3,    15,  -180,    20,   207,  -180,   230,  -180,   210,
    -180,   224,   228,   217,   287,   -35,   253,   259,   295,   107,
    -180,  -180,    62,  -180,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15,    15,    15,   297,   107,   196,   261,
     196,   255,   255,  -180,  -180,  -180,  -180,   158,   158,   284,
      48,   106,   267,   268,  -180,    49,   270,   273,   196,   315,
    -180,   167,   274,   166,  -180,   277,  -180,   112,   243,   243,
     243,   243,   243,   243,    31,    31,  -180,  -180,  -180,   124,
     280,   282,  -180,  -180,   276,   323,   283,  -180,   290,   289,
    -180,  -180,   106,   324,  -180,   183,  -180,  -180,   293,   294,
     291,   106,   106,  -180,   319,  -180,  -180,  -180,  -180,  -180,
     196,   340,  -180,   287,  -180,  -180,   298,  -180,   107,   107,
     196,   349,   107,    18,  -180,   345,   302,   106,   255,   203,
     325,   326,   107,   196,   106,   239,    15,   107,   196,  -180,
    -180,  -180,  -180,  -180,   304,  -180,   307,   306,   308,   305,
     354,   310,   356,   313,   314,   350,  -180,   196,   316,   203,
     352,   203,  -180,   106,  -180,   318,   317,  -180,  -180,   182,
    -180,   320,   321,   322,   327,   328,  -180,  -180,  -180,   329,
     279,   244,   330,  -180,  -180,   333,   335,    27,  -180,  -180,
    -180,   343,  -180,  -180,  -180,   334,   337,   328,   196,  -180,
     107,   107,  -180,   203,   203,   332,   336,   339,  -180,    15,
    -180,  -180,   342,   341,   344,   346,  -180,  -180,   347,   351,
    -180,   353,   196,  -180,  -180,   286,  -180,  -180,  -180,  -180
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     7,   155,   145,   148,   147,   149,     8,     9,
     146,     1,     0,    48,    18,    19,    20,    21,    17,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     5,     6,   131,   115,   129,   130,   132,   133,   134,
       0,     0,     0,   128,   113,   131,   115,   129,   130,   132,
     133,   134,    61,     0,    49,    59,    42,     0,     0,     0,
      11,    12,     0,    99,    91,     0,    95,     0,   102,     0,
      90,     0,     0,     0,     0,    25,     0,    23,     0,     0,
     128,   127,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,    64,    64,    10,    13,    14,    94,     0,     0,     0,
       0,     0,     0,     0,   152,     0,     0,    54,     0,    43,
      15,     0,   117,    50,    51,     0,   121,   114,   140,   139,
     138,   137,   136,   135,   122,   123,   124,   125,   126,   117,
       0,     0,   151,    60,     0,     0,     0,    65,    66,     0,
      92,    93,     0,    97,   109,   104,   107,   108,     0,     0,
       0,   143,   144,    86,     0,    87,    88,    96,   154,   153,
       0,     0,    16,     0,    26,    44,     0,    24,     0,     0,
      48,   116,     0,   116,    36,     0,    68,     0,     0,     0,
       0,     0,     0,    48,     0,     0,     0,     0,    48,   141,
     142,    89,    56,    58,     0,    55,    27,     0,     0,     0,
       0,     0,     0,    70,     0,     0,    67,     0,     0,    76,
       0,    79,   100,     0,    98,     0,     0,   103,   112,   106,
     105,     0,     0,     0,     0,     0,   119,    53,    52,   118,
     119,   118,     0,    69,    63,     0,     0,     0,    72,    62,
      75,     0,   111,   110,    83,     0,     0,     0,     0,    28,
       0,     0,    71,    77,    78,     0,     0,     0,   101,     0,
      85,    57,    46,     0,     0,     0,    73,    74,     0,     0,
      80,     0,     0,    45,   120,   120,    82,    81,    84,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -180,  -180,    74,  -180,    77,    -1,    -2,   249,  -180,  -123,
    -180,   114,   102,  -101,  -104,   201,  -180,  -180,   285,  -180,
     -26,   288,   200,  -180,  -173,  -179,    36,  -180,   -27,  -180,
    -180,   137,  -180,  -180,  -180,   278,  -180,  -180,   198,  -180,
     -21,    29,    92,  -158,  -180,  -180,  -180
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    11,    12,    69,   171,   155,    86,    87,    62,
     186,   269,   283,    63,   135,   126,   127,   214,    64,    65,
      14,   156,   157,   158,   230,   172,   173,    79,    73,    74,
     174,   175,    75,   163,   234,   176,    35,   168,   169,   237,
      66,    53,    54,   177,    18,    19,    20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    52,    31,   150,   200,   184,    71,   151,    39,    80,
      88,    13,    76,   209,   210,    76,    22,    13,    13,    23,
     231,   128,   129,     4,    81,    82,   222,    43,    44,    45,
      46,    70,    47,    48,    49,     1,    84,    15,    21,   225,
     275,   276,   117,   118,    71,    71,   238,    10,    15,    33,
     231,   116,   231,    32,    15,    15,   258,   212,   260,    89,
     164,   165,   166,   167,    50,    95,    96,    97,    98,    70,
      70,    83,   -37,   -37,    51,   261,   -37,    67,   -37,    90,
      90,   103,   104,   105,   217,   218,    40,   277,   221,   219,
     160,   161,    41,    42,   231,   231,    76,    76,   235,    93,
     286,   287,   236,   242,   255,   180,   181,   243,    99,   100,
     101,   102,   103,   104,   105,    95,    96,    97,    98,   170,
     133,   134,   136,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,     6,     7,     8,    16,    34,
     -32,   -32,    91,    92,   -32,   282,   -32,   114,   115,    16,
      10,    68,   195,   106,    36,    16,    16,    37,    99,   100,
     101,   102,   103,   104,   105,    77,   284,   285,    78,   282,
      43,    44,    45,    46,    72,    47,    48,    49,   -38,   -38,
      85,   192,   -38,    94,   -38,   241,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   229,   -29,
     -29,   109,   107,   -29,   108,   -29,   256,    50,    55,    56,
      57,    58,   110,    59,    60,    61,   170,    51,    24,     3,
      25,    26,    27,   189,    28,   190,     4,   227,   229,   111,
     229,     5,     6,     7,     8,     6,     7,     8,    29,   202,
     202,   203,   203,   228,  -106,    50,     9,    10,   112,    30,
      10,   164,   239,   166,   167,    51,   113,    24,   291,    25,
      26,    27,    24,    28,    25,    26,    27,   119,    28,   120,
     121,   124,   229,   229,   -30,   -30,    38,    29,   -30,    17,
     -30,   154,    29,    24,   122,    25,    26,    27,   123,    28,
      17,   101,   102,   103,   104,   105,    17,    17,   -39,   -39,
     125,   271,   -39,    29,   -39,   -31,   -31,   130,   132,   -31,
     149,   -31,   -33,   -33,   131,   152,   -33,   162,   -33,   -34,
     -34,   178,   179,   -34,   182,   -34,   -35,   -35,   183,   185,
     -35,   188,   -35,   -40,   -40,   191,   196,   -40,   193,   -40,
     -41,   -41,   194,   197,   -41,   198,   -41,   206,   207,   199,
     208,   211,   201,   204,   213,   205,   216,   220,   223,   224,
     233,   232,   244,   245,   246,   248,   247,   249,   250,   251,
     252,   254,   253,   259,   264,   257,   262,   263,   278,   265,
     187,   281,   266,   267,   215,   268,   270,   273,   272,   274,
     279,   280,   288,   290,   299,   153,   289,   292,   226,   293,
     159,   296,   294,   240,   295,   297,     0,   298
};

static const yytype_int16 yycheck[] =
{
       1,    22,     4,   107,   162,   128,    32,   108,    10,    36,
       8,    12,    33,   171,   172,    36,    56,    18,    19,    59,
     199,    56,    57,    20,    13,    14,     8,    12,    13,    14,
      15,    32,    17,    18,    19,    42,    38,     1,     0,   197,
      13,    14,    22,    23,    70,    71,   204,    44,    12,    59,
     229,    72,   231,    13,    18,    19,   229,   180,   231,    57,
      12,    13,    14,    15,    49,     3,     4,     5,     6,    70,
      71,    60,    54,    55,    59,   233,    58,    13,    60,    50,
      51,    50,    51,    52,   188,   189,    12,    60,   192,   190,
     117,   118,    18,    19,   273,   274,   117,   118,   202,    54,
     273,   274,   203,   207,   227,    56,    57,   208,    46,    47,
      48,    49,    50,    51,    52,     3,     4,     5,     6,    13,
      13,    14,    60,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,    29,    30,    31,     1,    59,
      54,    55,    50,    51,    58,   268,    60,    70,    71,    12,
      44,    13,   154,     8,    59,    18,    19,    59,    46,    47,
      48,    49,    50,    51,    52,    13,   270,   271,    37,   292,
      12,    13,    14,    15,    16,    17,    18,    19,    54,    55,
      13,    57,    58,    56,    60,   206,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   199,    54,
      55,    60,    57,    58,    59,    60,   227,    49,    12,    13,
      14,    15,    55,    17,    18,    19,    13,    59,     7,    13,
       9,    10,    11,    57,    13,    59,    20,    24,   229,    59,
     231,    25,    29,    30,    31,    29,    30,    31,    27,    57,
      57,    59,    59,    40,    61,    49,    40,    44,    59,    38,
      44,    12,    13,    14,    15,    59,    43,     7,   279,     9,
      10,    11,     7,    13,     9,    10,    11,    60,    13,    39,
      60,    54,   273,   274,    54,    55,    26,    27,    58,     1,
      60,    26,    27,     7,    60,     9,    10,    11,    60,    13,
      12,    48,    49,    50,    51,    52,    18,    19,    54,    55,
      13,    57,    58,    27,    60,    54,    55,    54,    13,    58,
      13,    60,    54,    55,    55,    54,    58,    33,    60,    54,
      55,    54,    54,    58,    54,    60,    54,    55,    55,    14,
      58,    57,    60,    54,    55,    58,    13,    58,    58,    60,
      54,    55,    60,    60,    58,    55,    60,    56,    57,    60,
      59,    32,    28,    60,    14,    61,    58,     8,    13,    57,
      34,    36,    58,    56,    58,    60,    58,    13,    58,    13,
      57,    21,    58,    21,    54,    59,    58,    60,    35,    58,
     131,   267,    60,    56,   183,    57,    57,    54,    58,    54,
      56,    54,    60,    54,   292,   110,    60,    55,   198,    58,
     112,    54,    58,   205,    58,    54,    -1,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    63,    13,    20,    25,    29,    30,    31,    40,
      44,    64,    65,    67,    82,    88,    93,    97,   106,   107,
     108,     0,    56,    59,     7,     9,    10,    11,    13,    27,
      38,    68,    13,    59,    59,    98,    59,    59,    26,    68,
      64,    64,    64,    12,    13,    14,    15,    17,    18,    19,
      49,    59,   102,   103,   104,    12,    13,    14,    15,    17,
      18,    19,    71,    75,    80,    81,   102,    13,    13,    66,
      67,    82,    16,    90,    91,    94,   102,    13,    37,    89,
      90,    13,    14,    60,    68,    13,    69,    70,     8,    57,
     103,   104,   104,    54,    56,     3,     4,     5,     6,    46,
      47,    48,    49,    50,    51,    52,     8,    57,    59,    60,
      55,    59,    59,    43,    66,    66,   102,    22,    23,    60,
      39,    60,    60,    60,    54,    13,    77,    78,    56,    57,
      54,    55,    13,    13,    14,    76,    60,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,    13,
      76,    75,    54,    80,    26,    68,    83,    84,    85,    83,
      90,    90,    33,    95,    12,    13,    14,    15,    99,   100,
      13,    67,    87,    88,    92,    93,    97,   105,    54,    54,
      56,    57,    54,    55,    71,    14,    72,    69,    57,    57,
      59,    58,    57,    58,    60,    68,    13,    60,    55,    60,
     105,    28,    57,    59,    60,    61,    56,    57,    59,   105,
     105,    32,    71,    14,    79,    77,    58,    76,    76,    75,
       8,    76,     8,    13,    57,   105,    84,    24,    40,    67,
      86,    87,    36,    34,    96,    76,    75,   101,   105,    13,
     100,   102,    76,    75,    58,    56,    58,    58,    60,    13,
      58,    13,    57,    58,    21,    71,   102,    59,    86,    21,
      86,   105,    58,    60,    54,    58,    60,    56,    57,    73,
      57,    57,    58,    54,    54,    13,    14,    60,    35,    56,
      54,    73,    71,    74,    76,    76,    86,    86,    60,    60,
      54,   102,    55,    58,    58,    58,    54,    54,    54,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    63,    64,    64,    64,    64,    64,    64,
      65,    66,    66,    66,    66,    67,    67,    68,    68,    68,
      68,    68,    68,    69,    69,    70,    70,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    72,    72,    73,    74,    74,    75,    75,
      76,    76,    76,    76,    77,    77,    78,    78,    79,    80,
      80,    81,    82,    82,    83,    83,    84,    84,    85,    85,
      85,    85,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    87,    87,    87,    87,    88,
      89,    90,    90,    90,    91,    91,    92,    93,    93,    94,
      95,    96,    97,    98,    99,    99,   100,   100,   100,   100,
     100,   100,   101,   102,   102,   103,   103,   103,   103,   103,
     103,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   105,   105,   105,   105,   106,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   108
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     2,     1,     1,     1,
       4,     1,     1,     2,     2,     4,     5,     1,     1,     1,
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
#line 46 "parser.y"
    { printf("Reached start symbol.\n"); }
#line 1623 "parser.cpp"
    break;

  case 3:
#line 47 "parser.y"
    { printf("Reached start symbol.\n"); }
#line 1629 "parser.cpp"
    break;

  case 4:
#line 50 "parser.y"
    { PRINT_RULE }
#line 1635 "parser.cpp"
    break;

  case 5:
#line 51 "parser.y"
    { PRINT_RULE }
#line 1641 "parser.cpp"
    break;

  case 6:
#line 52 "parser.y"
    { PRINT_RULE }
#line 1647 "parser.cpp"
    break;

  case 7:
#line 53 "parser.y"
    { PRINT_RULE }
#line 1653 "parser.cpp"
    break;

  case 8:
#line 54 "parser.y"
    { PRINT_RULE }
#line 1659 "parser.cpp"
    break;

  case 9:
#line 55 "parser.y"
    { PRINT_RULE }
#line 1665 "parser.cpp"
    break;

  case 10:
#line 58 "parser.y"
    { PRINT_RULE }
#line 1671 "parser.cpp"
    break;

  case 11:
#line 63 "parser.y"
    { PRINT_RULE }
#line 1677 "parser.cpp"
    break;

  case 12:
#line 64 "parser.y"
    { PRINT_RULE }
#line 1683 "parser.cpp"
    break;

  case 13:
#line 65 "parser.y"
    { PRINT_RULE }
#line 1689 "parser.cpp"
    break;

  case 14:
#line 66 "parser.y"
    { PRINT_RULE }
#line 1695 "parser.cpp"
    break;

  case 15:
#line 71 "parser.y"
    { PRINT_RULE }
#line 1701 "parser.cpp"
    break;

  case 16:
#line 72 "parser.y"
    { PRINT_RULE }
#line 1707 "parser.cpp"
    break;

  case 17:
#line 77 "parser.y"
    { PRINT_RULE }
#line 1713 "parser.cpp"
    break;

  case 18:
#line 78 "parser.y"
    { PRINT_RULE }
#line 1719 "parser.cpp"
    break;

  case 19:
#line 79 "parser.y"
    { PRINT_RULE }
#line 1725 "parser.cpp"
    break;

  case 20:
#line 80 "parser.y"
    { PRINT_RULE }
#line 1731 "parser.cpp"
    break;

  case 21:
#line 81 "parser.y"
    { PRINT_RULE }
#line 1737 "parser.cpp"
    break;

  case 22:
#line 82 "parser.y"
    { PRINT_RULE }
#line 1743 "parser.cpp"
    break;

  case 23:
#line 87 "parser.y"
    { PRINT_RULE }
#line 1749 "parser.cpp"
    break;

  case 24:
#line 88 "parser.y"
    { PRINT_RULE }
#line 1755 "parser.cpp"
    break;

  case 25:
#line 93 "parser.y"
    { PRINT_RULE }
#line 1761 "parser.cpp"
    break;

  case 26:
#line 94 "parser.y"
    { PRINT_RULE }
#line 1767 "parser.cpp"
    break;

  case 27:
#line 95 "parser.y"
    { PRINT_RULE }
#line 1773 "parser.cpp"
    break;

  case 28:
#line 96 "parser.y"
    { PRINT_RULE }
#line 1779 "parser.cpp"
    break;

  case 29:
#line 101 "parser.y"
    { PRINT_RULE }
#line 1785 "parser.cpp"
    break;

  case 30:
#line 102 "parser.y"
    { PRINT_RULE }
#line 1791 "parser.cpp"
    break;

  case 31:
#line 103 "parser.y"
    { PRINT_RULE }
#line 1797 "parser.cpp"
    break;

  case 32:
#line 104 "parser.y"
    { PRINT_RULE }
#line 1803 "parser.cpp"
    break;

  case 33:
#line 105 "parser.y"
    { PRINT_RULE }
#line 1809 "parser.cpp"
    break;

  case 34:
#line 106 "parser.y"
    { PRINT_RULE }
#line 1815 "parser.cpp"
    break;

  case 35:
#line 107 "parser.y"
    { PRINT_RULE }
#line 1821 "parser.cpp"
    break;

  case 36:
#line 108 "parser.y"
    { PRINT_RULE }
#line 1827 "parser.cpp"
    break;

  case 37:
#line 109 "parser.y"
    { PRINT_RULE }
#line 1833 "parser.cpp"
    break;

  case 38:
#line 110 "parser.y"
    { PRINT_RULE }
#line 1839 "parser.cpp"
    break;

  case 39:
#line 111 "parser.y"
    { PRINT_RULE }
#line 1845 "parser.cpp"
    break;

  case 40:
#line 112 "parser.y"
    { PRINT_RULE }
#line 1851 "parser.cpp"
    break;

  case 41:
#line 113 "parser.y"
    { PRINT_RULE }
#line 1857 "parser.cpp"
    break;

  case 42:
#line 114 "parser.y"
    { PRINT_RULE }
#line 1863 "parser.cpp"
    break;

  case 43:
#line 119 "parser.y"
    { PRINT_RULE /*s-ar putea sa ne vina mai usor daca facem vector size nul direct din regula fara eps pentru ca sa identificam noi nr de param*/}
#line 1869 "parser.cpp"
    break;

  case 44:
#line 120 "parser.y"
    { PRINT_RULE }
#line 1875 "parser.cpp"
    break;

  case 45:
#line 125 "parser.y"
    { PRINT_RULE }
#line 1881 "parser.cpp"
    break;

  case 46:
#line 130 "parser.y"
    { PRINT_RULE }
#line 1887 "parser.cpp"
    break;

  case 47:
#line 131 "parser.y"
    { PRINT_RULE }
#line 1893 "parser.cpp"
    break;

  case 48:
#line 136 "parser.y"
    { PRINT_RULE }
#line 1899 "parser.cpp"
    break;

  case 49:
#line 137 "parser.y"
    { PRINT_RULE }
#line 1905 "parser.cpp"
    break;

  case 50:
#line 142 "parser.y"
    { PRINT_RULE }
#line 1911 "parser.cpp"
    break;

  case 51:
#line 143 "parser.y"
    { PRINT_RULE }
#line 1917 "parser.cpp"
    break;

  case 52:
#line 144 "parser.y"
    { PRINT_RULE }
#line 1923 "parser.cpp"
    break;

  case 53:
#line 145 "parser.y"
    { PRINT_RULE }
#line 1929 "parser.cpp"
    break;

  case 54:
#line 150 "parser.y"
    { PRINT_RULE }
#line 1935 "parser.cpp"
    break;

  case 55:
#line 151 "parser.y"
    { PRINT_RULE }
#line 1941 "parser.cpp"
    break;

  case 56:
#line 156 "parser.y"
    { PRINT_RULE }
#line 1947 "parser.cpp"
    break;

  case 57:
#line 157 "parser.y"
    { PRINT_RULE }
#line 1953 "parser.cpp"
    break;

  case 58:
#line 162 "parser.y"
    { PRINT_RULE }
#line 1959 "parser.cpp"
    break;

  case 59:
#line 167 "parser.y"
    { PRINT_RULE }
#line 1965 "parser.cpp"
    break;

  case 60:
#line 168 "parser.y"
    { PRINT_RULE }
#line 1971 "parser.cpp"
    break;

  case 61:
#line 173 "parser.y"
    {/*nu stiu daca aici este corect, dar eu presupun ca da*/ PRINT_RULE }
#line 1977 "parser.cpp"
    break;

  case 62:
#line 178 "parser.y"
    { PRINT_RULE }
#line 1983 "parser.cpp"
    break;

  case 63:
#line 179 "parser.y"
    { PRINT_RULE }
#line 1989 "parser.cpp"
    break;

  case 64:
#line 184 "parser.y"
    { PRINT_RULE }
#line 1995 "parser.cpp"
    break;

  case 65:
#line 185 "parser.y"
    { PRINT_RULE }
#line 2001 "parser.cpp"
    break;

  case 66:
#line 190 "parser.y"
    { PRINT_RULE }
#line 2007 "parser.cpp"
    break;

  case 67:
#line 191 "parser.y"
    { PRINT_RULE }
#line 2013 "parser.cpp"
    break;

  case 68:
#line 196 "parser.y"
    { PRINT_RULE }
#line 2019 "parser.cpp"
    break;

  case 69:
#line 197 "parser.y"
    { PRINT_RULE }
#line 2025 "parser.cpp"
    break;

  case 70:
#line 198 "parser.y"
    { PRINT_RULE }
#line 2031 "parser.cpp"
    break;

  case 71:
#line 199 "parser.y"
    { PRINT_RULE }
#line 2037 "parser.cpp"
    break;

  case 72:
#line 204 "parser.y"
    { PRINT_RULE }
#line 2043 "parser.cpp"
    break;

  case 73:
#line 205 "parser.y"
    { PRINT_RULE }
#line 2049 "parser.cpp"
    break;

  case 74:
#line 206 "parser.y"
    { PRINT_RULE }
#line 2055 "parser.cpp"
    break;

  case 75:
#line 207 "parser.y"
    { PRINT_RULE }
#line 2061 "parser.cpp"
    break;

  case 76:
#line 208 "parser.y"
    { PRINT_RULE }
#line 2067 "parser.cpp"
    break;

  case 77:
#line 209 "parser.y"
    { PRINT_RULE }
#line 2073 "parser.cpp"
    break;

  case 78:
#line 210 "parser.y"
    { PRINT_RULE }
#line 2079 "parser.cpp"
    break;

  case 79:
#line 211 "parser.y"
    { PRINT_RULE }
#line 2085 "parser.cpp"
    break;

  case 80:
#line 212 "parser.y"
    { PRINT_RULE }
#line 2091 "parser.cpp"
    break;

  case 81:
#line 213 "parser.y"
    { PRINT_RULE }
#line 2097 "parser.cpp"
    break;

  case 82:
#line 214 "parser.y"
    { PRINT_RULE }
#line 2103 "parser.cpp"
    break;

  case 83:
#line 219 "parser.y"
    { PRINT_RULE }
#line 2109 "parser.cpp"
    break;

  case 84:
#line 220 "parser.y"
    { PRINT_RULE }
#line 2115 "parser.cpp"
    break;

  case 85:
#line 221 "parser.y"
    { PRINT_RULE }
#line 2121 "parser.cpp"
    break;

  case 86:
#line 222 "parser.y"
    { PRINT_RULE }
#line 2127 "parser.cpp"
    break;

  case 87:
#line 223 "parser.y"
    { PRINT_RULE }
#line 2133 "parser.cpp"
    break;

  case 88:
#line 224 "parser.y"
    { PRINT_RULE }
#line 2139 "parser.cpp"
    break;

  case 89:
#line 229 "parser.y"
    { PRINT_RULE }
#line 2145 "parser.cpp"
    break;

  case 90:
#line 234 "parser.y"
    { PRINT_RULE }
#line 2151 "parser.cpp"
    break;

  case 91:
#line 239 "parser.y"
    { PRINT_RULE }
#line 2157 "parser.cpp"
    break;

  case 92:
#line 240 "parser.y"
    { PRINT_RULE }
#line 2163 "parser.cpp"
    break;

  case 93:
#line 241 "parser.y"
    { PRINT_RULE }
#line 2169 "parser.cpp"
    break;

  case 94:
#line 246 "parser.y"
    { PRINT_RULE }
#line 2175 "parser.cpp"
    break;

  case 95:
#line 247 "parser.y"
    { PRINT_RULE }
#line 2181 "parser.cpp"
    break;

  case 96:
#line 252 "parser.y"
    {/*de asemenea nu stiu daca este ok ce fac aicea*/ PRINT_RULE }
#line 2187 "parser.cpp"
    break;

  case 97:
#line 257 "parser.y"
    { PRINT_RULE }
#line 2193 "parser.cpp"
    break;

  case 98:
#line 258 "parser.y"
    { PRINT_RULE }
#line 2199 "parser.cpp"
    break;

  case 99:
#line 263 "parser.y"
    { PRINT_RULE }
#line 2205 "parser.cpp"
    break;

  case 100:
#line 268 "parser.y"
    { PRINT_RULE }
#line 2211 "parser.cpp"
    break;

  case 101:
#line 273 "parser.y"
    { PRINT_RULE }
#line 2217 "parser.cpp"
    break;

  case 102:
#line 278 "parser.y"
    { PRINT_RULE }
#line 2223 "parser.cpp"
    break;

  case 103:
#line 283 "parser.y"
    { PRINT_RULE }
#line 2229 "parser.cpp"
    break;

  case 104:
#line 288 "parser.y"
    { PRINT_RULE }
#line 2235 "parser.cpp"
    break;

  case 105:
#line 289 "parser.y"
    { PRINT_RULE }
#line 2241 "parser.cpp"
    break;

  case 106:
#line 294 "parser.y"
    { PRINT_RULE }
#line 2247 "parser.cpp"
    break;

  case 107:
#line 295 "parser.y"
    { PRINT_RULE }
#line 2253 "parser.cpp"
    break;

  case 108:
#line 296 "parser.y"
    { PRINT_RULE }
#line 2259 "parser.cpp"
    break;

  case 109:
#line 297 "parser.y"
    { PRINT_RULE }
#line 2265 "parser.cpp"
    break;

  case 110:
#line 298 "parser.y"
    { PRINT_RULE }
#line 2271 "parser.cpp"
    break;

  case 111:
#line 299 "parser.y"
    { PRINT_RULE }
#line 2277 "parser.cpp"
    break;

  case 112:
#line 304 "parser.y"
    { PRINT_RULE }
#line 2283 "parser.cpp"
    break;

  case 113:
#line 309 "parser.y"
    { PRINT_RULE }
#line 2289 "parser.cpp"
    break;

  case 114:
#line 310 "parser.y"
    { PRINT_RULE }
#line 2295 "parser.cpp"
    break;

  case 115:
#line 313 "parser.y"
    { PRINT_RULE }
#line 2301 "parser.cpp"
    break;

  case 116:
#line 314 "parser.y"
    { PRINT_RULE }
#line 2307 "parser.cpp"
    break;

  case 117:
#line 315 "parser.y"
    { PRINT_RULE }
#line 2313 "parser.cpp"
    break;

  case 118:
#line 316 "parser.y"
    { PRINT_RULE }
#line 2319 "parser.cpp"
    break;

  case 119:
#line 317 "parser.y"
    { PRINT_RULE }
#line 2325 "parser.cpp"
    break;

  case 120:
#line 318 "parser.y"
    { PRINT_RULE }
#line 2331 "parser.cpp"
    break;

  case 121:
#line 321 "parser.y"
    { PRINT_RULE }
#line 2337 "parser.cpp"
    break;

  case 122:
#line 322 "parser.y"
    { PRINT_RULE }
#line 2343 "parser.cpp"
    break;

  case 123:
#line 323 "parser.y"
    { PRINT_RULE }
#line 2349 "parser.cpp"
    break;

  case 124:
#line 324 "parser.y"
    { PRINT_RULE }
#line 2355 "parser.cpp"
    break;

  case 125:
#line 325 "parser.y"
    { PRINT_RULE }
#line 2361 "parser.cpp"
    break;

  case 126:
#line 326 "parser.y"
    { PRINT_RULE }
#line 2367 "parser.cpp"
    break;

  case 127:
#line 327 "parser.y"
    { PRINT_RULE }
#line 2373 "parser.cpp"
    break;

  case 128:
#line 328 "parser.y"
    { PRINT_RULE }
#line 2379 "parser.cpp"
    break;

  case 129:
#line 329 "parser.y"
    { PRINT_RULE }
#line 2385 "parser.cpp"
    break;

  case 130:
#line 330 "parser.y"
    { PRINT_RULE }
#line 2391 "parser.cpp"
    break;

  case 131:
#line 331 "parser.y"
    { PRINT_RULE }
#line 2397 "parser.cpp"
    break;

  case 132:
#line 332 "parser.y"
    { PRINT_RULE }
#line 2403 "parser.cpp"
    break;

  case 133:
#line 333 "parser.y"
    { PRINT_RULE }
#line 2409 "parser.cpp"
    break;

  case 134:
#line 334 "parser.y"
    { PRINT_RULE }
#line 2415 "parser.cpp"
    break;

  case 135:
#line 335 "parser.y"
    { PRINT_RULE }
#line 2421 "parser.cpp"
    break;

  case 136:
#line 336 "parser.y"
    { PRINT_RULE }
#line 2427 "parser.cpp"
    break;

  case 137:
#line 337 "parser.y"
    { PRINT_RULE }
#line 2433 "parser.cpp"
    break;

  case 138:
#line 338 "parser.y"
    { PRINT_RULE }
#line 2439 "parser.cpp"
    break;

  case 139:
#line 339 "parser.y"
    { PRINT_RULE }
#line 2445 "parser.cpp"
    break;

  case 140:
#line 340 "parser.y"
    { PRINT_RULE }
#line 2451 "parser.cpp"
    break;

  case 141:
#line 343 "parser.y"
    { PRINT_RULE }
#line 2457 "parser.cpp"
    break;

  case 142:
#line 344 "parser.y"
    { PRINT_RULE }
#line 2463 "parser.cpp"
    break;

  case 143:
#line 345 "parser.y"
    { PRINT_RULE }
#line 2469 "parser.cpp"
    break;

  case 144:
#line 346 "parser.y"
    { PRINT_RULE }
#line 2475 "parser.cpp"
    break;

  case 145:
#line 351 "parser.y"
    { PRINT_RULE }
#line 2481 "parser.cpp"
    break;

  case 146:
#line 356 "parser.y"
    { PRINT_RULE }
#line 2487 "parser.cpp"
    break;

  case 147:
#line 357 "parser.y"
    { PRINT_RULE }
#line 2493 "parser.cpp"
    break;

  case 148:
#line 358 "parser.y"
    { PRINT_RULE }
#line 2499 "parser.cpp"
    break;

  case 149:
#line 359 "parser.y"
    { PRINT_RULE }
#line 2505 "parser.cpp"
    break;

  case 150:
#line 360 "parser.y"
    { PRINT_RULE }
#line 2511 "parser.cpp"
    break;

  case 151:
#line 361 "parser.y"
    { PRINT_RULE }
#line 2517 "parser.cpp"
    break;

  case 152:
#line 362 "parser.y"
    { PRINT_RULE }
#line 2523 "parser.cpp"
    break;

  case 153:
#line 363 "parser.y"
    { PRINT_RULE }
#line 2529 "parser.cpp"
    break;

  case 154:
#line 364 "parser.y"
    { PRINT_RULE }
#line 2535 "parser.cpp"
    break;

  case 155:
#line 369 "parser.y"
    { PRINT_RULE }
#line 2541 "parser.cpp"
    break;


#line 2545 "parser.cpp"

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
#line 374 "parser.y"


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
