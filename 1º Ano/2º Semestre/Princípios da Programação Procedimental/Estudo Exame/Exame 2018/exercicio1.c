#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 100
typedef struct no_carro * ListaCarros;
struct no_carro{
 char marca[MAX];
 int potencia;
 ListaCarros next;
};
typedef struct pessoa * ListaPessoas;
struct pessoa{
 char nome[MAX];
 int idade;
 ListaPessoas next;
};
typedef struct no_apont_pessoa * ListaApontPessoas;
struct no_apont_pessoa{
 ListaPessoas pessoa;
 ListaApontPessoas next;
};
typedef struct no_conjunto * ListaConjuntos;
struct no_conjunto{
 ListaApontPessoas piloto;
 ListaApontPessoas copiloto;
 ListaCarros carro;
 ListaConjuntos next;
};

void main(){
  ListaCarros carros,novoCarro;
  ListaPessoas pessoas;
  ListaApontPessoas pilotos, copilotos,novoPiloto,novoCopiloto;
  ListaConjuntos conjuntos;

  listarConjuntos(conjuntos);

  conjuntos = insereConjunto(conjuntos, novoCarro, novoPiloto,novoCopiloto);
  return 0;
}

void listarConjuntos (ListaConjuntos conj)
{
  // Salta o Header
  conj->next;

  while( conj->next != NULL)
  {

    printf(" Modelo carro: %s\n", conj->carro->marca);
    printf("Potência do carro: %d\n",conj->carro->potencia);
    printf("Piloto: %s,%d  Copiloto: %s,%d \n", conj->piloto->pessoa->nome, conj->piloto->pessoa->idade, conj->copiloto->pessoa->nome, conj->copiloto->pessoa->idade);
    





    conj->carro = conj->carro->next;
    conj->copiloto = conj->copiloto->next;
    conj->piloto = conj->copiloto->next;

  }
}

ListaConjuntos insereConjunto (ListaConjuntos conj, ListaCarros novoCarro,ListaApontPessoas novoPiloto, ListaApontPessoas novoCopiloto)
{
  ListaConjuntos ant,atual,novo;
  
  novo = (ListaConjuntos)malloc(sizeof(struct no_conjunto));

  novo->carro=novoCarro;
  novo->piloto=novoPiloto;
  novo->copiloto=novoCopiloto;
  novo->next = NULL;

  ant= conj; atual= atual->next;

  while ( (atual != NULL) && (ant->carro->potencia<= novoCarro->potencia) )
  {
    //Verifica se a potencia do carro atual na lista é maior que a do novoCarro a inserir na lista
    if (atual->carro->potencia > novoCarro->potencia)
    {
     // Aponta o nó anterior para o novo nó, e aponta o novo nó para o nó actual
      ant->next=novo;
      novo->next=atual;
      return conj;
    }
    //Verifica se a potencia do carro atual  na lista é igual à do novo carro a inserir na lista
    else if (atual->carro->potencia == novoCarro->potencia)
    {
      if(atual->piloto->pessoa->idade >= novoPiloto->pessoa->idade)
      {
        novo->next = atual->next;
        atual->next = novo;
        return conj;
      }
      else if (atual->piloto->pessoa->idade < novoPiloto->pessoa->idade)
      {
        ant->next = novo;
        novo->next = atual;
        return conj;
      }
    }
    else
    {
      ant=ant->next;
      conj=conj->next;
    }
  }

  while (atual->next != NULL)
  {
    ant =ant->next;
    atual = atual->next;
  }

  if (atual->next == NULL)
  {
    atual->next=novo;
    return conj;
  }
}
