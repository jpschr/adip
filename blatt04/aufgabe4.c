#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int pyth(int n){
	int u;
	int v;
	int x,y,z;
	for(u=1;u<n;u++){
		for(v=1;v<u;v++){
			x = pow(u,2)-pow(v,2);
			y=2*u*v;
			z=pow(u,2)+pow(v,2);
			printf("%i,%i,%i ",x,y,z);
			if(pow(x,2)+pow(y,2)==pow(z,2)) printf("OK\n"); /*Check if generated numbers really satisfy the condition for pyth-triplets*/
		}
	}
	return EXIT_SUCCESS;
}


int main(){
	pyth(100);
	return EXIT_SUCCESS;
}
