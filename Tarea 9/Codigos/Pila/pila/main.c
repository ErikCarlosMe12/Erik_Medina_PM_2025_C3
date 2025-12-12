#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 256

typedef struct {
    int a[MAX];
        int top;
        } Stack;

        void st_init(Stack* s) { s->top = -1; }
        int st_push(Stack* s, int x) { if (s->top == MAX-1) return 0; s->a[++s->top] = x; return 1; }
        int st_pop(Stack* s, int* out) { if (s->top < 0) return 0; *out = s->a[s->top--]; return 1; }

        int aplicar(char op, int b, int a, int* out) {
        // ojo: en postfix, a op b
            if (op == '+') { *out = a + b; return 1; }
                if (op == '-') { *out = a - b; return 1; }
                    if (op == '*') { *out = a * b; return 1; }
                        if (op == '/') { if (b == 0) return 0; *out = a / b; return 1; }
                            return 0;
        }

    int eval_postfix(const char* expr, int* result) {
        Stack s; st_init(&s);

        char buf[512];
        strncpy(buf, expr, sizeof(buf) - 1);
        buf[sizeof(buf) - 1] = '\0';

        char* tok = strtok(buf, " ");
        while (tok) {
        if (isdigit((unsigned char)tok[0]) || (tok[0] == '-' && isdigit((unsigned char)tok[1]))) {
        int val = atoi(tok);
            if (!st_push(&s, val)) return 0;
                } else if (strlen(tok) == 1 && strchr("+-*/", tok[0])) {
                    int b, a, r;
                        if (!st_pop(&s, &b) || !st_pop(&s, &a)) return 0;
                            if (!aplicar(tok[0], b, a, &r)) return 0;
                                if (!st_push(&s, r)) return 0;
                                } else {
                                    return 0;
                        }
                                    tok = strtok(NULL, " ");
                }

                                    if (s.top != 0) return 0;
                                        *result = s.a[s.top];
                                        return 1;
        }

        int main(void) {
            const char* expr = "5 1 2 + 4 * + 3 -"; // resultado: 14
            int r;

            printf("Expresion postfix: %s\n", expr);
            if (eval_postfix(expr, &r)) printf("Resultado: %d\n", r);
            else printf("Error evaluando expresion.\n");

            return 0;
        }


