#include <stdio.h>
#include <stdlib.h>

typedef struct NodoAdj {
    int v;
    struct NodoAdj* sig;
} NodoAdj;

typedef struct {
    int n;
    NodoAdj** adj; // array de listas
    } Grafo;

    NodoAdj* crear_nodo_adj(int v) {
    NodoAdj* n = (NodoAdj*)malloc(sizeof(NodoAdj));
    if (!n) return NULL;
    n->v = v;
    n->sig = NULL;
    return n;
    }

    Grafo* crear_grafo(int n) {
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
        if (!g) return NULL;
        g->n = n;
        g->adj = (NodoAdj**)calloc(n, sizeof(NodoAdj*));
        if (!g->adj) {
        free(g);
        return NULL;
        }
        return g;
    }

    void agregar_arista(Grafo* g, int a, int b) {
        if (!g) return;
        if (a < 0 || a >= g->n || b < 0 || b >= g->n) return;

        NodoAdj* nb = crear_nodo_adj(b);
        nb->sig = g->adj[a];
        g->adj[a] = nb;

        NodoAdj* na = crear_nodo_adj(a);
        na->sig = g->adj[b];
        g->adj[b] = na;
        }

        void imprimir_grafo(Grafo* g) {
        for (int i = 0; i < g->n; i++) {
        printf("%d: ", i);
        for (NodoAdj* p = g->adj[i]; p != NULL; p = p->sig) {
        printf("%d ", p->v);
        }
                printf("\n");
        }
        }

        // BFS usando cola simple (array)
void bfs(Grafo* g, int inicio) {
    if (!g) return;
    if (inicio < 0 || inicio >= g->n) return;

    int* visit = (int*)calloc(g->n, sizeof(int));
    int* q = (int*)malloc(sizeof(int) * g->n);
    if (!visit || !q) {
        printf("Error: no hay memoria.\n");
        free(visit);
        free(q);
        return;
    }

    int front = 0, back = 0;
    visit[inicio] = 1;
    q[back++] = inicio;

    printf("BFS desde %d: ", inicio);

    while (front < back) {
        int u = q[front++];
        printf("%d ", u);

        for (NodoAdj* p = g->adj[u]; p != NULL; p = p->sig) {
            int v = p->v;
            if (!visit[v]) {
                visit[v] = 1;
                q[back++] = v;
            }
        }
    }
    printf("\n");

    free(visit);
    free(q);
}

void liberar_grafo(Grafo* g) {
    if (!g) return;
    for (int i = 0; i < g->n; i++) {
        NodoAdj* p = g->adj[i];
        while (p) {
            NodoAdj* tmp = p;
            p = p->sig;
            free(tmp);
        }
    }
    free(g->adj);
    free(g);
}

int main(void) {
    Grafo* g = crear_grafo(6);

        // aristas de ejemplo
            agregar_arista(g, 0, 1);
            agregar_arista(g, 0, 2);
            agregar_arista(g, 1, 3);
            agregar_arista(g, 2, 3);
            agregar_arista(g, 3, 4);
            agregar_arista(g, 4, 5);

            printf("Lista de adyacencia:\n");
            imprimir_grafo(g);

            bfs(g, 0);

            liberar_grafo(g);
            return 0;
    }

