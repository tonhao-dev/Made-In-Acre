/**
 * 1624 - Promoção - https://www.beecrowd.com.br/judge/pt/problems/view/1624
 * PD, programação dinâmica, algoritmo da mochila
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

int N, cap;
vi v;
vi w;

int memo[1010][1010];

int dp(int produto, int peso) {
  if(peso > cap) return -INF;
  if(produto == N) return 0;

  int &p = memo[produto][peso];
  if(p != -1) return p;

  return p = max(dp(produto + 1, peso), v[produto] + dp(produto + 1, peso + w[produto]));
}

int main()
{
  speed;
  while(cin >> N && N) {
    memset(memo, -1, sizeof(memo));

    v.resize(N);
    w.resize(N);

    for(int i = 0; i < N; i++) cin >> v[i] >> w[i];

    cin >> cap;

    cout << dp(0, 0) << endl;
  }

  return 0;
}
