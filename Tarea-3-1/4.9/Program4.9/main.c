#include <stdio.h>


/* Paso de una funcion como parametro por referencia. */

int Suma(int x, int y)
/* La funcion Suma refre la suma de los parametros de tipo entero X y Y. */
{
    return (x+y);
}
int Resta(int x, int y)
/* Esta funcion regresa la resta de los parametros que tipo X y Y. */
{
    return (x-y);
}
int Control(int (*apf)(int, int), int x, int y)
/* Esta funcion recibe como parametro otra funcion -la direccion- y
dependiendo de cual sea esta, llama a la funcion Suma o Resta. */

{
    int RES;
    RES = (*apf) (x, y); /* Se llama a la funcion Suma o Resta. */
    return (RES);
}



void main(void)
{
    int R1, R2;
    R1 = Control(Suma, 15, 5); /*Se pasa como parametro la funcion Suma. */
    R2 = Control(Resta, 10, 4);/*Se pasa como parametro la funcion Resta. */
    printf("\nResultado 1: %d", R1);
    printf("\nResultado 2: %d", R2);
}

