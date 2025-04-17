#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

clienteInfo_type perguntar_servico(clienteInfo_type cliente) {

    int horas=0,minutos=0,opcao_min=0;

    printf("Nome do Cliente?\n");
    printf("Input: ");
    fgets(cliente.nome, 50, stdin);
    cliente.nome[strcspn(cliente.nome, "\n")] = '\0';

    while (cliente.servico != 1 && cliente.servico != 2) {
        printf("\nTipo de serviços\n 1) Lavagem\n 2) Manutenção\n\n");
        printf("Input: ");
        scanf("%d", &cliente.servico);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }


    while(horas<8 || horas >17){
    printf("Introduza o as horas (H) em HH:MM \n");
    printf("Input: ");
    scanf("%d",&horas);
    }

    while (opcao_min <1 || opcao_min >2)
    {
        /* code */
    
    if(horas<10){
    printf("1) 0%d:00 ou 2) 0%d:30\n",horas,horas);
    printf("Input: ");
    scanf("%d",&opcao_min);
    }
    else 
    {
        printf("1) %d:00 ou 2) %d:30\n",horas,horas);
        printf("Input: ");
        scanf("%d",&opcao_min);
    }
    }

    if (opcao_min == 1)
    {
    minutos=0;
    }
    if (opcao_min ==2)
    {
        minutos=30;
    }

    // CONVERTE HORARIO PARA BLOCOS de meia hora
    cliente.bloco = (horas - 8) * 2;
    if (minutos >= 30) {
        cliente.bloco += 2;
    } else {
        cliente.bloco += 1;
    }
    fflush(stdin);

    return cliente;
}


pLista_type criaLista (){
    pLista_type aux;
    aux = (pLista_type)malloc(sizeof(noLista_type));
    if (aux != NULL) {
        aux->cliente.nome[0] = '\0'; 
        aux->cliente.bloco = -1; 
        aux->cliente.servico = -1; 
        aux->prox = NULL;
    } else {
        perror("Memória não disponível para nó header");
    }
    return aux;
}


int vaziaLista (pLista_type lista) {
    if (lista->prox == NULL) return 1;
    else return 0;
}

pLista_type destroiLista (pLista_type lista){
    pLista_type temp_ptr;
    while (!vaziaLista (lista)) {
        temp_ptr = lista;
        lista = lista->prox;
        free (temp_ptr);
    }
    free(lista);
    return NULL;
}



void procuraNome (pLista_type lista, char nome[50], pLista_type *ant, pLista_type *actual){
    int counter=1;
    *ant = lista; *actual = lista->prox;
    while ((*actual) != NULL && strcmp((*actual)->cliente.nome, nome)==0) {

            int blocoInicial = (*actual)->cliente.bloco;
            int blocoFinal = (*actual)->cliente.bloco + (*actual)->cliente.servico - 1;

            printf("Reserva nº%d de %s\n",counter,nome);
            printf("Nome: %s\n", (*actual)->cliente.nome);

            int horaBaseInicial = 8;  
            int duracaoBlocoInicial = 30;  
            int minutosTotaisInicial = ((*actual)->cliente.bloco - 1) * duracaoBlocoInicial;  
            int horasInicial = horaBaseInicial + minutosTotaisInicial / 60; 
            int minutosInicial = minutosTotaisInicial % 60; 

            int horasFinal=0,minutosFinal=0;

            if (blocoInicial == blocoFinal)
            {
                minutosFinal = minutosInicial +30;
                if(minutosFinal == 60)
                {
                    minutosFinal =0;
                    horasFinal = horasInicial +=1;
                }
            }
            else if (blocoInicial == blocoFinal-1)
            {
                horasFinal = horasInicial+1;
                minutosFinal=minutosInicial;
            }
            

            printf("Horário: %02d:%02d - %02d:%02d \n",horasInicial,minutosInicial,horasFinal,minutosFinal);
            printf("\n\n");

        *ant = *actual;
        *actual = (*actual)->prox;
        counter +=1;
        
    }
    if ((*actual) != NULL && (strcmp((*actual)->cliente.nome, nome) !=0))
        *actual = NULL;   /* elemento não encontrado*/
}

void procuraNomeNum (pLista_type lista, char nome[50], pLista_type *ant, pLista_type *actual,int numReserva){
    int counter=1;
    *ant = lista; *actual = lista->prox;
    while ((*actual) != NULL && strcmp((*actual)->cliente.nome, nome)==0) {
        if (numReserva == counter) return;

        *ant = *actual;
        *actual = (*actual)->prox;
        counter +=1;
        
    }
    if ((*actual) != NULL && (strcmp((*actual)->cliente.nome, nome) !=0))
        *actual = NULL;   /* elemento não encontrado*/
}

