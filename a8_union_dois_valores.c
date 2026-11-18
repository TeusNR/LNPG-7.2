/* Parte A, questao 8: ERRO DE INTERPRETACAO INTENCIONAL.
   Em plataformas comuns, nao imprime 65.000000. */
#include <stdio.h>
int main(void) {
    union u { int i; float f; } v;
    v.i = 65;
    printf("%f\n", v.f);
    return 0;
}
