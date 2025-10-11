#include <stdio.h>


/* Busqueda binaria. */
#define MAX 100

void Lectura(int *A, int T);   /* Prototipos de funciones. */
int Binaria(int *A, int T , int E);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];
    do{
        printf("Ingrese el tamaño del arreglo (1-%d): ", MAX);
        if(scanf("%d", &TAM) != 1){
                printf("Entrada invalida.\n");
                return 0;

    }

    } while (TAM > MAX || TAM < 1); /* Se verifica que el tamaño del arreglo se correcto. */

    Lectura(VEC, TAM);
    printf("\nIngrese el elemento a buscar: ");

    scanf("%d", &ELE);

    RES = Binaria(VEC, TAM, ELE); /* Se llama a la funcion que busca en el arreglo. */
    if (RES)
        /* Si RES tiene un valor verdadero -diferente de 0-, se escribe la posicion
        en la que se encontro el elemento. */
        printf("\nEl elemento se ecuentra en la posicion: %d\n ", RES);
    else
        printf("\nEl elemento nose encuentra en el arreglo\n");
        return 0;

}


void Lectura(int A[], int T)
/* La funcion Lectura se utiliza para leer un arreglo unidimensional de T
elementos de tipo entero. */

{
    int I;
    for (I=0; I<T; I++){
        printf("Ingrese el elemento %d: ", I+1);
        scanf("%d ", &A[I]);
    }
}

int Binaria(int A[], int T, int E)
/* Esta funcion se utiliza para realizar una busqueda binaria del elemento
E en el arreglo unidimensional A de T elementos. Si se encuentra el elemento,
la funcion regresa la posicion correspondiente. En caso contrario, regresa 0. */

{
    int IZQ = 0, DER =  T-1;

    while (IZQ <= DER){
           int CEN = (IZQ + DER) / 2;


    if (E == A[CEN]){
            return CEN + 1;

        } else if (E > A[CEN]) {
            IZQ = CEN + 1;

        } else {
            DER = CEN - 1;

        }

    }
    return 0;
}


