#ifndef FICHA1112_MYQUEUE_H
#define FICHA1112_MYQUEUE_H

struct str_struct {
    char str[50];
};

typedef struct noFila{
    struct str_struct strFila;
    struct str_struct *prox;
} noFila;

typedef struct tipoFila {
    noFila *inicio;
    noFila *fim;
}   tipoFila;

void Cria (tipoFila *fila);
int vazia (tipoFila *fila);
void destroi (tipoFila *fila);
void insere (tipoFila *fila, struct str_struct str1);
struct str_struct retira (tipoFila *fila);


#endif
