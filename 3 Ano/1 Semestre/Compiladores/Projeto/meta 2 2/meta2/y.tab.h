#ifndef _yy_defines_h_
#define _yy_defines_h_

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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    char *valor;
    struct no *no;

} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
