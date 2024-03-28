/**
 *  Problema A - Troca de Bicicletas
 * Adhoc, implementação
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

void solve() {
    int n; cin >> n;

    vector<int> p(n);
    for(auto &i : p) cin >> i;

    for(int pessoa = 1; pessoa <= n; pessoa++) {
        int i = pessoa - 1;
        vector<int> ans;

        ans.pb(i + 1);
        i = p[i] - 1;
        while((i + 1) != pessoa) {
            ans.pb(i + 1);
            i = p[i] - 1;
        }

        int flag = 0;
        for(auto a : ans) {
            if(flag) cout << " ";
            flag = 1;
            cout << a;
        }
        cout << endl;
    }
}

int main() {
    speed;

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
