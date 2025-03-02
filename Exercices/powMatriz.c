#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  int a, b;
  printf("Digite a quantidade de colunas da matriz:");
  scanf("%d", &a);
  printf("Digite a quantidade de linhas da matriz:");
  scanf("%d", &b);

  printf("O quadrado de cada elemento da matriz é:\n ");

  int matriz[b][a];

  for (int i = 0; i < b; i++)
  {
    for (int j = 0; j < a; j++)
      scanf("%d", &matriz[i][j]);
  }

  for (int i = 0; i < b; i++)
  {
    for (int j = 0; j < a; j++)
      printf("%d ", matriz[i][j] * matriz[i][j]);
    printf("\n");
  }
}