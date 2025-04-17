/* Autores do projeto
        -Carlos Pereira 2022232042
        -Miguel Pereira 2022232552
*/

#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int main( ){
    sem_t *sem = sem_open("semaforo", O_CREAT | O_EXCL, 0700, 1);
    char comando[100];
    int totalData[3] = {0, 0, 0};
    int AuthRequests[3] = {0, 0, 0};

    if(sem == SEM_FAILED){
        printf("Programa já a correr\n");
        return 1;
    }

    while(1){
        printf("Comando ( lista ):  \n");
        fgets(comando, 100, stdin);
        comando[strlen(comando) - 1] = '\0';

        if(strcmp(comando, "exit") == 0){
            sem_close(sem);
            sem_unlink("semaforo");
            return 0;
        }else if (strcmp(comando, "data_stats") == 0){
            printf("A pedir dados...\n"); //realizar pedido das estatisticas atráves do Named  Pipe 
            printf("VIDEO:  %d    %d\n", totalData[0], AuthRequests[0]);
            printf("MUSIC:  %d    %d\n", totalData[1], AuthRequests[1]);
            printf("SOCIAL:  %d    %d\n", totalData[2], AuthRequests[2]);
    
        }else if (strcmp(comando, "reset") == 0){
            //Dá reset das estatisticas, posteriormente na shared memory
            totalData[0] = 0;
            totalData[1] = 0;
            totalData[2] = 0;
            AuthRequests[0] = 0;
            AuthRequests[1] = 0;
            AuthRequests[2] = 0;
            
        }else if(strcmp(comando, "lista") == 0){
            printf("Comandos disponíveis: \n");
            printf("data_stats\n");
            printf("reset\n");
            printf("exit\n");
        }else{
            printf("Comando inválido\n");
        }

    }

    sem_close(sem);
    sem_unlink("semaforo");

    return 0;
}