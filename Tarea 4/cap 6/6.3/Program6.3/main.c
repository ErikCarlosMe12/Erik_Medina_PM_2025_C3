#include <stdio.h>

/* Univrsidad.
El programa, al recibir informacion sobre el numero de alumnos que han ingresado
a sus ocho diferentes carreras en los dos semestres lectivos de los ultimos
cinco años, obtiene informacion util para el departamento escolar. */

#define F 8
#define C 2
#define P 5

/* Se declaran constantes para la fila, columna y profundidad. */

void Lectura(int [][C][P], int, int, int);
void Funcion1(int [][C][P], int, int, int);
void Funcion2(int [][C][P], int, int, int);
void Funcion3(int [][C][P], int, int, int);

/* Prototipo de funciones. Cada prototipo de funcion corresponde a uno
de los inicios. */

int main(void)
{
    int UNI[F][C][P];


    Lectura(UNI, F, C, P);
    Funcion1(UNI, F, C, P);
    Funcion2(UNI, F, C, P);
    Funcion3(UNI, F, C, P); /* 6= clave de Ingenieria en Computacion(fila 6.)*/

    return 0;

}

void Lectura(int A [][C][P], int FI, int CO, int PR)
/* Lee un arreglo tridimensional entero de FI filas, CO columnas y PR profundidad. */

{
    int K, I, J;
    for (K = 0; K < PR; K++)
        for (I = 0; I < FI; I++)
        for (J = 0; J < CO; J++) {
                printf("Ano: %d\tSemestre: %d\tSemestre: %d", K + 1, I + 1, J + 1);
                scanf("%d", &A[I][J][K]);

                }
}


void Funcion1(int A[][C][P], int FI, int CO, int PR)
/* Determina el año con mayor ingreso total de alumnos. */

{
    int K, I, J, MAY = 0, AO = -1, SUM;

    for (K = 0; K < PR; K++){
            SUM = 0;
            for(I = 0; I < FI; I++)
                for (J = 0; J < CO; J++)
                SUM += A[I][J][K];

            if (SUM > MAY){
                MAY = SUM;
                AO = K;

                }
            }

            printf("\n\nAño con mayor ingreso de alumnos: %d Alumnos: %d", AO + 1, MAY);

}

void Funcion2(int A[][C][P], int FI, int CO, int PR)
/* Determina la carrera con mayor numero de alumnos en el ultimo año. */

{
    int I, J, MAY = 0, CAR = -1, SUM;

    for (I = 0; I < FI; I++) {
            SUM = 0;
            for (J = 0; J < CO; J++)
                SUM += A[I][J][PR - 1];

            if (SUM > MAY) {
                    MAY = SUM;
                    CAR = I;


                        }
                    }

    printf("\n\nCarrera con mayor numero de alumnos (ultimo año): %d Alumnos: %d", CAR + 1, MAY);
}


void Funcion3(int A[][C][P], int FI, int CO, int PR)

/* Determina el año con mayor ingreso para la carrera FI (por parametro). */

{
    int K, J, MAY = 0, AO = -1, SUM;

    for (K = 0; K < PR; K++) {
        SUM = 0;
        for (J = 0; J < CO; J++)
            SUM += A[FI - 1][J][K];

        if (SUM > MAY){
            MAY = SUM;
            AO = K;
        }
    }
    printf("\n\nAño con mayor ingreso de alumnos (carrera %d): %d Alumnos: %d",
           FI, AO + 1, MAY);
}




