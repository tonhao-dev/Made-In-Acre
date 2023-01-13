// Implementação do algoritmo de Dijkstra
// Teste: http://br.spoj.com/problems/ENGARRAF/
// Grafos, menor caminho, algoritmo do A*

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>

#define INFINITO 10000000
#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

class Grafo {
   private:
    int V;  // número de vértices

    // ponteiro para um array contendo as listas de adjacências
    list<pair<int, int>> *adj;

   public:
    // construtor
    Grafo(int V) {
        this->V = V;  // atribui o número de vértices

        /*
            cria as listas onde cada lista é uma lista de pairs
            onde cada pair é formado pelo vértice destino e o custo
        */
        adj = new list<pair<int, int>>[V + 10];
    }

    // adiciona uma aresta ao grafo de v1 à v2
    void addAresta(int v1, int v2, int custo) {
        adj[v1].push_back(make_pair(v2, custo));
        adj[v2].push_back(make_pair(v1, custo));
    }

    // algoritmo de Dijkstra
    int dijkstra(int orig, int dest) {
        // vetor de distâncias
        int dist[V];

        /*
           vetor de visitados serve para caso o vértice já tenha sido
           expandido (visitado), não expandir mais
        */
        int visitados[V];

        // fila de prioridades de pair (distancia, vértice)
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>, greater<pair<int, int>>>
            pq;

        // inicia o vetor de distâncias e visitados
        for (int i = 0; i < V; i++) {
            dist[i] = INFINITO;
            visitados[i] = false;
        }

        // a distância de orig para orig é 0
        dist[orig] = 0;

        // insere na fila
        pq.push(make_pair(dist[orig], orig));

        // loop do algoritmo
        while (!pq.empty()) {
            pair<int, int> p = pq.top();  // extrai o pair do topo
            int verticeAtual = p.second;  // obtém o vértice do pair

            pq.pop();  // remove da fila

            if (visitados[verticeAtual] == true)
                continue;

            // marca como visitado
            visitados[verticeAtual] = true;

            // percorre os vértices "verticeAdjacente" adjacentes de "verticeAtual"
            for (auto it : adj[verticeAtual]) {
                // obtém o vértice adjacente e o custo da aresta
                int verticeAdjacente = it.first;
                int custo_aresta = it.second;

                // se eu faco parte da rota eu so posso expandir para o proximo vertice
                // que faz parte da rota
                if (verticeAtual <= dest && verticeAdjacente != verticeAtual + 1)
                    continue;

                // relaxamento (verticeAtual, verticeAdjacente)
                if (dist[verticeAdjacente] > (dist[verticeAtual] + custo_aresta)) {
                    debug("verticeAdjacente", dist[verticeAdjacente]);
                    // atualiza a distância de "verticeAdjacente" e insere na fila
                    dist[verticeAdjacente] = dist[verticeAtual] + custo_aresta;
                    pq.push(make_pair(dist[verticeAdjacente], verticeAdjacente));
                }
            }
        }

        // retorna a distância mínima até o destino
        return dist[dest];
    }
};

int main(int argc, char *argv[]) {
    int num_cidades, num_arestas, num_rota, num_conserto;

    while (cin >> num_cidades >> num_arestas >> num_rota >> num_conserto) {
        if (num_cidades == 0 && num_arestas == 0)
            return 0;

        Grafo grafo(num_cidades);

        for (int i = 0; i < num_arestas; i++) {
            int origem, destino, pedagio;
            cin >> origem >> destino >> pedagio;

            grafo.addAresta(origem, destino, pedagio);
        }

        cout << grafo.dijkstra(num_conserto, num_rota - 1);

        cout << endl;
    }

    return 0;
}
