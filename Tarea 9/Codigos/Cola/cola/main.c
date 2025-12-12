#include <stdio.h>

#define MAX 5

typedef struct {
    int a[MAX];
        int top;
        } Stack;

        void st_init(Stack* s) { s->top = -1; }
        int st_empty(Stack* s) { return s->top == -1; }
        int st_full(Stack* s) { return s->top == MAX - 1; }

        int st_push(Stack* s, int x) {
        if (st_full(s)) return 0;
        s->a[++s->top] = x;
        return 1;
    }

int st_pop(Stack* s, int* out) {
    if (st_empty(s)) return 0;
    *out = s->a[s->top--];
    return 1;
    }

    int st_peek(Stack* s, int* out) {
    if (st_empty(s)) return 0;
    *out = s->a[s->top];
    return 1;
    }

void st_print(Stack* s) {
    printf("Stack (top -> bottom): ");
    for (int i = s->top; i >= 0; i--) printf("%d ", s->a[i]);
    printf("\n");
    }

int main(void) {
    Stack s;
    st_init(&s);

    st_push(&s, 10);
    st_push(&s, 20);
    st_push(&s, 30);
    st_print(&s);

    int x;
    if (st_peek(&s, &x)) printf("Peek: %d\n", x);

    while (st_pop(&s, &x)) {
    printf("Pop: %d\n", x);
    }
    printf("Pop en vacio: %s\n", st_pop(&s, &x) ? "OK" : "UNDERFLOW");
    return 0;
}
