#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noLista * lista;

struct noLista{
  int num;
  lista next;
};
void insereLista(lista no, int num);
int minimo(lista no);
int maximo(lista no);
int media(lista no);

int main()
{
  int digito=0;

  lista no = (lista)malloc(sizeof(struct noLista));

  printf("Agora irá introduzir digitos para guardar numa lista (Introduza um valor inferior a 0 para parar)\n");
  for (int i = 1; digito >= 0 ; i++)
  {
    printf("Introduzar o digito #%d: ",i);
    scanf("%d",&digito);

    insereLista(no, digito);

    printf("\n");
  }

  int opcao_menu=0;
  while (1)
  {
  printf("1)Mínimo da lista \n 2)Máximo da lista \n 3)Média da lista \n 0) Terminar \n");
  printf("Input: ");
  scanf("%d",&opcao_menu);
  printf("\n");

  switch (opcao_menu)
  {
  case 1:
  {
    int min_num = minimo(no);
    printf("O mínimo da lista é %d\n",min_num);
    break;
  }
  case 2:
  {
    int max_num = maximo(no);
    printf("O máximo da lista é %d\n",max_num);
    break;
  }
  case 3:
  {
    int med_num = media(no);
    printf("A média da lista é %d\n",med_num);
    break;
  }
  case 0:
    printf(" Adeus!\n");
    return 0;
  
  default:
    break;
  }

  }
  
  
  

  return 0;
  
}

void insereLista(lista no, int num)
{
  lista novo_no = (lista)malloc(sizeof(struct noLista));
  novo_no->num = num;
  novo_no->next = NULL;

  if(no == NULL)
  {
    no = novo_no;
  }
  else
  {
    lista atual = no;
    while (atual->next != NULL)
    {
      atual = atual->next;
    }
    atual->next = novo_no;
  }
}


int media(lista no)
{
  int tamanho=0;
  int total=0;
  do
  {
    total += no->num;
    no = no->next;
    tamanho++;
  } while (no->next!=NULL);
  
  return (total/tamanho);
}

int minimo(lista no)
{
  lista atual;
  atual = no;
  int minimo = atual->num;
  atual=atual->next;

  while (atual->next != NULL)
  {
    if (atual->num < minimo)
    {
      minimo = atual->num;
    }
    atual = atual->next;
  }
  return minimo;  
}

int maximo(lista no)
{
  lista atual;
  atual = no;

  int maximo = atual->num;
  atual=atual->next;

  while(atual->next != NULL)
  {
    if(atual->num > maximo)
    {
      maximo = atual->num;
    }
    atual= atual->next;
  }

  return maximo;
}