#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INFINITO INT_MAX

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

typedef struct Grafo
{
    int V;
    List *adj;
} Grafo;

void grafo_add_aresta(Grafo *grafo, int v1, int v2, int custo)
{
    List *l1 = &grafo->adj[v1];
    l1->data = (Pair *)realloc(l1->data, ++l1->size * sizeof(Pair));
    l1->data[l1->size - 1] = (Pair){v2, custo};

    List *l2 = &grafo->adj[v2];
    l2->data = (Pair *)
        realloc(l2->data, ++l2->size * sizeof(Pair));
    l2->data[l2->size - 1] = (Pair){v1, custo};
}

int grafo_dijkstra(Grafo *grafo, int orig, int dest)
{
    int dist[grafo->V];
    int visitados[grafo->V];
    Pair *pq = (Pair *)malloc(grafo->V * sizeof(Pair));
    int pq_size = 0;

    for (int i = 0; i < grafo->V; i++)
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

        for (int i = 0; i < grafo->adj[verticeAtual].size; i++)
        {
            Pair it = grafo->adj[verticeAtual].data[i];
            int verticeAdjacente = it.first;
            int custo_aresta = it.second;

            if (verticeAtual <= dest && verticeAdjacente != verticeAtual + 1)
                continue;

            if (dist[verticeAdjacente] > dist[verticeAtual] + custo_aresta)
            {
                dist[verticeAdjacente] = dist[verticeAtual] + custo_aresta;
                pq[pq_size++] = (Pair){dist[verticeAdjacente], verticeAdjacente};
            }
        }
    }
    return dist[dest];
}

int main()
{
    int num_cidades, num_arestas, num_rota, num_conserto;

    while (1)
    {
        scanf("%d %d %d %d", &num_cidades, &num_arestas, &num_rota, &num_conserto);
        if (num_cidades == 0 && num_arestas == 0 && num_rota == 0 && num_conserto == 0)
            return 0;

        Grafo grafo;
        grafo.V = num_cidades;
        grafo.adj = (List *)calloc(num_cidades, sizeof(List));

        for (int i = 0; i < num_arestas; i++)
        {
            int origem, destino, pedagio;
            scanf("%d %d %d", &origem, &destino, &pedagio);

            grafo_add_aresta(&grafo, origem, destino, pedagio);
        }

        printf("%d\n", grafo_dijkstra(&grafo, num_conserto, num_rota - 1));
    }

    return 0;
}
