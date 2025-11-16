#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Reemplaza "mexico" incorrecto por "México" */

void cambia(FILE *, FILE *);

int main(void)
{

    FILE *ar  = fopen("arc.txt", "r");
    FILE *ap  = fopen("arc1.txt", "w");

    if (ar != NULL && ap != NULL) {
        cambia(ar, ap);
        fclose(ar);
        fclose(ap);
    } else {
        printf("No se pueden abrir los archivos");
        }

    return 0;
}

void cambia(FILE *ap1, FILE *ap2)
{

    char cad[200];
    char salida[200];
    const char *incorrectas[] = {"mexico", "méxico", "Mexico", "MEXICO", "MéXico"};
    int n = 5;

    /* Leer línea por línea */
    while (fgets(cad, sizeof(cad), ap1) != NULL)
    {

        strcpy(salida, cad);

        /* Reemplazar TODAS las versiones incorrectas */
        for (int i = 0; i < n; i++)
        {

            char *pos;

            while ((pos = strstr(salida, incorrectas[i])) != NULL)
            {

                char temp[200];
                int index = pos - salida;

                /* Construir reemplazo */
                salida[index] = '\0';
                sprintf(temp, "%sMéxico%s", salida, pos + strlen(incorrectas[i]));

                strcpy(salida, temp);
            }
        }

        /* Escribir la linea corregida */
        fputs(salida, ap2);
    }
}

