#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Funciones para el manejo de caracteres de la biblioteca stdlib.h. */
int main(void)
{

    int i;
    double d;
    long l;
    char cad0[20], *cad1;

    printf("\nIngrese una cadena de caracteres: ");
    if (fgets(cad0, sizeof(cad0), stdin)) {
    size_t L = strlen(cad0);
    if (L && cad0[L-1] == '\n') cad0[L-1] = '\0';
    }
    i = atoi(cad0);
    /* atoi: convierte string numérico a int (0 si no hay número). */
    printf("\n%s \t %d", cad0, i + 3);

    printf("\nIngrese una cadena de caracteres: ");
    if (fgets(cad0, sizeof(cad0), stdin)) {
    size_t L = strlen(cad0);
    if (L && cad0[L-1] == '\n') cad0[L-1] = '\0';
            }
    d = atof(cad0);
    /* atof: convierte string a double (0 si no hay número). */
    printf("\n%s \t %.2lf ", cad0, d + 1.50);

    d = strtod(cad0, &cad1);
    /* strtod: convierte a double y deja el resto en cad1. */
    printf("\n%s \t %.2lf", cad0, d + 1.50);
    puts(cad1);

    l = atol(cad0);
    /* atol: convierte string a long (0 si no hay número). */
    printf("\n%s \t %ld ", cad0, l + 10);

    l = strtol(cad0, &cad1, 0);
    /* strtol: convierte a long; cad1 apunta al resto; base auto (0). */
    printf("\n%s \t %ld", cad0, l + 10);
    puts(cad1);

    return 0;
}

