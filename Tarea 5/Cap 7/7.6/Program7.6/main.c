#include <stdio.h>
#include <string.h>


/* Funciones de la biblioteca string.h para el manejo de cadenas de caracteres. */
int main(void)
{

    char cad0[200] = "Hola México";
    char cad1[200], cad2[200], cad3[200] = ", buenos días!!!";
    const char *p;

    strcpy(cad1, cad0);
    printf("\nPrueba de strcpy. Se copia cad0 a cad1: %s\n", cad1);

    strcpy(cad1, cad3);
    printf("\nPrueba de strcpy. Se copia cad3 a cad1: %s\n", cad1);

    strcpy(cad1, "XX");
    printf("\nPrueba de strcpy. Se copia \"XX\" a cad1: %s\n", cad1);

    strncpy(cad2, cad0, 4);  cad2[4] = '\0';
    printf("\nPrueba de strncpy. 4 chars de cad0 a cad2: %s\n", cad2);

    strncpy(cad2, cad3, 3);  cad2[3] = '\0';
    printf("\nPrueba de strncpy. 3 chars de cad3 a cad2: %s\n", cad2);

    /* Ahora cad0 es buffer grande, se puede concatenar con seguridad. */
    strcat(cad0, cad3);
    printf("\nPrueba de strcat. Se incorpora cad3 a cad0: %s\n", cad0);

    strcat(cad1, " YY");
    printf("\nPrueba de strcat. Se incorpora \" YY\" a cad1: %s\n", cad1);

    strcat(cad2, " ");
    strncat(cad2, cad0, 4);
    printf("\nPrueba de strncat. 4 chars de cad0 a cad2: %s\n", cad2);

    /* Buscar subcadenas con strstr usando un apuntador auxiliar. */
    p = strstr(cad0, "México");
    printf("\nPrueba de strstr (\"México\" en cad0): %s\n", p ? p : "(no encontrada)");

    p = strstr(cad0, "Guatemala");
    printf("\nPrueba de strstr (\"Guatemala\" en cad0): %s\n", p ? p : "(no encontrada)");

    return 0;
}

