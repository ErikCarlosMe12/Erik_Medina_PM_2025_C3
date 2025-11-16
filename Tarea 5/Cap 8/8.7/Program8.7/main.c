#include <stdio.h>
#include <string.h>

/* Escuela.
El programa genera informacion importante de los alumnos de una escuela. */

typedef struct {
    char mat[20];  /* Materia */
    int pro;       /* Promedio */
    } matpro;

    typedef struct {
    int matri;        /* Matricula */
    char nom[20];     /* Nombre del alumno */
    matpro cal[5];    /* Arreglo de 5 materias */
    } alumno;

    /* Prototipos */
    void Lectura(alumno *, int);
    void F1(alumno *, int);
    void F2(alumno *, int);
    void F3(alumno *, int);

    int main(void)
    {

    alumno ALU[50];
    int TAM;

    do {
    printf("Ingrese el tamanodel arreglo: ");
    scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1);

    Lectura(ALU, TAM);
    F1(ALU, TAM);
    F2(ALU, TAM);
    F3(ALU, TAM);

    return 0;
    }

/* -------------------------------------------------------- */
/* LECTURA                                                  */
/* -------------------------------------------------------- */
void Lectura(alumno A[], int T)
{

    int I, J;

    for (I = 0; I < T; I++) {

        printf("\nIngrese los datos del alumno %d\n", I + 1);

        printf("Ingrese la matricula del alumno: ");
        scanf("%d", &A[I].matri);

        printf("Ingrese el nombre del alumno: ");
        scanf(" %19[^\n]", A[I].nom);

        for (J = 0; J < 5; J++) {
            printf("\tMateria %d: ", J + 1);
            scanf(" %19[^\n]", A[I].cal[J].mat);

            printf("\tPromedio %d: ", J + 1);
            scanf("%d", &A[I].cal[J].pro);

        }

    }

}

/* -------------------------------------------------------- */
/* F1 – Promedio general de cada alumno                     */
/* -------------------------------------------------------- */

void F1(alumno A[], int T)
{

    int I, J;
    float SUM;

    for (I = 0; I < T; I++) {

        printf("\nMatricula del alumno: %d", A[I].matri);

        SUM = 0.0;
        for (J = 0; J < 5; J++)
            SUM += A[I].cal[J].pro;

        SUM /= 5;

        printf("\tPromedio: %.2f", SUM);
    }
}

/* -------------------------------------------------------- */
/* F2 – Alumnos con calificacion > 9 en la materia 3        */
/* -------------------------------------------------------- */
void F2(alumno A[], int T)
{

    int I;

    printf("\n\nAlumnos con calificacion mayor a 9 en la tercera materia:\n");

    for (I = 0; I < T; I++) {
        if (A[I].cal[2].pro > 9)
            printf("Matricula: %d\n", A[I].matri);
    }
}

/* -------------------------------------------------------- */
/* F3 – Promedio general de la materia 4                    */
/* -------------------------------------------------------- */
void F3(alumno A[], int T)
{

    int I;
    float SUM = 0.0;

    for (I = 0; I < T; I++)
        SUM += A[I].cal[3].pro;

    SUM /= T;

    printf("\nPromedio de la cuarta materia: %.2f\n", SUM);
}

