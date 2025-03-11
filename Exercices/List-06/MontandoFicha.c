/*Descrição
Yuto adora jogar RPG com seus amigos, mas tem muito dificuldade na criação de ficha de personagem. No Dungeon and Dragons, que é o seu sistema favorito, há 6 atributos: Força, Destreza, Constituição, Sabedoria, Inteligência e Carisma, e seus valores são determinados pela seguinte regra: São jogados 4d6 (4 dados de 6 faces) e os três maiores valores são somados.

Yuto está desesperado, hoje a noite terá a primeira sessão e ele ainda não determinou os atributos de seu guerreiro, Kayn. Você, como um bom amigo e programador, decidiu ajudá-lo criando um programa para determinar esses atributos. Dado os dados rolados por ele e a ordem dos atributes, retorne os valores de cada atributo.

Formato de entrada

A entrada consiste em 6 linhas com 4 números, e uma outra linha com a "ordem de prioridade" dos atributos, ou seja, 2 1 5 3 6 4 significa que:


For receberá a 2º maior soma
Des receberá a 1º maior soma
Con receberá a 5º maior soma
Sab receberá a 3º maior soma
Int receberá a 6º maior soma
Car receberá a 4º maior soma

Formato de saída

A saída consiste no nome do atributo com seu respectivo valor.

For =

Des =

Con =

Sab =

Int =

Car =
*/

#include <stdio.h>

void StepBubbleSort(int *array, int i, int j)
{
  if (j == i)
  {
    return;
  }
  if (array[j] < array[j + 1])
  {
    int aux = array[j];
    array[j] = array[j + 1];
    array[j + 1] = aux;
  }

  return StepBubbleSort(array, i, j + 1);
}

void BubbleSort(int *array, int i)
{
  if (i < 2)
    return;
  StepBubbleSort(array, i, 0);
  BubbleSort(array, i - 1);
}

int soma(int *array, int i, int guardar, int aux)
{
  if (i == 4)
  {
    aux -= guardar;
    return aux;
  }
  aux += array[i];
  if (array[i] <= guardar)
  {
    guardar = array[i];
  }
  return soma(array, i + 1, guardar, aux);
}

int Printar(int *array, int i)
{
  if (i == 6)
  {
    return 0;
  }

  switch (i)
  {
  case 0:
    printf("For = %d\n", array[i]);
    break;
  case 1:
    printf("Des = %d\n", array[i]);
    break;
  case 2:
    printf("Con = %d\n", array[i]);
    break;
  case 3:
    printf("Sab = %d\n", array[i]);
    break;
  case 4:
    printf("Int = %d\n", array[i]);
    break;
  case 5:
    printf("Car = %d\n", array[i]);
    break;
  }
  return Printar(array, i + 1);
}

int Priority(int *order, int master[6], int i, int guarda[6])
{
  if (i == 6)
  {
    return Printar(guarda, 0); // Alterado para começar do índice 5
  }
  guarda[i] = master[order[i] - 1]; // Corrigido o índice
  return Priority(order, master, i + 1, guarda);
}

int Input(int *array, int i, int size)
{
  if (i == size && i != 6)
  {
    return soma(array, 0, 1000, 0);
  }
  else if (i == 6)
  {
    return *array;
  }
  scanf("%d", &array[i]);
  return Input(array, i + 1, size);
}

int main()
{
  int array1[4], array2[4], array3[4], array4[4], array5[4], array6[4], priority[6], mestra[6], guarda[6];

  mestra[0] = Input(array1, 0, 4);
  mestra[1] = Input(array2, 0, 4);
  mestra[2] = Input(array3, 0, 4);
  mestra[3] = Input(array4, 0, 4);
  mestra[4] = Input(array5, 0, 4);
  mestra[5] = Input(array6, 0, 4);
  Input(priority, 0, 6);

  BubbleSort(mestra, 6);

  Priority(priority, mestra, 0, guarda);

  return 0;
}