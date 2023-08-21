/**
 * 1210 - Produção Ótima de Ótima Vodka - https://www.beecrowd.com.br/judge/pt/problems/view/1210
 * PD, programação dinâmica
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

int N, I, M, P;
vi manuntencao;
vi venda;

int memo[2010][2010];
int nxt[2010][2010];

int dp(int periodo, int idade) {
  if(periodo == N + 1) return 0;

  int &p = memo[periodo][idade];
  if(p != -1) return p;

  int vender = INF;
  int nao_vender = INF;

  vender = manuntencao[0] + P - venda[idade] + dp(periodo + 1, 1);
  if(idade < M) nao_vender = manuntencao[idade] + dp(periodo + 1, idade + 1);

  nxt[periodo][idade] = vender <= nao_vender ? 1 : idade + 1;

  return p = min(vender, nao_vender);
}

int main()
{
  speed;
  while(cin >> N >> I >> M >> P) {
    manuntencao.assign(M + 1, 0);
    venda.assign(M + 1, 0);
    for(int i = 0; i  < M; i++) cin >> manuntencao[i];
    for(int i = 1; i <= M; i++) cin >> venda[i];

    for(int i = 0; i <= N; i++) {
      for(int j = 0; j <= M; j++) {
        nxt[i][j] = 0;
        memo[i][j] = -1;
      }
    }

    cout << dp(1, I) << endl;

    int t = 1, idade = I, flag = 0;
    do {
      if(nxt[t][idade] == 1) {
        if(flag) cout << " ";
        flag = 1;
        cout << t;
      }

      idade = nxt[t++][idade];
    } while(t <= N);
    if(!flag) cout << 0;
    cout << endl;
  }

  return 0;
}
