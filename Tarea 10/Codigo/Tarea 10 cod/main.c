#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct Libro {
    int codigoLibro;
    char titulo[300];
    char nombreAutor[300];
    char descripcion[300];
    int anioPublicacion;
    float precioVenta;
    struct Libro* siguienteLibro;
    } Libro;


/* Prototipos de funciones de la lista */
    void agregarLibro(Libro** inicioLista);
    void imprimirCatalogo(Libro* inicioLista);
    void buscarPorTitulo(Libro* inicioLista);
    void buscarPorAutor(Libro* inicioLista);
    void ordenarPorPrecio(Libro* inicioLista);
    void eliminarLibro(Libro** inicioLista);
    void guardarEnDisco(Libro* inicioLista);
    void leerDeDisco(Libro** inicioLista);
    void liberarMemoria(Libro* inicioLista);

/* Prototipos de funciones de utilidad y validación  */
    void limpiarBuffer();
    int esSoloNumero(char* cadena);
    int esSoloLetrasYEspacios(char* cadena);
    void mostrarMenu();


    int main() {
    Libro* listaLibros = NULL; /*Puntero al inicio de la lista*/
    int opcionMenu;


    leerDeDisco(&listaLibros);

    do {
        mostrarMenu();

    /* Validación para la entrada del menú */
    if (scanf("%d", &opcionMenu) != 1) {
    printf("\n>> ERROR: Ingrese solo el numero de la opcion.\n");
    limpiarBuffer();
    opcionMenu = 0; /* Opción inválida*/
    } else {
    limpiarBuffer();
    }

    switch(opcionMenu) {
    case 1: agregarLibro(&listaLibros); break;
    case 2: imprimirCatalogo(listaLibros); break;
    case 3: buscarPorTitulo(listaLibros); break;
    case 4: buscarPorAutor(listaLibros); break;
    case 5:ordenarPorPrecio(listaLibros);
    printf("\n--- Inventario Ordenado por Precio ---\n");
    imprimirCatalogo(listaLibros);
    break;
    case 6: eliminarLibro(&listaLibros); break;
    case 7:guardarEnDisco(listaLibros);
    printf("\n--- Cambios Guardados con Éxito ---\n");
                        break;
    case 8:
    printf("\nCerrando sistema...\n");
    break;
    default: printf(">> Opcion no valida.\n");
                                                            }
    } while(opcionMenu != 8);

        liberarMemoria(listaLibros);
            return 0;
    }

    void mostrarMenu() {
        printf("\n\n");
        printf("\t==============================================\n");
        printf("\t||                                          ||\n");
        printf("\t||          Biblioteca Medina               ||\n");
        printf("\t||          Sistema de Libros               ||\n");
        printf("\t||                                          ||\n");
        printf("\t==============================================\n");
        printf("\t||                                          ||\n");
        printf("\t|| [1] Agregar Nuevo Libro                  ||\n");
        printf("\t|| [2] Ver Catalogo Completo                ||\n");
        printf("\t|| [3] Buscar por Titulo                    ||\n");
        printf("\t|| [4] Buscar por Autor                     ||\n");
        printf("\t|| [5] Ordenar Inventario (Precio)          ||\n");
        printf("\t|| [6] Eliminar un Libro                    ||\n");
        printf("\t|| [7] Guardar Cambios (Backup)             ||\n");
        printf("\t||                                          ||\n");
        printf("\t|| [8] SALIR                                ||\n");
        printf("\t||                                          ||\n");
        printf("\t==============================================\n");
        printf("\n\t>> Ingrese su opcion: ");
        }

