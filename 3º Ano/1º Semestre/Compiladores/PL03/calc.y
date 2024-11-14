%{
#include <stdio.h>
extern int yylex(void);
void yyerror(char *);
extern char *yytext;
extern int line;
extern int column;

%}

%token NATURAL IF THEN ELSE
%left LOW
%left '+' '-'
%left '/' '*'
%left '(' ')'
%token ','


%%

calculator: expression                  { printf("%d", $1); }
        |  calculator ',' expression    { printf(", %d", $3);}
          ;


expression: NATURAL                     { $$ = $1; }
          | IF expression THEN expression ELSE expression  %prec LOW {$$ = $2 ? $4 : $6;}
          | expression '+' expression   { $$ = $1 + $3; }
          | expression '-' expression   { $$ = $1 - $3; }
          | expression '*' expression   { $$ = $1 * $3; }
          | expression '/' expression   { $$ = $1 / $3; }
          | '(' expression ')'          { $$ = $2;      }
          ;

%%

void yyerror(char *error) {
    printf("Syntax error %s: '%s' at line %d, column %d\n", error, yytext, line, column);
}