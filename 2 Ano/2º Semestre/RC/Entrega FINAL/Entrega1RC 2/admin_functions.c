#include "Header.h"

// Terminar o udp_server
void udp_server() {
    int serv_sock;
    struct sockaddr_in addr;

    serv_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (serv_sock == -1)
        erro("UDP socket creation error");

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(PORTO_CONFIG);

    if (bind(serv_sock, (struct sockaddr*)&addr, sizeof(addr)) == -1)
        erro("bind() error");

    User adminUsers[MAX_USERS];
    int num_admin_users;
    int authenticated=0;
    read_credential_udp(adminUsers, &num_admin_users);
    while(authenticated==0){
        authenticated = handle_login_request_udp(serv_sock, adminUsers, num_admin_users);
        }
    process_admin(serv_sock, addr);

    close(serv_sock);
    
}

int handle_login_request_udp(int fd, User admin_users[], int num_admin_users) {
    char buffer[BUF_SIZE];
    int bytes_received;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Receive login request
    bytes_received = recvfrom(fd, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_addr, &client_len);
    if (bytes_received == -1) {
        perror("recvfrom");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0'; // Null-terminate the received data

    // Extract username and password from the received message
    char username[MAX_USERNAME_LEN], password[MAX_PASSWORD_LEN];
    sscanf(buffer, "LOGIN %s %s", username, password);

    // Authenticate user
    int authenticated = 0;
    for (int i = 0; i < num_admin_users; i++) {
        if (strcmp(admin_users[i].username, username) == 0 && strcmp(admin_users[i].password, password) == 0) {
            authenticated = 1;
            break;
        }
    }

    if (authenticated) {
        const char *success_msg = "Autenticação de administrador realizada com sucesso. Bem-vindo!";
        sendto(fd, success_msg, strlen(success_msg), 0, (struct sockaddr*)&client_addr, client_len);
        return 1;
    } else {
        const char *failure_msg = "Falha na autenticação. Verifique suas credenciais.";
        sendto(fd, failure_msg, strlen(failure_msg), 0, (struct sockaddr*)&client_addr, client_len);
        return 0;
    }
}

// Trims leading and trailing whitespace from a string
char *trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    if(*str == 0)  // All spaces?
        return str;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    // Write new null terminator character
    end[1] = '\0';

    return str;
}

// Function to send the list of commands
void send_command_list(int udp_socket, struct sockaddr_in client_addr) {
    char buf[BUF_SIZE];

    sprintf(buf, "----------------\n| COMANDOS ADMIN |\n----------------\n.ADD_USER {username} {password} {administrador/professor/aluno}\n.DEL {username}\n.LIST\n.QUIT\n.QUIT_SERVER\n\n");
    sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
}

void process_admin(int udp_socket, struct sockaddr_in client_addr) {
    char buf[BUF_SIZE];
    socklen_t client_len = sizeof(client_addr);
    send_command_list(udp_socket,client_addr);


    
    while(1) {
            
        memset(buf,0,sizeof(buf));
        recvfrom(udp_socket, buf, sizeof(buf), 0, (struct sockaddr *)&client_addr, &client_len);
        if (strncmp(buf, "QUIT", strlen("QUIT")) == 0 || strncmp(buf, "QUIT_SERVER", strlen("QUIT_SERVER")) == 0) {
            break;
        }

        printf("Received command: %s\n", buf);


        //Verifica se o comando enviado pelo admin é ADD_USER
       if (strncmp(buf, "ADD_USER ", strlen("ADD_USER ")) == 0) {
            //Declara as variaveis username , password , user_type
            char username[MAX_USERNAME_LEN];
            char password[MAX_PASSWORD_LEN];
            char role[MAX_ROLE_LEN];  // Pode ser administrador / professor / aluno

            // Tentativa de dar parsing ao comando
            if (sscanf(buf, "ADD_USER %s %s %s", username, password, role) == 3) {
                // O parse foi sucedido
                //Verifica se o user_type é administrador / professor / aluno
                if (strncmp(role,"administrador",strlen("administrador"))==0 || strncmp(role,"professor",strlen("professor"))==0 || strncmp(role,"aluno",strlen("aluno"))==0)
                {
                add_user(username, password, role);
                sprintf(buf,"User %s com a role %s adicionado com sucessos!\n",username,role);
                sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));                  
                }
                //Erro caso os parametros não sejam os pedidos
                else{
                    sprintf(buf,"Erro: user_type diferente de administrado/professor/aluno\n\n");
                    sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
                }

        } else {
            // Parametros no comando diferente dos 3 necessários (username, password, tipo de utilizador)
            sprintf(buf, "Erro: Parâmetros diferentes de ADD_USER {username} {password} {administrador/professor/aluno}\n\n");
            sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
        }
       }

        // Verifica se o comando eviado pelo admin é DEL
        if (strncmp(buf,"DEL ", strlen("DEL "))==0)
        {
            //Declara as variaveis username , password , user_type
            char username[MAX_USERNAME_LEN];

            // Tentativa de dar parsing ao comando
            if (sscanf(buf, "DEL %s", username) == 1) {
                // O parse foi sucedido
                //Verifica se o user_type é administrador / professor / aluno
    
                delete_user(username);

                sprintf(buf,"%s deletado com sucesso\n",username);
                sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
                                 
                //Erro caso os parametros não sejam os pedidos
            }
        }
        if(strncmp(buf,"LIST\0",sizeof(BUF_SIZE))==0)   
        {
            char buf[BUF_SIZE];
            char userList[MAX_USERS][MAX_USERNAME_LEN];
            //cria um buffer que guarde a string concatenada
            char concatenatedString[MAX_USERS * MAX_USERNAME_LEN]; // Comprimento máximo assumindo que todos os user name tenham BUF_SIZE
            
            //Inicializa o  buffer para um string vazia
            concatenatedString[0] = '\0';

            //Concatena as strings de userList com \n
            list_user(userList);
            for (int i = 0; i < MAX_USERS && userList[i][0] !='\0'; i++)
            {
                strcat(concatenatedString,userList[i]);
                strcat(concatenatedString,"\n");
            }
            
            //envia a string concatenada
            sprintf(buf,"User List:\n %s",concatenatedString);
            sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
        }

        if (strncmp(buf,"QUIT",sizeof("QUIT"))==0)
        {

            printf("Quiting process_admin...\n");
            return;
        }
        if (strncmp(buf,"QUIT_SERVER",sizeof("QUIT_SERVER"))==0)
        {
            printf("Quiting process_admin...\n");
            return;
        }
        
        send_command_list(udp_socket,client_addr);
    }
}

