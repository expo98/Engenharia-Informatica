#include <stdio.h>
#include <string.h>

#define alphabet_size 26
#define MAX_LETRAS 100

int main(){
    char maiuscula[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char minuscula[]="abcedfghijklmnopqrstuvwzyz";
    char key[]=     "DEIABCFGHJKLZYXWVUTSRQPONM";

    char pass[MAX_LETRAS];
    char pass_codified[MAX_LETRAS];

    printf("Introduza uma mensagem para ser codificada:\n");
    fgets(pass,MAX_LETRAS,stdin); 
    pass[strlen(pass)-1] = 0;

    for (int i = 0; pass[i]!= 0; i++)
    {
        pass_codified[i] = pass[i];
        for (int j = 0; j < alphabet_size; j++)
        {
            
            if (pass_codified[i]==maiuscula[j] || pass_codified[i]==minuscula[j])
            {
                pass_codified[i] = key[j];
                break;
            } 
        }
    }

    printf("A sua mensagem descodificada é %s\nA sua mensagem codificada é %s\n", pass,pass_codified);
    
}

