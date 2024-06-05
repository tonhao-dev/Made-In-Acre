/**
 * https://vjudge.net/problem/LightOJ-1012
 * A - Guilty Prince
 * Grafo, graph, componente conexo, grid
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

int n, m;

const vector<pair<int, int>> moves = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}};

bool ehValid(int x, int y) {
    return (x >= 0 && x < n) && (y >= 0 && y < m);
}

void solve(int t) {
    cin >> m >> n;

    pii start;
    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];

        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '@') start = {i, j};
        }
    }

    queue<pii> fila;
    fila.push(start);

    int ans = 0;
    while (!fila.empty()) {
        pii atual = fila.front();

        fila.pop();

        if (grid[atual.f][atual.s] == '.' || grid[atual.f][atual.s] == '@') {
            ans++;
            grid[atual.f][atual.s] = 'X';
        }

        for (auto mov : moves) {
            int x = atual.f + mov.f, y = atual.s + mov.s;

            if (!ehValid(x, y)) continue;

            if (grid[x][y] != '.') continue;

            fila.push({x, y});
        }
    }

    cout << "Case " << t << ": " << ans << endl;
}

int main(int argc, char** argv) {
    SPEED;

    int t;
    cin >> t;

    int n = t;

    while (t--) solve(n - t);

    return 0;
}
