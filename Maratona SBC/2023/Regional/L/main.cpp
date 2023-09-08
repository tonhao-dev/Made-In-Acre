/**
 * L - Lexicograficamente Agradável
 * String, STL
 */

#include <bits/stdc++.h>

using namespace std;

#define speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#define MOD 1000000007

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

#define endl "\n"
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
#define f first
#define s second

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{
  speed;

  string txt; cin >> txt;
  int k; cin >> k;

  map<int, priority_queue<char, vector<char>, greater<char>>> res;

  for(int i = 0; i < sz(txt); i++) {
    int pos = i % k;
    res[pos].push(txt[i]);
  }

  bool teve = false;
  do {
    teve = false;
    for(auto &r : res) {
      if(r.s.empty()) continue;
      cout << r.s.top();
      r.s.pop();
      teve = true;
    }
  } while(teve);
  cout << endl;

  return 0;
}
