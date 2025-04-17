#include <stdio.h>

int main(){
    int vetor[12]={1,2,3,4,5,6,7,8,9,10,11,12};
    int *ptr, *ptrFim, cont=0;
    double media=0.0;

    ptr= vetor;
    ptrFim= vetor+12;
    printf("ptrFim(%p)-ptr(%p)=%ld\n",ptrFim,ptr, ptrFim-ptr);

    while (ptr<ptrFim)
    {
        cont++;
        media += *ptr;
        // printf("%d",*ptr);
        ptr++;
    }
    printf("Media (%lf/%d)=%lf\n",media,cont,media/cont);

    return 0;
}