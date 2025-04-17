#include <stdlib.h>
#include <stdio.h>

// Estrutura do nó AVL
typedef struct nodeAVL{
  int key,height;
  struct nodeAVL* left;
  struct nodeAVL* right;

}nodeAVL_t;

#define new_max(x,y) (((x) >= (y)) ? (x) : (y)) /*Adaptado de https://stackoverflow.com/questions/21338215/library-function-for-finding-the-larger-of-two-numbers */

nodeAVL_t* createAVLTree(int key);
nodeAVL_t* insertNodeAVL(nodeAVL_t* root, int key);
nodeAVL_t* leftRotateAVL(nodeAVL_t* originalNode);
nodeAVL_t* rightRotateAVL(nodeAVL_t* originalNode);
void printTreeAVL(nodeAVL_t* root);
void freeNodesAVL(nodeAVL_t* root);
void menuAVL();

int main(){
  menuAVL;
  return 0;
}

void menuAVL()
{
  int key, resposta;

  printf("Insira um número para a raiz: ");
  scanf("%d",&key);
  while (getchar() != '\n');
  nodeAVL_t* raizAVL = createAVLTree(key);
  
  while (1)
  {
    printf("      Menu AVL\n");
    printf("1) Inserir um novo nó\n");
    printf("2) Imprime os nós\n");
    printf("3) Libertar memória e sair\n\n");
    printf("Opção: ");
    scanf("%d",&resposta);
    while (getchar() != '\n');

    switch (resposta)
    {
    case 1:
      printf("\n\n\n\n");
      printf("Insira um número para a novo nó: ");
      scanf("%d",&key);
      raizAVL = insertNodeAVL(raizAVL,key);
      printf("\n\n\n\n\n");
      break;
    case 2:
      printf("\n\n\n\n\n");
      printTreeAVL(raizAVL);
      printf("\n\n\n\n\n");
      break;
    case 3:
      freeNodesAVL(raizAVL);
      printf("Nós libertados!\nSaindo...");
      return 0;
    break;
    default:
      printf("Opção Inválida!\n\n\n\n\n");
      break;
    }
  }
}




nodeAVL_t* createAVLTree(int key){

  nodeAVL_t* root = (nodeAVL_t*) malloc(sizeof(nodeAVL_t));
  if (root == NULL)
  {
    perror("Memory allocation failed!\n");
    free(root);
    exit(1);
  }

  root->key = key;
  root->left= NULL;
  root->right= NULL;
  root->height=1;

  return root;
}

nodeAVL_t* insertNodeAVL(nodeAVL_t* root, int key){

 if (root == NULL) {
    nodeAVL_t* node = (nodeAVL_t*)malloc(sizeof(nodeAVL_t));
    if (node == NULL) {
        perror("Memory allocation failed!\n");
        exit(1);
    }

    // Inicializa o novo
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
  }

  else if (key < root->key)
  {
    root->left = insertNodeAVL(root->left, key);
  }
  else if (key > root->key)
  {
    root->right = insertNodeAVL(root->right,key);
  }
  //Previne que existam nós com a mesma chave, liberta a memória criada 
  else if( key == root->key){
    printf("Erro: Chave já existente!\n");
    free(root);
    return root;
  }

  // Atualiza o height do nó
  if (root->left != NULL && root->right != NULL) {
    root->height = 1 + new_max(root->left->height, root->right->height);
  } else if (root->left != NULL) {
    root->height = 1 + root->left->height;
  } else if (root->right != NULL) {
    root->height = 1 + root->right->height;
  } else {
    root->height = 1;
  }

  // Vai buscar o factor de equilibrio para verificar se está ou não desequilibrado
  int balance = 0;
  if (root->left != NULL && root->right != NULL) {
    balance = (root->left->height) - (root->right->height);
  } else if (root->left != NULL) {
    balance = root->left->height;
  } else if (root->right != NULL) {
    balance = -root->right->height;
  }

  // Se o nó estiver desquilibrado, existem 4 casos


  // Left Left
  if (balance > 1 && key < root->left->key)
  {
    printf("Left left 1\n");
    return rightRotateAVL(root);
    printf("Left left 2\n");
  }
  
  //Right Right
  if (balance < -1 && key > root->right->key)
  {
    printf("Right Right 1\n");
    return leftRotateAVL(root);
    printf("Right Right 2\n");
  }

  // Left Right
  if (balance > 1 && key > root->left->key)
  {
    printf("Left right 1\n");
    root->left = leftRotateAVL(root);
    return rightRotateAVL(root);
    printf("Left right 2\n");

  }

  // Right left
  if (balance < -1 && key < root->right->key)
  {
    printf("Right left 1\n");
    root->right = rightRotateAVL(root);
    return leftRotateAVL(root);
    printf("Right left 2\n");
  }
  return root;

}