void procuraBloco (pLista_type lista, int bloco, pLista_type *ant, pLista_type *actual){
    *ant = lista; *actual = lista->prox;
    while ((*actual) != NULL && (*actual)->cliente.bloco<bloco) {
        *ant = *actual;
        *actual = (*actual)->prox;
    }
    if ((*actual) != NULL && (*actual)->cliente.bloco != bloco)
        *actual = NULL;   /* elemento não encontrado*/
}

void elimina (pLista_type listaPrereserva, pLista_type listaReserva, char nome[50]){
    int num_reserva;
    pLista_type ant, actual,ant2,actual2;
    procuraNome (listaReserva, nome, &ant, &actual);

    printf("Qual o nº da reserva que desja cancelar?\n");
    printf("Input: ");
    scanf("%d",&num_reserva);
    printf("\n");


    procuraNomeNum (listaReserva, nome, &ant2, &actual2, num_reserva);

    if (actual2 != NULL) {
        ant2->prox = actual2->prox;
        free (actual2);
        printf("Reserva nº %d de %s cancelado\n",num_reserva,nome);


        // Move nós da listaPrereserva para listaReserva caso eles caibam nos novos espaços de tempo livre
        pLista_type prereserva_ant = NULL;
        pLista_type prereserva_atual = listaPrereserva;

        while (prereserva_atual != NULL) {
            int blocoInicial = actual2->cliente.bloco;
            int blocoFinal = actual2->cliente.bloco + actual2->cliente.servico - 1;

            int atualBlocoInicial = prereserva_atual->cliente.bloco;
            int atualBlocoFinal = prereserva_atual->cliente.bloco + prereserva_atual->cliente.servico - 1;

            if (atualBlocoInicial >= blocoInicial && atualBlocoFinal <= blocoFinal) {
                // Move o no de PreReserva para Reserva

                if (prereserva_ant != NULL) {
                    prereserva_ant->prox = prereserva_atual->prox;
                } else {
                    listaPrereserva = prereserva_atual->prox;
                }

                prereserva_atual->prox = NULL;

                if (listaReserva == NULL) {
                    listaReserva = prereserva_atual;
                } else {
                    pLista_type reserva_atual = listaReserva->prox;

                    while (reserva_atual != NULL) {
                        if(reserva_atual->prox->cliente.bloco > prereserva_atual->cliente.bloco)
                        {
                            prereserva_atual->prox=reserva_atual->prox;
                            reserva_atual->prox = prereserva_atual;
                            break;
                        }
                        if (reserva_atual->prox == NULL)
                        {
                            reserva_atual->prox = prereserva_atual;
                            prereserva_atual->prox= NULL;
                        }
                        
                        reserva_atual = reserva_atual->prox;
                    }

                }

                printf("Movido da lista de Pré-Reservas para a lista de Reservas: %s\n", prereserva_atual->cliente.nome);
                prereserva_atual = prereserva_ant != NULL ? prereserva_ant->prox : listaPrereserva;
            } else {
                prereserva_ant = prereserva_atual;
                prereserva_atual = prereserva_atual->prox;
            }
        }


    }
}

void inserePrereserva(pLista_type listaPrereserva, clienteInfo_type cliente)
{
    pLista_type no2, ant2, inutil2;
    no2 = (pLista_type)malloc(sizeof(noLista_type));

    if (no2!=NULL)
    {
        no2->cliente= cliente;
        procuraBloco(listaPrereserva,cliente.bloco,&ant2,&inutil2);

        pLista_type atualPrereserva = listaPrereserva;
        while (atualPrereserva != NULL)
        {
                int blocoInicial = cliente.bloco;
                int blocoFinal = cliente.bloco + cliente.servico - 1;

                int atualBlocoInicial = atualPrereserva->cliente.bloco;
                int atualBlocoFinal = atualPrereserva->cliente.bloco + atualPrereserva->cliente.servico - 1;

                if (blocoInicial >= atualBlocoInicial && blocoInicial <= atualBlocoFinal) {
                    printf("O horário que deseja já se encontra ocupado\n");
                    return;
                }
                else if (blocoFinal>= atualBlocoInicial && blocoFinal <= atualBlocoFinal){
                    printf("O horário que deseja já se encotnra ocupado\n");
                    return;
                }
                else if (blocoInicial >= atualBlocoInicial && blocoFinal <= atualBlocoFinal){
                    printf("O horário que deseja já se encotnra ocupado\n");
                    return;
                }

                else atualPrereserva = atualPrereserva->prox;
        }
        }
    else {
        perror("Memória não disponível");
        return;

    }

        no2->prox = ant2->prox;
        ant2->prox = no2;

}

