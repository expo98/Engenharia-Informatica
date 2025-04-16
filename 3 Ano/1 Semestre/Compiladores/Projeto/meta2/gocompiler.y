%{
    /*
        Carlos Manuel Gomes da Fonseca Augusto Pereira - 2022232042
        Miguel Teixeira de Pina Monteiro Pereira - 2022232552
    */

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "struct.h"
    
        int yylex(void);
        void yyerror(char *s) {
    fprintf(stderr, "Syntax error: %s\n", s);  // Prints error message
}

        struct no *raiz;
        struct no *aux = NULL;
        int counter = 0;

    %}

%union {
    char *valor;
    struct no *no;

}

%token SEMICOLON COMMA LBRACE RBRACE LPAR RPAR LSQ RSQ STAR DIV MINUS PLUS GE GT LE LT NE EQ VAR MOD NOT AND OR INT FLOAT32 BOOL STRING RETURN PACKAGE ELSE IF FOR ASSIGN PARSEINT CMDARGS FUNC BLANKID PRINT

%token <valor> IDENTIFIER
%token <valor> RESERVED
%token <valor> NATURAL
%token <valor> DECIMAL
%token <valor> STRLIT



%type<no> Program
%type<no> Declarations
%type<no> Type 
%type<no> VarDeclaration
%type<no> VarsAndStatement
%type<no> VarsSpec
%type<no> FuncDeclaration
%type<no> FuncBody
%type<no> FuncInvocation
%type<no> FuncParams
%type<no> ID2
%type<no> COMMA2
%type<no> COMMAID
%type<no> StatementSC
%type<no> ParseArgs

%type<no> Statement
%type<no> Expr
%type<no> Expr2





%left       LOW
%nonassoc   IF ELSE FOR
%left       COMMA
%right      ASSIGN
%left       OR
%left       AND
%left       LT GT LE GE EQ NE
%left       PLUS MINUS
%left       STAR DIV MOD
%left       LBRACE RBRACE LPAR RPAR LSQ RSQ
%right      NOT 

%nonassoc IF ELSE

%%

Program: PACKAGE IDENTIFIER SEMICOLON Declarations { raiz = novo_no("Program", NULL); $$ = raiz; add_filho($$, $4);}
;

Declarations: Declarations FuncDeclaration SEMICOLON {$$ = $1; add_filho($$, $2);}
            | Declarations VarDeclaration SEMICOLON {$$ = $1; add_filho($$, $2);}
            | {$$ = novo_no("Declarations", NULL);}
            ;

VarDeclaration: VAR VarsSpec {$$ = $2;}
            | VAR LPAR VarsSpec SEMICOLON RPAR {$$ = $3;}
            ;

ID2: IDENTIFIER {$$ = novo_no("ID", $1);}
    ;

VarsSpec: ID2 Type{$$ = novo_no("VarDeclaration", NULL); add_filho($$, $1); add_filho($$, $2);} 
        | ID2 COMMA2 Type{$$ = novo_no("VarDeclaration", NULL); add_filho($$, $3); 
                                                    add_filho($3, $1); 
                                                    add_filho($$, $2);
                                                    aux = $$->irmao;
                                                    while(aux->irmao != NULL){
                                                        strcpy(aux->filho->tipo, $3->tipo);
                                                        aux = aux->irmao;}
                                                    }
                                                    
        ;

COMMA2: COMMA ID2 COMMA2 { 
                                                                $$ = novo_no("VarDecl", NULL);
                                                                aux = novo_no("NULL", NULL);
                                                                add_irmao($$, $3);
                                                                add_filho($$,aux);
                                                                add_irmao(aux, $2);
                                                                }


                                                             
        | ID2 COMMA2 Type { $$ = novo_no("VarDecl", NULL);
            add_filho($$, $3);
            add_irmao($3, $1);
            add_irmao($$, $2);
            aux = $$->irmao;
            while(aux->irmao != NULL){
                strcpy(aux->filho->tipo, $3->tipo);
                aux = aux->irmao;}
            }
        ;

Type: INT {$$ = novo_no("Int",NULL);} | FLOAT32 {$$ = novo_no("Float32",NULL);} | BOOL {$$ = novo_no("Bool",NULL);} | STRING {$$ = novo_no("String",NULL);}
    ;

