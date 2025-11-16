#include <stdio.h>
#include <string.h>

/* Vendedores.
El programa maneja informacion de vendedores y sus ventas.
*/

typedef struct {
    char noba[10];   /* Nombre del banco */
    char nucu[10];   /* Numero de cuenta */
} banco;

typedef union {
    banco che;       /* Pago por cheque */
    banco nomi;      /* Pago por nomina */
    char venta;      /* Pago por ventanilla */
} fpago;

typedef struct {
    char cnu[20];    /* Calle y numero */
    char col[20];    /* Colonia */
    char cp[6];      /* Codigo Postal (5 chars + '\0') */
    char ciu[15];    /* Ciudad */
} domicilio;

typedef struct {
    int num;              /* Numero de vendedor */
    char nom[20];         /* Nombre del vendedor */
    float ven[12];        /* Ventas mensuales */
    domicilio domi;       /* Domicilio */
    float sal;            /* Salario mensual */
    fpago pago;           /* Forma de pago */
    int cla;              /* 1=Cheque, 2=Nomina, 3=Ventanilla */
} vendedor;


/*Prototipos */
void Lectura(vendedor *, int);
void F1(vendedor *, int);
void F2(vendedor *, int);
void F3(vendedor *, int);
void F4(vendedor *, int);

/* -------------------------------------------------------- */
/* MAIN                                                     */
/* -------------------------------------------------------- */
int main(void)
{

    vendedor VENDEDORES[100];
    int TAM;

    do {
        printf("Ingrese el numero de vendedores: ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);

    Lectura(VENDEDORES, TAM);
    F1(VENDEDORES, TAM);
    F2(VENDEDORES, TAM);
    F3(VENDEDORES, TAM);
    F4(VENDEDORES, TAM);

    printf("\n\tFIN DEL PROGRAMA\n");
    return 0;
}

/* -------------------------------------------------------- */
/* LECTURA                                                  */
/* -------------------------------------------------------- */
void Lectura(vendedor A[], int T)
{

    int I, J;

    for (I = 0; I < T; I++) {

        printf("\n\tIngrese datos del vendedor %d\n", I + 1);

        printf("Numero de vendedor: ");
        scanf("%d", &A[I].num);

        printf("Nombre del vendedor: ");
        scanf(" %19[^\n]", A[I].nom);

        printf("Ventas del año\n");
        for (J = 0; J < 12; J++) {
            printf("\tMes %d: ", J + 1);
            scanf("%f", &A[I].ven[J]);
        }

        printf("Domicilio:\n");

        printf("\tCalle y numero: ");
        scanf(" %19[^\n]", A[I].domi.cnu);

        printf("\tColonia: ");
        scanf(" %19[^\n]", A[I].domi.col);

        printf("\tCodigo Postal: ");
        scanf(" %5s", A[I].domi.cp);

        printf("\tCiudad: ");
        scanf(" %14[^\n]", A[I].domi.ciu);

        printf("Salario mensual: ");
        scanf("%f", &A[I].sal);

        printf("Forma de Pago (1=Banco Cheque, 2=Nomina, 3=Ventanilla): ");
        scanf("%d", &A[I].cla);

        switch (A[I].cla) {

        case 1:
                printf("\tNombre del banco: ");
                scanf(" %9[^\n]", A[I].pago.che.noba);

                printf("\tNumero de cuenta: ");
                scanf(" %9[^\n]", A[I].pago.che.nucu);
                break;

        case 2:
                printf("\tNombre del banco: ");
                scanf(" %9[^\n]", A[I].pago.nomi.noba);

                printf("\tNumero de cuenta: ");
                scanf(" %9[^\n]", A[I].pago.nomi.nucu);
                break;

        case 3:
                A[I].pago.venta = 'S';
                break;

        default:
                printf("\tForma de pago invalida.\n");
        }
    }
}

/* -------------------------------------------------------- */
/* F1 – Ventas anuales                                      */
/* -------------------------------------------------------- */
void F1(vendedor A[], int T)
{

    int I, J;
    float SUM;

    printf("\n\tVENTAS TOTALES ANUALES\n");

     for (I = 0; I < T; I++) {

        SUM = 0.0;
        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];

        printf("\nVendedor: %d\nVentas: %.2f\n", A[I].num, SUM);
 }
}

/* -------------------------------------------------------- */
/* F2 – Aumento del 5%                                      */
/* -------------------------------------------------------- */
void F2(vendedor A[], int T)
{

    int I, J;
    float SUM;

    printf("\n\tINCREMENTO A VENDEDORES (> 1,500,000)\n");

    for (I = 0; I < T; I++) {

        SUM = 0.0;
        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];

        if (SUM > 1500000.0) {
            A[I].sal *= 1.05;
            printf("\nEmpleado: %d\nVentas: %.2f\nNuevo salario: %.2f\n",
                A[I].num, SUM, A[I].sal);
        }
    }
}

/* -------------------------------------------------------- */
/* F3 – Ventas < 300,000                                     */
/* -------------------------------------------------------- */
void F3(vendedor A[], int T)
{

    int I, J;
    float SUM;

    printf("\n\tVENDEDORES CON VENTAS < 300,000\n");

    for (I = 0; I < T; I++) {

        SUM = 0.0;
        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];

        if (SUM < 300000.0)
            printf("\nEmpleado: %d\nNombre: %s\nVentas: %.2f\n",
                  A[I].num, A[I].nom, SUM);
        }
}

/* -------------------------------------------------------- */
/* F4 – Vendedores con cuenta de banco (cheque)             */
/* -------------------------------------------------------- */
void F4(vendedor A[], int T)
{

    int I;

    printf("\n\tVENDEDORES CON CUENTA BANCARIA (CHEQUE)\n");

    for (I = 0; I < T; I++) {

        if (A[I].cla == 1)
            printf("\nVendedor: %d\nBanco: %s\nCuenta: %s\n",
                   A[I].num,
                   A[I].pago.che.noba,
                   A[I].pago.che.nucu);
        }
    }



