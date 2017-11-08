#include <stdio.h>
#include <stdlib.h>


int print_number(int n){
	int m;	
	if(n<20||n>69){ 
		printf("Die Zahl muss zwischen 20 und 69 liegen!\n");
		return EXIT_FAILURE;
	}


	m=n%10;
	switch(m){
		case 0:
			break;
		case 1:
			printf("ein-und-");
			break;
		case 2:
			printf("zwei-und-");
			break;
		case 3:
			printf("drei-und-");
			break;
		case 4:
			printf("vier-und-");
			break;
		case 5:
			printf("fünf-und-");
			break;
		case 6:
			printf("sechs-und-");
			break;
		case 7:
			printf("sieben-und-");
			break;
		case 8:
			printf("acht-und-");
			break;
		case 9:
			printf("neun-und-");
			break;
		default:
			printf("Fehler\n");
			return EXIT_FAILURE;
	}
	n=n-m;

	switch(n){
		case 20:
			printf("zwanzig\n");
			break;
		case 30:
			printf("dreißig\n");
			break;
		case 40:
			printf("vierzig\n");
			break;
		case 50:
			printf("fünfzig\n");
			break;
		case 60:
			printf("sechzig\n");
			break;
		default:
			printf("Fehler\n");
			return EXIT_FAILURE;	
	}
	return EXIT_SUCCESS;
}

int main(){
	int n;
	int i;
	printf("Bitte eine natürliche Zahl zwischen 20 und 69 eingeben:");
	scanf("%i", &n);
	print_number(n);
	
	printf("-----------TEST-------\n");
	for(i=20;i<=69;i++){
	print_number(i);
	}
	printf("----------------------\n");
	return EXIT_SUCCESS;
}
