#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct clientInfo
{
    char nome[50];
    int ano,mes,dia;
    int bloco,servico;
}clientInfo;

typedef struct no
{
    clientInfo cliente;
    int prioridade; // 1- reserva 2- pré-reserva
    struct no *next;
}no_reserva;

typedef struct 
{
    no_reserva *head;
    no_reserva *tail;
} tipoFila;

void cria(tipoFila *fila);  

int main()
{
    char nome[50];
    int ano=0,mes=0,dia=0;
    int horas=0,minutos=-1,bloco=0;
    int servico=0; // duracao

    printf("Nome do Cliente? ");
    fgets(nome,50,stdin);

    while (servico != 1 && servico != 2)
    {            
    printf("\nTipo de serviços \n 1) Lavagem \n 2) Manutenção\n");
    scanf("%d",&servico);
    }
    
    printf("\nPara que horas o serviço?\n ");
    while (horas<8 || horas>17)
    {        
    printf("\nIntroduza a hora (sem os minutos)\n");
    scanf("%d",&horas);
    }
    while (minutos != 00 && minutos != 30)
    {
        printf("Introduza os minutos\n");
        scanf("%d", &minutos);
    }

    // CONVERTER O HORARIO DE INICIO EM BLOCO DE HORARIO    
    bloco = (horas-9);
    if (minutos==30)
    {
        bloco+=1;
    }


    
// VERIFICAR SE EXISTE ALGUM NÓ COM PRIORIDADE 1 QUE ESTEJA NO HORARIO DO SERVICO
// SE NÃO, METER NA LISTA DE RESERVAS (PRIORIDADE 1)
// SE SIM, PERGUNTAR SE QUER METER NA LISTA DE PRÉ-RESERVAS (PRIORIDADE 2)
    no_reserva *auxiliar;
    auxiliar = (no_reserva *) malloc(sizeof (no_reserva));
    no_reserva *auxiliar2;
    auxiliar2 = (no_reserva *) malloc(sizeof(no_reserva));

    while (auxiliar->next !=NULL || auxiliar2 != NULL;)
    {
        //Se já exisitir uma reserva no mesmo horário, verifica se 
        if ((auxiliar->cliente.bloco >= bloco) && (bloco <= (auxiliar->cliente.bloco + auxiliar->cliente.servico-1)) && (auxiliar->prioridade==1))
        {
            // Adiciona a informação à struct do cliente
            no_reserva * temp_ptr;
            temp_ptr = (no_reserva *) malloc(sizeof (no_reserva));
            clientInfo cliente;
            temp_ptr->prioridade=2; // Prioridade 2 -> 
            strcpy(cliente.nome, nome);
            cliente.bloco=bloco;
            cliente.servico=servico;
        }
        else
        {
            // Adiciona a informação à struct do cliente
            no_reserva * temp_ptr;
            temp_ptr = (no_reserva *) malloc(sizeof (no_reserva));
            clientInfo cliente;
            temp_ptr->prioridade=1;
            strcpy(cliente.nome, nome);
            cliente.bloco=bloco;
            cliente.servico=servico;
        }
        

        auxiliar=auxiliar->next;
    }
    

    
    free(auxiliar);
    free(temp_ptr);

    
    return 0;
}