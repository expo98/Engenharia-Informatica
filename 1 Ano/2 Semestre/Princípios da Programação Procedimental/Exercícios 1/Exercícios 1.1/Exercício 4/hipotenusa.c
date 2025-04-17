#include <stdio.h>
#include <math.h>

int main(){
    int hipotenusa=0;
    int catetoA=0;
    int catetoB=0;


    printf("Qual o comprimento de um dos catetos?\n");
    scanf("%d",&catetoA);

    printf("Qual é o comprimento do outro cateto?\n");
    scanf("%d",&catetoB);

    hipotenusa = sqrt(pow(catetoA,2)+pow(catetoB,2));

    printf("A hipotenusa mede %d\n",hipotenusa);

    return 0;
}