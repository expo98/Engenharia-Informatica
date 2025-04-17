#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void cria (tipoFila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

int vazia (tipoFila *fila){
    if (fila->inicio == NULL) return 1;
    else return 0;
}

void destroi (tipoFila *fila){
    noFila * temp_ptr;
    while (!vazia(fila)) {
        temp_ptr = fila->inicio->prox;
        free(temp_ptr);
    }
    fila->fim = NULL;
}