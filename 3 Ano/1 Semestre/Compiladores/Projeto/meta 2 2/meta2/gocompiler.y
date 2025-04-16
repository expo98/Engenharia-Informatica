%{
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
%type<no> Statement
%type<no> Expr
%type<no> Expr2
%type<no> FuncDeclaration
%type<no> FuncBody
%type<no> FuncInvocation
%type<no> FuncParams
%type<no> COMMAID
%type<no> StatementSC
%type<no> ParseArgs






%right ASSIGN
%right NOT

%left OR
%left AND
%left LBRACE
%left RBRACE
%left LPAR
%left RPAR
%left LSQ
%left RSQ
%left GE GT LE LT NE EQ 
%left PLUS MINUS STAR DIV MOD
%left COMMA

%nonassoc IF ELSE

%%

Program: PACKAGE IDENTIFIER SEMICOLON Declarations { raiz = novo_no("Program", NULL); $$ = raiz; add_filho($$, $4);}
;

Declarations: Declarations FuncDeclaration SEMICOLON {$$ = $1; add_filho($$, $2);}
            | Declarations VarDeclaration SEMICOLON {$$ = $1; add_filho($$, $2);}
            | {$$ = novo_no("temp", NULL);}
            ;

VarDeclaration: VAR VarsSpec {$$ = $2;}
            | VAR LPAR VarsSpec SEMICOLON RPAR {$$ = $3;}
            ;


VarsSpec: IDENTIFIER Type{struct no *id_node = novo_no("Identifier", NULL); $$ = novo_no("VarsSpec", NULL);add_filho($$, $1); add_filho($$, $2);} 
;



Type: INT {$$ = novo_no("Int",NULL);} | FLOAT32 {$$ = novo_no("Float32",NULL);} | BOOL {$$ = novo_no("Bool",NULL);} | STRING {$$ = novo_no("String",NULL);}
    ;

FuncDeclaration:
    FUNC IDENTIFIER LPAR FuncParams RPAR Type FuncBody {
        $$ = novo_no("FuncDecl", NULL);
        struct no *fheader = novo_no("FuncHeader", NULL);
        add_filho($$, fheader);
        add_irmao(fheader, $7);
        add_filho(fheader, $2);  // Add function name
        add_irmao($6, $4);       // Add return type as sibling of parameters
        add_filho($2, $6);       // Add parameters under function name
    }
    | FUNC IDENTIFIER LPAR FuncParams RPAR FuncBody {
        $$ = novo_no("FuncDecl", NULL);
        struct no *fheader = novo_no("FuncHeader", NULL);
        add_filho($$, fheader);
        add_irmao(fheader, $6);
        add_filho(fheader, $2);
        add_irmao($2, $4);  // Add return type as sibling
    }
    | FUNC IDENTIFIER LPAR RPAR Type FuncBody {
        $$ = novo_no("FuncDecl", NULL);
        struct no *fheader = novo_no("FuncHeader", NULL);
        struct no *aux = novo_no("FuncParams", NULL);  // Handle empty parameters
        add_filho($$, fheader);
        add_irmao(fheader, $6);  // Add function body
        add_filho(fheader, $2);  // Add function name
        add_irmao($2, aux);      // Add empty FuncParams
        add_irmao(fheader, $5);  // Add return type as sibling of FuncParams
    }
    | FUNC IDENTIFIER LPAR RPAR FuncBody {
        $$ = novo_no("FuncDecl", NULL);
        struct no *fheader = novo_no("FuncHeader", NULL);
        struct no *aux = novo_no("FuncParams", NULL);  // Handle empty parameters
        add_filho($$, fheader);
        add_filho(fheader, $2);  // Add function name
        add_irmao($2, aux);      // Add empty parameters
        add_irmao(fheader, $5);  // Add function body
    }
    ;


FuncParams:
    IDENTIFIER Type COMMAID {
        $$ = novo_no("FuncParams", NULL);
        struct no *aux = novo_no("ParamDecl", NULL);
        add_filho($$, aux);
        add_irmao(aux, $3);
        add_filho(aux, $2);
        add_irmao($2, $1);  // Link identifier to type
    }
    | IDENTIFIER Type {
        $$ = novo_no("FuncParams", NULL);
        struct no *aux = novo_no("ParamDecl", NULL);
        add_filho($$, aux);
        add_filho(aux, $2);
        add_irmao($2, $1);  // Link identifier to type
    }
    ;

COMMAID:
    COMMA IDENTIFIER Type COMMAID {
        $$ = novo_no("ParamDecl", NULL);
        add_filho($$, $3);
        add_irmao($3, $2);
        add_irmao($$, $4);  // Link to next parameter
    }
    | COMMA IDENTIFIER Type {
        $$ = novo_no("ParamDecl", NULL);
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

Statement:
    IDENTIFIER ASSIGN Expr {
        $$ = novo_no("Assign", NULL);
        add_filho($$, $1);  // Add the identifier (lhs)
        add_irmao($1, $3);  // Add the expression (rhs)
    }
    | LBRACE StatementSC RBRACE {
        aux = $2;
        counter = 0;
        while (aux != NULL) {
            counter++;
            aux = aux->irmao;  // Count statements inside block
        }
        if (counter > 1) {
            $$ = novo_no("Block", NULL);
            add_filho($$, $2);  // Add all statements in a block
        } else {
            $$ = $2;  // Directly use if only one statement inside
        }
    }
    | IF Expr LBRACE RBRACE {
        $$ = novo_no("If", NULL);
        add_filho($$, $2);  // Add condition (Expr)
        aux = novo_no("Block", NULL);
        add_irmao($2, aux);  // Add empty block for true condition
    }
    | IF Expr LBRACE StatementSC RBRACE {
        $$ = novo_no("If", NULL);
        add_filho($$, $2);  // Add condition
        aux = novo_no("Block", NULL);
        add_irmao($2, aux);
        add_filho(aux, $4);  // Add statements inside block
    }
    | FOR LBRACE StatementSC RBRACE {
        $$ = novo_no("For", NULL);
        aux = novo_no("Block", NULL);
        add_filho($$, aux);
        add_filho(aux, $3);  // Add statements inside for loop
    }
    | RETURN Expr {
        $$ = novo_no("Return", NULL);
        add_filho($$, $2);  // Add return expression
    }
    | RETURN {
        $$ = novo_no("Return", NULL);  // Empty return
    }
    | PRINT LPAR Expr RPAR {
        $$ = novo_no("Print", NULL);
        add_filho($$, $3);  // Add expression to print
    }
    | FuncInvocation {
        $$ = novo_no("Call", NULL);
        add_filho($$, $1);  // Add function invocation
    }
    | error {
        $$ = novo_no("Error", NULL);  // Handle syntax errors
    }
    ;


                            
StatementSC: StatementSC Statement SEMICOLON {
                    $$ = $1;
                    add_irmao($1, $2);
}
| Statement SEMICOLON {
                    $$ = $1;
}
;


ParseArgs: IDENTIFIER COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR {
                $$ = novo_no("ParseArgs", NULL);
                add_filho($$, $1);
                add_irmao($1, $9);
}
| IDENTIFIER COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR {
                $$ = novo_no("ParseArgs", NULL);
                add_filho($$, $1);
                aux = novo_no("NULL", NULL);
                add_irmao($1, aux);

}
;
  
FuncInvocation: IDENTIFIER LPAR error RPAR {$$ = novo_no("NULL", NULL);}
| IDENTIFIER LPAR Expr2 RPAR {$$ = novo_no("Call", NULL); add_filho($$, $1);}
| IDENTIFIER LPAR RPAR {$$ = $1;}
;



Expr2: COMMA Expr {$$ = $2;}
| Expr COMMA Expr2 {$$ = $1; add_irmao($1, $3);}
;

Expr:
    Expr OR Expr {
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
    | Expr EQ Expr {
        $$ = novo_no("EQ", NULL);
        add_filho($$, $1);
        add_irmao($1, $3);
    }
    | IDENTIFIER {
        $$ = $1;  // Directly use the identifier node
    }
    | NATURAL {
        $$ = novo_no("Natural", $1);  // Wrap natural number in a node
    }
    | DECIMAL {
        $$ = novo_no("Decimal", $1);  // Wrap decimal number in a node
    }
    | LPAR Expr RPAR {
        $$ = $2;  // Parentheses just group the expression
    }
    ;



%%




