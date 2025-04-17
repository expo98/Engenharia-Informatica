#include <stdio.h>
#include <stdlib.h>

void preencher_matriz(int *v, int n);
void multiplicar_matriz(int *v, int n, int k);

int main(){
    int size, *matriz, multi, *aux;

    printf("Introduza um valor N para a dimensão da matriz NxN: ");
    scanf("%d", &size);
    printf("\n");

    matriz = (int *) malloc(size * size * sizeof(int));
    if (matriz == NULL)
    {
        printf("Memória não disponível");
        return 1;
    }

    preencher_matriz(matriz, size);
    printf("\n");

    aux = matriz;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("v[%d][%d]= %d   ",i,j,*(aux));
            aux++;
        }
        printf("\n");
    }

    printf("Introduza um valor para multiplicar a matriz por: ");
    scanf("%d", &multi);
    printf("\n");

    multiplicar_matriz( matriz, size, multi);

    
    aux = matriz;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("v[%d][%d]= %d   ",i,j,*(aux));
            aux++;
        }
        printf("\n");
    }



    

    free (matriz);
    return 0;
}

void preencher_matriz(int *v, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("v[%d][%d]= ",i,j);
            scanf("%d",v);
            v++;
        }
    }
}

void multiplicar_matriz(int *v, int n, int k){
    for (int i = 0; i < n*n; i++)
    {
        (*v) *= k;
        v++;
    }
    
}