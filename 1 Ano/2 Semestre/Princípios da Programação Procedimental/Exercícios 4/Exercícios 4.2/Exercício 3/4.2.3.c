#include <stdio.h>

long long int fact(int num);
long long int perm(int num, int repetition);

int main(){
    int num=0;
    int repetitions=0;
    int resultado=0;
    printf("Qual o número?\n");
    scanf("%d",&num);
    
    for (int i = 2; i<num;i++){
        resultado = perm(num,i);
        printf("Todas as permutações do número %d para %d repetições é %d\n",num,repetitions,resultado);
    }

    return 0;
}


long long int fact(int num){
    long int factorial=1;
    for (int i=num ; i>1; i--){
        factorial *= i;
    }
    return factorial;
}

long long int perm(int num, int repetition){
    
    return (fact(num))/(fact(num-repetition));
}