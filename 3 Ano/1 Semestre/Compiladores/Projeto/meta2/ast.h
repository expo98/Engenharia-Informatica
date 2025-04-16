//Carlos Pereira 2022232042
//MIguel Pereira 2022242552


#ifndef _AST_H
#define _AST_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>


struct no {
    struct no *filho;
    struct no *irmao;
    char* token;
    char* type;

};

struct no *novo_no(char* token, char* type);
void add_filho(struct no* pai, struct no *filho);
void add_irmao(struct no *no, struct no *irmao);
void print_arvore(struct no *raiz, int tamanho);

#endif
