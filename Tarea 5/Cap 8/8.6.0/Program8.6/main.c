#include <stdio.h>
#include <string.h>

/* Comercializadora farmacéutica */

typedef struct {
    int clave;
    char nombre[15];
    float precio;
    int existencia;
} producto;

/* Prototipos */
void Lectura(producto *, int);
void Ventas(producto *, int);
void Reabastecimiento(producto *, int);
void Nuevos_Productos(producto *, int *);
void Inventario(producto *, int);

int main(void)
{

    producto INV[100];
    int TAM, OPE;

    do {
        printf("Ingrese el numero de productos: ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);   /* || corregido */

    Lectura(INV, TAM);
    printf("\nIngrese operacion: \n"
           "1 - Ventas\n"
           "2 - Reabastecimiento\n"
           "3 - Nuevos Productos\n"
           "4 - Inventario\n"
           "0 - Salir\n> ");
    scanf("%d", &OPE);

    while (OPE) {
        switch (OPE) {
            case 1: Ventas(INV, TAM); break;
            case 2: Reabastecimiento(INV, TAM); break;
            case 3: Nuevos_Productos(INV, &TAM); break;
            case 4: Inventario(INV, TAM); break;
            default: printf("Opcion invalida\n");
        }

        printf("\nIngrese operacion: \n"
               "1 - Ventas\n"
               "2 - Reabastecimiento\n"
               "3 - Nuevos Productos\n"
               "4 - Inventario\n"
               "0 - Salir\n> ");
        scanf("%d", &OPE);
    }

        return 0;
}


/* --------------------------------------- */
/* LECTURA                                 */
/* --------------------------------------- */
void Lectura(producto A[], int T)
{

    int I;
    for (I = 0; I < T; I++) {
        printf("\nIngrese informacion del producto %d\n", I + 1);

        printf("Clave: ");
        scanf("%d", &A[I].clave);

        printf("Nombre: ");
        scanf(" %14[^\n]", A[I].nombre);   // reemplazo de gets()

        printf("Precio: ");
        scanf("%f", &A[I].precio);

        printf("Existencia: ");
        scanf("%d", &A[I].existencia);
    }
}

/* --------------------------------------- */
/* VENTAS                                  */
/* --------------------------------------- */
void Ventas(producto A[], int T)
{

    int CLA, CAN, I, RES;
    float TOT = 0.0, PAR;

    printf("\nIngrese clave del producto (-0 para salir): ");
    scanf("%d", &CLA);

    while (CLA) {
        printf("\tCantidad: ");
        scanf("%d", &CAN);

        I = 0;
        while (I < T && A[I].clave < CLA)
            I++;

        if (I == T || A[I].clave > CLA)
            printf("\nLa clave del producto es incorrecta\n");
        else if (A[I].existencia >= CAN) {
            A[I].existencia -= CAN;
            PAR = A[I].precio * CAN;
            TOT += PAR;
        } else {
            printf("\nNo existe la cantidad solicitada. Solo hay %d\n",
                   A[I].existencia);

            printf("¿Desea llevar los disponibles? (1=Si / 0=No): ");
            scanf("%d", &RES);

            if (RES) {
                PAR = A[I].precio * A[I].existencia;
                A[I].existencia = 0;
                TOT += PAR;
            }
        }

                printf("\nIngrese la siguiente clave del producto (0 para salir): ");
        scanf("%d", &CLA);
    }

        printf("\nTotal de la venta: %.2f\n", TOT);
}

/* --------------------------------------- */
/* REABASTECIMIENTO                        */
/* --------------------------------------- */
void Reabastecimiento(producto A[], int T)
{

    int CLA, CAN, I;

    printf("\nIngrese clave del producto (0 para salir): ");
    scanf("%d", &CLA);

    while (CLA) {
        I = 0;
        while (I < T && A[I].clave < CLA)
            I++;

        if (I == T || A[I].clave > CLA)
            printf("\nLa clave ingresada es incorrecta\n");
        else {
            printf("\tCantidad a agregar: ");
            scanf("%d", &CAN);
            A[I].existencia += CAN;
        }

        printf("\nIngrese otra clave (0 para salir): ");
        scanf("%d", &CLA);
    }
}

/* --------------------------------------- */
/* NUEVOS PRODUCTOS                        */
/* --------------------------------------- */
void Nuevos_Productos(producto A[], int *T)
{

        int CLA, I, J;

    printf("\nIngrese clave del nuevo producto (0 para salir): ");
    scanf("%d", &CLA);

    while (*T < 30 && CLA) {

        I = 0;
        while (I < *T && A[I].clave < CLA)
            I++;

        if (I < *T && A[I].clave == CLA) {
            printf("\nEl producto ya existe en el inventario\n");
        }
        else {
            for (J = *T; J > I; J--)
            A[J] = A[J - 1];

            A[I].clave = CLA;

            printf("Nombre: ");
            scanf(" %14[^\n]", A[I].nombre);

            printf("Precio: ");
            scanf("%f", &A[I].precio);

            printf("Cantidad: ");
            scanf("%d", &A[I].existencia);

            (*T)++;
        }

        printf("\nIngrese otra clave (0 para salir): ");
        scanf("%d", &CLA);
    }

        if (*T == 30)
        printf("\nInventario lleno, no se pueden agregar mas productos\n");
}

/* --------------------------------------- */
/* INVENTARIO                              */
/* --------------------------------------- */
void Inventario(producto A[], int T)
{

    int I;
    for (I = 0; I < T; I++) {
        printf("\nClave: %d", A[I].clave);
        printf("\tNombre: %s", A[I].nombre);
        printf("\tPrecio: %.2f", A[I].precio);
        printf("\tExistencia: %d\n", A[I].existencia);
    }
}


