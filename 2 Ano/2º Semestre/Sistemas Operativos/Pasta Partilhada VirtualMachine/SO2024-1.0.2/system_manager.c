/* Autores do projeto
        -Carlos Pereira 2022232042
        -Miguel Pereira 2022232552
*/
#include "Header.h"

void create_shared_memory(Config * conf);
void starting(char* config_filename);


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

    thread_args *t_args = (thread_args*)args;
    int fd = t_args->fd;
    int fd_backoffice = t_args->fd_backoffice;
    filas *f = t_args->f;


    char buf[MAX_BUF];

    fd_set set;
    FD_ZERO(&set); /* clear the set */
    FD_SET(fd, &set); /* add our file descriptor to the set */
    FD_SET(fd_backoffice, &set);

    while(1){
        fd_set temp_set = set;
        if (select(FD_SETSIZE, &temp_set, NULL, NULL, NULL) == -1) {
            perror("select");
            return NULL;
        }

        for(int i = 0; i < FD_SETSIZE; ++i) {
            if (FD_ISSET(i, &temp_set)) {
                ssize_t bytes_read = read(i, buf, MAX_BUF);
                if(bytes_read== -1){
                    log_msg("Erro ao ler do named_pipe");
                    return NULL;
                }else if(bytes_read == 0){
                    log_msg("Fim do named_pipe");
                    close(i);
                    if (i == fd) {
                        unlink(USER_PIPE);
                    } else if (i == fd_backoffice) {
                        unlink(BACK_PIPE);
                    }
                    FD_CLR(i, &set);
                } else {
                    buf[bytes_read] = '\0';
                    printf("Recebido: %s\n", buf);
                    
                    if (sscanf(buf, "%*d#VIDEO#%*d") == 0) {
                        insere_fila(&f->Video_Streaming_Queue, buf, f->QUEUE_POS++);
                    }
                    if (sscanf(buf, "%*d#SOCIAL#%*d") == 0) {
                        insere_fila(&f->Others_Services_Queue, buf, f->QUEUE_POS++);
                    }
                    if (sscanf(buf, "%*d#MUSIC#%*d") == 0) {
                        insere_fila(&f->Others_Services_Queue, buf, f->QUEUE_POS++);
                    }
                 }
            }
        }
    }
    
    


    /*if(insere_fila(&f->Video_Streaming_Queue, pedidos, f->QUEUE_POS) == NULL){
        log_msg("Video_Streaming_Queue cheia");
        return NULL;
    }else if (insere_fila(&f->Others_Services_Queue, pedidos, f->QUEUE_POS) == NULL){
       log_msg("Others_Services_Queue cheia");
        return NULL;
    } */

    return NULL;

}
// Sender_thread
void* sender_thread(void* args){
    log_msg("Criação da thread sender");

    thread_args *t_args = (thread_args*)args;

    filas *f = t_args->f;
    
    fila* VIDEO_QUEUE = &f->Video_Streaming_Queue;
    fila* OTHERS_QUEUE = &f->Others_Services_Queue;
    sleep(25);
    printf("%s",OTHERS_QUEUE->inicio->s);

    int count=0;
    int video_queue_count=0;
    int other_queue_count=0;
    while (!vazia_fila(VIDEO_QUEUE) )
    {
        count++;
        printf("Enviando VIDEO para o unnamed pipe\n");
        printf("VIDEOPIPE:%s",VIDEO_QUEUE->inicio->s);
        write(shared_var->auth_engines[count]->fdU[1],VIDEO_QUEUE->inicio->s,sizeof(VIDEO_QUEUE->inicio->s));
        retira_fila(VIDEO_QUEUE);
    }
    while (!vazia_fila(OTHERS_QUEUE))
    {
        count++;
        printf("Enviando OTHER para o unnamed pipe\n");
        printf("OTHERPIPE:%s",OTHERS_QUEUE->inicio->s);
        write(shared_var->auth_engines[count]->fdU[1],OTHERS_QUEUE->inicio->s,sizeof(OTHERS_QUEUE->inicio->s));
        retira_fila(OTHERS_QUEUE);
    }
    
    
    return NULL;
}


void sigint_handler(int sig) {
    // Delete the named pipe
    if (unlink(USER_PIPE) == -1) {
        perror("unlink");
    }

    if (unlink(BACK_PIPE) == -1) {
        perror("unlink");
    }
    exit(0);
}
 

