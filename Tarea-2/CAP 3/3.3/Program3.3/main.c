#include <stdio.h>

/* Suma pagos.


El programa, al recibir como datos un conjunto de pagos realizados
en el ultimos mes, obtiene la suma de los mismos.

PAG y SPA:

variables de tipo real. */

int main(void)
{
    float PAG, SPA = 0.0f;
    printf("Ingrese el primer pago (0 para terminar): ");
    if (scanf("%f", &PAG)!= 1){
            printf("\nEntrada invalida. \n");
            return 1;

    }
    /* La condicion es verdadera mientras el pago sea distinto de cero. */

    while (PAG != 0.0f)

    {
        SPA = SPA + PAG;
        printf("Ingrese el siguiente pago(0 para terminar):");
        if (scanf("%f", &PAG) != 1){
            printf("cnEntrada invalida. \n");
            return 1;

        }

    }
    printf("\nEl total de pagos del mes es: %.2f\n", SPA);
    return 0;
}





