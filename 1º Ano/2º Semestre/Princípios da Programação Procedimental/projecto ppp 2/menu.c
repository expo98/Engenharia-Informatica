#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

// TODO 
// INDTRODUZIR DATAS 
// COMPOR A NÃO INSERÇÃO DO NÓ NA LISTA
// SUBSTITUIR os pPrereserva e pReserva POR OUTRO NOME E DEIXA-LOS NA MESMA ESTRUTURA
// QUANDO FECHA PROGRAMA


static const char ficheiro_reservas[] ="reservas.txt";
static const char ficheiro_prereservas[] ="prereservas.txt";

int main()
{
    pLista_type listaReserva = criaLista();

    pLista_type listaPrereserva = criaLista(); // Header node das Pre-Reservas

    int opcao_menu=-1;

do
{
    printf("1) Adicionar serviço\n2) Cancelar Reserva\n3) Listar Reserva e Pré-Reserva (por data)\n4) Listar Reservas e Pré-Reservas de Cliente\n5) Executar serviço\n6) Guardar num ficheiro\n7) Carregar ficheiro\n0) Terminar programa\n\n");
    printf("Input: ");
    scanf("%d", &opcao_menu);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    switch (opcao_menu) {
        case 1:
            // ADICIONAR SERVICO
            {
                clienteInfo_type clienteTemp = {"",-1,-1};
                clienteTemp = perguntar_servico(clienteTemp);
                insereLista(listaReserva, listaPrereserva, clienteTemp);
            }
            break;

        case 2:
            // Cancelar_Reserva
            {
                char nome[50];
                printf("Introduza o nome do cliente: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                printf("\n");
                elimina(listaPrereserva,listaReserva, nome);

                //Verificar se há alguma pré-reserva que caiba no buraco agora criado

            }
            break;

        case 3: 
            // Listar Reservas e Pré-Reservas (por data)
            imprimeTudo(listaReserva, listaPrereserva);
            break;

        case 4:
            // Listar Reservas e Pré-Reservas de Cliente
            {
                char nome[50];
                printf("Introduza o nome do cliente: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                printf("\n");
                imprimeCliente(listaReserva, nome, listaPrereserva);
            }
            break;

        case 5:
            // Executar serviço
            executarServico(listaReserva);
            break;

        case 6:
            // Guardar listas num ficheiro
            salvarLista(listaReserva, ficheiro_reservas);
            salvarLista(listaPrereserva, ficheiro_prereservas);


            break;

        case 7:
            // Carregar listas dum ficheiro
            listaReserva= carregarLista(ficheiro_reservas);
            listaPrereserva = carregarLista(ficheiro_prereservas);
            break;
        case 0:
            //Termina o programa e  liberta toda a memória
            printf("Adeus!\n");
            destroiLista(listaReserva);
            destroiLista(listaPrereserva);
            return 1;

        default:
            printf("Escolha não válida\n");
            continue;
    }

} while(1);




    

    return 0;
}