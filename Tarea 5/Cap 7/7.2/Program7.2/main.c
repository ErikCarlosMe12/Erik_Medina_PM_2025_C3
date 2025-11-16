#include <stdio.h>
#include <ctype.h>

/* Funciones para el manejo de caracteres de la biblioteca ctype.h. */
int main(void)
{

        char p1;

        printf("\nIngrese un caracter para analizar si éste es un dígito: ");
        p1 = getchar();
        if (isdigit(p1))
            /* isdigit regresa 1 si p1 es un dígito y 0 en caso contrario. */
            printf("%c es un dígito \n", p1);
        else
            printf("%c no es un dígito \n", p1);

        fflush(stdin);

        printf("\nIngrese un caracter para examinar si éste es una letra: ");
        p1 = getchar();
        if (isalpha(p1))
            /* isalpha regresa 1 si p1 es una letra y 0 en caso contrario. */
            printf("%c es una letra \n", p1);
        else
            printf("%c no es una letra \n", p1);

        fflush(stdin);

        printf("\nIngrese un caracter para examinar si éste es una letra minúscula: ");
        p1 = getchar();
        if (isalpha(p1))
            if (islower(p1))
                /* islower regresa 1 si p1 es minúscula. isupper lo es para mayúsculas. */
                printf("%c es una letra minúscula \n", p1);
        else
        printf("%c no es una letra minúscula \n", p1);
        else
        printf("%c no es una letra \n", p1);

    fflush(stdin);

    printf("\nIngrese una letra para convertirla de mayúscula a minúscula: ");
    p1 = getchar();
    if (isalpha(p1))
    if (isupper(p1))
            /* tolower convierte de mayúscula a minúscula. */
                                                                                                                            printf("%c fue convertida de mayúscula a minúscula \n", (char)tolower(p1));
        else
            printf("%c es una letra minúscula \n", p1);
        else
        printf("%c no es una letra \n", p1);

    return 0;
}

