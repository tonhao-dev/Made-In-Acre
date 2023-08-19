// https://www.beecrowd.com.br/judge/pt/problems/view/1798

/*
	@autor: Ezequiel Soares da Silva;
	@data: 15/08/2023;
	@nome: Cortando Canos;
    Programação dinâmica
*/

#include <bits/stdc++.h>

#define speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<string> vstr;
typedef vector<vll> vvll;

#define print_vector(vector) \
  for (auto x : vector)      \
    cout << x << " ";        \
  cout << endl
#define db(x) cout << #x << ": " << x << endl
#define sz(x) (ll)(x).size()
#define all(x) begin(x), end(x)
#define pb push_back
#define pf push_front
#define mp make_pair
#define endl "\n"
#define f first
#define s second

ll N, T;
vector<pll> canos;
unordered_map<ll, ll> memo;

ll max_lucro(ll tamanho) {
  if(tamanho == 0) return 0;
  if(memo.count(tamanho)) return memo[tamanho];

  for(ll i = 0; i < N; i++) {
    if(canos[i].f > tamanho) continue;
    memo[tamanho] = max(memo[tamanho], max_lucro(tamanho - canos[i].f) + canos[i].s);
  }

  return memo[tamanho];
}

int main()
{
  speed;
  cin >> N >> T;
  canos.assign(N, {0, 0});

  for(ll i = 0; i < N; i++) cin >> canos[i].f >> canos[i].s;
  cout << max_lucro(T) << endl;

  return 0;
}
