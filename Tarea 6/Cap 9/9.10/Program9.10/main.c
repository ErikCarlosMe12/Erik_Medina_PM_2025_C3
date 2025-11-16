#include <stdio.h>


/* Alumnos.
   El programa lee registros de un archivo de acceso directo. */

   typedef struct {
       int matricula;
        char nombre[20];
        int carrera;
    float promedio;
} alumno;


/* Prototipo */
void lee(FILE *);

int main(void)
{

    FILE *ar;

    ar = fopen("ad1.dat", "rb");   /* Corrección: leer archivo binario */

    if (ar != NULL)
    {

        lee(ar);
        fclose(ar);
    }
        else
        {

            printf("\nEl archivo no se puede abrir");
        }

    return 0;
}

/* ---------------------------------------------------------- */
/* LECTURA DE REGISTROS BINARIOS                              */
/* ---------------------------------------------------------- */
void lee(FILE *ap)
{

    alumno alu;

    /* Primera lectura ANTES del ciclo */
        if (fread(&alu, sizeof(alumno), 1, ap) != 1)
            return;  /* archivo vacío */

            while (1)
            {

        printf("\nMatricula: %d", alu.matricula);
        printf("\tCarrera: %d", alu.carrera);
        printf("\tPromedio: %.2f\t", alu.promedio);
        printf("Nombre: %s", alu.nombre);

        /* Leer siguiente registro */
        if (fread(&alu, sizeof(alumno), 1, ap) != 1)
            break;  /* fin del archivo */

            }
}


