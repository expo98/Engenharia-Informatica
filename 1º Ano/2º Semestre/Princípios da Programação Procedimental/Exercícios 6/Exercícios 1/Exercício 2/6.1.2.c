#include <stdio.h>
#include <limits.h>

#define MAX_LETRAS 80

int main(){
    char linha [MAX_LETRAS];
    char linha_copia [MAX_LETRAS];

    printf("char_max=%d - char_min=%d\n", CHAR_MAX, CHAR_MIN);
    printf("Cadeia = ");

    if (fgets(linha,MAX_LETRAS-1,stdin)==NULL){
        printf("Erro na leitura da cadeia de caracteres\n");
        return 1;
    }

    for (int i = 0; linha[i] !=0; i++)
    {
        linha_copia[i] = linha[i];
    }

    printf("Cadeia original = %s\n Cadeia copiada = %s\n", linha, linha_copia);
    
    return 0;
}