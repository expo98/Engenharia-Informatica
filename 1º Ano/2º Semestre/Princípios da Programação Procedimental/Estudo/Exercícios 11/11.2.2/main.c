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
void funcao(int *vetor, tipoFila fila);


int main()
{
    int N,valor;
    tipoFila *ptrFila;
    struct num elemento;


    printf("Introduza quantos elementos quer na fila: ");
    scanf("%d",&N);

    ptrFila = (tipoFila *) malloc(sizeof(tipoFila));

    cria(ptrFila);

    for (int i = 0; i < N; i++)
    {
        printf("Introduza elemento %d: ",i+1);
        scanf("%d",&valor);
        elemento.isNull =0;
        elemento.numero=valor;
        insere(ptrFila, elemento);

    }
/*
    noFila *atual = ptrFila->inicio;
    while (atual != NULL)
    {
        printf("Output %d \n",atual->numFila.numero);
        atual=atual->prox;
    }
*/
    int *vetor = (int *) malloc(sizeof(int) * N);
    
    funcao(vetor, *ptrFila);
    
    
    destroi(ptrFila);
    free(ptrFila);
    free(vetor);

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


void funcao(int *vetor, tipoFila fila)
{
    noFila *atual = fila.inicio;
    int *AUXvetor = vetor;
    int size=0;

    while (atual != NULL)
    {
        size++;
        atual = atual->prox;
    }

    atual=fila.inicio;

    while (atual != NULL)
    {
        *AUXvetor= atual->numFila.numero;
        AUXvetor++;
        atual = atual->prox;
    }
    
    AUXvetor = vetor;
    
    for (int i = 0; i < size; i++)
    {
        printf("%d\n",*AUXvetor);
        AUXvetor++;
    }
    
}