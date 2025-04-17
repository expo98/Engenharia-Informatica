#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noPilha
{
  char string[50];
  struct noPilha * prox;
}noPilha_type;

typedef noPilha_type * pPilha_type;

int main()
{
  pPilha_type pilha = NULL;
  pPilha_type pilha_temp = NULL;

  // Introduz a string na pilha

  char string_temp[50];
  pilha_temp = pilha;
  while(1)
  {
    printf("Introduza uma string: ");
    fgets(string_temp,50,stdin);
    string_temp[strcspn(string_temp, "\n")] = 0;


    if (strcmp(string_temp,"FIM")==0) break;
    else
    {
      pilha_temp = (pPilha_type)malloc(sizeof(noPilha_type));
      if(pilha_temp == NULL)
      {
        perror("Memória não disponível");
        return 1;
      }

      strcpy(pilha_temp->string,string_temp);
      pilha_temp->prox=pilha;
      pilha=pilha_temp;
    } 
  }
  
  
  // Imprime as strings das pilhas e liberta a memória

  while(pilha!=NULL)
  {
    pilha_temp =pilha;
    printf("%s\n",pilha_temp->string);
    pilha = pilha_temp->prox;
    free(pilha_temp);
  }

  
  return 0;
}