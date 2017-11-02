#include <stdio.h>;
#include <stdlib.h>

double exp_rec_2(double a, int n){
if(n==0) return 1.;
if(n%2==0){
    return exp_rec_2(a,n/2)*exp_rec_2(a,n/2);
}
else{
    return a * exp_rec_2(a,(n-1)/2) * exp_rec_2(a,(n-1)/2);
}


}
double exp_rec(double a, int n){
    if (n == 1){ return a;}
        else{ return a * exp_rec(a, n-1);}

}

int main(void){
    double result1, result2, a;
    int n = 1;


    printf("Bitte a (Basis) eingeben\n");
    scanf("%lf", &a); //Man muss hier richtig formattiert einlesen als lf ==> long float, da wir oben double angegeben haben. Mit f wird nur 0 eingelesen
    printf("\n");

    printf("Bitte n (Exp.) eingeben\n");
    scanf("%i", &n);
    printf("\n");

    result1 = exp_rec(a,n);
    printf("Das Ergebnis von %f \^ %i lautet via langsame Berechnung: %f\n", a, n, result1);
    result2 = exp_rec_2(a,n);
    printf("Das Ergebnis von %f \^ %i lautet via schnelle Berechnung: %f\n", a, n, result2);

    return EXIT_SUCCESS;
}
