#include <stdio.h>
#include <stdlib.h>
#include <string.h>




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




int main(){
  // Main function

  bstMenu();



  return 0;
}


//*************************************************************************************************//
//*************************************** BINARY SEARCH TREE **************************************//
//*************************************************************************************************//
void bstMenu()
{
  int option =1 ;
  int num;

  printf("Escolha um número para a raiz: ");

  scanf("%d", &num);
  NodeBST_t *root = createNodeBST(num); // Create the root node

  while (option != 0)
  {
    printf("Binary Tree Menu\n");
    printf("1) Insert a new node\n2) Print all nodes\n3) Search for a number\n4) Insert a million elements\n0)Exit and free memory\n\nOption: ");
    scanf("%d",&option);
    // User menu
    switch (option)
    {
      case 1:
      {
        printf("\nChoose a number for the next node: ");
        scanf("%d",&num);
        printf("\n");
        insertNodeBST(root,num); // Insert a new node
      }
      break;
      
      case 2:
      {
        printf("\n");
        printTreeBST(root,0); // Print all nodes
        printf("\n");
      }
      break;
      case 3:
      {
        printf("\nChoose a number to search for: ");
        scanf("%d",&num);
        searchBinaryBST(root,num);
        printf("\n");
        break;
      }
      case 4:
        printf("Inserting 1000000 elements...");
        insertMillionElements(root);
      break;
      case 0:
        freeBinaryTreeBST(root);

      break;
      default:
        printf("Option not available!\n");
        break;
    }
  }
  
  insertNodeBST(root, num); // Insert a new node
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
    freeBinaryTreeBST(root->left);
  }

  if (root->right != NULL) {
    freeBinaryTreeBST(root->right);
  }

  free(root);
  return;
}
