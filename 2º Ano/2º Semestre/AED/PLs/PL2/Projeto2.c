#include <stdlib.h>
#include <stdio.h>
#include <time.h>


// TEMPO

  clock_t start_time, end_time;
  double elapsed_time;


//**************************************************************************************************//
//*************************************** CONJUNTO DE NUMEROS **************************************//
//*************************************************************************************************//


int conjuntoA1[1000];
int conjuntoA2[5000];
int conjuntoA3[10000];
int conjuntoA4[50000];
int conjuntoA5[100000];

int conjuntoB1[1000];
int conjuntoB2[5000];
int conjuntoB3[10000];
int conjuntoB4[50000];
int conjuntoB5[100000];

int conjuntoC1[1000];
int conjuntoC2[5000];
int conjuntoC3[10000];
int conjuntoC4[50000];
int conjuntoC5[100000];

int conjuntoD1[1000];
int conjuntoD2[5000];
int conjuntoD3[10000];
int conjuntoD4[50000];
int conjuntoD5[100000];

//*************************************************************************************************//
//****************************************** BINARY  TREE *****************************************//
//*************************************************************************************************//

typedef struct nodeBin {
  int value;
  struct nodeBin* left;
  struct nodeBin* right;
} nodeBin_t;

void binMenu();
void printTreeBin(nodeBin_t* root, int value);
nodeBin_t* createRootBin(int value);
nodeBin_t* insertTreeBin(nodeBin_t* root, int value);
void definirConjuntos();
void generate_C(int X, int array[]);
void generate_D(int X, int array[]);
void inserirConjuntoBin(int array[],int size);

//*************************************************************************************************//
//*************************************** BINARY SEARCH TREE **************************************//
//*************************************************************************************************//

// Struct of a Node for a Binary Search Tree
typedef struct NodeBST
{
  int num;
  struct NodeBST *left;
  struct NodeBST *right;
} NodeBST_t;

NodeBST_t* createNodeBST(int num); // Function  for creating a new node
NodeBST_t* insertNodeBST(NodeBST_t* root, int num); // Function  for inserting a node
void searchBinaryBST(NodeBST_t* root, int num);
void printTreeBST(NodeBST_t* root, int value);
void bstMenu(); // Function to start a binary Tree
void inserirConjuntoBST(int array[], int size);


//*************************************************************************************************//
//**************************************** AVL SEARCH TREE ****************************************//
//*************************************************************************************************//

// Código de AVL SearchTree inspirado de: https://github.com/msambol/dsa/blob/master/trees/avl_tree.py

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
void inserirAVL(int array[],int size);

int AVLrotations = 0;


//*************************************************************************************************//
//***************************************** VP SEARCH TREE ****************************************//
//*************************************************************************************************//

/*  Código adaptado de : https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/        */

// Structure to represent each 
// node in a red-black tree
struct nodeVP {
	int d; // data
	int c; // 1-red, 0-black
	struct nodeVP* p; // parent
	struct nodeVP* r; // right-child
	struct nodeVP* l; // left child
};

void fixupVP(struct nodeVP* root, struct nodeVP* pt);
struct nodeVP* bstVP(struct nodeVP* trav, struct nodeVP* temp);
void rightrotateVP(struct nodeVP* temp);
void leftrotateVP(struct nodeVP* temp);
void inorderVP(struct nodeVP* trav);
void VPtree();
void insertArrayIntoVP(int array[], int size);
int VProtations;


//*************************************************************************************************//
//*************************************************************************************************//
//*************************************************************************************************//


int main()
{

  definirConjuntos(); // Chama a função para definir os arrays A,B,C,D (1-5)




  int escolha=-1;


  while (escolha <1 || escolha > 5)
  {
    printf("Escolha que árvore deseja testar\n1) Binary tree\n2)Binary Search Tree\n3)AVL Search Tree\n4)VP Search Tree\n5) Sair");
    printf("\n\nOpção: ");
    scanf("%d",&escolha);
  }

  switch (escolha)
  {
  case 1:
    binMenu();
    break;
  case 2:
    bstMenu();
    break;
  case 3:
    menuAVL();
    break;
  case 4:
    VPtree();
    break;
  case 5:
  return 0;
  break;
  
  default:
    break;
  }
  

  return 0;
}


