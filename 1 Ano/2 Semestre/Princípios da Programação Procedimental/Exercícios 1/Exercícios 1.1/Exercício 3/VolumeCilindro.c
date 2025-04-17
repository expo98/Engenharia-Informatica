#include <stdio.h>
#include <math.h>

int main(){
    int raioBase, altura, areaBase, volumeCilindro;

    printf("Qual o raio da base do cilindro?\n");
    scanf("%d",&raioBase);

    printf("Qual a altura do cilindro?\n");
    scanf("%d",&altura);


    areaBase = pow(raioBase,2) * M_PI;

    volumeCilindro = areaBase * altura;

    printf("O volume do cilindro é %d centímetros cúbicos",volumeCilindro);

    return 0;
}