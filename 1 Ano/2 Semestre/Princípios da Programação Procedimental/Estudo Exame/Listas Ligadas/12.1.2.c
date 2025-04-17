#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noPilha
{
  int num;
  struct noPilha * prox;
}noPilha_type;

typedef noPilha_type * pPilha_type;



int main()
{
  pPilha_type pilha = (pPilha_type)malloc(sizeof(noPilha_type));
  if (pilha == NULL)
  {
    perror("Memória não disponível");
    return 1;
  }

  pPilha_type pilha_temp;

  int digito;

  while(1)
  {
    printf("Introduza um número >=0 (Outros valores param o programa): ");
    scanf("%d",&digito);
    printf("\n");

    if(digito<0) break;
    else{
      pilha_temp = (pPilha_type)malloc(sizeof(noPilha_type));

      pilha_temp->num=digito;
      pilha_temp->prox=pilha;
      pilha=pilha_temp;
    }  
  }


  while(pilha != NULL)
  {
    pilha_temp = pilha;
    printf("Digito: %d\n", pilha_temp->num);
    pilha=pilha_temp->prox;
    free(pilha_temp);
  }

  return 0;
}