void definirConjuntos()
{
  for (int i = 0; i < 1000; i++)
  {
    conjuntoA1[i] = i;
    if (i>=900)
    {
      conjuntoA1[i] = conjuntoA1[i-900];
    }
    
  }

  for (int i = 0; i < 5000; i++)
  {
    conjuntoA2[i] = i;
      if (i>=4500)
    {
      conjuntoA2[i] = conjuntoA2[i-4500];
    }
  }

  for (int i = 0; i < 10000; i++)
  {
    conjuntoA3[i] = i;
      if (i>=9000)
    {
      conjuntoA3[i] = conjuntoA3[i-9000];
    }
  }


  for (int i = 0; i < 50000; i++)
  {
    conjuntoA4[i] = i;
      if (i>=45000)
    {
      conjuntoA4[i] = conjuntoA5[i-45000];
    }
  }




  int B1 = 1000;
  int B2 = 5000;
  int B3 = 10000;
  int B4 = 50000;


  for (int i = 0; i < 1000; i++) {
      conjuntoB1[i] = B1--;
      if (i >=900)
      {
        conjuntoB1[i] = conjuntoB1[i-900];
      }
      
  }

  for (int i = 0; i < 5000; i++) {
      conjuntoB2[i] = B2--;
      if (i >=4500)
      {
        conjuntoB2[i] = conjuntoB2[i-4500];
      }
  }

  for (int i = 0; i < 10000; i++) {
      conjuntoB3[i] = B3--;
      if (i >=9000)
      {
        conjuntoB3[i] = conjuntoB3[i-9000];
      }
  }

  for (int i = 0; i < 50000; i++) {
      conjuntoB4[i] = B4--;
      if (i >=45000)
      {
        conjuntoB4[i] = conjuntoB4[i-45000];
      }
  }



  generate_C(1000,conjuntoC1);
  generate_C(5000,conjuntoC2);
  generate_C(10000,conjuntoC3);
  generate_C(50000,conjuntoC4);

  generate_D(1000,conjuntoD1);
  generate_D(5000,conjuntoD2);
  generate_D(10000,conjuntoD3);
  generate_D(50000,conjuntoD4);

}

