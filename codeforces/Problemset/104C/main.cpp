/**
 * https://codeforces.com/problemset/problem/104/C
 * Cthulhu
 * Grafos, dfs, detectar ciclo
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

class Graph {
   public:
    int num_vertices;
    vector<vi> lista;
    set<int> visitado;

    Graph(int n) {
        num_vertices = 100006;
        lista.resize(num_vertices);
    }

    void add_edge(int u, int v) {
        lista[u].pb(v);
        lista[v].pb(u);
    }

    void dfs(int origin) {
        stack<int> pilha;

        visitado.insert(origin);
        pilha.push(origin);

        while (!pilha.empty()) {
            int atual = pilha.top();
            pilha.pop();

            for (auto vizinho : lista[atual]) {
                if (visitado.find(vizinho) != visitado.end()) continue;

                pilha.push(vizinho);
                visitado.insert(vizinho);
            }
        }
    }
};

int n, m;

void solve() {
    cin >> n >> m;

    Graph grafo(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        grafo.add_edge(u, v);
    }

    grafo.dfs(1);

    cout << ((grafo.visitado.size() == n && n == m) ? "FHTAGN" : "NO") << endl;
}

int main(int argc, char** argv) {
    SPEED;

    solve();

    return 0;
}
