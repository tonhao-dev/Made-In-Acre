/**
 * https://judge.beecrowd.com/pt/problems/view/1955
 * See World
 * DFS, Grafos, graph, bipartidos
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

class Grafo {
   public:
    int num_vertices;
    vector<vector<bool>> edges;
    vector<int> color;

    Grafo(int n) {
        num_vertices = n;

        edges.resize(num_vertices, vector<bool>(num_vertices, false));
        color.resize(num_vertices);
    }

    // Devolve true quando uma componente pode ser bipartida
    bool dfs(int u, int c) {
        if (color[u] != 0) return color[u] == c;

        color[u] = c;

        bool is_bipartite = true;
        for (int v = 0; v < num_vertices; v++) {
            if (edges[u][v]) is_bipartite &= dfs(v, c == 1 ? 2 : 1);
        }

        return is_bipartite;
    }

    // Devolve true quando todas as componentes são bipartidas
    bool is_bipartite() {
        bool ans = true;
        for (int u = 0; u < num_vertices; u++) {
            if (color[u] != 0) continue;

            ans &= dfs(u, 1);
        }

        return ans;
    }
};

void solve() {
    int N;
    cin >> N;

    Grafo grafo(N);

    for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {
            bool dialeto;
            cin >> dialeto;

            grafo.edges[u][v] = !dialeto;
        }
    }

    cout << (grafo.is_bipartite() ? "Bazinga!" : "Fail!") << endl;
}

int main(int argc, char** argv) {
    SPEED;

    solve();

    return 0;
}
