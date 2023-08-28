/**
 * Mega Inversões - https://www.beecrowd.com.br/judge/pt/problems/view/3248
 * Estruturas e bibliotecas
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

int N;
vector<ll> T1(100005, 0), T2(100005, 0);

void update(vector<ll> &t, int x, ll v)
{
  while (x > 0)
  {
    t[x] += v;
    x -= x & -x;
  }
}

ll query(vector<ll> &t, int x)
{
  ll ret = 0;
  while (x <= N)
  {
    ret += t[x];
    x += x & -x;
  }
  return ret;
}

int main()
{
  speed;
  cin >> N;
  ll ans = 0;

  for(int i = 0; i < N; i++) {
    int x; cin >> x;

    update(T1, x, 1);
    int q = query(T1, x + 1);
    update(T2, x, q);

    ans += query(T2, x + 1);
  }

  cout << ans << endl;
}
