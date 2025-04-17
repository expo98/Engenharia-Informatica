#include <stdio.h>
#include <stdlib.h>

typedef struct nolistaNum
{
  int num;
  struct nolistaNum * prox;
}nolistaNum_type;

typedef nolistaNum_type * plistaNum_type;

int main()
{
  plistaNum_type  lista1,lista2,lista3;
  lista1 = (plistaNum_type)malloc(sizeof(nolistaNum_type));
  lista1->prox=NULL;
  lista2 = (plistaNum_type)malloc(sizeof(nolistaNum_type));
  lista2->prox=NULL;
  lista3 = (plistaNum_type)malloc(sizeof(nolistaNum_type));
  lista3->prox=NULL;


  plistaNum_type lista1_temp,lista2_temp,lista3_temp;

  //Adiciona número a lista 1
  int lista1Num=0;
  printf("Irá agora introduzir vários números, quando quiser parar, introduza um qualquer número negativo.\n");

  lista1_temp = lista1;

  while(1)
  {
    printf("Introduza um número para a Lista1: ");
    scanf("%d",&lista1Num);
    fflush(stdin);
    if(lista1Num>=0)
   {
      lista1_temp->num = lista1Num;
      lista1_temp->prox= (plistaNum_type)malloc(sizeof(nolistaNum_type));
      lista1_temp= lista1_temp->prox;
      lista1_temp->prox=NULL;
   }
   else break;
  }


  //Adiciona números a lista 2
  int lista2Num=0;
  printf("Irá agora introduzir vários números, quando quiser parar, introduza um qualquer número negativo.\n");

  lista2_temp = lista2;
  
  while(lista2Num >=0)
  {
    printf("Introduza um número para a Lista2: ");
    scanf("%d",&lista2Num);
    fflush(stdin);
    if(lista2Num >=0)
    {
    lista2_temp->num = lista2Num;
    lista2_temp->prox = (plistaNum_type)malloc(sizeof(nolistaNum_type));
    lista2_temp= lista2_temp->prox;
    lista2_temp->prox=NULL;
    }
    else break;
  }



  // Verifica se há intersecção entre a lista1 e lista2

 int repete=0;


  lista1_temp = lista1;
  lista3_temp= lista3;

  while (lista1_temp!= NULL)
  {
    lista2_temp = lista2; 
    repete=0;
    while (lista2_temp != NULL)
    {

      if(lista1_temp->num == lista2_temp->num) 
      {
        repete++;
        break;
      }

      lista2_temp= lista2_temp->prox;
    }

    if(repete>0)
    {
    lista3_temp->num = lista1_temp->num;
    lista3_temp->prox = (plistaNum_type)malloc(sizeof(nolistaNum_type));
    lista3_temp= lista3_temp->prox;
    lista3_temp->prox=NULL;
    repete=0;
    }
     
    lista1_temp = lista1_temp->prox;
  }
  
  // Imprimir lista3

  lista3_temp= lista3;
  while (lista3_temp != NULL)
  {
    printf("%d\n",lista3_temp->num);
    lista3_temp=lista3_temp->prox;
  }
  
  // Libertar memória

  while(lista1 != NULL)
  {
    lista1_temp=lista1->prox;
    free(lista1);
    lista1=lista1_temp;
  }  
  
  while(lista2 != NULL)
  {
    lista2_temp=lista2->prox;
    free(lista2);
    lista2=lista2_temp;
  }  
  
  while(lista3 != NULL)
  {
    lista3_temp=lista3->prox;
    free(lista3);
    lista3=lista3_temp;
  }
  return 0;
}