/**
 * Problema: J - Jogo da Estratégia
 * Assunto: Adhoc, STL
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


int main()
{
  speed;
  int J, R; cin >> J >> R;

  vi pontos_jogadores(J, 0);

  for(int i = 0; i < R; i++) {
    for(int j = 0; j < J; j++) {
      int ptn; cin >> ptn;
      pontos_jogadores[j] += ptn;
    }
  }

  pii ans = mp(sz(pontos_jogadores), pontos_jogadores[sz(pontos_jogadores) - 1]);
  for(int i = sz(pontos_jogadores) - 1; i >= 0; i--) {
    if(pontos_jogadores[i] > ans.s) {
      ans = mp(i + 1, pontos_jogadores[i]);
    }
  }

  cout << ans.f << endl;

  return 0;
}
