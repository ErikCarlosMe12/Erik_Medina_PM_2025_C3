#include <stdio.h>


/* Prueba de parametros por referencia. */

void f1 (int *);
/* Prototipo de funcion. EL parametro es de tipo entero y por redefenciaa
observa el uso del operador de indireccion. */

int main(void)
{
int I, K = 4;
for (I = 1; I <= 3; I++)
{
    printf("\n\nValor de K antes de llamar a la funcion: %d", ++K);
    f1(&K); /* Se pasa la direccion de K por referencia */
    printf("\nValor de K despues de llamar a la funcion: %d", K);
    }
    /* Llamada a la funcion f1. Se pasa la direccion de la variable K,
    por medio del operador de direccion: &. */
    return 0;
    }

void f1 (int *R)
/* La funcion f1 recibe un parametro por referencia.
Cada vez que el parametro se usa, debe ir precedido por el operador
de direccion  (*). */

{
    *R += *R; /* Duplica el valor de K */
}





