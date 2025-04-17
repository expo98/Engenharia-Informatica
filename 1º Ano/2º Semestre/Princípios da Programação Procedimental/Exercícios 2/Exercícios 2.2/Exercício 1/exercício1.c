#include <stdio.h>

int main(){
    int idade=0;

    printf("Idade do utilizador do bilhete?\n");
    scanf("%d",&idade);

    if(idade<=12)   
        printf("Isento de pagamento!\n");
    else if(idade<25)   
        printf("Bilhete radical!\n");
    else if((idade<37))   
        printf("Bilhete light!\n");
    else if(( idade < 49))
        printf("Bilhete normal!\n");
    else if(idade<61)
        printf("Bilhete light!\n");
    else if(idade>=61)
        printf("Isento de pagamento!\n");
    else 
        printf("Idade inválida!");

    return 0;
}