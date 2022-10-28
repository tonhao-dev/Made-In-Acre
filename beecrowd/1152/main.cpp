// https://www.beecrowd.com.br/judge/pt/problems/view/1152
// Grafos, Kruskal, Arvore geradora minima
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define debug(message, x) cout << message << x << endl;

using namespace std;

// Structure to represent a graph
struct Graph
{
  long long int num_vertices, num_arestas;
  vector<pair<long long int, pair<long long int, long long int>>> edges;

  // Constructor
  Graph(long long int num_vertices, long long int num_arestas)
  {
    this->num_vertices = num_vertices;
    this->num_arestas = num_arestas;
  }

  // Utility function to add an edge
  void addEdge(long long int u, long long int v, long long int w)
  {
    edges.push_back({w, {u, v}});
  }

  // Function to find MST using Kruskal's
  // MST algorithm
  long long int kruskalMST();
};

// To represent Disjoint Sets
struct DisjointSets
{
  long long int *parent, *rnk;
  long long int n;

  // Constructor.
  DisjointSets(long long int n)
  {
    // Allocate memory
    this->n = n;
    parent = new long long int[n + 1];
    rnk = new long long int[n + 1];

    // Initially, all vertices are in
    // different sets and have rank 0.
    for (long long int i = 0; i <= n; i++)
    {
      rnk[i] = 0;

      // every element is parent of itself
      parent[i] = i;
    }
  }

  // Find the parent of a node 'u'
  // Path Compression
  long long int find(long long int u)
  {
    /* Make the parent of the nodes in the path
    from u--> parent[u] point to parent[u] */
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }

  // Union by rank
  void merge(long long int x, long long int y)
  {
    x = find(x), y = find(y);

    /* Make tree with smaller height
    a subtree of the other tree */
    if (rnk[x] > rnk[y])
      parent[y] = x;
    else // If rnk[x] <= rnk[y]
      parent[x] = y;

    if (rnk[x] == rnk[y])
      rnk[y]++;
  }
};

/* Functions returns weight of the MST*/

long long int Graph::kruskalMST()
{
  long long int mst_wt = 0; // Initialize result

  // Sort edges in increasing order on basis of cost
  sort(edges.begin(), edges.end());

  // Create disjoint sets
  DisjointSets ds(num_vertices);

  // Iterate through all sorted edges
  vector<pair<long long int, pair<long long int, long long int>>>::iterator it;
  for (it = edges.begin(); it != edges.end(); it++)
  {
    long long int u = it->second.first;
    long long int v = it->second.second;

    long long int set_u = ds.find(u);
    long long int set_v = ds.find(v);

    // Check if the selected edge is creating
    // a cycle or not (Cycle is created if u
    // and v belong to same set)
    if (set_u != set_v)
    {
      // Current edge will be in the MST

      // Update MST weight
      mst_wt += it->first;

      // Merge two sets
      ds.merge(set_u, set_v);
    }
  }

  return mst_wt;
}

// Driver program to test above functions
int main()
{
  long long int num_vertices = 0, num_arestas = 0;
  cin >> num_vertices >> num_arestas;

  while (num_vertices != 0 && num_arestas != 0)
  {
    Graph grafo(num_vertices, num_arestas);
    long long int custo_total = 0;
    for (long long int num_testes = 0; num_testes < num_arestas; num_testes++)
    {
      long long int origem, destino, peso;

      cin >> origem >> destino >> peso;

      // o valor que deve ser printado eh a diferenca entre o Kruskal e a soma das arestas
      custo_total += peso;
      grafo.addEdge(origem, destino, peso);
    }

    long long int peso_menor_caminho = grafo.kruskalMST();

    cout << custo_total - grafo.kruskalMST() << endl;

    cin >> num_vertices >> num_arestas;
  }

  return 0;
}
