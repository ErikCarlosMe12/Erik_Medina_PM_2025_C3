#include <stdio.h>
#include <ctype.h>
#include <string.h>



/* Decodifica.
El programa decodifica una cadena de caracteres compuesta por números y letras. */
void interpreta(char *); /* Prototipo de función. */

int main(void)
{

char cad[50];

printf("\nIngrese la cadena de caracteres: ");
    if (fgets(cad, sizeof(cad), stdin)) {
    size_t L = strlen(cad);
    if (L && cad[L - 1] == '\n') cad[L - 1] = '\0';
    } else {
            cad[0] = '\0';
        }

    interpreta(cad);
    return 0;
}

void interpreta(char *cadena)
/* Decodifica: repite cada letra tantas veces como indique el dígito anterior. */
{

    int i = 0, j, k;

    while (cadena[i] != '\0') {
        unsigned char ch = (unsigned char)cadena[i];

        if (isalpha(ch)) {  /* Es una letra */
        /* Si el carácter previo es dígito, úsalo; si no, repite 1 vez. */
            if (i > 0 && isdigit((unsigned char)cadena[i - 1]))
                k = cadena[i - 1] - '0';
            else
                k = 1;

            for (j = 0; j < k; j++)
                putchar(ch);
        }
            i++;
}
        putchar('\n');
}
