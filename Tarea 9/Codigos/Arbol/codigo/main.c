#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    char nombre[64];
    char telefono[32];
    struct Nodo* izq;
    struct Nodo* der;
    } Nodo;

Nodo* nuevo_contacto(const char* nombre, const char* tel) {
    Nodo* n = (Nodo*)malloc(sizeof(Nodo));
    if (!n) return NULL;
    strncpy(n->nombre, nombre, sizeof(n->nombre) - 1);
    n->nombre[sizeof(n->nombre) - 1] = '\0';
    strncpy(n->telefono, tel, sizeof(n->telefono) - 1);
    n->telefono[sizeof(n->telefono) - 1] = '\0';
    n->izq = n->der = NULL;
    return n;
}

Nodo* insertar(Nodo* r, const char* nombre, const char* tel) {
    if (!r) return nuevo_contacto(nombre, tel);

    int cmp = strcmp(nombre, r->nombre);
    if (cmp < 0) r->izq = insertar(r->izq, nombre, tel);
    else if (cmp > 0) r->der = insertar(r->der, nombre, tel);
    else {
            // si existe, actualiza telefono
            strncpy(r->telefono, tel, sizeof(r->telefono) - 1);
            r->telefono[sizeof(r->telefono) - 1] = '\0';
    }
        return r;
}

Nodo* buscar(Nodo* r, const char* nombre) {
    if (!r) return NULL;
        int cmp = strcmp(nombre, r->nombre);
    if (cmp == 0) return r;
    if (cmp < 0) return buscar(r->izq, nombre);
    return buscar(r->der, nombre);
}

void inorden(Nodo* r) {
    if (!r) return;
    inorden(r->izq);
    printf("  %-12s -> %s\n", r->nombre, r->telefono);
    inorden(r->der);
}

void liberar(Nodo* r) {
    if (!r) return;
        liberar(r->izq);
        liberar(r->der);
        free(r);
}

int main(void) {
    Nodo* agenda = NULL;

    agenda = insertar(agenda, "Ana", "809-111-1111");
    agenda = insertar(agenda, "Luis", "829-222-2222");
    agenda = insertar(agenda, "Carlos", "849-333-3333");
    agenda = insertar(agenda, "Bea", "809-444-4444");

    printf("Agenda (alfabetica):\n");
    inorden(agenda);

    printf("\nBuscar 'Luis':\n");
    Nodo* c = buscar(agenda, "Luis");
    if (c) printf("  Encontrado: %s -> %s\n", c->nombre, c->telefono);
    else printf("  No encontrado\n");

    liberar(agenda);
    return 0;
}