void limpiarBuffer() {
    int c;
        while ((c = getchar()) != '\n' && c != EOF);
        }

        /* Valida si una cadena que solo sea para valores numericos */
        int esSoloNumero(char* cadena) {
        if (cadena[0] == '\0') return 0; /* Cadena vacía */
        for (int i = 0; cadena[i] != '\0'; i++) {
        /* Permite punto decimal para el precio*/
        if (!isdigit(cadena[i]) && (cadena[i] != '.')) {
        return 0;
            }
        }
            return 1;
    }

    int esSoloLetrasYEspacios(char* cadena) {
        if (cadena[0] == '\0') return 0;
            for (int i = 0; cadena[i] != '\0'; i++) {
                if (!isalpha(cadena[i]) && !isspace(cadena[i])) {
                return 0;
            }
        }
            return 1;
    }

    /* Función auxiliar para leer texto con validación numérica */
    int leerNumeroValidado(const char* mensaje) {
    char buffer[50];
    int numero;
    while (1) {
    printf("%s", mensaje);
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) continue;
    buffer[strcspn(buffer, "\n")] = 0;

    if (esSoloNumero(buffer)) {
    sscanf(buffer, "%d", &numero);
    return numero;
    } else {
    printf(">> ERROR: Ingrese solo valores numericos enteros.\n");
            }
        }
    }
    float leerPrecioValidado(const char* mensaje) {
    char buffer[50];
    float precio;
    while (1) {
    printf("%s", mensaje);
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) continue;
    buffer[strcspn(buffer, "\n")] = 0; /* Limpiar \n */

    if (esSoloNumero(buffer)) {
    sscanf(buffer, "%f", &precio);
    return precio;
    } else {
    printf(">> ERROR: Ingrese un valor numerico valido (ej: 15.50).\n");
                                                                            }
        }
    }

    /* Función auxiliar para leer texto con validación de solo letras */
    void leerAutorValidado(const char* mensaje, char* destino, size_t tamano) {
    while (1) {
    printf("%s", mensaje);
    if (fgets(destino, tamano, stdin) == NULL) continue;
    destino[strcspn(destino, "\n")] = 0;

    if (esSoloLetrasYEspacios(destino)) {
    break;
    } else {
    printf(">> ERROR: El autor debe contener solo letras y espacios.\n");
                }
            }
        }


    /* --- Implementación de Funciones de Lista Enlazada --- */

    /* 1. Agrega un nuevo libro a la lista usa malloc */
    void agregarLibro(Libro** inicioLista) {
    Libro* nuevoLibro = (Libro*)malloc(sizeof(Libro));
    if (nuevoLibro == NULL) {
    printf("Error: No hay memoria suficiente (malloc fallo).\n");
    return;
        }

    printf("\n--- AGREGAR NUEVO LIBRO ---\n");

    /* Lectura y validación de datos */
    nuevoLibro->codigoLibro = leerNumeroValidado("Ingrese Codigo del Libro: ");

    leerAutorValidado("Ingrese Nombre del Autor (Solo letras): ", nuevoLibro->nombreAutor, 300);

    printf("Ingrese Titulo: ");
    fgets(nuevoLibro->titulo, 300, stdin);
    nuevoLibro->titulo[strcspn(nuevoLibro->titulo, "\n")] = 0;

    printf("Ingrese Descripcion: ");
    fgets(nuevoLibro->descripcion, 300, stdin);
    nuevoLibro->descripcion[strcspn(nuevoLibro->descripcion, "\n")] = 0;

    nuevoLibro->anioPublicacion = leerNumeroValidado("Ingrese Anio de Publicacion: ");
    nuevoLibro->precioVenta = leerPrecioValidado("Ingrese Precio de Venta (ej: 25.00): ");

    nuevoLibro->siguienteLibro = *inicioLista;
    *inicioLista = nuevoLibro;

    printf("\n¡Libro agregado correctamente!\n");
        }

    void imprimirCatalogo(Libro* inicioLista) {
    if (inicioLista == NULL) {
    printf("\n--- EL CATALOGO ESTÁ VACÍO ---\n");
    return;
    }

    printf("\n\n");
    printf("========================================================================================\n");
    printf("| %-6s | %-30s | %-20s | %-6s | %-8s |\n",
    "CÓDIGO", "TÍTULO", "AUTOR", "AÑO", "PRECIO");
    printf("========================================================================================\n");

    Libro* actual = inicioLista;
    while (actual != NULL) {
    printf("| %-6d | %-30.30s | %-20.20s | %-6d | $%-7.2f |\n",
    actual->codigoLibro,
    actual->titulo,
    actual->nombreAutor,
    actual->anioPublicacion,
    actual->precioVenta);
    actual = actual->siguienteLibro;
        }
    printf("========================================================================================\n");
    }
    void buscarPorTitulo(Libro* inicioLista) {
    if (inicioLista == NULL) {
    printf("\nLa lista esta vacia.\n");
    return;
        }
    char busqueda[300];
    printf("\nIngrese el TITULO o parte del titulo a buscar: ");
    fgets(busqueda, 300, stdin);
    busqueda[strcspn(busqueda, "\n")] = 0;

    int encontrado = 0;
    Libro* actual = inicioLista;
    printf("\n--- RESULTADOS DE BÚSQUEDA POR TÍTULO ---\n");
    while (actual != NULL) {
    if (strstr(actual->titulo, busqueda) != NULL) {
    printf("ENCONTRADO -> Titulo: %s | Autor: %s | Codigo: %d\n",
    actual->titulo, actual->nombreAutor, actual->codigoLibro);
    encontrado = 1;
    }
    actual = actual->siguienteLibro;
        }
    if (!encontrado) printf("No se encontraron libros con ese titulo.\n");
    }
    void buscarPorAutor(Libro* inicioLista) {
    if (inicioLista == NULL) {
    printf("\nLa lista esta vacia.\n");
    return;
    }
    char busqueda[300];
    printf("\nIngrese el AUTOR o parte del autor a buscar: ");
    fgets(busqueda, 300, stdin);
    busqueda[strcspn(busqueda, "\n")] = 0;
    int encontrado = 0;
    Libro* actual = inicioLista;
    printf("\n--- RESULTADOS DE BÚSQUEDA POR AUTOR ---\n");
    while (actual != NULL) {
    if (strstr(actual->nombreAutor, busqueda) != NULL) {
    printf("ENCONTRADO -> Autor: %s | Titulo: %s | Codigo: %d\n",
    actual->nombreAutor, actual->titulo, actual->codigoLibro);
    encontrado = 1;
                    }
    actual = actual->siguienteLibro;
            }
    if (!encontrado) printf("No se encontraron libros de ese autor.\n");
        }

    void ordenarPorPrecio(Libro* inicioLista) {
    if (inicioLista == NULL || inicioLista->siguienteLibro == NULL) return;

    int intercambiado;
    Libro* puntero1;
    Libro* ultimoRevisado = NULL;

    do {
    intercambiado = 0;
    puntero1 = inicioLista;

    while (puntero1->siguienteLibro != ultimoRevisado) {
    if (puntero1->precioVenta > puntero1->siguienteLibro->precioVenta) {
    /* Intercambio de datos del struct */
    /* Guardar datos en el nodo actual en variables temporales */
    int temp_cod = puntero1->codigoLibro;
    int temp_anio = puntero1->anioPublicacion;
    float temp_precio = puntero1->precioVenta;
    char temp_tit[300], temp_aut[300], temp_desc[300];
    strcpy(temp_tit, puntero1->titulo);
    strcpy(temp_aut, puntero1->nombreAutor);
    strcpy(temp_desc, puntero1->descripcion);

    /* Copiar datos del nodo siguiente al nodo actual */
    puntero1->codigoLibro = puntero1->siguienteLibro->codigoLibro;
    puntero1->anioPublicacion = puntero1->siguienteLibro->anioPublicacion;
    puntero1->precioVenta = puntero1->siguienteLibro->precioVenta;
    strcpy(puntero1->titulo, puntero1->siguienteLibro->titulo);
    strcpy(puntero1->nombreAutor, puntero1->siguienteLibro->nombreAutor);
    strcpy(puntero1->descripcion, puntero1->siguienteLibro->descripcion);

    /* Copiar datos temporales al nodo siguiente */
    puntero1->siguienteLibro->codigoLibro = temp_cod;
    puntero1->siguienteLibro->anioPublicacion = temp_anio;
    puntero1->siguienteLibro->precioVenta = temp_precio;
    strcpy(puntero1->siguienteLibro->titulo, temp_tit);
    strcpy(puntero1->siguienteLibro->nombreAutor, temp_aut);
    strcpy(puntero1->siguienteLibro->descripcion, temp_desc);
    intercambiado = 1;
        }
    puntero1 = puntero1->siguienteLibro;
    }
    ultimoRevisado = puntero1;
    } while (intercambiado);
    }

    void eliminarLibro(Libro** inicioLista) {
    if (*inicioLista == NULL) {
    printf("\nLa lista esta vacia, no hay nada que eliminar.\n");
    return;
    }

    int codigoAEliminar = leerNumeroValidado("Ingrese el CODIGO del libro a eliminar: ");

    Libro* actual = *inicioLista;
    Libro* anterior = NULL;

    if (actual != NULL && actual->codigoLibro == codigoAEliminar) {
    *inicioLista = actual->siguienteLibro; /* La cabeza avanza*/
    free(actual); /* Liberamos la memoria */
    printf("Libro con codigo %d eliminado exitosamente.\n", codigoAEliminar);
    return;
                                }

    /* Caso 2: Buscar en el resto de la lista */
    while (actual != NULL && actual->codigoLibro != codigoAEliminar) {
    anterior = actual;
    actual = actual->siguienteLibro;
    }

    if (actual == NULL) {
    printf("No se encontro ningun libro con el codigo %d.\n", codigoAEliminar);
    return;
    }

    anterior->siguienteLibro = actual->siguienteLibro;
    free(actual); /* Libera la memoria */
    printf("Libro con codigo %d eliminado exitosamente.\n", codigoAEliminar);
    }

    void guardarEnDisco(Libro* inicioLista) {
    FILE* archivo = fopen("libros_inventario.txt", "w");
    if (archivo == NULL) {
    printf("Error: No se pudo abrir el archivo para guardar.\n");
    return;
    }

    Libro* actual = inicioLista;
    while (actual != NULL) {
    /* Guardamos en formato CSV simple (separado por |) */
    fprintf(archivo, "%d|%s|%s|%s|%d|%.2f\n",
    actual->codigoLibro, actual->titulo, actual->nombreAutor,
    actual->descripcion, actual->anioPublicacion, actual->precioVenta);
    actual = actual->siguienteLibro;
        }
    fclose(archivo);
    }

    void leerDeDisco(Libro** inicioLista) {
    FILE* archivo = fopen("libros_inventario.txt", "r");
    if (archivo == NULL) {
    printf("Archivo de inventario no encontrado. Se creara uno nuevo.\n");
    return;
    }
    /* Variables temporales para la lectura deben ser del mismo tamaño que en el struct. */
    int cod, anio;
    float pre;
    char tit[300], aut[300], des[300];
    char linea[1000]; // Buffer para leer la linea completa

    while (fgets(linea, sizeof(linea), archivo)) {
    /* Parsear la línea y extraer los valores*/
    sscanf(linea, "%d|%[^|]|%[^|]|%[^|]|%d|%f",
    &cod, tit, aut, des, &anio, &pre);

    Libro* nuevoNodo = (Libro*)malloc(sizeof(Libro));
    if (nuevoNodo == NULL) {
    printf("Error de memoria al cargar archivo.\n");
    break;
    }

    nuevoNodo->codigoLibro = cod;
    strcpy(nuevoNodo->titulo, tit);
    strcpy(nuevoNodo->nombreAutor, aut);
    strcpy(nuevoNodo->descripcion, des);
    nuevoNodo->anioPublicacion = anio;
    nuevoNodo->precioVenta = pre;

    nuevoNodo->siguienteLibro = *inicioLista;
    *inicioLista = nuevoNodo;
    }
    fclose(archivo);
    printf("Inventario cargado correctamente.\n");
        }

    void liberarMemoria(Libro* inicioLista) {
    Libro* actual = inicioLista;
    while (actual != NULL) {
    Libro* temporal = actual;
    actual = actual->siguienteLibro;
    free(temporal);
        }
    }




