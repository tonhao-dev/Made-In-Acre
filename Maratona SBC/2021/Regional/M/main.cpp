/**
 * https://codeforces.com/gym/103388/problem/M
 * Grafos, DFS, Busca em profundidade
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define db(x) cout << #x << ": " << x << endl
#define db_pair(x) cout << #x << ": " << x.f << ", " << x.s << endl
#define cv(vector)        \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl
#define cm(map)                             \
    for (auto e : map)                      \
        cout << e.first << " " << e.second; \
    cout << endl
#define FOR(i, a, b) for (ll i = a; i < (b); ++i)
#define foreach(a, b) for (auto &(a) : (b))
#define rep(i, n) FOR(i, 0, n)
#define Rep(i, a, b) for (ll i = a; i >= (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

class Node {
   public:
    vector<ll> vizinhos;
    bool isLive = true;
};

class Graph {
   public:
    vector<Node> children;
    ll num_nodes;
    bool found = false;

    Graph(ll num_nodes) {
        this->children.resize(num_nodes + 10);
        this->num_nodes = num_nodes;
    }

    void add_edge(ll from, ll to) {
        this->children[from].vizinhos.push_back(to);
    }

    void find_people_to_kill(ll find_node, void (*mark_as_visited)(Node *)) {
        mark_as_visited(&this->children[find_node]);
    }

    void find_first_people_live(ll current_node) {
        if(this->found) return;

        if(this->children[current_node].isLive) {
            cout << current_node << endl;
            this->found = true;
            return;
        };

        for (auto next_node_index : this->children[current_node].vizinhos) {
            find_first_people_live(next_node_index);
        }
    }
};

bool is_people_live(Node node) {
    return node.isLive;
}

void set_people_die(Node *node) {
    node->isLive = false;
}

int main(int argc, char **argv) {
    SPEED;

    ll vertices;
    cin >> vertices;

    Graph grafo(vertices);

    ll currentId = 2;
    rep(i, vertices) {
        ll event, id;
        cin >> event >> id;

        if(event == 1) {
            grafo.add_edge(id, currentId++);
        } else {
            grafo.find_people_to_kill(id, set_people_die);
            grafo.found = false;
            grafo.find_first_people_live(1);
        }
    }

    return 0;
}
