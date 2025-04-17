#include <stdio.h>

int main(){
    int numA = 2;
    int numB = 6;

    if((numA%2==0) && (numB%2==0)){
        printf("%d\n",numA+numB);
    }
    if((numA%2!=0) && (numB%2!=0)){
        printf("%d\n",numA*numB);
    }
    else if (numA%2!=0){
        printf("%d",numA);
    }
    else if (numB%2!=0){
        printf("%d",numB);
    }

    return 0;
}