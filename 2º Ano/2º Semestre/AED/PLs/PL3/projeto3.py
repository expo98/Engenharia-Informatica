import math
import statistics
import time
import sys
import random

sys.setrecursionlimit(10**6)

def generate_ascending_array(max_value):
    return list(range(max_value + 1))

def generate_descending_array(max_value):
    return list(range(max_value, -1, -1))

def generate_random_array(size, min_value, max_value):
    return [random.randint(min_value, max_value) for _ in range(size)]



#########################################################################################################
############################################ Insertion Sort #############################################
#########################################################################################################

def insertSort(array):

  n = len(array)

  for i in range(1,n):
    temp = array[i]
    j = i-1

    while j>=0 and array[j]>temp:
      array[j+1] = array[j]
      j= j-1
    
    array[j+1] = temp

#########################################################################################################
############################################## Heap Sort ################################################
#########################################################################################################

def heapify(array, N, i ):
  largest = i #Inicializa o maior como raiz
  left = 2*i +1
  right = 2*i +2

  # Se o left child for maior que a raiz
  # até agora
  if left < N and array[left] > array[largest]:
    largest = left
  # Se o right child for maior que a raiz
  #a até agora
  if right < N and array[right] > array[largest]:
    largest = right

  #Se o maior nao for a raiz
  if largest != i:
    array[i],array[largest] = array[largest],array[i] #Swap

    #Fazer heapify recursivamente a
    # sub-tree afectada    
    heapify(array,N, largest)

