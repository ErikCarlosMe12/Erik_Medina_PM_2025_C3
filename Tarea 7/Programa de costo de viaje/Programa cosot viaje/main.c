#include <stdio.h>
#include <string.h>


#define MAX_VEH 50
#define MAX_COMB 10

// ---------------------- ESTRUCTURAS -------------------------

typedef struct {
    int id;
    char marca[20];
    char modelo[20];
    int ano;
    char placa[10];
    float consumoCiudad;     // L/100km
    float consumoCarretera;  // L/100km
    float costoSeguroAnual;
    float costoCambioKm;
    int tiempoDepreciacion;  // años
    float costoVehiculo;
    float costoLimpieza;
    float kmPromedioAnual;
} Vehiculo;


typedef struct {
    int id;
    char nombre[20];
    float precioLitro;
} Combustible;


// ---------------------- PROTOTIPOS --------------------------
void menu();
void agregarVehiculo();
void listarVehiculos();
void modificarVehiculo();

void agregarCombustible();
void listarCombustibles();
void modificarCombustible();

void calcularViaje();

// ---------------------- VARIABLES GLOBALES -------------------
Vehiculo veh[MAX_VEH];
Combustible comb[MAX_COMB];
int cantVeh = 0;
int cantComb = 0;

// ---------------------- MAIN -------------------------------
int main() {
    menu();
    return 0;
}


// ---------------------- MENU PRINCIPAL ---------------------
void menu() {
    int op;

    do {
        printf("\n\n====== SISTEMA COSTO DE VIAJE ======\n");
        printf("1. Agregar Vehiculo\n");
        printf("2. Listar Vehiculos\n");
        printf("3. Modificar Vehiculo\n");
        printf("4. Agregar Combustible\n");
        printf("5. Modificar Combustible\n");
        printf("6. Listar Combustible\n");
        printf("7. Calcular Viaje\n");
        printf("0. Salir\n");
        printf("Seleccione opcion: ");
        scanf("%d", &op);

        switch (op) {
            case 1: agregarVehiculo(); break;
            case 2: listarVehiculos(); break;
            case 3: modificarVehiculo(); break;
            case 4: agregarCombustible(); break;
            case 5: modificarCombustible(); break;
            case 6: listarCombustibles(); break;
            case 7: calcularViaje(); break;
        }

    } while (op != 0);
}

// -----------------------------------------------------------
//             FUNCIONES DE VEHICULOS
// -----------------------------------------------------------

void agregarVehiculo() {
    if (cantVeh >= MAX_VEH) {
        printf("Limite de vehiculos alcanzado.\n");
        return;
    }

    Vehiculo v;

    printf("\n=== Agregar Vehiculo ===\n");
    v.id = cantVeh + 1;

    printf("Marca: "); scanf("%s", v.marca);
    printf("Modelo: "); scanf("%s", v.modelo);
    printf("Ano: "); scanf("%d", &v.ano);
    printf("Placa: "); scanf("%s", v.placa);
    printf("Consumo Ciudad (L/100km): "); scanf("%f", &v.consumoCiudad);
    printf("Consumo Carretera (L/100km): "); scanf("%f", &v.consumoCarretera);
    printf("Costo Seguro Anual: "); scanf("%f", &v.costoSeguroAnual);
    printf("Costo Cambio por Km: "); scanf("%f", &v.costoCambioKm);
    printf("Tiempo de Depreciacion (anos): "); scanf("%d", &v.tiempoDepreciacion);
    printf("Costo Vehiculo: "); scanf("%f", &v.costoVehiculo);
    printf("Km Promedio Anual: "); scanf("%f", &v.kmPromedioAnual);
    printf("Costo Limpieza: "); scanf("%f", &v.costoLimpieza);

    veh[cantVeh] = v;
    cantVeh++;

    printf("\nVehiculo agregado correctamente.\n");
}

void listarVehiculos() {
    printf("\n=== Lista de Vehiculos ===\n");
        for (int i = 0; i < cantVeh; i++) {
        printf("\nID: %d | %s %s (%d)\n", veh[i].id, veh[i].marca, veh[i].modelo, veh[i].ano);
        printf("Placa: %s\n", veh[i].placa);
        printf("Consumo Ciudad: %.2f L/100km\n", veh[i].consumoCiudad);
        printf("Consumo Carretera: %.2f L/100km\n", veh[i].consumoCarretera);
        }
}


