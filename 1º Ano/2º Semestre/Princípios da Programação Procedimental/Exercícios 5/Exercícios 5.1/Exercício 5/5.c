#include <stdio.h>

int calc_primos(int nEl, int lastNumber);

int main(){

    int nEl=0;
    
    printf("Quantos números primos quer?\n");
    scanf("%d",&nEl);

    int primos[nEl];

    primos[0]=2;

    for(int i=1; i<nEl;i++){
        primos[i]= calc_primos(nEl,primos[i-1]);
    }

    printf("Os número primos são ");
    for(int i=0; i<nEl;i++){
        printf("%d",primos[i]);
    }
    return 0;
}

int calc_primos(int nEl,int lastNumber){
    int is_prime=3;
    int not_prime=1;


    for(int j= lastNumber; j<nEl;j++){
        
        do{
            for(int k = 3; k<j;k++){
                if (is_prime%k){
                    not_prime=1;
                  }
                else {
                    not_prime=0;
                    return is_prime;
                }
                is_prime++;
            }         
        }while (not_prime==1);
        not_prime=1;
    }

}