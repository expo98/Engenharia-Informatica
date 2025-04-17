#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noPilha
{
    char string[50];
    struct noPilha *prox;
} noPilha_type;

typedef noPilha_type * ptr_noPilha_type;

int main(){
    ptr_noPilha_type pilha;

    //inicializar pilha
    pilha = NULL;

    printf("Introduzir strings até 50 caracteres(Introduzir FIM para terminar)\n");
    
    char str[50];
    int size=0;
    while (strcmp(str,"FIM\n") !=0)
    {
        printf("Nova string: ");
        fgets(str, 51, stdin);

        // PUSH - Inserir elemento na pilha
        ptr_noPilha_type auxPtr;
        auxPtr = (ptr_noPilha_type) malloc(sizeof(noPilha_type));
        if (auxPtr == NULL)
        {
            printf("Memoria insuficiente\n");
            return 1;
        }

        strcpy(auxPtr->string, str);
        auxPtr->prox = pilha;
        pilha=auxPtr;
        size++;

    }

    printf("%d\n",size);


    printf("Retirar strings da pilha e imprimir\n");
    while(pilha!=NULL)
    {
        //POP - retirar elemento da pilha
        ptr_noPilha_type auxPtr;
        auxPtr = pilha;
        pilha = pilha->prox;
        printf("String: %s\n",auxPtr->string);
        free(auxPtr); // Libertar memória do elemento reitrado
    }

    return 0;
    
}