FuncDeclaration: FUNC ID2 LPAR FuncParams RPAR Type FuncBody {$$=novo_no("FuncDecl", NULL);
                                                            struct no *fheader = novo_no("FuncHeader", NULL);
                                                            add_filho($$, fheader);
                                                            add_irmao(fheader, $7);
                                                            add_filho(fheader, $2);
                                                            add_irmao($6, $4);
                                                            add_filho($2, $6);
                                                            }
                 | FUNC ID2 LPAR FuncParams RPAR FuncBody {$$=novo_no("FuncDecl", NULL);
                                                            struct no *fheader = novo_no("FuncHeader", NULL);
                                                            add_filho($$, fheader);
                                                            add_irmao(fheader, $6);
                                                            add_filho(fheader, $2);
                                                            add_irmao($2, $4);
                                                         
                                                            }
                | FUNC ID2 LPAR RPAR Type FuncBody {$$=novo_no("FuncDecl", NULL);
                                                            struct no *fheader = novo_no("FuncHeader", NULL);
                                                            aux = novo_no("FuncParams", NULL);
                                                            add_filho($$, fheader);
                                                            add_irmao(fheader, $6);
                                                            add_filho(fheader, $2);
                                                            add_irmao($2,$5);
                                                            aux = novo_no("FuncParams", NULL);
                                                            add_irmao($5, aux);
                                                            } 
                | FUNC ID2 LPAR RPAR FuncBody {$$=novo_no("FuncDecl", NULL);
                                                             struct no *fheader = novo_no("FuncHeader", NULL);
                                                             add_filho($$, fheader);
                                                             add_filho(fheader, $2);
                                                             aux = novo_no("FuncParams", NULL);
                                                             add_irmao($2, aux);
                                                             add_irmao(fheader, $5);
                                                                }        
                                                                ;


FuncParams: ID2 Type COMMAID{$$ = novo_no("FuncParams", NULL); 
                            aux = novo_no("ParamDecl", NULL);
                            add_filho($$, aux);
                            add_irmao(aux, $3);
                            add_filho(aux, $2);
                            add_irmao($2, $1);
                            
                            }
                        | ID2 Type {$$ = novo_no("FuncParams", NULL); 
                            aux = novo_no("ParamDecl", NULL);
                            add_filho($$, aux);
                            add_filho(aux, $2);
                            add_irmao($2, $1);
                            }
            ;

COMMAID: COMMA ID2 Type COMMAID {
                                $$ = novo_no("ParamDecl", NULL);
                                add_filho($$, $3);
                                add_irmao($3, $2);
                                add_irmao($$, $4);
                                }
        |COMMA ID2 Type { $$ = novo_no("ParamDecl", NULL);
                                        add_filho($$, $3);
                                        add_irmao($3, $2);
                                        }
                                        ;

FuncBody: LBRACE VarsAndStatement RBRACE {$$ = novo_no("FuncBody", NULL); add_filho($$, $2);}
        ;


VarsAndStatement: VarsAndStatement  SEMICOLON {$$ = $1;}
                |VarsAndStatement VarDeclaration SEMICOLON {$$ = $1; add_irmao($1, $2);}
                | VarsAndStatement Statement {$$ = $1; add_irmao($1, $2);}
                | {$$ = novo_no("NULL", NULL);}
                ;

Statement: ID2 ASSIGN Expr { $$ = novo_no("Assign", NULL); add_filho($$,$1); add_irmao($1,$3);}
| LBRACE StatementSC RBRACE{
    struct no *aux2 = $2;
    counter = 0;
    while(aux2 != NULL){
        counter++;
        aux2 = aux2->irmao;
    }
    if(counter > 1){
        $$ = novo_no("Block", NULL);
        add_filho($$, $2);
    }else{
        $$ = $2;
    }
}
| LBRACE RBRACE {$$ = novo_no("Block", NULL);}

| IF Expr LBRACE RBRACE { $$ = novo_no("If", NULL); add_filho($$, $2);
                                                        aux = novo_no("Block", NULL);
                                                        add_irmao($2, aux);
                                                        struct no *aux1 = novo_no("Block", NULL);
                                                        add_irmao(aux, aux1);
}
| IF Expr LBRACE StatementSC RBRACE { $$ = novo_no("If", NULL); add_filho($$, $2);
                                                        aux = novo_no("Block", NULL);
                                                        add_irmao($2, aux);
                                                        add_filho(aux, $4);
                                                        struct no *aux1 = novo_no("Block", NULL);
                                                        add_irmao(aux, aux1);
}
| IF Expr LBRACE RBRACE ELSE LBRACE RBRACE { $$ = novo_no("If", NULL); add_filho($$, $2);
                                                        aux = novo_no("Block", NULL);
                                                        add_irmao($2, aux);
                                                        struct no *aux1 = novo_no("Block", NULL);
                                                        add_irmao(aux, aux1);
                                                        
}
| IF Expr LBRACE RBRACE ELSE LBRACE StatementSC RBRACE { $$ = novo_no("If", NULL); add_filho($$, $2);
                                                        aux = novo_no("Block", NULL);
                                                        struct no *aux1 = novo_no("Block", NULL);
                                                        add_irmao($2, aux);
                                                        add_irmao(aux, aux1);
                                                        add_filho(aux1, $7);
}
|IF Expr LBRACE StatementSC RBRACE ELSE LBRACE StatementSC RBRACE { $$ = novo_no("If", NULL); add_filho($$, $2);
                                                        aux = novo_no("Block", NULL);
                                                        struct no *aux1 = novo_no("Block", NULL);
                                                        add_irmao($2, aux);
                                                        add_filho(aux, $4);
                                                        add_irmao(aux, aux1);
                                                        add_filho(aux1, $8);
}
|FOR LBRACE StatementSC RBRACE { $$ = novo_no("For", NULL);
                                aux = novo_no("Block", NULL);
                                add_filho($$, aux);
                                add_filho(aux, $3);
}
|FOR LBRACE RBRACE { $$ = novo_no("For", NULL);
                                aux = novo_no("Block", NULL);
                                add_filho($$, aux);
}
|FOR Expr LBRACE RBRACE { $$ = novo_no("For", NULL);add_filho($$, $2);
                                aux = novo_no("Block", NULL);
                                add_irmao($2, aux);
}
|FOR Expr LBRACE StatementSC RBRACE { $$ = novo_no("For", NULL);add_filho($$, $2);
                                aux = novo_no("Block", NULL);
                                add_irmao($2, aux);
                                add_filho(aux, $4);
}
|RETURN Expr { $$ = novo_no("Return", NULL); add_filho($$, $2);}
|RETURN { $$ = novo_no("Return", NULL);}
| ParseArgs { $$ = $1;}
| PRINT LPAR Expr RPAR { $$ = novo_no("Print", NULL); add_filho($$, $3);}
| PRINT LPAR STRLIT RPAR { $$ = novo_no("NULL", NULL);
                                                aux = novo_no("StrLit", $3);
                                                add_filho($$, aux);
                                                }
