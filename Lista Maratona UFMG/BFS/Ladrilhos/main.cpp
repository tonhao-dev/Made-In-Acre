/**
 * https://neps.academy/br/exercise/122
 * Ladrilhos, SBC 2016
 * Grafos, graph, bfs, grid
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
    set<pii> visited;

const vector<pair<int, int>> moves = {
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1},
};

bool ehValid(int x, int y) {
    return (x >= 0 && x < n) && (y >= 0 && y < m);
}

int bfs(vector<vi> &grid, int i, int j) {
    queue<pii> fila;
    int area = 1;

    fila.push({i, j});
    visited.insert({i, j});

    while(!fila.empty()) {
        pii atual = fila.front();
        fila.pop();

        for(int i=0;i<moves.size(); i++ ) {
            int x = atual.f + moves[i].f, y = atual.s + moves[i].s;

            if(!ehValid(x, y)) continue;

            if(grid[x][y] != grid[atual.f][atual.s]) continue;

            if(visited.find({ x, y}) != visited.end()) continue;

            area++;
            fila.push({ x, y });
            visited.insert({ x, y });
        }
    }

    return area;
}

void solve() {
    cin >> n >> m;

    vector<vi> grid(n, vi(m));

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> grid[i][j];
        }
    }

    int ans = INF;
    visited.clear();

    for(int i=0; i<n;i++) {
        for(int j=0;j<m;j++) {
            if(visited.find({i, j}) != visited.end()) continue;

            ans = min(ans, bfs(grid, i, j));
        }
    }

    cout << ans << endl;
}

int main(int argc, char** argv) {
    SPEED;

    solve();

    return 0;
}