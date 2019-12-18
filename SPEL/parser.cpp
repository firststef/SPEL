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
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   449

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  316

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
  "ENDCLASS", "CRAFT", "BSTOW", "ENCH", "WITH", "SACRF", "TIME", "CHNT",
  "IFX", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "'.'",
  "','", "'['", "']'", "':'", "'('", "')'", "$accept", "sp", "s",
  "class_def", "class_body", "class_var", "type", "class_ids", "class_id",
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    60,    62,    43,    45,    42,    47,    37,   307,
      46,    44,    91,    93,    58,    40,    41
};
# endif

#define YYPACT_NINF -216

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-216)))

#define YYTABLE_NINF -107

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -35,   250,    49,  -216,  -216,  -216,  -216,  -216,    38,  -216,
      -7,    -3,    16,    71,    29,   303,    85,    86,  -216,   250,
    -216,    92,  -216,  -216,  -216,  -216,   250,   250,  -216,  -216,
     260,   137,   115,    95,   137,   132,    14,   329,   135,   121,
     133,  -216,   171,  -216,  -216,   144,   260,   260,  -216,     6,
    -216,  -216,   199,  -216,  -216,  -216,   176,   211,   211,  -216,
      10,   124,  -216,  -216,   117,   154,  -216,   128,  -216,   172,
     155,   165,   138,   227,   -39,   182,   183,   199,   112,   200,
    -216,  -216,  -216,   238,     2,  -216,   208,  -216,    81,   137,
     137,   225,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   129,   276,    30,   202,   205,  -216,    31,
     212,   213,   191,   268,  -216,   135,   218,   175,    53,   264,
     302,   307,   312,   317,  -216,   280,  -216,   231,  -216,   236,
    -216,    30,   237,   240,  -216,   290,   226,   211,  -216,  -216,
    -216,   276,   283,   289,   289,   289,   289,   289,   289,   228,
     228,  -216,  -216,  -216,  -216,   -20,  -216,  -216,   310,   265,
     269,   319,   324,   276,   276,  -216,   309,  -216,  -216,  -216,
     329,  -216,   340,   291,  -216,   293,  -216,  -216,   191,   350,
    -216,   227,  -216,  -216,   306,  -216,  -216,   361,     2,   331,
     332,   191,   320,     2,     2,   341,   385,   117,   358,   362,
       2,   347,   276,   151,   153,   349,  -216,  -216,  -216,   386,
     336,   276,   308,  -216,  -216,   337,  -216,   356,   288,   339,
     112,  -216,  -216,   203,   342,   343,   112,   390,  -216,   276,
    -216,   344,   112,  -216,  -216,   346,  -216,   199,     2,   112,
     348,   351,   383,  -216,   364,   353,     2,    11,   352,   191,
     354,   203,   391,   203,  -216,  -216,   357,   355,   376,  -216,
     359,   360,   363,   365,   367,  -216,  -216,   353,   191,  -216,
     368,   400,  -216,   372,   373,    17,  -216,  -216,  -216,  -216,
       2,  -216,  -216,  -216,   371,   374,  -216,  -216,   366,   375,
     322,   297,   203,   203,   369,   370,   377,   378,   199,  -216,
     191,  -216,     2,  -216,  -216,   379,   380,  -216,  -216,   382,
    -216,   381,  -216,  -216,  -216,   327
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,    18,    19,    20,    21,    17,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     7,
     155,     0,   145,   148,   147,   149,     8,     9,   146,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     0,     5,     6,     0,    11,    12,   131,   115,
     129,   130,     0,   132,   133,   134,     0,     0,     0,    99,
      91,     0,    95,   128,   113,     0,   102,     0,    90,     0,
       0,     0,     0,     0,    25,     0,    23,     0,     0,     0,
      10,    13,    14,     0,     0,    94,     0,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,     0,
       0,    54,     0,    43,    15,     0,     0,   131,   115,   129,
     130,   132,   133,   134,    48,     0,    61,     0,    49,    59,
      42,     0,   117,    50,    51,     0,     0,     0,   121,    92,
      93,     0,    97,   140,   139,   138,   137,   136,   135,   122,
     123,   124,   125,   126,   109,   104,   107,   108,     0,     0,
       0,     0,     0,   143,   144,    86,     0,    87,    88,    96,
       0,    64,     0,     0,    65,    66,   154,   153,     0,     0,
      16,     0,    26,    44,     0,    24,   150,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,   114,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   142,    89,     0,
      68,     0,     0,    56,    58,     0,    55,    27,   117,     0,
       0,   151,    60,     0,     0,     0,     0,     0,   100,     0,
      98,     0,     0,   103,   112,   106,   105,     0,     0,     0,
      70,     0,     0,    67,     0,     0,     0,   116,     0,     0,
       0,    76,     0,    79,   119,    53,     0,   118,     0,   111,
       0,     0,     0,     0,     0,    69,    63,     0,     0,    28,
       0,     0,    36,     0,     0,     0,    72,    62,    75,    52,
       0,   101,   110,    83,     0,     0,    71,    57,    46,     0,
     119,   118,    77,    78,     0,     0,     0,     0,     0,    85,
       0,    45,     0,    73,    74,     0,     0,    80,   120,     0,
      47,     0,    82,    81,    84,   120
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -216,  -216,    -6,  -216,     7,    -1,   -13,   313,  -216,  -109,
    -216,   157,   122,   -44,  -183,   244,  -216,  -216,   252,  -216,
     150,   314,   234,  -216,  -203,  -215,    69,  -216,   -25,  -216,
    -216,   159,  -216,  -216,  -216,   282,  -216,  -216,   245,  -216,
     -30,   393,     9,  -129,  -216,  -216,  -216
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    18,    19,    45,   163,    21,    75,    76,   126,
     184,   269,   289,   127,   136,   110,   111,   215,   128,   129,
      22,   173,   174,   175,   252,   164,   165,    67,    59,    60,
     166,   167,    61,   142,   230,   168,    33,   159,   160,   233,
     130,    63,    64,   169,    26,    27,    28
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    62,    38,   182,    62,   219,   112,     1,   253,    68,
     224,   225,   198,    41,    83,   133,   134,   231,    20,   271,
      43,    44,    85,   113,    73,    20,    20,    70,    71,    46,
     294,   295,    89,    90,   206,   207,   253,     3,   253,     4,
       5,     6,   200,     7,  -106,    46,    46,   116,   276,    29,
     278,    30,   135,    81,    82,   262,   170,     9,    31,    62,
      62,   187,    32,   270,   139,   140,    87,    88,    84,   213,
      23,   -37,   -37,   234,   -37,   -37,   178,   253,   253,   171,
      72,    34,   242,   296,    92,    93,    94,    95,    23,   303,
     304,    35,   172,   179,    36,    23,    23,   297,    39,    40,
     258,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    42,   -29,   -29,   188,   -29,   -29,   172,   311,
      92,    93,    94,    95,   117,   118,   119,   120,    65,   121,
     122,   123,    66,    96,    97,    98,    99,   100,   101,   102,
     273,   154,   155,   156,   157,    69,   197,   138,    74,    48,
      49,    50,    51,    52,    53,    54,    55,   209,    56,   288,
      24,   124,   125,   154,   235,   156,   157,    57,    77,    96,
      97,    98,    99,   100,   101,   102,   248,    58,    24,   158,
      47,    78,   256,    56,    79,    24,    24,    80,   260,    49,
      91,   288,    57,   103,   104,   263,    47,    47,   108,   172,
     237,   158,    58,   117,   118,   119,   120,   261,   121,   122,
     123,    48,    49,    50,    51,   238,    53,    54,    55,   274,
     105,   106,   251,    48,    49,    50,    51,   249,    53,    54,
      55,   107,    10,    11,    12,   -32,   -32,    56,   -32,   -32,
     109,   125,   114,   250,   115,    56,    57,    15,   131,   161,
     251,   132,   251,   162,    57,   137,    58,     3,   141,     4,
       5,     6,   176,     7,    58,   177,    57,     3,   309,     4,
       5,     6,   180,     7,   181,     8,    58,     9,   186,    10,
      11,    12,   183,    25,   100,   101,   102,     9,    13,   196,
      14,   251,   251,   189,    15,   190,    16,   191,    13,   193,
      17,    25,   194,   195,    15,    10,    11,    12,    25,    25,
       3,   199,     4,     5,     6,     3,     7,     4,     5,     6,
      15,     7,   161,   201,   -30,   -30,   162,   -30,   -30,    37,
       9,   202,   204,   203,   170,     9,     3,   205,     4,     5,
       6,   208,     7,    98,    99,   100,   101,   102,   -38,   -38,
     246,   -38,   -38,   210,   212,   211,     9,   -39,   -39,   302,
     -39,   -39,   -31,   -31,   214,   -31,   -31,   -33,   -33,   217,
     -33,   -33,   -34,   -34,   218,   -34,   -34,   -35,   -35,   220,
     -35,   -35,   -40,   -40,   223,   -40,   -40,   -41,   -41,   226,
     -41,   -41,   221,   227,   228,   232,   229,   239,   241,   240,
     244,   245,   247,   257,   266,   254,   255,   259,   200,   267,
     264,   281,   277,   291,   265,   268,   272,   280,   298,   275,
     283,   279,   310,   282,   287,   216,   284,   300,   185,   285,
     286,   290,   292,   293,   299,   305,   306,   307,   301,   312,
     313,   308,   314,   222,   315,   192,   243,     0,   236,    86
};

