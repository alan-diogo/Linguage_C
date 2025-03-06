/*
**Descrição**
Faça um programa que lê uma Lista de números inteiros, depois encontra e imprime:

      a) a lista dos números lidos na ordem inversa;

      b) primeiro os números que estiverem nas posições com índices pares, seguidos pelos que estão nas posições com índices ímpares;

      c) a soma dos elementos, de mesma posição, tomando dois a dois, considerando os valores resultantes das listas dos itens a) e b).

**Formato de entrada**

Consiste de uma sequência de números separados por espaços em branco.

Suponha que a sequência de entrada terá no mínimo um número.

**Formato de saída**

Consiste de 3 sequências de números, uma por linha, separados por espaços em branco. Após cada sequência, existe um final de linha.

A primeira linha começa com a palavra Invert:, seguida dos números lidos da entrada na ordem inversa. A segunda começa com a palavra ParImp:, seguida dos números das posições de índices pares seguidos pelos números das posições de índices ímpares. A terceira linha começa com a palavra Soma:, seguida da soma dessas duas sequências anteriores de números, considerando os valores de mesma posição tomados dois a dois. Veja os exemplos de Entrada/Saída para mais detalhes.

Lembre-se que depois do último número de cada sequência não existe espaço.

Exemplos de:

Entrada
-1 -1 1 1

Saída

Invert: 1 1 -1 -1
ParImp: -1 1 -1 1
Soma: 0 2 -2 0
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int main()
{
  int lista1[MAX], listaInvert[MAX];
  int size = 0;

  while (scanf("%d", &lista1[size]) == 1 && size < MAX)
  {
    size++;
  }

  int size2 = 0;

  printf("Invert:");
  for (int i = size - 1; i > -1; i--)
  {
    printf(" %d", lista1[i]);
    listaInvert[size2] = lista1[i];
    size2++;
  }

  int aux[size];
  int auxSize = 0;

  printf("\nParImp:");

  for (int i = 0; i < size; i++)
  {
    if (i % 2 == 0)
    {
      printf(" %d", lista1[i]);
      aux[auxSize] = lista1[i];
      auxSize++;
    }
  }
  for (int i = 0; i < size; i++)
  {
    if (i % 2 != 0)
    {
      printf(" %d", lista1[i]);
      aux[auxSize] = lista1[i];
      auxSize++;
    }
  }

  printf("\nSoma:");
  for (int i = 0; i < auxSize; i++)
  {
    printf(" %d", listaInvert[i] + aux[i]);
  }

  return 0;
}