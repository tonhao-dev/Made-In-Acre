/**
 * https://cses.fi/problemset/task/1668
 * F - Building Teams
 * dfs and similar, dsu, graphs, grafos
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG false
#define db(x)  \
    if (DEBUG) \
    cout << #x << ": " << x << endl
#define dbpair(x) \
    if (DEBUG)    \
    cout << #x << ": " << x.f << ", " << x.s << endl
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

class Graph {
   public:
    int n_vertex;
    vector<vi> edges;
    vector<bool> visited;
    vi color;
    bool impossible;

    Graph(int n) {
        n_vertex = n + 1;
        edges.resize(n + 1);
        visited.resize(n + 1);
        color.resize(n + 1);
        impossible = false;
    }

    void add_edge(int u, int v) {
        edges[u].pb(v);
        edges[v].pb(u);
    }

    void dfs(int origin) {
        vi parent(n_vertex, -1);
        stack<int> pilha;

        visited[origin] = true;
        parent[origin] = origin;
        color[origin] = 0;
        pilha.push(origin);

        while (!pilha.empty()) {
            int current = pilha.top();

            pilha.pop();

            for (auto neighbor : edges[current]) {
                if (visited[neighbor] && neighbor == parent[current])
                    continue;

                if (visited[neighbor] && color[current] == color[neighbor]) {
                    impossible = true;
                    return;
                };

                pilha.push(neighbor);
                parent[neighbor] = current;
                visited[neighbor] = true;
                color[neighbor] = (color[current] + 1) % 2;
            }
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    Graph graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph.add_edge(u, v);
    }

    for (int i = 1; i <= n; i++) {
        if (!graph.visited[i])
            graph.dfs(i);

        if (graph.impossible) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << graph.color[i] + 1 << " ";
    }
    cout << endl;
}

int main(int argc, char **argv) {
    SPEED;

    solve();

    return 0;
}
