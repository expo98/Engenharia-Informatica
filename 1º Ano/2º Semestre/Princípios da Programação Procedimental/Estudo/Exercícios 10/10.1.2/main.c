#include <stdlib.h>
#include <stdio.h>

int* criar_matriz(int size);
void multiMatriz(int* matriz, int multi, int size);

int main()
{
    int size, *vetor, multi, *aux;

    printf("Para uma matriz de tamanho NxN, qual o valor para N? \n");
    scanf("%d", &size);

    vetor = criar_matriz(size);

    aux = vetor;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("Matriz[%d][%d]= %d   ",i,j, *(aux));
            aux++;
        }
            printf("\n");
    }
    



    printf("Por qual valor deseja multiplicar a matriz?\n");
    scanf("%d",&multi);

    multiMatriz(vetor, multi, size);

    aux = vetor;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("MAtriz[%d][%d]= %d  ",i,j, *(aux));
            aux++;
        }
            printf("\n");
    }



    free(vetor);
    return 0;
}


int* criar_matriz(int size){
    int *v;
    int *ptr;

    v= (int *) malloc(size*size*sizeof(int));
    if (v == NULL){
        printf("Memória não disponível\n");
        return NULL;
    }

    ptr = v;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {

        printf("Qual o valor de Matriz[%d][%d]? \n",i,j);
        scanf("%d", ptr);
        ptr++; 
        }
    }
    return v;
}

void multiMatriz(int* matriz, int multi, int size){
    for (int i = 0; i < size*size; i++)
    {
        (*matriz) *= multi;
        matriz++;
    }
}