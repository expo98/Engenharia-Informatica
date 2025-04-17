#include <stdio.h>
#include "ListaPing.h"

int main(){
    pLista l, l1;
    pListaAux a;

    l = cria(); // lista principal, ordenada por números
    a = criaAux(); // lista auxiliar, ordem alfabética

    socio s1 = {1, "Xavier", 20, "Estudante", "Coimbra", {1, 1, 2022}, 10};
    socio s2 = {3, "Maria", 20, "Prof", "Coimbra", {1, 1, 2022}, 0};
    socio s3 = {2, "Jose", 20, "Estudante", "Coimbra", {1, 1, 2022}, 20};
    
    insere (l, s1); 
    insere (l, s2); 
    insere (l, s3);

    l1 = l->prox;
    while (l1 != NULL){
        insereAux(a, l1);
        l1 = l1->prox;
    }

    imprime (l); // lista principal

    imprimeAux(a); // lista auz«xiliar

    a = destroiAux(a);
    l = destroi(l);
    return 0;
}