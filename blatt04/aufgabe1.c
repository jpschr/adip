#include <stdio.h>
#include <stdlib.h>

int fac(int n){
	int i;
	int fac=1;
	if(n<0) return -1;
	if(n==0) return 1;
	for(i=1;i<=n;i++){
		fac*=i;
	}
	return fac;
}

int n_over_k(int n, int k){
	if(n<0||k<0) return -1;
	if(n<k) return 0;
	return fac(n)/(fac(n-k)*fac(k));
}

int test_fac(){
	int n;
	int nfac;
	printf("Bitte eine nichtnegative ganze Zahl n eingeben:");
	scanf("%i", &n);
	nfac=fac(n);
	if(nfac==-1){
		printf("Die Zahl muss nichtnegativ sein!\n");
		return 0;
	}
	printf("%i!=%i\n",n, nfac);
	return 0;
}

int test_n_over_k(){
	int n,k;
	int nok;
	printf("Bitte n>=0 eingeben:");
	scanf("%i", &n);
	printf("Bitte k>=0 eingeben:");
	scanf("%i", &k);
	nok=n_over_k(n,k);
	if(nok==-1){
		printf("Eingabe unzulässig!\n");
		return EXIT_FAILURE;
	}
	printf("n über k ist %i\n", nok);
	return EXIT_SUCCESS;
}

int lotto(int n, int k){
	int nok;
	nok=n_over_k(n,k);
	if(nok==-1){ /*n_over_k checks if n and k are not-negative*/
		return -1;
	}	
	return n_over_k(n,k)*fac(k);

}

int test_lotto(){
	int n,k;
	int lot;
	printf("Bitte n>=0 eingeben:");
	scanf("%i", &n);
	printf("Bitte k>=0 eingeben:");
	scanf("%i", &k);
	/*if(n<0||k<0){
		printf("Eingabe unzulässig!");
		return EXIT_FAILURE;
	}*/
	lot=lotto(n,k);
	if(lot==-1){
		printf("Fehler!");
		return EXIT_FAILURE;
	}
	printf("lotto= %i\n", lot);
	return EXIT_SUCCESS;

}

int main(){
	test_fac();
	test_n_over_k();
	test_lotto();
	return EXIT_SUCCESS;
}

