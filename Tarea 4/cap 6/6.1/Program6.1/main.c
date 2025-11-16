#include <stdio.h>


/* Diagonal principal.

El programa, al recibir como dato una matriz de tipo entero, escribe la diagonal principal. */


#define TAM 10
void  Lectura(int [][TAM], int ); /* Prototipo de funciones. */
void Imprime(int [][TAM], int);

int main(void)

{
    int MAT[TAM][TAM];
    Lectura(MAT, TAM);
    Imprime(MAT, TAM);
    return 0;

}

void Lectura(int A[][TAM], int F)
/* La funcion lectura se utiliza para leer un arreglo bidimensional. */

{
    int I, J;
    for (I = 0; I < F; I++)
        for (J = 0; J < F;  J++)
    {
        printf("Ingrese el elemento %d %d: ", I + 1, J + 1);
        scanf ("%d", &A[I][J]);
    }
}



void Imprime(int A[][TAM], int F)
/* La funcion Imprime se utiliza para escribir la diagonal principal
de una matriz cuadrada de F filas y columnas. */

{
    int I,J;
    for (I = 0; I < F; I++)
        for (J = 0; J < F; J++)
        if (I == J)
        printf("\Diagonal %d %d: %d", I, J, A [I][J]);

}




