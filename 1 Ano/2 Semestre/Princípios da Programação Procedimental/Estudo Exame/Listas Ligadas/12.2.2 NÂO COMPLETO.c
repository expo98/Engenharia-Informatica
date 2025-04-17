#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct noPilha
{
  int inteiro;
  struct noPilha * prox;
}noPilha_type;

typedef noPilha_type * pPilha_type;

void duplicarTopo(pPilha_type pilha);
void consultarTopo(pPilha_type pilha);
void trocarTopo(pPilha_type pilha);

int main()
{

  pPilha_type pilha = NULL;
  pPilha_type pilha_temp = NULL;

  // Inserção de inteiro na pilha
  int digito;
  while(1)
  {
    printf("Introduza um digito (<0 para terminar): ");
    scanf("%d",&digito);
    printf("\n");
    if (digito<0) break;
    
    else
    {
      pPilha_type pilha_temp = (pPilha_type)malloc(sizeof(noPilha_type));
      if(pilha_temp == NULL)
      {
        perror("Memória não disponível");
        return 1;
      }
      pilha_temp->inteiro = digito;
      pilha_temp->prox=pilha;
      pilha = pilha_temp;
    }
  }
  printf("\n\n");

  // Imprimir a pilha inicialmente
  pilha_temp = pilha;
  printf("Pilha inicial\n");
  while(pilha_temp!=NULL)
  {
    printf("%d",pilha_temp->inteiro);
    pilha_temp=pilha_temp->prox;
  }
  printf("\n\n");

  //Consultar topo
  consultarTopo(pilha);
  printf("\n\n");
/*
  //Trocar o topo
  trocarTopo(pilha);

  pilha_temp = pilha;
  //Imprimir a pilha
  printf("Pilha topo trocado\n");
  while(pilha_temp!=NULL)
  {
    printf("%d",pilha_temp->inteiro);
    pilha_temp=pilha_temp->prox;
  }
  printf("\n\n");
*/
  //Duplica o topo
  duplicarTopo(pilha);

  pilha_temp = pilha;
  //IMmprimir a pilha;
  printf("Pilha com topo duplicado\n");
  while(pilha_temp!=NULL)
  {
    printf("%d",pilha_temp->inteiro);
    pilha_temp=pilha_temp->prox;
  }
  printf("\n\n");

  //Libertar memória
  while(pilha!=NULL)
  {
    pilha_temp=pilha;
    pilha=pilha_temp->prox;
    free(pilha_temp);
  }

}

void duplicarTopo(pPilha_type pilha)
{
  pPilha_type novoNo = (pPilha_type)malloc(sizeof(noPilha_type));
  if(novoNo== NULL)
  {
    perror("Memória não disponível");
    return ;
  }

  novoNo->inteiro= pilha->inteiro;
  novoNo->prox= pilha;

  pilha=novoNo;
}

void consultarTopo(pPilha_type pilha)
{
  pPilha_type pilha_temp = pilha;
  printf("O número no topo é %d\n",pilha_temp->inteiro);
}


/*void trocarTopo(pPilha_type pilha)
{
  pPilha_type no1,no1_next,no2,no2_next,no3;
  pPilha_type inutil = (pPilha_type)malloc(sizeof(noPilha_type));
  inutil->inteiro=NULL;
  inutil->prox = no1;

  no1=pilha;
  no1_next=pilha->prox;
  no2=no1->prox;
  no2_next=no2->prox;


  no1->prox=no2_next;
  no2_next=inutil->prox;

  pilha=no2;


}
*/