|FuncInvocation { $$ = novo_no("Call", NULL); add_filho($$, $1);}
|error { $$ = novo_no("Error", NULL);}

;

                            
StatementSC: StatementSC Statement SEMICOLON {
                    $$ = $1;
                    add_irmao($1, $2);
}
| Statement SEMICOLON {
                    $$ = $1;
}
;


ParseArgs: ID2 COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR {
                $$ = novo_no("ParseArgs", NULL);
                add_filho($$, $1);
                add_irmao($1, $9);
}
| ID2 COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR {
                $$ = novo_no("ParseArgs", NULL);
                add_filho($$, $1);
                aux = novo_no("NULL", NULL);
                add_irmao($1, aux);

}
;
  
FuncInvocation: ID2 LPAR error RPAR {$$ = novo_no("NULL", NULL);}
| ID2 LPAR Expr2 RPAR {$$ = novo_no("Call", NULL); add_filho($$, $1);}
| ID2 LPAR RPAR {$$ = $1;}
;



Expr2: COMMA Expr {$$ = $2;}
| Expr COMMA Expr2 {$$ = $1; add_irmao($1, $3);}
;

Expr: Expr OR Expr {
    $$ = novo_no("OR", NULL);
    add_filho($$, $1);
    add_irmao($1, $3);
}
| Expr AND Expr {
    $$ = novo_no("AND", NULL);
    add_filho($$, $1);
    add_irmao($1, $3);
}
| Expr GE Expr {
    $$ = novo_no("GE", NULL);
    add_filho($$, $1);
    add_irmao($1, $3);
}
| Expr GT Expr {
    $$ = novo_no("GT", NULL);
    add_filho($$, $1);
    add_irmao($1, $3);
}
| Expr LE Expr {
    $$ = novo_no("LE", NULL);
    add_filho($$, $1);
    add_irmao($1, $3);
}
| Expr LT Expr {
    $$ = novo_no("LT", NULL);
    add_filho($$, $1);
    add_irmao($1, $3);
}
| Expr NE Expr {
    $$ = novo_no("NE", NULL);
    add_filho($$, $1);
    add_irmao($1, $3);
}
| Expr EQ Expr {
    $$ = novo_no("EQ", NULL);
    add_filho($$, $1);
    add_irmao($1, $3);
}
| Expr PLUS Expr {
    $$ = novo_no("PLUS", NULL);
    add_filho($$, $1);
    add_irmao($1, $3);
}
| Expr MINUS Expr {
    $$ = novo_no("MINUS", NULL);
    add_filho($$, $1);
    add_irmao($1, $3);
}
| Expr STAR Expr {
    $$ = novo_no("STAR", NULL);
    add_filho($$, $1);
    add_irmao($1, $3);
}
| Expr DIV Expr {
    $$ = novo_no("DIV", NULL);
    add_filho($$, $1);
    add_irmao($1, $3);
}
| Expr MOD Expr {
    $$ = novo_no("MOD", NULL);
    add_filho($$, $1);
    add_irmao($1, $3);
}
| NOT Expr %prec NOT {
    $$ = novo_no("NOT", NULL);
    add_filho($$, $2);
}
| MINUS Expr %prec MINUS {
    $$ = novo_no("MINUS", NULL);
    add_filho($$, $2);
}
| PLUS Expr %prec PLUS {
    $$ = novo_no("PLUS", NULL);
    add_filho($$, $2);
}
|ID2 {$$ = $1;}
|NATURAL {$$ = novo_no("Natural", $1);}
|DECIMAL {$$ = novo_no("Decimal", $1);}
|FuncInvocation {add_filho(novo_no("Call", NULL), $1);}

| LPAR Expr RPAR {$$ = $2;}
| LPAR error RPAR {$$ = novo_no("NULL", NULL);}
;


%%




