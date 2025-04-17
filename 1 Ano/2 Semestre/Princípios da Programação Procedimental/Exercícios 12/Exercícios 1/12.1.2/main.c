#include <stdio.h>
#include <stdlib.h>

typedef struct noPilha
{
    int numero;
    struct noPilha *prox;
} noPilha_type;

typedef noPilha_type * ptr_noPilha_type;

int main(){
    ptr_noPilha_type pilha;

    // inicializar a pilha
    pilha = NULL;

    printf("Introduzir numeros inteiros (-1 para terminar)\n");
    int num =0;
    while (num!=-1)
    {
        printf("Novo numero?");
        scanf("%d", &num);

        //PUSH - inserir elemento na pilha
        ptr_noPilha_type auxPtr;
        auxPtr = (ptr_noPilha_type) malloc(sizeof(noPilha_type));
        if (auxPtr==NULL){
            printf("Memoria insuficiente\n");
            return 1;
        }
        auxPtr->numero= num;
        auxPtr->prox = pilha;
        pilha = auxPtr;
    }

    printf("Retirar numeros da pilha e imprimir\n");
    while(pilha!=NULL)
    {
        //POP - retirar elemento da pilha
        ptr_noPilha_type auxPtr;
        auxPtr = pilha;
        pilha = pilha->prox;
        printf("Numero: %d\n",auxPtr->numero);
        free(auxPtr); // Libertar memória do elemento reitrado
    }
    return 0;
}