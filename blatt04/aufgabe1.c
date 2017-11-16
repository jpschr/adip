#include <stdio.h>
unsigned long long fac(int n, int k){
	int i = 0;
	unsigned long long fac = 1;
	
	if(n == 0){
		return 1;
	}
	for(i = n; i > k; i--){
		fac *= i;
	}
	return fac;
}

unsigned long long bincoef(int n, int k){

	if(n < k){
		return 0;
	}
	return (fac(n,k)/(fac(n-k, 0)));
}

unsigned long long lotto(int n, int k){
	return (bincoef(n, k) * fac(k, 0));
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
	
	return 0;
}