#include <stdio.h>


int main(int argc, char * argv[])
{
    int arg_size=0;
    while (arg_size<argc)
    {
        arg_size++;
    }
    
    FILE *fOrigem, *fDestino;

     for (int i = 1; i <= arg_size ; i++)
    {

    if (strcmp(argv[i][0],"-")==0)
    {           
        if (strcmp(argv[i][1],"o"))
        {
            char ficheiroOrigem[50];

            for (int j = 0; argv[i][j] != "\0"; j++)
            {
                strcpy(argv[i][j],ficheiroOrigem[j]);
            }
            
            fOrigem = fopen(ficheiroOrigem,"r");

            if (ficheiroOrigem == NULL)
            {
                perror("Erro abertura ficheiro de origem");
                return 1;
            }
        }

        if (strcmp(argv[i][1],"d"))
        {
            char ficheiroDestino[50];

            for (int j = 0; argv[i][j] != "\0"; j++)
            {
                strcpy(argv[i][j],ficheiroDestino[j]);
            }
            
            fDestino = fopen(ficheiroDestino,"w");

            if (ficheiroDestino == NULL)
            {
                perror("Erro abertura ficheiro de destino");
                return 1;
            }
        }
        if (strcmp(argv[i][1],"l"))
        {
           
        }

        if (strcmp(argv[i][1],"c"))
        {
            
        }
        if (strcmp(argv[i][1],"a"))
        {
            /* code */
        }

        if (strcmp(argv[i][1],"p"))
        {
            
        }
        
        else perror("Argumento não válido");
        }

        else perror("Argumento não válido");
    }
    return 0;   
}