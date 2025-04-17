#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct 
{
    char nome[25];
    int pontos;
    int golos;
} equipaPontos;

typedef struct 
{
    char casa[25];
    char adversario[25];
    int marcados;
    int sofridos;
} equipaJornada;


void ordenaPontos(equipaPontos equipas[20]);

int main(){

    equipaPontos Arsenal ={"Arsenal", 75, 77};
    equipaPontos AstonVilla ={"Aston Villa", 51, 45};
    equipaPontos Bournemouth ={"Bournmouth", 33, 31};
    equipaPontos Brentford ={"Brentford", 44, 48};
    equipaPontos Brighton ={"Brighton", 49, 54};
    equipaPontos Chelsea ={"Chelsea", 39, 30};
    equipaPontos CrystalPalace ={"Crystal Palace", 37, 31};
    equipaPontos Everton ={"Everton", 28, 24};
    equipaPontos Fulham ={"Fulham", 45, 44};
    equipaPontos Leeds ={"Leeds", 29, 41};
    equipaPontos LeicesterCity= {"Leicester City", 28, 43};
    equipaPontos Liverpool ={"Liverpool", 50, 59};
    equipaPontos ManCity ={"Manchester City", 70, 78};
    equipaPontos ManUnited ={"Manchester United", 59, 46};
    equipaPontos Newcastle ={"Newcastle", 56, 48};
    equipaPontos Nottingham= {"Nottingham Forest", 27, 26};
    equipaPontos Southampton ={"Southampton", 24, 27};
    equipaPontos Tottenham ={"Tottenham", 53, 57};
    equipaPontos WestHam ={"West Ham", 31, 29};
    equipaPontos Wolverhampton = {"Wolves", 34, 37};

    equipaPontos equipas[]={Arsenal, AstonVilla, Bournemouth, Brentford, Brighton, Chelsea, 
    CrystalPalace, Everton, Fulham, Leeds, LeicesterCity, Liverpool, ManCity,
    ManUnited, Newcastle, Nottingham, Southampton, Tottenham, WestHam, Wolverhampton};

    //Imprime tabela
    for (int i = 0; i < 20; i++){
        printf("%s - Pontos: %d Golos: %d\n",equipas[i].nome,equipas[i].pontos,equipas[i].golos);
    }


    for (int i = 0; i < 10; i++)
    {
        printf("\n");
    }
    // Usa a função para ordenar consoante pontos, golos
    ordenaPontos(equipas);

    //Imprime tabela
    for (int i = 0; i < 20; i++){
        printf("%s - Pontos: %d Golos: %d\n",equipas[i].nome,equipas[i].pontos,equipas[i].golos);
    }
    return 0;
}


void ordenaPontos(equipaPontos equipas[20]){
    equipaPontos t;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
                if (equipas[i].pontos > equipas[j].pontos) {
                t = equipas[j];
                equipas[j] = equipas[i];
                equipas[i] = t;
        }
                else if (equipas[i].pontos == equipas[j].pontos)
                {
                    if (equipas[i].golos > equipas[j].golos)
                    {
                        t = equipas[i];
                        equipas[i] = equipas[j];
                        equipas[j] = t;
                    }
                }    
     }
    }
}