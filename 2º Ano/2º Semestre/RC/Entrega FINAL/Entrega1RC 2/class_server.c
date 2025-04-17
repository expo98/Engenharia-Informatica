#include "Header.h"

void handle_login_request_tcp(int fd, User admin_users[], int num_admin_users,
                        User aluno_users[], int num_student_users,
                        User professor_users[], int num_professor_users);


int main()
{
    printf("\n\n");
    printf("Starting up classes server...\n\n");
    fflush(stdout);

    sem_unlink("SEMAPHORE"); // Garante que caso ao encerrar o programa não feche o SEMPAHORE
                             // Ao abrir o semaphore existe à mesma
    user_sem = sem_open("SEMAPHORE", O_CREAT, 0777, 1);
        if(user_sem == SEM_FAILED)
            erro("Error creating semaphore for user file");

    pid_t udp_pid = fork();

    if (udp_pid < 0)
    {
        erro("Error creating UDP protocol fork");
    }
    else if (udp_pid == 0)
        udp_server();

    
    sleep(1); 
    printf("UDP protocol active.\n\n");
    fflush(stdout);
    

    pid_t tcp_pid = fork();
    if(tcp_pid < 0)
    {
        erro("Error creating TCP protocol fork");
    }
    else if(tcp_pid == 0)
    
        tcp_server();
    
    
    sleep(1);
    printf("TCP protocol active.\n\n");
    fflush(stdout);
    
    // FODA-SE REVER ISTO
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    pthread_sigmask(SIG_BLOCK, &set, NULL);

    printf("Server started successfully!\n\n");
    int sig;
    sigwait(&set, &sig);

    printf("Server powering off...\n\n");
    fflush(stdout);

    kill(udp_pid, SIGINT);
    kill(tcp_pid, SIGINT);

    while (wait(NULL)>0);
    

    if(sem_close(user_sem) == -1)
        printf("Error closing file semaphore!\n");
    else if (sem_close(user_sem) == -1 && errno != ENOENT)
        printf("Error eliminating file semaphore!");
    else
        printf("File semaphore cleared!\n");

    printf("Server shutdown!\n");
    fflush(stdout);

    exit(EXIT_SUCCESS);
}

