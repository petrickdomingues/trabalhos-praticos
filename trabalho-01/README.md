# Trabalho Prático 01 - Maximum Subarray

## Informações

**Aluno:** Petrick Domingues

**Disciplina:** Algoritmos e Estruturas de Dados (AED)

**Professor:** RAFAEL PICCIN TORCHELSEN

**Trabalho:** Trabalho Prático 01

---

## Problema

### LeetCode #53 - Maximum Subarray

O problema consiste em receber um vetor de números inteiros e encontrar a
subsequência contígua que possui a maior soma possível.

A função deve retornar somente o valor da maior soma encontrada.

Por exemplo:

```text
Entrada:
[-2,1,-3,4,-1,2,1,-5,4]

Saída:
6
```

A subsequência com maior soma é:

```text
[4,-1,2,1]
```

Sua soma é:

```text
4 + (-1) + 2 + 1 = 6
```

---

## Objetivo

Implementar uma função capaz de encontrar a maior soma possível de uma
subsequência contígua do vetor.

A solução utilizada percorre o vetor uma única vez, mantendo a melhor soma
da sequência atual e a maior soma encontrada durante a execução.

---

## Funcionamento da solução

A solução utiliza duas variáveis principais:

* `somaAtual` — armazena a melhor soma de uma sequência que termina na
  posição atual.
* `melhorSoma` — armazena a maior soma encontrada até o momento.

Para cada elemento do vetor, é verificado se é melhor continuar a sequência
atual ou começar uma nova sequência a partir daquele elemento.

Se começar uma nova sequência for melhor, `somaAtual` recebe o elemento atual.

Caso contrário, o elemento atual é somado à sequência existente.

Depois disso, se `somaAtual` for maior que `melhorSoma`, o valor de
`melhorSoma` é atualizado.

Ao final, `melhorSoma` é retornada.

---

## Testes realizados

Os três casos abaixo correspondem aos exemplos apresentados no enunciado
do problema no LeetCode.

### Caso 1

**Entrada:**

```text
nums = [-2,1,-3,4,-1,2,1,-5,4]
```

**Saída esperada:**

```text
6
```

**Resultado:** Funcionou corretamente.

---

### Caso 2

**Entrada:**

```text
nums = [1]
```

**Saída esperada:**

```text
1
```

**Resultado:** Funcionou corretamente.

---

### Caso 3

**Entrada:**

```text
nums = [5,4,-1,7,8]
```

**Saída esperada:**

```text
23
```

**Resultado:** Funcionou corretamente.

---

## Dificuldades encontradas

A dificuldade foi entender o conceito de subsequência contígua
e perceber quando é melhor continuar somando os elementos ou iniciar uma
nova sequência.

Também entender a diferença entre a soma atual e a maior
soma encontrada durante o percurso do vetor.
