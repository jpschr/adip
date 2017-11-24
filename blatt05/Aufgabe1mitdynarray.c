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

char* encrypt(char*s, int k){
    int i,size;
    for(size=0;!(s[size] == '\0');size++);

    for(i=0;i<=size;i++){
        if(s[i]>64 && s[i]<91){
            s[i] = (65+((s[i]+k-65)%26));
        }
        if(s[i]>96 && s[i]<123){
            s[i] = (97+((s[i]+k-97)%26));
        }
    }
    return s;
}

char* decrypt(char*a, int k){
    return encrypt(a, 26-(k%26));

}



void falschrum(char * string){
	int i,size;
	printf("Richtig: \n");
	for( size=0 ; !(string[size] == '\0') ;size++ ){
		printf("%c", string[size]);
	}
	printf("\n\n");
	printf("\nGedreht: \n");
	for (i=size;i>=0;i--){
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
	char* string;
	int key, limit = 100;

	string = malloc(limit*sizeof(char));
	if(string==NULL){

		return EXIT_FAILURE;

	}

    fillstring(string, 0);
    printf("String: ");
	printstring(string);
	printf("\n");


	printf("\nGib ein Wort ein:\n");
	scanf( "%99s" , string); /* stop weading from stdin after limit-1 characters so that string + terminating '\0' Byte fits into char array*/
	printf("\nGib einen Schlüssel ein:\n");
	scanf( "%i" , &key);




	falschrum(string);
	if(palindrom(string)){
            printf("Die Eingabe ist ein Palindrom.\n\n");
	}
	else printf("Die Eingabe ist kein Palindrom.\n\n");
	printf("String verschlüsselt:\n");
	printstring(encrypt(string, key));
	printf("String entschlüsselt:\n");
    printstring(decrypt(string, key));

    free(string);


	return EXIT_SUCCESS;

}
/*Testinstanz: "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz123,.;:%@"*/
