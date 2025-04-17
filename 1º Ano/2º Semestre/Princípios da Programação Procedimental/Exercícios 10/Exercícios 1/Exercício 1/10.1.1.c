#include <stdio.h>
#include <stdlib.h>

void ler_vetor_inteiros(int * v, int n);
int * criar_ler_vetor_inteiros(int n);
int maximo_vetor(int * v, int num);


int main(){
    int size, *vetor,k;
    printf("Quantos elemento deve ter o vetor?\n");
    scanf("%d",&size);
/*
//Cria Espaço para o vetor
vetor = malloc( size * sizeof(int));
if (vetor == NULL){
    printf("Memória não disponível\n");
    return 1;
}
let_vetor_inteiros(vetor,size);
*/

vetor = criar_ler_vetor_inteiros(size);
do
{
    printf("Quantos elementos para verificar máximo?\n");
    scanf("%d",&k);
} while ((k<1) || (k>size));

int max = maximo_vetor(vetor+size-k,k);
printf("Máximo: %d\n",max);

//libertar o espaço utilizado pelo vetor
    free (vetor);
    return 0;
}

void ler_vetor_inteiros(int * v, int n ){
    for (int i=0; i<n; i++){
        printf("v[%d]=",i);
        scanf("%d",v);
        v++;
    }
}

int maximo_vetor(int * v, int num){
    int max= *v;
        for (int i = 0; i < num; i++)
    {
        if (*(v+1)>max)
        {
            max = *(v+1);
        }
    }
    return max;
}

int * criar_ler_vetor_inteiros(int n){
    int * v, ptr;

    //criar espaço para vetor
    v = (int *) malloc( n * sizeof(int));
    if (v==NULL){
        printf("Memória não disponível\n");
        return NULL;
    }
    ptr =v;
    for (int i = 0; i < n; i++)
    {
        printf("v[%d]=",i);
        scanf("%d",ptr);
        ptr++;
    }
    return v;
}