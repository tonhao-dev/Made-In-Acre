/**
 * Problema: B - Bolsa de Valores
 * Assunto: Programação Dinâmica ou Guloso
 */

#include <bits/stdc++.h>

#define speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<string> vstr;
typedef vector<vll> vvll;

#define db(x) cout << #x << ": " << x << endl
#define sz(x) (ll)(x).size()
#define all(x) begin(x), end(x)
#define pb push_back
#define pf push_front
#define mp make_pair
#define endl "\n"
#define f first
#define s second

int main()
{
  ll dias, taxa;
  cin >> dias >> taxa;

  vll bolsa(dias);

  for (ll i = 0; i < dias; ++i)
    cin >> bolsa[i];

  ll lucroAtual, lucroFinal, lucroMaximo;
  lucroMaximo = 0;
  lucroAtual = lucroFinal = bolsa[0];
  for (ll i = 1; i < dias; ++i)
  {
    if ((lucroAtual > bolsa[i] && (lucroAtual - bolsa[i] >= taxa)) || bolsa[i] < lucroFinal)
    {

      if (lucroAtual - lucroFinal - taxa > 0)
        lucroMaximo += lucroAtual - lucroFinal - taxa;

      lucroAtual = lucroFinal = bolsa[i];
    }

    if (bolsa[i] > lucroAtual)
      lucroAtual = bolsa[i];
  }

  if (lucroAtual - lucroFinal - taxa > 0)
    lucroMaximo += lucroAtual - lucroFinal - taxa;

  cout << lucroMaximo << endl;

  return 0;
}
