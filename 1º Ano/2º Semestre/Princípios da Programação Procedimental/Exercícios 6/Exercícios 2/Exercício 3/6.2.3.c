#include <stdio.h>
#define MAX 100
int deslocacao;
char string_introduzida[MAX];

int main(){
    printf("Introduza um valor de deslocação de alfabeto:\n");
    scanf("%d",&deslocacao);

    printf("Introduza uma string com qualquer tipo de caracteres:\n");
    fgets(string_introduzida,100,stdin);

    printf("%s", string_introduzida);



    return 0;
}