#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define TAMANHO 1000000


int cmp_int(const void *a, const void *b);
bool checkForSum(int input[], int inputSize, int k);


int main(){

  srand(time(NULL)); 

  int input[TAMANHO];
  for (int i = 0; i < TAMANHO; i++)
  {
    input[i]=i;
  }

  int inputSize = TAMANHO;
  int k = 1999997;
  bool foundPair;

  qsort(input,inputSize,sizeof(int),cmp_int);

  clock_t begin = clock();

  foundPair = checkForSum(input,inputSize, k);

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Execution time : %f seconds\n", time_spent);
  return 0;

}

int cmp_int(const void *a, const void *b)
{
  return * (int *)a - * (int *)b;
}

bool checkForSum(int input[], int inputSize, int k) {

  int i =0;
  int j = inputSize-1;

  int flag = 1;

  while ( flag == 1)
  {
    if (i >=j)
    {
      flag = 0;
    }
    
    if (input[i]+input[j]>k)
    {
      j--;
    }
    if (input[i]+input[j]<k)
    {
      i++;
    }
    if (input[i] + input[j]==k)
    {
      printf("True\n A soma do par %d e %d = %d\n",input[i],input[j],k);
      return true;
    }
  }
  
    printf("Não foi encontrado par\n");
   return false;
}