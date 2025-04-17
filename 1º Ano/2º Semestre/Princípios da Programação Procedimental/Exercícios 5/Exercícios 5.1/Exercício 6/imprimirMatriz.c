#include <stdio.h>

#include "imprimirMatriz.h"

void imprimir_matriz (int nLin, int nCol, const int matriz[][MAX]){
    printf("Número de elementos é %d x %d",nLin,nCol);
    for(int i=0; i<nLin;i++){
        for (int j=0; j<nCol;j++){
            printf("%d",matriz[i][j]);

        }
        printf("\n");
    }
}