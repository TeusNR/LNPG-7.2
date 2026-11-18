#include <stdio.h>
struct ponto { int x, y; };
int main(void) {
    struct ponto a = {1, 2}, b = {1, 2};
    if (a.x == b.x && a.y == b.y)
        printf("iguais\n");
    return 0;
}
