#include <stddef.h>
#include <stdio.h>

struct Ruim {
    char a;
    int b;
    char c;
};

struct Bom {
    int b;
    char a;
    char c;
};

int main(void) {
    printf("Ruim: tamanho = %zu bytes\n", sizeof(struct Ruim));
    printf("  a: offset %zu\n", offsetof(struct Ruim, a));
    printf("  b: offset %zu\n", offsetof(struct Ruim, b));
    printf("  c: offset %zu\n", offsetof(struct Ruim, c));

    printf("Bom: tamanho = %zu bytes\n", sizeof(struct Bom));
    printf("  b: offset %zu\n", offsetof(struct Bom, b));
    printf("  a: offset %zu\n", offsetof(struct Bom, a));
    printf("  c: offset %zu\n", offsetof(struct Bom, c));
    return 0;
}
