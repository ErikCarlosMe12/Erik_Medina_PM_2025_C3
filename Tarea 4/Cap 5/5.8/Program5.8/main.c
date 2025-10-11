#include <stdio.h>

/* Primos.
El programa almacena en un arreglo unidimensional los primeros 100
numeros primos. */

#define TAM 100

 void Imprime(const int Primos[], int T); /* Prototipos de funciones. */
 void Primo(int A, int *esPrimo);

int main(void)
{
    int P[TAM];
    int J = 1;
    int PRI = 3;
    int FLA;
    P [0] = 2;

    while (J < TAM)
    {
        FLA = 1;
         Primo(PRI, &FLA); /* Se llama a la funcion que determina si PRI es primo. */

         if (FLA) /* Si FLA es 1, entonces PRI es primo. */
         {
             P[J] = PRI;
             J++;
         }
         PRI += 2;

    }

    Imprime(P, TAM);
    return 0;
}

void Primo(int A, int *B)
/* Esta funcion determina si A es primo, en cuyo caso el valor de *B nose altera. */

{
    int d;

    if (A < 2)  { *B = 0; return;}
    if (A == 2)  { *B = 1; return;}
    if (A % 2 == 0)  { *B = 0; return;}

    for (d = 3; (*B) && (d * d <= A); d += 2){
            if (A % d == 0) *B = 0;

    }
}


void Imprime(const int Primos[], int T)
/* Esta funcion imprime el arreglo unidimensional de numeros primos. */
{
    int I;
    for (I = 0; I < T; I++)
        printf("\nPrimos[%3d] = %d\n ", I, Primos[I]);

}



