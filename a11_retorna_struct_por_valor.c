/* Devolver por valor evita retornar ponteiro para variavel local. */
#include <stdio.h>
struct ponto { int x, y; };
struct ponto cria(void) {
    struct ponto p = {1, 2};
    return p;
}
int main(void) {
    struct ponto q = cria();
    printf("%d %d\n", q.x, q.y);
    return 0;
}
