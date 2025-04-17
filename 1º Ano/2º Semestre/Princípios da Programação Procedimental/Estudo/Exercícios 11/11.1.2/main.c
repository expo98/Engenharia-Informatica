#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct string
{
    int isNull;
    char string[4096];
};
typedef struct noFila
{
    struct string strFila;
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
void insere(tipoFila *fila, struct string str1);
struct string retira(tipoFila *fila);


int main()
{
    char tempStr[4096];
    tipoFila *ptrFila;
    struct string elemento;


    ptrFila = (tipoFila *) malloc(sizeof(tipoFila));

    //Cria a fila
    cria(ptrFila);

    //Cria um loop para que se adicione strings à fila
    int i=0;
    while (strcmp(tempStr,"FIM\n")!=0)
    {
        printf("Introduza a string %d: ",i+1);
        fgets(tempStr,4097,stdin);
        elemento.isNull =0;
        strcpy(elemento.string,tempStr);
        insere(ptrFila, elemento);
        i++;
    }
    
    //Imprime todos os elementos da fila
    noFila *atual = ptrFila->inicio;
    while (atual != NULL)
    {
        printf("Output %s \n",atual->strFila.string);
        atual=atual->prox;
    }

    //Retira o primeior elemento d afila
    elemento = retira(ptrFila);
    //Verifica se a fila está vazia, caso esteja o programa termina
    if(elemento.isNull)
    {
        printf("A fila está vazia");
        return -1;
    }

    //Repõe o ponteiro para o início da fila
    atual = ptrFila->inicio;

    //Imprime todos os elementos à exeção do que fora retirado
    while(atual != NULL)
    {
        printf("Output: %s \n", atual->strFila.string);
        atual = atual->prox;
    }

    //Destroi a fila
    destroi(ptrFila);
    //Liberta a memória alocada
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

void insere(tipoFila *fila, struct string str1   )
{
    noFila * temp_ptr;
    temp_ptr = (noFila *) malloc(sizeof (noFila));
    if (temp_ptr != NULL)
    {
        temp_ptr->strFila = str1;
        temp_ptr->prox = NULL;
        if(vazia(fila))
            fila->inicio = temp_ptr;
        else fila->fim->prox = temp_ptr;
        fila->fim = temp_ptr;
    }   
}

struct string  retira(tipoFila *fila)
{
    noFila * temp_ptr;
    struct string str1;
    if (!vazia(fila))
    {
        temp_ptr =  fila->inicio;
        str1 = temp_ptr->strFila;
        fila->inicio = fila->inicio->prox;
        if (vazia(fila))
        {
            fila->fim = NULL;
        }
        free(temp_ptr);
        
        return (str1);
    }
}