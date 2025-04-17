#include <stdio.h>

#define MAX_LETRAS 80

int calculaTamanho (char s[]);

int main(){
    char string_a[MAX_LETRAS] = "As armas e os Barões assinalados";
    char string_b[MAX_LETRAS] = "Barões";

    int string_a_size = calculaTamanho(string_a);
    printf("%d\n",string_a_size);
    int string_b_size = calculaTamanho(string_b);
    printf("%d\n", string_b_size);



    int same_letters=0;
    int j=0;

    for (int i = 0; i < string_a_size; i++)
    {
        if (string_a[i] != string_b[j])
        {
            j=0;
            same_letters=0;
        }
        if (string_a[i] == string_b[j])
        {
            same_letters++;

            if (same_letters == string_b_size)
            {
                printf("A palavra %s existe na frase: %s\n", string_b,string_a);
            }

            j++;
        }
        
        
        
        
    }
        
    return 0;
}


int calculaTamanho (char s[]){
    int t =0;
    for (int i =0; s[i] !=0; i++) {
        t++;
    }
    return t;
}