static const yytype_int16 yycheck[] =
{
       1,    31,    15,   112,    34,   188,    45,    42,   223,    34,
     193,   194,   141,    19,     8,    13,    14,   200,    19,     8,
      26,    27,    52,    62,    37,    26,    27,    13,    14,    30,
      13,    14,    22,    23,   163,   164,   251,     7,   253,     9,
      10,    11,    62,    13,    64,    46,    47,    77,   251,     0,
     253,    13,    50,    46,    47,   238,    26,    27,    65,    89,
      90,     8,    65,   246,    89,    90,    57,    58,    62,   178,
       1,    60,    61,   202,    63,    64,    45,   292,   293,    49,
      66,    65,   211,    66,     3,     4,     5,     6,    19,   292,
     293,    20,   105,    62,    65,    26,    27,   280,    13,    13,
     229,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    20,    60,    61,    62,    63,    64,   131,   302,
       3,     4,     5,     6,    12,    13,    14,    15,    13,    17,
      18,    19,    37,    52,    53,    54,    55,    56,    57,    58,
     249,    12,    13,    14,    15,    13,   137,    66,    13,    12,
      13,    14,    15,    16,    17,    18,    19,   170,    46,   268,
       1,    49,    50,    12,    13,    14,    15,    55,    47,    52,
      53,    54,    55,    56,    57,    58,   220,    65,    19,    50,
      30,    48,   226,    46,    13,    26,    27,    43,   232,    13,
      66,   300,    55,    39,    66,   239,    46,    47,    60,   212,
      47,    50,    65,    12,    13,    14,    15,   237,    17,    18,
      19,    12,    13,    14,    15,    62,    17,    18,    19,   249,
      48,    66,   223,    12,    13,    14,    15,    24,    17,    18,
      19,    66,    29,    30,    31,    60,    61,    46,    63,    64,
      13,    50,    60,    40,    61,    46,    55,    44,    48,    46,
     251,    13,   253,    50,    55,    47,    65,     7,    33,     9,
      10,    11,    60,    13,    65,    60,    55,     7,   298,     9,
      10,    11,    60,    13,    61,    25,    65,    27,    60,    29,
      30,    31,    14,     1,    56,    57,    58,    27,    38,    63,
      40,   292,   293,    13,    44,    64,    46,    61,    38,    62,
      50,    19,    62,    13,    44,    29,    30,    31,    26,    27,
       7,    28,     9,    10,    11,     7,    13,     9,    10,    11,
      44,    13,    46,    13,    60,    61,    50,    63,    64,    26,
      27,    66,    13,    64,    26,    27,     7,    13,     9,    10,
      11,    32,    13,    54,    55,    56,    57,    58,    60,    61,
      62,    63,    64,    13,    61,    64,    27,    60,    61,    62,
      63,    64,    60,    61,    14,    63,    64,    60,    61,    63,
      63,    64,    60,    61,    13,    63,    64,    60,    61,    48,
      63,    64,    60,    61,    64,    63,    64,    60,    61,    48,
      63,    64,    60,     8,    36,    48,    34,    48,    62,    13,
      63,    45,    63,    13,    21,    63,    63,    63,    62,    45,
      62,    35,    21,    13,    63,    62,    64,    62,    47,    65,
      60,    64,   300,    64,   267,   181,    63,    61,   115,    64,
      63,    63,    60,    60,    60,    66,    66,    60,    63,    60,
      60,    63,    60,   191,    63,   131,   212,    -1,   203,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    68,     7,     9,    10,    11,    13,    25,    27,
      29,    30,    31,    38,    40,    44,    46,    50,    69,    70,
      72,    73,    87,    93,    98,   102,   111,   112,   113,     0,
      13,    65,    65,   103,    65,    20,    65,    26,    73,    13,
      13,    69,    20,    69,    69,    71,    72,    87,    12,    13,
      14,    15,    16,    17,    18,    19,    46,    55,    65,    95,
      96,    99,   107,   108,   109,    13,    37,    94,    95,    13,
      13,    14,    66,    73,    13,    74,    75,    47,    48,    13,
      43,    71,    71,     8,    62,   107,   108,   109,   109,    22,
      23,    66,     3,     4,     5,     6,    52,    53,    54,    55,
      56,    57,    58,    39,    66,    48,    66,    66,    60,    13,
      82,    83,    45,    62,    60,    61,   107,    12,    13,    14,
      15,    17,    18,    19,    49,    50,    76,    80,    85,    86,
     107,    48,    13,    13,    14,    50,    81,    47,    66,    95,
      95,    33,   100,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,    12,    13,    14,    15,    50,   104,
     105,    46,    50,    72,    92,    93,    97,    98,   102,   110,
      26,    49,    73,    88,    89,    90,    60,    60,    45,    62,
      60,    61,    76,    14,    77,    74,    60,     8,    62,    13,
      64,    61,    88,    62,    62,    13,    63,   109,   110,    28,
      62,    13,    66,    64,    13,    13,   110,   110,    32,    73,
      13,    64,    61,    76,    14,    84,    82,    63,    13,    81,
      48,    60,    85,    64,    81,    81,    48,     8,    36,    34,
     101,    81,    48,   106,   110,    13,   105,    47,    62,    48,
      13,    62,   110,    89,    63,    45,    62,    63,    80,    24,
      40,    72,    91,    92,    63,    63,    80,    13,   110,    63,
      80,   107,    81,    80,    62,    63,    21,    45,    62,    78,
      81,     8,    64,    76,   107,    65,    91,    21,    91,    64,
      62,    35,    64,    60,    63,    64,    63,    78,    76,    79,
      63,    13,    60,    60,    13,    14,    66,    81,    47,    60,
      61,    63,    62,    91,    91,    66,    66,    60,    63,   107,
      79,    81,    60,    60,    60,    63
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
      91,    91,    91,    92,    92,    92,    92,    92,    92,    93,
      94,    95,    95,    95,    96,    96,    97,    98,    98,    99,
     100,   101,   102,   103,   104,   104,   105,   105,   105,   105,
     105,   105,   106,   107,   107,   108,   108,   108,   108,   108,
     108,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   110,   110,   110,   110,   111,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   113
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
       4,     5,     5,     5,     8,     6,     1,     1,     1,     6,
       1,     1,     3,     3,     2,     1,     1,     5,     7,     1,
       3,     3,     3,     6,     1,     3,     1,     1,     1,     1,
       5,     4,     1,     1,     4,     1,     4,     3,     6,     6,
       9,     3,     3,     3,     3,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       5,     6,     4,     5,     5,     1
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
#line 1643 "parser.cpp"
    break;

  case 3:
#line 47 "parser.y"
    { printf("Reached start symbol.\n"); }
#line 1649 "parser.cpp"
    break;

  case 4:
#line 50 "parser.y"
    { PRINT_RULE }
#line 1655 "parser.cpp"
    break;

  case 5:
#line 51 "parser.y"
    { PRINT_RULE }
#line 1661 "parser.cpp"
    break;

  case 6:
#line 52 "parser.y"
    { PRINT_RULE }
#line 1667 "parser.cpp"
    break;

  case 7:
#line 53 "parser.y"
    { PRINT_RULE }
#line 1673 "parser.cpp"
    break;

  case 8:
#line 54 "parser.y"
    { PRINT_RULE }
#line 1679 "parser.cpp"
    break;

  case 9:
#line 55 "parser.y"
    { PRINT_RULE }
#line 1685 "parser.cpp"
    break;

  case 10:
#line 58 "parser.y"
    { PRINT_RULE }
#line 1691 "parser.cpp"
    break;

  case 11:
#line 63 "parser.y"
    { PRINT_RULE }
#line 1697 "parser.cpp"
    break;

  case 12:
#line 64 "parser.y"
    { PRINT_RULE }
#line 1703 "parser.cpp"
    break;

  case 13:
#line 65 "parser.y"
    { PRINT_RULE }
#line 1709 "parser.cpp"
    break;

  case 14:
#line 66 "parser.y"
    { PRINT_RULE }
#line 1715 "parser.cpp"
    break;

  case 15:
#line 71 "parser.y"
    { PRINT_RULE }
#line 1721 "parser.cpp"
    break;

  case 16:
#line 72 "parser.y"
    { PRINT_RULE }
#line 1727 "parser.cpp"
    break;

  case 17:
#line 77 "parser.y"
    { PRINT_RULE }
#line 1733 "parser.cpp"
    break;

  case 18:
#line 78 "parser.y"
    { PRINT_RULE }
#line 1739 "parser.cpp"
    break;

  case 19:
#line 79 "parser.y"
    { PRINT_RULE }
#line 1745 "parser.cpp"
    break;

  case 20:
#line 80 "parser.y"
    { PRINT_RULE }
#line 1751 "parser.cpp"
    break;

  case 21:
#line 81 "parser.y"
    { PRINT_RULE }
#line 1757 "parser.cpp"
    break;

  case 22:
#line 82 "parser.y"
    { PRINT_RULE }
#line 1763 "parser.cpp"
    break;

  case 23:
#line 87 "parser.y"
    { PRINT_RULE }
#line 1769 "parser.cpp"
    break;

  case 24:
#line 88 "parser.y"
    { PRINT_RULE }
#line 1775 "parser.cpp"
    break;

  case 25:
#line 93 "parser.y"
    { PRINT_RULE }
#line 1781 "parser.cpp"
    break;

  case 26:
#line 94 "parser.y"
    { PRINT_RULE }
#line 1787 "parser.cpp"
    break;

  case 27:
#line 95 "parser.y"
    { PRINT_RULE }
#line 1793 "parser.cpp"
    break;

  case 28:
#line 96 "parser.y"
    { PRINT_RULE }
#line 1799 "parser.cpp"
    break;

  case 29:
#line 101 "parser.y"
    { PRINT_RULE }
#line 1805 "parser.cpp"
    break;

  case 30:
#line 102 "parser.y"
    { PRINT_RULE }
#line 1811 "parser.cpp"
    break;

  case 31:
#line 103 "parser.y"
    { PRINT_RULE }
#line 1817 "parser.cpp"
    break;

  case 32:
#line 104 "parser.y"
    { PRINT_RULE }
#line 1823 "parser.cpp"
    break;

  case 33:
#line 105 "parser.y"
    { PRINT_RULE }
#line 1829 "parser.cpp"
    break;

  case 34:
#line 106 "parser.y"
    { PRINT_RULE }
#line 1835 "parser.cpp"
    break;

  case 35:
#line 107 "parser.y"
    { PRINT_RULE }
#line 1841 "parser.cpp"
    break;

  case 36:
#line 108 "parser.y"
    { PRINT_RULE }
#line 1847 "parser.cpp"
    break;

  case 37:
#line 109 "parser.y"
    { PRINT_RULE }
#line 1853 "parser.cpp"
    break;

  case 38:
#line 110 "parser.y"
    { PRINT_RULE }
#line 1859 "parser.cpp"
    break;

  case 39:
#line 111 "parser.y"
    { PRINT_RULE }
#line 1865 "parser.cpp"
    break;

  case 40:
#line 112 "parser.y"
    { PRINT_RULE }
#line 1871 "parser.cpp"
    break;

  case 41:
#line 113 "parser.y"
    { PRINT_RULE }
#line 1877 "parser.cpp"
    break;

  case 42:
#line 114 "parser.y"
    { PRINT_RULE }
#line 1883 "parser.cpp"
    break;

  case 43:
#line 119 "parser.y"
    { PRINT_RULE /*s-ar putea sa ne vina mai usor daca facem vector size nul direct din regula fara eps pentru ca sa identificam noi nr de param*/}
#line 1889 "parser.cpp"
    break;

  case 44:
#line 120 "parser.y"
    { PRINT_RULE }
#line 1895 "parser.cpp"
    break;

  case 45:
#line 125 "parser.y"
    { PRINT_RULE }
#line 1901 "parser.cpp"
    break;

  case 46:
#line 130 "parser.y"
    { PRINT_RULE }
#line 1907 "parser.cpp"
    break;

  case 47:
#line 131 "parser.y"
    { PRINT_RULE }
#line 1913 "parser.cpp"
    break;

  case 48:
#line 136 "parser.y"
    { PRINT_RULE }
#line 1919 "parser.cpp"
    break;

  case 49:
#line 137 "parser.y"
    { PRINT_RULE }
#line 1925 "parser.cpp"
    break;

  case 50:
#line 142 "parser.y"
    { PRINT_RULE }
#line 1931 "parser.cpp"
    break;

  case 51:
#line 143 "parser.y"
    { PRINT_RULE }
#line 1937 "parser.cpp"
    break;

  case 52:
#line 144 "parser.y"
    { PRINT_RULE }
#line 1943 "parser.cpp"
    break;

  case 53:
#line 145 "parser.y"
    { PRINT_RULE }
#line 1949 "parser.cpp"
    break;

  case 54:
#line 150 "parser.y"
    { PRINT_RULE }
#line 1955 "parser.cpp"
    break;

  case 55:
#line 151 "parser.y"
    { PRINT_RULE }
#line 1961 "parser.cpp"
    break;

  case 56:
#line 156 "parser.y"
    { PRINT_RULE }
#line 1967 "parser.cpp"
    break;

  case 57:
#line 157 "parser.y"
    { PRINT_RULE }
#line 1973 "parser.cpp"
    break;

  case 58:
#line 162 "parser.y"
    { PRINT_RULE }
#line 1979 "parser.cpp"
    break;

  case 59:
#line 167 "parser.y"
    { PRINT_RULE }
#line 1985 "parser.cpp"
    break;

  case 60:
#line 168 "parser.y"
    { PRINT_RULE }
#line 1991 "parser.cpp"
    break;

  case 61:
#line 173 "parser.y"
    {/*nu stiu daca aici este corect, dar eu presupun ca da*/ PRINT_RULE }
#line 1997 "parser.cpp"
    break;

  case 62:
#line 178 "parser.y"
    { PRINT_RULE }
#line 2003 "parser.cpp"
    break;

  case 63:
#line 179 "parser.y"
    { PRINT_RULE }
#line 2009 "parser.cpp"
    break;

  case 64:
#line 184 "parser.y"
    { PRINT_RULE }
#line 2015 "parser.cpp"
    break;

  case 65:
#line 185 "parser.y"
    { PRINT_RULE }
#line 2021 "parser.cpp"
    break;

  case 66:
#line 190 "parser.y"
    { PRINT_RULE }
#line 2027 "parser.cpp"
    break;

  case 67:
#line 191 "parser.y"
    { PRINT_RULE }
#line 2033 "parser.cpp"
    break;

  case 68:
#line 196 "parser.y"
    { PRINT_RULE }
#line 2039 "parser.cpp"
    break;

  case 69:
#line 197 "parser.y"
    { PRINT_RULE }
#line 2045 "parser.cpp"
    break;

  case 70:
#line 198 "parser.y"
    { PRINT_RULE }
#line 2051 "parser.cpp"
    break;

  case 71:
#line 199 "parser.y"
    { PRINT_RULE }
#line 2057 "parser.cpp"
    break;

  case 72:
#line 204 "parser.y"
    { PRINT_RULE }
#line 2063 "parser.cpp"
    break;

  case 73:
#line 205 "parser.y"
    { PRINT_RULE }
#line 2069 "parser.cpp"
    break;

  case 74:
#line 206 "parser.y"
    { PRINT_RULE }
#line 2075 "parser.cpp"
    break;

  case 75:
#line 207 "parser.y"
    { PRINT_RULE }
#line 2081 "parser.cpp"
    break;

  case 76:
#line 208 "parser.y"
    { PRINT_RULE }
#line 2087 "parser.cpp"
    break;

  case 77:
#line 209 "parser.y"
    { PRINT_RULE }
#line 2093 "parser.cpp"
    break;

  case 78:
#line 210 "parser.y"
    { PRINT_RULE }
#line 2099 "parser.cpp"
    break;

  case 79:
#line 211 "parser.y"
    { PRINT_RULE }
#line 2105 "parser.cpp"
    break;

  case 80:
#line 212 "parser.y"
    { PRINT_RULE }
#line 2111 "parser.cpp"
    break;

  case 81:
#line 213 "parser.y"
    { PRINT_RULE }
#line 2117 "parser.cpp"
    break;

  case 82:
#line 214 "parser.y"
    { PRINT_RULE }
#line 2123 "parser.cpp"
    break;

  case 83:
#line 219 "parser.y"
    { PRINT_RULE }
#line 2129 "parser.cpp"
    break;

  case 84:
#line 220 "parser.y"
    { PRINT_RULE }
#line 2135 "parser.cpp"
    break;

  case 85:
#line 221 "parser.y"
    { PRINT_RULE }
#line 2141 "parser.cpp"
    break;

  case 86:
#line 222 "parser.y"
    { PRINT_RULE }
#line 2147 "parser.cpp"
    break;

  case 87:
#line 223 "parser.y"
    { PRINT_RULE }
#line 2153 "parser.cpp"
    break;

  case 88:
#line 224 "parser.y"
    { PRINT_RULE }
#line 2159 "parser.cpp"
    break;

  case 89:
#line 229 "parser.y"
    { PRINT_RULE }
#line 2165 "parser.cpp"
    break;

  case 90:
#line 234 "parser.y"
    { PRINT_RULE }
#line 2171 "parser.cpp"
    break;

  case 91:
#line 239 "parser.y"
    { PRINT_RULE }
#line 2177 "parser.cpp"
    break;

  case 92:
#line 240 "parser.y"
    { PRINT_RULE }
#line 2183 "parser.cpp"
    break;

  case 93:
#line 241 "parser.y"
    { PRINT_RULE }
#line 2189 "parser.cpp"
    break;

  case 94:
#line 246 "parser.y"
    { PRINT_RULE }
#line 2195 "parser.cpp"
    break;

  case 95:
#line 247 "parser.y"
    { PRINT_RULE }
#line 2201 "parser.cpp"
    break;

  case 96:
#line 252 "parser.y"
    {/*de asemenea nu stiu daca este ok ce fac aicea*/ PRINT_RULE }
#line 2207 "parser.cpp"
    break;

  case 97:
#line 257 "parser.y"
    { PRINT_RULE }
#line 2213 "parser.cpp"
    break;

  case 98:
#line 258 "parser.y"
    { PRINT_RULE }
#line 2219 "parser.cpp"
    break;

  case 99:
#line 263 "parser.y"
    { PRINT_RULE }
#line 2225 "parser.cpp"
    break;

  case 100:
#line 268 "parser.y"
    { PRINT_RULE }
#line 2231 "parser.cpp"
    break;

  case 101:
#line 273 "parser.y"
    { PRINT_RULE }
#line 2237 "parser.cpp"
    break;

  case 102:
#line 278 "parser.y"
    { PRINT_RULE }
#line 2243 "parser.cpp"
    break;

  case 103:
#line 283 "parser.y"
    { PRINT_RULE }
#line 2249 "parser.cpp"
    break;

  case 104:
#line 288 "parser.y"
    { PRINT_RULE }
#line 2255 "parser.cpp"
    break;

  case 105:
#line 289 "parser.y"
    { PRINT_RULE }
#line 2261 "parser.cpp"
    break;

  case 106:
#line 294 "parser.y"
    { PRINT_RULE }
#line 2267 "parser.cpp"
    break;

  case 107:
#line 295 "parser.y"
    { PRINT_RULE }
#line 2273 "parser.cpp"
    break;

  case 108:
#line 296 "parser.y"
    { PRINT_RULE }
#line 2279 "parser.cpp"
    break;

  case 109:
#line 297 "parser.y"
    { PRINT_RULE }
#line 2285 "parser.cpp"
    break;

  case 110:
#line 298 "parser.y"
    { PRINT_RULE }
#line 2291 "parser.cpp"
    break;

  case 111:
#line 299 "parser.y"
    { PRINT_RULE }
#line 2297 "parser.cpp"
    break;

  case 112:
#line 304 "parser.y"
    { PRINT_RULE }
#line 2303 "parser.cpp"
    break;

  case 113:
#line 309 "parser.y"
    { PRINT_RULE }
#line 2309 "parser.cpp"
    break;

  case 114:
#line 310 "parser.y"
    { PRINT_RULE }
#line 2315 "parser.cpp"
    break;

  case 115:
#line 313 "parser.y"
    { PRINT_RULE }
#line 2321 "parser.cpp"
    break;

  case 116:
#line 314 "parser.y"
    { PRINT_RULE }
#line 2327 "parser.cpp"
    break;

  case 117:
#line 315 "parser.y"
    { PRINT_RULE }
#line 2333 "parser.cpp"
    break;

  case 118:
#line 316 "parser.y"
    { PRINT_RULE }
#line 2339 "parser.cpp"
    break;

  case 119:
#line 317 "parser.y"
    { PRINT_RULE }
#line 2345 "parser.cpp"
    break;

  case 120:
#line 318 "parser.y"
    { PRINT_RULE }
#line 2351 "parser.cpp"
    break;

  case 121:
#line 321 "parser.y"
    { PRINT_RULE }
#line 2357 "parser.cpp"
    break;

  case 122:
#line 322 "parser.y"
    { PRINT_RULE }
#line 2363 "parser.cpp"
    break;

  case 123:
#line 323 "parser.y"
    { PRINT_RULE }
#line 2369 "parser.cpp"
    break;

  case 124:
#line 324 "parser.y"
    { PRINT_RULE }
#line 2375 "parser.cpp"
    break;

  case 125:
#line 325 "parser.y"
    { PRINT_RULE }
#line 2381 "parser.cpp"
    break;

  case 126:
#line 326 "parser.y"
    { PRINT_RULE }
#line 2387 "parser.cpp"
    break;

  case 127:
#line 327 "parser.y"
    { PRINT_RULE }
#line 2393 "parser.cpp"
    break;

  case 128:
#line 328 "parser.y"
    { PRINT_RULE }
#line 2399 "parser.cpp"
    break;

  case 129:
#line 329 "parser.y"
    { PRINT_RULE }
#line 2405 "parser.cpp"
    break;

  case 130:
#line 330 "parser.y"
    { PRINT_RULE }
#line 2411 "parser.cpp"
    break;

  case 131:
#line 331 "parser.y"
    { PRINT_RULE }
#line 2417 "parser.cpp"
    break;

  case 132:
#line 332 "parser.y"
    { PRINT_RULE }
#line 2423 "parser.cpp"
    break;

  case 133:
#line 333 "parser.y"
    { PRINT_RULE }
#line 2429 "parser.cpp"
    break;

  case 134:
#line 334 "parser.y"
    { PRINT_RULE }
#line 2435 "parser.cpp"
    break;

  case 135:
#line 335 "parser.y"
    { PRINT_RULE }
#line 2441 "parser.cpp"
    break;

  case 136:
#line 336 "parser.y"
    { PRINT_RULE }
#line 2447 "parser.cpp"
    break;

  case 137:
#line 337 "parser.y"
    { PRINT_RULE }
#line 2453 "parser.cpp"
    break;

  case 138:
#line 338 "parser.y"
    { PRINT_RULE }
#line 2459 "parser.cpp"
    break;

  case 139:
#line 339 "parser.y"
    { PRINT_RULE }
#line 2465 "parser.cpp"
    break;

  case 140:
#line 340 "parser.y"
    { PRINT_RULE }
#line 2471 "parser.cpp"
    break;

  case 141:
#line 343 "parser.y"
    { PRINT_RULE }
#line 2477 "parser.cpp"
    break;

  case 142:
#line 344 "parser.y"
    { PRINT_RULE }
#line 2483 "parser.cpp"
    break;

  case 143:
#line 345 "parser.y"
    { PRINT_RULE }
#line 2489 "parser.cpp"
    break;

  case 144:
#line 346 "parser.y"
    { PRINT_RULE }
#line 2495 "parser.cpp"
    break;

  case 145:
#line 351 "parser.y"
    { PRINT_RULE }
#line 2501 "parser.cpp"
    break;

  case 146:
#line 356 "parser.y"
    { PRINT_RULE }
#line 2507 "parser.cpp"
    break;

  case 147:
#line 357 "parser.y"
    { PRINT_RULE }
#line 2513 "parser.cpp"
    break;

  case 148:
#line 358 "parser.y"
    { PRINT_RULE }
#line 2519 "parser.cpp"
    break;

  case 149:
#line 359 "parser.y"
    { PRINT_RULE }
#line 2525 "parser.cpp"
    break;

  case 150:
#line 360 "parser.y"
    { PRINT_RULE }
#line 2531 "parser.cpp"
    break;

  case 151:
#line 361 "parser.y"
    { PRINT_RULE }
#line 2537 "parser.cpp"
    break;

  case 152:
#line 362 "parser.y"
    { PRINT_RULE }
#line 2543 "parser.cpp"
    break;

  case 153:
#line 363 "parser.y"
    { PRINT_RULE }
#line 2549 "parser.cpp"
    break;

  case 154:
#line 364 "parser.y"
    { PRINT_RULE }
#line 2555 "parser.cpp"
    break;

  case 155:
#line 369 "parser.y"
    { PRINT_RULE }
#line 2561 "parser.cpp"
    break;


#line 2565 "parser.cpp"

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
