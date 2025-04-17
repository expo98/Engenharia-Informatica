#include <stdio.h>

long long int fact(int num);
long long int sum(int num);

int main(){
    
    int num;
    printf("Qual o número?\n");
    scanf("%d",&num);

    if (num >=20){
      printf("O somatório de todos os números até %d é %lld\n",num,sum(num));
    }

    else if(num>10){
      printf("O factorial de %d é %lld\n",num,fact(num));
    }

    else{
        printf("O somatório do factorial de todos os número de %d é %lld\n",num,sum(fact(num)));
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

long long int sum(int num){
    long int sum=0;
    for(int i=num;i>0;i--){
        sum +=i;
    }
    return sum;
}