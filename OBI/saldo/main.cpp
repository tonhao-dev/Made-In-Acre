/*
* OBI 2013 - Fase 1: Saldo do Vovô
*/


#include <bits/stdc++.h>

#define _                       \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#define INF 1000000007

using namespace std;

int main()
{
  _ int qtd, saldo;
  cin >> qtd >> saldo;

  int menor = INF;
  while (qtd--)
  {
    int saldoDiario;
    cin >> saldoDiario;

    saldo += saldoDiario;
    if (saldo < menor)
    {
      menor = saldo;
    }
  }
  cout << menor << endl;

  return 0;
}
