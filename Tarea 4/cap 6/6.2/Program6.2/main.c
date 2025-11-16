#include <stdio.h>

/* Suma de matrices.
El programa, al recibir como datos dos arreglos bidimensionales del mismo tamaño,
calcula la suma de ambos y almacena en un tercer arreglo bidimensiional */

#define MAX 50

/* Prototipo de funciones. */

void Lectura(int [][MAX], int, int);
void Suma(int [][MAX], int [][MAX], int [][MAX], int, int);
void Imprime(int [][MAX], int, int);


int main(void)
{
    int MA[MAX][MAX], MB[MAX][MAX], MC[MAX][MAX]; /* Tres arreglos */
    int FIL, COL;

    do
    {
        printf("Ingrese el numero de filas de los arreglos:");
        scanf("%d", &FIL);

    } while (FIL > MAX || FIL < 1); /* Validacion filas */

    do {
        printf("Ingrese el numero de columnas de los arrglos:");
        scanf("%d",&COL);

    } while (COL > MAX || COL < 1); /* Verificacion de columnas */

    printf("\nLectura del Arreglo MA\n");
    Lectura(MA, FIL, COL);

    printf("\nLectura del Arreglo MB\n");
    Lectura(MB, FIL, COL);

    Suma(MA, MB, MC, FIL, COL);

    printf("\nImpresion del Arreglo MC\n");
    Imprime(MC, FIL, COL);

    return 0;

}

void Lectura(int A[][MAX], int F, int C)
/* La funcion lectura se utiliza para leer un arreglo bidimensional entero
de fila y columnas. */

{
    int I, J;
    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++){
            printf("Ingrese el elemento %d %d: ", I + 1, J + 1);
            scanf("%d",&A [I][J]);

            }

}


void Suma(int M1[][MAX], int M2[][MAX], int M3[][MAX], int F, int C)
/* Suma M1 y M2 y guarda en M3. */

{
    int I, J;
    for(I = 0; I < F; I++)
        for(J = 0; J <C; J++)
        M3[I][J] = M1[I][J] + M2[I][J];

}

void Imprime(int A[][MAX], int F, int C)
/* Imprime el arreglo bidimensional de F filas y C columnas.*/

{
    int I, J;
    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++)
            printf("Elemento %d %d: %d\n",I, J, A[I][J]);

}



