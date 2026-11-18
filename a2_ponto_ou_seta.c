/* Parte A, questao 2: ERRO INTENCIONAL - nao compila. */
#include <stdio.h>
struct ponto { int x, y; };
void muda(struct ponto *p) {
    p.x = 10; /* p e ponteiro: deveria ser p->x */
}
int main(void) {
    struct ponto q = {0, 0};
    muda(&q);
    printf("%d\n", q.x);
    return 0;
}
