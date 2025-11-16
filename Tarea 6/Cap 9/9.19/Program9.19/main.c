#include <stdio.h>

/* Ordena de menor a mayor.
   El programa ordena de menor a mayor en función de la matrícula, creando
   un nuevo archivo de acceso directo compuesto por estructuras. */

typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void ordena(FILE *, FILE *); /* Prototipo de función */

int main(void)
{
    FILE *ar1, *ar2;

    ar1 = fopen("ad5.dat", "rb");   /* Archivo binario */
    ar2 = fopen("ad6.dat", "wb");   /* Archivo binario */

    if ((ar1 != NULL) && (ar2 != NULL))
    {
        ordena(ar1, ar2);
    }
    else
    {
        printf("\nEl o los archivos no se pudieron abrir");
    }

    fclose(ar1);
    fclose(ar2);

    return 0;
}

void ordena(FILE *ap1, FILE *ap2)
{
    alumno alu;
    int t, n, i;

    t = sizeof(alumno);

    /* Mover al final del archivo para calcular cantidad de registros */
    fseek(ap1, 0, SEEK_END);
    n = ftell(ap1) / t;   /* Cantidad de registros */

    /* Volver al inicio para leer */
    rewind(ap1);

    /* Recorrer en orden inverso y escribir en ap2 */
    for (i = n - 1; i >= 0; i--)
    {
        fseek(ap1, i * t, SEEK_SET);
        fread(&alu, t, 1, ap1);
        fwrite(&alu, t, 1, ap2);
    }
}
