/**
 * 2785 - Pirâmide - https://www.beecrowd.com.br/judge/pt/problems/view/2785
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

int N;
vector<vi> caixas;

int memo[101][101];

int dp(int linha, int coluna) {
  if(linha == 1) {
    return memo[linha][coluna] = caixas[linha][coluna];
  }

  int &p = memo[linha][coluna];
  if(p != -1) return p;

  int soma = 0;
  for(int j = 0; j < linha; j++) {
    soma += caixas[linha][coluna + j];
  }

  return p = (soma + min(dp(linha - 1, coluna), dp(linha - 1, coluna + 1)));
}

int main()
{
  speed;
  cin >> N;
  caixas.resize(N + 1, vector<int>(N + 1));

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) cin >> caixas[i][j];
  }

  memset(memo, -1, sizeof(memo));

  cout << dp(N, 1) << endl;

  return 0;
}
