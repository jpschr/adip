#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void){
    int limits[2] = {10,10};
    int i = 1, j = 1;
    int product = 1;

    for (i=1; i <= limits[0]; i++){
        for (j=1; j <= limits[1]; j++){
            product = i * j;
            printf("%i * %i = %i \t", i, j, product);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}
