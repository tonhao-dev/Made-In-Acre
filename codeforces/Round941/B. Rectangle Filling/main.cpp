/**
 * [Link]
 * [Título da questão]
 * [Assuntos]
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

    vector<string> grid(n);
    for (string& linha : grid) cin >> linha;

    if (grid[0][0] == grid[n - 1][m - 1]) {
        cout << "YES" << endl;
        return;
    }

    if (grid[0][m - 1] == grid[n - 1][0]) {
        cout << "YES" << endl;
        return;
    }

    bool linhaSuperiorIgual = true;
    char borda = grid[0][0];
    for (int i = 0; i < m; i++) {
        if (grid[0][i] != borda) {
            linhaSuperiorIgual = false;
            break;
        }
    }

    bool colunaDireitaIgual = true;
    borda = grid[0][m - 1];
    for (int i = 0; i < n; i++) {
        if (grid[i][m - 1] != borda) {
            colunaDireitaIgual = false;
            break;
        }
    }

    bool linhaInferiorIgual = true;
    borda = grid[n - 1][0];
    for (int i = 0; i < m; i++) {
        if (grid[n - 1][i] != borda) {
            linhaInferiorIgual = false;
            break;
        }
    }

    bool colunaEsquerdaIgual = true;
    borda = grid[0][0];
    for (int i = 0; i < n; i++) {
        if (grid[i][0] != borda) {
            colunaEsquerdaIgual = false;
            break;
        }
    }

    if (linhaSuperiorIgual && linhaInferiorIgual && grid[0][0] != grid[n - 1][0]) {
        cout << "NO" << endl;
        return;
    }

    if (colunaEsquerdaIgual && colunaDireitaIgual && grid[0][0] != grid[0][m - 1]) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}

int main(int argc, char** argv) {
    SPEED;

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}
