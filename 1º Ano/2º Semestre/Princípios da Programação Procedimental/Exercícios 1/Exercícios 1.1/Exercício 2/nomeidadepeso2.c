#include <stdio.h>

int main(){
    int peso,idade;

    printf("Quanto pesas?\n");
    scanf("%d",&peso);
    
    printf("Quantos anos tens?\n");
    scanf("%d",&idade);

    printf("Chamo-me Miguel, tenho %d anos e peso %d Kg.\n",idade,peso);

    return 0;
}