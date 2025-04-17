#include <stdio.h>

#define MAX 100

void imprimir_tranposta(matriz)

int main(){
    int matriz_original[MAX][MAX] = {0};
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
            scanf("%d", &matriz_original[i][j]);
        }
    }
   

   void imprimir_tranposta(matriz_original);

}



void imprimir_tranposta(const int matriz[][MAX]){
    int linhas, colunas;

    linhas = sizeof(matriz)/sizeof(int);
    colunas = sizeof(matriz[0])/sizeof(int);


    printf("A matriz transposta é \n\n");

    for (int i=0; i<linhas;i++){
        for(int j=0; j<colunas; j++){
            printf("%d     ", matriz[j][i]);
    }
        printf("\n\n");
   }


    return;
}