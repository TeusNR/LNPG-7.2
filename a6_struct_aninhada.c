/* Parte A, questao 6: ERRO INTENCIONAL - nao compila. */
#include <stdio.h>
struct endereco { char rua[50]; int numero; };
struct cadastro { char nome[50]; struct endereco ender; };
int main(void) {
    struct cadastro c;
    c.numero = 10; /* numero pertence a c.ender */
    printf("%d\n", c.numero);
    return 0;
}
