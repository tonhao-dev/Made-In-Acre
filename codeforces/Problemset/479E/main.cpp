/**
 * https://codeforces.com/contest/977/problem/E
 * E. Cyclic Components
 * dfs and similar, dsu, graphs
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

class Graph {
   public:
    int n_vertex;
    vector<vi> edges;
    vector<bool> visited;

    Graph(int n) {
        n_vertex = n + 1;
        edges.resize(n + 1);
        visited.resize(n + 1);
    }

    void add_edge(int u, int v) {
        edges[u].pb(v);
        edges[v].pb(u);
    }

    int count_cycles() {
        int ans = 0;

        for (int i = 1; i < n_vertex; i++) {
            if (visited[i]) continue;

            ans += dfs(i);
        }

        return ans;
    }

    bool dfs(int origin) {
        bool is_cycle = true;
        stack<int> pilha;

        visited[origin] = true;
        pilha.push(origin);

        while (!pilha.empty()) {
            int degree = 0;
            int current = pilha.top();
            db(current);
            pilha.pop();

            degree = edges[current].size();

            for (auto neighbor : edges[current]) {
                if (visited[neighbor]) continue;

                pilha.push(neighbor);
                visited[neighbor] = true;
            }

            /**
             * If every vertex in a component has degree equals two, so, the
             * component are a cycle
             */
            if (degree != 2) is_cycle = false;
        }

        return is_cycle;
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

    cout << graph.count_cycles() << endl;
}

int main(int argc, char** argv) {
    SPEED;

    solve();

    return 0;
}
