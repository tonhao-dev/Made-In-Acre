/**
 * https://judge.beecrowd.com/pt/problems/view/1928
 * Grafos, DFS, BFS
 */

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

class Graph {
   public:
    int num_vertex;
    vector<vi> graph;
    vi cards;
    map<int, int> pos_card;

    Graph(int n) {
        num_vertex = n + 1;

        cards.resize(num_vertex);
        graph.resize(num_vertex);
    }

    void set_card(int card, int value) {
        pos_card[value] = card;
        cards[card] = value;
    }

    void add_edge(int u, int v) {
        graph[u].pb(v);
        graph[v].pb(u);
    }

    int max_points() {
        int points = 0;

        for (int i = 1; i <= num_vertex / 2; i++) {
            db(i);
            int ponto = dfs(pos_card[i], i);
            db(ponto);
            points += ponto;
        }

        return points;
    }

    int dfs(int pos_start, int target) {
        db(pos_start);
        db(target);

        vector<bool> visited(num_vertex);
        stack<pii> pilha;

        pilha.push({0, pos_start});
        visited[pos_start] = true;

        while (!pilha.empty()) {
            pii curr = pilha.top();
            // dbpair(curr);
            pilha.pop();

            if (cards[curr.s] == target && curr.s != pos_start) {
                // dbpair(curr);
                return curr.f;
            }

            for (auto neighbor : graph[curr.s]) {
                if (visited[neighbor]) continue;

                visited[neighbor] = true;
                pilha.push({curr.f + 1, neighbor});
            }
        }

        return 0;
    }
};

void solve() {
    int n;
    cin >> n;

    Graph grafo(n);

    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        grafo.set_card(i, c);
    }

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;

        grafo.add_edge(u, v);
    }

    cout << grafo.max_points() << endl;
}

int main(int argc, char** argv) {
    SPEED;

    solve();

    return 0;
}
