/**
 * M - Máquina de Café
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

#define db(x) cout << #x << ": " << x << endl
#define sz(x) (ll)(x).size()
#define all(x) begin(x), end(x)
#define pb push_back
#define pf push_front
#define mp make_pair
#define endl "\n"
#define f first
#define s second

int main()
{
  speed;
  ll a, b, c;
  cin >> a >> b >> c;

  ll ans;

  // escolher A
  ans = (b * 2) + ((c + c) * 2);
  // escolher B
  ans = min((a * 2) + (c * 2), ans);
  // escolher C
  ans = min(((a + a) * 2) + (b * 2), ans);

  cout << ans << endl;

  return 0;
}
