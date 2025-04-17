#include <stdio.h>
#include <stdlib.h>
#include "myQueue.h"

int main(){
    char string[60]="";

    tipoFila *simpleQueueptr; //= &simpleQueue;
    struct str_struct element;

    printf("Vamos criar uma fila de strings\n");

    simpleQueueptr = (tipoFila *) malloc(sizeof(tipoFila));

    if (simpleQueueptr == NULL){
        printf("Memory not allocated.\n");
        exit(1);
    }

    void Cria (simpleQueueptr);

    for(int i=1; string!="FIM";i++){
        printf("String %d: ",i);
        fgets(string, 60, stdin);
        element.str = string;
        insere(simpleQueueptr, element);
    }
    return 0;
}