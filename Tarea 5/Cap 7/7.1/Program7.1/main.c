#include <stdio.h>

/* Funciones para el manejo de caracteres de la biblioteca stdio.h */
int main(void)
{

    char p1, p2, p3 = '$';
    /* Declaración de las variables tipo caracter p1, p2 y p3. Observa que a p3 se le
    asigna el símbolo $. */

    printf("\nIngrese un caracter: ");
    p1 = getchar();     /* Leer un caracter */
    putchar(p1);        /* Escribir un caracter */
    printf("\n");

    fflush(stdin);      /* No portátil; en GCC puede no hacer nada */

    printf("\nEl caracter p3 es: ");
    putchar(p3);        /* Escribir el caracter almacenado en p3 */
    printf("\n");

    printf("\nIngrese otro caracter: ");
    fflush(stdin);      /* No portátil */
    scanf(" %c", &p2);  /* Nota el espacio antes de %c para saltar '\n' pendiente */
    printf("%c", p2);   /* Escribir un caracter */
    return 0;
}
