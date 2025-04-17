#include <stdio.h>
#include <string.h>

#define MAX_NUMBERS 100

char array_to_string(int array);

int main(){
    int array_original[MAX_NUMBERS];
    char array_string;
    char string_compressed[MAX_NUMBERS];
    int digit;
    int repetitions=0;



    printf("Introduza uma sequência de algarismos para ser comprimida:\n");
    scanf("%d",array_original);
            //12355555555555542

    array_string = array_to_string(array_original);
    
        for (int i = 0; i < MAX_NUMBERS; i++)
    {
        if (array_string[i]==array_string[i-1])
        {
            digit = array_string[i];
            printf("Digito é : %d\n", digit);
            repetitions++;
            printf("Repetições é: %d\n", repetitions);
        }

        if ( (array_string[i] != array_string[i-1] ) && repetitions>=5)
        {
            string_compressed[i-repetitions]='c';
            string_compressed[i-repetitions+1]=digit;
            string_compressed[i-repetitions+2]=repetitions;
            string_compressed[i-repetitions+3]='f';
            repetitions=0;
        }

        if ((array_string[i] != array_string[i-1]) && repetitions<5)
        {
            for (int j = repetitions-1; j>=0 ; j--)
            {
                string_compressed[i-j] = array_string[i-j];
                repetitions=0;
            }
            
        }
        
    }
    

    printf("A sequencia comprimida é");
    for (int i = 0; i < MAX_NUMBERS; i++)
    {
        printf("%c",string_compressed[i]);
    }
    



    return 0;
}



char array_to_string(int array){
    char string[MAX_NUMBERS];

    for (int i = 0; i < MAX_NUMBERS; i++)
    {
        if (array[i]==1)
        {
            string[i] ='1';
        }

        if (array[i]==2)
        {
            string[i] ='2';
        }

        if (array[i]==3)
        {
            string[i] ='3';
        }

        if (array[i]==4)
        {
            string[i] ='4';
        }

        if (array[i]==5)
        {
            string[i] ='5';
        }

        if (array[i]==6)
        {
            string[i] ='6';
        }

        if (array[i]==7)
        {
            string[i] ='7';
        }

        if (array[i]==7)
        {
            string[i] ='8';
        }

        if (array[i]==9)
        {
            string[i] ='9';
        }

        if (array[i]==0)
        {
            string[i] ='0';
        }
        
    }

    return string;
}