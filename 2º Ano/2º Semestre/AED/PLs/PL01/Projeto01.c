#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define INTERVALORAND 10000

int cmp_int(const void *a, const void *b);
void Alg01(int input[], int inputSize, int k);
void Alg02(int input[], int inputSize, int k);
void Alg03(int input[], int inputSize, int k);
void funcaoAlgortimos(int size, int repeticoes);






int main(){

  int repeticoesNum = 10;

  // Impressão para Tabela
  printf("\n20 000 elementos\n");
  funcaoAlgortimos(20000,repeticoesNum);

  printf("\n40 000 elementos\n");
  funcaoAlgortimos(40000,repeticoesNum);

  printf("\n60 000 elementos\n");
  funcaoAlgortimos(60000,repeticoesNum);

  printf("\n80 000 elementos\n");
  funcaoAlgortimos(80000,repeticoesNum);

  printf("\n100 000 elementos\n");
  funcaoAlgortimos(100000,repeticoesNum);

  printf("\n\n\n\n\n\n");
  // Impressão para gráficos
  printf("\n100 000 elementos\n");
  funcaoAlgortimos(100000,1);

  printf("\n200 000 elementos\n");
  funcaoAlgortimos(200000,1);

  printf("\n300 000 elementos\n");
  funcaoAlgortimos(300000,1);

  printf("\n400 000 elementos\n");
  funcaoAlgortimos(400000,1);

  printf("\n500 000 elementos\n");
  funcaoAlgortimos(500000,1);

  printf("\n600 000 elementos\n");
  funcaoAlgortimos(600000,1);

  printf("\n700 000 elementos\n");
  funcaoAlgortimos(700000,1);

  printf("\n800 000 elementos\n");
  funcaoAlgortimos(800000,1);

  printf("\n900 000 elementos\n");
  funcaoAlgortimos(900000,1);

  printf("\n1 000 000 elementos\n");
  funcaoAlgortimos(1000000,1);


  return 0;
}

//Utilizado para quicksort
int cmp_int(const void *a, const void *b)
{
  return * (int *)a - * (int *)b;
}

void Alg01(int input[], int inputSize, int k) {

  //Percorre a lista de array duas vezes verificando se para cada numero na iteracao i
  //existe algum numero no array na iteracao j cuja soma seja igual a k
  for (int i = 0; i < inputSize; i++)
  {
    for (int j = 0; j < inputSize; j++)
    {
      if (input[i] + input[j] == k)
      {
        //printf("\nA soma do par %d e %d dão %d\n",input[i],input[j],k);
        return;
      } 
    }
  }
    //printf("\nNão foi encontrado par\n");
    return;
}

void Alg02(int input[], int inputSize, int k) {

  //Ordena o array
  qsort(input,inputSize,sizeof(int),cmp_int);

  int i =0;
  int j = inputSize-1;

  //Como o array encontra-se ordenado, vamos percorrer a itercao i crescentemente desde o 
  //primeiro numero no array, e a iteracao j decrescentemente desde o ultimo array
  while (i <j)
  { 
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
      //printf("\nA soma do par %d e %d = %d\n",input[i],input[j],k);
      return;
    }

  }
  
   //printf("\nNão foi encontrado par\n");
   return;
}

void Alg03(int input[], int inputSize, int k){
  
  //Define e inicializa a falso um array de booleanos com tamanho igual 
  //ao intervalo de número possiveis a serem introduzidos em input[]
  bool complemento[INTERVALORAND] = {false};
  int complementoInt;

  
  for (int i = 0; i < inputSize; i++)
  {
    //Define o complementoInt como a diferença entre o número atual na lista e o valor
    // "k" pre-definido, usamos abs() para evitar numeros negativos pois não existem
    complementoInt = abs(input[i] -k);


    if (complemento[complementoInt] == true)
    {
      //printf("\nA soma do par %d e %d dão %d\n",input[i],complementoInt,k);
      return;
    }
    //Muda o valor no índice de complemento[] para true, sinalizando que na lista
    //existe esse número
    complemento[input[i]] = true;
  }

  //printf("\nNão foi encontrado par\n");
  return;
}


void funcaoAlgortimos(int size, int repeticoes){

  srand(time(NULL)); 
  int input[size];
  for (int i = 0; i <= size; i++)
  {
    input[i]=rand() % INTERVALORAND;
  }

  int inputSize = size;
  int k = -1;

    // Time variables
    clock_t begin,end;
    double time_spent;


    //Algortimo 01

  float temposAlg01=0;
  float tempoMedioAlg01=0;

  for (int i = 0; i < repeticoes; i++)
  {
    //printf("\nRun %d : Algoritmo 01\n",i+1);
    begin = clock();

    Alg01(input,inputSize,k);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    temposAlg01 += time_spent;
    //printf("Run %d: Execution time for Algoritmo 01 : %f seconds\n", i+1, time_spent);
  }
  tempoMedioAlg01 = temposAlg01 / repeticoes;
  printf("Average execution time for Algoritmo 01 : %f seconds\n", tempoMedioAlg01);



    //Algoritmo 02  

  float temposAlg02=0;
  float tempoMedioAlg02=0;

  for (int i = 0; i < repeticoes; i++)
  {
    //printf("\nRun %d : Algoritmo 02\n",i+1);
    begin = clock();

    Alg02(input,inputSize, k);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    temposAlg02+=time_spent;
    //printf("Run %d: Execution time for Algoritmo 02: %f seconds\n", i+1, time_spent);
  }

  tempoMedioAlg02 = temposAlg02 / repeticoes;
  printf("Average execution time for Algoritmo 02 : %f seconds\n", tempoMedioAlg02);


  //Algoritmo 03

  float temposAlg03=0;
  float tempoMedioAlg03=0;

  for (int i = 0; i < repeticoes; i++)
  {
    //printf("\nRun %d : Algoritmo 03\n",i+1);
    begin = clock();

    Alg03(input,inputSize, k);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    temposAlg03 += time_spent;
    //printf("Run %d : Execution time for Algoritmo 03: %f seconds\n", i+1, time_spent); 
  }
  
  tempoMedioAlg03 = temposAlg03 / repeticoes;
  printf("Average execution time for Algoritmo 03 : %f seconds\n", tempoMedioAlg03);

  return;
}

