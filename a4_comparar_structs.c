/* Parte A, questao 4: ERRO INTENCIONAL - nao compila. */
#include <stdio.h>
struct ponto { int x, y; };
int main(void) {
    struct ponto a = {1, 2}, b = {1, 2};
    if (a == b) /* structs nao admitem == em C */
        printf("iguais\n");
    return 0;
}
