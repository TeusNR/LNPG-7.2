/* Para guardar dois valores independentes, use struct em vez de union. */
#include <stdio.h>
int main(void) {
    struct valores { int i; float f; } v = {65, 65.0f};
    printf("inteiro=%d real=%f\n", v.i, v.f);
    return 0;
}
