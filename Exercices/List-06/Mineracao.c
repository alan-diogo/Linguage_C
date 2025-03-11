/*
Descrição
Um dos problemas encontrados para gerenciar os recursos de uma mina é ter controle de onde cada túnel pode levar, sabendo disso a Sociedade Brasileira de Mineiros pediu para você construir um programa que, dado a quantidade de túneis, onde cada túnel leva e o túnel que quer saber onde você vai sair imprima na tela o túnel de saída.

Um túnel é considerado um túnel de saída quando ele leva a -1.



Obs1: sempre existe pelo menos um túnel de saída.

Obs2: um túnel i sempre leva a exatamente um túnel de saída (ou seja, não existe interseções entre os túneis)

Formato de entrada

A entrada é composta por 3 linhas, a primeira contém um inteiro N (0 < n < 30) que indica a quantidade de túneis da mina.

A segunda contém N inteiros Ai(-1 <= Ai < n) representando a qual túnel o túnel i leva.

A terceira linha contém um inteiro E(0 <= E < n) que indica o túnel inicial da busca.

Formato de saída

A saída é composta por um inteiro indicando qual o túnel de saída encontrado.
*/
#include <stdio.h>

int Toca(int *tuneis, int size, int i, int count)
{
  if (count == size)
  {
    printf("Toca sem saida");
    return 0;
  }

  if (tuneis[i] == -1)
  {
    printf("%d", i);
    return 0;
  }
  i = tuneis[i];

  return Toca(tuneis, size, i, count + 1);
}

int Read(int *tuneis, int size, int i, int start)
{
  if (i == size)
  {
    scanf("%d", &start);
    return Toca(tuneis, size, start, 0);
  }

  scanf("%d", &tuneis[i]);

  return Read(tuneis, size, i + 1, 0);
}

int main()
{
  int size;
  scanf("%d", &size);
  int tuneis[size];

  Read(tuneis, size, 0, 0);

  return 0;
}