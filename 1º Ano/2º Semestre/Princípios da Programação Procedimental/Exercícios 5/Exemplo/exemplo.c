#include <stdio.h>

int funcao (int v[]){
    v[0]=10;
    printf("dentro função  %p - %d\n",v,v[0]);

    return v[0];
}

int main(){
    int vect[1];
    int j=0;

    vect[0]=3;
    printf("%p - %d\n",vect,vect[0]);
    j = funcao(vect);
    printf("%p -%d -%d\n",vect,vect[0],j);

    return 0;
}
