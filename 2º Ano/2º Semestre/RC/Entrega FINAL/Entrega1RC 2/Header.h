#ifndef GLOBAL_H
#define GLOBAL_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <sys/file.h>
#include <arpa/inet.h>
#include <signal.h>
#include <semaphore.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <sys/shm.h>


#define BUF_SIZE 1024
#define MAX_PASSWORD_LEN 50
#define MAX_USERNAME_LEN 50
#define MAX_ROLE_LEN 50
#define MAX_CLASS_NAME_LEN 50
#define MAX_TOPICS 20
#define MAX_REGISTERED_USERS 100
#define MAX_SUBSCRIBED_CLASSES 20
#define FIRST_MULTICAST_PORT 5000

#define PORTO_CONFIG 9001
#define PORTO_TURMAS 9000

#define MAX_USERS 20
#define MAX_CLASSES 100

#define CONFIG "config.txt"
#define TMPCFG "temp.txt"



// Estrutura de um utilizador
typedef struct {
    char username[BUF_SIZE];
    char password[BUF_SIZE];
    char role[BUF_SIZE];
} User;

// Defines a single class
typedef struct class_info{
    char name[MAX_CLASS_NAME_LEN];
    int class_size;
    char mc_address[16];
    int udp_socket;
    struct sockaddr_in udp_address;
    User subscribed_users[MAX_CLASSES];
} ClassInfo; 

// Shared memory structure for classes
typedef struct classes{
    int classes_count;
    ClassInfo classes[MAX_CLASSES];
} Classes;

// Shared memory structure for classes
extern Classes *classes_shm;
extern int classes_shm_id;

// Semaphore for file reading
 sem_t *user_sem;



//_________________________________________________________________________________
// class_server.c Admin functions

//Load config.txt to arrays
void read_credentials(User admin_users[], int *num_admin_users, User student_users[], int *num_aluno_users, User professor_users[], int *num_professor_users);

//Login request handler for UDP
int handle_login_request_udp(int fd, User admin_users[], int num_admin_users);

//_________________________________________________________________________________
// class_server.c Client functions (TCP SERVER)
void tcp_server();// Boot tcp server
void tcp_session_manager(char client_ip[], int client_fd); // Session manager
//void handle_login_request_tcp(int fd); // Log In handler

//_________________________________________________________________________________
// class_server.c Admin functions (UDP SERVER)


void udp_server(); // Start udp server
void udp_receive_message(char logged_admins[][INET_ADDRSTRLEN], int socket_fd, struct sockaddr *client_addr, socklen_t *slen);


void process_admin(int udp_socket, struct sockaddr_in client_addr); // Process admin commands
void send_command_list(int udp_socket, struct sockaddr_in client_addr);
char *trim_whitespace(char *str);

void add_user(char *username, char *password, char *role); // Add user command

void delete_user(char *username); // Delete user command
void read_credential_udp(User admin_users[], int *num_admin_users);
void list_user(char (*username)[MAX_USERNAME_LEN]); // List users command

//_________________________________________________________________________________
// Miscellaneous functions
void erro(char* s);

#endif
