#include <stdio.h>
#include <stdbool.h>
int primeiro_digito(int num)
{
  if (num >= 10)
  {
    num /= 10;
  }
  else
  {
    return num;
  }

  return primeiro_digito(num);
}
int coprimo(int a, int b, int count)
{

  if (count > a || count > b)
    return true;
  if (a % count == 0 && b % count == 0)
    return false;

  return coprimo(a, b, count + 1);
}
int fibo(int valor, int a, int b)
{
  if (a == valor)
    return true;
  if (a > valor)
    return false;
  return fibo(valor, b, a + b);
}

typedef struct Card
{
  double atk;
  double def;
} Card;
typedef struct friends
{
  int confidence;
  char hungry;
} Friends;

int ReadFriends(int numFriends, int life, int countBonus)
{

  if (numFriends == 0)
  {
    return countBonus;
  }

  Friends friend;
  scanf("%d %c", &friend.confidence, &friend.hungry);

  if (fibo(friend.confidence, 0, 1) && friend.hungry == 'F')
  {
    countBonus += friend.confidence % 100;
  }
  else if (coprimo(friend.confidence, life, 2) && friend.hungry == 'C')
  {
    countBonus += primeiro_digito(friend.confidence) * 10;
  }

  ReadFriends(--numFriends, life, countBonus);
}
void CountRounds(int NRounds)
{
  if (NRounds == 0)
  {
  }
  Card ekul;
  Card luke;
  int numFriends;
  scanf("%lf %lf", &ekul.atk, &ekul.def);
  scanf("%lf %lf", &luke.atk, &luke.def);
  scanf("%d", &numFriends);
  double BonusDef = ReadFriends(numFriends, ekul.def, 0);
  double BonusAtk = BonusDef / 2;
  ekul.atk += BonusAtk;
  ekul.def += BonusDef;

  Beattle(ekul, luke);

  Rounds(--NRounds);
}

int Battle(Card ekull, Card luke)
{
  luke.def -= ekull.atk;
  if (luke.def >= 0)
  {
    return 1;
  }
}

int main()
{

  int rounds;
  scanf("%d", &rounds);

  CountRounds(rounds);
}