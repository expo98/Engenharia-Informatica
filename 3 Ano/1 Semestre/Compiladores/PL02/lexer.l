%{
    /* place here any C variables and definitions */
    #include <stdio.h>

    int line = 1;        // Track the current line number
    int column = 1;      // Track the current column number
%}



digit      [0-9]
letter     [a-zA-Z]
identifier {letter}({letter}|{digit})*

escape      (\\[fnrt\"\'\\])
invalid_escape (\\[^fnrt\'\\])
string      {identifier}({identifier}|{escape})*

%X STRLIT

%%
"("                        { printf("Used (\n"); column += yyleng; }
")"                        { printf("Used (\n"); column += yyleng; }
"()"                       { printf("Used ()\n"); column += yyleng; }
"="                        { printf("Used =\n"); column += yyleng; }
"*"                        { printf("Used *\n"); column += yyleng; }
","                        { printf("Used ,\n"); column += yyleng; }
"/"                        { printf("Used /\n"); column += yyleng; }
"+"                        { printf("Used +\n"); column += yyleng; }
"-"                        { printf("Used -\n"); column += yyleng; }
"integer"                  { printf("INTEGER\n"); column += yyleng; }
"double"                   { printf("DOUBLE\n"); column += yyleng; }
"if"                       { printf("IF\n"); column += yyleng; }
"then"                     { printf("THEN\n"); column += yyleng; }
"else"                     { printf("ELSE\n"); column += yyleng; }
{digit}+                   { printf("NATURAL(%s)\n", yytext); column += yyleng; }
{digit}*"."{digit}+        { printf("DECIMAL(%s)\n", yytext); column += yyleng; }
{identifier}               { printf("IDENTIFIER(%s)\n", yytext); column += yyleng; }


\"                         { BEGIN(STRLIT); }
<STRLIT>{invalid_escape}   { printf("Line %d, column %d: unknown escape sequence (%s)\n", line, column, yytext); }
<STRLIT>{string}           {printf("STRLIT(%s)\n", yytext); column += yyleng;}
<STRLIT>\"                 {BEGIN(INITIAL);}  

[ \t]+                     { column += yyleng; } /* Ignore spaces and tabs, but update the column */

\n                         { line++; column = 1; } /* Newline: update line number and reset column */

.                          { 
                              printf("Line %d, column %d: unrecognized character (%s)\n", line, column, yytext); 
                              column += yyleng;
                            } /* Error message for unrecognized characters */

%%

extern int yylex();
int main() {
    yylex();    /* run the lexical analysis automaton */
    return 0;
}

int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}

