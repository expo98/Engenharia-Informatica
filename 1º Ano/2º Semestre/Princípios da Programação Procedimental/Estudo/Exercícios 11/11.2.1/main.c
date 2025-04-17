#include <stdio.h>
#include <stdlib.h>
struct num
{
    int isNull;
    int numero;
};
typedef struct noFila
{
    struct num numFila;
    struct noFila *prox;
}noFila;

typedef struct 
{
    noFila *inicio;
    noFila *fim;
} tipoFila;

void cria(tipoFila *fila);
int vazia(tipoFila *fila);
void destroi(tipoFila *fila);
void insere(tipoFila *fila, struct num n1);
struct num  retira(tipoFila *fila);
void insere_vetor(tipoFila *fila,struct num elemento, int *vetor,int size);


int main()
{
    int N;
    tipoFila *ptrFila;
    struct num elemento;


    printf("Introduza quantos elementos quer na fila: ");
    scanf("%d",&N);

    int *vetor = (int * ) malloc(sizeof(int)* N);
    ptrFila = (tipoFila *) malloc(sizeof(tipoFila));

    cria(ptrFila);

    void insere_vetor(elemento,ptrFila, vetor, N);
    
    noFila *atual = ptrFila->inicio;
    while (atual != NULL)
    {
        printf("Output %d \n",atual->numFila.numero);
        atual=atual->prox;
    }

    elemento = retira(ptrFila);

    if(elemento.isNull)
    {
        printf("A fila está vazia");
        return -1;
    }

    atual = ptrFila->inicio;

    while(atual != NULL)
    {
        printf("Output: %d \n", atual->numFila.numero);
        atual = atual->prox;
    }

    destroi(ptrFila);
    free(ptrFila);

    return 0;

}

void cria(tipoFila *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
}

int vazia(tipoFila *fila)
{
    if (fila->inicio == NULL) return 1;
    else return 0;
}

void destroi(tipoFila *fila)
{
    noFila * temp_ptr;
    while(!vazia(fila))
    {
        temp_ptr = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(temp_ptr);
    }

    fila->fim = NULL;
}

void insere(tipoFila *fila, struct num n1   )
{
    noFila * temp_ptr;
    temp_ptr = (noFila *) malloc(sizeof (noFila));
    if (temp_ptr != NULL)
    {
        temp_ptr->numFila = n1;
        temp_ptr->prox = NULL;
        if(vazia(fila))
            fila->inicio = temp_ptr;
        else fila->fim->prox = temp_ptr;
        fila->fim = temp_ptr;
    }   
}

struct num  retira(tipoFila *fila)
{
    noFila * temp_ptr;
    struct num n1;
     ;
    if (!vazia(fila))
    {
        temp_ptr =  fila->inicio;
        n1 = temp_ptr->numFila;
        fila->inicio = fila->inicio->prox;
        if (vazia(fila))
        {
            fila->fim = NULL;
        }
        free(temp_ptr);
        
        return (n1);
    }
}

void insere_vetor(tipoFila *fila,struct num elemento, int *vetor,int size)
{
    int *auxptr;
    
    
    auxptr = vetor;
    for (int i = 0; i < size; i++)
    {
        printf("Introduza o elemento %d: ",i+1);
        scanf("%d", auxptr);
        auxptr++;
    }    

    auxptr=vetor;
    for (int i = 0; i < size; i++)
    {
        elemento.isNull=0;
        elemento.numero= *vetor;
        insere(fila, elemento);
        vetor++;
    }
    
}