void modificarVehiculo() {
    int id;
    listarVehiculos();

    printf("\nIngrese ID del vehiculo a modificar: ");
    scanf("%d", &id);

    if (id < 1 || id > cantVeh) {
        printf("ID invalido.\n");
        return;
    }

    Vehiculo *v = &veh[id - 1];

    printf("\nModificando vehiculo %d\n", v->id);
    printf("Nueva Marca: "); scanf("%s", v->marca);
    printf("Nuevo Modelo: "); scanf("%s", v->modelo);
    printf("Nuevo Ano: "); scanf("%d", &v->ano);
}


// ---------------------------------------------------------
//             FUNCIONES DE COMBUSTIBLE
// -----------------------------------------------------------

void agregarCombustible() {
    if (cantComb >= MAX_COMB) {
        printf("Limite de combustibles alcanzado.\n");
        return;
    }

    Combustible c;
    c.id = cantComb + 1;

    printf("\n=== Agregar Combustible ===\n");
    printf("Nombre: "); scanf("%s", c.nombre);
    printf("Precio por Litro: "); scanf("%f", &c.precioLitro);

    comb[cantComb] = c;
    cantComb++;

    printf("Combustible agregado.\n");
}


void listarCombustibles() {
    printf("\n=== Lista de Combustibles ===\n");
    for (int i = 0; i < cantComb; i++) {
        printf("\nID: %d | %s | %.2f$/L\n", comb[i].id, comb[i].nombre, comb[i].precioLitro);
    }
}


void modificarCombustible() {
    int id;
    listarCombustibles();

    printf("\nIngrese ID de combustible a modificar: ");
    scanf("%d", &id);

    if (id < 1 || id > cantComb) {
        printf("ID invalido.\n");
        return;
    }

    Combustible *c = &comb[id - 1];

    printf("Nuevo Nombre: "); scanf("%s", c->nombre);
    printf("Nuevo Precio por litro: "); scanf("%f", &c->precioLitro);
}


// -----------------------------------------------------------
//                 CALCULO DE VIAJE
// -----------------------------------------------------------

void calcularViaje() {
    int idVeh, idComb;
    float km, porcCiudad;

    listarVehiculos();
    printf("\nSeleccione ID de vehiculo: ");
    scanf("%d", &idVeh);

    listarCombustibles();
    printf("\nSeleccione ID de combustible: ");
    scanf("%d", &idComb);

    printf("\nCantidad total de KM del viaje: ");
    scanf("%f", &km);

    printf("Porcentaje KM en ciudad (0-100): ");
    scanf("%f", &porcCiudad);

    Vehiculo v = veh[idVeh - 1];
    Combustible c = comb[idComb - 1];

    float kmCiudad = km * (porcCiudad / 100);
    float kmCarretera = km - kmCiudad;

    float litrosCiudad = (v.consumoCiudad / 100) * kmCiudad;
    float litrosCarretera = (v.consumoCarretera / 100) * kmCarretera;

    float costoCombustible = (litrosCiudad + litrosCarretera) * c.precioLitro;

    float depreciacionAnual = v.costoVehiculo / v.tiempoDepreciacion;
    float depreciacionPorKm = depreciacionAnual / v.kmPromedioAnual;
    float costoDepreciacion = depreciacionPorKm * km;

    float costoSeguro = (v.costoSeguroAnual / v.kmPromedioAnual) * km;
    float costoCambio = v.costoCambioKm * km;

    float costoTotal = costoCombustible + costoDepreciacion + costoSeguro + costoCambio + v.costoLimpieza;

    printf("\n======= RESULTADOS =======\n");
    printf("Costo de Combustible: %.2f\n", costoCombustible);
    printf("Costo de Depreciacion: %.2f\n", costoDepreciacion);
    printf("Costo de Seguro: %.2f\n", costoSeguro);
    printf("Costo de Mantenimiento: %.2f\n", costoCambio);
    printf("Costo de Limpieza: %.2f\n", v.costoLimpieza);

    printf("\nCOSTO TOTAL DEL VIAJE: %.2f\n", costoTotal);
    printf("COSTO POR KM: %.2f\n", costoTotal / km);
}




