#include <stdio.h>

#define MAX 100

int main(){
    int matriz[MAX][MAX] = {0};
    int linhas, colunas;

    do{
        printf("Número de linhas?\n");
        scanf("%d",&linhas);
    } while (linhas<1 || linhas>MAX);

    do{
        printf("Número de colunas?\n");
        scanf("%d", &colunas);
    } while (colunas<1 || colunas>MAX);

    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            printf("Matriz[%d][%d]?\n", i,j);
            scanf("%d", &matriz[i][j]);
        }
    }
   

    printf("Número de elementos é %d x %d\n\n",linhas,colunas);
    
    for (int i=0; i<linhas;i++){
        for(int j=0; j<colunas; j++){
            printf("%5d", matriz[i][j]);
    }
        printf("\n\n");
   }


    return 0;
}