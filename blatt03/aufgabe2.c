#include <stdio.h>
#include <stdlib.h>




double arith_mtl(double* sp, int n){
	int i;
	double armtl=0;
	for(i=0;i<n;i++){
	armtl+=sp[i];
	}
	armtl=armtl/n;
	return armtl;
}

double varianz(double* sp, int n, double armtl){
	int i;
	double squarehelp;
	double var=0;
	for(i=0;i<n;i++){
		squarehelp=sp[i]-armtl;
		var+=squarehelp*squarehelp;
	}
	var=var/(n-1);
	return var;
}
int main(){
	int n;
	double* sp;
	int i;
	double armtl;
	double var;
	printf("Bitte größe der Stichprobe eingeben:");
	scanf("%i",&n);
	sp = malloc(n*sizeof(double));
	if(sp==NULL){
		return EXIT_FAILURE;
	}
	printf("Bitte die Stichprobe eingeben:\n");
	for(i=0;i<n;i++){
	printf("Wert %i von %i:", i+1, n);
	scanf("%lf", &sp[i]);
	}
	armtl=arith_mtl(sp,n);
	var=varianz(sp,n,armtl);
	printf("Arithmetisches Mittel: %f\nVarianz: %f\n",armtl,var);


	free(sp);
	return EXIT_SUCCESS;
}
