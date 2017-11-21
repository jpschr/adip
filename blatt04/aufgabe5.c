#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initializegenerator() {
	srand(time(NULL));
}


int main() {

    int preis = 1;
    int bezahlt = 0;
    int dif = 0;
    int limit = 0;

    initializegenerator();
    printf("Bitte gib eine sinnvolle Preisgrenze an, sodass du mit den Zahlen noch gut rechnen kannst:\n");     /*Sonst gibt rand() oft unhandlich große Zahlen zurück*/
    scanf("%i", &limit);
    while(limit<=0){
      printf("Fehler, bitte positive Zahl eingeben\n");
      scanf("%i", &limit);
    }
    preis = rand()%limit;
    while(bezahlt <= preis){
      printf("Bitte einen ganzzahligen Betrag größer %i eingeben:\n", preis);
      scanf("%i", &bezahlt);
    }
    
    printf("Bezahlt:%i\n", bezahlt);
    dif = bezahlt -preis;
    printf("%i wird in %i Fünfzigern, %i Zwanzigern, %i Zehnern, %i Fünfern, %i Zweiern und %i Einern zurückgegeben.\n", dif, dif/50, (dif%50)/20,(dif%20)/10,(dif%10)/5,(dif%5)/2,(dif%2));

    return EXIT_SUCCESS;

}
