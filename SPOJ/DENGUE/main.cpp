/**
 * https://br.spoj.com/problems/DENGUE/
 * DENGUE - Dengue
 * Grafos, arvores, tree, dfs, diametro de uma arvore
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
    vector<int> dist;

    Graph(int n) {
        num_vertices = n + 1;
        lista.resize(123);
    }

    void add_edge(int u, int v) {
        lista[u].pb(v);
        lista[v].pb(u);
    }

    pii deep_first_search(int start) {
        stack<int> pilha;

        visitado.assign(num_vertices, false);
        dist.assign(num_vertices, 0);

        pilha.push(start);
        visitado[start] = true;
        dist[start] = 0;

        int maior_dist = 0;
        int far_node = 0;

        while (!pilha.empty()) {
            int atual = pilha.top();
            pilha.pop();

            for (auto vizinho : lista[atual]) {
                if (visitado[vizinho]) continue;

                pilha.push(vizinho);
                visitado[vizinho] = true;

                dist[vizinho] = dist[atual] + 1;

                if (dist[vizinho] > maior_dist) {
                    maior_dist = dist[vizinho];
                    far_node = vizinho;
                }
            }
        }

        return {far_node, maior_dist};
    }
};

void solve(int teste, int n) {
    if (n == 1) {
        cout << "Teste " << teste << endl;
        cout << 1 << endl;
        cout << endl;
        return;
    }

    if (n == 2) {
        int u, v;
        cin >> u >> v;

        cout << "Teste " << teste << endl;
        cout << 1 << endl;
        cout << endl;
        return;
    }

    Graph grafo(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        grafo.add_edge(u, v);
    }

    pii start = grafo.deep_first_search(1);

    vector<int> dist1(n + 1), dist2(n + 1);

    pii far_node_1 = grafo.deep_first_search(start.f);

    copy(all(grafo.dist), dist1.begin());

    pii far_node_2 = grafo.deep_first_search(far_node_1.f);

    copy(all(grafo.dist), dist2.begin());

    for (int i = 0; i < dist1.size(); i++) {
        if (dist1[i] == far_node_2.s / 2 && dist1[i] == dist2[i]) {
            cout << "Teste " << teste << endl;
            cout << i << endl;
            cout << endl;
            return;
        }

        if (dist1[i] == far_node_2.s / 2 + 1 && dist2[i] == far_node_2.s / 2) {
            cout << "Teste " << teste << endl;
            cout << i << endl;
            cout << endl;
            return;
        }

        if (dist1[i] == far_node_2.s / 2 && dist2[i] == far_node_2.s / 2 + 1) {
            cout << "Teste " << teste << endl;
            cout << i << endl;
            cout << endl;
            return;
        }
    }
}

int main(int argc, char** argv) {
    SPEED;

    int t = 1;
    while (cin >> n, n) {
        solve(t, n);
        t++;
    }

    return 0;
}
