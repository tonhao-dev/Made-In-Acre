/**
 * https://neps.academy/br/exercise/289
 * Tá Ligado?
 * Grafos
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG true
#define db(x) \
    if (DEBUG) cout << #x << ": " << x << endl
#define dbpair(x) \
    if (DEBUG) cout << #x << ": " << x.f << ", " << x.s << endl
#define dbvector(vector)                           \
    {                                              \
        cout << #vector << " = ";                  \
        for (auto& it : vector) cout << it << " "; \
        cout << endl;                              \
    }
#define dbmap(map)                          \
    for (auto e : map)                      \
        cout << e.first << " " << e.second; \
    cout << endl
#define all(x) begin(x), end(x)
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second
#define MOD 1e9 + 7
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vi> matrix(n + 1, vi(n + 1));

    for (int query = 0; query < m; query++) {
        int t, a, b;
        cin >> t >> a >> b;

        if (t == 1) {
            matrix[a][b] = 1;
            matrix[b][a] = 1;
        } else {
            cout << matrix[a][b] << endl;
        }
    }
}

int main(int argc, char** argv) {
    SPEED;

    solve();

    return 0;
}
