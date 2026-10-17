# Trabalho Prático 02 — Add Two Numbers

## Informações

**Aluno:** Petrick Domingues  
**Disciplina:** Algoritmos e Estruturas de Dados (AED)  
**Professor:** Rafael Piccin Torchelsen  
**Trabalho:** Trabalho Prático 02

---

## 1. Problema

### LeetCode #2 — Add Two Numbers

O problema consiste em somar dois números inteiros não negativos representados por listas encadeadas.

Cada nó da lista armazena um dígito do número, e os dígitos estão armazenados em ordem inversa. A função deve retornar uma nova lista contendo o resultado da soma, também em ordem inversa.

**Exemplo:**

```text
Entrada:
l1 = [2,4,3]
l2 = [5,6,4]

Saída:
[7,0,8]
```

As listas representam os números 342 e 465. Portanto, a soma é 342 + 465 = 807, representada pela lista `[7,0,8]`.

**Link do problema:** https://leetcode.com/problems/add-two-numbers/

---

## 2. Objetivo

Implementar a função `addTwoNumbers` em linguagem C, utilizando listas encadeadas e alocação dinâmica de memória.

A solução deve somar os dígitos das duas listas, calcular o transporte entre as posições e construir uma nova lista com o resultado.

---

## 3. Organização dos arquivos

- `aula/` — código desenvolvido durante a aula.
- `casa/` — código desenvolvido em casa seguindo o estilo de programação solicitado.

Estrutura prevista:

```text
trabalho-02/
├── README.md
├── aula/
│   └── leetcode2.c
└── casa/
    └── LTC2_casa.c
```

---

## 4. Funcionamento da solução

A função utiliza três ponteiros principais para construir a lista de resultado:

- `inicio`: aponta para o primeiro nó da lista resultante.
- `fim`: aponta para o último nó, permitindo adicionar novos elementos.
- `novo`: aponta para o nó que está sendo criado.

A variável `soma` armazena a soma dos dígitos atuais e do transporte. A variável `vaiUm` guarda o transporte que será utilizado na próxima posição.

O algoritmo percorre as duas listas enquanto houver dígitos para somar ou transporte pendente.

Em cada iteração, os dígitos disponíveis são somados. O transporte é calculado pela divisão inteira da soma por 10, enquanto o dígito que será armazenado no novo nó é obtido pelo resto da divisão por 10.

Cada novo nó é ligado ao final da lista de resultado. Ao terminar, a função retorna o ponteiro para o início dessa lista.

---

## 5. Testes

### Caso 1 — Soma de números com três dígitos

**Entrada:**

```text
l1 = [2,4,3]
l2 = [5,6,4]
```

**Saída esperada:**

```text
[7,0,8]
```

**Resultado do teste:** [Preencher após testar]

### Caso 2 — Soma de zeros

**Entrada:**

```text
l1 = [0]
l2 = [0]
```

**Saída esperada:**

```text
[0]
```

**Resultado do teste:** [Preencher após testar]

### Caso 3 — Soma com transporte em várias posições

**Entrada:**

```text
l1 = [9,9,9,9,9,9,9]
l2 = [9,9,9,9]
```

**Saída esperada:**

```text
[8,9,9,9,0,0,0,1]
```

**Resultado do teste:** [Preencher após testar]

---

## 6. O que funciona

Após a realização dos testes, registrar aqui as funcionalidades verificadas, como:

- Soma de números representados por listas encadeadas.
- Soma de listas com tamanhos diferentes.
- Cálculo do transporte entre os dígitos.
- Criação de uma nova lista para armazenar o resultado.
- Tratamento de falha na alocação de um novo nó.


---

## 7. Complexidade do algoritmo

Considere `n` como o número de nós da primeira lista e `m` como o número de nós da segunda lista.

**Complexidade de tempo: O(max(n, m))**

O algoritmo percorre as listas uma posição por vez. O número de iterações é proporcional ao tamanho da lista mais longa, podendo haver uma iteração adicional para o transporte final.

**Complexidade de espaço: O(max(n, m))**

A função cria uma nova lista para armazenar o resultado. Essa lista possui tamanho proporcional ao tamanho da maior lista de entrada, podendo ter um nó adicional por causa do transporte final.

O espaço auxiliar utilizado pelas variáveis é O(1), sem contar a memória da lista de resultado.

---

## 8. Alocação dinâmica e gerenciamento de memória

A função utiliza `malloc` para alocar memória para cada novo nó da lista resultante.

Se uma alocação falhar, o código libera os nós do resultado que já foram criados utilizando `free` e retorna `NULL`.


---

## 9. Ajuda utilizada

[Descrever honestamente os recursos utilizados durante o desenvolvimento.]

Caso tenha utilizado inteligência artificial, explicar em quais partes ela ajudou, por exemplo, na compreensão dos ponteiros, da construção da lista resultante ou do tratamento do transporte.

---

## 10. Conclusão

O trabalho permite aplicar conceitos de listas encadeadas, ponteiros, laços de repetição, alocação dinâmica e gerenciamento de memória em C.

A solução percorre as listas de entrada, soma os dígitos e constrói uma nova lista com o resultado, tratando o transporte entre as posições.

A complexidade de tempo é O(max(n, m)) e a complexidade de espaço, incluindo a lista resultante, também é O(max(n, m)).
