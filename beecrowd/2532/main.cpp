/**
 * 2532 | Demogorgon - https://www.beecrowd.com.br/judge/pt/problems/view/2532
 * programação dinâmica - pd
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

ll N, P;
vector<pll> feiticos;

ll memo[1010][2010];

ll dp(ll feitico, ll vida) {
  if(vida <= 0) return 0;
  if(feitico == N) {
    if(vida > 0) return INF;
    return 0;
  }

  ll &p = memo[feitico][vida];
  if(p != -1) return p;

  return p = min(
    dp(feitico + 1, vida - feiticos[feitico].f) + feiticos[feitico].s,
    dp(feitico + 1, vida)
  );
}

int main()
{
  speed;
  while(cin >> N >> P) {
    feiticos.resize(N);
    for(auto &i : feiticos) cin >> i.f >> i.s;

    ll soma_dano = 0;
    for(auto feitico : feiticos) soma_dano += feitico.f;

    if(soma_dano < P) {
      cout << -1 << endl;
      continue;
    }

    memset(memo, -1, sizeof(memo));
    cout << dp(0, P) << endl;
  }

  return 0;
}
