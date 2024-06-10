/**
 * https://vjudge.net/problem/UVA-10004
 * Bicoloring
 * DFS, Grafos, graph, bipartidos
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG true
#define db(x)  \
    if (DEBUG) \
    cout << #x << ": " << x << endl
#define dbpair(x) cout << #x << ": " << x.f << ", " << x.s << endl
#define dbvector(vector)          \
    {                             \
        cout << #vector << " = "; \
        for (auto &it : vector)   \
            cout << it << " ";    \
        cout << endl;             \
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

int N, M;

class Grafo {
   public:
    int num_vertices;
    vector<vi> edges;
    vector<int> color;

    Grafo(int n) {
        num_vertices = n;

        edges.resize(num_vertices);
        color.resize(num_vertices);
    }

    void add_edge(int u, int v) {
        edges[u].pb(v);
        edges[v].pb(u);
    }

    // Devolve true quando uma componente pode ser bipartida
    bool dfs(int u, int c) {
        if (color[u] != 0)
            return color[u] == c;

        color[u] = c;

        bool is_bipartite = true;
        for (auto neighbor : edges[u]) {
            is_bipartite &= dfs(neighbor, c == 1 ? 2 : 1);
        }

        return is_bipartite;
    }

    // Devolve true quando todas as componentes são bipartidas
    bool is_bipartite() { return dfs(0, 1); }
};

void solve() {
    Grafo grafo(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        grafo.add_edge(u, v);
    }

    cout << (grafo.is_bipartite() ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
}

int main(int argc, char **argv) {
    SPEED;

    cin >> N;

    while (N != 0) {
        cin >> M;

        solve();

        cin >> N;
    }

    return 0;
}
