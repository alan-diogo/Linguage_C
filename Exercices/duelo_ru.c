#include <stdio.h>

typedef struct card
{
  int type;
  double life;
  double atk;
} Card;

int readcard(Card *attributes)
{
  scanf("%d %lf %lf", &attributes->type, &attributes->atk, &attributes->life);
}
int duel(Card *one, Card *two)
{
  if (one->life <= 0)
    return 0;
  else if (two->life <= 0)
    return 1;
  if (one->type == 1 && two->type == 2)
  {
    two->atk *= 1.15;
    two->life *= 1.15;
  }
  else if (one->type == 2 && two->type == 1)
  {
    one->atk *= 1.15;
    one->life *= 1.15;
  }
  if (one->type == 2 && two->type == 3)
    two->atk *= 1.25;
  else if (one->type == 3 && two->type == 2)
    one->atk *= 1.25;
  if (one->type == 1 && two->type == 3)
    one->life *= 1.3;
  else if (one->type == 3 && two->type == 1)
    two->life *= 1.3;
  // battle
  if (one->life <= two->life)
  {
    two->life -= one->atk;
    if (two->life <= 0)
      return 1;
    else
    {
      one->life -= two->atk;
      if (one->life <= 0)
        return 0;
    }
  }
  else
  {
    one->life -= two->atk;
    if (one->life <= 0)
      return 0;
    else
    {
      two->life -= one->atk;
      if (two->life <= 0)
        return 1;
    }
  }
  if (one->life > two->life)
    return 1;
  else if (one->life < two->life)
    return 0;
  if (one->atk > two->atk)
    return 1;
  else if (one->atk < two->atk)
    return 0;

  return 0;
}

int main()
{
  int pedro = 0, tulio = 0;
  Card pedroCard1;
  Card pedroCard2;
  Card pedroCard3;
  Card tulioCard1;
  Card tulioCard2;
  Card tulioCard3;

  readcard(&pedroCard1);
  readcard(&pedroCard2);
  readcard(&pedroCard3);
  readcard(&tulioCard1);
  readcard(&tulioCard2);
  readcard(&tulioCard3);

  if (duel(&pedroCard1, &tulioCard1) == 1)
  {
    pedro += 1;
    printf("Rodada1: Pedro\n");
  }
  else
  {
    tulio += 1;
    printf("Rodada1: Tulio\n");
  }
  if (duel(&pedroCard2, &tulioCard2) == 1)
  {
    pedro += 1;
    printf("Rodada2: Pedro\n");
  }
  else
  {
    tulio += 1;
    printf("Rodada2: Tulio\n");
  }
  if (duel(&pedroCard3, &tulioCard3) == 1)
  {
    pedro += 1;
    printf("Rodada3: Pedro\n");
  }
  else
  {
    tulio += 1;
    printf("Rodada3: Tulio\n");
  }

  if (pedro > tulio)
    printf("Pedro vitorioso");
  else
    printf("Tulio vitorioso");
  return 0;
}