int main(int argc, char *argv[]) {
    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

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
    


    unlink(BACK_PIPE);
    unlink(USER_PIPE);
    sem_unlink("SHM");
	sem_unlink("LOG");
	sem_unlink("AUTH_ENG");
    sem_unlink("MONITOR");
	
	SHM=sem_open("SHM", O_CREAT|O_EXCL, 0700,1);
		log_msg("SEMAPHORE TO SHARED MEMORY CREATED\n");

	
	LOG=sem_open("LOG", O_CREAT|O_EXCL, 0700,1);
		log_msg("SEMAPHORE TO WRITE LOGFILE CREATED\n");
    AUTH_ENG=sem_open("LOG", O_CREAT|O_EXCL, 0700,1);
        log_msg("SEMAPHORE TO AUTHORIZATION ENGINE CREATE\n");
	
	logs=fopen("Logs.txt", "w+");
		log_msg("LOGFILE CREATED\n");

    //Cria a shared memory
   // create_shared_memory(confs, servers);

    if((msqid=msgget(IPC_PRIVATE, IPC_CREAT|0777))<0){
    	log_msg("Cannot create message queue");
		exit(1);
	}
    log_msg("MESSAGUE QUEUE CREATED");
	#ifdef DEBUG
		DEBUG_PRINT("MESSAGE QUEUE CREATED\n\n");
	#endif

    /*int fdU[2];
    if(pipe(fdU) == -1){
        perror("Errocor creating unnamed pipe");
        return 1;
    }*/

    pid_t pid = fork();
    if(pid  < 0){
        log_msg("Erro ao criar processo Auth Request Manager");
        return 1;  

    }else if(pid == 0){ // Processo filho, referente ao Auth Request Manager
    log_msg("Processo Auth Request Manager criado");
    // Cria os named pipes
    if((mkfifo(USER_PIPE, O_CREAT|O_EXCL|0600)<0) && (errno!=EEXIST)){
    	perror("Cannot create pipe: ");
    	exit(1);
	}
	
	if((fd_user_pipe = open(USER_PIPE, O_RDWR))<0){
		perror("Cannot open pipe for writing: ");
		exit(1);
	}
	#ifdef DEBUG
		DEBUG_PRINT("NAMED PIPE CREATED\n");
	#endif

    if((mkfifo(BACK_PIPE, O_CREAT|O_EXCL|0600)<0) && (errno!=EEXIST)){
    	perror("Cannot create pipe: ");
    	exit(1);
	}
	
	if((fd_back_pipe = open(BACK_PIPE, O_RDWR))<0){
		perror("Cannot open pipe for writing: ");
		exit(1);
	}
	#ifdef DEBUG
		DEBUG_PRINT("NAMED PIPE CREATED\n");
	#endif
	

    

    char buf[BUFSIZ];
    fflush(stdout);

    
    pthread_t thr_receiver, thr_sender;

    filas f;

    f.QUEUE_POS = config.QUEUE_POS;
    cria_fila(&f.Video_Streaming_Queue);
    cria_fila(&f.Others_Services_Queue);

    thread_args args;
    args.f = &f;
    args.fd = fd_user_pipe;
    args.fd_backoffice = fd_back_pipe;

    //args.fd_pipe_write = fdU[1]; // Passa o write end do pipe para o sender thread
    //close(fdU[0]);// Fecha o read end do pipe no Auth Req Manager

    pthread_create(&thr_receiver, NULL, receiver_thread, &args);
    pthread_create(&thr_sender, NULL, sender_thread, &args);

    //

    pthread_join(thr_receiver, NULL);
    pthread_join(thr_sender, NULL);
    return 0;
    }


    pid_t pid2 = fork();
    if(pid2 < 0){
        log_msg("Erro ao criar processo Monitor Engine");
        return 1;
    }else if(pid2 == 0){ // Processo filho, referente ao Monitor Engine
        char* buf[BUFSIZ];
        log_msg("Processo Monitor Engine criado");
        log_msg("Limite plafond atingido");
        //close(fdU[1]); // Fecha o pipe end de writing no Monitor Engine visto que irá apenas ler
        int count=0;
        for (int i = 0; i < shared_var->AUTH_SERVER_MAX; i++)
        {
            read(shared_var->auth_engines[i]->fdU[0],buf,BUFSIZ);
            printf("Leitura de Monitor Engine: %s\n",buf);
        }
        return 0;
    }



    log_msg("Processo System Manager criado");

    waitpid(pid, NULL, 0);
    waitpid(pid2, NULL, 0);

    



    shmdt(shared_var);
    log_msg("Fim do programa");
    return 0;
}

void create_shared_memory(Config * conf){
	int size = sizeof(shm) + sizeof(statistics)*conf->MOBILE_USER + sizeof(mobile_user)*conf->MOBILE_USER;

	if((shmid=shmget(IPC_PRIVATE, size ,IPC_CREAT | 0766))<0){
		perror("Error in shmget with IPC_GREAT\n");
		exit(1);
	}

	if((shared_var = (shm*) shmat(shmid,NULL,0))==(shm*)-1){
		perror("Shmat error!");
		exit(1);
	}
		log_msg("Shared Memory created\n");
	    
    
    
    for(int k=0; k<conf->AUTH_SERVERS; k++){
    	if (pipe(shared_var->auth_engines[k]->fdU) == -1){
    		printf("An error as ocurred with opening the pipe\n");
    	}	
    }
	
}
