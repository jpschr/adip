#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char vorname[30];
	char nachname[30];
	int matrikelnummer;
}student;

/*Dateneingabe für neuen Student*/
void new_student(student *new_student){
	printf("Vorname: ");
	scanf("%s", new_student->vorname);
	printf("Nachname: ");
	scanf("%s", new_student->nachname);
	new_student->matrikelnummer = -1;
	while(new_student->matrikelnummer < 0){
		printf("Matrikelnummer: ");
		scanf("%i", &new_student->matrikelnummer);
	}
}

/*Ausgabe eines Studenten*/
void print_student(student *stdnt){
	int i = 0;
	
	while(stdnt->vorname[i] != '\0'){
		printf("%c", stdnt->vorname[i]);
		++i;
	}
	i = 0;
	printf(" ");
	while(stdnt->nachname[i] != '\0'){
		printf("%c", stdnt->nachname[i]);
		++i;
	}
	printf(", %i\n", stdnt->matrikelnummer);
}

/*Ausgabe aller gespeicherten Studenten*/
void print_students(student **many, int max){
	int i = 0;
	
	if(many == NULL) return;
	for(i = 0; i < max; i++){
		if(many[i] != NULL){
			many[i] = malloc(sizeof(student));
			if(many[i] == NULL) return; 
			print_student(many[i]);
		}
	}
}

/*Zurücksetzen der Liste von studenten*/
void clear_students(student **many, int max, int* num){
	int i = 0;
	
	if(many == NULL) return;
	for(i = 0; i < max; i++){
		free(many[i]);
		many[i] = NULL;
	}
	*num = 0;
}

/*Suche nach Student mit bestimmter Matrikelnummer*/
void get_name(student **many, int matrikel, int num){
	int i = 0;
	int j = 0;
	int exist = 0;
	
	if(many == NULL) return;
	for(i = 0; i < num; i++){
		if((many[i] != NULL) & (many[i]->matrikelnummer == matrikel)){
			exist = 1;
			printf("Der Student mit Matrikelnummer %i heißt: ", matrikel);
			while(many[i]->vorname[j] != '\0'){
				printf("%c", many[i]->vorname[j]);
				++j;
			}
			j = 0;
			printf(" ");
			while(many[i]->nachname[j] != '\0'){
				printf("%c", many[i]->nachname[j]);
				++j;
			}
			printf("\n");
		}
	}
	if(exist == 0){
		printf("Es gibt keinen Student mit der Matrikelnummer: %i", matrikel);
	}
}

/*Einfügen eines Studenten an eine freie Stelle*/
void add_student(student **many, int *num, int max){
	int i;
	
	if(many == NULL) return;
	if(*num == max){
		printf("Es können keine weiteren Studenten eingefügt werden.\n");
		return;
	}
	/*Hier wird nach freier Stelle gesucht, da möglicherweise die Liste nicht "ordentlich" befüllt*/
	for(i = 0; i < max; i++){
		if(many[i] == NULL){
			new_student(many[i]);
			*num += 1;
			break;
		}
	}
}

/*Falls es Student mit Matrikelnumer xy gibt, wird dieser aus liste entfernt*/
void remove_student(student **many, int max, int matrikel, int *num){
	int i;
	int exist = 0;
	
	if(many == NULL) return;
	
	for(i = 0; i < max; i++){
		if((many[i] != NULL) & (many[i]->matrikelnummer == matrikel)){
			exist = 1;
			free(many[i]);
			many[i] = NULL;
		}
	}
	
	if(exist == 0){
		printf("Es gibt keinen Student mit der Matrikelnummer: %i\n", matrikel);
	}
	else{
		*num -= 1;
	}
}

int main(){
	/*student *stdnt = NULL;
	stdnt = malloc(sizeof(student));
	new_student(stdnt);
	print_student(stdnt);
	free(stdnt)*/
	
	student ** many_students = NULL;
	int i = 0;
	int max = 2;
	int num_stu = 0;
	
	many_students = malloc(num_stu * sizeof(student *));
	if(many_students == NULL) return EXIT_FAILURE;
	
	for(i = 0; i < max; i++){
		many_students[i] = NULL;
	}
	
	add_student(many_students, &num_stu, max);
	get_name(many_students, 42, max);
	add_student(many_students, &num_stu, max);
	remove_student(many_students, max, 42, &num_stu);
	print_students(many_students, max);
	clear_students(many_students, max, &num_stu);
	print_students(many_students, max);
	
	free(many_students);
	return EXIT_SUCCESS;
}