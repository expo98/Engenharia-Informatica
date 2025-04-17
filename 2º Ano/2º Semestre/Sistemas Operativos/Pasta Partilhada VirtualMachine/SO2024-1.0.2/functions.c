#include "Header.h"

void cria_fila(fila* f){
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}


no* insere_fila(fila *f, char *s, int QUEUE_POS){
    if(f->tamanho == QUEUE_POS){
        return NULL;
    }

    no* n = malloc(sizeof(no));
    if(n != NULL){
        n->s = malloc(sizeof(char) * (strlen(s)+1));
        if( n->s == NULL){
            free(n);
            return NULL;
        }
        strcpy(n->s, s);
        n->prox = NULL;
        if(f->fim != NULL){
            f->fim->prox = n;
            f->fim = n;
        } else{
            f->inicio = n;
            f->fim = n;
        }
        f->tamanho++;
    }
    return n;
}

void destroi_fila(fila *f){
    while(f->inicio != NULL){
        no* aux = f->inicio;
        f->inicio = f->inicio->prox;
        free(aux);
    }
    f->fim = NULL;
}

int vazia_fila(fila *f){
    return f->inicio == NULL;
}

char* retira_fila(fila *f){
    if( f->inicio != NULL){
        char *res = f->inicio->s;
        no* temp = f->inicio;
        f->inicio = f->inicio->prox;
        free(temp);
        f->tamanho--;
        return res;
    }else {
        return 0;
    }
}