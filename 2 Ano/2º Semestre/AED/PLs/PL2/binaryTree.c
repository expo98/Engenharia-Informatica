#include <stdlib.h>
#include <stdio.h>
#include <time.h>



typedef struct nodeBin {
  int value;
  struct nodeBin* left;
  struct nodeBin* right;
} nodeBin_t;

void binMenu();
void printTreeBin(nodeBin_t* root, int value);
nodeBin_t* createRootBin(int value);
nodeBin_t* insertTreeBin(nodeBin_t* root, int value);


int main()
{

  return 0;
}

void binMenu(){
  
}

nodeBin_t* createRootBin(int value){

  nodeBin_t *root = (nodeBin_t*) malloc(sizeof(nodeBin_t));

  root->value = value;
  root->left=NULL;
  root->right = NULL;

  return root;
}

nodeBin_t* insertTreeBin(nodeBin_t* root, int value){
  
  srand(time(NULL));
  int r = rand();
  
  
  if (root == NULL) {
    nodeBin_t* newNode = (nodeBin_t*)malloc(sizeof(nodeBin_t));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }

  if (r % 2 == 0) {
    root->left = insertNodeBST(root->left, value);
  } else {
    root->right = insertNodeBST(root->right, value);
  }

  return root;
}


void printTreeBin(nodeBin_t* root, int value){

   if (root == NULL || value == 20)
  {
    return;
  }
  
  printTreeBST(root->left, value + 1);

  for (int i = 0; i < value * 4; i++)
  {
    printf(" ");
  }
  printf("%d\n", root->value);

  printTreeBST(root->right, value + 1);
}