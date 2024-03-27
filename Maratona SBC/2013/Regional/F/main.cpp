/**
 * F - Triângulos
 * Paradigmas, Busca Binária, Geometria
*/

#include <bits/stdc++.h>

using namespace std;

#define speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#define MOD 1000000007

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

#define endl "\n"
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
#define f first
#define s second

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
  speed;

  int n;

  while(cin >> n) {
    int acumulador = 0;
    vi vertices(n);

    for(int i = 0; i < n; i++) {
      int x; cin >> x;
      acumulador += x;
      vertices[i] = acumulador;
    }

    if(acumulador % 3 != 0) {
      cout << 0 << endl;
      continue;
    }

    int ans = 0;
    acumulador /= 3;
    for(int i = 0; i < n; i++) {
      bool tem_na_mesma = binary_search(all(vertices), vertices[i] + acumulador * 1);
      bool tem_oposto = binary_search(all(vertices), vertices[i] + acumulador * 2);
      if(tem_na_mesma && tem_oposto) ans++;
    }

    cout << ans << endl;
  }

  return 0;
}
