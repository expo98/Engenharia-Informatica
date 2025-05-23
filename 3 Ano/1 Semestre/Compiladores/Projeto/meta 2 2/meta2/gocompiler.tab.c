/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "gocompiler.y"

    /*
        Carlos Manuel Gomes da Fonseca Augusto Pereira - 2022232042
        Miguel Teixeira de Pina Monteiro Pereira - 2022232552
    */

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "ast.h"
    
    int yylex(void);
    void yyerror(char *s);

    struct no *raiz = NULL;
    struct no *aux = NULL;
    int counter = 0;


#line 91 "gocompiler.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "gocompiler.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_COMMA = 4,                      /* COMMA  */
  YYSYMBOL_LBRACE = 5,                     /* LBRACE  */
  YYSYMBOL_RBRACE = 6,                     /* RBRACE  */
  YYSYMBOL_LPAR = 7,                       /* LPAR  */
  YYSYMBOL_RPAR = 8,                       /* RPAR  */
  YYSYMBOL_LSQ = 9,                        /* LSQ  */
  YYSYMBOL_RSQ = 10,                       /* RSQ  */
  YYSYMBOL_STAR = 11,                      /* STAR  */
  YYSYMBOL_DIV = 12,                       /* DIV  */
  YYSYMBOL_MINUS = 13,                     /* MINUS  */
  YYSYMBOL_PLUS = 14,                      /* PLUS  */
  YYSYMBOL_GE = 15,                        /* GE  */
  YYSYMBOL_GT = 16,                        /* GT  */
  YYSYMBOL_LE = 17,                        /* LE  */
  YYSYMBOL_LT = 18,                        /* LT  */
  YYSYMBOL_NE = 19,                        /* NE  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_VAR = 21,                       /* VAR  */
  YYSYMBOL_MOD = 22,                       /* MOD  */
  YYSYMBOL_NOT = 23,                       /* NOT  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_INT = 26,                       /* INT  */
  YYSYMBOL_FLOAT32 = 27,                   /* FLOAT32  */
  YYSYMBOL_BOOL = 28,                      /* BOOL  */
  YYSYMBOL_STRING = 29,                    /* STRING  */
  YYSYMBOL_RETURN = 30,                    /* RETURN  */
  YYSYMBOL_PACKAGE = 31,                   /* PACKAGE  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_IF = 33,                        /* IF  */
  YYSYMBOL_FOR = 34,                       /* FOR  */
  YYSYMBOL_ASSIGN = 35,                    /* ASSIGN  */
  YYSYMBOL_PARSEINT = 36,                  /* PARSEINT  */
  YYSYMBOL_CMDARGS = 37,                   /* CMDARGS  */
  YYSYMBOL_FUNC = 38,                      /* FUNC  */
  YYSYMBOL_BLANKID = 39,                   /* BLANKID  */
  YYSYMBOL_PRINT = 40,                     /* PRINT  */
  YYSYMBOL_IDENTIFIER = 41,                /* IDENTIFIER  */
  YYSYMBOL_RESERVED = 42,                  /* RESERVED  */
  YYSYMBOL_NATURAL = 43,                   /* NATURAL  */
  YYSYMBOL_DECIMAL = 44,                   /* DECIMAL  */
  YYSYMBOL_STRLIT = 45,                    /* STRLIT  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_Program = 47,                   /* Program  */
  YYSYMBOL_Declarations = 48,              /* Declarations  */
  YYSYMBOL_VarDeclaration = 49,            /* VarDeclaration  */
  YYSYMBOL_VarsSpec = 50,                  /* VarsSpec  */
  YYSYMBOL_Type = 51,                      /* Type  */
  YYSYMBOL_FuncDeclaration = 52,           /* FuncDeclaration  */
  YYSYMBOL_FuncParams = 53,                /* FuncParams  */
  YYSYMBOL_COMMAID = 54,                   /* COMMAID  */
  YYSYMBOL_FuncBody = 55,                  /* FuncBody  */
  YYSYMBOL_VarsAndStatement = 56,          /* VarsAndStatement  */
  YYSYMBOL_Statement = 57,                 /* Statement  */
  YYSYMBOL_StatementSC = 58,               /* StatementSC  */
  YYSYMBOL_ParseArgs = 59,                 /* ParseArgs  */
  YYSYMBOL_FuncInvocation = 60,            /* FuncInvocation  */
  YYSYMBOL_Expr2 = 61,                     /* Expr2  */
  YYSYMBOL_Expr = 62                       /* Expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   499

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    78,    78,    81,    82,    83,    86,    87,    91,    96,
      96,    96,    96,    99,   107,   115,   125,   136,   144,   152,
     158,   164,   168,   169,   170,   171,   174,   175,   189,   191,
     197,   204,   211,   218,   226,   231,   235,   239,   244,   245,
     246,   247,   248,   252,   253,   258,   262,   268,   273,   282,
     283,   284,   289,   290,   293,   298,   303,   308,   313,   318,
     323,   328,   333,   338,   343,   348,   353,   358,   362,   366,
     370,   371,   372,   373,   375,   376
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "COMMA",
  "LBRACE", "RBRACE", "LPAR", "RPAR", "LSQ", "RSQ", "STAR", "DIV", "MINUS",
  "PLUS", "GE", "GT", "LE", "LT", "NE", "EQ", "VAR", "MOD", "NOT", "AND",
  "OR", "INT", "FLOAT32", "BOOL", "STRING", "RETURN", "PACKAGE", "ELSE",
  "IF", "FOR", "ASSIGN", "PARSEINT", "CMDARGS", "FUNC", "BLANKID", "PRINT",
  "IDENTIFIER", "RESERVED", "NATURAL", "DECIMAL", "STRLIT", "$accept",
  "Program", "Declarations", "VarDeclaration", "VarsSpec", "Type",
  "FuncDeclaration", "FuncParams", "COMMAID", "FuncBody",
  "VarsAndStatement", "Statement", "StatementSC", "ParseArgs",
  "FuncInvocation", "Expr2", "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-63)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -27,   -36,    19,    23,   -63,   -63,   -18,     7,    -9,    30,
      38,    12,    32,   -63,    49,   -63,   -63,    59,   -63,   -63,
     -63,   -63,   -63,     9,    56,    76,    32,    77,   -63,   -63,
      81,   -63,    84,    76,   119,   -63,    51,   -63,    81,   -63,
     -63,   -63,   128,   -63,   321,   321,   308,    83,    20,    90,
     -63,   -63,   -63,    32,   -63,   -63,    95,   140,    94,   321,
     321,   321,    93,   -63,   -63,   -63,   448,   371,   142,   387,
     313,    67,     8,   321,   -63,    84,   -63,   -63,   106,   104,
     402,   -63,   -63,   448,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   183,   -63,   185,
     197,   105,   417,    88,   110,   321,   -63,   118,   355,   448,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   143,   143,
     143,   143,   143,   143,   -63,   477,   463,    96,   199,   -63,
     -63,   240,   -63,   -63,    91,   -63,   448,   -63,   243,   125,
      99,   -63,   129,   -63,   258,   127,     0,   -63,   270,     6,
     134,   135,   -63,   284,   -63,   321,   -63,   433,   155,   -63
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     5,     2,     0,     0,     0,
       0,     0,     0,     6,     0,     4,     3,     0,     9,    10,
      11,    12,     8,     0,     0,     0,     0,     0,     7,    25,
       0,    16,    18,     0,     0,    15,     0,    17,     0,    14,
      44,    22,     0,    21,    39,     0,     0,     0,     0,     0,
      24,    40,    43,     0,    13,    28,     0,     0,     0,     0,
       0,     0,    70,    71,    72,    73,    38,     0,     0,     0,
       0,     0,     0,     0,    23,    20,    46,    27,     0,     0,
       0,    68,    69,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    35,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,    26,
      19,    45,    75,    74,    64,    65,    63,    62,    56,    57,
      58,    59,    60,    61,    66,    55,    54,    29,     0,    34,
      36,     0,    42,    41,     0,    49,    52,    50,     0,     0,
      30,    37,     0,    53,     0,     0,     0,    31,     0,     0,
       0,     0,    32,     0,    48,     0,    33,     0,     0,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   -63,   -63,   116,   153,    58,   -63,   -63,    92,   -20,
     -63,   -32,   -62,   -63,   -34,    13,   -16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     6,     9,    13,    22,    10,    27,    37,    31,
      34,    56,    57,    51,    65,   107,   108
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      52,   150,    50,     7,     1,     3,    99,    40,    52,   104,
      35,    42,   105,    39,    11,    58,   106,    25,    54,     4,
       8,    59,    60,    52,    71,    78,     5,    72,    66,    67,
      69,    61,    14,    15,    52,   128,    44,   151,   131,    45,
      46,    16,    80,    81,    82,    83,    47,    48,    12,    62,
      26,    63,    64,    12,   102,    73,    23,   109,    18,    19,
      20,    21,    24,    52,    28,    52,    52,    78,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    29,   148,    30,    32,    33,    29,   153,    36,   136,
      70,    38,    53,    74,    52,    79,    78,    52,    76,    78,
      72,    58,    18,    19,    20,    21,   103,    59,    60,   111,
      52,    75,   112,   132,    52,    52,    78,    61,   135,    52,
      40,    78,    41,   134,    42,    43,   137,   142,   139,    40,
     144,   145,   149,    42,    55,    62,   146,    63,    64,   157,
       7,    40,   154,    40,   155,    42,    77,    42,    98,    44,
      49,   143,    45,    46,    84,    85,    86,    87,    44,    47,
      48,    45,    46,   159,    17,    94,     0,   110,    47,    48,
      44,     0,    44,    45,    46,    45,    46,     0,     0,     0,
      47,    48,    47,    48,    40,     0,    40,     0,    42,   127,
      42,   129,     0,     0,     0,     0,     0,     0,    40,     0,
      40,     0,    42,   130,    42,   140,     0,     0,     0,     0,
       0,     0,     0,    44,     0,    44,    45,    46,    45,    46,
       0,     0,     0,    47,    48,    47,    48,    44,     0,    44,
      45,    46,    45,    46,     0,     0,     0,    47,    48,    47,
      48,    40,     0,     0,     0,    42,   141,   105,     0,     0,
      58,     0,     0,     0,     0,     0,    59,    60,     0,    40,
       0,     0,     0,    42,   147,     0,    61,     0,     0,     0,
      44,    40,     0,    45,    46,    42,   152,     0,     0,     0,
      47,    48,     0,     0,    62,    40,    63,    64,    44,    42,
     156,    45,    46,     0,     0,     0,     0,     0,    47,    48,
      44,     0,     0,    45,    46,     0,     0,     0,     0,     0,
      47,    48,     0,    68,    44,    58,     0,    45,    46,     0,
      58,    59,    60,     0,    47,    48,    59,    60,    58,     0,
       0,    61,     0,     0,    59,    60,    61,     0,     0,     0,
       0,     0,     0,     0,    61,     0,     0,     0,     0,    62,
       0,    63,    64,     0,    62,     0,    63,    64,   101,   138,
       0,     0,    62,     0,    63,    64,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    97,    94,     0,    95,
      96,     0,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,   100,    94,     0,    95,    96,     0,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,    94,
     113,    95,    96,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,     0,    94,   133,    95,    96,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,    94,
       0,    95,    96,   158,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     0,    94,     0,    95,    96,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,     0,
      94,     0,    95,    96,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     0,    94,     0,    95,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,    94
};

static const yytype_int16 yycheck[] =
{
      34,     1,    34,    21,    31,    41,    68,     1,    42,     1,
      30,     5,     4,    33,     7,     7,     8,     8,    38,     0,
      38,    13,    14,    57,     4,    57,     3,     7,    44,    45,
      46,    23,    41,     3,    68,    97,    30,    37,   100,    33,
      34,     3,    58,    59,    60,    61,    40,    41,    41,    41,
      41,    43,    44,    41,    70,    35,     7,    73,    26,    27,
      28,    29,     3,    97,     8,    99,   100,    99,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,     5,   144,    25,    26,     8,     5,   149,     4,   105,
       7,    33,    41,     3,   128,     1,   128,   131,     3,   131,
       7,     7,    26,    27,    28,    29,    39,    13,    14,     3,
     144,    53,     8,     8,   148,   149,   148,    23,     8,   153,
       1,   153,     3,    35,     5,     6,     8,    36,    32,     1,
       5,    32,     5,     5,     6,    41,     7,    43,    44,   155,
      21,     1,     8,     1,     9,     5,     6,     5,     6,    30,
      34,   138,    33,    34,    11,    12,    13,    14,    30,    40,
      41,    33,    34,     8,    11,    22,    -1,    75,    40,    41,
      30,    -1,    30,    33,    34,    33,    34,    -1,    -1,    -1,
      40,    41,    40,    41,     1,    -1,     1,    -1,     5,     6,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       1,    -1,     5,     6,     5,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    30,    33,    34,    33,    34,
      -1,    -1,    -1,    40,    41,    40,    41,    30,    -1,    30,
      33,    34,    33,    34,    -1,    -1,    -1,    40,    41,    40,
      41,     1,    -1,    -1,    -1,     5,     6,     4,    -1,    -1,
       7,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,     1,
      -1,    -1,    -1,     5,     6,    -1,    23,    -1,    -1,    -1,
      30,     1,    -1,    33,    34,     5,     6,    -1,    -1,    -1,
      40,    41,    -1,    -1,    41,     1,    43,    44,    30,     5,
       6,    33,    34,    -1,    -1,    -1,    -1,    -1,    40,    41,
      30,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,
      40,    41,    -1,     5,    30,     7,    -1,    33,    34,    -1,
       7,    13,    14,    -1,    40,    41,    13,    14,     7,    -1,
      -1,    23,    -1,    -1,    13,    14,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    41,
      -1,    43,    44,    -1,    41,    -1,    43,    44,    45,     4,
      -1,    -1,    41,    -1,    43,    44,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     5,    22,    -1,    24,
      25,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     5,    22,    -1,    24,    25,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
       8,    24,    25,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,     8,    24,    25,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      -1,    24,    25,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    -1,    24,    25,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    -1,    24,    25,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    -1,    24,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    31,    47,    41,     0,     3,    48,    21,    38,    49,
      52,     7,    41,    50,    41,     3,     3,    50,    26,    27,
      28,    29,    51,     7,     3,     8,    41,    53,     8,     5,
      51,    55,    51,     8,    56,    55,     4,    54,    51,    55,
       1,     3,     5,     6,    30,    33,    34,    40,    41,    49,
      57,    59,    60,    41,    55,     6,    57,    58,     7,    13,
      14,    23,    41,    43,    44,    60,    62,    62,     5,    62,
       7,     4,     7,    35,     3,    51,     3,     6,    57,     1,
      62,    62,    62,    62,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    22,    24,    25,     5,     6,    58,
       5,    45,    62,    39,     1,     4,     8,    61,    62,    62,
      54,     3,     8,     8,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,     6,    58,     6,
       6,    58,     8,     8,    35,     8,    62,     8,     4,    32,
       6,     6,    36,    61,     5,    32,     7,     6,    58,     5,
       1,    37,     6,    58,     8,     9,     6,    62,    10,     8
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    49,    49,    50,    51,
      51,    51,    51,    52,    52,    52,    52,    53,    53,    54,
      54,    55,    56,    56,    56,    56,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    58,    58,    59,    59,    60,
      60,    60,    61,    61,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     3,     0,     2,     5,     2,     1,
       1,     1,     1,     7,     6,     6,     5,     3,     2,     4,
       3,     3,     2,     3,     2,     0,     3,     3,     2,     4,
       5,     7,     8,     9,     4,     3,     4,     5,     2,     1,
       1,     4,     4,     1,     1,     3,     2,    11,     8,     4,
       4,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       1,     1,     1,     1,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: PACKAGE IDENTIFIER SEMICOLON Declarations  */