void generate_C(int X, int array[]) {
    int num_repeats = X * 0.1; // percentage% de X

    // Gera numeros para o array
    for (int i = 0; i < X - num_repeats; i++) {
        array[i] = i; 
    }

    // Repete percentage % dos numeros aleatorios
    for (int i = X - num_repeats; i < X; i++) {
        array[i] = array[rand() % (X - num_repeats)]; // Seleciona aleatoriamente para repetir
    }

    // Baralha o array para garantir aleatoriadade
    for (int i = X - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void generate_D(int X, int array[]) {
    int num_repeats = X * 0.9; // percentage% de X

    // Gera numeros para o array
    for (int i = 0; i < X - num_repeats; i++) {
        array[i] = i; 
    }

    // Repete percentage % dos numeros aleatorios
    for (int i = X - num_repeats; i < X; i++) {
        array[i] = array[rand() % (X - num_repeats)]; // Seleciona aleatoriamente para repetir
    }

    // Baralha o array para garantir aleatoriadade
    for (int i = X - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

//*************************************************************************************************//
//****************************************** BINARY  TREE *****************************************//
//*************************************************************************************************//

void binMenu(){

    printf("Conjunto A1\n");
    inserirConjuntoBin(conjuntoA1,1000);
    printf("Conjunto A2\n");
    inserirConjuntoBin(conjuntoA2,5000);
    printf("Conjunto A3\n");
    inserirConjuntoBin(conjuntoA3,10000);
    printf("Conjunto A4\n");
    inserirConjuntoBin(conjuntoA4,50000);
    

    printf("Conjunto B1\n");
    inserirConjuntoBin(conjuntoB1,1000);
    printf("Conjunto B2\n");
    inserirConjuntoBin(conjuntoB2,5000);
    printf("Conjunto B3\n");
    inserirConjuntoBin(conjuntoB3,10000);
    printf("Conjunto B4\n");
    inserirConjuntoBin(conjuntoB4,50000);
    

    printf("Conjunto C1\n");
    inserirConjuntoBin(conjuntoC1,1000);
    printf("Conjunto C2\n");
    inserirConjuntoBin(conjuntoC2,5000);
    printf("Conjunto C3\n");
    inserirConjuntoBin(conjuntoC3,10000);
    printf("Conjunto C4\n");
    inserirConjuntoBin(conjuntoC4,50000);
    

    printf("Conjunto D1\n");
    inserirConjuntoBin(conjuntoD1,1000);
    printf("Conjunto D2\n");
    inserirConjuntoBin(conjuntoD2,5000);
    printf("Conjunto D3\n");
    inserirConjuntoBin(conjuntoD3,10000);
    printf("Conjunto D4\n");
    inserirConjuntoBin(conjuntoD4,50000);
    

  return;
}

void inserirConjuntoBin(int array[],int size){

  start_time = clock();

  nodeBin_t* root = createRootBin(array[0]);

  for (int i = 1; i < size; i++)
  {
    insertTreeBin(root,array[i]);
  }
  end_time = clock();
  elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
  printf("Elapsed time: %.6f seconds\n", elapsed_time);
  printf("\n\n\n");

}

nodeBin_t* createRootBin(int value){

  nodeBin_t *root = (nodeBin_t*) malloc(sizeof(nodeBin_t));

  root->value = value;
  root->left=NULL;
  root->right = NULL;

  return root;
}

nodeBin_t* insertTreeBin(nodeBin_t* root, int value){

  int r = rand();
  
  
  if (root == NULL) {
    nodeBin_t* newNode = (nodeBin_t*)malloc(sizeof(nodeBin_t));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }

  if (r % 2 == 0) {
    root->left = insertTreeBin(root->left, value);
  } else {
    root->right = insertTreeBin(root->right, value);
  }

  return root;
}


void printTreeBin(nodeBin_t* root, int value){

   if (root == NULL || value == 20)
  {
    return;
  }
  
  printTreeBin(root->left, value + 1);

  for (int i = 0; i < value * 4; i++)
  {
    printf(" ");
  }
  printf("%d\n", root->value);

  printTreeBin(root->right, value + 1);
}


//*************************************************************************************************//
//*************************************** BINARY SEARCH TREE **************************************//
//*************************************************************************************************//
void bstMenu()
{

  printf("Conjunto A1:\n");
  inserirConjuntoBST(conjuntoA1,1000);
  printf("Conjunto A2:\n");
  inserirConjuntoBST(conjuntoA2,5000);
  printf("Conjunto A3:\n");
  inserirConjuntoBST(conjuntoA3,10000);
  printf("Conjunto A4:\n");
  inserirConjuntoBST(conjuntoA4,50000);
  
  printf("Conjunto B1:\n");
  inserirConjuntoBST(conjuntoB1,1000);
  printf("Conjunto B2:\n");
  inserirConjuntoBST(conjuntoB2,5000);
  printf("Conjunto B3:\n");
  inserirConjuntoBST(conjuntoB3,10000);
  printf("Conjunto B4:\n");
  inserirConjuntoBST(conjuntoB4,50000);
 

  printf("Conjunto C1:\n");
  inserirConjuntoBST(conjuntoC1,1000);
  printf("Conjunto C2:\n");
  inserirConjuntoBST(conjuntoC2,5000);
  printf("Conjunto C3:\n");
  inserirConjuntoBST(conjuntoC3,10000);
  printf("Conjunto C4:\n");
  inserirConjuntoBST(conjuntoC4,50000);
  

  printf("Conjunto D1:\n");
  inserirConjuntoBST(conjuntoD1,1000);
  printf("Conjunto D2:\n");
  inserirConjuntoBST(conjuntoD2,5000);
  printf("Conjunto D3:\n");
  inserirConjuntoBST(conjuntoD3,10000);
  printf("Conjunto D4:\n");
  inserirConjuntoBST(conjuntoD4,50000);
  
  return;
}


void inserirConjuntoBST(int array[], int size){

  start_time = clock();

  NodeBST_t* root = createNodeBST(array[0]);

  for (int i = 1; i < size; i++)
  {
    insertNodeBST(root,array[i]);
  }
  end_time = clock();
  elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
  printf("Elapsed time: %.6f seconds\n", elapsed_time);
  printf("\n\n");

}

NodeBST_t* insertNodeBST(NodeBST_t* root, int num) {
  // Function to insert a new node in the binary tree

  if (root == NULL) {
    NodeBST_t* newNode = (NodeBST_t*)malloc(sizeof(NodeBST_t));
    newNode->num = num;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }

  if (num < root->num) {
    root->left = insertNodeBST(root->left, num);
  } else if (num > root->num) {
    root->right = insertNodeBST(root->right, num);
  }

  return root;
}

void searchBinaryBST(NodeBST_t* root, int num){
  if (root == NULL) {
    printf("%d não encontrado!\n", num);
    return;
  }

  if (root->num == num)
  {
    printf("%d encontrado!\n", num);
    return;
  }

  if (num < root->num)
  {
    root= root->left;
    searchBinaryBST(root, num);
  } else if (num > root->num)
  {
    root = root->right;
    searchBinaryBST(root,num);
  }
}

NodeBST_t* createNodeBST(int num){
  // Function to create a new node
  NodeBST_t *root = (NodeBST_t *) malloc(sizeof(NodeBST_t));

  root->num = num;
  root->left = NULL;
  root->right = NULL;

  return root;
}


void printTreeBST(NodeBST_t* root, int value)
{
  if (root == NULL || value == 20)
  {
    return;
  }
  
  printTreeBST(root->left, value + 1);

  for (int i = 0; i < value * 4; i++)
  {
    printf(" ");
  }
  printf("%d\n", root->num);

  printTreeBST(root->right, value + 1);
}

void freeBST(NodeBST_t* root) {
  // Function to free the memory allocated for the binary tree

  if (root == NULL) {
    return;
  }

  if (root->left != NULL) {
    freeBST(root->left);
  }

  if (root->right != NULL) {
    freeBST(root->right);
  }

  free(root);
  return;
}


//*************************************************************************************************//
//**************************************** AVL SEARCH TREE ****************************************//
//*************************************************************************************************//

void menuAVL()
{
  printf("Conjunto A1:\n");
  inserirAVL(conjuntoA1,1000);
  printf("Conjunto A2:\n");
  inserirAVL(conjuntoA2,5000);
  printf("Conjunto A3:\n");
  inserirAVL(conjuntoA3,10000);
  printf("Conjunto A4:\n");
  inserirAVL(conjuntoA4,50000);


  printf("Conjunto B1:\n");
  inserirAVL(conjuntoB1,1000);
  printf("Conjunto B2:\n");
  inserirAVL(conjuntoB2,5000);
  printf("Conjunto B3:\n");
  inserirAVL(conjuntoB3,10000);
  printf("Conjunto B4:\n");
  inserirAVL(conjuntoB4,50000);


  printf("Conjunto C1:\n");
  inserirAVL(conjuntoC1,1000);
  printf("Conjunto C2:\n");
  inserirAVL(conjuntoC2,5000);
  printf("Conjunto C3:\n");
  inserirAVL(conjuntoC3,10000);
  printf("Conjunto C4:\n");
  inserirAVL(conjuntoC4,50000);


  printf("Conjunto D1:\n");
  inserirAVL(conjuntoD1,1000);
  printf("Conjunto D2:\n");
  inserirAVL(conjuntoD2,5000);
  printf("Conjunto D3:\n");
  inserirAVL(conjuntoD3,10000);
  printf("Conjunto D4:\n");
  inserirAVL(conjuntoD4,50000);
  
}


void inserirAVL(int array[],int size)
{
  start_time = clock();
  AVLrotations=0;
  nodeAVL_t* root = createAVLTree(array[0]);

  for (int i = 1; i < size; i++)
  {
    insertNodeAVL(root,array[i]);
  }
  end_time = clock();
  elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
  printf("%d rotacoes\n",AVLrotations);
  printf("Elapsed time: %.6f seconds\n", elapsed_time);
  printf("\n\n\n");

  freeNodesAVL(root);
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
  else {
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
    AVLrotations++;
    return rightRotateAVL(root);
  }
  
  //Right Right
  if (balance < -1 && key > root->right->key)
  {
    AVLrotations++;
    return leftRotateAVL(root);
 
  }

  // Left Right
  if (balance > 1 && key > root->left->key)
  {
    root->left = leftRotateAVL(root);
    AVLrotations++;
    return rightRotateAVL(root);
    AVLrotations++;

  }

  // Right left
  if (balance < -1 && key < root->right->key)
  {
    AVLrotations++;
    root->right = rightRotateAVL(root);
    AVLrotations++;
    return leftRotateAVL(root);
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


//*************************************************************************************************//
//***************************************** VP SEARCH TREE ****************************************//
//*************************************************************************************************//

// global root for the entire tree
struct nodeVP* root = NULL;

// function to perform BST insertion of a node
struct nodeVP* bstVP(struct nodeVP* trav, struct nodeVP* temp)
{
	// If the tree is empty, 
	// return a new node
	if (trav == NULL)
		return temp;

	// Otherwise recur down the tree
	if (temp->d < trav->d) 
	{
		trav->l = bstVP(trav->l, temp);
		trav->l->p = trav;
	}
	else if (temp->d > trav->d) 
	{
		trav->r = bstVP(trav->r, temp);
		trav->r->p = trav;
	}
  else
  {
    free(temp);
    return trav;
  }

	// Return the (unchanged) node pointer
	return trav;
}

// Function performing right rotation 
// of the passed node
void rightrotateVP(struct nodeVP* temp)
{
	struct nodeVP* left = temp->l;
	temp->l = left->r;
	if (temp->l)
		temp->l->p = temp;
	left->p = temp->p;
	if (!temp->p)
		root = left;
	else if (temp == temp->p->l)
		temp->p->l = left;
	else
		temp->p->r = left;
	left->r = temp;
	temp->p = left;
  }

// Function performing left rotation 
// of the passed node
void leftrotateVP(struct nodeVP* temp)
{
	struct nodeVP* right = temp->r;
	temp->r = right->l;
	if (temp->r)
		temp->r->p = temp;
	right->p = temp->p;
	if (!temp->p)
		root = right;
	else if (temp == temp->p->l)
		temp->p->l = right;
	else
		temp->p->r = right;
	right->l = temp;
	temp->p = right;
}

// This function fixes violations 
// caused by BST insertion
void fixupVP(struct nodeVP* root, struct nodeVP* pt)
{
    // Continue fixing until we reach the root or parent becomes black (or no parent exists)
    while (pt != root && pt->p != NULL && pt->p->c == 1) {
        struct nodeVP* parent_pt = pt->p;
        struct nodeVP* grand_parent_pt = parent_pt->p;

        // If parent is black or grandparent doesn't exist, no fixing needed, so break the loop
        if (grand_parent_pt == NULL || parent_pt->c == 0) {
            break;
        }

        // Case: Parent of pt is left child of Grand-parent of pt
        if (parent_pt == grand_parent_pt->l) {
            struct nodeVP* uncle_pt = grand_parent_pt->r;

            // Case 1: The uncle of pt is also red (Recoloring)
            if (uncle_pt != NULL && uncle_pt->c == 1) {
                grand_parent_pt->c = 1;
                parent_pt->c = 0;
                uncle_pt->c = 0;
                pt = grand_parent_pt;
            } else {
                // Case 2: pt is right child of its parent (Left-rotation)
                if (pt == parent_pt->r) {
                    pt = parent_pt;
                    VProtations++;
                    leftrotateVP(pt);
                    parent_pt = pt->p;
                }
                // Case 3: pt is left child of its parent (Right-rotation)
                parent_pt->c = 0;
                grand_parent_pt->c = 1;
                VProtations++;
                rightrotateVP(grand_parent_pt);
                pt = parent_pt;
            }
        } else {
            // Case: Parent of pt is right child of Grand-parent of pt
            struct nodeVP* uncle_pt = grand_parent_pt->l;

            // Case 1: The uncle of pt is also red (Recoloring)
            if (uncle_pt != NULL && uncle_pt->c == 1) {
                grand_parent_pt->c = 1;
                parent_pt->c = 0;
                uncle_pt->c = 0;
                pt = grand_parent_pt;
            } else {
                // Case 2: pt is left child of its parent (Right-rotation)
                if (pt == parent_pt->l) {
                    pt = parent_pt;
                    VProtations++;
                    rightrotateVP(pt);
                    parent_pt = pt->p;
                }
                // Case 3: pt is right child of its parent (Left-rotation)
                parent_pt->c = 0;
                grand_parent_pt->c = 1;
                VProtations++;
                leftrotateVP(grand_parent_pt);
                pt = parent_pt;
            }
        }
    }

    // Ensure root is black
    root->c = 0;
}


// Function to print inorder traversal 
// of the fixated tree
void inorderVP(struct nodeVP* trav)
{
	if (trav == NULL)
		return;
	inorderVP(trav->l);
	printf("%d ", trav->d);
	inorderVP(trav->r);
}

// driver code
void VPtree()
{
  printf("Conjunto A1\n");
	insertArrayIntoVP(conjuntoA1,1000);
  printf("Conjunto A2\n");
  insertArrayIntoVP(conjuntoA2,5000);
  printf("Conjunto A3\n");
  insertArrayIntoVP(conjuntoA3,10000);
  printf("Conjunto A4\n");
  insertArrayIntoVP(conjuntoA4,50000);
  

  printf("Conjunto B1\n");
  insertArrayIntoVP(conjuntoB1,1000);
  printf("Conjunto B2\n");
  insertArrayIntoVP(conjuntoB1,5000);
  printf("Conjunto B3\n");
  insertArrayIntoVP(conjuntoB1,10000);
  printf("Conjunto B4\n");
  insertArrayIntoVP(conjuntoB1,50000);
  

  printf("Conjunto C1\n");
  insertArrayIntoVP(conjuntoC1,1000);
  printf("Conjunto C2\n");
  insertArrayIntoVP(conjuntoC1,5000);
  printf("Conjunto C3\n");
  insertArrayIntoVP(conjuntoC1,10000);
  printf("Conjunto C4\n");
  insertArrayIntoVP(conjuntoC1,50000);


  printf("Conjunto D1\n");
  insertArrayIntoVP(conjuntoD1,1000);
  printf("Conjunto D2\n");
  insertArrayIntoVP(conjuntoD1,5000);
  printf("Conjunto D3\n");
  insertArrayIntoVP(conjuntoD1,10000);
  printf("Conjunto D4\n");
  insertArrayIntoVP(conjuntoD1,50000);
 

	
}

void insertArrayIntoVP(int array[], int size)
{
  start_time = clock();
  VProtations=0;
    for (int i = 0; i < size; i++) {

        // allocating memory to the node and initializing:
        // 1. color as red
        // 2. parent, left and right pointers as NULL
        // 3. data as i-th value in the array
        struct nodeVP* temp = (struct nodeVP*)malloc(sizeof(struct nodeVP));
        temp->r = NULL;
        temp->l = NULL;
        temp->p = NULL;
        temp->d = array[i];
        temp->c = 1;


        // calling function that performs bst insertion of
        // this newly created node
        root = bstVP(root, temp);

        // calling function to preserve properties of rb
        // tree
        fixupVP(root, temp);
        root->c = 0;
        
    }

  end_time = clock();
  elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
  printf("Elapsed time: %.6f seconds\n", elapsed_time);
  printf("%d rotações",VProtations);
  printf("\n\n\n");
}