#include <stdio.h>
#include <stdbool.h>

int primeiro_digito(int num)
{
  if (num >= 10)
  {
    return primeiro_digito(num / 10);
  }
  return num;
}

int coprimo(int a, int b, int count)
{
  if (count > a || count > b)
    return 1;
  if (a % count == 0 && b % count == 0)
    return 0;
  return coprimo(a, b, count + 1);
}

int fibo(int valor, int a, int b)
{
  if (a == valor)
    return 1;
  if (a > valor)
    return 0;
  return fibo(valor, b, a + b);
}

typedef struct Card
{
  int def;
  int atk;
} Card;

typedef struct friends
{
  int confidence;
  char hungry;
} Friends;

int Battle(Card ekul, Card luke)
{
  // Ekul atk
  luke.def -= ekul.atk;
  if (luke.def <= 0)
  {
    printf("Ekul venceu o round!\nVida restante: %d\n\n", ekul.def);
    return 1;
  }

  // Luke atk
  ekul.def -= luke.atk;
  if (ekul.def <= 0)
  {
    printf("Luke venceu o round!\nVida restante: %d\n\n", luke.def);
    return 0;
  }

  return Battle(ekul, luke);
}

int ReadFriends(int numFriends, int life, int bonus)
{
  if (numFriends == 0)
    return bonus;

  Friends friend;
  scanf("%d %c", &friend.confidence, &friend.hungry);

  if (friend.hungry == 'F')
  {
    if (fibo(friend.confidence, 0, 1))
    {
      bonus += friend.confidence % 100;
    }
  }
  else if (friend.hungry == 'C')
  {
    if (coprimo(friend.confidence, life, 2))
    {
      bonus += primeiro_digito(friend.confidence) * 10;
    }
  }

  return ReadFriends(numFriends - 1, life, bonus);
}

void CountRounds(int rounds, int ekul_wins, int luke_wins)
{
  if (rounds == 0)
  {
    if (ekul_wins > luke_wins)
    {
      printf("Ekul liberou a entrada do RU!\n");
    }
    else
    {
      printf("Luke concluiu seu plano maligno!\n");
    }
    return;
  }

  Card ekul, luke;
  int M;

  scanf("%d %d", &ekul.def, &ekul.atk);
  scanf("%d %d", &luke.def, &luke.atk);
  scanf("%d", &M);

  int BonusDef = ReadFriends(M, ekul.def, 0);
  int BonusAtk = BonusDef / 2;

  ekul.def += BonusDef;
  ekul.atk += BonusAtk;

  int result = Battle(ekul, luke);

  if (result == 1)
    ekul_wins++;
  else
    luke_wins++;

  CountRounds(rounds - 1, ekul_wins, luke_wins);
}

int main()
{
  int N;
  scanf("%d", &N);
  CountRounds(N, 0, 0);
  return 0;
}