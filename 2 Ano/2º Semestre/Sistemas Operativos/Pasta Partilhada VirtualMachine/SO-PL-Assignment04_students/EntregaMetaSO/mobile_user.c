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
#include <time.h>
#include <pthread.h>

int max_pedidos_aut;
pid_t ID_mobile_user;
int dados_reservar;
int user_pipe_fd;

char mensagem_inicial[100];
char mensagem_autorizacao_VIDEO[100];
char mensagem_autorizacao_MUSIC[100];
char mensagem_autorizacao_SOCIAL[100];

typedef struct 
{
    char* type;
    int interval;
}threadData;


int main(int argc, char *argv[]) {
    // Verificar se os argumentos corretos foram passados
    if(argc != 7) {
        printf("Syntax Inválida: ./mobile_user  {plafond inicial} {número máximo de pedidos de autorização} {intervalo VIDEO} {intervalo MUSIC} {intervalo SOCIAL} {dados a reservar}\n");
        return 1;
    }
    user_pipe_fd = open(user_pipe_fd,O_WRONLY);
    ID_mobile_user = getpid();
    int plafond_inicial = atoi(argv[1]);
    max_pedidos_aut = atoi(argv[2]);
    float inter_VIDEO = atoi(argv[3]) / 1000;
    float inter_MUSIC = atoi(argv[4]) / 1000;
    float inter_SOCIAL  = atoi(argv[5]) / 1000;
    dados_reservar = atoi(argv[6]);



    sprintf(mensagem_inicial, "%d#%d", ID_mobile_user, plafond_inicial);
    printf("Mensagem inicial: %s\n", mensagem_inicial);

    // Cria as instancias struct para guardar os argmentos necessários para cada thread
    threadData authArgs[3];
    authArgs[0].type = "VIDEO";
    authArgs[0].interval = inter_VIDEO;
    authArgs[1].type = "MUSIC";
    authArgs[1].interval = inter_MUSIC;
    authArgs[2].type = "SOCIAL";
    authArgs[2].interval = inter_SOCIAL;

    // Declaração dos threads para as autorizações
    pthread_t threadArray[3];

    // Cria threads para handling dos auth request
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&threadArray[i],NULL,check_type,(void *)&authArgs[i]);
    }

    // Espera que os threads terminem
    for (int i = 0; i < 3; i++)
    {
        pthread_join(threadArray[i],NULL);
    }
    
    // Cancela os threads
    for (int i = 0; i < 3; i++)
    {
        pthread_cancel(threadArray[i]);
    }

    // Exit
    for (int i = 0; i < 3; i++)
    {
        pthread_exit(threadArray[i]);
    }

    return 0;
}

void check_type(void *arg){
    threadData* data = (threadData*)arg;
    sleep(data->interval);
    if (max_pedidos_aut>1)
    {
    sendcenas(data->type);
    }    
}

void sendcenas(char type){
    char* mensagem;
    sprintf(mensagem,"Mensagem autorização %s: %d#%s#%d\n", type, ID_mobile_user, type, dados_reservar);
    ssize_t bytes_written = write(user_pipe_fd, mensagem, strlen(mensagem));
    max_pedidos_aut--;
}