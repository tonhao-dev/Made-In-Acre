#include <bits/stdc++.h>

#define INFINITO 1000000

using namespace std;

class Grafo {
  private:
    int quantidadeVertices;
    list<pair<int, int>> *listaAdjacencia;

  public:
    Grafo(int quantidadeVertices) {
      this->quantidadeVertices = quantidadeVertices;
      listaAdjacencia = new list<pair<int, int>>[quantidadeVertices + 1];
    }

    void addAresta(int vertice1, int vertice2, int custo) {
      listaAdjacencia[vertice1].push_back(make_pair(vertice2, custo));
      listaAdjacencia[vertice2].push_back(make_pair(vertice1, custo));
    }

    int dijkstra(int origem, int destino){
      int distancias[quantidadeVertices];
      int visitados[quantidadeVertices];

      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> filaPrioridade;

      for (int i = 0; i < quantidadeVertices; i++) {
        distancias[i] = INFINITO;
        visitados[i] = false;
      }

      distancias[origem] = 0;

      filaPrioridade.push(make_pair(distancias[origem], origem));

      while(!filaPrioridade.empty()) {
        pair<int, int> parVerticeCusto = filaPrioridade.top();
        int verticeAtual = parVerticeCusto.second;

        filaPrioridade.pop();

        if(visitados[verticeAtual]) continue;

        visitados[verticeAtual] = true;

        for (auto nodo : listaAdjacencia[verticeAtual]) {
          int vizinho = nodo.first;
          int custoAteVizinho = nodo.second;

          if(distancias[vizinho] > (distancias[verticeAtual] + custoAteVizinho)) {
            distancias[vizinho] = distancias[verticeAtual] + custoAteVizinho;
            filaPrioridade.push(make_pair(distancias[vizinho], vizinho));
          }
        }
      }
      return distancias[destino];
    }

};

int main() {
  Grafo grafo(3);
  grafo.addAresta(0, 1, 6);
  grafo.addAresta(0, 2, 2);
  grafo.addAresta(1, 3, 1);
  grafo.addAresta(2, 1, 3);
  grafo.addAresta(2, 3, 5);
  cout << grafo.dijkstra(0, 3) << endl;
  return 0;
}
