#include <stdio.h>
#include <math.h>

int main(){
    int dolares=0;
    int euro=0;
    float taxa_cambio_eur_dol = 1.07338;

    printf("Quantos euros deseja converter em dólares?\n");
    scanf("%d",&euro);

    dolares = euro * taxa_cambio_eur_dol;
    printf("%d euros equivale a %d dólares!",euro,dolares);

    return 0;
}