#include <stdio.h>

int main(){
    int num;

    printf("Introduza um número:\n");
    scanf("%d",&num);

   if(num%2==0){
    printf("O número é par!\n");
   }
   else{
    printf("O número é ímpar!\n");
   }

   return 0;
}