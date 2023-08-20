/**
 * https://atcoder.jp/contests/dp/tasks/dp_c
 * PD, programação dinâmica
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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll N;
vvll atividades;

ll memo[100010][3];

ll dp(ll dia, ll ultimo_selecionado) {
  if(dia == N) return 0;

  ll &p = memo[dia][ultimo_selecionado];
  if(p != -1) return p;

  ll maximo = -LINF;
  for(ll i = 0; i < 3; i++) {
    if(i == ultimo_selecionado) continue;
    maximo = max(maximo, dp(dia + 1, i) + atividades[dia][i]);
  }

  return p = maximo;
}

int main()
{
  speed;
  cin >> N;
  atividades.resize(N, vll(3));

  for(ll i = 0; i < N; i++)
    for(ll j = 0; j < 3; j++) cin >> atividades[i][j];

  memset(memo, -1, sizeof memo);

  ll ans = -LINF;
  for(ll i = 0; i < 3; i++) {
    ans = max(ans, dp(1, i) + atividades[0][i]);
  }

  cout << ans << endl;

  return 0;
}