#line 78 "gocompiler.y"
                                                   { raiz = novo_no("Program", NULL); (yyval.no) = raiz; add_filho((yyval.no), (yyvsp[0].no));}
#line 1305 "gocompiler.tab.c"
    break;

  case 3: /* Declarations: Declarations FuncDeclaration SEMICOLON  */
#line 81 "gocompiler.y"
                                                     {(yyval.no) = (yyvsp[-2].no); add_filho((yyval.no), (yyvsp[-1].no));}
#line 1311 "gocompiler.tab.c"
    break;

  case 4: /* Declarations: Declarations VarDeclaration SEMICOLON  */
#line 82 "gocompiler.y"
                                                    {(yyval.no) = (yyvsp[-2].no); add_filho((yyval.no), (yyvsp[-1].no));}
#line 1317 "gocompiler.tab.c"
    break;

  case 5: /* Declarations: %empty  */
#line 83 "gocompiler.y"
              {(yyval.no) = novo_no("temp", NULL);}
#line 1323 "gocompiler.tab.c"
    break;

  case 6: /* VarDeclaration: VAR VarsSpec  */
#line 86 "gocompiler.y"
                             {(yyval.no) = (yyvsp[0].no);}
#line 1329 "gocompiler.tab.c"
    break;

  case 7: /* VarDeclaration: VAR LPAR VarsSpec SEMICOLON RPAR  */
