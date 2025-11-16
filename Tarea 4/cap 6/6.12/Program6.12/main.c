#include <stdio.h>

/* Lluvias.
El programa, al recibir como dato un arreglo tridimensional que contiene
información sobre lluvias, genera información estadística. */

#define PRO 24
#define MES 12
#define ANIO 10

void Lectura(float [PRO][MES][ANIO], int, int, int);
void Funcion1(float [PRO][MES][ANIO], int, int, int);
void Funcion2(float [PRO][MES][ANIO], int, int, int);
void Funcion3(float [PRO][MES][ANIO], int, int, int);

int main(void)
{

    float LLU[PRO][MES][ANIO];
    Lectura(LLU, PRO, MES, ANIO);
    Funcion1(LLU, PRO, MES, ANIO);
    Funcion2(LLU, PRO, MES, ANIO);
    Funcion3(LLU, 18, MES, 5);  /* provincia 18, año 5 */
    return 0;
}

void Lectura(float A[][MES][ANIO], int F, int C, int P)
/* Lee un arreglo tridimensional de reales de F x C x P. */
{

    int K, I, J;
        for (K = 0; K < P; K++)
            for (I = 0; I < F; I++)
                for (J = 0; J < C; J++) {
                        printf("Año: %d\tProvincia: %d\tMes: %d: ", K + 1, I + 1, J + 1);
                        scanf("%f", &A[I][J][K]);
            }
}

void Funcion1(float A[][MES][ANIO], int F, int C, int P)
/* Provincia con mayor registro promedio en P años (promedio sobre meses). */
{

    int I, K, J, EMAY = -1;
    float ELLU = -1.0f, SUM;

    for (I = 0; I < F; I++) {
        SUM = 0.0f;
            for (K = 0; K < P; K++)
                for (J = 0; J < C; J++)
                                                                    SUM += A[I][J][K];
                    SUM /= (P * C);
                       if (SUM > ELLU) {
                                                                    ELLU = SUM;
                                                                                EMAY = I;
            }
    }

    printf("\n\nProvincia con mayor registro de lluvias: %d", EMAY + 1);
    printf("\nRegistro: %.2f", ELLU);
}

void Funcion2(float A[][MES][ANIO], int F, int C, int P)
/* Provincia con menor promedio en el último año (P-1). */
{

    int I, J, EMEN = -1;
    float ELLU = 1000.0f, SUM;

    for (I = 0; I < F; I++) {
        SUM = 0.0f;
            for (J = 0; J < C; J++)
                SUM += A[I][J][P - 1];
                SUM /= C;

                if (SUM < ELLU) {
                                                                    ELLU = SUM;
                                                                                EMEN = I;
            }
    }

    printf("\n\nProvincia con menor registro anual de lluvias en el último año: %d",EMEN + 1);
    printf("\nRegistro anual: %.2f", ELLU);
}

void Funcion3(float A[][MES][ANIO], int F, int C, int P)
/* Mes con mayor registro en la provincia F (índice) del año P (índice). */
{

    int J, EMES = -1;
    float ELLU = -1.0f;

    for (J = 0; J < C; J++) {
            if (A[F - 1][J][P - 1] > ELLU) {
            ELLU = A[F - 1][J][P - 1];
            EMES = J;
        }
    }

printf("\n\nMes: %d Lluvias: %.2f", EMES + 1, ELLU);
}

