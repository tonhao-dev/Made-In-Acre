/**
 * https://judge.beecrowd.com/pt/problems/view/1862
 * Grafo, dfs, componentes conexos
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG true
#define db(x) \
    if (DEBUG) cout << #x << ": " << x << endl
#define dbpair(x) cout << #x << ": " << x.f << ", " << x.s << endl
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
    bool invalid;
    int num_vertices;
    vector<string> matrix;
    vector<vi> graph;
    set<int> visited;

    Graph(int n) {
        num_vertices = n;
        graph.resize(n);
        invalid = false;
        matrix.resize(n);
    }

    void add_edge(int u, int v) {
        graph[u].pb(v);
        graph[v].pb(u);
    }

    void ans() {
        vector<vi> components = connected_components();

        sort(all(components), [](const vi& a, const vi& b) { return a.size() > b.size(); });

        if (invalid)
            cout << -1 << endl;
        else {
            cout << components.size() << endl;
            for (int i = 0; i < components.size(); i++) {
                if (i == components.size() - 1)
                    cout << components[i].size() << endl;
                else
                    cout << components[i].size() << " ";
            }
        }
    }

    vector<vi> connected_components() {
        vector<vi> components;

        for (int i = 0; i < graph.size(); i++) {
            if (visited.find(i) != visited.end()) continue;

            vi component = dfs(i);

            for (auto u : component) {
                for (auto v : component) {
                    if (matrix[u][v] == 'D') {
                        invalid = true;
                        break;
                    }
                }

                if (invalid) break;
            }

            if (invalid) return vector<vi>(0);

            components.pb(component);
        }

        return components;
    }

    vi dfs(int origin) {
        stack<int> pilha;
        vi path;

        pilha.push(origin);
        visited.insert(origin);
        path.pb(origin);

        while (!pilha.empty()) {
            int curr = pilha.top();
            pilha.pop();

            for (int neighbor : graph[curr]) {
                if (visited.find(neighbor) != visited.end()) continue;

                if (matrix[curr][neighbor] == 'D') {
                    invalid = true;
                    return vi(0);
                }

                pilha.push(neighbor);
                visited.insert(neighbor);
                path.pb(neighbor);
            }
        }

        return path;
    }
};

void solve() {
    int num_pessoas;
    cin >> num_pessoas;

    Graph grafo(num_pessoas);

    for (int i = 0; i < num_pessoas; i++) {
        string linha;
        cin >> linha;

        for (int j = 0; j < num_pessoas; j++) {
            if (linha[j] == 'S' && i != j) grafo.add_edge(i, j);

            grafo.matrix[i] = linha;
        }
    }

    grafo.ans();
}

int main(int argc, char** argv) {
    SPEED;

    solve();

    return 0;
}
