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

int n, m, k;

class Graph {
   private:
    int quantidadeVertices;
    list<pair<int, int>>* listaAdjacencia;

   public:
    Graph(int quantidadeVertices) {
        this->quantidadeVertices = quantidadeVertices + 1;
        listaAdjacencia = new list<pair<int, int>>[quantidadeVertices + 1];
    }

    void add_edge(int vertice1, int vertice2, int custo) {
        listaAdjacencia[vertice1].push_back(make_pair(vertice2, custo));
        listaAdjacencia[vertice2].push_back(make_pair(vertice1, custo));
    }

    int dijkstra(int origem, int destino) {
        vi distancias(quantidadeVertices);
        vi visitados(quantidadeVertices);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> filaPrioridade;

        for (int i = 0; i < quantidadeVertices; i++) {
            distancias[i] = INF;
            visitados[i] = false;
        }

        distancias[origem] = 0;

        filaPrioridade.push(make_pair(distancias[origem], origem));

        while (!filaPrioridade.empty()) {
            pair<int, int> parVerticeCusto = filaPrioridade.top();
            int verticeAtual = parVerticeCusto.second;

            filaPrioridade.pop();

            if (visitados[verticeAtual]) continue;

            visitados[verticeAtual] = true;

            for (auto nodo : listaAdjacencia[verticeAtual]) {
                int vizinho = nodo.first;
                int custoAteVizinho = nodo.second;

                if (distancias[vizinho] > max(distancias[verticeAtual], custoAteVizinho)) {
                    distancias[vizinho] = max(distancias[verticeAtual], custoAteVizinho);
                    filaPrioridade.push(make_pair(distancias[vizinho], vizinho));
                }
            }
        }

        sort(all(distancias));

        return distancias[k - 1];
    }
};

void solve() {
    cin >> n >> m >> k;

    Graph graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        graph.add_edge(u, v, c);
    }

    cout << graph.dijkstra(1, -1) << endl;
}

int main(int argc, char** argv) {
    SPEED;

    solve();

    return 0;
}
