#include <stdio.h>
struct endereco { char rua[50]; int numero; };
struct cadastro { char nome[50]; struct endereco ender; };
int main(void) {
    struct cadastro c = {0};
    c.ender.numero = 10;
    printf("%d\n", c.ender.numero);
    return 0;
}
