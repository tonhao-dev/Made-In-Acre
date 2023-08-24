/**
 * H - Haja Ordenação
 * Ordenação, STL
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

#define all(x) begin(x), end(x)
#define lll long long int
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second

int main()
{
  speed;
  ll qtd, qtd_cor;
  cin >> qtd >> qtd_cor;

  vector<pll> caixas(qtd);

  for (ll i = 0; i < qtd; i++)
  {
    ll n, cor;
    cin >> n >> cor;
    caixas[i] = make_pair(n, cor);
  }

  vector<pll> aux_caixas(all(caixas));
  sort(all(aux_caixas));

  bool eh_ordenado = true;
  for (ll i = 0; i < aux_caixas.size(); i++)
  {
    if (aux_caixas[i].s != caixas[i].s)
    {
      eh_ordenado = false;
      break;
    }
  }

  cout << (eh_ordenado ? "Y" : "N") << endl;

  return 0;
}
