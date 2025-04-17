#include <stdio.h>


#define Max 100

int main(){

    int vect[Max];
    int nEl=0;

    do {
        printf("Quantos elementos?\n");
        scanf("%d",&nEl);
    } while ((nEl<1) || (nEl>Max));

    for (int i=0;i<nEl;i++){
        printf("Elemento[%d]?\n",i);
        scanf("%d",&vect[i]);
    }

    for (int i=0;i<nEl;i++){
        if (vect[i]%2){
            vect[i] = 2* vect[i];
        }
    }

    printf("O novo vector é ");

    for (int i=0; i<nEl;i++){
        printf("%d ",vect[i]);
    }
    printf("\n");
    return 0;
}