void insereLista(pLista_type listaReserva, pLista_type listaPrereserva, clienteInfo_type cliente)
{

        pLista_type no, ant, inutil;
        no = (pLista_type)malloc(sizeof(noLista_type));

        if (no != NULL) {
            no->cliente = cliente;
            procuraBloco(listaReserva, cliente.bloco, &ant, &inutil);

            // Faz uma verificação se há alguma coincidência em horários,
            // Caso haja, pergunta se deseja ir para pré reserva e dá return
            pLista_type atualReserva = listaReserva;
            while (atualReserva != NULL) {

                int blocoInicial = cliente.bloco;
                int blocoFinal = cliente.bloco + cliente.servico - 1;

                int atualBlocoInicial = atualReserva->cliente.bloco;
                int atualBlocoFinal = atualReserva->cliente.bloco + atualReserva->cliente.servico - 1;

                if (blocoInicial >= atualBlocoInicial && blocoInicial <= atualBlocoFinal) {
                    printf("O horário que deseja já se encontra ocupado\n");
                    printf("Deseja ficar em Pré-Reserva? \n1) Sim  2) Não\n Input: ");
                    int escolha;
                    scanf("%d", &escolha);
                    if (escolha == 2) {
                        free(no); // Liberta o nó
                        return;
                    } else {
                        inserePrereserva(listaPrereserva,cliente);
                        return;
                    }
                } else if (blocoFinal >= atualBlocoInicial && blocoFinal <= atualBlocoFinal) {

                    printf("O horário que deseja já se encontra ocupado\n");
                        printf("Deseja ficar em Pré-Reserva? \n1) Sim  2) Não\n Input: ");
                        int escolha;
                        scanf("%d", &escolha);
                        if (escolha == 2) {
                            free(no); // Liberta o nó
                            return;
                        } else {
                            inserePrereserva(listaPrereserva,cliente);
                            return;
                        }
                    

                } else if (blocoInicial >= atualBlocoInicial && blocoFinal <= atualBlocoFinal) {
                    printf("O horário que deseja já se encontra ocupado\n");
                    printf("Deseja ficar em Pré-Reserva? \n1) Sim  2) Não\n Input: ");
                    int escolha;
                    scanf("%d", &escolha);
                        if (escolha == 2) {
                            free(no); // Liberta o nó
                            return;
                        } else {
                            inserePrereserva(listaPrereserva,cliente);
                            return;
                        }
                    
                }

                atualReserva = atualReserva->prox;
            }
        } else {
            perror("Memória não disponível");
            return;
        }


        // Adiciona à lista de Reservas
        no->prox = ant->prox;
        ant->prox = no;
    }





pLista_type pesquisa (pLista_type lista, char nome[50]){
    pLista_type ant, actual;
    procuraNome (lista, nome, &ant, &actual);
    return (actual);
}

void imprimeTudo(pLista_type listaReserva, pLista_type listaPrereserva) {
    /*
    pLista_type noReserva, noPrereserva;
    noReserva = (pLista_type)malloc(sizeof(noLista_type));
    noPrereserva = (pLista_type)malloc(sizeof(noLista_type));
*/
    // Salta os headers
    pLista_type noReserva = listaReserva;
    noReserva = noReserva->prox;
    pLista_type noPrereserva = listaPrereserva;
    noPrereserva = noPrereserva->prox;

    printf("\n\n\n");

    if(vaziaLista(listaReserva) !=1 ){
        if(noReserva != NULL) printf("RESERVAS:\n\n\n");

        while (noReserva != NULL) {
            printf("Nome: %s\n", noReserva->cliente.nome);
            printf("Bloco: %d\n", noReserva->cliente.bloco);

            int horaBase = 8;  
            int duracaoBloco = 30;  
            int minutosTotais = (noReserva->cliente.bloco - 1) * duracaoBloco;  
            int horas = horaBase + minutosTotais / 60; 
            int minutos = minutosTotais % 60; 
            printf("Horário: %02d:%02d\n",horas,minutos);

            if(noReserva->cliente.servico ==1) printf("Serviço: Lavagem\n");
            if(noReserva->cliente.servico ==2) printf("Serviço: Manutenção\n");

            printf("\n");

            noReserva = noReserva->prox; // Avança para o nó seguinte
        }
    } else printf("Reservas vazio\n\n");
    
    if(vaziaLista(listaPrereserva)!=1){    
        if(noPrereserva != NULL) printf("PRERESERVAS:\n\n\n");

        while(noPrereserva != NULL) {
            printf("Nome: %s\n", noPrereserva->cliente.nome);
            printf("Bloco: %d\n", noPrereserva->cliente.bloco);

            int horaBase = 8;  
            int duracaoBloco = 30;  
            int minutosTotais = (noPrereserva->cliente.bloco - 1) * duracaoBloco;  
            int horas = horaBase + minutosTotais / 60; 
            int minutos = minutosTotais % 60; 
            printf("Horário: %02d:%02d\n",horas,minutos);
            
            if(noPrereserva->cliente.servico ==1) printf("Serviço: Lavagem\n");
            if(noPrereserva->cliente.servico ==2) printf("Serviço: Manutenção\n");

            printf("\n");

            noPrereserva = noPrereserva->prox; // Avança para o nó seguinte
        }
    } else printf("Prereservas vazio\n\n");

}

