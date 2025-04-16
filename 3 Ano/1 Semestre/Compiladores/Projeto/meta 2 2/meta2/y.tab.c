/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20221106

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

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

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 21 "gocompiler.y"
typedef union YYSTYPE {
    char *valor;
    struct no *no;

} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 56 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define SEMICOLON 257
#define COMMA 258
#define LBRACE 259
#define RBRACE 260
#define LPAR 261
#define RPAR 262
#define LSQ 263
#define RSQ 264
#define STAR 265
#define DIV 266
#define MINUS 267
#define PLUS 268
#define GE 269
#define GT 270
#define LE 271
#define LT 272
#define NE 273
#define EQ 274
#define VAR 275
#define MOD 276
#define NOT 277
#define AND 278
#define OR 279
#define INT 280
#define FLOAT32 281
#define BOOL 282
#define STRING 283
#define RETURN 284
#define PACKAGE 285
#define ELSE 286
#define IF 287
#define FOR 288
#define ASSIGN 289
#define PARSEINT 290
#define CMDARGS 291
#define FUNC 292
#define BLANKID 293
#define PRINT 294
#define IDENTIFIER 295
#define RESERVED 296
#define NATURAL 297
#define DECIMAL 298
#define STRLIT 299
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    1,    3,    3,    5,    2,    2,    2,
    2,    9,    9,    9,    9,   12,   12,   13,   13,   10,
    4,    4,    4,    4,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,   14,   14,   15,   15,   11,   11,
   11,    8,    8,    7,    7,    7,    7,    7,    7,    7,
    7,
};
static const YYINT yylen[] = {                            2,
    4,    3,    3,    0,    2,    5,    2,    1,    1,    1,
    1,    7,    6,    6,    5,    3,    2,    4,    3,    3,
    2,    3,    2,    0,    3,    3,    4,    5,    4,    2,
    1,    4,    1,    1,    3,    2,   11,    8,    4,    4,
    3,    2,    3,    3,    3,    3,    3,    1,    1,    1,
    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    4,    0,    0,    0,    0,    0,    0,
    0,    5,    0,    3,    2,    0,    8,    9,   10,   11,
    7,    0,    0,    0,    0,    0,    6,   24,    0,   15,
    0,    0,    0,   14,    0,   16,    0,   13,   34,   21,
    0,   20,    0,    0,    0,    0,    0,    0,   23,   33,
    0,   12,    0,    0,    0,   48,   49,   50,    0,    0,
    0,    0,    0,    0,   22,    0,   36,   26,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   41,
    0,    0,    0,   18,   35,   51,   46,   47,    0,    0,
   27,    0,   29,   32,   39,    0,    0,   40,   28,   43,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  285,  301,  295,  257,  302,  275,  292,  304,  310,  261,
  295,  306,  295,  257,  257,  306,  280,  281,  282,  283,
  303,  261,  257,  262,  295,  313,  262,  259,  303,  311,
  303,  262,  305,  311,  258,  314,  303,  311,  256,  257,
  259,  260,  284,  287,  288,  294,  295,  304,  307,  312,
  295,  311,  307,  315,  261,  295,  297,  298,  308,  308,
  259,  261,  261,  289,  257,  303,  257,  260,  307,  308,
  269,  274,  278,  279,  259,  315,  308,  256,  258,  262,
  308,  309,  308,  314,  257,  262,  308,  308,  308,  308,
  260,  315,  260,  262,  262,  308,  258,  262,  260,  309,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          2,
    5,   21,    8,   33,   12,   53,   81,   82,    9,   30,
   50,   26,   36,   54,    0,
};
static const YYINT yysindex[] = {                      -271,
 -279,    0, -234,    0, -268, -259, -270, -229, -223, -233,
 -138,    0, -198,    0,    0, -193,    0,    0,    0,    0,
    0, -256, -196, -201, -138, -186,    0,    0, -155,    0,
 -162, -201, -210,    0, -175,    0, -155,    0,    0,    0,
 -123,    0, -242, -242, -133, -140, -235, -130,    0,    0,
 -138,    0, -119, -165, -242,    0,    0,    0,  -41, -176,
 -123, -242, -253, -242,    0, -162,    0,    0, -118, -163,
 -242, -242, -242, -242, -125, -110,  -76, -109, -242,    0,
  -58, -106,  -41,    0,    0,    0,    0,    0, -252,  -60,
    0, -105,    0,    0,    0,  -41, -257,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,  132,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -104,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -65,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -170,    0,
    0,    0,    0,    0,    0, -102,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -147,    0,    0,    0,    0,    0, -227, -187,
    0,    0,    0,    0,    0,  -96,    0,    0,    0,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,  -14,  119,    0,  147,  -33,  153,   70,    0,  -17,
    0,    0,  102,  -48,    0,
};
#define YYTABLESIZE 238
static const YYINT yytable[] = {                         49,
   79,   10,   78,   55,   79,   24,    6,   55,   80,   29,
   31,   34,   76,    1,   38,    3,   71,   37,   55,   52,
   69,   72,    4,    7,   13,   63,   92,   14,   45,   45,
   45,   45,   45,   15,   45,   11,   66,   56,   25,   57,
   58,   56,   69,   57,   58,   39,   40,   45,   41,   42,
   45,   45,   56,   64,   57,   58,   45,   28,   69,   45,
   45,   11,   22,   23,    6,   27,   45,   45,   44,   44,
   44,   44,   44,   43,   44,   32,   44,   45,   17,   18,
   19,   20,   75,   46,   47,   30,   30,   44,   30,   30,
   39,   44,   71,   41,   68,   35,   44,   72,   86,   44,
   44,   73,   74,   28,   30,   71,   44,   44,   25,   25,
   72,   25,   25,   30,   73,   74,   30,   30,   43,   51,
   62,   44,   45,   30,   30,   61,   65,   25,   46,   47,
   39,    1,   39,   41,   91,   41,   25,   67,   85,   25,
   25,   17,   18,   19,   20,   39,   25,   25,   41,   93,
   39,   48,   95,   41,   99,   98,   16,   17,   43,   19,
   43,   44,   45,   44,   45,   42,  100,   84,   46,   47,
   46,   47,    0,   43,    0,    0,   44,   45,   43,    0,
    0,   44,   45,   46,   47,   94,    0,    0,   46,   47,
   31,   31,   71,   31,   31,   59,   60,   72,    0,   97,
    0,   73,   74,    0,    0,    0,    0,   70,   71,   31,
   71,    0,    0,   72,   77,   72,   83,   73,   31,   73,
   74,   31,   31,   87,   88,   89,   90,   71,   31,    0,
    0,   96,   72,    0,    0,    0,   73,   74,
};
static const YYINT yycheck[] = {                         33,
  258,  261,  256,  261,  258,  262,  275,  261,  262,   24,
   25,   29,   61,  285,   32,  295,  269,   32,  261,   37,
   54,  274,  257,  292,  295,  261,   75,  257,  256,  257,
  258,  259,  260,  257,  262,  295,   51,  295,  295,  297,
  298,  295,   76,  297,  298,  256,  257,  275,  259,  260,
  278,  279,  295,  289,  297,  298,  284,  259,   92,  287,
  288,  295,  261,  257,  275,  262,  294,  295,  256,  257,
  258,  259,  260,  284,  262,  262,  287,  288,  280,  281,
  282,  283,  259,  294,  295,  256,  257,  275,  259,  260,
  256,  279,  269,  259,  260,  258,  284,  274,  262,  287,
  288,  278,  279,  259,  275,  269,  294,  295,  256,  257,
  274,  259,  260,  284,  278,  279,  287,  288,  284,  295,
  261,  287,  288,  294,  295,  259,  257,  275,  294,  295,
  256,    0,  256,  259,  260,  259,  284,  257,  257,  287,
  288,  280,  281,  282,  283,  256,  294,  295,  259,  260,
  256,   33,  262,  259,  260,  262,   10,  262,  284,  262,
  284,  287,  288,  287,  288,  262,   97,   66,  294,  295,
  294,  295,   -1,  284,   -1,   -1,  287,  288,  284,   -1,
   -1,  287,  288,  294,  295,  262,   -1,   -1,  294,  295,
  256,  257,  269,  259,  260,   43,   44,  274,   -1,  258,
   -1,  278,  279,   -1,   -1,   -1,   -1,   55,  269,  275,
  269,   -1,   -1,  274,   62,  274,   64,  278,  284,  278,
  279,  287,  288,   71,   72,   73,   74,  269,  294,   -1,
   -1,   79,  274,   -1,   -1,   -1,  278,  279,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 299
#define YYUNDFTOKEN 317
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","SEMICOLON","COMMA","LBRACE",
"RBRACE","LPAR","RPAR","LSQ","RSQ","STAR","DIV","MINUS","PLUS","GE","GT","LE",
"LT","NE","EQ","VAR","MOD","NOT","AND","OR","INT","FLOAT32","BOOL","STRING",
"RETURN","PACKAGE","ELSE","IF","FOR","ASSIGN","PARSEINT","CMDARGS","FUNC",
"BLANKID","PRINT","IDENTIFIER","RESERVED","NATURAL","DECIMAL","STRLIT",
"$accept","Program","Declarations","Type","VarDeclaration","VarsAndStatement",
"VarsSpec","Statement","Expr","Expr2","FuncDeclaration","FuncBody",
"FuncInvocation","FuncParams","COMMAID","StatementSC","ParseArgs",
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : Program",
"Program : PACKAGE IDENTIFIER SEMICOLON Declarations",
"Declarations : Declarations FuncDeclaration SEMICOLON",
"Declarations : Declarations VarDeclaration SEMICOLON",
"Declarations :",
"VarDeclaration : VAR VarsSpec",
"VarDeclaration : VAR LPAR VarsSpec SEMICOLON RPAR",
"VarsSpec : IDENTIFIER Type",
"Type : INT",
"Type : FLOAT32",
"Type : BOOL",
"Type : STRING",
"FuncDeclaration : FUNC IDENTIFIER LPAR FuncParams RPAR Type FuncBody",
"FuncDeclaration : FUNC IDENTIFIER LPAR FuncParams RPAR FuncBody",
"FuncDeclaration : FUNC IDENTIFIER LPAR RPAR Type FuncBody",
"FuncDeclaration : FUNC IDENTIFIER LPAR RPAR FuncBody",
"FuncParams : IDENTIFIER Type COMMAID",
"FuncParams : IDENTIFIER Type",
"COMMAID : COMMA IDENTIFIER Type COMMAID",
"COMMAID : COMMA IDENTIFIER Type",
"FuncBody : LBRACE VarsAndStatement RBRACE",
"VarsAndStatement : VarsAndStatement SEMICOLON",
"VarsAndStatement : VarsAndStatement VarDeclaration SEMICOLON",
"VarsAndStatement : VarsAndStatement Statement",
"VarsAndStatement :",
"Statement : IDENTIFIER ASSIGN Expr",
"Statement : LBRACE StatementSC RBRACE",
"Statement : IF Expr LBRACE RBRACE",
"Statement : IF Expr LBRACE StatementSC RBRACE",
"Statement : FOR LBRACE StatementSC RBRACE",
"Statement : RETURN Expr",
"Statement : RETURN",
"Statement : PRINT LPAR Expr RPAR",
"Statement : FuncInvocation",
"Statement : error",
"StatementSC : StatementSC Statement SEMICOLON",
"StatementSC : Statement SEMICOLON",
"ParseArgs : IDENTIFIER COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR",
"ParseArgs : IDENTIFIER COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR",
"FuncInvocation : IDENTIFIER LPAR error RPAR",
"FuncInvocation : IDENTIFIER LPAR Expr2 RPAR",
"FuncInvocation : IDENTIFIER LPAR RPAR",
"Expr2 : COMMA Expr",
"Expr2 : Expr COMMA Expr2",
"Expr : Expr OR Expr",
"Expr : Expr AND Expr",
"Expr : Expr GE Expr",
"Expr : Expr EQ Expr",
"Expr : IDENTIFIER",
"Expr : NATURAL",
"Expr : DECIMAL",
"Expr : LPAR Expr RPAR",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 315 "gocompiler.y"





#line 523 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 78 "gocompiler.y"
	{ raiz = novo_no("Program", NULL); yyval.no = raiz; add_filho(yyval.no, yystack.l_mark[0].no);}
#line 1196 "y.tab.c"
break;
case 2:
#line 81 "gocompiler.y"
	{yyval.no = yystack.l_mark[-2].no; add_filho(yyval.no, yystack.l_mark[-1].no);}
#line 1201 "y.tab.c"
break;
case 3:
#line 82 "gocompiler.y"
	{yyval.no = yystack.l_mark[-2].no; add_filho(yyval.no, yystack.l_mark[-1].no);}
#line 1206 "y.tab.c"
break;
case 4:
#line 83 "gocompiler.y"
	{yyval.no = novo_no("temp", NULL);}
#line 1211 "y.tab.c"
break;
case 5:
#line 86 "gocompiler.y"
	{yyval.no = yystack.l_mark[0].no;}
#line 1216 "y.tab.c"
break;
case 6:
#line 87 "gocompiler.y"
	{yyval.no = yystack.l_mark[-2].no;}
#line 1221 "y.tab.c"
break;
case 7:
#line 91 "gocompiler.y"
	{struct no *id_node = novo_no("Identifier", NULL); yyval.no = novo_no("VarsSpec", NULL);add_filho(yyval.no, yystack.l_mark[-1].valor); add_filho(yyval.no, yystack.l_mark[0].no);}
#line 1226 "y.tab.c"
break;
case 8:
#line 96 "gocompiler.y"
	{yyval.no = novo_no("Int",NULL);}
#line 1231 "y.tab.c"
break;
case 9:
#line 96 "gocompiler.y"
	{yyval.no = novo_no("Float32",NULL);}
#line 1236 "y.tab.c"
break;
case 10:
#line 96 "gocompiler.y"
	{yyval.no = novo_no("Bool",NULL);}
#line 1241 "y.tab.c"
break;
case 11:
#line 96 "gocompiler.y"
	{yyval.no = novo_no("String",NULL);}
#line 1246 "y.tab.c"
break;
case 12:
#line 100 "gocompiler.y"
	{
        yyval.no = novo_no("FuncDecl", NULL);
        struct no *fheader = novo_no("FuncHeader", NULL);
        add_filho(yyval.no, fheader);
        add_irmao(fheader, yystack.l_mark[0].no);
        add_filho(fheader, yystack.l_mark[-5].valor);  /* Add function name*/
        add_irmao(yystack.l_mark[-1].no, yystack.l_mark[-3].no);       /* Add return type as sibling of parameters*/
        add_filho(yystack.l_mark[-5].valor, yystack.l_mark[-1].no);       /* Add parameters under function name*/
    }
#line 1259 "y.tab.c"
break;
case 13:
#line 109 "gocompiler.y"
	{
        yyval.no = novo_no("FuncDecl", NULL);
        struct no *fheader = novo_no("FuncHeader", NULL);
        add_filho(yyval.no, fheader);
        add_irmao(fheader, yystack.l_mark[0].no);
        add_filho(fheader, yystack.l_mark[-4].valor);
        add_irmao(yystack.l_mark[-4].valor, yystack.l_mark[-2].no);  /* Add return type as sibling*/
    }
#line 1271 "y.tab.c"
break;
case 14:
#line 117 "gocompiler.y"
	{
        yyval.no = novo_no("FuncDecl", NULL);
        struct no *fheader = novo_no("FuncHeader", NULL);
        struct no *aux = novo_no("FuncParams", NULL);  /* Handle empty parameters*/
        add_filho(yyval.no, fheader);
        add_irmao(fheader, yystack.l_mark[0].no);  /* Add function body*/
        add_filho(fheader, yystack.l_mark[-4].valor);  /* Add function name*/
        add_irmao(yystack.l_mark[-4].valor, aux);      /* Add empty FuncParams*/
        add_irmao(fheader, yystack.l_mark[-1].no);  /* Add return type as sibling of FuncParams*/
    }
#line 1285 "y.tab.c"
break;
case 15:
#line 127 "gocompiler.y"
	{
        yyval.no = novo_no("FuncDecl", NULL);
        struct no *fheader = novo_no("FuncHeader", NULL);
        struct no *aux = novo_no("FuncParams", NULL);  /* Handle empty parameters*/
        add_filho(yyval.no, fheader);
        add_filho(fheader, yystack.l_mark[-3].valor);  /* Add function name*/
        add_irmao(yystack.l_mark[-3].valor, aux);      /* Add empty parameters*/
        add_irmao(fheader, yystack.l_mark[0].no);  /* Add function body*/
    }
#line 1298 "y.tab.c"
break;
case 16:
#line 140 "gocompiler.y"
	{
        yyval.no = novo_no("FuncParams", NULL);
        struct no *aux = novo_no("ParamDecl", NULL);
        add_filho(yyval.no, aux);
        add_irmao(aux, yystack.l_mark[0].no);
        add_filho(aux, yystack.l_mark[-1].no);
        add_irmao(yystack.l_mark[-1].no, yystack.l_mark[-2].valor);  /* Link identifier to type*/
    }
#line 1310 "y.tab.c"
break;
case 17:
#line 148 "gocompiler.y"
	{
        yyval.no = novo_no("FuncParams", NULL);
        struct no *aux = novo_no("ParamDecl", NULL);
        add_filho(yyval.no, aux);
        add_filho(aux, yystack.l_mark[0].no);
        add_irmao(yystack.l_mark[0].no, yystack.l_mark[-1].valor);  /* Link identifier to type*/
    }
#line 1321 "y.tab.c"
break;
case 18:
#line 158 "gocompiler.y"
	{
        yyval.no = novo_no("ParamDecl", NULL);
        add_filho(yyval.no, yystack.l_mark[-1].no);
        add_irmao(yystack.l_mark[-1].no, yystack.l_mark[-2].valor);
        add_irmao(yyval.no, yystack.l_mark[0].no);  /* Link to next parameter*/
    }
#line 1331 "y.tab.c"
break;
case 19:
#line 164 "gocompiler.y"
	{
        yyval.no = novo_no("ParamDecl", NULL);
        add_filho(yyval.no, yystack.l_mark[0].no);
        add_irmao(yystack.l_mark[0].no, yystack.l_mark[-1].valor);
    }
#line 1340 "y.tab.c"
break;
case 20:
#line 172 "gocompiler.y"
	{yyval.no = novo_no("FuncBody", NULL); add_filho(yyval.no, yystack.l_mark[-1].no);}
#line 1345 "y.tab.c"
break;
case 21:
#line 176 "gocompiler.y"
	{yyval.no = yystack.l_mark[-1].no;}
#line 1350 "y.tab.c"
break;
case 22:
#line 177 "gocompiler.y"
	{yyval.no = yystack.l_mark[-2].no; add_irmao(yystack.l_mark[-2].no, yystack.l_mark[-1].no);}
#line 1355 "y.tab.c"
break;
case 23:
#line 178 "gocompiler.y"
	{yyval.no = yystack.l_mark[-1].no; add_irmao(yystack.l_mark[-1].no, yystack.l_mark[0].no);}
#line 1360 "y.tab.c"
break;
case 24:
#line 179 "gocompiler.y"
	{yyval.no = novo_no("NULL", NULL);}
#line 1365 "y.tab.c"
break;
case 25:
#line 183 "gocompiler.y"
	{
        yyval.no = novo_no("Assign", NULL);
        add_filho(yyval.no, yystack.l_mark[-2].valor);  /* Add the identifier (lhs)*/
        add_irmao(yystack.l_mark[-2].valor, yystack.l_mark[0].no);  /* Add the expression (rhs)*/
    }
#line 1374 "y.tab.c"
break;
case 26:
#line 188 "gocompiler.y"
	{
        aux = yystack.l_mark[-1].no;
        counter = 0;
        while (aux != NULL) {
            counter++;
            aux = aux->irmao;  /* Count statements inside block*/
        }
        if (counter > 1) {
            yyval.no = novo_no("Block", NULL);
            add_filho(yyval.no, yystack.l_mark[-1].no);  /* Add all statements in a block*/
        } else {
            yyval.no = yystack.l_mark[-1].no;  /* Directly use if only one statement inside*/
        }
    }
#line 1392 "y.tab.c"
break;
case 27:
#line 202 "gocompiler.y"
	{
        yyval.no = novo_no("If", NULL);
        add_filho(yyval.no, yystack.l_mark[-2].no);  /* Add condition (Expr)*/
        aux = novo_no("Block", NULL);
        add_irmao(yystack.l_mark[-2].no, aux);  /* Add empty block for true condition*/
    }
#line 1402 "y.tab.c"
break;
case 28:
#line 208 "gocompiler.y"
	{
        yyval.no = novo_no("If", NULL);
        add_filho(yyval.no, yystack.l_mark[-3].no);  /* Add condition*/
        aux = novo_no("Block", NULL);
        add_irmao(yystack.l_mark[-3].no, aux);
        add_filho(aux, yystack.l_mark[-1].no);  /* Add statements inside block*/
    }
#line 1413 "y.tab.c"
break;
case 29:
#line 215 "gocompiler.y"
	{
        yyval.no = novo_no("For", NULL);
        aux = novo_no("Block", NULL);
        add_filho(yyval.no, aux);
        add_filho(aux, yystack.l_mark[-1].no);  /* Add statements inside for loop*/
    }
#line 1423 "y.tab.c"
break;
case 30:
#line 221 "gocompiler.y"
	{
        yyval.no = novo_no("Return", NULL);
        add_filho(yyval.no, yystack.l_mark[0].no);  /* Add return expression*/
    }
#line 1431 "y.tab.c"
break;
case 31:
#line 225 "gocompiler.y"
	{
        yyval.no = novo_no("Return", NULL);  /* Empty return*/
    }
#line 1438 "y.tab.c"
break;
case 32:
#line 228 "gocompiler.y"
	{
        yyval.no = novo_no("Print", NULL);
        add_filho(yyval.no, yystack.l_mark[-1].no);  /* Add expression to print*/
    }
#line 1446 "y.tab.c"
break;
case 33:
#line 232 "gocompiler.y"
	{
        yyval.no = novo_no("Call", NULL);
        add_filho(yyval.no, yystack.l_mark[0].no);  /* Add function invocation*/
    }
#line 1454 "y.tab.c"
break;
case 34:
#line 236 "gocompiler.y"
	{
        yyval.no = novo_no("Error", NULL);  /* Handle syntax errors*/
    }
#line 1461 "y.tab.c"
break;
case 35:
#line 243 "gocompiler.y"
	{
                    yyval.no = yystack.l_mark[-2].no;
                    add_irmao(yystack.l_mark[-2].no, yystack.l_mark[-1].no);
}
#line 1469 "y.tab.c"
break;
case 36:
#line 247 "gocompiler.y"
	{
                    yyval.no = yystack.l_mark[-1].no;
}
#line 1476 "y.tab.c"
break;
case 37:
#line 253 "gocompiler.y"
	{
                yyval.no = novo_no("ParseArgs", NULL);
                add_filho(yyval.no, yystack.l_mark[-10].valor);
                add_irmao(yystack.l_mark[-10].valor, yystack.l_mark[-2].no);
}
#line 1485 "y.tab.c"
break;
case 38:
#line 258 "gocompiler.y"
	{
                yyval.no = novo_no("ParseArgs", NULL);
                add_filho(yyval.no, yystack.l_mark[-7].valor);
                aux = novo_no("NULL", NULL);
                add_irmao(yystack.l_mark[-7].valor, aux);

}
#line 1496 "y.tab.c"
break;
case 39:
#line 267 "gocompiler.y"
	{yyval.no = novo_no("NULL", NULL);}
#line 1501 "y.tab.c"
break;
case 40:
#line 268 "gocompiler.y"
	{yyval.no = novo_no("Call", NULL); add_filho(yyval.no, yystack.l_mark[-3].valor);}
#line 1506 "y.tab.c"
break;
case 41:
#line 269 "gocompiler.y"
	{yyval.no = yystack.l_mark[-2].valor;}
#line 1511 "y.tab.c"
break;
case 42:
#line 274 "gocompiler.y"
	{yyval.no = yystack.l_mark[0].no;}
#line 1516 "y.tab.c"
break;
case 43:
#line 275 "gocompiler.y"
	{yyval.no = yystack.l_mark[-2].no; add_irmao(yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1521 "y.tab.c"
break;
case 44:
#line 279 "gocompiler.y"
	{
        yyval.no = novo_no("OR", NULL);
        add_filho(yyval.no, yystack.l_mark[-2].no);
        add_irmao(yystack.l_mark[-2].no, yystack.l_mark[0].no);
    }
#line 1530 "y.tab.c"
break;
case 45:
#line 284 "gocompiler.y"
	{
        yyval.no = novo_no("AND", NULL);
        add_filho(yyval.no, yystack.l_mark[-2].no);
        add_irmao(yystack.l_mark[-2].no, yystack.l_mark[0].no);
    }
#line 1539 "y.tab.c"
break;
case 46:
#line 289 "gocompiler.y"
	{
        yyval.no = novo_no("GE", NULL);
        add_filho(yyval.no, yystack.l_mark[-2].no);
        add_irmao(yystack.l_mark[-2].no, yystack.l_mark[0].no);
    }
#line 1548 "y.tab.c"
break;
case 47:
#line 294 "gocompiler.y"
	{
        yyval.no = novo_no("EQ", NULL);
        add_filho(yyval.no, yystack.l_mark[-2].no);
        add_irmao(yystack.l_mark[-2].no, yystack.l_mark[0].no);
    }
#line 1557 "y.tab.c"
break;
case 48:
#line 299 "gocompiler.y"
	{
        yyval.no = yystack.l_mark[0].valor;  /* Directly use the identifier node*/
    }
#line 1564 "y.tab.c"
break;
case 49:
#line 302 "gocompiler.y"
	{
        yyval.no = novo_no("Natural", yystack.l_mark[0].valor);  /* Wrap natural number in a node*/
    }
#line 1571 "y.tab.c"
break;
case 50:
#line 305 "gocompiler.y"
	{
        yyval.no = novo_no("Decimal", yystack.l_mark[0].valor);  /* Wrap decimal number in a node*/
    }
#line 1578 "y.tab.c"
break;
case 51:
#line 308 "gocompiler.y"
	{
        yyval.no = yystack.l_mark[-1].no;  /* Parentheses just group the expression*/
    }
#line 1585 "y.tab.c"
break;
#line 1587 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
