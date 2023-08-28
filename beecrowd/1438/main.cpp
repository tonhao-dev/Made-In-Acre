/**
 * Desempilhando Caixas - https://www.beecrowd.com.br/judge/pt/problems/view/1438
 * Adhoc, gulosos
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

int main() {
  speed;

  while(true) {
    int N, P; cin >> N >> P;
    if(N == 0 && P == 0) break;

    vector<vector<int>> pilhas(P);

    int x = 0, y = 0;
    for(int i = 0; i < P; i++) {
      int n; cin >> n;
      pilhas[i].resize(n);
      for(int j = 0; j < n; j++) {
        cin >> pilhas[i][j];
        if(pilhas[i][j] == 1) {
          x = i;
          y = j;
        }
      }
    }

    int esq, dir; esq = dir = 0;
    for(int i = x + 1; i < P; i++) {
      if(pilhas[i].size() > y) esq += pilhas[i].size() - y;
      else break;
    }
    for(int i = x - 1; i >= 0; i--) {
      if(pilhas[i].size() > y) dir += pilhas[i].size() - y;
      else break;
    }

    cout << (min(esq, dir) + pilhas[x].size() - y - 1) << endl;
  }

  return 0;
}
