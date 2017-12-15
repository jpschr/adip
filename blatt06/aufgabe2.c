#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nachname[30];
    float note;
} student;

student einlesen(int i){
    student tim;
    printf("Bitte den Nachnamen des %iten Studenten eingeben: ", i);
    scanf("%s", tim.nachname);
    printf("Nun bitte Note für %s eingeben: \n", tim.nachname);
    scanf("%f", &tim.note);
    if(tim.note>5.0 || tim.note<1.0){
        printf("Bitte Note zwischen 1.0 und 5.0 eingeben: ");
        scanf("%f", &tim.note);
    }
    return tim;
}

int main(){

	student* menschen;
	int* top;
	int key, n = 0, i, j;
	float min=6.0, durchschnitt = 0.0;

    printf("Wie viele Studenten werden betrachtet?\n");
    scanf("%i", &n);
    while(n<1){
        printf("Bitte positiven Wert angeben!\n");
        scanf("%i", &n);
    }

    menschen = malloc(n*sizeof(student));
    top = malloc(n*sizeof(int));

	if(menschen==NULL){
        printf("Fehler beim Allokieren.\n");
		return EXIT_FAILURE;
	}

    for(i = 0; i<n; i++){
        menschen[i]=einlesen(i+1);
        /*printf("%s: %f\n", menschen[i].nachname, menschen[i].note);*/
        durchschnitt += menschen[i].note;
        if(menschen[i].note==min){
            j++;
            top[j]=i;
        }
        if(menschen[i].note<min){
            j=0;
            top[0]=i;
            min = menschen[i].note;
        }
    }

    printf("Beste Noten:\n");
    for(i=0;i<=j;i++){
        printf("%s: %f\n", menschen[top[i]].nachname, menschen[top[i]].note);
    }
    printf("Es wurde ein Durchschnitt von %f erreicht.\n", durchschnitt/n);

    free(menschen);
    free(top);
	return EXIT_SUCCESS;
}
