# Parte A — Teste de mesa e caça ao bug (Unidade 7)

Respostas dos 12 exercícios da atividade **Tipos definidos pelo usuário: caça ao bug e teste de mesa**. As observações sobre tamanho de tipos e ordem dos bytes consideram o ambiente comum indicado no enunciado: `int` de 4 bytes, alinhamento de 4 bytes e arquitetura little-endian, quando aplicável.

## Nível 1 — Fácil

### 1. Campos de uma `struct`

**Saída:** `3 7`

O ponto começa em `{3, 4}`. A instrução `p.y = p.x + p.y` soma `3 + 4` e altera apenas `y` para `7`. O campo `x` continua `3`.

### 2. Ponto ou seta?

**Bug:** `p` é um ponteiro para `struct ponto`; a expressão `p.x` tenta acessar um campo como se `p` fosse a estrutura. **Não compila**.

**Correção:** substituir por `p->x = 10;` (equivalente a `(*p).x = 10;`). Então `muda(&q)` modifica `q.x`, e o programa imprime `10`.

### 3. Enumeração

**Saída:** `4`

Sem valores explícitos, a contagem começa em zero: `DOM=0`, `SEG=1`, `TER=2`, `QUA=3`, `QUI=4`, `SEX=5`, `SAB=6`.

## Nível 2 — Médio

### 4. Structs são iguais?

**Bug:** a expressão `a == b` **não compila**, pois C não define os operadores `==` e `!=` para comparar duas estruturas diretamente.

**Correção:** comparar os campos desejados:

```c
if (a.x == b.x && a.y == b.y)
    printf("iguais\n");
```

A atribuição `a = b` é permitida para estruturas compatíveis, porque copia o valor da estrutura; isso não cria um operador de comparação. Para estruturas com mais campos, compare cada campo relevante.

### 5. Enum com valor fixado

**Saída:** `6 7`

O enum define `AZUL=5`. Como os próximos elementos não recebem valores explícitos, seguem a sequência: `VERDE=6` e `VERMELHO=7`.

### 6. Struct aninhada

**Bug:** `numero` não é campo direto de `cadastro`; ele pertence à `struct endereco`, armazenada em `c.ender`. Portanto, o código original **não compila**.

**Correção:**

```c
c.ender.numero = 10;
printf("%d\n", c.ender.numero);
```

A saída do programa corrigido é `10`.

## Nível 3 — Difícil

### 7. União: os campos se sobrepõem

**Saída no sistema little-endian indicado na questão:** `9`.

O valor `1545` equivale a `0x0609`. Em little-endian, o byte menos significativo fica primeiro na memória: `09 06`. Como `t.c` lê o primeiro byte dessa mesma região, recebe `0x09`, que vale `9` em decimal. **Em big-endian, a saída seria `6`**, assumindo `short` de 2 bytes.

### 8. Uma união guarda os dois?

**Não imprime `65.000000`.** `int i` e `float f` compartilham os mesmos bytes: escrever `v.i = 65` não faz uma conversão numérica para `float`.

Em uma máquina usual com `int` e `float` de 32 bits, representação IEEE 754, os bits do inteiro `65` (`0x00000041`) interpretados como `float` correspondem a um número positivo minúsculo (~`9,1 × 10⁻⁴⁴`). Com `printf("%f", ...)`, normalmente aparece **`0.000000`**. O comportamento exato depende da implementação e da representação dos tipos.

**Correção conforme o objetivo:** se quer imprimir o número real 65, atribua `v.f = 65.0f` e leia `v.f`; se quer armazenar **os dois valores independentemente**, use uma `struct` em vez de `union`.

### 9. `sizeof` com padding

**Tamanho esperado:** `12` bytes.

| Região de bytes | Conteúdo |
|---|---|
| 0–3 | `i` (`int`) |
| 4 | `c` (`char`) |
| 5–7 | *padding* (3 bytes) |
| 8–11 | `j` (`int`) |

O compilador insere bytes entre `c` e `j` para posicionar `j` em um offset múltiplo de 4.

## Nível 4 — Muito difícil

### 10. A ordem dos campos muda o tamanho

**Saída esperada:** `Ruim=12 Bom=8`.

**`struct Ruim`:** `a` no offset 0; padding nos bytes 1–3; `b` nos bytes 4–7; `c` no byte 8; padding final nos bytes 9–11. **Total: 12 bytes.**

**`struct Bom`:** `b` nos bytes 0–3; `a` no byte 4; `c` no byte 5; padding final nos bytes 6–7. **Total: 8 bytes.**

Reordenar os campos reduz o padding, respeitando as necessidades de alinhamento. Os tamanhos são típicos, não universais para toda arquitetura.

### 11. Devolvendo uma `struct`

**Bug:** `cria` devolve `&p`, mas `p` é uma variável local automática cujo tempo de vida termina ao retornar da função. O ponteiro `q` fica **pendente**, e acessar `q->x` causa **comportamento indefinido** (pode falhar ou aparentar funcionar).

**Correção:** retornar a estrutura **por valor**, em vez de retornar o endereço da variável local:

```c
struct ponto cria(void) {
    struct ponto p = {1, 2};
    return p;
}

int main(void) {
    struct ponto q = cria();
    return q.x;
}
```

Nesse exemplo, `main` retorna `1` ao sistema (pois `q.x == 1`), **não imprime nada**. Se a intenção for mostrar os campos na tela, use `printf` e retorne `0`.

### 12. Copiar `struct` com `=`

**Saída:** `1 9`

`struct ponto b = a` copia os valores dos campos de `a` para `b`. Alterar `b.x` para `9` não muda `a.x`, que continua `1`. Diferentemente de arrays em C (que não podem ser atribuídos com `=`), estruturas compatíveis podem ser copiadas por atribuição. Se uma estrutura contiver ponteiros, essa cópia também copia os endereços, não os dados apontados.

---

**Síntese:** as questões 2, 4 e 6 têm erros que impedem a compilação; a 11 ilustra retorno de endereço inválido; as 7 e 8 exigem compreender como a `union` compartilha memória; e as 9 e 10 demonstram padding e alinhamento.
