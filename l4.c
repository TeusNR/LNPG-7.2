#include <stdio.h>

union bytes {
    int i;
    unsigned char b[4];
};

int main(void) {
    /* O exercicio considera int de 4 bytes, comum nas maquinas atuais. */
    if (sizeof(int) != 4) {
        fprintf(stderr, "Este exemplo exige int com 4 bytes.\n");
        return 1;
    }

    union bytes u;
    u.i = 0x01020304;

    printf("Bytes: ");
    for (int j = 0; j < 4; j++) {
        printf("%02X%s", (unsigned int)u.b[j], j == 3 ? "\n" : " ");
    }

    if (u.b[0] == 0x04) {
        printf("Ordem: little-endian\n");
    } else if (u.b[0] == 0x01) {
        printf("Ordem: big-endian\n");
    } else {
        printf("Ordem: outra representacao\n");
    }
    return 0;
}
