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
			printf("%i,%i,%i\n",x,y,z);
			/*printf("%i^2+%i^2=%f+%f=%f\n", a, b, pow(a,2), pow(b,2), pow(a,2)+pow(b,2));*/
		}
	}
	return EXIT_SUCCESS;
}


int main(){
	pyth(20);
	return EXIT_SUCCESS;
}