nodeAVL_t* leftRotateAVL(nodeAVL_t* originalNode)
{
    // Verifica se o originalNode ou seu right child são nulos
    if (originalNode == NULL || originalNode->right == NULL)
        return originalNode; // Nenhuma rotação pode ser realizada

    // Define newNode como o right child do originalNode
    nodeAVL_t* newNode = originalNode->right;
    // Verifica se o novo nó é nulo
    if (newNode == NULL)
        return originalNode; // Nenhuma rotação pode ser realizada

    // Guarda o left child do novo nó
    nodeAVL_t* tempNode = newNode->left;

    // Efetua a rotação
    newNode->left = originalNode;
    originalNode->right = tempNode;

    // Atualiza as alturas (garante verificar os ponteiros nulos antes de acessar seus membros)
    int leftHeight;
    if (originalNode->left != NULL)
        leftHeight = originalNode->left->height;
    else
        leftHeight = 0;
  
    int rightHeight;
    if (originalNode->right != NULL)
        rightHeight = originalNode->right->height;
    else
        rightHeight = 0;

    originalNode->height = 1 + new_max(leftHeight, rightHeight);

    if (newNode->left != NULL)
        leftHeight = newNode->left->height;
    else
        leftHeight = 0;

    if (newNode->right != NULL)
        rightHeight = newNode->right->height;
    else
        rightHeight = 0;

    newNode->height = 1 + new_max(leftHeight, rightHeight);

    return newNode;
}


nodeAVL_t* rightRotateAVL(nodeAVL_t* originalNode)
{
    // Verifica se originalNode ou o seu left child são NULL
    if (originalNode == NULL || originalNode->left == NULL)
        return originalNode; //Nenhuma rotação pode ser realizada

    // Define o newNode como o left child do originalNode
    nodeAVL_t* newNode = originalNode->left;
    // Verifica se o newNode é NULL
    if (newNode == NULL)
        return originalNode; // Nenhuma rotação pode ser efetuada

    // Guarda o right child do novo nó
    nodeAVL_t* tempNode = newNode->right;

    // Efetua a rotação
    newNode->right = originalNode;
    originalNode->left = tempNode;

    // Atualiza as alturas (verifica por ponteiros NULL antes de acessar os seus)
    int leftHeight;
    if (originalNode->left != NULL)
        leftHeight = originalNode->left->height;
    else
        leftHeight = 0;
  
    int rightHeight;
    if (originalNode->right != NULL)
        rightHeight = originalNode->right->height;
    else
        rightHeight = 0;

    originalNode->height = 1 + new_max(leftHeight, rightHeight);

    if (newNode->left != NULL)
        leftHeight = newNode->left->height;
    else
        leftHeight = 0;

    if (newNode->right != NULL)
        rightHeight = newNode->right->height;
    else
        rightHeight = 0;

    newNode->height = 1 + new_max(leftHeight, rightHeight);

    return newNode;
}



void printTreeAVL(nodeAVL_t* root)
{
  if (root == NULL)
  {
    return;
  }
  
  printTreeAVL(root->left);

  for (int i = 0; i < root->height * 4; i++)
  {
    printf(" ");
  }
  printf("%d\n", root->key);

  printTreeAVL(root->right);
}

void freeNodesAVL(nodeAVL_t* root){
  if (root == NULL)
  {
    return;
  }

  //Liberta a memória dos nós da subtree da esquerdarecursivamente
  freeNodesAVL(root->left);
  //Liberta a memória dos nós da subtree da direita recursivamente
  freeNodesAVL(root->right);
  
  free(root);
}