void tcp_server()
{
int fd, client;
struct sockaddr_in addr, client_addr;
int client_addr_size;

memset(&addr, 0, sizeof(addr));
addr.sin_family=AF_INET;
addr.sin_addr.s_addr=htonl(INADDR_ANY);
addr.sin_port=htons(PORTO_TURMAS);

if ( (fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    erro("in socket function");
if ( bind(fd,(struct sockaddr*)&addr,sizeof(addr)) < 0)
    erro("in bind function");
if( listen(fd, 5) < 0)
    erro("in listen function");


// Load user credentials from file
User admin_users[MAX_USERS];
User aluno_users[MAX_USERS];
User professor_users[MAX_USERS];
int num_admin_users = 0, num_aluno_users = 0, num_professor_users = 0;
read_credentials(admin_users, &num_admin_users, aluno_users, &num_aluno_users, professor_users, &num_professor_users);

client_addr_size = sizeof(client_addr);
while (1) {

    //clean finished child processes, avoiding zombies
    //must use WNOHANG or would block whenever a child process was working
    while(waitpid(-1,NULL,WNOHANG)>0);
    //wait for new connection
    client = accept(fd,(struct sockaddr *)&client_addr,(socklen_t *)&client_addr_size);
    if (client > 0) {
    if (fork() == 0) {
        //Close parent socket
        close(fd);

        // Handle login request from the client
        handle_login_request_tcp(client, admin_users, num_admin_users, aluno_users, num_aluno_users, professor_users, num_professor_users);
        
        //Close client socket after handling the requuset
        close(client);
        exit(0); // Exit child process
    }

    //Close client socket in parent process
    close(client);
    }
}
return;
}

// Function to read user credentials from a file
void read_credentials(User admin_users[], int *num_admin_users,
                    User student_users[], int *num_aluno_users,
                    User professor_users[], int *num_professor_users) {
    FILE *fp;
    char line[BUF_SIZE];

    sem_wait(user_sem);

    // Open the file containing user credentials
    fp = fopen(CONFIG, "r");
    if (fp == NULL) {
        perror("Error opening file");
        sem_post(user_sem);
        exit(EXIT_FAILURE);
    }

    // Read lines from the file and store user credentials
    *num_admin_users = 0;
    *num_aluno_users = 0;
    *num_professor_users = 0;
    while (fgets(line, sizeof(line), fp)) {
        char *username = strtok(line, ";");
        char *password = strtok(NULL, ";");
        char *role = strtok(NULL, ";\n");

        if (username != NULL && password != NULL && role != NULL) {
            if (strcmp(role, "administrador") == 0) {
                User admin_user;
                strcpy(admin_user.username, username);
                strcpy(admin_user.password, password);
                strcpy(admin_user.role,role);

                admin_users[*num_admin_users] = admin_user;
                (*num_admin_users)++;
            } else if (strcmp(role, "aluno") == 0) {
                User aluno_user;
                strcpy(aluno_user.username, username);
                strcpy(aluno_user.password, password);
                strcpy(aluno_user.role,role);

                student_users[*num_aluno_users] = aluno_user;
                (*num_aluno_users)++;
            } else if (strcmp(role, "professor") == 0) {
                User professor_user;
                strcpy(professor_user.username, username);
                strcpy(professor_user.password, password);
                strcpy(professor_user.role,role);

                professor_users[*num_professor_users] = professor_user;
                (*num_professor_users)++;
            }
        }
    }
    sem_post(user_sem);
    fclose(fp);
}


// Função para tratar dos requests de login dos utilizadores tcp (professores e/ou alunos)
void handle_login_request_tcp(int fd, User admin_users[], int num_admin_users,
                        User aluno_users[], int num_student_users,
                        User professor_users[], int num_professor_users) {
    char buffer[BUF_SIZE];
    int bytes_received;
    char username[BUF_SIZE], password[BUF_SIZE];

    // Receive login request
    bytes_received = read(fd, buffer, sizeof(buffer));
    if (bytes_received == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0'; // Null-terminate the received data

    // Extract username and password from the received message
    sscanf(buffer, "LOGIN %s %s", username, password);


    // Authenticate user (checking against all types of users)
    int authenticated = 0;
    for (int i = 0; i < num_admin_users; i++) {
        if (strcmp(admin_users[i].username, username) == 0){
            authenticated = 0;
            write(fd, "Máquina não autorizada a autenticação de administrador!", strlen("Máquina não autorizada a autenticação de administrador!"));
            break;
        }
    }
    if (!authenticated) {
        for (int i = 0; i < num_student_users; i++) {
            if (strcmp(aluno_users[i].username, username) == 0 && strcmp(aluno_users[i].password, password) == 0) {
                authenticated = 1;
                write(fd, "Autenticação de aluno feita com sucesso. Bem-vindo!", strlen("Autenticação de aluno feita com sucesso. Bem-vindo!"));
                break;
            }
        }
    }
    if (!authenticated) {
        for (int i = 0; i < num_professor_users; i++) {
            if (strcmp(professor_users[i].username, username) == 0 && strcmp(professor_users[i].password, password) == 0) {
                authenticated = 1;
                write(fd, "Autenticação de professor feita com sucesso. Bem-vindo!", strlen("Autenticação de professor feita com sucesso. Bem-vindo!"));
                break;
            }
        }
    }
    if (!authenticated) {
        write(fd, "Autenticação falhada failed. Nome de utilizador ou password inválidos.", strlen("Autenticação falhada failed. Nome de utilizador ou password inválidos."));
    }
}