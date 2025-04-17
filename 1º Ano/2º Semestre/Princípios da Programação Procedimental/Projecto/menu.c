#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

// TODO 
// ADICIONAR O RESTO DOS PROGRAMAS NO PRINTF DO MENU
// INDTRODUZIR DATAS 
// SUBSTITUIR os pPrereserva e pReserva POR OUTRO NOME E DEIXA-LOS NA MESMA ESTRUTURA
// CORRIGIR ERROS DE COMPILAÇÃO 
//FUNCAO EXECUTAR
// QUANDO FECHA PROGRAMA
// FUNCAO GUARDAR 
// FUNCAO CARREGAR

static const char nome_ficheiro[] ="savefile.txt";

int main()
{
    pReserva listaReserva = cria();

    pReserva listaPrereserva;
    listaPrereserva = cria(); // Header node das Pre-Reservas

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
            // PERGUNTAR PELAS CENAS DO SERVIÇO
            {
                clienteInfo clienteTemp = {"",-1,-1};
                perguntar_servico(clienteTemp);

                printf("Before calling insereReserva\n");
                insereReserva(listaReserva, clienteTemp);
                printf("After calling insereReserva\n");
            }
            break;

        case 2:
            // Cancelar_Reserva
            // PERGUNTAR PELO SERVICO
            {
                char nome[50];
                printf("Introduza o nome do cliente: ");
                fgets(nome, 50, stdin);
                printf("\n");
                elimina(listaReserva, nome);
            }
            break;

        case 3: 
            // Listar Reservas e Pré-Reservas (por data)
            if(vazia(listaReserva)==1) printf("Vazia");
            imprimeTudo(listaReserva);
            break;

        case 4:
            // Listar Reservas e Pré-Reservas de Cliente
            {
                char nome[50];
                printf("Introduza o nome do cliente: ");
                fgets(nome, 50, stdin);
                printf("\n");
                imprimeCliente(listaReserva, nome);
            }
            break;

        case 5:
            // Executar serviço
            executarServico(listaReserva);
            break;

        case 6:
            // Guardar listas num ficheiro
            salvarLista(listaReserva, nome_ficheiro);

            break;

        case 7:
            // Carregar listas dum ficheiro
            listaReserva= carregarLista(nome_ficheiro);
            break;
        default:
            printf("Escolha não válida\n");
            continue;
    }

} while(opcao_menu !=0);


        //case 0:
        destroi(listaPrereserva);
        destroi(listaReserva);

    
    
    return 0;
}