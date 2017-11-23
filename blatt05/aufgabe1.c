#include <stdio.h>
#include <stdlib.h>

void fillstring(char * s, char n){
	int size, i;
    for(size=0;!(s[size]=='\0');size++);
	for (i = 0; i<size; i++){
		s[i] = n;
	}
}

void printstring(char * s){
	int size, i;
    for(size=0;!(s[size]=='\0');size++);
	for (i = 0; i<size; i++){
		printf("%c", s[i]);
	}
	printf("\n");
}


void falschrum(char * string){
	int i;
	printf("Richtig: \n");
	for( i=0 ; !(string[i] == '\0') ;i++ ){
		printf("%c", string[i]);
	}
	printf("\n\n");
	printf("\nGedreht: \n");
	for (i;i>=0;i--){
		printf("%c", string[i]);
	}
	printf("\n\n");
}
int palindrom(char * string){
	int size,i;
	for( size=0 ; !(string[size] == '\0') ;size++ );


	for (i=0;i<(size/2);i++){
		if(!(string[i] == string[size-1-i])){
			return 0;
		}
	}
	return 1;
}

int main(){
	char string[200];

	fillstring(string, 0);


	printstring(string);


	printf("\nGib ein Wort ein:\n");
	scanf( "%s" , string);


	falschrum(string);
	if(palindrom(string))	printf("Die Eingabe ist ein Palindrom.\n");
	else printf("Die Eingabe ist kein Palindrom.\n");


	return EXIT_SUCCESS;
}
