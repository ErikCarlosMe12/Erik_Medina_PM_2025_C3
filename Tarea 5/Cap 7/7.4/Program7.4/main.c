#include <stdio.h>
#include <string.h>

/* Declaracion de cadenas de caracteres y asignacion de valores. */
int main(void)
{

    const char *cad0;     /* literal → const char* */
    cad0 = "Argentina";   /* Correcto */
    puts(cad0);
    cad0 = "Brasil";     /* Correcto: cambia a dónde apunta */
    puts(cad0);

    /* Para leer a memoria escribible, usa un arreglo (buffer), no un char* sin asignar */
    char cad1[100] = "";     /* Reservar espacio primero */
    /* gets(*cad1); gets(cad1);  ← Incorrecto (eliminado) */
    /* Correcto: lectura segura con fgets */
    printf("Ingrese una línea para cad1: ");
    if (fgets(cad1, sizeof(cad1), stdin)) {
        size_t L = strlen(cad1);
        if (L && cad1[L - 1] == '\n') cad1[L - 1] = '\0';
    }
    puts(cad1);

    /* Arreglo con espacio reservado: se puede modificar */
    char cad2[20] = "México";        /* Correcto */
    puts(cad2);

    printf("Ingrese una palabra/frase corta para cad2: ");
    if (fgets(cad2, sizeof(cad2), stdin)) {
        size_t L2 = strlen(cad2);
        if (L2 && cad2[L2 - 1] == '\n') cad2[L2 - 1] = '\0';

    }
    puts(cad2);

    /* cad2[10] = "Guatemala";  ← Incorrecto: no se asignan cadenas a un char */
    /* Correcto: usar strcpy/strncpy si cabe en el buffer */
    strncpy(cad2, "Guatemala", sizeof(cad2) - 1);
    cad2[sizeof(cad2) - 1] = '\0';
    puts(cad2);

    return 0;
}


