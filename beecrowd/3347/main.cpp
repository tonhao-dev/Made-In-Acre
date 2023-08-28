/**
 * Ancestralidade - https://www.beecrowd.com.br/judge/pt/problems/view/3347
 * Strings, simulação
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

int N, P;
vector<string> genomas;
string meu_genoma;

void solve() {
  string ant;
  vi index(N + 1, 1);
  int last_index = -1;
  bool deu_match = false;
  for(int i = 0; i < P; i++) {
    deu_match = false;
    int inner_last_index = -1;
    ant += meu_genoma[i];

    for(int j = 0; j < N; j++) {
      if(genomas[j][i] == meu_genoma[i] && index[j] == 1) {
        deu_match = true;
        if(inner_last_index == -1) inner_last_index = j;
      } else {
        index[j] = 0;
      }
    }

    if(inner_last_index != -1) last_index = inner_last_index;
    if(!deu_match && ant.size() == 1) {
      cout << meu_genoma[i] << " " << -1 << endl;
      ant.clear();
      index.assign(N + 1, 1);
      last_index = -1;
      continue;
    }

    if(!deu_match && ant.size() > 1) {
      ant.pop_back();
      cout << ant << " " << last_index + 1 << endl;
      ant.clear();
      index.assign(N + 1, 1);
      last_index = -1;
      i--;
      continue;
    }
  }

  if(!deu_match && ant.size() == 1) {
    cout << ant << " " << -1 << endl;
    ant.clear();
    index.assign(N + 1, 1);
    last_index = -1;
  }

  if(!deu_match && ant.size() > 1) {
    ant.pop_back();
    cout << ant << " " << last_index + 1 << endl;
    ant.clear();
    index.assign(N + 1, 1);
    last_index = -1;
  }

  if(deu_match) {
    cout << ant << " " << last_index + 1 << endl;
  }
}

int main() {
  speed;
  cin >> P >> N;
  genomas.resize(N);

  for(auto &i : genomas) cin >> i;
  cin >> meu_genoma;

  solve();

  return 0;
}