def heapSort(array):
  N = len(array)

  #Construir a maxheap
  for i in range(N//2 -1, -1, -1):
    heapify(array, N, i)

  #Extrair elementos um por um
  for i in range(N-1, 0, -1):
    array[i],array[0] = array[0],array[i] # Swap
    heapify(array, i, 0)
  

#########################################################################################################
############################################## Quick Sort ###############################################
#########################################################################################################


def quickSort(array, start, end):
  #Verifica se o indíce start é menor que o índice end
  if(start < end):
    # Obtém o pivot_location usando a função partition
    pivot_location = partition(array,start,end)
    #Chama recursivamente quickSort para a partição da direita
    quickSort(array,pivot_location+1,end)
    #Chama recursivamente quickSort para a partição da esquerda
    quickSort(array,start,pivot_location-1)
  
def partition(array, start, end):
    #inicia o índice do pivot
    i = start
    #Seleciona o elemento pivot (neste caso o valor mediano do valor inicial, central e final do array)
    pivot = array[start + (end - start) // 2]

    #Itera pelo array do start ao end-1
    for j in range(start, end):
        #Se o actual elemento é menor ou igual ao pivot
        if array[j] <= pivot:
            #Troca o elemento actual com o elemento no índice i
            array[i], array[j] =  array[j], array[i]
            #Move o índice pivot para a direita
            i += 1

    #Troca o elemento pivot com o elemento no índice i
    array[i], array[end] = array[end] ,array[i]
    
    #Devolve o índice pivot
    return i

def medianThree( a,  b,  c):
    return sorted([a, b, c])[1]

def getTimeQuickSortAscending(maxvalue):

  lista = generate_ascending_array(maxvalue)
  start_time = time.time()
  quickSort(lista,0,maxvalue)
  end_time = time.time()
  elapsed_time = end_time - start_time
  print(f'{elapsed_time},', end='' )


   
def getTimeQuickSortDescending(maxvalue):

  lista = generate_descending_array(maxvalue)
  start_time = time.time()
  quickSort(lista,0,maxvalue)
  end_time = time.time()
  elapsed_time = end_time - start_time
  print(f'{elapsed_time},', end='')



def getTimeQuickSortRandom(maxvalue):

  lista =generate_random_array(maxvalue,0,1000000)
  start_time = time.time()
  quickSort(lista,0,maxvalue)
  end_time = time.time()
  elapsed_time = end_time - start_time
  print(f'{elapsed_time},', end='')

def getTimeHeapSortAscending(maxvalue):
    array = generate_ascending_array(maxvalue)
    start_time = time.time()
    heapSort(array)
    end_time = time.time()
    elapsed_time = end_time - start_time
    print(f'{elapsed_time},', end='')

def getTimeHeapSortDescending(maxvalue):
    array = generate_descending_array(maxvalue)
    start_time = time.time()
    heapSort(array)
    end_time = time.time()
    elapsed_time = end_time - start_time
    print(f'{elapsed_time},', end='')

def getTimeHeapSortRandom(maxvalue):
    array = generate_random_array(maxvalue, 0, 1000000)
    start_time = time.time()
    heapSort(array)
    end_time = time.time()
    elapsed_time = end_time - start_time
    print(f'{elapsed_time},', end='')


def getTimeInsertSortAscending(maxvalue):
    array = generate_ascending_array(maxvalue)
    start_time = time.time()
    insertSort(array)
    end_time = time.time()
    elapsed_time = end_time - start_time
    print(f'{elapsed_time},', end='')

def getTimeInsertSortDescending(maxvalue):
    array = generate_descending_array(maxvalue)
    start_time = time.time()
    insertSort(array)
    end_time = time.time()
    elapsed_time = end_time - start_time
    print(f'{elapsed_time},', end='')

def getTimeInsertSortRandom(maxvalue):
    array = generate_random_array(maxvalue, 0, 1000000)
    start_time = time.time()
    insertSort(array)
    end_time = time.time()
    elapsed_time = end_time - start_time
    print(f'{elapsed_time},', end='')


#########################################################################################################
################################################# Main ##################################################
#########################################################################################################
def main():
  
  print("QuickSort Ascending")
  getTimeQuickSortAscending(10000)
  getTimeQuickSortAscending(20000)
  getTimeQuickSortAscending(30000)
  getTimeQuickSortAscending(40000)
  getTimeQuickSortAscending(50000)
  getTimeQuickSortAscending(60000)
  getTimeQuickSortAscending(70000)
  getTimeQuickSortAscending(80000)
  getTimeQuickSortAscending(90000)
  getTimeQuickSortAscending(100000)

  print("\n\n QuickSort Descending")

  getTimeQuickSortDescending(10000)
  getTimeQuickSortDescending(20000)
  getTimeQuickSortDescending(30000)
  getTimeQuickSortDescending(40000)
  getTimeQuickSortDescending(50000)
  getTimeQuickSortDescending(60000)
  getTimeQuickSortDescending(70000)
  getTimeQuickSortDescending(80000)
  getTimeQuickSortDescending(90000)
  getTimeQuickSortDescending(100000)

  print("\n\n")


  getTimeQuickSortRandom(10000)
  getTimeQuickSortRandom(20000)
  getTimeQuickSortRandom(30000)
  getTimeQuickSortRandom(40000)
  getTimeQuickSortRandom(50000)
  getTimeQuickSortRandom(60000)
  getTimeQuickSortRandom(70000)
  getTimeQuickSortRandom(80000)
  getTimeQuickSortRandom(90000)
  getTimeQuickSortRandom(100000)




  """
  getTimeHeapSortAscending(10000)
  getTimeHeapSortAscending(20000)
  getTimeHeapSortAscending(30000)
  getTimeHeapSortAscending(40000)
  getTimeHeapSortAscending(50000)
  getTimeHeapSortAscending(60000)
  getTimeHeapSortAscending(70000)
  getTimeHeapSortAscending(80000)
  getTimeHeapSortAscending(90000)
  getTimeHeapSortAscending(100000)

  getTimeHeapSortDescending(10000)
  getTimeHeapSortDescending(20000)
  getTimeHeapSortDescending(30000)
  getTimeHeapSortDescending(40000)
  getTimeHeapSortDescending(50000)
  getTimeHeapSortDescending(60000)
  getTimeHeapSortDescending(70000)
  getTimeHeapSortDescending(80000)
  getTimeHeapSortDescending(90000)
  getTimeHeapSortDescending(100000)
  
  getTimeHeapSortRandom(10000)
  getTimeHeapSortRandom(20000)
  getTimeHeapSortRandom(30000)
  getTimeHeapSortRandom(40000)
  getTimeHeapSortRandom(50000)
  getTimeHeapSortRandom(60000)
  getTimeHeapSortRandom(70000)
  getTimeHeapSortRandom(80000)
  getTimeHeapSortRandom(90000)
  getTimeHeapSortRandom(100000)


  getTimeInsertSortAscending(10000)
  getTimeInsertSortAscending(20000)
  getTimeInsertSortAscending(30000)
  getTimeInsertSortAscending(40000)
  getTimeInsertSortAscending(50000)
  getTimeInsertSortAscending(60000)
  getTimeInsertSortAscending(70000)
  getTimeInsertSortAscending(80000)
  getTimeInsertSortAscending(90000)
  getTimeInsertSortAscending(100000)


  getTimeInsertSortDescending(10000)
  getTimeInsertSortDescending(20000)
  getTimeInsertSortDescending(30000)
  getTimeInsertSortDescending(40000)
  getTimeInsertSortDescending(50000)
  getTimeInsertSortDescending(60000)
  getTimeInsertSortDescending(70000)
  getTimeInsertSortDescending(80000)
  getTimeInsertSortDescending(90000)
  getTimeInsertSortDescending(100000)

  getTimeInsertSortRandom(10000)
  getTimeInsertSortRandom(20000)
  getTimeInsertSortRandom(30000)
  getTimeInsertSortRandom(40000)
  getTimeInsertSortRandom(50000)
  getTimeInsertSortRandom(60000)
  getTimeInsertSortRandom(70000)
  getTimeInsertSortRandom(80000)
  getTimeInsertSortRandom(90000)
  getTimeInsertSortRandom(100000)"""


if __name__ == '__main__':
  main()