#include <stdio.h>

/* Empresa textil.
El programa, al recibir un arreglo tridimensional que contiene información
sobre las ventas mensuales de tres departamentos en los últimos ocho años,
genera información estadística valiosa para la empresa. */

#define MES 12
#define DEP 3
#define ANIO 8

void Lectura(float [MES][DEP][ANIO], int, int, int);
void Funcion1(float [MES][DEP][ANIO], int, int, int);
void Funcion2(float [MES][DEP][ANIO], int, int, int);
void Funcion3(float [MES][DEP][ANIO], int, int, int);

int main(void)
{

    float PRO[MES][DEP][ANIO];

    Lectura(PRO, MES, DEP, ANIO);
    Funcion1(PRO, MES, DEP, 2);
    Funcion2(PRO, MES, DEP, ANIO);
    Funcion3(PRO, MES, DEP, ANIO);

    return 0;
}

void Lectura(float A[][DEP][ANIO], int F, int C, int P)
/* Lee un arreglo tridimensional de reales de F x C x P. */
{

    int K, I, J;
    for (K = 0; K < P; K++)
        for (I = 0; I < F; I++)
            for (J = 0; J < C; J++) {
                printf("Año: %d\tMes: %d\tDepartamento: %d ", K + 1, I + 1, J + 1);
                scanf("%f", &A[I][J][K]);
            }
}

void Funcion1(float A[][DEP][ANIO], int F, int C, int P)
/* Ventas totales de la empresa en el año P (2 => segundo año). */
{

    int I, J;
    float SUM = 0.0f;

    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++)
            SUM += A[I][J][P - 1];

        printf("\n\nVentas totales de la empresa en el segundo año: %.2f", SUM);
}

void Funcion2(float A[][DEP][ANIO], int F, int C, int P)
/* Departamento con mayores ventas en el último año (P). */
{

    int I, J;
    float SUM1 = 0.0f, SUM2 = 0.0f, SUM3 = 0.0f;

    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++) {
        switch (J + 1) {
        case 1: SUM1 += A[I][J][P - 1]; break;  /* Hilos */
        case 2: SUM2 += A[I][J][P - 1]; break;  /* Lanas */
        case 3: SUM3 += A[I][J][P - 1]; break;  /* Licra */
            }
    }

        if (SUM1 >= SUM2 && SUM1 >= SUM3) {
                printf("\n\nDepartamento con mayores ventas en el último año: Hilos");
                printf(" Ventas: %.2f", SUM1);
            } else if (SUM2 >= SUM1 && SUM2 >= SUM3) {
                    printf("\n\nDepartamento con mayores ventas en el último año: Lanas");
                    printf(" Ventas: %.2f", SUM2);
                        } else {
                    printf("\n\nDepartamento con mayores ventas en el último año: Licra");
                    printf(" Ventas: %.2f", SUM3);
        }
}

void Funcion3(float A[][DEP][ANIO], int F, int C, int P)
/* Departamento, mes y año con la mayor venta (valor máximo en todo el tensor). */
{

    int K, I, J, DE = 0, ME = 0, AN = 0;
    float VEN = -1.0f;

    for (K = 0; K < P; K++)
        for (I = 0; I < F; I++)
            for (J = 0; J < C; J++)
                if (A[I][J][K] > VEN) {
                VEN = A[I][J][K];
                DE = J; ME = I; AN = K;
                }

        printf("\n\nDepartamento: %d\tMes: %d\tAño: %d", DE + 1, ME + 1, AN + 1);
        printf("\tVentas: %.2f", VEN);
}