#line 87 "gocompiler.y"
                                               {(yyval.no) = (yyvsp[-2].no);}
#line 1335 "gocompiler.tab.c"
    break;

  case 8: /* VarsSpec: IDENTIFIER Type  */
#line 91 "gocompiler.y"
                         {(yyval.no) = novo_no("Identifier", NULL); add_filho((yyval.no), (yyvsp[-1].valor)); add_filho((yyval.no), (yyvsp[0].no));}
#line 1341 "gocompiler.tab.c"
    break;

  case 9: /* Type: INT  */
#line 96 "gocompiler.y"
          {(yyval.no) = novo_no("Int",NULL);}
#line 1347 "gocompiler.tab.c"
    break;

  case 10: /* Type: FLOAT32  */
#line 96 "gocompiler.y"
                                                {(yyval.no) = novo_no("Float32",NULL);}
#line 1353 "gocompiler.tab.c"
    break;

  case 11: /* Type: BOOL  */
#line 96 "gocompiler.y"
                                                                                       {(yyval.no) = novo_no("Bool",NULL);}
#line 1359 "gocompiler.tab.c"
    break;

  case 12: /* Type: STRING  */
#line 96 "gocompiler.y"
                                                                                                                             {(yyval.no) = novo_no("String",NULL);}
#line 1365 "gocompiler.tab.c"
    break;

  case 13: /* FuncDeclaration: FUNC IDENTIFIER LPAR FuncParams RPAR Type FuncBody  */
