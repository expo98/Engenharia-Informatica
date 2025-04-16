%{    
    /*
        Carlos Manuel Gomes da Fonseca Augusto Pereira - 2022232042
        Miguel Teixeira de Pina Monteiro Pereira - 2022232552
    */

   #include <stdio.h>
   #include <string.h>
    #include <stdlib.h>
    #include "y.tab.h"
    #include "struct.h"


    int  column = 1, line = 1, line_error = 0, column_error = 0, line_string = 0, column_string = 0;
    int flag = 0, semicolon = 0, lex_flag = 0;

    char *buffer;
    int erros = 0;
    int yyparse(void);

    extern struct no* raiz;


%}

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
RESERVED "++"|"--"|"break"|"case"|"chan"|"const"|"continue"|"default"|"defer"|"fallthrough"|"go"|"goto"|"import"|"interface"|"map"|"range"|"select"|"struct"|"switch"|"type"

DIGIT [0-9]
LETTER [a-zA-Z_]
STRLIT   ([^\n\r\\"]|\\n|\\f|\\r|\\\\|\\\"|\\t)*
OCTAL 0[0-7]*
ILLEGAL_OCTAL 0{0-9}*
HEXDIGIT 0[xX][0-9A-Fa-f]+
INVALID_OCTAL 0{DIGIT}*
INVALID_ESCAPE \\[^fnrt"\\]
IDENTIFIER ({LETTER})+({LETTER}|{DIGIT})*
NATURAL {DIGIT}+
SIGNAL [+-]?
EXPONENT [eE]{SIGNAL}?{DIGIT}+
DECIMAL ({DIGIT}+"."{DIGIT}*{EXPONENT}?)|("."{DIGIT}+{EXPONENT}?)|({DIGIT}+{EXPONENT})
OPEN \"
NEWLINE  \n|\r|\r\n
IGNORE " "|"\t"|"\f"


%x  COMMENTS LINE_COMMENT STR_ERROR 

%%



"//" {BEGIN(LINE_COMMENT);}
<LINE_COMMENT>{NEWLINE} {BEGIN(INITIAL); line++; column = 1; if (flag) { printf("SEMICOLON\n"); flag = 0; }}
<LINE_COMMENT><<EOF>> {BEGIN(INITIAL); printf("Line %d, column %d: unterminated comment\n", line_error, column_error); flag = 0;}
<LINE_COMMENT>. {;}

"/*" {BEGIN(COMMENTS); line_error = line; column_error = column;}
<COMMENTS><<EOF>> {printf("Line %d, column %d: unterminated comment\n", line_error, column_error); BEGIN(INITIAL); flag = 0;}
<COMMENTS>{NEWLINE} {line++;}
<COMMENTS>"*/" {BEGIN(INITIAL);}
<COMMENTS>. {;}

{OPEN} {BEGIN(STR_ERROR); line_string = line; column_string = column; flag = 1;}
<STR_ERROR>{NEWLINE} {BEGIN(INITIAL); printf("Line %d, column %d: unterminated string literal\n", line_string, column_string); line++; column = 1; flag = 0;}
<STR_ERROR>{STRLIT} {BEGIN(INITIAL); flag = 1;}
<STR_ERROR>\\(.?) {printf("Line %d, column %d: invalid escape sequence (%s)\n", line_string, column_string, yytext); column += yyleng;}
<STR_ERROR>{OPEN} {flag = 1;if(lex_flag) printf("STRLIT(%s)\n", yytext); BEGIN(INITIAL);}


{SEMICOLON} {if(lex_flag) printf("SEMICOLON\n"); flag = 0; column += yyleng; if(!lex_flag) {return SEMICOLON;}}
{COMMA} {if(lex_flag) printf("COMMA\n"); flag = 0; column += yyleng; if(!lex_flag) {return COMMA;}}
{ASSIGN} {if(lex_flag) printf("ASSIGN\n"); flag = 0; column += yyleng; if(!lex_flag) {return ASSIGN;}}
{STAR} {if(lex_flag) printf("STAR\n"); flag = 0; column += yyleng; if(!lex_flag) {return STAR;}}
{DIV} {if(lex_flag) printf("DIV\n"); flag = 0; column += yyleng; if(!lex_flag) {return DIV;}}
{MINUS} {if(lex_flag) printf("MINUS\n"); flag = 0; column += yyleng; if(!lex_flag) {return MINUS;}}
{PLUS} {if(lex_flag) printf("PLUS\n"); flag = 0; column += yyleng; if(!lex_flag) {return PLUS;}}
{EQ} {if(lex_flag) printf("EQ\n"); flag = 0; column += yyleng; if(!lex_flag) {return EQ;}}
{GE} {if(lex_flag) printf("GE\n"); flag = 0; column += yyleng; if(!lex_flag) {return GE;}}
{GT} {if(lex_flag) printf("GT\n"); flag = 0; column += yyleng; if(!lex_flag) {return GT;}}
{LE} {if(lex_flag) printf("LE\n"); flag = 0; column += yyleng; if(!lex_flag) {return LE;}}
{LT} {if(lex_flag) printf("LT\n"); flag = 0; column += yyleng; if(!lex_flag) {return LT;}}
{MOD} {if(lex_flag) printf("MOD\n"); flag = 0; column += yyleng; if(!lex_flag) {return MOD;}}
{NE} {if(lex_flag) printf("NE\n"); flag = 0; column += yyleng; if(!lex_flag) {return NE;}}
{NOT} {if(lex_flag) printf("NOT\n"); flag = 0; column += yyleng; if(!lex_flag) {return NOT;}}
{AND} {if(lex_flag) printf("AND\n"); flag = 0; column += yyleng; if(!lex_flag) {return AND;}}
{OR} {if(lex_flag) printf("OR\n"); flag = 0; column += yyleng; if(!lex_flag) {return OR;}}
{LBRACE} {if(lex_flag) printf("LBRACE\n"); flag = 0; column += yyleng; if(!lex_flag) {return LBRACE;}}
{LPAR} {if(lex_flag) printf("LPAR\n"); flag = 0; column += yyleng; if(!lex_flag) {return LPAR;}}
{LSQ} {if(lex_flag) printf("LSQ\n"); flag = 0; column += yyleng; if(!lex_flag) {return LSQ;}}
{RBRACE} {if(lex_flag) printf("RBRACE\n"); flag = 1; column += yyleng; if(!lex_flag) {return RBRACE;}}
{RPAR} {if(lex_flag) printf("RPAR\n"); flag = 1; column += yyleng; if(!lex_flag) {return RPAR;}}
{RSQ} {if(lex_flag) printf("RSQ\n"); flag = 1; column += yyleng; if(!lex_flag) {return RSQ;}}
{PACKAGE} {if(lex_flag) printf("PACKAGE\n"); flag = 0; column += yyleng; if(!lex_flag) {return PACKAGE;}}
{RETURN} {if(lex_flag) printf("RETURN\n"); flag = 1; column += yyleng; if(!lex_flag) {return RETURN;}}
{ELSE} {if(lex_flag) printf("ELSE\n"); flag = 0; column += yyleng; if(!lex_flag) {return ELSE;}}
{FOR} {if(lex_flag) printf("FOR\n"); flag = 0; column += yyleng; if(!lex_flag) {return FOR;}}
{IF} {if(lex_flag) printf("IF\n"); flag = 0; column += yyleng; if(!lex_flag) {return IF;}}
{VAR} {if(lex_flag) printf("VAR\n"); flag = 0; column += yyleng; if(!lex_flag) {return VAR;}}
{INT} {if(lex_flag) printf("INT\n"); flag = 0; column += yyleng; if(!lex_flag) {return INT;}}
{FLOAT32} {if(lex_flag) printf("FLOAT32\n"); flag = 0; column += yyleng; if(!lex_flag) {return FLOAT32;}}
{BOOL} {if(lex_flag) printf("BOOL\n"); flag = 0; column += yyleng; if(!lex_flag) {return BOOL;}}
{STRING} {if(lex_flag) printf("STRING\n"); flag = 0; column += yyleng; if(!lex_flag) {return STRING;}}
{PRINT} {if(lex_flag) printf("PRINT\n"); flag = 0; column += yyleng; if(!lex_flag) {return PRINT;}}
{PARSEINT} {if(lex_flag) printf("PARSEINT\n"); flag = 0; column += yyleng; if(!lex_flag) {return PARSEINT;}}
{FUNC} {if(lex_flag) printf("FUNC\n"); flag = 0; column += yyleng; if(!lex_flag) {return FUNC;}}
{CMDARGS} {if(lex_flag) printf("CMDARGS\n"); flag = 0; column += yyleng; if(!lex_flag) {return CMDARGS;}}
{RESERVED} {if(lex_flag) printf("RESERVED(%s)\n", yytext); flag = 0; column += yyleng; if(!lex_flag) {return RESERVED;}}
{BLANKID} {if(lex_flag) printf("BLANKID\n"); flag = 0; column += yyleng; if(!lex_flag) {return BLANKID;}}
{INVALID_OCTAL} {printf("Line %d, column %d: invalid octal constant (%s)\n", line, column, yytext); column += yyleng;}
{IGNORE} {;}
{IDENTIFIER} {if(lex_flag) printf("ID(%s)\n", yytext); flag = 1; column += yyleng; if(!lex_flag) {yylval.valor = (char*) strdup(yytext); return IDENTIFIER;}}
{NATURAL} {if(lex_flag) printf("NATURAL(%s)\n", yytext); flag = 1; column += yyleng; if(!lex_flag) {yylval.valor = (char*) strdup(yytext); return NATURAL;}}
{DECIMAL} {if(lex_flag) printf("DECIMAL(%s)\n", yytext); flag = 1; column += yyleng; if(!lex_flag) {yylval.valor = (char*) strdup(yytext); return NATURAL;}}



{NEWLINE} { if(flag) { flag = 0;if(lex_flag == 1) {printf("SEMICOLON\n");}if(lex_flag == 0) { return SEMICOLON;  } }}

<<EOF>> {if(flag){if(lex_flag) {printf("SEMICOLON\n");}flag = 0;} if(lex_flag == 0) {return SEMICOLON;}return 0;}

. {printf("Line %d, column %d: illegal character (%s)\n", line, column, yytext);column += yyleng;}

%%


extern int yylex();
int main(int argc, char** argv) {
    if(argc > 1){
        if(strcmp(argv[1], "-l") == 0){
            yylex();
        }else if(strcmp(argv[1], "-t") == 0){
            flag = 1;
            yylex(); 
            if(erros){
                print_arvore(raiz, 0);
            }
    }else{ 
        yyparse(); /* run the lexical analysis automaton */
    }
    }
       
    return 0;
}


int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}

