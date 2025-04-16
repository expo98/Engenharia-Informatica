//Carlos Pereira 2022232042
//MIguel Pereira 2022242552

#include "ast.h"

struct no *novo_no(char *token, char *type) {
    struct no *novo =  (struct no *) malloc(sizeof(struct no));
    novo->type = (char *) strdup(type);
    novo->irmao = NULL;
    novo->filho = NULL;

    if (token != NULL) {
        novo->token = (char *) strdup(token);
    } else {
        novo->token = NULL;
        return novo;
    }

    return novo;
}

void add_filho(struct no *pai, struct no *filho) {
    if(pai == NULL) {
        return;
    } else if(filho == NULL) {
        return;
    }
    pai->filho = filho;

}

void add_irmao(struct no *no, struct no *irmao) {
   if (no == NULL) {
        return;
   } else if (irmao == NULL) {
        return;
   }

    struct no *aux = no; 
    while(aux->irmao != NULL) {
        aux = aux->irmao;
    }
    aux->irmao = irmao;
}

void print_arvore(struct no *no, int tamanho) {
    if(no == NULL) {
        return;
    }else{
        if(strcmp(no->type, "NULL") != 0){

            for(int i = 0; i < tamanho; i++) {
                printf("..");
            }
            if(no->token != NULL){
                printf("%s(%s)\n", no->type, no->token);
            }else{
                printf("%s\n", no->type);
            }

            if(no->filho != NULL) {
                print_arvore(no->filho, tamanho + 1);
            }
            if(no->irmao != NULL) {
                print_arvore(no->irmao, tamanho);
            }

        }else{
            if (no->filho != NULL) {
                print_arvore(no->filho, tamanho);
            }
            if (no->irmao != NULL) {
                print_arvore(no->irmao, tamanho);
            }
    }
}
}