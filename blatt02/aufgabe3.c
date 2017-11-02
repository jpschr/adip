#include <stdio.h>

int factorsum(int n){
	int sum=0;
	for(int i=1;i<n;i++){
		if(n%i==0) sum+=i;
	}
return sum;
}

int n_perfect(int n){
	if(n==0) return 0;
	if(n==factorsum(n)){
	
	//printf("%i ist perfekt\n", n);
	return 1;
	}
return 0;
}

int n_deficient(int n){
	if(n>factorsum(n)){
	
	//printf("%i ist deficient\n",n);
	return 1;
	}
return 0;
}
int print_smaller_perfects(int n){
printf("-----------------------------------\n");
printf("Diese perfekten Zahlen sind kleiner als %i\n", n);
for(int i=0;i<n;i++){
	if(n_perfect(i)) printf("%i\n",i);
}
printf("-----------------------------------\n");
return 0;
}

int count_smaller_deficients(int n){
int count=0;
for(int i=1; i<n;i++){
	if(n_deficient(i)) count++;
}
return count;
}

int main(){
int n=0;
printf("Bitte eine natürliche Zahl eingben: ");
scanf("%i",&n);
if(n_perfect(n)){ 
	printf("%i ist perfekt\n", n);
}else{
	printf("%i ist nicht perfekt\n",n);
}
if(n_deficient(n)){
	printf("%i ist deficient\n",n);
}else{
	printf("%i ist nicht deficient\n",n);
}
print_smaller_perfects(n);
printf("%i defiziente Zahlen sind kleiner als n\n",count_smaller_deficients(n));
	
return 0;
}
