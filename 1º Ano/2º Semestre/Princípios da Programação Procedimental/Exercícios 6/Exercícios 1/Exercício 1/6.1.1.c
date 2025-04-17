#include <stdio.h>
#include <limits.h>

#define MAX_LETRAS 80

int calculaTamanho (char s[]);
int calculaTamanho2 (char *s);
//int calculaTamanho2 (char *s);

int main(){
    char linha [MAX_LETRAS];
    int tam;
    printf("char_max=%d - char_min=%d\n", CHAR_MAX, CHAR_MIN);
    printf("Cadeia = ");

    if (fgets(linha,MAX_LETRAS-1,stdin)==NULL){
        printf("Erro na leitura da cadeia de caracteres\n");
        return 1;
    }
    //scanf("%s",linha);
    //scanf ("%79[^\n]", linha);
    tam = calculaTamanho2(linha);
    printf("Tamanho = %d\nCadeia lida= %s\n", tam,linha);
    return 0;
}

int calculaTamanho (char s[]){
    int t =0;
    for (int i =0; s[i] !=0; i++) {
        t++;
    }
    return t;
}

int calculaTamanho2 (char *s){
    int t =0;
    for (int i =0; *(s+i) !=0; i++) {
        t++;
    }
    return t;
}