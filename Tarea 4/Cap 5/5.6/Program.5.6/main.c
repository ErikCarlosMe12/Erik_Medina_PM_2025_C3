#include <stdio.h>
#include <math.h>

/* Suma-cuadrados.
El programa calcula la suma del cuadrado de los elementos de un arreglo
unidimensional de 100 elementod de tipo real. */

#define MAX 100

/* MAX se utiliza para reservar el espacio maximo que podra ocupar
el arreglo. */

void Lectura(float *A, int T ); /* Prototipos de funciones. */
double Suma(const float *A, int T);

int main(void)
{
    float VEC[MAX];
    double RES;

    Lectura(VEC, MAX);
    RES = Suma(VEC, MAX); /* Suma de cuadrados*/

    /* Se llama a la funcion Suma y se almacena el resultado en la variable RES. */

    printf("\n\nSuma del arreglo: %.2f\n", RES);
    return 0;
}

void Lectura(float A[], int T)
/* La funcion Lectura se utiliza leer un arreglo unidimensional de T
elementos de tipo real. */

{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%f", &A[I]);

    }
}

double Suma( const float A[], int T)
/* La funcion Suma se utiliza para calcular la suma del cuadrado
de los componentes de un arreglo unidimensional de T elementos de
tipo real. */
{
    int I;
    double AUX = 0.0;
    for (I = 0; I < T; I++)
        AUX += (double)A[I] * (double)A[I];
    return AUX;


}

