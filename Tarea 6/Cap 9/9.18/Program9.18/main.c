#include <stdio.h>

/* Mezcla archivos ordenados por matricula */

void mezcla(FILE *, FILE *, FILE *);

int main(void)
{

    FILE *ar, *ar1, *ar2;

    ar  = fopen("arc9.dat",  "r");
    ar1 = fopen("arc10.dat", "r");
    ar2 = fopen("arc11.dat", "w");

    if (ar != NULL && ar1 != NULL && ar2 != NULL)
    {

        mezcla(ar, ar1, ar2);

        fclose(ar);
        fclose(ar1);
        fclose(ar2);
    }
    else
    {

        printf("No se pueden abrir los archivos");
    }

    return 0;
}

/* ---------------------------------------------------------- */
/* Funcion que MEZCLA ar y ar1 en ORDEN, y escribe en ar2     */
/* ---------------------------------------------------------- */
void mezcla(FILE *ar, FILE *ar1, FILE *ar2)
{

    int mat, mat1;
    float ca[3], ca1[3], cal;
    int b = 1, b1 = 1;   /* banderas para lectura */
    int i;

    /* Mientras ambos tengan registros disponibles */
    while (1)
    {

        /* Leer siguiente registro de ar si bandera b = 1 */
        if (b)
        {

            if (fscanf(ar, "%d", &mat) != 1)
                break;  /* ar se acabó */
            for (i = 0; i < 3; i++)
                fscanf(ar, "%f", &ca[i]);
            b = 0;
        }

        /* Leer siguiente registro de ar1 si bandera b1 = 1 */
        if (b1)
        {

            if (fscanf(ar1, "%d", &mat1) != 1)
                break;  /* ar1 se acabó */
            for (i = 0; i < 3; i++)
                fscanf(ar1, "%f", &ca1[i]);
            b1 = 0;
        }

        /* Comparar matrículas y escribir la menor */
        if (mat < mat1)
        {

            fprintf(ar2, "%d\t", mat);
            for (i = 0; i < 3; i++)
                fprintf(ar2, "%.2f\t", ca[i]);
            fprintf(ar2, "\n");
            b = 1;  /* leer otro registro de ar */
        }
        else
        {

            fprintf(ar2, "%d\t", mat1);
            for (i = 0; i < 3; i++)
                fprintf(ar2, "%.2f\t", ca1[i]);
            fprintf(ar2, "\n");
            b1 = 1; /* leer otro registro de ar1 */
        }
    }

    /* Si quedaron registros sin mezclar en ar */
    if (!b) /* hay un registro pendiente en ar */
    {

        fprintf(ar2, "%d\t", mat);
        for (i = 0; i < 3; i++)
            fprintf(ar2, "%.2f\t", ca[i]);
        fprintf(ar2, "\n");
    }

    while (fscanf(ar, "%d", &mat) == 1)
    {

        fprintf(ar2, "%d\t", mat);
        for (i = 0; i < 3; i++)
        {

            fscanf(ar, "%f", &cal);
            fprintf(ar2, "%.2f\t", cal);
        }
        fprintf(ar2, "\n");
    }

        /* Si quedaron registros en ar1 */
    if (!b1) /* había un registro pendiente en ar1 */
    {

        fprintf(ar2, "%d\t", mat1);
        for (i = 0; i < 3; i++)
            fprintf(ar2, "%.2f\t", ca1[i]);
        fprintf(ar2, "\n");
    }

    while (fscanf(ar1, "%d", &mat1) == 1)
    {

        fprintf(ar2, "%d\t", mat1);
        for (i = 0; i < 3; i++)
        {

            fscanf(ar1, "%f", &cal);
            fprintf(ar2, "%.2f\t", cal);
        }
            fprintf(ar2, "\n");
    }
}

