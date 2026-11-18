#include <stdio.h>
struct ponto { int x, y; };
void muda(struct ponto *p) {
    p->x = 10;
}
int main(void) {
    struct ponto q = {0, 0};
    muda(&q);
    printf("%d\n", q.x);
    return 0;
}
