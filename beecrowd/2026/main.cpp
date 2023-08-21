/**
 * 2026 - Árvore de Natal - https://www.beecrowd.com.br/judge/pt/problems/view/2026
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

int P, cap;
vi v;
vi w;

int memo[110][1010];

int dp(int presente, int peso) {
  if(peso > cap) return -INF;
  if(presente == P) return 0;

  int &p = memo[presente][peso];
  if(p != -1) return p;

  return p = max(dp(presente + 1, peso), v[presente] + dp(presente + 1, peso + w[presente]));
}

int main()
{
  speed;
  int G; cin >> G;
  int caso = 1;

  while(G--) {
    memset(memo, -1, sizeof(memo));

    cin >> P >> cap;
    v.resize(P);
    w.resize(P);

    for(int i = 0; i < P; i++) cin >> v[i] >> w[i];

    cout << "Galho " << caso << ":" << endl;
    cout << "Numero total de enfeites: " << dp(0, 0) << endl;
    cout << endl;
    caso++;
  }

  return 0;
}
