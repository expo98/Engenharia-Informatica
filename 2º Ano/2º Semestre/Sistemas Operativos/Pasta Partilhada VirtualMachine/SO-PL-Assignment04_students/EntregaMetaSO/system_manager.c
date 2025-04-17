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
#include <pthread.h>

#define USER_PIPE "user_pipe"
#define BACK_PIPE "back_pipe"

int user_pipe_fd;

typedef struct 
{
    int MOBILE_USER;
    int QUEUE_POS;
    int AUTH_SERVERS;
    int AUTH_PROC_TIME;
    int MAX_VIDEO_WAIT;
    int MAX_OTHERS_WAIT;
} Config;


typedef struct no {
    char *s;
    struct no* prox;
} no;

typedef struct fila{
    struct no* inicio;
    struct no* fim; 
    int tamanho;
}fila;

typedef struct filas{
    fila Video_Streaming_Queue;
    fila Others_Services_Queue;
    int QUEUE_POS;
} filas;

void cria_fila(fila* f){
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}


no* insere_fila(fila *f, char *s, int QUEUE_POS){
    if(f->tamanho == QUEUE_POS){
        return NULL;
    }

    no* n = malloc(sizeof(no));
    if(n != NULL){
        n->s = malloc(sizeof(char) * (strlen(s)+1));
        if( n->s == NULL){
            free(n);
            return NULL;
        }
        strcpy(n->s, s);
        n->prox = NULL;
        if(f->fim != NULL){
            f->fim->prox = n;
            f->fim = n;
        } else{
            f->inicio = n;
            f->fim = n;
        }
        f->tamanho++;
    }
    return n;
}

void destroi_fila(fila *f){
    while(f->inicio != NULL){
        no* aux = f->inicio;
        f->inicio = f->inicio->prox;
        free(aux);
    }
    f->fim = NULL;
}

int vazia_fila(fila *f){
    return f->inicio == NULL;
}

char* retira_fila(fila *f){
    if( f->inicio != NULL){
        char *res = f->inicio->s;
        no* temp = f->inicio;
        f->inicio = f->inicio->prox;
        free(temp);
        f->tamanho--;
        return res;
    }else {
        return 0;
    }
}

void log_msg(char *msg){
    FILE *file = fopen("log.txt", "a");
    if(file == NULL){
        printf("Erro ao abrir o ficheiro log\n");
        return ;
    }

    time_t tempo = time(NULL);
    char tempo_str[100];
    strftime(tempo_str, 100, "%Y-%m-%d %H:%M:%S", localtime(&tempo));
    fprintf(file, "%s - ", tempo_str);
    fprintf(file, "%s\n", msg);
    printf("%s - ", tempo_str);
    printf("%s\n", msg);
    fclose(file);
}


void* receiver_thread(void* args){
    log_msg("Criação da thread receiver");
    
    char *pedidos = "pedidos";

    filas *f = (filas*)args;

    if(insere_fila(&f->Video_Streaming_Queue, pedidos, f->QUEUE_POS) == NULL){
        log_msg("Video_Streaming_Queue cheia");
        return NULL;
    }else if (insere_fila(&f->Others_Services_Queue, pedidos, f->QUEUE_POS) == NULL){
       log_msg("Others_Services_Queue cheia");
        return NULL;
    }

    return NULL;

}

void* sender_thread(){
    log_msg("Criação da thread sender");
    return NULL;

}

// Function to open the named pipe
void open_user_pipe() {
    // Open the named pipe USER_PIPE for reading and writing
    user_pipe_fd = open(USER_PIPE, O_RDWR);

    if (user_pipe_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    log_msg("Início do programa");
    char *filename;

    if(argc != 2) {
        printf("Syntax Inválida: ./system_manager  {config-file}\n");
        return 1;
    }

    filename = argv[1];
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        log_msg("Erro ao abrir o ficheiro de configuração");
        return 1;
    }

    Config config = {0,0,0,0,0,0};


    if(fscanf(file, "%d %d %d %d %d %d", &config.MOBILE_USER, &config.QUEUE_POS, &config.AUTH_SERVERS, &config.AUTH_PROC_TIME, &config.MAX_VIDEO_WAIT, &config.MAX_OTHERS_WAIT) != 6) {
       log_msg("Erro ao ler o ficheiro de configuração");
        return 1;
    }

   /*
    printf("MOBILE_USER: %d\n", config.MOBILE_USER);
    printf("QUEUE_POS: %d\n", config.QUEUE_POS);
    printf("AUTH_SERVERS: %d\n", config.AUTH_SERVERS);
    printf("AUTH_PROC_TIME: %d\n", config.AUTH_PROC_TIME);
    printf("MAX_VIDEO_WAIT: %d\n", config.MAX_VIDEO_WAIT);
    printf("MAX_OTHERS_WAIT: %d\n", config.MAX_OTHERS_WAIT);
    */
    fclose(file);

    int shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT  | 0777);
    if( shmid < 0){
        log_msg("Erro ao criar a shared memory");
        return 1;
    }

    int *shared_var = (int *)shmat(shmid,NULL, 0);

    pid_t pid = fork();
    if(pid  < 0){
        log_msg("Erro ao criar processo Auth Request Manager");
        return 1;  

    }else if(pid == 0){ // Processo filho, referente ao Auth Request Manager
    log_msg("Processo Auth Request Manager criado");

     // Cria o named pipe
    if (mkfifo(USER_PIPE, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    printf("Named pipe USER_PIPE criado.\n");

    pthread_t thr_receiver, thr_sender;

    filas f;

    f.QUEUE_POS = config.QUEUE_POS;
    cria_fila(&f.Video_Streaming_Queue);
    cria_fila(&f.Others_Services_Queue);


    pthread_create(&thr_receiver, NULL, receiver_thread, &f);
    pthread_create(&thr_sender, NULL, sender_thread, &f);
    return 0;
    }


    pid_t pid2 = fork();
    if(pid2 < 0){
        log_msg("Erro ao criar processo Monitor Engine");
        return 1;
    }else if(pid2 == 0){ // Processo filho, referente ao Monitor Engine
        log_msg("Processo Monitor Engine criado");
        log_msg("Limite plafond atingido");
        return 0;

    }



    log_msg("Processo System Manager criado");

    waitpid(pid, NULL, 0);
    waitpid(pid2, NULL, 0);

    



    shmdt(shared_var);
    log_msg("Fim do programa");
    return 0;
}