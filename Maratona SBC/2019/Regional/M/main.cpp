/**
 * M - Maratona Brasileira de Comedores de Pipoca
 * Busca binária
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

vll pipocas;
ll competidores, tempo, qtd;

bool eh_possivel(ll chute) {
  ll competidor_atual = 1, resta = chute * tempo;
  for(ll i = 0; i < sz(pipocas); i++) {
    if(resta >= pipocas[i]) resta -= pipocas[i];
    else {
      competidor_atual++;
      resta = chute * tempo;
      i--;
    }
    if(competidor_atual > competidores) return false;
  }

  return true;
}

int main()
{
  speed;
  cin >> qtd >> competidores >> tempo;
  pipocas.assign(qtd, 0);

  for(ll i = 0; i < qtd; i++) cin >> pipocas[i];

  ll l = 0, r = 1e9+1;
  while(l < r) {
    ll m = (l + r) / 2;

    if(!eh_possivel(m)) l = m + 1;
    else r = m;
  }

  cout << l << endl;

  return 0;
}
