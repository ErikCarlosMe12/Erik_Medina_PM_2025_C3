#include <stdio.h>
#include <string.h>

#define MAXQ 10

typedef struct {
    int id;
    char nombre[32];
} Cliente;

typedef struct {
    Cliente a[MAXQ];
    int front, rear, size;
} Queue;

void q_init(Queue* q) { q->front = 0; q->rear = -1; q->size = 0; }
int q_empty(Queue* q) { return q->size == 0; }
int q_full(Queue* q)  { return q->size == MAXQ; }

int enqueue(Queue* q, Cliente c) {
    if (q_full(q)) return 0;
    q->rear = (q->rear + 1) % MAXQ;
    q->a[q->rear] = c;
    q->size++;
    return 1;
}

int dequeue(Queue* q, Cliente* out) {
    if (q_empty(q)) return 0;
    *out = q->a[q->front];
    q->front = (q->front + 1) % MAXQ;
    q->size--;
    return 1;
    }

    void imprimir(Queue* q) {
        printf("Cola (front->rear): ");
        for (int i = 0; i < q->size; i++) {
            int idx = (q->front + i) % MAXQ;
            printf("[%d:%s] ", q->a[idx].id, q->a[idx].nombre);
        }
        printf("\n");
    }

int main(void) {
    Queue q;
    q_init(&q);

    Cliente c1 = {1, "Erik"};
    Cliente c2 = {2, "Maria"};
    Cliente c3 = {3, "Jose"};
    Cliente c4 = {4, "Ana"};

    enqueue(&q, c1);
    enqueue(&q, c2);
    enqueue(&q, c3);
    imprimir(&q);

    Cliente atendido;
    if (dequeue(&q, &atendido))
        printf("Atendiendo: %d - %s\n", atendido.id, atendido.nombre);

    enqueue(&q, c4);
    imprimir(&q);

    while (dequeue(&q, &atendido)) {
        printf("Atendiendo: %d - %s\n", atendido.id, atendido.nombre);
    }

    printf("Cola vacia: %s\n", q_empty(&q) ? "SI" : "NO");
    return 0;
}


