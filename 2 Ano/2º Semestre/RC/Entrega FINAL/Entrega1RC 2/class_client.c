/**********************************************************************
 * CLIENTE liga ao servidor (definido em argv[1]) no porto especificado
 * (em argv[2]) USO: >cliente <enderecoServidor>  <porto> 
 **********************************************************************/
#include "Header.h"


int server_fd;
Classes subbed_classes;
pthread_mutex_t subbed_classes_mutex = PTHREAD_MUTEX_INITIALIZER;

int send_message();
void login(int fd);
void receive_answer();
void session_manager(int server_fd);
void error(char *msg);

int main(int argc, char *argv[]) 
{
  char endServer[100];
  struct sockaddr_in addr;
  struct hostent *hostPtr;

  if (argc != 3) {
    printf("cliente <host> <port>\n");
    exit(-1);
  }

  strcpy(endServer, argv[1]);
  if ((hostPtr = gethostbyname(endServer)) == 0)
    erro("Não consegui obter endereço");

  bzero((void *) &addr, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = ((struct in_addr *)(hostPtr->h_addr))->s_addr;
  addr.sin_port = htons(atoi(argv[2]));

  if ((server_fd = socket(AF_INET,SOCK_STREAM,0)) == -1)
	  erro("socket");
  if (connect(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
      perror("Connect error");
      exit(EXIT_FAILURE);
  }

  struct sigaction sh;
  //sh.sa_handler = sigint_handler; // Adicionar sigint handler
  sigemptyset(&sh.sa_mask);
  sh.sa_flags=0;

  // Signal handler
  if (sigaction(SIGINT, &sh, NULL) == -1) {
      error("não foi possível instalar o signal handler!");
      exit(1);
  }

  printf("Conexão estabelecida com sucesso!\n\n\n");
  
  receive_answer();

  session_manager(server_fd);

  receive_answer();

  close(server_fd);
  exit(0);
}

void session_manager(int server_fd) {
    int procedure = 1; // Inicializa o código de procedimento

    // Loopa até o código de procedimento indicar saída
    while (procedure > 0) {
        // Chama send_message() para determinar a próxima ação
        procedure = send_message();

        // Continua baseado no códido de procedimento
        if (procedure == 1) {
            // Tentativa de enviar mensagem ao servidor
            if (send(server_fd, NULL, 0, MSG_NOSIGNAL) != -1) {
                // Se succesful, recebe mensagem do servidor
                receive_answer(server_fd);
            } else {
                // Se o servidor não responder, envia uma mensagem de error
                error("error: Servidor não respondeu.");
            }
        } else if (procedure == 2) {
            // // Se código de procedimento for 2, prompt por input
            printf(">>> ");
        }
    }
}


void login(int fd) {
    char username[BUF_SIZE];
    char password[BUF_SIZE];
    char buffer[BUF_SIZE];

    printf("Username: ");
    scanf("%506s", username);
    printf("Password: ");
    scanf("%506s", password);

    // Construir mensagem de login
   snprintf(buffer, sizeof(buffer), "LOGIN %.505s %.505s", username, password);

    // Enviar mensagem de login para o servidor
    write(fd, buffer, strlen(buffer));

    // Receber resposta do servidor
    read(fd, buffer, sizeof(buffer));

    // Imprimir resposta do servidor
    printf("%s\n", buffer);
}

void sigint_handler() 
{
	int nread;
	char buffer[BUF_SIZE];

	printf("QUIT\n\n");

    if(write(server_fd,"QUIT", strlen("QUIT")) == -1)
		error("não foi possível enviar a mensagem!");

	nread = read(server_fd, buffer, BUF_SIZE);
	if(nread == -1)
		error("não foi possível receber uma resposta do servidor!");

	buffer[nread] = '\0';
	printf("%s\n\n", buffer);

	close(server_fd);

	/*
  for (int i = 0; i < subbed_topics_count; i++)
	{
		if (setsockopt(subbed_topics[i].socket_fd, IPPROTO_IP, IP_DROP_MEMBERSHIP, &subbed_topics[i].mreq, sizeof(subbed_topics[i].mreq)) < 0)
			error("não foi possível sair de um grupo multicast!");

		close(subbed_topics[i].socket_fd);
	}
  */
	
	_exit(EXIT_SUCCESS);
}

void receive_answer()
{
  int nread;
  char buf[BUF_SIZE];

  nread = read(server_fd, buf, BUF_SIZE);
  if(nread == -1)
    error("não foi possível obter resporta do servidor!");

  buf[nread] = '\0';
  printf("%s\n\n",buf);

  // varia a mensagem de pedido de introdução de dados consoante a mensagem recebida
  if(!strcasecmp(buf,"User name não registado. Tente novamente!") || !strcmp(buf,"Bem-vindo! Efetue o login com as suas credenciais ou digite QUIT para terminar."))
    printf("Username >>> "); // Pedido de introdução de username
  else if (!strcasecmp(buf,"Password incorreta, tente novamente!") || !strcasecmp(buf,"Username identificado!"))
    printf("Password >>> "); // pedido de introdução de password
  else if (!strcmp(buf,"Não foi possível processar as permissões desta conta, a sua sessão será terminada, contacte um administrador!"))
    exit(-1); // recebeu uma mensagem de error nesta conta, termina a sessão para forçar a iniciar noutra
  else if (!strcasecmp(buf,"A sua sessão foi terminada com sucesso!") || !strcmp(buf, "Processo de login cancelado!"))
    return;
  else
    printf(">>> "); // O login foi efectuado com sucesso, introdução de comandos genéricos
    
}

int send_message()
{
  char message[BUF_SIZE];
  fgets(message,BUF_SIZE,stdin);
    if(message[0] == '\n')
    strcpy(message, "invalid\n");
    printf("\n\n");

  message[strcspn(message,"\n")] = '\0';

  if(write(server_fd,message,strlen(message))== -1)
    error("não foi possível enviar a mensaem!");

  char *token = strtok(message, " ");

  if(!strcasecmp(token,"LIST_CLASSES"))
  {
    
  }
  else if (!strcasecmp(token,"LIST_SUBSCRIBED"))
  {
    pthread_mutex_lock(&subbed_classes_mutex);
    if(subbed_classes.classes_count == 0)
    {
    printf("Não está inscrito em nenhuma turma.");
    pthread_mutex_unlock(&subbed_classes_mutex);
    return 2;
    }
    printf("Turmas em que está inscrito:\n\n");
    for (int i = 0; i < subbed_classes.classes_count; i++)
    {
      printf("%s\n\n",subbed_classes.classes[i].name);
    }
    
  }
  else if (!strcasecmp(token,"SUBSCRIBE_CLASS"))
  {
    int nread;
    char buf[BUF_SIZE];
    nread = read(server_fd,buf,BUF_SIZE); // Recebe a resposta do servidor
    if(nread==-1)
      error("não foi possível receber resposta do servidor!");
      
    buf[nread] = '\0';
    
    if(!strcasecmp("Não existe nenhumam turma com este nome!",buf))
    {
      printf("%s\n\n",buf);
      return 2;
    }

    ClassInfo new_subbed_class;

    strcpy(new_subbed_class.name,strtok(buf, "#")); // Compor o token
    for (int i = 0; i < subbed_classes.classes_count; i++)
    {
      if(strcasecmp(new_subbed_class.name,subbed_classes.classes[i].name) == 0)
      {
        printf("Já está inscrito nesta turma!\n\n");
        return 2;
      }
    }
    
  }
  else if (!strcasecmp(token,"QUIT"))
  return 0;

  return 1;
}

void error(char *msg) {
    printf("Erro: %s\n", msg);
    exit(-1);
}
