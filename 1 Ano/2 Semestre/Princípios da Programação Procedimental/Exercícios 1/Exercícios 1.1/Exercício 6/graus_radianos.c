#include <stdio.h>
#include <math.h>
float graus;
float radianos;
float graus_decimal;
float segundos;
float minutos;


int main(){

    printf("Introduza os graus (número inteiro) do seu ângulo: \n");
    scanf("%f",&graus);

    printf("Introduza os minutos (número inteiro) do seu ângulo: \n");
    scanf("%f",&minutos);

    printf("Introduza os segundos (número inteiro) do seu ângulo: \n");
    scanf("%f",&segundos);

    graus_decimal = graus + minutos/60 + segundos/3600;

    radianos = (M_PI * graus_decimal)/180;
    printf("O seu ângulo em radianos é %f rad.\n",radianos);

    return 0;
}
