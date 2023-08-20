/**
 * 1838 | A Pedra Filosofal - https://www.beecrowd.com.br/judge/pt/problems/view/1838
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

ll N;
vector<pll> req;
ll memo[1010][3601];

ll dp(ll pesquisador, ll ant) {
  if(pesquisador == N) return 0;
  if(req[pesquisador].f < ant) return dp(pesquisador + 1, ant);

  ll &p = memo[pesquisador][ant];
  if(p != -1) return p;

  return p = max(
    dp(pesquisador + 1, ant),
    abs(req[pesquisador].f - req[pesquisador].s) + dp(pesquisador + 1, req[pesquisador].s)
  );
}

int main()
{
  speed;
  cin >> N;
  req.resize(N);

  for(auto &i : req) cin >> i.f >> i.s;
  memset(memo, -1, sizeof(memo));
  sort(all(req));

  cout << dp(0, 0) << endl;

  return 0;
}
