#include <stdio.h>
#include <stdlib.h>
#include "myQueue.h"

//Cria e coloca NULL os ponteiros da fila
void Cria (tipoFila *fila){
    fila->inicio=NULL;
    fila->fim=NULL;
}

//Devolve 1 se a fila estiver vazia, caso contrário devolve 0
int vazia (tipoFila *fila){
    if (fila->inicio == NULL) return 1;
    else return 0;
}

//Coloca os ponteiros da fila a NULL e liberta o espaço ocupado
//pelos elementos que existem na fila
void destroi (tipoFila *fila){
    noFila * temp_ptr;
    while (!vazia(fila)) {
        temp_ptr = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(temp_ptr);
    }
    fila->fim = NULL;
}

//Coloca um elemento no fim da fila, verificando se a função
//malloc teve sucesso na reserva de espaço
void insere (tipoFila *fila, struct str_struct str1){
    noFila * temp_ptr;
    temp_ptr = (noFila *) malloc (sizeof (noFila));
    if (temp_ptr != NULL){
        temp_ptr->strFila = str1;
        temp_ptr->prox = NULL;
        if (vazia(fila))
            fila->inicio = temp_ptr;
        else fila->fim->prox = temp_ptr;
        fila->fim = temp_ptr;
    }
}

//Devolve o primeiro elemento da fila

struct str_struct retira (tipoFila *fila){
    noFila * temp_ptr;
    struct str_struct str1;
    if (!vazia(fila)) {
        temp_ptr = fila->inicio;
        str1 = temp_ptr->strFila;
        fila->inicio = fila->inicio->prox;
        if (vazia(fila))
            fila->fim = NULL;
        free (temp_ptr);
        return(str1);
    }

}