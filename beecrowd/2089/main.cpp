/**
 * 2089 - Lanchonete - https://www.beecrowd.com.br/judge/pt/problems/view/2089
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

ll V, N;
vll moedas;

ll memo[1010][10010];

ll dp(ll moeda, ll soma) {
  if(moeda == N) return soma == V;
  if(soma > V) return 0;
  if(soma == V) return 1;

  ll &p = memo[moeda][soma];
  if(p != -1) return p;

  return p = (dp(moeda + 1, soma + moedas[moeda]) || dp(moeda + 1, soma));
}

int main()
{
  speed;

  while(true) {
    cin >> V >> N;
    if(V == 0 && N == 0) break;
    moedas.resize(N);
    for(auto &i : moedas) cin >> i;

    memset(memo, -1, sizeof(memo));
    cout << (dp(0, 0) ? "sim" : "nao") << endl;
  }

  return 0;
}
