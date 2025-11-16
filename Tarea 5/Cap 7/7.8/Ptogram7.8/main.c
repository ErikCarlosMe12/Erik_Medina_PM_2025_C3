#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Minúsculas y mayúsculas.
   Determina el número de minúsculas y mayúsculas en cada cadena. */

   void minymay(char *cad);  /* Prototipo corregido: puntero a char */

   int main(void)
   {

    int i, n;
    char FRA[20][50];

    printf("\nIngrese el número de filas del arreglo: ");
    scanf("%d", &n);
    if (n < 1) n = 1;
    if (n > 20) n = 20;

    /* limpiar '\n' pendiente antes de usar fgets */
    getchar();


    for (i = 0; i < n; i++) {
        printf("Ingrese la línea %d de temxto: ", i + 1);
        if (fgets(FRA[i], sizeof(FRA[i]), stdin)) {
            size_t L = strlen(FRA[i]);
                if (L && FRA[i][L - 1] == '\n') FRA[i][L - 1] = '\0';
            } else {
                FRA[i][0] = '\0';
        }
}

    printf("\n\n");
    for (i = 0; i < n; i++)
        minymay(FRA[i]);

    return 0;


   }

   void minymay(char *cadena)
   /* Calcula el número de minúsculas y mayúsculas de la cadena. */
   {

        int i = 0, mi = 0, ma = 0;

        while (cadena[i] != '\0') {
            unsigned char ch = (unsigned char)cadena[i];
            if (islower(ch))
                mi++;
            else if (isupper(ch))
                ma++;
            i++;
               }

    printf("\n\nNúmero de letras minúsculas: %d", mi);
    printf("\nNúmero de letras mayúsculas: %d", ma);
   }
