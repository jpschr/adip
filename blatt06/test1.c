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

    int m=0, n=0;
    int** zeilen;
    /* int* zeileneintraege; Imaginary, since in zeilen there are arrays containing the array zeileneintraege, just left it here so the upper explanation still works */
}

/*  Functions and procedures */

matrix* createMatrix(int m, int n){
    matrix fertigeMatrix;

    fertigeMatrix.m = m;
    fertigeMatrix.n = n;

    fertigeMatrix.zeilen = malloc(m * Sizeof(int*));
    for (i=0; i<m; i++){
        fertigeMatrix.zeilen[i] = malloc(n * Sizeof(int));

        for (j=0; j<n; j++){
            fertigeMatrix.zeilen[i][j] = 0;
        }
    }
}

void printMatrix(matrix* matrix_a){

}

matrix* randomizeMatrix(matrix* matrix_a){

}

matrix* matrixMultiplikation(matrix* matrix_a, matrix* matrix_b, matrix* matrix_c){

}

/* START HERE */

int main(void){
    int m=n=10;
    matrix* matrix_a, matrix_b, matrix_c;

    matrix_a = createMatrix(m, n);
    matrix_b = createMatrix(m, n);
    matrix_c = createMatrix(m, n);

    randomizeMatrix(matrix_a);
    randomizeMatrix(matrix_b);

    printf("Die Matrizen lauten:\n");
    printf("\n A: \n");
    printMatrix(matrix_a);
    printf("\n B: \n");
    printMatrix(matrix_b);
    printf("\n \n");

    if matrixmultiplikation(&matrix_a, &matrix_b, &matrix_c) {
        printf("Resultat der Multiplikation der Matrizen A und B lautet \n");
        printMatrix(&matrix_c);
    } else {
        printf("Matrizen erfuellen nicht die Bedingungen an die Matrixmultiplikation. \n");
    }



    return EXIT_SUCCESS;
}
