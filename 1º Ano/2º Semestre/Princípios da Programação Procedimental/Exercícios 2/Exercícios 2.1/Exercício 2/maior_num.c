#include <stdio.h>

int main(){
    int numA=123;
    int numB=1233;
    int numC=99999;

    int maior=0;

    if(numA>numB){
        maior=numA;
    }
    else maior=numB;

    if(maior<numC){
        maior=numC;
    }

    printf("O maior número é %d\n",maior);
    

    return 0;
}