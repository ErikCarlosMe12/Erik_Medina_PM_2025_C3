#include <stdio.h>
#include <string.h>

/* Hospital.
El programa genera informacion acerca de los pacientes de un hospital. */

typedef struct {
    char cal[20];  /* Calle */
    int num;       /* Numero */
    char col[20];  /* Colonia */
    char cp[6];    /* Codigo Postal (5 + '\0') */
    char ciu[20];  /* Ciudad */
} domicilio;

typedef struct {
    char nom[20];     /* Nombre y apellido */
    int  edad;
    char sexo;        /* 'F' o 'M' */
    int  con;         /* Condicion (1..5) */
    domicilio dom;    /* Domicilio completo */
    char tel[11];     /* Telefono (10 + '\0') */
} paciente;

/* Prototipos */
void Lectura(paciente *, int);
void F1(paciente *, int);
void F2(paciente *, int);
void F3(paciente *, int);

int main(void)
{

    paciente HOSPITAL[100];
    int TAM;

    do {
        printf("Ingrese el numero de pacientes: ");
        scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1);

    Lectura(HOSPITAL, TAM);
    F1(HOSPITAL, TAM);
    F2(HOSPITAL, TAM);
    F3(HOSPITAL, TAM);

    return 0;
}

/* ------------------------------------------------------------- */
/* LECTURA                                                        */
/* ------------------------------------------------------------- */
void Lectura(paciente A[], int T)
{

    int I;

    for (I = 0; I < T; I++)
    {

    printf("\n\tPaciente %d\n", I + 1);

    printf("Nombre: ");
    scanf(" %19[^\n]", A[I].nom);

    printf("Edad: ");
    scanf("%d", &A[I].edad);

    printf("Sexo (F-M): ");
    scanf(" %c", &A[I].sexo);

    printf("Condicion (1..5): ");
    scanf("%d", &A[I].con);

        /* ---------------------- Domicilio ---------------------- */
    printf("Calle: ");
    scanf(" %19[^\n]", A[I].dom.cal);

    printf("Numero: ");
    scanf("%d", &A[I].dom.num);

    printf("Colonia: ");
    scanf(" %19[^\n]", A[I].dom.col);

    printf("Codigo Postal: ");
    scanf(" %5s", A[I].dom.cp);   /* 5 chars max */

    printf("Ciudad: ");
    scanf(" %19[^\n]", A[I].dom.ciu);

    /* ---------------------- Telefono ----------------------- */
    printf("Telefono (10 digitos): ");
    scanf(" %10s", A[I].tel);
    }
}

/* ------------------------------------------------------------- */
/* F1 – Porcentaje de hombres y mujeres                          */
/* ------------------------------------------------------------- */
void F1(paciente A[], int T)
{

    int I, FEM = 0, MAS = 0, TOT;

    for (I = 0; I < T; I++) {
        if (A[I].sexo == 'F' || A[I].sexo == 'f')
            FEM++;
        else if (A[I].sexo == 'M' || A[I].sexo == 'm')
            MAS++;
    }

        TOT = FEM + MAS;

    if (TOT == 0)
        return;

    printf("\nPorcentaje de Hombres: %.2f%%", (float)MAS / TOT * 100);
    printf("\nPorcentaje de Mujeres: %.2f%%", (float)FEM / TOT * 100);
}

/* ------------------------------------------------------------- */
/* F2 – Pacientes por condicion                                   */
/* ------------------------------------------------------------- */
void F2(paciente A[], int T)
{

    int I, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;

    for (I = 0; I < T; I++) {
        switch (A[I].con) {
        case 1: C1++; break;
        case 2: C2++; break;
        case 3: C3++; break;
        case 4: C4++; break;
        case 5: C5++; break;
        }
    }

    printf("\n\nPacientes por condicion:");
    printf("\nCondicion 1: %d", C1);
    printf("\nCondicion 2: %d", C2);
    printf("\nCondicion 3: %d", C3);
    printf("\nCondicion 4: %d", C4);
    printf("\nCondicion 5: %d", C5);
}

/* ------------------------------------------------------------- */
/* F3 – Pacientes en condicion 5                                  */
/* ------------------------------------------------------------- */
void F3(paciente A[], int T)
{

    int I;

    printf("\n\nPacientes en estado de gravedad (condicion 5):\n");

    for (I = 0; I < T; I++) {
        if (A[I].con == 5)
            printf("Nombre: %s\tTelefono: %s\n", A[I].nom, A[I].tel);
    }
}


