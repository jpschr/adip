#include <stdio.h>


int main(void){
    float numbersf[] = {10000.0, -1.0e-3/9.0, 25.0e2, 1.0e-3/7.0, -12.5e3};
    float sumf = 0;
    float sum_oldf, deltaf = 0;

    double numbersd[] = {10000.0, -1.0e-3/9.0, 25.0e2, 1.0e-3/7.0, -12.5e3};
    double sumd = 0;
    double sum_oldd, deltad = 0;

    int i,n;
    n = 5; /*Number of entries*/

    printf("Values to be summarized over:\n");
    for (i=0; i < n; i++){
        printf("numbersf[%i]: %f  \t\t\t numbersd[%i]: %f \n", i, numbersf[i], i, numbersd[i]);
    }
    printf("\n");

    printf("Computing sum using floats only... \n");
    for (i = 0; i < n; i++){
        sumf += numbersf[i];
        printf("Sum of first i = %i numbers = %f \n",i +1 ,sumf);
    }
    printf("\n");

    printf("Computing sum using doubles only... \n");
    for (i = 0; i < n; i++){
        sumd += numbersd[i];
        printf("Sum of first i = %i numbers = %f \n",i +1 ,sumd);
    }
    printf("\n");

    printf("----------------------------------------------\n\n");

    printf("Computing sum using floats and smart method... \n");
    sumf = 0;
    deltaf = 0;
    for (i = 0; i < n; i++){
        sum_oldf = sumf;
        sumf += numbersf[i];
        deltaf += numbersf[i] - (sumf - sum_oldf);
        printf("D is: %f \n", deltaf);
        sumf += deltaf;
    }
    printf("Smart sum using floats = %f", sumf);
    printf("\n\n");

    printf("Computing sum using doubles and smart method... \n");
    sumd = 0;
    deltad = 0;
    for (i = 0; i < n; i++){
        sum_oldd = sumd;
        sumd += numbersd[i];
        deltad += numbersd[i] - (sumd - sum_oldd);
        printf("D is: %f \n", deltad);
        sumd += deltad;
    }
    printf("Smart sum using doubles = %f", sumd);
    printf("\n");

    return 0;
}
