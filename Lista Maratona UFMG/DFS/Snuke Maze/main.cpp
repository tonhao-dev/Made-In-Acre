/**
 * https://atcoder.jp/contests/abc308/tasks/abc308_d
 * D - Snuke Maze
 * Grafo, graph, componente conexo, grid, string, dfs
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
#define INF 0x3f3f3f3f;
#define LINF 0x3f3f3f3f3f3f3f3fll;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

int n, m;

const vector<pair<int, int>> moves = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}};

bool ehValid(int x, int y) {
    return (x >= 0 && x < n) && (y >= 0 && y < m);
}

void solve() {
    cin >> n >> m;

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    pii start = {0, 0};
    stack<pair<int, pii>> pilha;

    pilha.push({0, start});
    string snuke = "snuke";
    bool ans = false;

    while (!pilha.empty()) {
        auto atual = pilha.top();

        if (atual.s.f == n - 1 && atual.s.s == m - 1) {
            ans = true;
            break;
        }

        grid[atual.s.f][atual.s.s] = 'X';
        pilha.pop();

        for (auto mov : moves) {
            int x = atual.s.f + mov.f, y = atual.s.s + mov.s;

            if (!ehValid(x, y)) continue;

            if (grid[x][y] != snuke[(atual.f + 1) % snuke.size()]) continue;

            pilha.push({atual.f + 1, {x, y}});
        }
    }

    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main(int argc, char** argv) {
    SPEED;

    solve();

    return 0;
}
