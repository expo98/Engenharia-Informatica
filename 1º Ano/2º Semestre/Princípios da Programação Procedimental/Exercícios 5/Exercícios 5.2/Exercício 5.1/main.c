#include <stdio.h>

#define MAX 100

int main(){

    int array[MAX];
    int dimensao;
    int opcao;

    do
    {
        printf("Quantos números deve a sequência ter? \n");
        scanf("%d",&dimensao);
    } while (dimensao<1 || dimensao>100);
    
    printf("Irá agora introduzir os números da sequência!\n");

    for (int i=0; i<dimensao;i++){
        printf("Qual o %dº elemento?\n",i);
        scanf("%d",&array[i]);
    }

    
    printf("A sua sequência é: ");
    for (int i=0; i<dimensao;i++){
        printf("%5d",array[i]);
    }

   






    return 0;
}



int menu(int array,int const dimensao){

    int opcao;
    printf("Este programa tem as seguintes funcionalidades: \n");
    printf("1) Procurar o maior número da sequência\n");
    printf("2) Procurar o menor número da sequência\n");
    printf("3) Calcular o somatório da sequência\n");
    printf("4) Calcular a média da sequência\n");
    printf("5) Determinar a subsequência abaixo da média\n");
    printf("6) Determinar a subsequência acima da média\n");
    printf("7) Terminar o programa\n");

    scanf("%d",&opcao);
    
    switch (opcao)
    {
    case 1:
        {
            int maior_numero = array[0];
            for (int i = 1; i < dimensao; i++)
            {
                if (array[i]> maior_numero){
                    maior_numero = array[i];
                }
            }
            
        }
        
        break;
    
    case 2:
        {
            int menor_numero = array[0];
            for (int i=1; i<dimensao;i++){
                if (array[i]< menor_numero){
                    menor_numero = array[i];
                }
            }
        }

    case 3:

    case 4:

    case 5:

    case 6:

    case 7:
        exit();
        break;
    default:
        
        break;
    }

}