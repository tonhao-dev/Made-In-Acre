#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INFINITO 10000000

typedef struct Pair
{
  int first;
  int second;
} Pair;

int cmp(const void *a, const void *b)
{
  Pair *pa = (Pair *)a;
  Pair *pb = (Pair *)b;
  return pa->first - pb->first;
}

typedef struct List
{
  int size;
  Pair *data;
} List;

typedef struct g
{
  int V;
  List *adjacente;
} g;

void addAresta(g *g, int v1, int v2, int custo)
{
  List *l1 = &g->adjacente[v1];
  l1->data = (Pair *)realloc(l1->data, ++l1->size * sizeof(Pair));
  l1->data[l1->size - 1] = (Pair){v2, custo};

  List *l2 = &g->adjacente[v2];
  l2->data = (Pair *)realloc(l2->data, ++l2->size * sizeof(Pair));
  l2->data[l2->size - 1] = (Pair){v1, custo};
}

int dijkstra(g *g, int orig, int dest)
{
  int dist[g->V];
  int visitados[g->V];
  Pair *pq = (Pair *)malloc(g->V * sizeof(Pair));
  int pq_size = 0;

  for (int i = 0; i < g->V; i++)
  {
    dist[i] = INFINITO;
    visitados[i] = 0;
  }

  dist[orig] = 0;
  pq[pq_size++] = (Pair){dist[orig], orig};

  while (pq_size > 0)
  {
    qsort(pq, pq_size, sizeof(Pair), cmp);
    Pair p = pq[--pq_size];
    int verticeAtual = p.second;

    if (visitados[verticeAtual])
      continue;
    visitados[verticeAtual] = 1;

    for (int i = 0; i < g->adjacente[verticeAtual].size; i++)
    {
      Pair it = g->adjacente[verticeAtual].data[i];
      int verticeAdjacenteacente = it.first;
      int custo_aresta = it.second;

      if (verticeAtual <= dest && verticeAdjacenteacente != verticeAtual + 1)
        continue;

      if (dist[verticeAdjacenteacente] > dist[verticeAtual] + custo_aresta)
      {
        dist[verticeAdjacenteacente] = dist[verticeAtual] + custo_aresta;
        pq[pq_size++] = (Pair){dist[verticeAdjacenteacente], verticeAdjacenteacente};
      }
    }
  }
  return dist[dest];
}

int main()
{
  int N, M, C, K, aux = 1;

  while (aux = 1)
  {
    scanf("%d %d %d %d", &N, &M, &C, &K);
    if (N == 0 && M == 0)
      break;

    g g;
    g.V = N;
    g.adjacente = (List *)calloc(N, sizeof(List));

    for (int i = 0; i < M; i++)
    {
      int origem, destino, pedagio;
      scanf("%d %d %d", &origem, &destino, &pedagio);

      addAresta(&g, origem, destino, pedagio);
    }

    printf("%d\n", dijkstra(&g, K, C - 1));
  }

  return 0;
}
