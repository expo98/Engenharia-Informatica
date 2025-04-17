#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    char *string;
    int size;
    printf("Quantos caracteres tem a frase?\n");
    scanf("%d",&size);
    string = (char *) malloc((size+1)* sizeof(char));
    if (string == NULL) {
        printf("Não há memória disponível.\n");    
        return 1;
    }

    printf("Introduza a frase: ");
    scanf("%s",string);
    printf("\n");

    printf("%s\n",string);

    free(string);
    return 0;
}


void *leitura_escrita_string(char string){
    int size;
    printf("Quantos caracteres tem a frase?\n");
    scanf("%d",&size);
    string = (char *) malloc((size+1)* sizeof(char));
    if (string == NULL) {
        printf("Não há memória disponível.\n");
        return 1;
    }

    printf("Introduza uma frase:\n");

}