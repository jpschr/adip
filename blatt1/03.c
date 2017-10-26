#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primetest(int n){
    int i = 2;
    int nroot = (sqrt(n));

    while (i <= nroot){
            if (n % i == 0) return 0;
            i++;
    }
    return 1;



}

int main(void){
    int n = -1, loopcount = 1;

    do{
        if (loopcount > 1) printf("\n ERROR: This was no positive natural number.\n\n");
        else loopcount++;
        printf("Enter a positive natural number: \n");
        scanf("%i", &n);
        printf("\n");
    }
    while (n<0);
    printf("Thank you!\n");

    printf("\n Computing...\n\n");
    if (primetest(n)) printf("%i is a prime. \n", n);
    else printf("%i is no prime.\n", n);

    return EXIT_SUCCESS;
}