/*void process_admin(int udp_socket, struct sockaddr_in client_addr) {
    int recv_len;
    char buf[BUF_SIZE];
    socklen_t client_len = sizeof(client_addr);


    // Send initial list of commands to the client
    send_command_list(udp_socket, client_addr);

    while (1) {
        bzero(buf, sizeof(buf)); // Clear buffer

        printf("Waiting for command...\n");

        if ((recv_len = recvfrom(udp_socket, buf, sizeof(buf), 0, (struct sockaddr *)&client_addr, &client_len)) == -1) { // ESPERA P RECEBER DE COMANDOS ADMIN
            erro("[ADMIN] ERRO RECVFROM");
        }
        buf[recv_len] = '\0';
        trim_whitespace(buf); // Trim whitespace

        printf("Received command: '%s'\n", buf);

        // Verifica se o comando enviado pelo admin é ADD_USER
        if (strncmp(buf, "ADD_USER ", strlen("ADD_USER ")) == 0) {
            // Declara as variaveis username, password, user_type
            char username[MAX_USERNAME_LEN];
            char password[MAX_PASSWORD_LEN];
            char role[MAX_ROLE_LEN];  // Pode ser administrador / professor / aluno

            // Tentativa de dar parsing ao comando
            if (sscanf(buf, "ADD_USER %s %s %s", username, password, role) == 3) {
                // O parse foi sucedido
                // Verifica se o user_type é administrador / professor / aluno
                if (strcmp(role, "administrador") == 0 || strcmp(role, "professor") == 0 || strcmp(role, "aluno") == 0) {
                    add_user(username, password, role);
                    sprintf(buf, "User %s com a role %s adicionado com sucesso!\n", username, role);
                    sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
                } else {
                    sprintf(buf, "Erro: user_type diferente de administrador/professor/aluno\n\n");
                    sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
                }
            } else {
                // Parametros no comando diferente dos 3 necessários (username, password, tipo de utilizador)
                sprintf(buf, "Erro: Parâmetros diferentes de ADD_USER {username} {password} {administrador/professor/aluno}\n\n");
                sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
            }
        }

        // Verifica se o comando enviado pelo admin é DEL
        else if (strncmp(buf, "DEL ", strlen("DEL ")) == 0) {
            // Declara a variavel username
            char username[MAX_USERNAME_LEN];

            // Tentativa de dar parsing ao comando
            if (sscanf(buf, "DEL %s", username) == 1) {
                // O parse foi sucedido
                delete_user(username);
                sprintf(buf, "%s deletado com sucesso\n", username);
                sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
            } else {
                sprintf(buf, "Erro: Parâmetros diferentes de DEL {username}\n\n");
                sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
            }
        }

        // Verifica se o comando enviado pelo admin é LIST
        else if (strcmp(buf, "LIST") == 0) {
            char userList[MAX_USERS][MAX_USERNAME_LEN];
            // Cria um buffer que guarde a string concatenada
            char concatenatedString[MAX_USERS * MAX_USERNAME_LEN]; // Comprimento máximo assumindo que todos os user names tenham MAX_USERNAME_LEN

            // Inicializa o buffer para uma string vazia
            concatenatedString[0] = '\0';

            // Concatena as strings de userList com \n
            list_user(userList);
            for (int i = 0; i < MAX_USERS && userList[i][0] != '\0'; i++) {
                strcat(concatenatedString, userList[i]);
                strcat(concatenatedString, "\n");
            }

            // Envia a string concatenada
            sprintf(buf, "User List:\n%s", concatenatedString);
            sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
        }

        // Verifica se o comando enviado pelo admin é QUIT
        else if (strcmp(buf, "QUIT") == 0) {
            printf("Quitting process_admin...\n");
            return;
        }

        // Verifica se o comando enviado pelo admin é QUIT_SERVER
        else if (strcmp(buf, "QUIT_SERVER") == 0) {
            printf("Quitting process_admin...\n");
            return;
        }

        // Comando não reconhecido
        else {
            sprintf(buf, "Erro: Comando não reconhecido\n\n");
            sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
            send_command_list(udp_socket,client_addr); // Resend command list if command is not recognized
        }
    }
}*/
/*void process_admin(int udp_socket, struct sockaddr_in client_addr) {
    int recv_len;
    char buf[BUF_SIZE];
    socklen_t client_len = sizeof(client_addr);

    // Flag to track if the command list has been sent
    int command_list_sent = 0;

    while (1) {
        bzero(buf, sizeof(buf)); // Clear buffer

        // If command list hasn't been sent yet, send it
        if (!command_list_sent) {
            // Send initial list of commands to the client
            send_command_list(udp_socket, client_addr);
            command_list_sent = 1; // Update flag to indicate command list has been sent
        }

        printf("Waiting for command...\n");

        if ((recv_len = recvfrom(udp_socket, buf, sizeof(buf), 0, (struct sockaddr *)&client_addr, &client_len)) == -1) { // ESPERA P RECEBER DE COMANDOS ADMIN
            erro("[ADMIN] ERRO RECVFROM");
        }
        buf[recv_len] = '\0';
        trim_whitespace(buf); // Trim whitespace

        printf("Received command: '%s'\n", buf);

        // Verifica se o comando enviado pelo admin é ADD_USER
        if (strncmp(buf, "ADD_USER ", strlen("ADD_USER ")) == 0) {
            // Declara as variaveis username, password, user_type
            char username[MAX_USERNAME_LEN];
            char password[MAX_PASSWORD_LEN];
            char role[MAX_ROLE_LEN];  // Pode ser administrador / professor / aluno

            // Tentativa de dar parsing ao comando
            if (sscanf(buf, "ADD_USER %s %s %s", username, password, role) == 3) {
                // O parse foi sucedido
                // Verifica se o user_type é administrador / professor / aluno
                if (strcmp(role, "administrador") == 0 || strcmp(role, "professor") == 0 || strcmp(role, "aluno") == 0) {
                    add_user(username, password, role);
                    sprintf(buf, "User %s com a role %s adicionado com sucesso!\n", username, role);
                    sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
                } else {
                    sprintf(buf, "Erro: user_type diferente de administrador/professor/aluno\n\n");
                    sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
                }
            } else {
                // Parametros no comando diferente dos 3 necessários (username, password, tipo de utilizador)
                sprintf(buf, "Erro: Parâmetros diferentes de ADD_USER {username} {password} {administrador/professor/aluno}\n\n");
                sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
            }
        }

                // Verifica se o comando enviado pelo admin é DEL
            else if (strncmp(buf, "DEL ", strlen("DEL ")) == 0) {
                // Declara a variavel username
                char username[MAX_USERNAME_LEN];

                // Tentativa de dar parsing ao comando
                if (sscanf(buf, "DEL %s", username) == 1) {
                    // O parse foi sucedido
                    printf("Username to delete: %s\n", username); // Debugging output
                    delete_user(username);
                    sprintf(buf, "%s deletado com sucesso\n", username);
                    sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
                } else {
                    sprintf(buf, "Erro: Parâmetros diferentes de DEL {username}\n\n");
                    sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
                }
            }


        // Verifica se o comando enviado pelo admin é LIST
        else if (strcmp(buf, "LIST") == 0) {
            char userList[MAX_USERS][MAX_USERNAME_LEN];
            // Cria um buffer que guarde a string concatenada
            char concatenatedString[MAX_USERS * MAX_USERNAME_LEN]; // Comprimento máximo assumindo que todos os user names tenham MAX_USERNAME_LEN

            // Inicializa o buffer para uma string vazia
            concatenatedString[0] = '\0';

            // Concatena as strings de userList com \n
            list_user(userList);
            for (int i = 0; i < MAX_USERS && userList[i][0] != '\0'; i++) {
                strcat(concatenatedString, userList[i]);
                strcat(concatenatedString, "\n");
            }

            // Envia a string concatenada
            sprintf(buf, "User List:\n%s", concatenatedString);
            sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
        }

        // Verifica se o comando enviado pelo admin é QUIT
        else if (strcmp(buf, "QUIT") == 0) {
            printf("Quitting process_admin...\n");
            return;
        }

        // Verifica se o comando enviado pelo admin é QUIT_SERVER
        else if (strcmp(buf, "QUIT_SERVER") == 0) {
            printf("Quitting process_admin...\n");
            return;
        }

        // Comando não reconhecido
        else {
            sprintf(buf, "Erro: Comando não reconhecido\n\n");
            sendto(udp_socket, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
            send_command_list(udp_socket,client_addr); // Resend command list if command is not recognized
        }
    }
}*/

