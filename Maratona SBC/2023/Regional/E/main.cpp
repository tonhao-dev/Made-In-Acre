/**
 * E - Extraindo Pólen
 * Adhoc, implementação
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

int soma(int n)
{
  int ans = 0;
  while (n)
  {
    ans += n % 10;
    n /= 10;
  }
  return ans;
}

int main()
{
  speed;
  int pos = 0;
  // poderia ser um array com tamanho 10^6, cada posicao o tanto de polens
  unordered_map<int, int> polen;

  int n, k;
  cin >> n >> k;
  int max_polen = -INF;
  while (n--) {
    int v; cin >> v;
    polen[v]++;
    max_polen = max(max_polen, v);
  }

  bool conseguiu = false;
  int atual_polen = max_polen;
  for (int i = atual_polen; i >= 0; i--)
  {
    if(!polen.count(i)) continue;
    auto valor = i;
    auto qtd = polen[i];

    auto retirado = soma(valor);

    polen[valor - retirado] += qtd;
    pos += qtd;

    if(pos >= k) {
      conseguiu = true;
      cout << retirado << endl;
      break;
    }
  }

  if(!conseguiu) cout << 0 << endl;

  return 0;
}
