/**
 * https://atcoder.jp/contests/dp/tasks/dp_d
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

ll N, W;
vll w, v;

ll memo[101][100010];

ll dp(ll item, ll capacidade) {
  if(capacidade < 0) return -LINF;
  if(item == N) return 0;

  ll &p = memo[item][capacidade];
  if(p != -1) return p;

  return p = max(dp(item + 1, capacidade), dp(item + 1, capacidade - w[item]) + v[item]);
}

int main()
{
  speed;
  cin >> N >> W;
  w.resize(N); v.resize(N);

  for(ll i = 0; i < N; i++) cin >> w[i] >> v[i];
  memset(memo, -1, sizeof memo);
  cout << dp(0, W) << endl;

  return 0;
}