#line 99 "gocompiler.y"
                                                                    {(yyval.no)=novo_no("FuncDecl", NULL);
                                                            struct no *fheader = novo_no("FuncHeader", NULL);
                                                            add_filho((yyval.no), fheader);
                                                            add_irmao(fheader, (yyvsp[0].no));
                                                            add_filho(fheader, (yyvsp[-5].valor));
                                                            add_irmao((yyvsp[-1].no), (yyvsp[-3].no));
                                                            add_filho((yyvsp[-5].valor), (yyvsp[-1].no));
                                                            }
#line 1378 "gocompiler.tab.c"
    break;

  case 14: /* FuncDeclaration: FUNC IDENTIFIER LPAR FuncParams RPAR FuncBody  */
#line 107 "gocompiler.y"
                                                                 {(yyval.no)=novo_no("FuncDecl", NULL);
                                                            struct no *fheader = novo_no("FuncHeader", NULL);
                                                            add_filho((yyval.no), fheader);
                                                            add_irmao(fheader, (yyvsp[0].no));
                                                            add_filho(fheader, (yyvsp[-4].valor));
                                                            add_irmao((yyvsp[-4].valor), (yyvsp[-2].no));
                                                         
                                                            }
#line 1391 "gocompiler.tab.c"
    break;

  case 15: /* FuncDeclaration: FUNC IDENTIFIER LPAR RPAR Type FuncBody  */
#line 115 "gocompiler.y"
                                                          {(yyval.no)=novo_no("FuncDecl", NULL);
                                                            struct no *fheader = novo_no("FuncHeader", NULL);
                                                            aux = novo_no("FuncParams", NULL);
                                                            add_filho((yyval.no), fheader);
                                                            add_irmao(fheader, (yyvsp[0].no));
                                                            add_filho(fheader, (yyvsp[-4].valor));
                                                            add_irmao((yyvsp[-4].valor),(yyvsp[-1].no));
                                                            aux = novo_no("FuncParams", NULL);
                                                            add_irmao((yyvsp[-1].no), aux);
                                                            }
