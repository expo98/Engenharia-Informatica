#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaPing.h"

pLista cria (){
    pLista aux;
    socio s1 = {0, "", 0, "", "", {0, 0, 0}, 0};
    aux = (pLista) malloc (sizeof (noLista));
    if (aux != NULL) {
        aux->s = s1;
        aux->prox = NULL;
    }
    return aux;
}

int vazia (pLista lista) {
    if (lista->prox == NULL) return 1;
    else return 0;
}

pLista destroi (pLista lista){
    pLista temp_ptr;
    while (!vazia (lista)) {
        temp_ptr = lista;
        lista = lista->prox;
        free (temp_ptr);
    }
    free(lista);
    return NULL;
}

void procura (pLista lista, int n, pLista *ant, pLista *actual){
    *ant = lista; *actual = lista->prox;
    while ((*actual) != NULL && (*actual)->s.numero < n) {
        *ant = *actual;
        *actual = (*actual)->prox;
    }
    if ((*actual) != NULL && (*actual)->s.numero != n)
        *actual = NULL;   /* elemento não encontrado*/
}

void elimina (pLista lista, int n){
    pLista ant, actual;
    procura (lista, n, &ant, &actual);
    if (actual != NULL) {
        ant->prox = actual->prox;
        free (actual);
    }
}

void insere (pLista lista, socio s1) {
    pLista no, ant, inutil;
    no = (pLista) malloc (sizeof (noLista));
    if (no != NULL) {
        no->s = s1;
        procura (lista, s1.numero, &ant, &inutil);
        no->prox = ant->prox;
        ant->prox = no;
    }
}

pLista pesquisa (pLista lista, int n){
    pLista ant, actual;
    procura (lista, n, &ant, &actual);
    return (actual);
}

void imprime (pLista lista){
    pLista aux = lista->prox; /* Salta o header */
    while (aux) {
        printf("%d  %s\n", aux->s.numero, aux->s.nome);
        aux = aux->prox;
    }
}

/*--------- Lista auxiliar --------------*/

pListaAux criaAux (){
    pListaAux aux;
    aux = (pListaAux) malloc (sizeof (noListaAux));
    if (aux != NULL) {
        aux->paux = NULL;
        aux->prox = NULL;
    }
    return aux;
}

int vaziaAux (pListaAux listaAux){
    if (listaAux->prox == NULL) return 1;
    else return 0;
}

pListaAux destroiAux (pListaAux listaAux){
    pListaAux temp_ptr;
    while (!vaziaAux (listaAux)) {
        temp_ptr = listaAux;
        listaAux = listaAux->prox;
        free (temp_ptr);
    }
    free(listaAux);
    return NULL;
}

void procuraAux (pListaAux listaAux, char *n, pListaAux *ant, pListaAux *actual){
  *ant = listaAux; *actual = listaAux->prox;
    while ((*actual) != NULL && strcmp((*actual)->paux->s.nome, n)<0) {
        *ant = *actual;
        *actual = (*actual)->prox;
    }
    if ((*actual) != NULL && strcmp((*actual)->paux->s.nome, n)!=0)
        *actual = NULL;   /* elemento não encontrado*/
}

void insereAux (pListaAux listaAux, pLista lista) {
 pListaAux no, ant, inutil;
    no = (pListaAux) malloc (sizeof (noListaAux));
    if (no != NULL) {
        procuraAux (listaAux, lista->s.nome, &ant, &inutil);
        no->paux = lista;
        no->prox = ant->prox;
        ant->prox = no;
    }
}

void imprimeAux (pListaAux listaAux){
    pListaAux aux = listaAux->prox; /* Salta o header */
    while (aux) {
        printf("--> %s\n", aux->paux->s.nome);
        aux = aux->prox;
    }
}
