#include <stdio.h>

/* Fabrica de lacteos.
El programa, al recibir como datos las ventas mensuales de diferentes
productos, obtiene informacion estadisticas valiosa para la empresa. */

#define PROD 15
#define MESES 12

void Lectura1(int [PROD][MESES]);
void Lectura2(float [], int);
void Funcion1(int [][MESES], int, int, float[], float[]);
void Funcion2(float [], int);
void Funcion3(float[], int);


int main(void)

{
    int FAB[PROD][MESES] = {0};/* Ventas por producto y mes. */
    float COS[PROD], VEN[PROD];

    Lectura1(FAB);
    Lectura2(COS, PROD);
    Funcion1(FAB, PROD, MESES, COS, VEN);
    Funcion2(VEN, PROD);
    Funcion3(VEN, PROD);

    return 0;
}

void Lectura1(int A[PROD][MESES])
/* Lee transacciones: mes, tipo de producto, cantidad. Fin con -1 -1 -1. */

{
    int MES, PRO, CAN;
    printf("\nIngrrese mes, tipo de producto y cantidad vendidad:");
    scanf("%d %d %d", &MES, &PRO, &CAN);


    while (MES != -1  && PRO != -1 && CAN != -1){
        if (MES >= 1 && MESES && PRO >= 1 && PRO <= PROD)
            A[PRO -  1][MES - 1] += CAN; /* fila = producto, col = mes */

            printf("Ingrese mes, tipo de producto y cantidad vendida: ");
            scanf("%d %d %d", &MES, &PRO, &CAN);

    }
}

void Lectura2(float A[], int N)
/* Lee el costo de cada producto. */
{
    int I;
    for (I = 0; I < N; I++){
        printf("Ingrese costo del producto %d: ", I + 1);
        scanf("%f", &A[I]);

    }
}

void Funcion1(int A[][MESES],int F, int C, float V1[], float V2[])

/* Calcula el monto anual vendido por cada producto. */

{
    int I, J, SUM;
    printf("\n");
    for (I = 0; I < C; J++){
        SUM = 0;
        for (J = 0; J < C; J++)
            SUM += A[I][J];

        V2[I] = V1[I]*SUM;
        printf("\nTotal de ventas del productos %d: %8.2f",  I + 1, V2[I]);

    }
}

void Funcion2(float A[], int C)
/* Calcula el monto total de ventas de la fabrica. */

{
    int I;
    float SUM = 0.0f;

    for (I = 0; I < C; I++)
        SUM += A[I];

    printf("\n\nTotl de ventas de la fabrica: %d.2f", SUM);

}

void Funcion3(float A[], int C)
/* Determina el producto con mayores ventas. */


{
    int I, TPR = 0;
    float VEN = A[0];

    for (I = 1; I < C; I++){
        if (A[I] > VEN){
            VEN = A[I];
            TPR = I;
            }
    }
    printf("\n\nTipo de Producto mas vendido: %d \t Ventas: %.2f\n", TPR + 1, VEN);


}
