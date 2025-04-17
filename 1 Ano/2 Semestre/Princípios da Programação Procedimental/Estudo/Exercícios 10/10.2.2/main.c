#include <stdio.h>
#include <stdlib.h>



float * introduzirNotas();
float * mediaFinal(float *notasgerais);
float melhorNota(float *notasfinais);

int main()
{
    float *notasFinais, *notasGerais, maiorNota;

    notasGerais = introduzirNotas();

    notasFinais = mediaFinal(notasGerais);

    maiorNota = melhorNota(notasFinais);

    printf("A melhor nota da turma foi %.2f", maiorNota);

    free(notasGerais);
    free(notasFinais);

    return 0;
}


float * introduzirNotas()
{
    float *notas, *ptr;

    notas = (float *) malloc(sizeof(float)*20*3);

    ptr = notas;
    for (int i = 0; i < 20*3; i+=3)
    {
        printf("Introduza a nota do teste do aluno %d: ", ((i/3)+1));
        scanf("%f",ptr);
        ptr++;
        printf("Introduza a nota do projecto do aluno %d: ", ((i/3)+1));
        scanf("%f",ptr);
        ptr++;

        printf("Introduza a nota do trabalho-prático do aluno %d: ", ((i/3)+1));
        scanf("%f",ptr);
        ptr++;

    }
    
    return notas;
}

float * mediaFinal(float *notasgerais)
{
    float *notasfinal = (float *) malloc( sizeof(float) *20);
    float *ptrfinal = notasfinal;
    float *ptrgerais = notasgerais;

    for (int i = 0; i < 20; i++)
    {
        *ptrfinal = (*(ptrgerais+i) *0.5) + (*(ptrgerais+1+i) *0.25) + (*(ptrgerais+2+i)*0.25);
        ptrfinal++;
    }

    return notasfinal;
}

float melhorNota(float *notasfinais)
{
    float maiorNota= *notasfinais;

    for (int i = 0; i < 20; i++)
    {
        printf("%.2f", *notasfinais);
        notasfinais++;
    }
    return maiorNota;
}