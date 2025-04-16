/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_GOCOMPILER_TAB_H_INCLUDED
# define YY_YY_GOCOMPILER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SEMICOLON = 258,               /* SEMICOLON  */
    COMMA = 259,                   /* COMMA  */
    LBRACE = 260,                  /* LBRACE  */
    RBRACE = 261,                  /* RBRACE  */
    LPAR = 262,                    /* LPAR  */
    RPAR = 263,                    /* RPAR  */
    LSQ = 264,                     /* LSQ  */
    RSQ = 265,                     /* RSQ  */
    STAR = 266,                    /* STAR  */
    DIV = 267,                     /* DIV  */
    MINUS = 268,                   /* MINUS  */
    PLUS = 269,                    /* PLUS  */
    GE = 270,                      /* GE  */
    GT = 271,                      /* GT  */
    LE = 272,                      /* LE  */
    LT = 273,                      /* LT  */
    NE = 274,                      /* NE  */
    EQ = 275,                      /* EQ  */
    VAR = 276,                     /* VAR  */
    MOD = 277,                     /* MOD  */
    NOT = 278,                     /* NOT  */
    AND = 279,                     /* AND  */
    OR = 280,                      /* OR  */
    INT = 281,                     /* INT  */
    FLOAT32 = 282,                 /* FLOAT32  */
    BOOL = 283,                    /* BOOL  */
    STRING = 284,                  /* STRING  */
    RETURN = 285,                  /* RETURN  */
    PACKAGE = 286,                 /* PACKAGE  */
    ELSE = 287,                    /* ELSE  */
    IF = 288,                      /* IF  */
    FOR = 289,                     /* FOR  */
    ASSIGN = 290,                  /* ASSIGN  */
    PARSEINT = 291,                /* PARSEINT  */
    CMDARGS = 292,                 /* CMDARGS  */
    FUNC = 293,                    /* FUNC  */
    BLANKID = 294,                 /* BLANKID  */
    PRINT = 295,                   /* PRINT  */
    IDENTIFIER = 296,              /* IDENTIFIER  */
    RESERVED = 297,                /* RESERVED  */
    NATURAL = 298,                 /* NATURAL  */
    DECIMAL = 299,                 /* DECIMAL  */
    STRLIT = 300                   /* STRLIT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "gocompiler.y"

    char *valor;
    struct no *no;


#line 115 "gocompiler.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_GOCOMPILER_TAB_H_INCLUDED  */
