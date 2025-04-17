/*
8.1.1
8.2.1
8.2.2
*/


/*print Fharenheit-Celsius table; version with if*/
#include <stdio.h>

int main(){
    float fahr, celsius;
    int lower, upper, step;

    float *p_celsius, *p_fahr;
    int *p_upper, *p_step;

    p_fahr = &fahr;
    p_celsius = &celsius;
    p_upper = &upper;
    p_step= &step;

    lower =0;
    upper=300;
    step=20;

    fahr=lower;
    while(1){
        *p_celsius = (5.0/9.0) * (*p_fahr-32);
        printf("%3.0f %6.1f\n", *p_fahr, *p_celsius);
        *p_celsius += *p_step;
        if (*p_fahr > *p_upper) break;  
    }
    return 0;
}