#include <stdio.h>

int main(){
    int horas_normal=0;
    int horas_ampm=0;
    int minutos=0;
    printf("Introduza as horas em formato 24h:\n");
    scanf("%d",&horas_normal);

    printf("Introduza os minutos:\n");
    scanf("%d",&minutos);

    horas_ampm = horas_normal % 12;

    if (horas_normal <12){
        printf("%d:%d AM\n",horas_ampm,minutos);
    }
    else 
        printf("%d:%d PM\n",horas_ampm,minutos);
    
    return 0;
}