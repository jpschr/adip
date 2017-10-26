#include <stdio.h>
#include <stdlib.h>

int main(){
int n;
printf("Bitte eine ganze Zahl größer 1 eingeben:"); 
scanf("%i", &n);
if(n<=1) printf("Diese Zahl ist nicht größer als 1\n");
int* A = malloc(sizeof(int)*n+1);
if(A==NULL) return -1;
for(int i=0;i<n+1;i++) A[i]=0;

int m = n;

for(int i=2;i<n+1;i++){
	while(n % i==0){ 
		A[i]++;
		n=n/i;
	}
}

for(int i=2;i<m+1;i++){
	if(A[i]!=0) printf("%i ^ %i\n", i, A[i]);
}

return 0;
}
