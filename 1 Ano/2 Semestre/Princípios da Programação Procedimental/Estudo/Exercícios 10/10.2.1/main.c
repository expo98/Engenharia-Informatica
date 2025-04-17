#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 4096

char* characterReader();
int findWally(char *string, char *word);

int main()
{
    char *string[BUFFER_SIZE];
    char *word="Wally";

    *string = characterReader();



    

    free(string);
    free(word);


    return 0;
}



char* characterReader()
{
    char *string[BUFFER_SIZE];
    char *string = malloc(sizeof(char) * BUFFER_SIZE);
    printf("Introduza a sua palavra: ");
    fgets(string,BUFFER_SIZE,stdin);
    printf("\n");

    return *string;
}

int findWally(char *string, char *word)
{
    int *auxStr, *auxWrd;

    auxStr = string;
    auxWrd = word;
    
    int count=0;
    for (int i = 0; i < strlen(*string)-strlen(*word)+1; i++)
    {
        for (int j = 0; j < strlen(*word); j++)
        {   
            if ((*(auxWrd+j))!=(*(auxStr)+i+j))
            {
                count=0;
                break;
            }
            else if ((*(auxWrd+j))==(*(auxStr)+i+j))
            {
                count++;
                if (count==strlen(word))
                {
                    return i;
                    break;
                }
            }
        }
    }
}