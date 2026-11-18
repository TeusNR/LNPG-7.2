# Unidade 7 — Tipos definidos pelo usuário em C

Projeto referente à atividade **“Tipos definidos pelo usuário: caça ao bug e teste de mesa” (Unidade 7)**.

O conteúdo trabalha `struct`, operadores `.` e `->`, `union`, `enum`, `typedef`, `sizeof`, `offsetof`, alinhamento e *padding* em C. A atividade foi dividida entre uma parte teórica (**Parte A**) e cinco exercícios práticos (**Parte B**).

## Organização do projeto

```text
atividade-u7-c/
├── README.md
├── PARTE_A.md
├── RESPOSTAS_LAB.md
├── Makefile
├── .gitignore
├── parte_b/
│   ├── l1.c                  # Distância entre pontos (struct e sqrt)
│   ├── l2.c                  # Melhor média (typedef e array de struct)
│   ├── l3.c                  # Move um ponto (ponteiro e ->)
│   ├── l4.c                  # Bytes de um int (union / endianness)
│   └── l5.c                  # Tamanho e offsets (padding)
├── exemplos_com_bug/
│   ├── a2_ponto_ou_seta.c
│   ├── a4_comparar_structs.c
│   ├── a6_struct_aninhada.c
│   ├── a8_union_dois_valores.c
│   └── a11_retorna_local.c
└── exemplos_corrigidos/
    ├── a2_ponto_ou_seta.c
    ├── a4_comparar_structs.c
    ├── a6_struct_aninhada.c
    ├── a8_struct_para_dois_valores.c
    └── a11_retorna_struct_por_valor.c
```

## Resolução da atividade

- **[Parte A — 12 questões respondidas](PARTE_A.md)**: testes de mesa, explicação dos bugs e correções.
- **[Parte B — Explicações dos exercícios](RESPOSTAS_LAB.md)**: lógica e saídas esperadas dos labs.
- **[`parte_b/`](parte_b/)**: soluções dos cinco exercícios em C.
- **[`exemplos_com_bug/`](exemplos_com_bug/)**: códigos propositalmente incorretos das questões 2, 4, 6, 8 e 11 da Parte A.
- **[`exemplos_corrigidos/`](exemplos_corrigidos/)**: versões seguras/corrigidas desses exemplos.

> **Atenção:** os exemplos em `exemplos_com_bug/` são demonstrativos, não são soluções finais. Alguns nem compilam, e o exemplo da questão 11 contém comportamento indefinido. Não os execute como programas corretos.

## Como compilar e executar (GCC)

É necessário ter o GCC instalado. No Linux ou GitHub Codespaces, entre na pasta do projeto e execute:

```bash
make
```

Os executáveis serão criados na pasta `build/` (ignorada pelo Git).

Para executar cada exercício:

```bash
make run-l1
make run-l2
make run-l3
make run-l4
make run-l5
```

No **L1**, digite dois pares de coordenadas quando solicitado, por exemplo `0 0` e `3 4`.

Para remover os executáveis gerados:

```bash
make clean
```

### Compilação manual (sem Makefile)

```bash
gcc -std=c11 -Wall -Wextra parte_b/l1.c -o l1 -lm
gcc -std=c11 -Wall -Wextra parte_b/l2.c -o l2
gcc -std=c11 -Wall -Wextra parte_b/l3.c -o l3
gcc -std=c11 -Wall -Wextra parte_b/l4.c -o l4
gcc -std=c11 -Wall -Wextra parte_b/l5.c -o l5
```

O `-lm` é necessário no L1 por utilizar `sqrt` da biblioteca matemática.

## Saídas de referência

| Lab | Resultado esperado |
|---|---|
| L1 | Para A `(0,0)` e B `(3,4)`: `Distancia = 5.00` |
| L2 | `Maior media: Ana (9.00)` |
| L3 | `(5, 3)` |
| L4 | `Bytes: 04 03 02 01` em little-endian |
| L5 | `Ruim: 12 bytes`, `Bom: 8 bytes` em plataforma comum com `int` de 4 bytes |

Os resultados de L4 e L5 podem variar em outras arquiteturas, pois dependem da representação dos números, do alinhamento e do tamanho dos tipos.

## Publicar no GitHub / Codespaces

1. Crie ou abra o repositório desejado no GitHub Codespaces.
2. Extraia o ZIP e copie **os arquivos e as pastas de dentro de `atividade-u7-c/`** para a raiz do repositório, preservando a estrutura das pastas. Inclua também `.gitignore` e `Makefile`.
3. No terminal do Codespaces, execute:

```bash
git add .
git commit -m "Adiciona atividade da Unidade 7"
git push origin main
```

Se a sua branch não for `main`, substitua pelo nome que aparece no terminal. O `Makefile` é opcional para a entrega, mas facilita os testes.

## Referência

Atividade de sala: **Tipos definidos pelo usuário: caça ao bug e teste de mesa — Unidade 7**, arquivo `u7-tipos-usuario-caca-bug.pdf`.
