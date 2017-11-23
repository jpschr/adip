#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct DynArray{
int* array;
int elements;
int max_size;
};

struct DynArrayMin{
int* array;
int size;
};

int dyn_array_add(struct DynArray* dynarray, int new_elem){
	int* n_array=NULL;
	if(dynarray->elements<dynarray->max_size){
		dynarray->array[dynarray->elements]=new_elem;
		dynarray->elements++;
	}
	else{						
		n_array=malloc(2*dynarray->max_size*sizeof(int));
		if(NULL==n_array){
			return 0;
		}else{

			memcpy(n_array,dynarray->array, dynarray->max_size*sizeof(int));
			free(dynarray->array);
			dynarray->array=n_array;
			dynarray->max_size*=2;
			dyn_array_add(dynarray, new_elem);
		}
	}
	return 1;
}

int dyn_array_min_add(struct DynArrayMin* dynarraymin, int new_elem){
	int* n_array=NULL;
	n_array=malloc((dynarraymin->size+1)*sizeof(int));
	if(NULL==n_array){
		return 0;
	}else{
		memcpy(n_array,dynarraymin->array, dynarraymin->size*sizeof(int));
		free(dynarraymin->array);
		dynarraymin->array=n_array;
		dynarraymin->array[dynarraymin->size]=new_elem;
		dynarraymin->size++;
	}
	return 1;
}

void dyn_array_print(struct DynArray* dynarray){
	int i;
	printf("[");
	for(i=0;i<dynarray->elements;i++){
		printf("%i, ",dynarray->array[i]);
	}
	printf("]i\n");
}

void dyn_array_print_full(struct DynArray* dynarray){
	int i;
	printf("[");
	for(i=0;i<dynarray->elements;i++){
		printf("%i, ",dynarray->array[i]);
	}
	if(dynarray->elements<dynarray->max_size){
		printf("|");
		for(i=dynarray->elements;i<dynarray->max_size;i++){
			printf("%i, ",dynarray->array[i]);
		}
	}
	printf("]\n");
}

void dyn_array_min_print(struct DynArrayMin* dynarraymin){
	int i;
	printf("[");
	for(i=0;i<dynarraymin->size;i++){	
		printf("%i, ",dynarraymin->array[i]);	
	}
	printf("]\n");
}


void initializegenerator() {
        srand(time(NULL));
}




int main(){
	struct DynArray dynarray;
	struct DynArrayMin dynarraymin;
	int i;
	int test_size=10;
	/* initialize dynarray */
	dynarray.max_size=1;
	dynarray.elements=0;
	dynarray.array=malloc(dynarray.max_size*sizeof(int));
	if(NULL==dynarray.array) return EXIT_FAILURE;
	/* initialize dynarraymin */
	/*dynarraymin.size=1;
	dynarraymin.array=malloc(dynarraymin.size*sizeof(int));
	if(NULL==dynarraymin.array) return EXIT_FAILURE;
	dynarraymin.array[0]=rand()%100;*/
	dynarraymin.size=0;
	dynarraymin.array=NULL;
	printf("Test von DynArray\n");
	for(i=0;i<test_size;i++){
		dyn_array_add(&dynarray,rand()%100);
		dyn_array_print_full(&dynarray);
	}
	printf("Test von DynArrayMin\n");
	dyn_array_min_print(&dynarraymin);
	for(i=0;i<test_size;i++){
		dyn_array_min_add(&dynarraymin, rand()%100);
		dyn_array_min_print(&dynarraymin);
	}
	return EXIT_SUCCESS;
}

/* Im Vergleich zu DynArrayMin muss das Array bei DynArray deutlich seltener vergrößert werden, die Laufzeit ist also besser. DynArray reserviert dafür mehr Speicher als benötigt wird, bis zu ca. doppelt so viel wie benötigt. */