void delete_user(char *username)
{
    FILE *fp,*tempfp;
    char line[BUF_SIZE];

    sem_wait(user_sem);
    //open the file in read and write mode
    fp = fopen(CONFIG, "r");
    if (fp == NULL) {
        perror("Error opening file");
        sem_post(user_sem);
        exit(EXIT_FAILURE);
    }

    tempfp = fopen(TMPCFG,"w");
    if(tempfp == NULL)
    {
        perror("Error opening file");
        sem_post(user_sem);
        exit(EXIT_FAILURE);
    }


    while (fgets(line, sizeof(line), fp))
{
    // Tokenize the line
    char *file_user = strtok(line, ";");
    char *file_password = strtok(NULL, ";");
    char *file_role = strtok(NULL, "\n"); // Role is terminated by newline

    // Check if the username matches
    if (file_user != NULL && strcmp(file_user, username) != 0)
    {
        // Write the line to the temporary file
        fprintf(tempfp, "%s;%s;%s\n", file_user, file_password, file_role);
    }
}

    //Remove ficheiro original 
    if(remove(CONFIG) != 0)
    {
        perror("Error deleting original file\n");
        exit(EXIT_FAILURE);
    }

    //Renomeia ficheiro temporário para o nome do original
    if(rename(TMPCFG,CONFIG) !=0)
    {
        perror("Error deleting original file\n");
        exit(EXIT_FAILURE);
    }

    fclose(tempfp);
    sem_post(user_sem);
}

