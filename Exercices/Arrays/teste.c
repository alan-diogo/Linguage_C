#include <stdio.h>
void BubbleSort(int *array, int i)
{

  if (i < 2)
    return;
  for (int j = 0; j < i - 1; j++)
  {
    if (array[j] > array[j + 1])
    {
      int aux = array[j];
      array[j] = array[j + 1];
      array[j + 1] = aux;
    }
  }
  BubbleSort(array, i - 1);
}

void soma(int *array, int i, int *aux)
{
  for (int j = 1; j < 4; j++)
  {
    aux[i] += array[j];
  }
  return;
}
void Printar(int *array, int i)
{
  if (i == 4)
  {
    return;
  }
  printf("%d ", array[i]);

  return Printar(array, i + 1);
}

void Input(int *array, int i, int size)
{
  if (i == size)
  {
    return;
  }
  scanf("%d", &array[i]);

  return Input(array, i + 1, size);
}

int main()
{

  int array1[4], array2[4], array3[4], array4[4], array5[4], array6[4], priority[6], aux[6];

  Input(array1, 0, 4);
  Input(array2, 0, 4);
  Input(array3, 0, 4);
  Input(array4, 0, 4);
  Input(array5, 0, 4);
  Input(array6, 0, 4);
  Input(priority, 0, 6);

  BubbleSort(array1, 4);
  soma(array1, 0, aux);
  Printar(aux, 0);

  return 0;
}