void imprimeCliente (pLista_type listaReserva,char nome[50], pLista_type listaPrereserva){
    pLista_type atualReserva = listaReserva->prox; // Salta o header
    pLista_type atualPrereserva = listaPrereserva->prox; // Salta o Header

    if(atualReserva != NULL) printf("RESERVAS:\n\n\n");
    while (atualReserva != NULL) {
        if (strcmp(atualReserva->cliente.nome, nome)==0) {
            printf("Nome: %s\n", atualReserva->cliente.nome);
            printf("Bloco: %d\n", atualReserva->cliente.bloco);

            // Converte Blocos em horas
            int horaBase = 8;  
            int duracaoBloco = 30;  
            int minutosTotais = (atualReserva->cliente.bloco - 1) * duracaoBloco;  
            int horas = horaBase + minutosTotais / 60; 
            int minutos = minutosTotais % 60; 
            printf("Horário: %02d:%02d\n",horas,minutos);
            
            if(atualReserva->cliente.servico ==1) printf("Serviço: Lavagem\n");
            if(atualReserva->cliente.servico ==2) printf("Serviço: Manutenção\n");

            printf("\n");
        }

        atualReserva = atualReserva->prox; // Avança para o nó seguinte
    }

    if(atualPrereserva != NULL) printf("PRERESERVAS:\n\n\n");
    while (atualPrereserva != NULL) {
        if (strcmp(atualPrereserva->cliente.nome, nome)) {
            printf("Nome: %s\n", atualPrereserva->cliente.nome);
            printf("Bloco: %d\n", atualPrereserva->cliente.bloco);

            // Converte Blocos em horas
            int horaBase = 8;  
            int duracaoBloco = 30;  
            int minutosTotais = (atualReserva->cliente.bloco - 1) * duracaoBloco;  
            int horas = horaBase + minutosTotais / 60; 
            int minutos = minutosTotais % 60; 
            printf("Horário: %02d:%02d\n",horas,minutos);
            
            if(atualReserva->cliente.servico ==1) printf("Serviço: Lavagem\n");
            if(atualReserva->cliente.servico ==2) printf("Serviço: Manutenção\n");

            printf("\n");
        }
        atualPrereserva = atualPrereserva->prox; // Avança para o nó seguinte
    }
}




void salvarLista(pLista_type lista, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    pLista_type atual = lista->prox;
    while (atual != NULL) {
        fprintf(arquivo, "%s %d %d\n", atual->cliente.nome, atual->cliente.bloco, atual->cliente.servico);
        atual = atual->prox;
    }

    fclose(arquivo);
}

pLista_type carregarLista(const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    pLista_type lista_temp = criaLista();
    char nome[50];
    int bloco, servico;

    while (fscanf(arquivo, "%s %d %d", nome, &bloco, &servico) == 3) {
        pLista_type novo = (pLista_type)malloc(sizeof(noLista_type));
        if (novo == NULL) {
            perror("Erro ao alocar memória");
            fclose(arquivo);
            free(lista_temp);
            return NULL;
        }
        strcpy(novo->cliente.nome, nome);
        novo->cliente.bloco = bloco;
        novo->cliente.servico = servico;
        novo->prox = lista_temp->prox;
        lista_temp->prox = novo;
    }

    fclose(arquivo);
    return lista_temp;
}


void executarServico(pLista_type lista) {
    if (lista->prox == NULL) {
        printf("A lista de reservas está vazia.\n");
        return;
    }
    
    pLista_type primeiro = lista->prox; // Salta o Header


    

    printf("A executar o serviço... \n");
    printf("Nome: %s\n",primeiro->cliente.nome);
    printf("Bloco:%d",primeiro->cliente.bloco);

    if (primeiro->cliente.servico ==1)  printf("Serciço: Lavagem\n");
    else     printf("Serviço: Manutenção\n");

    int horaBase = 8;  
    int duracaoBloco = 30;  

    int minutosTotais = (primeiro->cliente.bloco - 1) * duracaoBloco;  

    int horas = horaBase + minutosTotais / 60; 
    int minutos = minutosTotais % 60; 
    printf("Horário: %02d:%02d",horas,minutos);


    lista->prox = primeiro->prox;
    free(primeiro);
}