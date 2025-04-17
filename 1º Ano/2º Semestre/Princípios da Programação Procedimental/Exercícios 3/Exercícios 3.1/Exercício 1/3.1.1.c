#include <stdio.h>

int num;
int resultado;

int main(){
    printf("Introduza um número para se realizar um somatório até esse número:\n");
    scanf("%d",&num);

    for (int i=0;i<=num;i++){
        resultado +=i;
    }

    printf("O somatório é igual a %d\n",resultado);    

    return 0;
}