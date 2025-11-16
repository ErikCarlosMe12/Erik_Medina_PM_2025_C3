#include <stdio.h>
#include <string.h>


int longitud(char *cad); /* Prototipo de función. */

int main(void)
{

    int i, n, l = -1, p = 0, t;
    char cad[50], FRA[20][50];

    printf("\nIngrese el número de filas del arreglo: ");
    scanf("%d", &n);
    if (n < 1) n = 1;
    if (n > 20) n = 20;
    getchar(); /* limpia '\n' pendiente */

    for (i = 0; i < n; i++)
    {

    printf("Ingrese la línea %d Mde texto. Máximo 50 caracteres: ", i + 1);
    if (fgets(FRA[i], sizeof(FRA[i]), stdin)) {
        size_t L = strlen(FRA[i]);
        if (L && FRA[i][L - 1] == '\n') FRA[i][L - 1] = '\0';
            } else {
            FRA[i][0] = '\0';
        }
    }

    printf("\n");
        for (i = 0; i < n; i++)
        {

        strcpy(cad, FRA[i]);   /* <-- I mayúscula corregida a i */
        t = longitud(cad);
        if (t > l) { l = t; p = i; }
            }

        printf("\nLa cadena con mayor longitud es: ");
        puts(FRA[p]);
        printf("\nLongitud: %d", l);

        return 0;
}

int longitud(char *cadena)
/* Calcula la longitud de la cadena (equivalente a strlen). */
{

    int cue = 0;
    while (cadena[cue] != '\0')
        cue++;
    return cue;
}
