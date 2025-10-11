#include <stdio.h>


/* Orden por seleccion directa. */

#define MAX 100
/* Prototipos */


void Lectura(int *A, int T);
void Ordena(int *A, int T);   /* Prototipos de funciones. */
void Imprime(int *A, const int T);


int main(void)

{
    int TAM, VEC[MAX];
    do
    {
        printf("Ingrese el tamaño del arreglo (1-%d): " , MAX);
        if(scanf("%d", &TAM) != 1){
            printf("Entrada invalida.\n");
            return 0;

        }
    } while (TAM > MAX || TAM < 1); /* Se verifica que el tamaño del arreglo sea correcto. */

    Lectura(VEC, TAM);
    Ordena(VEC, TAM);
    Imprime(VEC, TAM);
    return 0;
    }


void Lectura(int A[], int T)
/* La funcion  Lectura se utiliza para leer un arreglo unidimensional de T
elementos de tipo neter. */
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("Ingrese el elemento %d: ", I+1);
        scanf("%d", &A[I]);
    }
}

void Imprime(int A[], int T)
/* Esta funcion utiliza para escribir un arreglo unidimensional
ordenado de T elementos de tipo entero. */

{
    int I;
    printf("\nArreglo ordenado:\n");
    for (I=0; I<T; I++)
        printf("\nA[%d]: %d\n", I, A[I]);
}


void Ordena (int A[], int T)
/* La funcion Ordena Utiliza el metodo de seleccion directa para ordenar
los elementos del arreglo unidimensional A. */

{
    int I, J, MEN, L;
    for (I=0; I < T-1; I++)
    {
        MEN = A[I];
        L = I;
        for (J=(I+1); J<T; J++){
            if (A[J] < MEN){
            MEN = A[J];
            L = J;
        }

    }
    if (L != I){
        A[L] = A[I];
        A[I] = MEN;
    }


}
}
