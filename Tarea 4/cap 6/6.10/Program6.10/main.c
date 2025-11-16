#include <stdio.h>

/* Cuadrado magico.
El programa genera un cuadrado magico siguiendo los criterios
enunciados. */

#define MAX 50

void Cuadrado(int [][MAX], int);
void Imprime(int [][MAX], int);

int main(void)
{
    int CMA[MAX][MAX], TAM;

    do {
        printf("Ingrese el tamaño impar de la matriz: ");
        scanf("%d", &TAM);

    }while (TAM > MAX || TAM < 1 || (TAM % 2 == 0)); /* Debe ser 1..MAX e impar */

    Cuadrado(CMA, TAM);
    Imprime(CMA, TAM);

    return 0;
}

void Cuadrado(int A[][MAX], int N)
/* Forma el cuadrado magico por el metodo siames. */
{
    int I = 1, FIL = 0, COL = N/ 2, NUM = N * N;

    while(I <= NUM) {
        A[FIL][COL] = I;
        if (I % N != 0){
            FIL = (FIL - 1 + N) % N; /* Subir una fila (con wrap) */
            COL = (COL + 1)% N;   /* Avanzar una columna (con wrap) */

        } else {
            FIL = (FIL + 1) %N; /* Bajar una fila */
        }
        I++;
        }
    }


void Imprime(int A[][MAX], int N)
/* Escribe el cuadrado magico. */
{

    int I, J;
    for (I = 0; I < N; I++)
        for (J = 0; J < N; J++)
            printf("Elemento %d %d: %d\n", I+1, J+1, A[I][J]);

}



