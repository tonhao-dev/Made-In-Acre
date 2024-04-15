/**
 * https://www.spoj.com/problems/PT07Z/
 * Longest path in a tree
 * Grafos, arvores, tree, dfs
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

class Graph {
   public:
    vector<vi> children;
    int num_nodes;

    Graph(int num_nodes) {
        this->children.resize(num_nodes + 1);
        this->num_nodes = num_nodes + 1;
    }

    void add_edge(int from, int to) {
        children[from].push_back(to);
        children[to].push_back(from);
    }

    pii deep_first_search(int start) {
        stack<int> pilha;
        vector<bool> visitado(num_nodes);
        vi dist(num_nodes);

        pilha.push(start);
        visitado[start] = true;
        dist[start] = 0;

        int maior_dist = 0;
        int far_node = 0;

        while (!pilha.empty()) {
            int atual = pilha.top();
            pilha.pop();

            for (auto vizinho : children[atual]) {
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

        return {far_node, dist[far_node]};
    }
};

void solve() {
    int nodes;
    cin >> nodes;

    Graph grafo(nodes);
    for (int i = 0; i < nodes; i++) {
        int u, v;
        cin >> u >> v;

        grafo.add_edge(u, v);
    }

    pii far_node = grafo.deep_first_search(1);
    pii most_far_node = grafo.deep_first_search(far_node.f);

    cout << most_far_node.s << endl;
}

int main(int argc, char** argv) {
    SPEED;

    solve();

    return 0;
}
