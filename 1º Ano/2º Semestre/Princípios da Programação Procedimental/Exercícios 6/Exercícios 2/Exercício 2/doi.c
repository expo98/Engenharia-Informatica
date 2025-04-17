#include <stdio.h>

int main(){
    int same_digit= 123;
    int fim=1;
    
    do
        {
        printf("%d\n",same_digit%10);
        same_digit = same_digit/10;
        //printf("%d\n", same_digit);

        if (same_digit/10 ==0)
        {
            printf("%d\n",same_digit%10);
            fim =0;
        }
        
     }
    
    while (fim !=0);

    
    

    return 0;
}