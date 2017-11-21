#include <stdio.h>
#include <stdlib.h>

int succ(int x) {
	return ++x;
}
int pre(int x) {
	return --x;
}

int add(int x, int y){
	if(y==0){
		return x;
	}
	if(y>0){
		return add(succ(x),pre(y));
	}
	if(y<0){
		return add(pre(x),succ(y));
	}
	return -1000; 
}

int sub(int x, int y){
	if(y==0){
		return x;
	}else{
		return sub(pre(x),pre(y));
	}
}

int mult(int x, int y){
	if(y==0) return 0;
	if(y==1){
		return x;
	}else{
		return add(x,mult(x,pre(y)));
	}
}

int test(int x, int y){
	printf("Testcase: (%i,%i)\n", x, y);
	printf("add(%i,%i)=%i\n",x,y,add(x,y));
	printf("sub(%i,%i)=%i\n",x,y,sub(x,y));
	printf("mult(%i,%i)=%i\n",x,y,mult(x,y));
	return EXIT_SUCCESS;
		}

int main(){
	test(2,0);
	test(-3,2);
	return EXIT_SUCCESS;
}
