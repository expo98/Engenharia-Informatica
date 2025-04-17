#ifndef LISTAPING_H
#define LISTAPING_H

typedef struct data {
    int dia;
    int mes;
    int ano;
} data;

typedef struct socio {
    int numero;
    char nome [30];
    int idade;
    char profissao [20];
    char morada [50];
    data d;
    double quota;
} socio;

typedef struct noLista {
    socio s;
    struct noLista * prox;
} noLista;

typedef noLista * pLista;

typedef struct noListaAux { // Lista auxiliar
    pLista paux; // ponteiro para elemento da lista principal
    struct noListaAux *prox;
}noListaAux;

typedef noListaAux * pListaAux;

pLista cria ();

int vazia (pLista lista) ;

pLista destroi (pLista lista);

void procura (pLista lista, int n, pLista *ant, pLista *actual);

void elimina (pLista lista, int n);

void insere (pLista lista, socio s1) ;

pLista pesquisa (pLista lista, int n);

void imprime (pLista lista);

pListaAux criaAux ();

int vaziaAux (pListaAux listaAux) ;

pListaAux destroiAux (pListaAux listaAux);

void procuraAux (pListaAux listaAux, char *n, pListaAux *ant, pListaAux *actual);

void insereAux (pListaAux listaAux, pLista lista) ;

void imprimeAux (pListaAux listaAux);

#endif

