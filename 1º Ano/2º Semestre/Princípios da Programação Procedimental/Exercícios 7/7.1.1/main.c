#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    int dia;
    int mes;
    int ano;
} data;

int datasIguais (data data1, data data2);
void datasDiferenca (data data1, data data2);
void dataSec (data data1);

int main(){
    data data1;
    data1.dia = 15;
    data1.mes = 02;
    data1.ano = 2004;

    data data2;
    data2.dia = 15;
    data2.mes = 02;
    data2.ano = 2004;
    printf("%d\n\n",datasIguais(data1,data2));

    data2.dia=13;
    data2.mes=05;
    data2.ano=1972;

    datasDiferenca(data1, data2);

    
    dataSec (data2);

    return 0;
}


int datasIguais (data data1, data data2){

    if( data1.dia == data2.dia && data1.mes == data2.mes && data1.ano == data2.ano) return 0;

    else return 1;
}

void datasDiferenca (data data1, data data2){

    int dia = data1.dia - data2.dia;
    if (dia<0) dia *= -1;

    int mes = data1.mes - data2.mes;
    if(mes<0) mes *= -1;

    int ano = data1.ano - data2.ano;
    if(ano<0) ano *= -1;

    printf("As duas datas diferem em %d dias, %d meses e %d anos.\n\n",dia,mes,ano);
}

void dataSec (data data1){

    int seculo = (data1.ano/100) +1;

    printf("A data dada é no século %d.\n\n",seculo);
}
