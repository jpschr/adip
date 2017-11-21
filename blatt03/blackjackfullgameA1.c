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

int gamestart(){       /*gibt 1 bei Sieg, -1 bei Niederlage und 0 bei unentscieden zurück*/
	int dealer=0;
	int player=0;
	int input;
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
					return -1;
				}
				if(player==21){			/* Verhalten wenn Spieler 21 trifft in Aufgabenstellung unklar */
					printf("Aktueller Punktestand: %i\n", player);
					printf("Spieler gewinnt\n");
					return 1;
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
					return 1;
				}
				if(dealer==player){
					printf("Unentschieden\n");
					return 0;
				}
				if(player<dealer){
					printf("Dealer gewinnt\n");
					return -1;
				}else{
					printf("Spieler gewinnt\n");
					return 1;
				}
				break;
			default:

				printf("ungültige Eingabe!\n");
				break;
		}
	}while(player<21);
	printf("Dealer gewinnt\n");
	return -1;
}

int again(int bilanz){            /*gibt nebenbei Anzahl der Gesamtrunden zurück*/
    int input;
    int runden = 1;
    do{
		printf("\n\n");
		printf("Neue Runde starten?[0|1] ");
		scanf("%i", &input);
		switch(input){
			case 1:

				bilanz += gamestart();
				runden ++;
				break;
			case 0:

				printf("Spiel beendet.\n");
				return runden;
				break;      /*Kompiler bestand auf as break hier, warum? Es  wird doch eh nie erreicht?*/
			default:

				printf("ungültige Eingabe! Spiel beendet.\n");
                		return runden;
				break;
		}
	}while(bilanz>-5);          /*keine weiteren Runden wenn Bilanz zu schlecht ist*/
    printf("Vermutlich solltest du aufhören.\n");
	return runden;
}

int main() {
    int bilanz;
    initializegenerator();
    printf("BLACKJACK START\n");
    bilanz = gamestart();
    again(bilanz);               /*kann aus dem Code entfernt werden, dadurch wird das Spiel nach der ersten Runde beendet*/
    return EXIT_SUCCESS;
}
