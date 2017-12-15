#include <stdio.h>
#include <stdlib.h>

/*  TypeDefs */

typedef struct matrix{
    /*  Zeilen ist ein Array mit Verweisen auf die jeweiligen Arrays mit den Zeileneintraegen (Elemente oder auch Eintraege unserer Matrix)
        Also korrespondiert Index von Zeilen mit dem Zeilenindex i < m (Index beginnt bei 0)
        und der Index j von Zeileneintraege respektive Zeilen[i] mit der Spaltennummer j < n (Index beginnt bei 0) eines Elements.

        Zugriff Auf das Element i,j der Matrix mit Matrix[i,j];

        m ist die Zeielenanzahl der Matrix
        n ist die Spaltenzahl der Matrix
    */

    int m;
    int n;
    int** zeilen;
    /* int* zeileneintraege; Imaginary, since in zeilen there are arrays containing the array zeileneintraege, just left it here so the upper explanation still works */
} matrix;

/*  Functions and procedures */

matrix* createMatrix(int m, int n){
    int i,j;
    matrix fertigeMatrix;

    fertigeMatrix.m = m;
    fertigeMatrix.n = n;

    fertigeMatrix.zeilen = malloc(m * sizeof(int*));
    for (i=0; i<m; i++){
        fertigeMatrix.zeilen[i] = malloc(n * sizeof(int));

        for (j=0; j<n; j++){
            fertigeMatrix.zeilen[i][j] = 0;
        }
    }

    return &fertigeMatrix;
}

void printMatrix(matrix* matrix_a){
    int i,j;

    printf("\t%i \n\n", matrix_a->m);

    for (i=0; i < matrix_a->m; i++){
        for (j=0; j < matrix_a->n; j++){
                printf("\t%i", matrix_a->zeilen[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void randomizeMatrix(matrix* matrix_a){
    int i,j;

    printf("\t%i \n\n", matrix_a->m);

    srand(time(NULL));
    for (i=0; i < matrix_a->m; i++){
        for (j=0; j < matrix_a->n; j++){
                matrix_a->zeilen[i][j] = rand() % 9;
                printf("\t%i", matrix_a->zeilen[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int matrixMultiplikation(matrix* matrix_a, matrix* matrix_b, matrix* matrix_c){
    int i,j,k;

    printf("\t%i \n\n", matrix_a->m);

    if (matrix_a->n == matrix_b->m){
        for (i=0; i < matrix_a->m; i++){
                for (j=0; j < matrix_b->n; j++){
                        for (k=0; k < matrix_a->n; k++){
                            matrix_c->zeilen[i][j] += matrix_c->zeilen[i][k] * matrix_c->zeilen[k][j];
                        }
                }
            printf("\n");
        }
        printf("\n");
        return 1;
    } else{
        return 0;
    }
}

/* START HERE */

int main(void){
    int m=2, n=2, o=2, p=2;
    matrix* matrix_a;
    matrix* matrix_b;
    matrix* matrix_c;
    /* Solche Deklarationen muessen in einzelne Zeilen bei structs, da sonst Fehler bei Zuweisungen */

    matrix_a = createMatrix(m, n);
    matrix_b = createMatrix(o, p);
    matrix_c = createMatrix(m, p);

    randomizeMatrix(matrix_a);
    randomizeMatrix(matrix_b);

    printf("Die Matrizen lauten:\n");
    printf("\n A: \n");
    printMatrix(matrix_a);
    printf("\n B: \n");
    printMatrix(matrix_b);
    printf("\n \n");

    if (matrixMultiplikation(matrix_a, matrix_b, matrix_c)) {
        printf("Resultat der Multiplikation der Matrizen A und B lautet \n");
        printMatrix(matrix_c);
    } else {
        printf("Matrizen erfuellen nicht die Bedingungen an die Matrixmultiplikation. \n");
    }


    return EXIT_SUCCESS;
}
