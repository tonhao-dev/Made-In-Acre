/**
 * https://codeforces.com/problemset/problem/580/C
 * C. Kefa and Park
 * Grafos, tree, arvores, dfs
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

int n, m, resp;

class Graph {
   public:
    int num_vertices;
    vector<vi> lista;
    vector<bool> visitado;
    vector<bool> hasCat;

    Graph(int n) {
        num_vertices = n + 1;
        lista.resize(n + 1);
        visitado.resize(n + 1);
        hasCat.resize(n + 1);
    }

    void add_edge(int u, int v) {
        lista[u].pb(v);
        lista[v].pb(u);
    }

    void set_cat(int node) {
        hasCat[node] = true;
    }

    int dfs(int origin) {
        stack<pii> pilha;

        visitado[origin] = true;
        pilha.push({origin, hasCat[origin]});

        while (!pilha.empty()) {
            pii atual = pilha.top();

            pilha.pop();

            if (atual.s > m) {
                continue;
            }

            if (lista[atual.f].size() == 1 && atual.f != 1) {  // leaf
                resp += atual.s <= m;
                continue;
            }

            for (auto vizinho : lista[atual.f]) {
                if (visitado[vizinho]) continue;

                visitado[vizinho] = true;

                if (hasCat[vizinho]) {
                    pilha.push({vizinho, atual.s + 1});
                } else {
                    pilha.push({vizinho, 0});
                }
            }
        }
        return resp;
    }
};

void solve() {
    cin >> n >> m;

    Graph grafo(n);
    resp = 0;

    for (int i = 0; i < n; i++) {
        int hasCat;
        cin >> hasCat;

        if (!hasCat) continue;

        grafo.set_cat(i + 1);
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        grafo.add_edge(u, v);
    }

    cout << grafo.dfs(1) << endl;
}

int main(int argc, char** argv) {
    SPEED;

    solve();

    return 0;
}
