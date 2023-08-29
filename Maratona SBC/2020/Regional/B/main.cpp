/**
 * B - Batalha Naval
 * Simulação, adhoc
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

vector<vi> tabuleiro(11, vi(11, 0));

int main()
{
  speed;
  int qtd; cin >> qtd;

  bool certo = true;
  while(qtd--) {
    int dir, l, r, c;
    cin >> dir >> l >> r >> c;

    if(!certo) continue;

    if(r < 1 || r > 10 || c < 1 || c > 10) {
      certo = false;
      continue;
    }
    if(dir == 0 && (c + l) - 1 > 10) {
      certo = false;
      continue;
    }
    if(dir == 1 && (r + l) - 1 > 10) {
      certo = false;
      continue;
    }

    if(dir == 0) {
      for(int j = c; j <= (c + l) - 1; j++) {
        if(tabuleiro[r][j] == 1) {
          certo = false;
          break;
        }

        tabuleiro[r][j] = 1;
      }
    }

    if(dir == 1) {
      for(int i = r; i <= (r + l) - 1; i++) {
        if(tabuleiro[i][c] == 1) {
          certo = false;
          break;
        }

        tabuleiro[i][c] = 1;
      }
    }
  }

  cout << (certo ? "Y" : "N") << endl;

  return 0;
}
