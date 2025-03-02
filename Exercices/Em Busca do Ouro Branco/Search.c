#include <stdio.h>
#include <math.h>

int Search(int steps)
{
  scanf("%d", &steps);
  if (steps == 0)
  {
    return 0;
  }
  int right = steps * (steps + steps - 1);
  int left = right + (steps * 2);
  printf("%d %d\n", right, left);

  Search(steps);
}

int main()
{
  int steps;
  Search(steps);

  return 0;
}