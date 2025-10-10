#include <stdio.h>

/* Mayor divisor.
El programa, al recibir como dato un numero entero positivo,
calcula su mayor divisor. */


int mad(int);    /* Prototipo de funcion. */
void main(void)
{
    int NUM, RES;
    printf("\nIngresa el numero:");
    scanf("%d", &NUM);
    RES = mad(NUM);
    printf("\nEl mayor divisor de %d es: %d", NUM, RES);
}

int mad(int N1)
/*Esta funcion calcula el mayor divisor del numero N1. */
{
    int I = (N1 / 2);
    /* I se inicializa con el maximo valor posible que puede
    ser dividor de N1. */
    I --;
    return I;

}



