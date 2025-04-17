#include <stdio.h>

int main(){
    int matriz[5][5]={0};
    int linha,coluna;
    int  lin_col_igual=0;

    for (int i= 0; i<5; i++){

        for (int j=0; j<5; j++){
            if (lin_col_igual ==1)
            {
                matriz[i][j] = (j+2)*10 ;
                
            }
            if (lin_col_igual == 0){}
            {

                matriz[i][j] = ((-1)*j +5)*10 ;

                if (i==j)
                {
                    lin_col_igual=1 ;
                    matriz[i][j]=0 ;
                }
            }
            

            } 
            lin_col_igual=0;

        }




    for (int i= 0; i<5; i++){
        for (int j=0; j<5; j++){
                printf("%5d",matriz[i][j]);
            } 
            printf("\n");
        }


/*    while(1==1){
        printf("Primeira cidade?\n");
        scanf("%d",&linha);

        printf("Segunda cidade?\n");
        scanf("%d",&coluna);

        printf("A distância entre a cidade %d e a cidade %d é %d\n\n\n",linha,coluna,matriz[linha-1][coluna-1]);
    }



*/
    return 0;
}
