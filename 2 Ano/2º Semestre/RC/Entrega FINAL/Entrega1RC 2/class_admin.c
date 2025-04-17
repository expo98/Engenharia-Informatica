/*******************************************************************************
									UDP CLIENT
*******************************************************************************/

#include "Header.h"


void error(char *msg);
void session_manager(int socket_fd, struct sockaddr *addr, socklen_t slen);
int send_message(int socket_fd, struct sockaddr *addr, socklen_t slen);
void receive_answer(int socket_fd, struct sockaddr *addr, socklen_t slen);
void sigint_handler();

int main(int argc, char *argv[]) 
{
    printf("\n\n");
    
	if (argc != 3)
		error("deve utilizar os seguintes argumentos: [server_ip] [port]");

    printf("Inicialização em progresso...\n\n");

    int socket_fd; //file descriptor
    char endServer[100];
    struct sockaddr_in addr;

    strcpy(endServer, argv[1]);
    if (gethostbyname(endServer) == 0) 
        error("IP não encontrado!");

    //preenche a estrutura de endereço do servidor
    bzero((void *) &addr, sizeof(addr)); 
    addr.sin_family = AF_INET; 
    addr.sin_port = htons((short) atoi(argv[2])); 
    addr.sin_addr.s_addr = htonl(INADDR_ANY); 

    //cria um socket para receção de datagramas UDP
    socklen_t slen = sizeof(addr); 

    if ((socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) 
        error("socket inválido!");
    if (connect(socket_fd, (struct sockaddr *) &addr, slen) < 0) 
        error("não foi possível conectar!");

    // define o handler para SIGINT
    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, NULL) == -1)
        error("não foi possível definir o handler para SIGINT!");

    printf("Pronto para comunicar com o servidor!\n\n\n");

    printf("Comece por fazer login como administrador caso ainda não tenha sessão iniciada, deve utilizar o seguinte comando:\n"
           "LOGIN [username] [password]\n\n");
        
	session_manager(socket_fd, (struct sockaddr *) &addr, slen); // inicia um gestor de sessão

	receive_answer(socket_fd, (struct sockaddr *) &addr, slen); // recebe a mensagem de despedida

    printf("\n");
    close(socket_fd);

    exit(0);
}

void error(char *input)
{
	printf("Erro, %s\n\n", input);
	exit(-1);
}

void session_manager(int socket_fd, struct sockaddr *addr, socklen_t slen)
{
    while (!send_message(socket_fd, addr, slen)) // lê a mensagem a enviar para o servidor e verifica se é um pedido de saída ou não
        receive_answer(socket_fd, addr, slen);
}

void receive_answer(int socket_fd, struct sockaddr *addr, socklen_t slen)
{
    char answer[BUF_SIZE];
    int nread;

    // recebe a resposta do servidor
    if((nread = recvfrom(socket_fd, answer, BUF_SIZE, 0, addr, &slen)) == -1)
        error("o servidor não respondeu, é possível que tenha sido desligado ou esta porta é inválida!");

    answer[nread]='\0'; // ignorar o restante conteúdo

    printf("%s\n\n", answer);
}

int send_message(int socket_fd, struct sockaddr *addr, socklen_t slen)
{
	char input[BUF_SIZE];

    printf(">>> ");
	fgets(input, BUF_SIZE, stdin);
    if(input[0] == '\n')
		strcpy(input, "invalid\n");
    printf("\n\n");

	input[strcspn(input, "\n")] = '\0';

    // envia a mensagem para o servidor
	if(sendto(socket_fd, input, strlen(input), 0, addr, slen) == -1)
        error("não foi possível enviar a mensagem!");

    if (strcmp(input, "QUIT") == 0) 
        return 1;
	else
		return 0;
}

void sigint_handler()
{
    printf("INTERRUPT\n\nA sua sessão irá manter-se aberta pois fechou o programa com CTRL+C, para terminar a sessão utilize o comando QUIT!\n\n");
    exit(0);
}
