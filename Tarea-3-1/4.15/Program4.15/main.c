#include <stdio.h>


/* Productoria.
El programa calcula la productoria de los N primeros
numero naturales. */
int Productoria(int);

int main(void)
{
    int NUM;
    /* Se escribe un do-while para verificar que el numero del cual
    se quiere calcular la productoria sea correcto. */

    do
    {
        printf("Ingresa el numero del cual queires calcular la productoria: ");
        scanf("%d", &NUM);
    }
    while (NUM > 100 || NUM < 1 );
    printf("\nLa productoria de %d es: %d", NUM, Productoria(NUM));
}
int Productoria(int N)
/* La funcion calcula la productoria d N. */
{
    int I, PRO = 1;
    for (I = 1; I <= N; I++)
        PRO *= I;
    return (PRO);

}


