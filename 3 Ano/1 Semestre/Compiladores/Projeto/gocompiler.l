/* Carlos Manuel Gomes da Fonseca Augusto Pereira 2022232042
    Miguel Teixeira de Pina Monteiro Pereira 2022232552*/

%{
    #include <string.h>
    #include <stdio.h>

    int  column = 1, line = 1, line_error = 0, column_error = 0, token = 0, flag = 0, smcl = 1;

%}

%x STRING_INVALIDA COMENTARIO COMENTARIOS 
DIGIT [0-9]
LETTER [a-zA-Z_]
CHAR [^\"\n\r\\]
ESCAPE \\[fnrt"\\]
OCTALDIGIT [0-7]
HEXDIGIT [0-9a-fA-F]
INVALID_OCTAL 0([0-7]*[89][0-7]*)+
INVALID_ESCAPE \\[^fnrt"\\]
SIGNAL [+-]?
IDENTIFIER ({LETTER})+({LETTER}|{DIGIT})*
STRLIT \"({CHAR}|{ESCAPE})*\"
NATURAL 0{OCTALDIGIT}+|(0[xX]{HEXDIGIT}+)|{DIGIT}+
FRACTION {DIGIT}+
EXPONENTIAL [eE]{SIGNAL}?{DIGIT}+
DECIMAL ({DIGIT}+\.{FRACTION}?{EXPONENTIAL}?|\.{FRACTION}{EXPONENTIAL}?|{DIGIT}+{EXPONENTIAL})
COMMENT "//"
OPEN_COMMENT "/*"
CLOSE_COMMENT "*/"
OPEN_STRING \"
RESERVED "++"|"--"|"break"|"case"|"chan"|"const"|"continue"|"default"|"defer"|"fallthrough"|"go"|"goto"|"import"|"interface"|"map"|"range"|"select"|"struct"|"switch"|"type"
SEMICOLON  ";"
COMMA  ","
BLANKID  "_"
ASSIGN  "="
STAR  "*"
DIV  "/"
MINUS  "-"
PLUS  "+"
EQ  "=="
GE  ">="
GT  ">"
LBRACE  "{"
LE  "<="
LPAR  "("
LSQ  "["
LT  "<"
MOD  "%"
NE  "!="
NOT  "!"
AND  "&&"
OR  "||"
RBRACE  "}"
RPAR  ")"
RSQ  "]"
PACKAGE package
RETURN return
ELSE else
FOR for
IF if
VAR var
INT int
FLOAT32 float32
BOOL bool
STRING string
PRINT fmt"."Println
PARSEINT strconv"."Atoi
FUNC func
CMDARGS os"."Args



%%
{OPEN_STRING} {BEGIN STRING_INVALIDA; column_error = column; line_error = line; column += yyleng;}
<STRING_INVALIDA>(\r\n)|\n {printf("Line %d, column %d: unterminated string literal\n", line_error, column_error); line++; column = 1; BEGIN 0; token = 0;}
<STRING_INVALIDA><<EOF>> {printf("Line %d, column %d: unterminated string literal\n", line_error, column_error); BEGIN 0; token = 0;}
<STRING_INVALIDA>{OPEN_STRING} {column += yyleng; BEGIN 0;}
<STRING_INVALIDA>{INVALID_ESCAPE} {printf("Line %d, column %d: invalid escape sequence (%s)\n", line, column, yytext); column += yyleng;}
<STRING_INVALIDA>\\. {column += yyleng;}
<STRING_INVALIDA>. {column += yyleng;}

{COMMENT} {BEGIN COMENTARIO; column += yyleng;}
<COMENTARIO>\n {column = 1; line++; if (token) {printf("SEMICOLON\n"); token = 0;} BEGIN 0;}
<COMENTARIO>\\. {column += yyleng;}
<COMENTARIO>. {column += yyleng;}
{OPEN_COMMENT} {BEGIN COMENTARIOS; column_error = column; line_error = line; column += yyleng;}
<COMENTARIOS>{CLOSE_COMMENT} {BEGIN 0; column += yyleng;}
<COMENTARIOS>\n {column = 1; line++;}
<COMENTARIOS><<EOF>> {printf("Line %d, column %d: unterminated comment\n", line_error, column_error); BEGIN 0; token = 0;}
<COMENTARIOS>\\. {column += yyleng;}
<COMENTARIOS>. {column += yyleng;}

{RETURN} {if (flag) printf("RETURN\n"), token = smcl;}
{PACKAGE} {if (flag) printf("PACKAGE\n"), token = 0;}
{ELSE} {if (flag) printf("ELSE\n"), token = 0;}
{FOR} {if (flag) printf("FOR\n"), token = 0;}
{IF} {if (flag) printf("IF\n"), token = 0;}
{VAR} {if (flag) printf("VAR\n"), token = 0;}
{INT} {if (flag) printf("INT\n"), token = 0;}
{FLOAT32} {if (flag) printf("FLOAT32\n"), token = 0;}
{BOOL} {if (flag) printf("BOOL\n"), token = 0;}
{STRING} {if (flag) printf("STRING\n"), token = 0;}
{PRINT} {if (flag) printf("PRINT\n"), token = 0;}
{PARSEINT} {if (flag) printf("PARSEINT\n"), token = 0;}
{FUNC} {if (flag) printf("FUNC\n"), token = 0;}
{CMDARGS} {if (flag) printf("CMDARGS\n"), token = 0;}
{RESERVED} {if (flag) printf("RESERVED(%s)\n", yytext), column += yyleng, token = 0;}
{BLANKID} {if (flag) printf("BLANKID\n"), column += yyleng, token = 0;}
{IDENTIFIER} {if (flag) printf("IDENTIFIER(%s)\n", yytext), column += yyleng, token = smcl;}
{INVALID_OCTAL} {if (flag) printf("Line %d, column %d: invalid octal constant (%s)\n", line, column, yytext), column += yyleng;}
{NATURAL} {if (flag) printf("NATURAL(%s)\n", yytext), column += yyleng, token = smcl;}
{STRLIT} {if (flag) printf("STRLIT(%s)\n", yytext), column += yyleng, token = smcl;}
{DECIMAL} {if (flag) printf("DECIMAL(%s)\n", yytext), column += yyleng, token = smcl;}
{SEMICOLON} {if (flag) printf("SEMICOLON\n"), column += yyleng, token = 0;}
{COMMA} {if (flag) printf("COMMA\n"), column += yyleng, token = 0;}
{ASSIGN} {if (flag) printf("ASSIGN\n"), column += yyleng, token = 0;}
{STAR} {if (flag) printf("STAR\n"), column += yyleng, token = 0;}
{DIV} {if (flag) printf("DIV\n"), column += yyleng, token = 0;}
{MINUS} {if (flag) printf("MINUS\n"), column += yyleng, token = 0;}
{PLUS} {if (flag) printf("PLUS\n"), column += yyleng, token = 0;}
{EQ} {if (flag) printf("EQ\n"), column += yyleng, token = 0;}
{GE} {if (flag) printf("GE\n"), column += yyleng, token = 0;}
{GT} {if (flag) printf("GT\n"), column += yyleng, token = 0;}
{LBRACE} {if (flag) printf("LBRACE\n"), column += yyleng, token = 0;}
{LE} {if (flag) printf("LE\n"), column += yyleng, token = 0;}
{LPAR} {if (flag) printf("LPAR\n"), column += yyleng, token = 0;}
{LSQ} {if (flag) printf("LSQ\n"), column += yyleng, token = 0;}
{LT} {if (flag) printf("LT\n"), column += yyleng, token = 0;}
{MOD} {if (flag) printf("MOD\n"), column += yyleng, token = 0;}
{NE} {if (flag) printf("NE\n"), column += yyleng, token = 0;}
{NOT} {if (flag) printf("NOT\n"), column += yyleng, token = 0;}
{AND} {if (flag) printf("AND\n"), column += yyleng, token = 0;}
{OR} {if (flag) printf("OR\n"), column += yyleng, token = 0;}
{RBRACE} {if (flag) printf("RBRACE\n"), token = smcl, column += yyleng;}
{RPAR} {if (flag) printf("RPAR\n"), token = smcl, column += yyleng;}
{RSQ} {if (flag) printf("RSQ\n"), token = smcl, column += yyleng;}
\n {if(flag){if (token == smcl) {printf("SEMICOLON\n");  token = 0;}}line++; column = 1; }
[ \t\r]+ {column += yyleng; }
<<EOF>> {if(flag){if(token) printf("SEMICOLON\n");token = 0;}return 0;}
. {printf("Line %d, column %d: illegal character (%s)\n", line, column, yytext);column += yyleng;}
%%

extern int yylex();
int main(int argc, char** argv) {
    for(int i = 1; i < argc; i++){
        if (strcmp(argv[i], "-l") == 0){
            flag = 1;
        }
    }

    yylex();    /* run the lexical analysis automaton */
    return 0;
}

int yywrap() {  /* chamado no EOF, retorna 1 para terminar */
    return 1;
}
