#include <stdio.h>

/* Superficie del triangulo.
El programa, al recinbir datos la base y la altura de un triangulo, calcula su superficie.

BAS, ALT Y SUP: variables de tipo real. */
void main(void)
{
 float BAS, ALT, SUP;
 printf("Ingrese la base y la altura del triangulo: ");
 scanf("%f %f", &BAS, &ALT);
 SUP = BAS * ALT / 2;
 printf("\nLa superficie del triangulo es: %5.2f", SUP );
}
