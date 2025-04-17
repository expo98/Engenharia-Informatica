#include <stdio.h>

#define MAX 120


int main(int argc, char * argv[]){
    if (argc!=3){
        perror("Parametros inválidos");
        return 1;
    }
    FILE *fOrigem, *fDestino;
    fOrigem = fopen(argv[1],"r");
    if (fOrigem == NULL){
        perror("Erro abertura ficheiro de origem");
    }
    fDestino = fopen(argv[2],"w");
    if(fDestino == NULL)
    {
        perror("Erro criação novo ficheiro");
        fclose(fOrigem);
        return 1;
    }

    char txt[MAX];
    while(fgets(txt,MAX, fOrigem) != NULL)
    {
        fputs(txt, fDestino);
    }
    fclose(fDestino);
    fclose(fOrigem);
    return 0;
}