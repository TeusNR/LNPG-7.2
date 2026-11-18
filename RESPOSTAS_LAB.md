# Parte B — Respostas e explicações dos laboratórios

Todos os programas estão em [`parte_b/`](parte_b/) e podem ser compilados com GCC, C11, `-Wall` e `-Wextra`. Para o L1, também é necessário `-lm`, como pede a atividade.

## L1 — Distância entre dois pontos

**Arquivo:** [`parte_b/l1.c`](parte_b/l1.c)

Cria a `struct ponto` com dois `double`, lê A e B e calcula a distância euclidiana pela expressão `sqrt(dx * dx + dy * dy)`.

**Exemplo:** A = `(0, 0)`, B = `(3, 4)` → `Distancia = 5.00`.

O programa valida se as duas coordenadas foram lidas corretamente. Compile com `gcc -std=c11 -Wall -Wextra parte_b/l1.c -o l1 -lm`.

## L2 — Array de structs com `typedef`

**Arquivo:** [`parte_b/l2.c`](parte_b/l2.c)

Usa o tipo `Aluno`, com `nome`, `n1`, `n2` e `n3`. Os três alunos já estão preenchidos no código. Calcula a média de cada aluno e guarda o índice do maior resultado.

**Saída:** `Maior media: Ana (9.00)`.

**Conceitos:** `typedef`, array de estruturas, acesso com `.` e comparação de médias.

## L3 — Mover um ponto por ponteiro

**Arquivo:** [`parte_b/l3.c`](parte_b/l3.c)

A função `move(struct ponto *p, int dx, int dy)` altera os campos diretamente por `p->x` e `p->y`.

**Saída:** `(5, 3)`.

A chamada `move(&p, 4, 2)` modifica o ponto original `{1, 1}`, sem criar uma cópia independente.

## L4 — Observar bytes de um `int` com `union`

**Arquivo:** [`parte_b/l4.c`](parte_b/l4.c)

A `union bytes` permite observar os bytes da representação de `u.i = 0x01020304` por meio de `u.b`. O programa verifica que `int` tenha 4 bytes, conforme a proposta do exercício.

**Saída típica em little-endian:**

```text
Bytes: 04 03 02 01
Ordem: little-endian
```

O primeiro byte é `0x04`, porque o byte menos significativo fica no menor endereço. Em big-endian, a sequência seria `01 02 03 04` e o primeiro byte seria `0x01`. O resultado depende da arquitetura.

## L5 — Medir padding com `sizeof` e `offsetof`

**Arquivo:** [`parte_b/l5.c`](parte_b/l5.c)

Com `<stddef.h>`, o programa imprime o tamanho das estruturas e os deslocamentos de cada campo.

**Saída típica em plataformas com `int` de 4 bytes alinhado a 4:**

```text
Ruim: tamanho = 12 bytes
  a: offset 0
  b: offset 4
  c: offset 8
Bom: tamanho = 8 bytes
  b: offset 0
  a: offset 4
  c: offset 5
```

**Onde está o padding?** Em `Ruim`, 3 bytes entre `a` e `b`, mais 3 ao final. Em `Bom`, não há padding entre campos, apenas 2 bytes ao final. A ordem dos campos influencia o espaço total usado.

## Discussão final

- **Erros detectados pelo compilador:** o uso de `.` em um ponteiro (Parte A, 2), o uso de `==` entre estruturas (4) e o acesso a um campo no nível errado da estrutura (6).
- **Erros/efeitos ligados à representação em memória:** as questões 7 e 8 exigem interpretar uma união e seus bytes. O resultado pode variar conforme a arquitetura.
- **Ponteiro inválido após a função:** na questão 11, o compilador pode emitir o warning `-Wreturn-local-addr`, mas nem todo comportamento indefinido pode ser detectado só com warnings.
- **`struct` versus `union`:** estruturas armazenam seus membros em espaços distintos (possivelmente com padding); uniões sobrepõem a região de armazenamento dos membros.
- **Alinhamento:** reorganizar campos pode reduzir padding, especialmente em arrays grandes de estruturas.
