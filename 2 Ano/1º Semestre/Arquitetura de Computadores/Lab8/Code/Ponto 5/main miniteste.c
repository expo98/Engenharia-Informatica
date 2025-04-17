//
// Created by MIguel Monteiro Pereira on 05/12/2023.
//

#include <stdio.h>
#define DIM 6

int manipulada(unsigned char *a, int dim);

int main(){
    unsigned char array[DIM]={201,126,137,98,150,233};

    int val = manipulada(array, DIM);
    printf("Tabela manipulada:\n");
    int i;
    for (i = 0; i < DIM; i++) {
        printf("índice i=%d valor: %d\n", i , val);
        printf("Valor devolvido: %d\n, val");
    }
}