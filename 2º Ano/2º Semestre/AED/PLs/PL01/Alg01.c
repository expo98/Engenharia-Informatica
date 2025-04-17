#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


bool checkForSum(int input[], int inputSize, int k) {

  for (int i = 0; i < inputSize; i++)
  {
    for (int j = 0; j < inputSize; j++)
    {
      if (input[i] + input[j] == k)
      {
        return true;
      } 
    }
  }
   return false;
}

int main(){
  //Start clock for execution time

  // Declare array input, array size and k which is the number that we will
  // search for the sum of a pair of numbers
  int input[] = {80, 98, 83, 92, 1, 38, 37, 54, 58, 89};
  int inputSize = sizeof(input)/sizeof(int);
  int k = 181;

  clock_t begin = clock();
   
   checkForSum(input, inputSize, k);
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Execution time : %f seconds\n", time_spent);
  return 0;

}