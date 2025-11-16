#include <stdio.h>
#include <string.h>

/* Funciones para el manejo de cadenas de caracteres de la biblioteca stdio.h. */
int main(void)
{

    const char *cad0 = "Buenos días";   /* 11 chars + '\0' */
    char cad1[20] = "Hola";
    char cad2[] = "México";
    char cad3[] = { 'B','i','e','n','v','e','n','i','d','o','\0' };
    char cad4[20], cad5[20], cad6[20];

    printf("\nLa cadena cad0 es: ");
    puts(cad0);

    printf("\nLa cadena cad1 es: ");
    printf("%s", cad1);

    printf("\nLa cadena cad2 es: ");
    puts(cad2);

    printf("\nLa cadena cad3 es: ");
    puts(cad3);

    printf("\nIngrese una línea de texto —se lee con gets—: \n");
    /* gets está eliminado en C11; usar fgets como reemplazo directo */
    if (fgets(cad4, sizeof(cad4), stdin)) {
        size_t L = strlen(cad4);
        if (L && cad4[L - 1] == '\n') cad4[L - 1] = '\0';
    }
    printf("\nLa cadena cad4 es: ");
    puts(cad4);

    fflush(stdin);

    printf("\nIngrese una línea de texto —se lee con scanf—: \n");
    scanf("%19s", cad5);   /* limitar a 19 para evitar overflow */
    printf("\nLa cadena cad5 es: ");
    printf("%s", cad5);

    fflush(stdin);

    char p;
    int i = 0;

    printf("\nIngrese una línea de texto —se lee cada caracter con getchar—: \n");
    /* leer chars hasta fin de línea */
    while ((p = getchar()) != '\n' && i < (int)sizeof(cad6) - 1)
        cad6[i++] = p;
    cad6[i] = '\0';

    printf("\nLa cadena cad6 es: ");
    puts(cad6);

    return 0;
}
