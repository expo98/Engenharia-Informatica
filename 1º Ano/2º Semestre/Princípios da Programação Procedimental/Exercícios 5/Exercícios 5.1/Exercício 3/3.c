#include <stdio.h>


int main(){

    int a[10];
    int b[10];


    for(int i=0;i<10;i++){
        printf("Elemento a[%d]?\n",i);
        scanf("%d",&a[i]);
    }

    for(int i=0; i<10;i++){
        b[9-i] = a[i];
    }
    
    printf("O novo vector invertido é:\n");
    for(int i=0; i<10;i++){

        printf("b[%d] = %d\n",i, b[i]);
    }

     printf("O vector original é:\n");
    for(int i=0; i<10;i++){
        printf("a[%d] = %d\n",i, a[i]);
    }

    return 0;
}