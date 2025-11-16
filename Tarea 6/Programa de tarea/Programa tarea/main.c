#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char nombre[50];
    int cantidad;
        float precio;
    } Producto;

/* === PROTOTIPOS DE FUNCIONES === */
Producto* cargarInventario(const char *nombreArchivo, int *n);
void guardarProducto(const char *nombreArchivo, Producto p);
void imprimirInventario(Producto *inv, int n);
Producto crearProducto();
void menu();

/* ============================================================
            FUNCIÓN 1: cargarInventario
    Lee el archivo y usa memoria dinámica para cargar los productos
============================================================ */
Producto* cargarInventario(const char *nombreArchivo, int *n) {
FILE *archivo = fopen(nombreArchivo, "r");
if (!archivo) {
*n = 0;
return NULL; // No existe el archivo aún
}

    Producto *inventario = NULL;
    Producto temp;
    *n = 0;

while (fscanf(archivo, "%49[^,],%d,%f\n", temp.nombre, &temp.cantidad, &temp.precio) == 3) {
inventario = realloc(inventario, (*n + 1) * sizeof(Producto));
inventario[*n] = temp;
(*n)++;
}

fclose(archivo);
return inventario;
}

/* ============================================================
                FUNCIÓN 2: guardarProducto
        Agrega un producto nuevo al archivo inventario.txt
   ============================================================ */

void guardarProducto(const char *nombreArchivo, Producto p) {
FILE *archivo = fopen(nombreArchivo, "a");
if (!archivo) {
printf("No se pudo abrir el archivo.\n");
return;
}

fprintf(archivo, "%s,%d,%.2f\n", p.nombre, p.cantidad, p.precio);
fclose(archivo);
}

/* ============================================================
        FUNCIÓN 3: imprimirInventario
    Imprime los productos cargados en memoria dinámica
   ============================================================ */
void imprimirInventario(Producto *inv, int n) {
if (n == 0) {
        printf("\nNo hay productos en el inventario.\n");
        return;
}

    printf("\n=== PRODUCTOS EN INVENTARIO ===\n");
        for (int i = 0; i < n; i++) {
                    printf("%d) %s | Cantidad: %d | Precio: %.2f\n",
                                          i + 1, inv[i].nombre, inv[i].cantidad, inv[i].precio);
        }
}

/* ============================================================
   FUNCIÓN 4: crearProducto
      Pide al usuario los datos del producto nuevo
         ============================================================ */
        Producto crearProducto() {
        Producto p;
        fflush(stdin);

        printf("Nombre del producto: ");
        fgets(p.nombre, 50, stdin);
        p.nombre[strcspn(p.nombre, "\n")] = '\0';

        printf("Cantidad: ");
        scanf("%d", &p.cantidad);

        printf("Precio: ");
        scanf("%f", &p.precio);

        fflush(stdin);
        return p;
    }


/* ============================================================
                FUNCIÓN PRINCIPAL DEL MENÚ
  ============================================================ */
void menu() {
    const char *archivo = "inventario.txt";
    int opcion, n;
    Producto *inv = NULL;

    do {
        printf("\n============ MENU INVENTARIO ============\n");
        printf("1. Cargar inventario desde archivo\n");
        printf("2. Agregar nuevo producto al inventario\n");
        printf("3. Imprimir inventario en pantalla\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

    switch (opcion) {
        case 1:
            inv = cargarInventario(archivo, &n);
            if (n > 0)
                printf("\nInventario cargado exitosamente (%d productos).\n", n);
            else
                printf("\nNo hay productos o el archivo no existe aún.\n");
            break;

        case 2: {
            Producto nuevo = crearProducto();
            guardarProducto(archivo, nuevo);
            printf("\nProducto guardado correctamente.\n");
            break;
    }

        case 3:
            inv = cargarInventario(archivo, &n);
            imprimirInventario(inv, n);
            free(inv);
            break;


        case 4:
            printf("\nSaliendo del programa...\n");
            break;



        default:
            printf("\nOpcion invalida, intente otra vez.\n");
    }

    } while (opcion != 4);
}

/* ============================================================
               FUNCIÓN MAIN
   ============================================================ */
    int main(){
    menu();
    return 0;
    }




