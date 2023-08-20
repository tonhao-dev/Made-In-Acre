/**
 * 2446 - Troco - https://www.beecrowd.com.br/judge/pt/problems/view/2446
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

int V, M;
vi moedas;
bool dp[100001];

int main()
{
  speed;
  cin >> V >> M;
  moedas.resize(M);

  for (int &i : moedas) cin >> i;

  memset(dp, false, sizeof(dp));
  dp[0] = true;

  for (int i = 0; i < M; i++) {
    for (int j = V; j >= moedas[i]; j--) {
      dp[j] = dp[j] || dp[j - moedas[i]];
    }
  }

  cout << (dp[V] ? "S" : "N") << endl;

  return 0;
}
