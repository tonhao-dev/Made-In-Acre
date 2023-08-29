/**
 * I - Interruptores
 * Adhoc, Simulação
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

bool TahDesligado(vector<bool> &lampadas)
{
  return find(lampadas.begin(), lampadas.end(), true) == lampadas.end();
}

string PegarConfiguracao(vector<bool> &lampadas)
{
  string config = "";
  for (ll i = 0; i < lampadas.size(); i++)
  {
    config += to_string(lampadas[i]);
  }

  return config;
}

int main()
{
  speed;
  ll n_interruptor, n_lampadas;
  cin >> n_interruptor >> n_lampadas;

  vector<bool> lampadas(n_lampadas, false);

  ll n_lampadas_acessas;
  cin >> n_lampadas_acessas;

  while (n_lampadas_acessas--)
  {
    ll lampada;
    cin >> lampada;
    lampadas[lampada - 1] = true;
  }

  vector<vector<ll>> interruptores(n_interruptor, vector<ll>());

  for (ll i = 0; i < n_interruptor; i++)
  {
    ll qtd;
    cin >> qtd;
    while (qtd--)
    {
      ll interruptor;
      cin >> interruptor;
      interruptores[i].pb(interruptor - 1);
    }
  }

  unordered_map<string, int> configuracoes;

  ll ans = 0;

  while (!TahDesligado(lampadas))
  {
    string config = PegarConfiguracao(lampadas);
    if (configuracoes[config])
    {
      ans = -1;
      break;
    }
    else
    {
      configuracoes[config] = 1;
    }

    for (auto interruptor : interruptores)
    {
      if (TahDesligado(lampadas))
      {
        break;
      }

      for (auto lampada : interruptor)
      {
        lampadas[lampada] = !lampadas[lampada];
      }

      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
