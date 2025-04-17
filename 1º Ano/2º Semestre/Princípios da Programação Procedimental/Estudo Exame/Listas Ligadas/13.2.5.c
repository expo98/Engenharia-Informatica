#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define palavra_length 20
typedef struct listaPalavra
{
  char palavra[palavra_length*2]; // // A leitura é limitada a duas palavra_length para poder caber ambas as palavras, que medem apenas uma plavara_length cada
  struct listaPalavra * prox;
} listaPalavra_type;

typedef listaPalavra_type * pListaPalavra_type;

int main()
{
  pListaPalavra_type lista1 = (pListaPalavra_type)malloc(sizeof(listaPalavra_type));
  if(lista1 == NULL)
  {
    perror("Memória não disponível para lista1\n");
    return 0;
  }
  lista1->prox=NULL;

  pListaPalavra_type lista2 = (pListaPalavra_type)malloc(sizeof(listaPalavra_type));
  if(lista2 == NULL)
  {
    perror("Memória não disponível para lista2\n");
    return 0;
  }
  lista2->prox=NULL;

  int comprimentoLista;

  printf("Qual o nº de palavaras que cada lista deve ter?\n");
  scanf("%d",&comprimentoLista);
  fflush(stdin);


  //Inserir na lista1 as palavras

  pListaPalavra_type lista1_temp = lista1;

  for (int i = 0; i < comprimentoLista; i++)
  {
    printf("Introduza a palavara nº%d para a lista1:",i+1);
    fgets(lista1_temp->palavra,palavra_length,stdin); // A leitura é limitada a uma palavra_length para poder caber ambas as palavras
    lista1_temp->palavra[strcspn(lista1_temp->palavra, "\n")] = 0;
    printf("\n");

    // Aloca memória para o nó seguinte e NULLifica o ponteiro prox do nó seguinte
    lista1_temp->prox= (pListaPalavra_type)malloc(sizeof(listaPalavra_type));
    // Avança o nó temp, para o nó seguinte
    lista1_temp= lista1_temp->prox;
    lista1_temp->prox=NULL;
  }

  //Inserir na lista2 as palavras

  pListaPalavra_type lista2_temp = lista2;

  for (int i = 0; i < comprimentoLista; i++)
  {
    printf("Introduza a palavara nº%d para a lista2:",i+1);
    fgets(lista2_temp->palavra,palavra_length,stdin); // A leitura é limitada a uma palavra_length para poder caber ambas as palavras
    lista2_temp->palavra[strcspn(lista2_temp->palavra, "\n")] = 0;
    printf("\n");

    // Aloca memória para o nó seguinte e NULLifica o ponteiro prox do nó seguinte
    lista2_temp->prox= (pListaPalavra_type)malloc(sizeof(listaPalavra_type));

    // Avança o nó temp, para o nó seguinte
    lista2_temp= lista2_temp->prox;
    lista2_temp->prox = NULL;
  }
  
  // Concatenação de ambas as palavras

  //Define os ponteiros aos nós temporários na posição inicial das listas
  lista1_temp= lista1;
  lista2_temp = lista2;

  for (int i = 0; i < comprimentoLista; i++)
  {
    //Concatena a palavra da lista1 com a da lista2 e guarda em lista1
    strcat(lista1_temp->palavra,lista2_temp->palavra);

    //Avança o para o nó seguinte em lista1_temp e lista2_temp;
    lista1_temp=lista1_temp->prox;
    lista2_temp = lista2_temp->prox;
  }

  //Liberta memória da lista2 
  lista2_temp =lista2;

  while(lista2_temp != NULL)
  {
    lista2_temp=lista2->prox;
    free(lista2);
    lista2=lista2_temp;
  }
  
  //Imprime as palavras concatenadas
  lista1_temp=lista1;
  for (int i = 0; i < comprimentoLista; i++)
  {
    printf("Palavra nº%d : %s\n",i+1,lista1_temp->palavra);
    lista1_temp=lista1_temp->prox;
  } 

  //Liberta a lista 1
  lista1_temp =lista1;

  while(lista1_temp != NULL)
  {
    lista1_temp=lista1->prox;
    free(lista1);
    lista1=lista1_temp;
  }

  return 0;
}