#line 1406 "gocompiler.tab.c"
    break;

  case 16: /* FuncDeclaration: FUNC IDENTIFIER LPAR RPAR FuncBody  */
#line 125 "gocompiler.y"
                                                     {(yyval.no)=novo_no("FuncDecl", NULL);
                                                             struct no *fheader = novo_no("FuncHeader", NULL);
                                                             add_filho((yyval.no), fheader);
                                                             add_filho(fheader, (yyvsp[-3].valor));
                                                             aux = novo_no("FuncParams", NULL);
                                                             add_irmao((yyvsp[-3].valor), aux);
                                                             add_irmao(fheader, (yyvsp[0].no));
                                                                }
#line 1419 "gocompiler.tab.c"
    break;

  case 17: /* FuncParams: IDENTIFIER Type COMMAID  */
#line 136 "gocompiler.y"
                                   {(yyval.no) = novo_no("FuncParams", NULL); 
                            aux = novo_no("ParamDecl", NULL);
                            add_filho((yyval.no), aux);
                            add_irmao(aux, (yyvsp[0].no));
                            add_filho(aux, (yyvsp[-1].no));
                            add_irmao((yyvsp[-1].no), (yyvsp[-2].valor));
                            
                            }
#line 1432 "gocompiler.tab.c"
    break;

  case 18: /* FuncParams: IDENTIFIER Type  */
#line 144 "gocompiler.y"
                                          {(yyval.no) = novo_no("FuncParams", NULL); 
                            aux = novo_no("ParamDecl", NULL);
                            add_filho((yyval.no), aux);
                            add_filho(aux, (yyvsp[0].no));
                            add_irmao((yyvsp[0].no), (yyvsp[-1].valor));
                            }
#line 1443 "gocompiler.tab.c"
    break;

  case 19: /* COMMAID: COMMA IDENTIFIER Type COMMAID  */
#line 152 "gocompiler.y"
                                       {
                                (yyval.no) = novo_no("ParamDecl", NULL);
                                add_filho((yyval.no), (yyvsp[-1].no));
                                add_irmao((yyvsp[-1].no), (yyvsp[-2].valor));
                                add_irmao((yyval.no), (yyvsp[0].no));
                                }
#line 1454 "gocompiler.tab.c"
    break;

  case 20: /* COMMAID: COMMA IDENTIFIER Type  */
#line 158 "gocompiler.y"
                               { (yyval.no) = novo_no("ParamDecl", NULL);
                                        add_filho((yyval.no), (yyvsp[0].no));
                                        add_irmao((yyvsp[0].no), (yyvsp[-1].valor));
                                        }
#line 1463 "gocompiler.tab.c"
    break;

  case 21: /* FuncBody: LBRACE VarsAndStatement RBRACE  */
#line 164 "gocompiler.y"
                                         {(yyval.no) = novo_no("FuncBody", NULL); add_filho((yyval.no), (yyvsp[-1].no));}
#line 1469 "gocompiler.tab.c"
    break;

  case 22: /* VarsAndStatement: VarsAndStatement SEMICOLON  */
#line 168 "gocompiler.y"
                                              {(yyval.no) = (yyvsp[-1].no);}
#line 1475 "gocompiler.tab.c"
    break;

  case 23: /* VarsAndStatement: VarsAndStatement VarDeclaration SEMICOLON  */
#line 169 "gocompiler.y"
                                                           {(yyval.no) = (yyvsp[-2].no); add_irmao((yyvsp[-2].no), (yyvsp[-1].no));}
#line 1481 "gocompiler.tab.c"
    break;

  case 24: /* VarsAndStatement: VarsAndStatement Statement  */
#line 170 "gocompiler.y"
                                             {(yyval.no) = (yyvsp[-1].no); add_irmao((yyvsp[-1].no), (yyvsp[0].no));}
#line 1487 "gocompiler.tab.c"
    break;

  case 25: /* VarsAndStatement: %empty  */
#line 171 "gocompiler.y"
                  {(yyval.no) = novo_no("NULL", NULL);}
#line 1493 "gocompiler.tab.c"
    break;

  case 26: /* Statement: IDENTIFIER ASSIGN Expr  */
#line 174 "gocompiler.y"
                                  { (yyval.no) = novo_no("Assign", NULL); add_filho((yyval.no),(yyvsp[-2].valor)); add_irmao((yyvsp[-2].valor),(yyvsp[0].no));}
#line 1499 "gocompiler.tab.c"
    break;

  case 27: /* Statement: LBRACE StatementSC RBRACE  */
#line 175 "gocompiler.y"
                           {
    aux = (yyvsp[-1].no);
    counter = 0;
    while(aux != NULL){
        counter++;
        aux = aux->irmao;
    }
    if(counter > 1){
        (yyval.no) = novo_no("Block", NULL);
        add_filho((yyval.no), (yyvsp[-1].no));
    }else{
        (yyval.no) = (yyvsp[-1].no);
    }
}
#line 1518 "gocompiler.tab.c"
    break;

  case 28: /* Statement: LBRACE RBRACE  */
#line 189 "gocompiler.y"
                {(yyval.no) = novo_no("Block", NULL);}
#line 1524 "gocompiler.tab.c"
    break;

  case 29: /* Statement: IF Expr LBRACE RBRACE  */
