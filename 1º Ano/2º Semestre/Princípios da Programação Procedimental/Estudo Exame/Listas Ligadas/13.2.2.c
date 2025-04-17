#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_LENGTH 100
typedef struct contacto
{
  char nome[NOME_LENGTH];
  int numero_telefone;
}contacto_type;

typedef contacto_type * pContacto_type;

typedef struct noLista
{
  contacto_type contactoInfo;
  struct noLista * prox;
}noLista_type;

typedef noLista_type * pLista_type;

void insereLista(pLista_type lista);
void consultarLista(pLista_type lista);
void retiraLista(pLista_type lista);

int main()
{
  int opcao_menu=0;

  pLista_type lista = (pLista_type)malloc(sizeof(noLista_type));
  if (lista == NULL) {
  perror("Memória não disponível");
  free(lista);
  return 1;
  }

  strcpy(lista->contactoInfo.nome,"Header");
  lista->contactoInfo.numero_telefone=-1;

  while(1)
  {
    printf("1) Inserir na Lista \n2) Retirar da Lista \n3) Consultar a lista \n0) Sair\n");
    scanf("%d",&opcao_menu);
    fflush(stdin);

    switch (opcao_menu)
    {
    case 1:
    {
      insereLista(lista);
    }
      break;
    
    case 2:
    {
      retiraLista(lista);
    }
      break;
    
    case 3:
      consultarLista(lista);
      break;
    
    case 0:
      return 0;
    
    default:
      printf("Opção não válida");
    }

  }




  return 0;
}

void insereLista(pLista_type lista)
{
int numTelefone_temp;


  pLista_type novoNo = (pLista_type)malloc(sizeof(noLista_type));
  if (novoNo == NULL)
  {
    perror("Memória não disponível");
    free(novoNo);
    return;
  }

  printf("Introduza o nome do contacto: ");
  fgets((novoNo->contactoInfo.nome),NOME_LENGTH,stdin);
  novoNo->contactoInfo.nome[strcspn(novoNo->contactoInfo.nome, "\n")] = 0;


  printf("Introduza o contacto telefónico de %s: ", novoNo->contactoInfo.nome);
  scanf("%d",&numTelefone_temp);
  fflush(stdin);
  novoNo->contactoInfo.numero_telefone = numTelefone_temp;

  pLista_type actual = lista;

  while(actual != NULL)
  {
    
    if(actual->prox != NULL && strcasecmp(actual->prox->contactoInfo.nome,novoNo->contactoInfo.nome)>0)
    {
      novoNo->prox = actual->prox;
      actual->prox = novoNo;
      return;
    }
    else if(actual->prox == NULL)
    {
      novoNo->prox = actual->prox;
      actual->prox = novoNo;
      return;
    }

    actual= actual->prox;
  }
  
  
  
}

void consultarLista(pLista_type lista)
{
  pLista_type atual = lista->prox; // Salta o Header

  while (atual != NULL)
  {
    printf("Contacto\nNome: %s\nNúmero:%d\n\n",atual->contactoInfo.nome,atual->contactoInfo.numero_telefone);
    atual = atual->prox;
  }
}

void retiraLista(pLista_type lista)
{
  pLista_type atual = lista->prox; // Salta o Header
  int escolha;

  int cont=1;
  while (atual != NULL)
  {

    printf("Contacto Nº %d \nNome: %s\nNúmero:%d\n\n",cont,atual->contactoInfo.nome,atual->contactoInfo.numero_telefone);
    atual = atual->prox;
    cont++;
  }
  
  printf("Qual o nº do contacto que deseja eliminar?\n");
  scanf("%d",&escolha);

  atual = lista->prox;
  pLista_type ant = lista;
  cont=1;
  while(atual != NULL)
  {
    if (cont==escolha)
    {
      ant->prox= atual->prox;
      free(atual);
      return;
    }
    cont++;
    atual= atual->prox;
    ant= ant->prox;
  }
}