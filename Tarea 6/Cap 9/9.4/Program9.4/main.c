#include <stdio.h>

/* Archivos y cadenas de caracteres.
   El programa lee cadenas de un archivo. */

   int main(void)
   {

    char cad[50];
        FILE *ap;

        ap = fopen("arc.txt", "r");  /* Abre archivo para lectura */

            if (ap != NULL)
            {

        /* Metodo CORRECTO: fgets() devuelve NULL al terminar el archivo */
                while (fgets(cad, 50, ap) != NULL)
        {

            puts(cad);
        }

            fclose(ap);
        }
        else
    {

        printf("No se puede abrir el archivo");
    }

        return 0;
   }