#line 191 "gocompiler.y"
                        { (yyval.no) = novo_no("If", NULL); add_filho((yyval.no), (yyvsp[-2].no));
                                                        aux = novo_no("Block", NULL);
                                                        add_irmao((yyvsp[-2].no), aux);
                                                        struct no *aux1 = novo_no("Block", NULL);
                                                        add_irmao(aux, aux1);
}
#line 1535 "gocompiler.tab.c"
    break;

  case 30: /* Statement: IF Expr LBRACE StatementSC RBRACE  */
#line 197 "gocompiler.y"
                                    { (yyval.no) = novo_no("If", NULL); add_filho((yyval.no), (yyvsp[-3].no));
                                                        aux = novo_no("Block", NULL);
                                                        add_irmao((yyvsp[-3].no), aux);
                                                        add_filho(aux, (yyvsp[-1].no));
                                                        struct no *aux1 = novo_no("Block", NULL);
                                                        add_irmao(aux, aux1);
}
#line 1547 "gocompiler.tab.c"
    break;

  case 31: /* Statement: IF Expr LBRACE RBRACE ELSE LBRACE RBRACE  */
#line 204 "gocompiler.y"
                                           { (yyval.no) = novo_no("If", NULL); add_filho((yyval.no), (yyvsp[-5].no));
                                                        aux = novo_no("Block", NULL);
                                                        add_irmao((yyvsp[-5].no), aux);
                                                        struct no *aux1 = novo_no("Block", NULL);
                                                        add_irmao(aux, aux1);
                                                        
}
#line 1559 "gocompiler.tab.c"
    break;

  case 32: /* Statement: IF Expr LBRACE RBRACE ELSE LBRACE StatementSC RBRACE  */
#line 211 "gocompiler.y"
                                                       { (yyval.no) = novo_no("If", NULL); add_filho((yyval.no), (yyvsp[-6].no));
                                                        aux = novo_no("Block", NULL);
                                                        struct no *aux1 = novo_no("Block", NULL);
                                                        add_irmao((yyvsp[-6].no), aux);
                                                        add_irmao(aux, aux1);
                                                        add_filho(aux1, (yyvsp[-1].no));
}
#line 1571 "gocompiler.tab.c"
    break;

  case 33: /* Statement: IF Expr LBRACE StatementSC RBRACE ELSE LBRACE StatementSC RBRACE  */
#line 218 "gocompiler.y"
                                                                  { (yyval.no) = novo_no("If", NULL); add_filho((yyval.no), (yyvsp[-7].no));
                                                        aux = novo_no("Block", NULL);
                                                        struct no *aux1 = novo_no("Block", NULL);
                                                        add_irmao((yyvsp[-7].no), aux);
                                                        add_filho(aux, (yyvsp[-5].no));
                                                        add_irmao(aux, aux1);
                                                        add_filho(aux1, (yyvsp[-1].no));
}
#line 1584 "gocompiler.tab.c"
    break;

  case 34: /* Statement: FOR LBRACE StatementSC RBRACE  */
#line 226 "gocompiler.y"
                               { (yyval.no) = novo_no("For", NULL);
                                aux = novo_no("Block", NULL);
                                add_filho((yyval.no), aux);
                                add_filho(aux, (yyvsp[-1].no));
}
#line 1594 "gocompiler.tab.c"
    break;

  case 35: /* Statement: FOR LBRACE RBRACE  */
#line 231 "gocompiler.y"
                   { (yyval.no) = novo_no("For", NULL);
                                aux = novo_no("Block", NULL);
                                add_filho((yyval.no), aux);
}
#line 1603 "gocompiler.tab.c"
    break;

  case 36: /* Statement: FOR Expr LBRACE RBRACE  */
#line 235 "gocompiler.y"
                        { (yyval.no) = novo_no("For", NULL);add_filho((yyval.no), (yyvsp[-2].no));
                                aux = novo_no("Block", NULL);
                                add_irmao((yyvsp[-2].no), aux);
}
#line 1612 "gocompiler.tab.c"
    break;

  case 37: /* Statement: FOR Expr LBRACE StatementSC RBRACE  */
#line 239 "gocompiler.y"
                                    { (yyval.no) = novo_no("For", NULL);add_filho((yyval.no), (yyvsp[-3].no));
                                aux = novo_no("Block", NULL);
                                add_irmao((yyvsp[-3].no), aux);
                                add_filho(aux, (yyvsp[-1].no));
}
#line 1622 "gocompiler.tab.c"
    break;

  case 38: /* Statement: RETURN Expr  */
#line 244 "gocompiler.y"
             { (yyval.no) = novo_no("Return", NULL); add_filho((yyval.no), (yyvsp[0].no));}
#line 1628 "gocompiler.tab.c"
    break;

  case 39: /* Statement: RETURN  */
#line 245 "gocompiler.y"
        { (yyval.no) = novo_no("Return", NULL);}
#line 1634 "gocompiler.tab.c"
    break;

  case 40: /* Statement: ParseArgs  */
#line 246 "gocompiler.y"
            { (yyval.no) = (yyvsp[0].no);}
#line 1640 "gocompiler.tab.c"
    break;

  case 41: /* Statement: PRINT LPAR Expr RPAR  */
#line 247 "gocompiler.y"
                       { (yyval.no) = novo_no("Print", NULL); add_filho((yyval.no), (yyvsp[-1].no));}
