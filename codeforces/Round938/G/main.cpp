/**
 * [Link]
 * [Título da questão]
 * [Assuntos]
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG false
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

int n, m, resp = INT_MIN;
vector<vi> matriz;

bool ehValido(int i, int j) {
    return ((i >= 0 && i < n) && (j >= 0 && j < m));
}

int dfs(int i, int j, int mdc) {
    if (!ehValido(i, j)) return 0;
    if (mdc == 1) return 1;
    if (i == n - 1 && j == m - 1) return __gcd(mdc, matriz[i][j]);

    int atual = __gcd(mdc, matriz[i][j]);

    return max(dfs(i + 1, j, atual), dfs(i, j + 1, atual));
}

void solve() {
    cin >> n >> m;

    matriz.resize(n);
    for (int i = 0; i < n; i++) matriz[i].resize(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> matriz[i][j];
    }

    cout << dfs(0, 0, matriz[0][0]) << endl;
}

int main(int argc, char** argv) {
    SPEED;

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}
