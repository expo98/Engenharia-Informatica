#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000


int main()
{

  char str[MAX_LENGTH];
  char longest[MAX_LENGTH];
  int length=0;

  FILE *F = fopen("14.1.1.txt", "r");
  if (F==NULL)
  {
    perror("Erro ao abrir ficheiro. \n");
    return 1;
  }

  while(fgets(str,MAX_LENGTH,F)!=NULL)
  {
    if(length<strlen(str))
    {
      strcpy(longest,str);
      length = strlen(str);
    }
  }

  printf("A linha mais longa tem %d caracteres de comprimento e é: %s", length,longest);


  

  fclose(F);
  return 0;
}