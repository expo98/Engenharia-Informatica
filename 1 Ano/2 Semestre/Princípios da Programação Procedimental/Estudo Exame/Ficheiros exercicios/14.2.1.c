#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

#define str_len 100

int main()
{
  FILE *W = fopen("14.2.1.txt","w");

  for (size_t i = 0; i < 5; i++)
  {
    printf("Introduza uma string: \n");
    fscanf(W,"%s\n");
  }
  fclose(W);

  FILE *R = fopen("14.2.1.txt","r");
  char string_maior[str_len] = "";

  while(fgets("%s",str_len,R) != NULL)
  {
    if (strlen(string_maior)< strlen(fgets("%s",str_len,R)))
    {
      strcpy(string_maior,fgets("%s",str_len,R));
    }
  }

  printf("A string maior é: %s",string_maior);
  fclose(R);

  return 0;
}
