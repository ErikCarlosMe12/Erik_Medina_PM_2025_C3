#include <stdio.h>


/*El programa, al recibir los salarios de 15 profesores, obtiene el total de l nomina de la universidad.

I: variable de tipo entero.
SAL y NOM: variables de tipo de real. */
 int main(void)

{
    int I;
    float SAL, NOM = 0.0f;

    for (I = 1; I<= 15; I++)
    {
        printf("\nIngrese el salario del profesor%d:\t", I);
        if (scanf("%f", &SAL) != 1){
            printf("\nEntrada invalida.\n");
            return 1;

    }
    NOM += SAL;

    }
    printf("\nEl total de la nomina es: %.2f\n", NOM);
    return 0;

}




