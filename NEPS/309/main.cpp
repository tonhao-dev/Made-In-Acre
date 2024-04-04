/**
 * https://neps.academy/br/exercise/309
 * Gincana OBI 2011
 * Grafos, dfs, componentes conexos
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
    vector<bool> visitado;

    Graph(int n) {
        num_vertices = n + 1;
        lista.resize(n + 1);
        visitado.resize(n + 1);
    }

    void add_edge(int u, int v) {
        lista[u].pb(v);
        lista[v].pb(u);
    }

    int connected_components() {
        int resp = 0;

        for (int i = 1; i < num_vertices; i++) {
            if (visitado[i]) continue;

            resp++;
            dfs(i);
        }

        return resp;
    }

    void dfs(int origin) {
        stack<int> pilha;

        visitado[origin] = true;
        pilha.push(origin);

        while (!pilha.empty()) {
            int atual = pilha.top();
            pilha.pop();

            for (auto vizinho : lista[atual]) {
                if (visitado[vizinho]) continue;

                pilha.push(vizinho);
                visitado[vizinho] = true;
            }
        }
    }
};

void solve() {
    int num_alunos, num_linhas;
    cin >> num_alunos >> num_linhas;

    Graph grafo(num_alunos);

    for (int i = 0; i < num_linhas; i++) {
        int u, v;
        cin >> u >> v;

        grafo.add_edge(u, v);
    }

    cout << grafo.connected_components() << endl;
}

int main(int argc, char** argv) {
    SPEED;

    solve();

    return 0;
}
