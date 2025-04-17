#include <stdio.h>

int inverte(int i);

int main(){
    int num;
    printf("Qual o número?\n");
    scanf("%d",&num);
    printf("%d invertido é %d\n",num,inverte(num));

    if (num == inverte(num)){
        printf("%d é capícua, lê-se igual de frente para trás e de trás para a frente!\n",num);
    }
}

int inverte(int i){
    int digito=0;
    int num_invertido=0;

    while ((i/10) !=0){
    digito = i%10;
    i = i/10;
    num_invertido = num_invertido*10 + digito;
    }
    digito = i%10;
    i = i/10;
    num_invertido = num_invertido*10 + digito;


    return num_invertido;
}