#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cancion {
    int id;
    char nombre[64];
    int segundos;
    struct Cancion* sig;
}   Cancion;

Cancion* crear_cancion(int id, const char* nombre, int segundos) {
    Cancion* n = (Cancion*)malloc(sizeof(Cancion));
    if (!n) return NULL;
    n->id = id;
    strncpy(n->nombre, nombre, sizeof(n->nombre) - 1);
    n->nombre[sizeof(n->nombre) - 1] = '\0';
    n->segundos = segundos;
    n->sig = NULL;
    return n;
}

void agregar_final(Cancion** head, int id, const char* nombre, int segundos) {
    Cancion* n = crear_cancion(id, nombre, segundos);
    if (!n) { printf("Sin memoria.\n"); return; }

    if (*head == NULL) { *head = n; return; }
    Cancion* p = *head;
    while (p->sig) p = p->sig;
    p->sig = n;
}

int eliminar_por_id(Cancion** head, int id) {
    Cancion* act = *head;
    Cancion* ant = NULL;

    while (act && act->id != id) { ant = act; act = act->sig; }
    if (!act) return 0;

    if (!ant) *head = act->sig;
    else ant->sig = act->sig;

    free(act);
    return 1;
}

int duracion_total(Cancion* head) {
    int total = 0;
    for (Cancion* p = head; p; p = p->sig) total += p->segundos;
    return total;
    }



    void imprimir(Cancion* head) {
        printf("Playlist:\n");
        for (Cancion* p = head; p; p = p->sig)
        printf("  [%d] %s (%d s)\n", p->id, p->nombre, p->segundos);


    }

    void liberar(Cancion* head) {
        while (head) {
            Cancion* tmp = head;
            head = head->sig;
            free(tmp);
        }
    }

    int main(void) {
        Cancion* playlist = NULL;

        agregar_final(&playlist, 1, "Intro", 45);
        agregar_final(&playlist, 2, "Tema principal", 210);
        agregar_final(&playlist, 3, "Final", 160);

        imprimir(playlist);
        printf("Duracion total: %d s\n", duracion_total(playlist));

        printf("\nEliminar id=2: %s\n", eliminar_por_id(&playlist, 2) ? "OK" : "NO");
        imprimir(playlist);
        printf("Duracion total: %d s\n", duracion_total(playlist));

        liberar(playlist);
        return 0;
}

