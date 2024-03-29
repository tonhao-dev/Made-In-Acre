/**
 * https://judge.beecrowd.com/pt/problems/view/1905
 * Grafos, dfs, backtracking
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG true
#define db(x) \
    if (DEBUG) cout << #x << ": " << x << endl
#define dbpair(x) cout << #x << ": " << x.f << ", " << x.s << endl
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

vector<vector<int>> labirinto(5, vector<int>(5));
vector<vector<bool>> visitado(5, vector<bool>(5));

bool dfs(int i, int j) {
    if (i < 0 || i > 4) return false;
    if (j < 0 || j > 4) return false;

    if (labirinto[i][j] == 1) return false;

    if (visitado[i][j]) return false;
    visitado[i][j] = true;

    if (i == 4 && j == 4) return true;

    bool resp = false;

    resp |= dfs(i, j + 1);  // DIREITA
    resp |= dfs(i + 1, j);  // BAIXO
    resp |= dfs(i, j - 1);  // ESQUERDA
    resp |= dfs(i - 1, j);  // CIMA

    return resp;
}

void solve() {
    labirinto;
    visitado.assign(5, vector<bool>(5));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> labirinto[i][j];
        }
    }

    cout << (dfs(0, 0) ? "COPS" : "ROBBERS") << endl;
}

int main(int argc, char** argv) {
    SPEED;

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}
