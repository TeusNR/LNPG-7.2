/* Parte A, questao 11: ERRO INTENCIONAL - ponteiro pendente.
   NAO executar: o comportamento e indefinido. */
struct ponto { int x, y; };
struct ponto *cria(void) {
    struct ponto p = {1, 2};
    return &p;
}
int main(void) {
    struct ponto *q = cria();
    return q->x;
}
