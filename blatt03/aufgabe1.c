#include <stdio.h>
#include <time.h>
#include <stdlib.h>



void initializegenerator() {
	srand(time(NULL));
}
int karteziehen(){
	int zufall;
	do{
		zufall= (rand()%9)+2;
	} while(zufall<=1);
return zufall;
}
int main() {
	int dealer=0;
	int player=0;
	int input;
	initializegenerator();
	dealer+=karteziehen();
	printf("Dealer: %i\n", dealer);
	do{
		printf("Aktueller Punktestand: %i\n", player);
		printf("Karte ziehen?[0|1] ");
		scanf("%i", &input);
		switch(input){
			case 1:
				player+=karteziehen();
				if(player>21){
					printf("Aktueller Punktestand: %i\n", player);
					printf("Spieler verliert\n");
					return EXIT_SUCCESS;
				}
				if(player==21){			/* Verhalten wenn Spieler 21 trifft in Aufgabenstellung unklar */
					printf("Aktueller Punktestand: %i\n", player);
					printf("Spieler gewinnt\n");
					return EXIT_SUCCESS;
				}
				break;
			case 0:
				printf("Dealer: %i\n", dealer);
				while(dealer<=16){
					dealer+=karteziehen();
					printf("Dealer: %i\n", dealer);
				}
				if(dealer>21){
					printf("Spieler gewinnt\n");
					return EXIT_SUCCESS;
				}
				if(dealer==player){
					printf("Unentschieden\n");
					return EXIT_SUCCESS;
				}
				if(player<dealer){
					printf("Dealer gewinnt\n");
					return EXIT_SUCCESS;
				}else{
					printf("Spieler gewinnt\n");
					return EXIT_SUCCESS;
				}
				break;
			default:
				printf("ungültige Eingabe!\n");
				break;
		}
	}while(player<21);
	printf("Dealer gewinnt\n");

	return EXIT_SUCCESS;
}
