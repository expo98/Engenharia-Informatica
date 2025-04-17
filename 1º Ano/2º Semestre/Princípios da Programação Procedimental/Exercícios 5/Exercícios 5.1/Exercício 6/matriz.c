#include <stdio.h>

#include "imprimirMatriz.h"

int main(){
    int matriz[MAX][MAX] = {0};

    int linhas, colunas;
    
    do{
        printf("Número de linhas?");
        scanf("%d", &linhas);
    } while ( linhas<1 || linhas>MAX);

    do{
        printf("Número de colunas?");
        scanf("%d", &colunas);
    } while ( colunas<1 || colunas>MAX);

    for (int i=0; i<linhas; i++){
        for (int j=0; j<colunas;j++){
        printf("matriz[%d][%d]?",i,j);
        scanf("%d", &matriz[i][j]);
        }
    }

    imprimir_Matriz(linhas, colunas, matriz);
    return 0;
}