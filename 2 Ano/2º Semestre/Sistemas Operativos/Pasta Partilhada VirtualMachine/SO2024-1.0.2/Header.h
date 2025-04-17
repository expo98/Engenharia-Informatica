#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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
#include <signal.h>

#define MAX_BUF 1024
#define USER_PIPE "/tmp/user_pipe"
#define BACK_PIPE "/tmp/back_pipe"

#define MAX_MOBILE_USERS 100
#define MAX_AUTH_ENG 100



//____________________________________________________________________
//Struct da config
typedef struct 
{
    int MOBILE_USER;
    int QUEUE_POS;
    int AUTH_SERVERS;
    int AUTH_PROC_TIME;
    int MAX_VIDEO_WAIT;
    int MAX_OTHERS_WAIT;
}Config;


//____________________________________________________________________
//Struct de um nó
typedef struct no {
    char *s;
    struct no* prox;
} no;
//____________________________________________________________________
//Struct da fila
typedef struct fila{
    struct no* inicio;
    struct no* fim; 
    int tamanho;
}fila;
//____________________________________________________________________
//Struct das filas VIDEO e OTHERS
typedef struct filas{
    fila Video_Streaming_Queue;
    fila Others_Services_Queue;
    int QUEUE_POS;
} filas;
//____________________________________________________________________
//Struct dos argumentos a enviar para os threads Sender e Receiver
typedef struct {
    filas* f;
    int fd;
    int fd_backoffice;
    int fd_pipe_write;
} thread_args;


//____________________________________________________________________
//Struct da mensagem na message queue

typedef struct 
{
    long mtype;
    char something[MAX_BUF];
} msq;

//____________________________________________________________________
//Struct da shared memory

typedef struct 
{
    int video_total_data;
    int video_auth_req;
    int music_total_data;
    int music_auth_req;
    int social_total_data;
    int social_auth_req;
} statistics;

typedef struct
{
    int pid;
    int initial_plafond;
    int plafond;
    int requests;
    int dt_video;
    int dt_music;
    int dt_social;
    int amount_of_data;

    statistics stats;
} mobile_user;

typedef struct 
{
    int fdU[2];
}auth_engine;


typedef struct 
{
    int QUEUE_POS;
    int AUTH_SERVER_MAX;
    int AUTH_PROC_TIME;
    int MAX_VIDEO_WAIT;
    int MAX_OTHERS_WAIT;
    int MOBILE_USERS;
    mobile_user * users[MAX_MOBILE_USERS];
    auth_engine * auth_engines[MAX_AUTH_ENG]
} shm;

//___________________________________________________________________
//Variables like shm, semaphores, fd's, FILE.txt, pid, message queue

int shmid;           // Shared Memory
shm* shared_var;


sem_t * LOG; 		 // Semaphores
sem_t * SHM;
sem_t * MONITOR;
sem_t * AUTH_ENG;


pthread_cond_t sched;						//Conditional variables and mutexes
pthread_mutex_t mutex_sched;
pthread_condattr_t attrcond;
pthread_mutexattr_t attrmutex;


FILE* logs;			  // File.txt (Config.txt)

int fd_user_pipe;   // File Descriptor of Named Pipes
int fd_back_pipe;
      
int msqid; 			 // Message Queue
msq MQ;   



void cria_fila(fila* f);
no* insere_fila(fila *f, char *s, int QUEUE_POS);
void destroi_fila(fila *f);
int vazia_fila(fila *f);
char* retira_fila(fila *f);
#endif