#line 1646 "gocompiler.tab.c"
    break;

  case 42: /* Statement: PRINT LPAR STRLIT RPAR  */
#line 248 "gocompiler.y"
                         { (yyval.no) = novo_no("NULL", NULL);
                                                aux = novo_no("StrLit", (yyvsp[-1].valor));
                                                add_filho((yyval.no), aux);
                                                }
#line 1655 "gocompiler.tab.c"
    break;

  case 43: /* Statement: FuncInvocation  */
#line 252 "gocompiler.y"
                { (yyval.no) = novo_no("Call", NULL); add_filho((yyval.no), (yyvsp[0].no));}
#line 1661 "gocompiler.tab.c"
    break;

  case 44: /* Statement: error  */
#line 253 "gocompiler.y"
       { (yyval.no) = novo_no("Error", NULL);}
#line 1667 "gocompiler.tab.c"
    break;

  case 45: /* StatementSC: StatementSC Statement SEMICOLON  */
#line 258 "gocompiler.y"
                                             {
                    (yyval.no) = (yyvsp[-2].no);
                    add_irmao((yyvsp[-2].no), (yyvsp[-1].no));
}
#line 1676 "gocompiler.tab.c"
    break;

  case 46: /* StatementSC: Statement SEMICOLON  */
#line 262 "gocompiler.y"
                      {
                    (yyval.no) = (yyvsp[-1].no);
}
#line 1684 "gocompiler.tab.c"
    break;

  case 47: /* ParseArgs: IDENTIFIER COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR  */
#line 268 "gocompiler.y"
                                                                                   {
                (yyval.no) = novo_no("ParseArgs", NULL);
                add_filho((yyval.no), (yyvsp[-10].valor));
                add_irmao((yyvsp[-10].valor), (yyvsp[-2].no));
}
#line 1694 "gocompiler.tab.c"
    break;

  case 48: /* ParseArgs: IDENTIFIER COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR  */
#line 273 "gocompiler.y"
                                                           {
                (yyval.no) = novo_no("ParseArgs", NULL);
                add_filho((yyval.no), (yyvsp[-7].valor));
                aux = novo_no("NULL", NULL);
                add_irmao((yyvsp[-7].valor), aux);

}
#line 1706 "gocompiler.tab.c"
    break;

  case 49: /* FuncInvocation: IDENTIFIER LPAR error RPAR  */
#line 282 "gocompiler.y"
                                           {(yyval.no) = novo_no("NULL", NULL);}
#line 1712 "gocompiler.tab.c"
    break;

  case 50: /* FuncInvocation: IDENTIFIER LPAR Expr2 RPAR  */
#line 283 "gocompiler.y"
                             {(yyval.no) = novo_no("Call", NULL); add_filho((yyval.no), (yyvsp[-3].valor));}
#line 1718 "gocompiler.tab.c"
    break;

  case 51: /* FuncInvocation: IDENTIFIER LPAR RPAR  */
#line 284 "gocompiler.y"
                       {(yyval.no) = (yyvsp[-2].valor);}
#line 1724 "gocompiler.tab.c"
    break;

  case 52: /* Expr2: COMMA Expr  */
#line 289 "gocompiler.y"
                  {(yyval.no) = (yyvsp[0].no);}
#line 1730 "gocompiler.tab.c"
    break;

  case 53: /* Expr2: Expr COMMA Expr2  */
#line 290 "gocompiler.y"
                   {(yyval.no) = (yyvsp[-2].no); add_irmao((yyvsp[-2].no), (yyvsp[0].no));}
#line 1736 "gocompiler.tab.c"
    break;

  case 54: /* Expr: Expr OR Expr  */
#line 293 "gocompiler.y"
                   {
    (yyval.no) = novo_no("OR", NULL);
    add_filho((yyval.no), (yyvsp[-2].no));
    add_irmao((yyvsp[-2].no), (yyvsp[0].no));
}
#line 1746 "gocompiler.tab.c"
    break;

  case 55: /* Expr: Expr AND Expr  */
#line 298 "gocompiler.y"
                {
    (yyval.no) = novo_no("AND", NULL);
    add_filho((yyval.no), (yyvsp[-2].no));
    add_irmao((yyvsp[-2].no), (yyvsp[0].no));
}
#line 1756 "gocompiler.tab.c"
    break;

  case 56: /* Expr: Expr GE Expr  */
#line 303 "gocompiler.y"
               {
    (yyval.no) = novo_no("GE", NULL);
    add_filho((yyval.no), (yyvsp[-2].no));
    add_irmao((yyvsp[-2].no), (yyvsp[0].no));
}
#line 1766 "gocompiler.tab.c"
    break;

  case 57: /* Expr: Expr GT Expr  */
#line 308 "gocompiler.y"
               {
    (yyval.no) = novo_no("GT", NULL);
    add_filho((yyval.no), (yyvsp[-2].no));
    add_irmao((yyvsp[-2].no), (yyvsp[0].no));
}
#line 1776 "gocompiler.tab.c"
    break;

  case 58: /* Expr: Expr LE Expr  */
