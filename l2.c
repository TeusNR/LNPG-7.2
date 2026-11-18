#include <stdio.h>

typedef struct {
    char nome[30];
    float n1, n2, n3;
} Aluno;

int main(void) {
    Aluno alunos[3] = {
        {"Ana", 9.0f, 9.0f, 9.0f},
        {"Bruno", 7.0f, 8.0f, 9.0f},
        {"Carla", 8.0f, 8.5f, 8.5f}
    };

    int melhor = 0;
    float maior_media = (alunos[0].n1 + alunos[0].n2 + alunos[0].n3) / 3.0f;

    for (int i = 1; i < 3; i++) {
        float media = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3) / 3.0f;
        if (media > maior_media) {
            maior_media = media;
            melhor = i;
        }
    }

    printf("Maior media: %s (%.2f)\n", alunos[melhor].nome, maior_media);
    return 0;
}