void add_user(char username[MAX_USERNAME_LEN], char password[MAX_PASSWORD_LEN], char role[MAX_ROLE_LEN])
{
    FILE *fp;
    char line[BUF_SIZE];   

    sem_wait(user_sem);
    // open the file in append mode
    fp = fopen(CONFIG, "a");
    if (fp == NULL) {
        perror("Error opening file");
        sem_post(user_sem);
        exit(EXIT_FAILURE);
    }

    // Format the line as username;password;role
    sprintf(line, "%s;%s;%s\n", username, password, role);
    fprintf(fp, "%s", line); // Append the line to the file

    fclose(fp);
    sem_post(user_sem);
    exit(EXIT_SUCCESS);
}

void list_user(char (*username)[MAX_USERNAME_LEN])
{
    FILE *fp;
    char line[BUF_SIZE];   

    sem_wait(user_sem);
    //open the file in read mode
    fp = fopen(CONFIG, "r");
    if (fp == NULL) {
        perror("Error opening file");
        sem_post(user_sem);
        exit(EXIT_FAILURE);
    }

    int count=0;
    char *usertok;
    while(fgets(line,sizeof(line),fp) && count <MAX_USERS)
    {
        if (line == NULL) {
            perror("Error reading line");
            exit(EXIT_FAILURE);
        }

        usertok = strtok(line,";"); // Tokeniza o user
        if(usertok != NULL){
            username[count][0] = '\0';
            strcpy(username[count],usertok); // Guarda o username no duplo array original, devido ao ponteiro
            count++; // aumenta a contagem
        }
    }

    // Fill remaining slots with NULL
    for (int i = count; i < MAX_USERS; i++) {
        username[i][0] = '\0'; // Set the first character to NULL terminator
    }

    fclose(fp);
    sem_post(user_sem);
    exit(EXIT_SUCCESS);
}

void erro(char *msg)
{
	printf("Erro, %s\n\n", msg);
	exit(-1);
}

void read_credential_udp(User admin_users[], int *num_admin_users) {
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
            }
        }
    }
    sem_post(user_sem);
    fclose(fp);
    
}