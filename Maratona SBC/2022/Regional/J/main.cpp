/**
 * J - Jogando 23
 * Simulação, Adhoc
 */

#include <bits/stdc++.h>

#define speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define lll long long int
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second

ll ptts[14] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
ll qtd_cartas[14];

int main()
{
  speed;
  ll qtd;
  cin >> qtd;

  ll joao = 0;
  ll maria = 0;

  ll jogadas = 2;

  while (jogadas--)
  {
    ll carta;
    cin >> carta;
    joao += ptts[carta];
    qtd_cartas[carta]++;
  }

  jogadas = 2;

  while (jogadas--)
  {
    ll carta;
    cin >> carta;
    maria += ptts[carta];
    qtd_cartas[carta]++;
  }

  while (qtd--)
  {
    ll carta;
    cin >> carta;

    maria += ptts[carta];
    joao += ptts[carta];
    qtd_cartas[carta]++;
  }

  for (ll i = 1; i <= 13; i++)
  {
    if (qtd_cartas[i] == 4)
      continue;

    ll qtd_pontos_carta = ptts[i];

    if (maria + qtd_pontos_carta == 23)
    {
      cout << i << endl;
      return 0;
    }

    if (((joao + qtd_pontos_carta) > 23) && ((maria + qtd_pontos_carta) < 23))
    {
      cout << i << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}
