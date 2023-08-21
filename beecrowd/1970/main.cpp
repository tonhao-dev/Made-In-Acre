/**
 * 1970 - Primeiro Contato - https://www.beecrowd.com.br/judge/pt/problems/view/1970
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

int N, K;
vi musicas;
vi cap;

int memo[101][51][51][51];

int dp(int musica, int a, int b, int c) {
  if(a > cap[0]) return -INF;
  if(b > cap[1]) return -INF;
  if(c > cap[2]) return -INF;
  if(musica == N) return 0;


  int &p = memo[musica][a][b][c];
  if(p != -1) return p;

  int max_minutos = dp(musica + 1, a, b, c);
  max_minutos = max(max_minutos, musicas[musica] + dp(musica + 1, a + musicas[musica], b, c));
  max_minutos = max(max_minutos, musicas[musica] + dp(musica + 1, a, b + musicas[musica], c));
  max_minutos = max(max_minutos, musicas[musica] + dp(musica + 1, a, b, c + musicas[musica]));
  return p = max_minutos;
}

int main()
{
  speed;
  cin >> N >> K;
  musicas.resize(N);
  cap.assign(3, 0);

  for(auto &i : musicas) cin >> i;
  for(int i = 0; i < K; i++) cin >> cap[i];
  memset(memo, -1, sizeof(memo));

  cout << dp(0, 0, 0, 0) << endl;

  return 0;
}
