// Implementação do algoritmo de Dijkstra
// Teste: http://br.spoj.com/problems/ENGARRAF/
// Grafos, menor caminho, algoritmo do A*

#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
#include <iterator>

#define INFINITO 10000000
#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

class Grafo
{
private:
    int V; // número de vértices

    // ponteiro para um array contendo as listas de adjacências
    list<pair<int, int>> *adj;
    vector<vector<bool>> memo;

public:
    // construtor
    Grafo(int V)
    {
        this->V = V;                                                  // atribui o número de vértices
        this->memo = vector<vector<bool>>(V, vector<bool>(V, false)); //
        /*
            cria as listas onde cada lista é uma lista de pairs
            onde cada pair é formado pelo vértice destino e o custo
        */
        adj = new list<pair<int, int>>[V + 10];
    }

    // adiciona uma aresta ao grafo de v1 à v2
    void addAresta(int v1, int v2, int custo)
    {
        adj[v1].push_back(make_pair(v2, custo));
        memo[v1][v2] = true;
    }

    // algoritmo de Dijkstra
    int dijkstra(int orig, int dest)
    {
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
        for (int i = 0; i < V; i++)
        {
            dist[i] = INFINITO;
            visitados[i] = false;
        }

        // a distância de orig para orig é 0
        dist[orig] = 0;
        // debug("dist[orig]", dist[orig]);

        // insere na fila
        pq.push(make_pair(dist[orig], orig));

        // loop do algoritmo
        while (!pq.empty())
        {
            pair<int, int> p = pq.top(); // extrai o pair do topo
            int u = p.second;            // obtém o vértice do pair

            pq.pop(); // remove da fila

            // verifica se o vértice não foi expandido
            if (visitados[u] == false)
            {
                // marca como visitado
                visitados[u] = true;

                // percorre os vértices "v" adjacentes de "u"
                for (auto it : adj[u])
                {

                    // obtém o vértice adjacente e o custo da aresta
                    int v = it.first;

                    int custo_aresta = it.second;

                    /* Essas duas verificações olham se v tem conexão com u
                    e se u tem conexão com v, isso é para resolver o problema
                    no qual caso os dois possuam ligações cruzadas o custo é 0

                    PARA OUTROS USOS ESSE IF DEVE SER APAGADO
                    */
                    if (this->memo[u][v] == true && this->memo[v][u] == true)
                    {
                        custo_aresta = 0;
                    }

                    // relaxamento (u, v)
                    if (dist[v] > (dist[u] + custo_aresta))
                    {
                        // atualiza a distância de "v" e insere na fila
                        dist[v] = dist[u] + custo_aresta;
                        pq.push(make_pair(dist[v], v));
                    }
                }
            }
        }

        // retorna a distância mínima até o destino
        return dist[dest];
    }
};

int main(int argc, char *argv[])
{
    int num_cidades, num_arestas;

    while (cin >> num_cidades >> num_arestas)
    {
        if (num_cidades == 0 && num_arestas == 0)
            return 0;

        Grafo grafo(num_cidades + 5);

        for (int i = 0; i < num_arestas; i++)
        {

            int origem, destino, tempo_carta;
            cin >> origem >> destino >> tempo_carta;

            grafo.addAresta(origem, destino, tempo_carta);
        }

        int num_consultas;
        cin >> num_consultas;

        for (int i = 0; i < num_consultas; i++)
        {
            int origem, destino;
            cin >> origem >> destino;

            int resposta = grafo.dijkstra(origem, destino);

            if (resposta == INFINITO)
                cout << "Nao e possivel entregar a carta" << endl;
            else
                cout << resposta << endl;
        }

        cout << endl;
    }

    return 0;
}
