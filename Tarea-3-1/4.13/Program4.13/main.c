#include <stdio.h>


/* Pares e impares.
El programa, al recibir como datos N numeros enteros, calcula
cuantos de ellos son pares y cuantos impares, con la ayuda de una
funcion. */
void parimp(int num, int *pares, int *impares); /* Prototipo de funcion. */

int main(void)
{
    int i, n, num, par = 0, imp = 0;

    printf("Ingresa el numero de datos: ");
    if (scanf("%d", &n)!= 1 || n <= 0){
            printf("Entrada invalida.\n");
            return 0;
    }


    for (i =1; i <= n; i++)

    {
        printf("Ingresa el numero %d: ", i);
        if(scanf(" %d", &num) != 1){
        printf("Entrada invalida.\n");
        return 0;

        }
        parimp(num, &par, &imp);   /* Por valor y por por referencia*/

    }

    printf("\nNumero de pares: %d", par);
    printf("\nNumero de impares: %d\n", imp);


    return 0;

}
    void parimp(int num, int*pares, int *impares)
    /* Incrementa *pares o *impares segun num sea par o impar.*/

{

    if (num % 2 == 0)
        (*pares) ++;
    else
        (*impares)++;

}






