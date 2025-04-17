#ifndef LISTA_H
#define LISTA_H


typedef struct clienteInfo
{
    char nome[50];
    int bloco,servico;
    
}clienteInfo_type;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////// ESTRUTURAS DE RESERVA /////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct noLista
{
    clienteInfo_type cliente;
    struct noLista * prox;
    
}noLista_type;

typedef noLista_type * pLista_type; // Cria ponteiro pReserva que aponta para a lista de Reservas


clienteInfo_type perguntar_servico(clienteInfo_type cliente); // FEITO
pLista_type criaLista(); // FEITO
int vaziaLista (pLista_type lista); // FEITO
pLista_type destroiLista (pLista_type lista); // FEITO
void procuraNome (pLista_type lista, char nome[50], pLista_type *ant, pLista_type *actual);// FEITO
void procuraBloco (pLista_type lista, int bloco, pLista_type *ant, pLista_type *actual); // FEITO
void procuraNomeNum (pLista_type lista, char nome[50], pLista_type *ant, pLista_type *actual,int numReserva);
void elimina (pLista_type listaPrereserva, pLista_type listaReserva, char nome[50]); // FEITO
void insereLista(pLista_type listaReserva, pLista_type listaPrereserva, clienteInfo_type cliente); // FEITO
pLista_type pesquisa (pLista_type lista, char nome[50]); // FEITO
void imprimeTudo (pLista_type listaReserva, pLista_type listaPrereserva); // Feito
void imprimeCliente (pLista_type listaReserva,char nome[50], pLista_type listaPrereserva); // FEITO
pLista_type carregarLista(const char* nomeArquivo);
void salvarLista(pLista_type listaReserva, const char* nomeArquivo);
void executarServico(pLista_type listaReserva);






#endif