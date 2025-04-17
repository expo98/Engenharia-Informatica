#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


char * lerCaracteres();
int seqNum(char * input);


int main()
{
    char *caracteres = lerCaracteres();

    int sequencia = seqNum(caracteres);


    printf("A sequência maior de números é: %d\n",sequencia);


    free(caracteres);
    return 0;
}


char * lerCaracteres()
{
    char *input = (char *) malloc(sizeof(char)*11);
    char *auxptr = input;
    for (int i = 0; (i < 10) ; i++)
    {
        printf("Introduza o %dº caracter da sequência: ",i+1);
        fgets(auxptr,1,stdin);
        if ((strcmp(auxptr,"\n") !=0)) break;
        auxptr++;
    }
    
    return input; 
}

int seqNum(char * input)
{
    char *auxptr = input;
    int sequenciatemp=0;
    int comprimentotemp=0;
    int comprimento=0;
    int sequencia=0;

    for (int i = 0; (i < 10) || (strcmp(auxptr,"\n") !=0); i++)
    {
        for (int j = 0; atoi("0") <= atoi(auxptr) || (atoi(auxptr)<=atoi("9")); j++)
        {
            sequenciatemp += (atoi(auxptr))*(pow(10,j));
            comprimentotemp++;
        }
        if (comprimentotemp > comprimento)
        {
            comprimento = comprimentotemp;
            comprimento=0;
            sequencia = sequenciatemp;
            sequencia=0;
        }
        else 
        {
            comprimentotemp=0;
            sequenciatemp=0;
        }
    }
    
    return sequencia;
}
