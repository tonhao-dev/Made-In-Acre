/**
 * F - Fase
 * Iniciante
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

int main()
{
  speed;
  int N, K; cin >> N >> K;

  vi competidores(N);
  for(auto &i : competidores) cin >> i;

  sort(all(competidores), greater<int>());

  int ans = 1;
  for(int i = 1; i < N; i++) {
    if((i + 1) > K) {
      if(competidores[i] == competidores[i - 1]) ans++;
      else break;
      continue;
    }

    ans++;
  }

  cout << ans << endl;

  return 0;
}
