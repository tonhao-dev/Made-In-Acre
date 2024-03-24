/**
 * https://judge.beecrowd.com/pt/problems/view/1081
 * Grafo, graph, dfs, grafos disconexos
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG true
#define db(x) \
    if (DEBUG) cout << #x << ": " << x << endl
#define db_pair(x) cout << #x << ": " << x.f << ", " << x.s << endl
#define printv(vector)                             \
    {                                              \
        cout << #vector << " = ";                  \
        for (auto& it : vector) cout << it << " "; \
        cout << endl;                              \
    }
#define print_map(map)                      \
    for (auto e : map)                      \
        cout << e.first << " " << e.second; \
    cout << endl
#define FOR(i, a, b) for (ll i = a; i < (b); ++i)
#define foreach(a, b) for (auto&(a) : (b))
#define rep(i, n) FOR(i, 0, n)
#define Rep(i, a, b) for (ll i = a; i >= (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second
#define MOD 1e9 + 7
#define log(x) cout << x << endl

#define MAXV 21

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

template <typename T>

void read(T& arg) {
    std::cin >> arg;
}

template <typename T, typename... Args>
void read(T& first, Args&... args) {
    std::cin >> first;
    read(args...);
}

class Node {
   public:
    set<ll> neighbors;
};

class Graph {
   public:
    unordered_set<ll> visited;
    vector<Node> children;
    unordered_set<ll> existents_nodes;
    ll num_nodes;

    Graph(ll num_nodes) {
        this->num_nodes = num_nodes;
        this->children.resize(num_nodes + 50);
    }

    void add_edge(ll from, ll to) {
        this->existents_nodes.insert(from);
        this->existents_nodes.insert(to);
        this->children[from].neighbors.insert(to);
    }

    void dfs(ll node, ll level = 0, ll dad = -1) {
        this->visited.insert(node);

        if (level > 0) {
            rep(s, level) cout << " ";
            cout << dad << "-" << node << " pathR(G," << node << ")" << endl;
        }

        for (ll neighbor : this->children[node].neighbors) {
            if (this->visited.find(neighbor) != this->visited.end()) {
                rep(s, level + 2) cout << " ";
                cout << node << "-" << neighbor << endl;

                continue;
            }

            this->dfs(neighbor, level + 2, node);
        }
    }

    void dfs_disconnected() {
        rep(i, this->num_nodes) {
            if (this->existents_nodes.find(i) == this->existents_nodes.end()) continue;

            if (this->visited.find(i) == this->visited.end()) {
                dfs(i);
                cout << endl;
            }
        }
    }

    void print() {
        rep(i, this->num_nodes) {
            cout << i << ": ";
            for (auto neighbor : this->children[i].neighbors) {
                cout << neighbor << " ";
            }
            cout << endl;
        }

        cout << endl;
    }
};

int main(int argc, char** argv) {
    SPEED;

    ll test_cases;
    read(test_cases);

    rep(test_case, test_cases) {
        ll num_vertices, num_arestas;
        read(num_vertices, num_arestas);

        Graph grafo(num_vertices);

        rep(i, num_arestas) {
            ll from, to;
            read(from, to);

            grafo.add_edge(from, to);
        }

        cout << "Caso " << test_case + 1 << ":" << endl;
        grafo.dfs_disconnected();
        // cout << endl;
    }

    return 0;
}
