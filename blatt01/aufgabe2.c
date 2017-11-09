#include <stdio.h>
#include <math.h>



int main(){
printf("Bitte eine ganze Zahl größer Null eingeben:");
int n;
scanf("%i", &n);
if(n<=0){ 
	printf("Die Zahl muss größer Null sein!\n");
	return 1;
}
int sum1=0;
for(int i=1;i<=n;i++){
	sum1+=i;
}
int sum2=0;
for(int i=1;i*i<=n;i++){
sum2+=i*i;
}
printf("Summe aller Zahlen bis %i: %i\n",n, sum1);
printf("Summe der Quadratzahlen bis %i: %i\n",n, sum2);


return 0;
}
