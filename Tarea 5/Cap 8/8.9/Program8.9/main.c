#include <stdio.h>
#include <string.h>

/* Bienes raices.
El programa maneja informacion sobre las propiedades que tiene una empresa
de bienes raices de Lima, Peru. */


typedef struct {
    char zona[20];
    char calle[20];
    char colo[20];
} ubicacion;

typedef struct {
    char clave[6];       /* 5 chars + '\0' */
    float scu;           /* Superficie cubierta */
    float ste;           /* Superficie terreno */
    char car[50];        /* Caracteristicas */
    ubicacion ubi;       /* Datos de ubicacion */
    float precio;
    char dispo;          /* 'V' Venta, 'R' Renta */
} propiedades;

/* Prototipos */
void Lectura(propiedades *, int);
void F1(propiedades *, int);
void F2(propiedades *, int);

int main(void)
{

    propiedades PROPIE[100];
    int TAM;

    do {
        printf("Ingrese el numero de propiedades: ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);

    Lectura(PROPIE, TAM);
    F1(PROPIE, TAM);
    F2(PROPIE, TAM);

    return 0;
}

/* --------------------------------------------------------- */
/* LECTURA                                                   */
/* --------------------------------------------------------- */
void Lectura(propiedades A[], int T)
{

    int I;

    for (I = 0; I < T; I++) {

        printf("\n\tIngrese datos de la propiedad %d\n", I + 1);

        printf("Clave: ");
        scanf(" %5s", A[I].clave);

        printf("Superficie cubierta: ");
        scanf("%f", &A[I].scu);

        printf("Superficie terreno: ");
        scanf("%f", &A[I].ste);

        printf("Caracteristicas: ");
        scanf(" %49[^\n]", A[I].car);

        printf("Zona: ");
        scanf(" %19[^\n]", A[I].ubi.zona);

        printf("Calle: ");
        scanf(" %19[^\n]", A[I].ubi.calle);

        printf("Colonia: ");
        scanf(" %19[^\n]", A[I].ubi.colo);

        printf("Precio: ");
        scanf("%f", &A[I].precio);

        printf("Disponibilidad (V = Venta, R = Renta): ");
        scanf(" %c", &A[I].dispo);
    }
}

/* --------------------------------------------------------- */
/* F1 - Lista propiedades EN VENTA en Miraflores             */
/* dentro de 450,000 a 650,000                                */
/* --------------------------------------------------------- */
void F1(propiedades A[], int T)
{

    int I;

    printf("\n\tLISTADO DE PROPIEDADES EN VENTA EN MIRAFLORES\n");

    for (I = 0; I < T; I++) {

        if (A[I].dispo == 'V' &&
            strcmp(A[I].ubi.zona, "Miraflores") == 0 &&
            A[I].precio >= 450000 &&
            A[I].precio <= 650000)
        {

            printf("\nClave: %s", A[I].clave);
            printf("\nSuperficie cubierta: %.2f", A[I].scu);
            printf("\nSuperficie terreno: %.2f", A[I].ste);
            printf("\nCaracteristicas: %s", A[I].car);
            printf("\nCalle: %s", A[I].ubi.calle);
            printf("\nColonia: %s", A[I].ubi.colo);
            printf("\nPrecio: %.2f\n", A[I].precio);
        }
    }
}

/* --------------------------------------------------------- */
/* F2 - Listado de propiedades EN RENTA por zona y rango     */
/* --------------------------------------------------------- */
void F2(propiedades A[], int T)
{

    int I;
    float li, ls;
    char zon[20];

    printf("\n\tLISTADO DE PROPIEDADES PARA RENTA\n");

    printf("Ingrese zona geografica: ");
    scanf(" %19[^\n]", zon);

    printf("Ingrese limite inferior del precio: ");
    scanf("%f", &li);

    printf("Ingrese limite superior del precio: ");
    scanf("%f", &ls);

    for (I = 0; I < T; I++) {

        if (A[I].dispo == 'R'&&
            strcmp(A[I].ubi.zona, zon) == 0 &&
            A[I].precio >= li &&
            A[I].precio <= ls)
        {

            printf("\nClave: %s", A[I].clave);
            printf("\nSuperficie cubierta: %.2f", A[I].scu);
            printf("\nSuperficie terreno: %.2f", A[I].ste);
            printf("\nCaracteristicas: %s", A[I].car);
            printf("\nCalle: %s", A[I].ubi.calle);
            printf("\nColonia: %s", A[I].ubi.colo);
            printf("\nPrecio: %.2f\n", A[I].precio);
        }
    }
}

