#include <stdio.h>


/* Ordenacion por inserccion directa. */

#define MAX 100

void Lectura(int *A , int T);
void Ordena(int *A, int T);   /* Prototipos de funciones. */
void Imprime( const int *A, int T);

int main(void)
{
    int TAM, VEC[MAX];
    do{
        printf("Ingrese el tamaño del arreglo (1-%d): ", MAX);
        if (scanf("%d", &TAM) != 1){
                printf("Entrada invalida\n");
                return 0;
        }

}while (TAM > MAX || TAM < 1); /* Se verifica que el tamaño del arreglo sea correcto. */
Lectura(VEC, TAM);
Ordena(VEC, TAM);
Imprime(VEC, TAM);
return 0;
}


void Lectura(int A[], int T)
/* La funcion Lectura se utiliza para leer un arreglo unidimension de T elementos de tipo entero. */

{
    int I;
    for (I=0; I<T;  I++){
        printf("Ingrese el elemento %d: I + 1");
        scanf("%d", &A[I]);

    }
}

void Imprime(const int A[], int T)
/* Esta funcion se utiliza para escribir un arreglo unidimensional
ordenado de T elementos de tipo entero. */
{
    int I;
    printf("\nArreglo ordenado:\n");
    for (I=0;  I<T; I++)
        printf("\nA[%d]: %d ", I, A[I]);


}
void Ordena(int A[], int T)
/* La funcion Ordena utiliza el metodo de inserccion directa para ordenar
los elementos del arreglo unidimensional A. */

{
    int AUX, L, I;
    for (I=1; I<T; I++)
        AUX = A[I];
        L = I - 1;
        while (L >= 0 && AUX < A[L]){
        {
            A[L+1] = A[L];
            L--;

        }
        A[L+1] = AUX;
    }
}
