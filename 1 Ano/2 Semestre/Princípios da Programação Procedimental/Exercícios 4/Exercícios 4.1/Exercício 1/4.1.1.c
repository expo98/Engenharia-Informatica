#include <stdio.h>

long long int fact(int num);

int main(){
    int num=0;
    printf("Qual o número?\n");
    scanf("%d",&num);
    printf("O factorial de %d é %lld\n",num,fact(num));

    return 0;
}


long long int fact(int num){
    long int factorial=1;
    for (int i=num ; i>1; i--){
        factorial *= i;
    }
    return factorial;
}