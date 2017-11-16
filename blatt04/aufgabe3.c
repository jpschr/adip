#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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



double sinus (double x){
	int n;
	double result=0;
	for(n=0;n<6;n++){
		result+=pow(-1,n)*(pow(x,2*n+1)/fac(2*n+1));
	}
	return result;
}

double cosinus (double x){
	int n;
	double result=0;
	for(n=0;n<6;n++){
		result+=pow(-1,n)*(pow(x,2*n)/fac(2*n));
	}
	return result;
}

double expf (double x){
	int n;
	double result=0;
	for(n=0;n<11;n++){
		result+=pow(x,n)/fac(n);
	}
	return result;
}

int main(){
	double input=0;
	scanf("%lf",&input);
	printf("our    sinus %f\n", sinus(input));
	printf("math.h sinus %f\n", sin(input));
	printf("our    cosinus %f\n", cosinus(input));
	printf("math.h cosinus %f\n", cos(input));
	printf("our    exp %f\n", expf(input));
	printf("math.h exp %f\n", exp(input));
	return EXIT_SUCCESS;
}




