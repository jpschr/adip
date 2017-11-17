#include <stdio.h>
#include <stdlib.h>

/*Folgende Funktionen laufen nur auf positiven Zahlen und n >= k, wofür die main und vorrausgehende Funktionen sorgen.*/
/*In einer Bibliothek sollte man dies aber intern herausfiltern*/

unsigned long fac(int n){

	int i = 0;
	unsigned long fac = 1;
	
	if(n < 0){        /*Fall tritt nie auf*/
		return -1;
	}
	
	if(n == 0){
		return 1;
	}

	for(i = 1; i <= n; i++){
		fac *= i;
	}
	
	return fac;
}

unsigned long fac2(int n, int k){

	int i = 0;
	unsigned long fac = 1;

	if(n == 0){
		return 1;
	}

	for(i = n; i > k; i--){
		fac *= i;
	}
	
	return fac;
}



unsigned long bincoef(int n, int k){

	if(n < k){
		return 0;
	}
	
	return (fac2(n,k)/(fac(n-k)));
}


unsigned long lotto(int n, int k){
  
	return (bincoef(n, k) * fac(k));    
}


int main(){

	int n = -1,k = -1;

	while(n < 0){
		printf("Bitte geben sie eine natürliche Zahl ein: \n");
		scanf("%i" , &n);
	}

	while((k < 0)){
		printf("Bitte geben sie eine natürliche Zahl ein: \n");
		scanf("%i" , &k);
	}
	printf("Der Binomialkoeffizient ist: %llu\n", bincoef(n,k));
	printf("modifiziertes Lottoproblem : %llu\n", lotto(n, k));

	return EXIT_SUCCESS;
	
}
