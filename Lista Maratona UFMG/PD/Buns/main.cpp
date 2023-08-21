/**
 * C. Buns - Codeforces Beta Round 82 (Div. 2) - https://codeforces.com/contest/106/problem/C
 * PD, classe, programação dinâmica, DP
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


class Pao {
  public:
    int recheio;
    int recheio_para_preparo;
    int massa;
    int lucro;

  Pao() {};
  Pao(int a, int b, int c, int d) {
    recheio = a;
    recheio_para_preparo = b;
    massa = c;
    lucro = d;
  }

  int qtd_fabricar() {
    return floor((double)recheio / (double)recheio_para_preparo);
  }
};

int N, M;
vector<Pao> paes;

int memo[15][1010];

int dp(int pao, int massa) {
  if(massa < 0) return -INF;
  if(pao == (M + 1)) return 0;

  int &p = memo[pao][massa];
  if(p != -1) return p;

  auto pao_atual = paes[pao];

  int total_max = -INF;
  for(int i = 0; i <= pao_atual.qtd_fabricar(); i++) {
    total_max = max(total_max, pao_atual.lucro * i + dp(pao + 1, massa - (pao_atual.massa * i)));
  }

  return p = total_max;
}

int main()
{
  speed;
  cin >> N >> M;

  int c, d; cin >> c >> d;
  paes.pb(*new Pao(N, c, c, d));

  for(int i = 0; i < M; i++) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    paes.pb(*new Pao(a, b, c, d));
  }

  memset(memo, -1, sizeof(memo));
  cout << dp(0, N) << endl;

  return 0;
}
