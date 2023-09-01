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

int T, M, N;
int memo[112345][52];

int dp(int i, int j) {
  if(j == T) return memo[i][j] = 1;

  int &p = memo[i][j];
  if(p != -1) return p;

  int ans = 0;
  if(i - 1 >= M) ans = (ans + dp(i - 1, j + 1)) % MOD;
  if(i + 1 <= N) ans = (ans + dp(i + 1, j + 1)) % MOD;

  return p = ans;
}

int main()
{
  speed;
  cin >> T >> M >> N;
  T--;

  memset(memo, -1, sizeof(memo));

  int ans = 0;
  for(int i = M; i <= N; i++) {
    ans = (ans + dp(i, 0)) % MOD;
  }

  cout << ans << endl;

  return 0;
}
