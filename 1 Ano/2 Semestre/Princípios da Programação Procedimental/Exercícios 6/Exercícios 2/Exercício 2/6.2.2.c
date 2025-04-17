#include <stdio.h>
#include <string.h>

#define MAX 100
//char compress_string(int array_og[MAX], int sequence_size );

int main(){
    int array_og[MAX];
    int sequence_size=0;
    int same_digit_array[MAX];

 //   int digit_array_size;
 //   int digit_array[MAX];

 //   char array_string_og[MAX];
    char array_string_compressed[MAX];



    printf("Introduza o comprimento da sequência de números:\n");
    scanf("%d", &sequence_size);
    
    
    for (int i = 1; i <= sequence_size; i++)
    {
        printf("Introduza o %dº numero da sequência:\n",i);
        scanf("%d",&array_og[i]); 
    }
/*
     for (int i = 1; i <= sequence_size; i++)
    {
       printf("%d",array_og[i]);
    }
    
    for (int i = 0; i < sequence_size; i++)
    {
        array_string_og[i] = '0' + array_og[i];
    }
*/
    ///////printf("%s",compress_string(digit_array, sequence_size));

    int same_digit=1;
    int j=0;

    for (int i = 1; i < sequence_size; i++)
    {
        if (array_og[i] == array_og[i-1])
        {
            same_digit++;

        }

        if (array_og[i] != array_og[i-1])
        {
            if (same_digit>=4)
            {
                array_string_compressed[j]= 'c';
                j++;
                array_string_compressed[j]= '0' + array_og[i-1];
                j++;
                
              /*while (fim !=0)
               {
                array_string_compressed[j] = '0' + same_digit%10;
                same_digit= same_digit/10;
                j++;
                if (same_digit/10==0){
                    array_string_compressed[j] = '0' +same_digit%10;
                    j++;
                    fim =0;
                }
               }*/


                int l=0;
                int same_digit_length=0;

               while (same_digit != 0)
                {
                  same_digit_array[l] = (same_digit % 10);
                  same_digit_length++;
                  l++;
                  same_digit /= 10;
                }

                for (int m = same_digit_length-1; m >=0; m--)
                {
                    array_string_compressed[j]= '0' + same_digit_array[m];
                    j++;
                }
                

//12355555555555542
                array_string_compressed[j] = 'f';
                j++;
                same_digit=1;
            }

            else if (same_digit ==1)
            {
                array_string_compressed[j] = '0' + array_og[i-1];
                j++;

            }
            else if (same_digit <4)
            {
                //adicionar same digits vezes array_og[i-1]
                for (int k = 1; k < same_digit; k++)
                {
                    array_string_compressed[j] = '0' + array_og[i-1];
                    j++;
                }
                
            same_digit=1;
            }
            
            
            
        }
        
        
    }
    j++;
    array_string_compressed[j] = '\0';
    puts(array_string_compressed);

    ////////////////////////////////////////////////////////////

    return 0;
}

