#include <stdio.h>
#include <stdlib.h>

int * cria_ler_vetor_inteiros(int n);
int maiorValor(int k, int * v);

int main(){
    int size, *vetor,k;

    printf("Quantos elementos deverá ter o vector?\n");
    scanf("%d",&size);
    vetor = cria_ler_vetor_inteiros(size);


    do
    {
        printf("Quantos elementos para verificar máximo? ");
        scanf("%d",&k);
    } while ((k<1) || (k>size));
    int max = maiorValor(k,vetor+size-k);
    printf("Máximo : %d\n", max);
    

    free(vetor);
    return 0;
}



int * cria_ler_vetor_inteiros(int n){
    int* v;
    int* ptr;

    v = (int *) malloc(sizeof(int) * n);
    if (v == NULL){
        printf("Não existe memória para alocar\n");
        return NULL;
    }
    ptr = v;
    for(int i=0; i<n; i++){
        printf("v[%d]= ",i);
        scanf("%d",ptr);
        ptr++;
    }
        for(int i=0; i<n; i++){
        printf("v[%d]= %d ",i,*(v+i));
    }
    return v;
}

int maiorValor(int k, int* v){
    int max = *v;
    for (int i = 0; i < k; i++)
    {
        if (*(v+i)>max)
        {
            max = *(v+i);
        }
    }
    return max;
}