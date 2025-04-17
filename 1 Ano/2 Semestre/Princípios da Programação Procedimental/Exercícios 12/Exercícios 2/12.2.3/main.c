#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noPilha
{
    char caracter;
    struct noPilha *prox;
} noPilha_type;

typedef noPilha_type * ptr_noPilha_type;

int main(){

    char frase[81];
    ptr_noPilha_type pilha;

    // inicializar a pilha
    pilha = NULL;

    printf("Introduza uma frase para inverter (até 80 caracteres)\n");
    fgets(frase, 81, stdin);

    int i=0;
    while (frase[i] != '\0')    
    {
        //PUSH - inserir elemento na pilha
        ptr_noPilha_type auxPtr;
        auxPtr = (ptr_noPilha_type) malloc(sizeof(noPilha_type));
        if (auxPtr==NULL){
            printf("Memoria insuficiente\n");
            return 1;
        }
        auxPtr->caracter = frase[i];
        auxPtr->prox = pilha;
        pilha = auxPtr;
        i++;
    }

    printf("Retirar strings da pilha e imprimir\n");
    while(pilha!=NULL)
    {
        //POP - retirar elemento da pilha
        ptr_noPilha_type auxPtr;
        auxPtr = pilha;
        pilha = pilha->prox;
        printf("%c",auxPtr->caracter);
        free(auxPtr); // Libertar memória do elemento retirado
    }
    return 0;
    

    
    
    
    

}