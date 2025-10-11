#include <stdio.h>

/* Arreglo sin elementos repetidos.
El programa, al recibir como datos un arreglo unidimensional desordenado
de N elementos, obtiene como salida ese mismo arreglo pero sin los
elementos repetitivos. */

#define MAX 100


void Lectura(int *A, int T); /* Prototipos de funciones. */
void Imprime(const int *A , int T);
void Elimina_0(int *A, int *T); /* T por referencia: puede disminuir */


int main(void)

{
    int TAM, ARRE[MAX];
    /* Validacion del tamaño ingresado */

    do {
             printf("Ingrese el tamaño del arreglo (1-%d): ", MAX);

            if (scanf("%d", &TAM) != 1) {
                    printf("Entrada invalida.\n");
                    return 0;

                    }
}  while (TAM < 1  || TAM > MAX);


Lectura(ARRE, TAM);
Elimina_0(ARRE, &TAM); /* T por referencia: puede reducirse al eliminar dupllicados */
Imprime(ARRE, TAM);

return 0;
}


void Lectura(int A[], int T)
/* Lee T enteros en el arreglo A. */

{
    int I;
    printf("\n");
    for (I = 0; I < T; I++) {
            printf("Ingrese el elemento %d: ", I + 1);
            scanf("%d", &A[I]);
            }
}

void Imprime(const int A[], int T)
/* Imprime el arreglo A de tamaño T*/
{
    int I;
    printf("\nArreglo sin elementos repetitivos:\n");
    for (I = 0; I < T; I++)
    printf("A[%d]: %d\n", I, A[I]);

}


void Elimina_0(int A[], int *T)
/* Elimina elementos repetitivos preservando la primera aparicion. */

{
    int I = 0, K, L;

    while(I < (*T - 1)) {
            K = I + 1;
            while (K < *T){
                if (A[I] == A[K]){
                        /* Desplazar a la izquierda desde K */
                        for (L = K; L < (*T - 1); L++)
                        A[L] = A[L + 1];
                (*T)--; /* Se redujo el tama;o */
                /* No incrementamos K: deemos revisar el nuevo A[K] */

                } else {
                    K++;

                }

            }
            I++;

        }
}





