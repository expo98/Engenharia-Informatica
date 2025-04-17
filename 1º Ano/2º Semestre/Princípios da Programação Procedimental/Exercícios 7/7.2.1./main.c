#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
    int dia,mes,ano;
} data;

int main(){

    data datas[3];
    for (int i = 0; i < 3; i++) datas[i].ano = 2023;
    
    datas[0].dia = 27;
    datas[0].mes = 4;

    datas[1].dia = 22;
    datas[1].mes = 9;
    
    datas[2].dia = 22;
    datas[2].mes = 12;

    int request;
    printf("Deseja procurar a sua data por:\n 1) Dia    2) Mês   3) Ano\n ");
    scanf("%d", &request);

    if ( request == 1)
    {
        printf("Introduza o dia que pretene procurar:\n");
        int dia;
        scanf("%d", &dia);
        for (int i = 0; i < 3; i++ )
        {
            if (datas[i].dia == dia)
            {
                printf("%d/%d/%d\n", datas[i].dia, datas[i].mes, datas[i].ano);
            }
            
        }
        
    }
    else if ( request == 2)
    {
        printf("Introduza o mes que pretene procurar:\n");
        int mes;
        scanf("%d", &mes);
        for (int i = 0; i < 3; i++ )
        {
            if (datas[i].mes == mes)
            {
                printf("%d/%d/%d\n", datas[i].dia, datas[i].mes, datas[i].ano);
            }
            
        }
    }

    else if (request == 3)
    {
        printf("Introduza o ano que pretene procurar:\n");
        int ano;
        scanf("%d", &ano);
        for (int i = 0; i < 3; i++ )
        {
            if (datas[i].ano == ano)
            {
                printf("%d/%d/%d\n", datas[i].dia, datas[i].mes, datas[i].ano);
            }
            
        }
        
    }
    else { printf("Opção não válida\nA terminar programa...\n"); return 0;}
    
    
    
    
    
 
    
    return 0;
}

