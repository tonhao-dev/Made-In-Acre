/**
 * https://codeforces.com/gym/104854/problem/J
 * J. Judging Gifts
 * Grafos, graph
 */

#include <bits/stdc++.h>

using namespace std;

#define INFINITO 1000000
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

using namespace std;

int n, m, k, y;

class Grafo {
   private:
    int quantidadeVertices;
    list<pair<int, int>>* listaAdjacencia;
    vector<bool> visited;

   public:
    Grafo(int quantidadeVertices) {
        this->quantidadeVertices = quantidadeVertices;
        listaAdjacencia = new list<pair<int, int>>[quantidadeVertices + 1];
        visited.resize(n + 1);
    }

    void addAresta(int vertice1, int vertice2, int custo) {
        listaAdjacencia[vertice1].push_back(make_pair(vertice2, custo));
    }

    bool dijkstra(int origem, int destino) {
        ll distancias[quantidadeVertices];
        int visitados[quantidadeVertices];

        priority_queue<pair<int, int>> filaPrioridade;

        for (int i = 0; i < quantidadeVertices; i++) {
            distancias[i] = LINF;
            visitados[i] = false;
        }

        distancias[origem] = 0;

        filaPrioridade.push(make_pair(distancias[origem], origem));

        while (!filaPrioridade.empty()) {
            pair<int, int> parVerticeCusto = filaPrioridade.top();
            ll verticeAtual = parVerticeCusto.second;

            filaPrioridade.pop();

            if (visitados[verticeAtual]) continue;

            visitados[verticeAtual] = true;

            for (auto nodo : listaAdjacencia[verticeAtual]) {
                ll vizinho = nodo.first;
                ll custoAteVizinho = nodo.second;

                if (distancias[vizinho] > (distancias[verticeAtual] + custoAteVizinho)) {
                    distancias[vizinho] = distancias[verticeAtual] + custoAteVizinho;
                    filaPrioridade.push(make_pair(distancias[vizinho], vizinho));
                }
            }
        }

        for (auto distancia : distancias) {
            if (distancia >= k && distancia != LINF) return true;
        }

        return false;
    }

    bool dfs(int origin) {
        stack<int> pilha;

        visited[origin] = true;
        pilha.push(origin);

        while (!pilha.empty()) {
            int current = pilha.top();
            pilha.pop();

            for (auto neighbor : listaAdjacencia[current]) {
                if (visited[neighbor.f]) return true;

                pilha.push(neighbor.f);
                visited[neighbor.f] = true;
            }
        }

        return false;
    }
};

void solve() {
    cin >> n >> m >> k >> y;
    Grafo grafo(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        grafo.addAresta(v, u, w);
    }

    if (grafo.dfs(y)) {
        cout << "YES" << endl;
    } else if (grafo.dijkstra(y, 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    SPEED;

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}
