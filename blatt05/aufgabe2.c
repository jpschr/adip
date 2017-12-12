#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct DynArray{
	int* array;
	unsigned elements;
	unsigned max_size;
}DynArray;

/* array=NULL, elements=0, max_size=0 is the empty DynArray
 * array=NULL allowed only if max_size=0
 * elements<=max_size
 * array has size of max_size */

typedef struct DynArrayMin{
	int* array;
	unsigned size;
}DynArrayMin;

int dyn_array_add(DynArray* dynarray, int new_elem){
	int* n_array=NULL;
	/* sanity checks on dynarray */
	if(NULL==dynarray) return 0;
	if((NULL==dynarray->array)&&(0!=dynarray->max_size)) return 0;
	if(dynarray->max_size<dynarray->elements) return 0;

	if(dynarray->elements<dynarray->max_size){
		dynarray->array[dynarray->elements]=new_elem;
		dynarray->elements++;
	}
	else{
		n_array=malloc(((dynarray->max_size>0)?(2*dynarray->max_size):(1))* sizeof(int)); /* condition ? condition_is_true_expression : condition_is_false_expression */
		if(NULL==n_array) return 0;
		if(NULL!=dynarray->array){ /* TODO how to negate ==NULL? */
			memcpy(n_array,dynarray->array, dynarray->max_size*sizeof(int));
			free(dynarray->array);
		}
		dynarray->array=n_array;
		dynarray->max_size=(dynarray->max_size>0)?(2*dynarray->max_size):(1);
		dyn_array_add(dynarray, new_elem);
	}
	return 1;
}

int dyn_array_min_add(DynArrayMin* dynarraymin, int new_elem){
	int* n_array=NULL;
	/* sanity checks */
	if(NULL==dynarraymin) return 0;
	if(NULL==dynarraymin->array&&0!=dynarraymin->size) return 0;

	n_array=malloc((dynarraymin->size+1)*sizeof(int));
	if(NULL==n_array) return 0;
	if(NULL!=dynarraymin->array){
		memcpy(n_array,dynarraymin->array, dynarraymin->size*sizeof(int));
		free(dynarraymin->array);
	}
	dynarraymin->array=n_array;
	dynarraymin->array[dynarraymin->size]=new_elem;
	dynarraymin->size++;
	return 1;
}

void dyn_array_print(DynArray* dynarray){
	int i;
	printf("[");
	for(i=0;i<dynarray->elements;i++){
		printf("%i, ",dynarray->array[i]);
	}
	printf("]i\n");
}

void dyn_array_print_full(DynArray* dynarray){
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

void dyn_array_min_print(DynArrayMin* dynarraymin){
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
	DynArray dynarray;
	DynArrayMin dynarraymin;
	int i;
	int test_size=10;
	/* initialize dynarray */
	dynarray.max_size=0;
	dynarray.elements=0;
	dynarray.array=NULL;
	/* initialize dynarraymin */
	dynarraymin.size=0;
	dynarraymin.array=NULL;
	printf("Test von DynArray\n");
	dyn_array_print_full(&dynarray);
	initializegenerator();
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
