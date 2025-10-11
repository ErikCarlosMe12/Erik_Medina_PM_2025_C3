#include <stdio.h>


void trueque(int *x, int *y)
{
     int tem;
     tem = *x;
     *x = *y;
     *y = tem;
}

int suma(int x)
{
    return (x + x);
}


/**Ejercico de pensamiento logico*/


/* Examina cuidadosamente el siguiente segmento de programa:
y determina cuáles de las siguientes llamadas a las funciones son correctas si x, y y
z son variables de tipo entero.

1. trueque(suma (&x), &x); =  no

2. trueque(3, 4);   = no

3. suma(10);      = si

4. y = suma(10);   = si

5. z = trueque(&x, &y);  = no

6. trueque(&x, &y);     = si     */





