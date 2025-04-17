#include <stdio.h>

int main(){
    int limite;
    int resultado=0;
    int posicao=0;
    int i=0;

    printf("Introduza um número\n");
    scanf("%d",&limite);

    while(resultado<=limite){
        resultado+=i;
        posicao=i;
        i++;
    }

    printf("O somatório só ultrapassou o limite %d no número %d\n",limite,posicao);
    return 0;
}