#line 313 "gocompiler.y"
               {
    (yyval.no) = novo_no("LE", NULL);
    add_filho((yyval.no), (yyvsp[-2].no));
    add_irmao((yyvsp[-2].no), (yyvsp[0].no));
}
#line 1786 "gocompiler.tab.c"
    break;

  case 59: /* Expr: Expr LT Expr  */
#line 318 "gocompiler.y"
               {
    (yyval.no) = novo_no("LT", NULL);
    add_filho((yyval.no), (yyvsp[-2].no));
    add_irmao((yyvsp[-2].no), (yyvsp[0].no));
}
#line 1796 "gocompiler.tab.c"
    break;

  case 60: /* Expr: Expr NE Expr  */
#line 323 "gocompiler.y"
               {
    (yyval.no) = novo_no("NE", NULL);
    add_filho((yyval.no), (yyvsp[-2].no));
    add_irmao((yyvsp[-2].no), (yyvsp[0].no));
}
#line 1806 "gocompiler.tab.c"
    break;

  case 61: /* Expr: Expr EQ Expr  */
#line 328 "gocompiler.y"
               {
    (yyval.no) = novo_no("EQ", NULL);
    add_filho((yyval.no), (yyvsp[-2].no));
    add_irmao((yyvsp[-2].no), (yyvsp[0].no));
}
#line 1816 "gocompiler.tab.c"
    break;

  case 62: /* Expr: Expr PLUS Expr  */
#line 333 "gocompiler.y"
                 {
    (yyval.no) = novo_no("PLUS", NULL);
    add_filho((yyval.no), (yyvsp[-2].no));
    add_irmao((yyvsp[-2].no), (yyvsp[0].no));
}
#line 1826 "gocompiler.tab.c"
    break;

  case 63: /* Expr: Expr MINUS Expr  */
#line 338 "gocompiler.y"
                  {
    (yyval.no) = novo_no("MINUS", NULL);
    add_filho((yyval.no), (yyvsp[-2].no));
    add_irmao((yyvsp[-2].no), (yyvsp[0].no));
}
#line 1836 "gocompiler.tab.c"
    break;

  case 64: /* Expr: Expr STAR Expr  */
#line 343 "gocompiler.y"
                 {
    (yyval.no) = novo_no("STAR", NULL);
    add_filho((yyval.no), (yyvsp[-2].no));
    add_irmao((yyvsp[-2].no), (yyvsp[0].no));
}
#line 1846 "gocompiler.tab.c"
    break;

  case 65: /* Expr: Expr DIV Expr  */
#line 348 "gocompiler.y"
                {
    (yyval.no) = novo_no("DIV", NULL);
    add_filho((yyval.no), (yyvsp[-2].no));
    add_irmao((yyvsp[-2].no), (yyvsp[0].no));
}
#line 1856 "gocompiler.tab.c"
    break;

  case 66: /* Expr: Expr MOD Expr  */
#line 353 "gocompiler.y"
                {
    (yyval.no) = novo_no("MOD", NULL);
    add_filho((yyval.no), (yyvsp[-2].no));
    add_irmao((yyvsp[-2].no), (yyvsp[0].no));
}
#line 1866 "gocompiler.tab.c"
    break;

  case 67: /* Expr: NOT Expr  */
#line 358 "gocompiler.y"
                     {
    (yyval.no) = novo_no("NOT", NULL);
    add_filho((yyval.no), (yyvsp[0].no));
}
#line 1875 "gocompiler.tab.c"
    break;

  case 68: /* Expr: MINUS Expr  */
#line 362 "gocompiler.y"
                         {
    (yyval.no) = novo_no("MINUS", NULL);
    add_filho((yyval.no), (yyvsp[0].no));
}
#line 1884 "gocompiler.tab.c"
    break;

  case 69: /* Expr: PLUS Expr  */
#line 366 "gocompiler.y"
                       {
    (yyval.no) = novo_no("PLUS", NULL);
    add_filho((yyval.no), (yyvsp[0].no));
}
#line 1893 "gocompiler.tab.c"
    break;

  case 70: /* Expr: IDENTIFIER  */
#line 370 "gocompiler.y"
            {(yyval.no) = (yyvsp[0].valor);}
#line 1899 "gocompiler.tab.c"
    break;

  case 71: /* Expr: NATURAL  */
#line 371 "gocompiler.y"
         {(yyval.no) = novo_no("Natural", (yyvsp[0].valor));}
#line 1905 "gocompiler.tab.c"
    break;

  case 72: /* Expr: DECIMAL  */
#line 372 "gocompiler.y"
         {(yyval.no) = novo_no("Decimal", (yyvsp[0].valor));}
#line 1911 "gocompiler.tab.c"
    break;

  case 73: /* Expr: FuncInvocation  */
#line 373 "gocompiler.y"
                {add_filho(novo_no("Call", NULL), (yyvsp[0].no));}
#line 1917 "gocompiler.tab.c"
    break;

  case 74: /* Expr: LPAR Expr RPAR  */
#line 375 "gocompiler.y"
                 {(yyval.no) = (yyvsp[-1].no);}
#line 1923 "gocompiler.tab.c"
    break;

  case 75: /* Expr: LPAR error RPAR  */
#line 376 "gocompiler.y"
                  {(yyval.no) = novo_no("NULL", NULL);}
#line 1929 "gocompiler.tab.c"
    break;


#line 1933 "gocompiler.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 380 "gocompiler.y"





