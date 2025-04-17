#include <stdio.h>

int const dimensao=5;
int matriz[dimensao][dimensao];

int valores_matriz();
int multi_matriz(int matriz);
void print_matriz(int matriz);



int main(){

    
    for (int i =0; i<dimensao; i++){
        for (int j=0; j<dimensao;j++){
            printf("Qual o valor para matriz[%d][%d]?\n",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }

    int multiplicador;
        


        printf("Por que valor deseja multiplicar a sua matriz?\n");
        scanf("%d",&multiplicador);

        for (int i=0; i<dimensao; i++){
            for (int j=0; j<dimensao; j++){
                matriz[i][j] *= multiplicador;
            }
        }

    for( int i=0; i<dimensao;i++){
        for (int j=0; j<dimensao; j++){
            printf("%5d",matriz[j][i]);
        }
        printf("\n\n");

    }





    return 0;
}

/*
int valores_matriz(){


    for (int i =0; i<dimensao; i++){
        for (int j=0; j<dimensao;j++){
            printf("Qual o valor para matriz[%d][%d]?\n",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }

    return matriz;
}

int multi_matriz(int matriz){

    int multiplicador;
    


    printf("Por que valor deseja multiplicar a sua matriz?\n");
    scanf("%d",&multiplicador);

    for (int i=0; i<dimensao; i++){
        for (int j=0; j<dimensao; j++){
            matriz[i][j] *= multiplicador;
        }
    }

    return matriz;
}

void print_matriz(int matriz){

    for( int i=0; i<dimensao;i++){
        for (int j=0; j<dimensao; j++){
            printf("%d",matriz[i][j]);
        }
    }
    return;
} */