/**
 * https://cses.fi/problemset/task/1667
 * Message route
 * BFS
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

int n, m;

class Graph {
  public:
    int num_nodes;
    vector<vi> edges;

    Graph(int qtd_nodes){
        num_nodes = qtd_nodes + 1;

        edges.resize(num_nodes);
    }

    void add_edge(int u, int v) {
        edges[u].pb(v);
        edges[v].pb(u);
    }

    vi bfs(int from, int to) {
        vector<bool> visited(num_nodes);
        queue<int> q;
        vi parent(num_nodes);

        q.push({ from });
        parent[1] = 0;
        visited[1] = true;

        while(!q.empty()) {
            int current = q.front();
            q.pop();

            for(auto neighbor: edges[current]) {
                if(visited[neighbor]) continue;

                parent[neighbor] = current;
                visited[neighbor] = true;

                q.push(neighbor);
            }
        }

        if(!visited[n]) return vi();
        
        vi path;
        for(int at = n; at != 0; at = parent[at]) {
            path.pb(at);
        }

        return path;
    }
};

void solve() {
    cin >> n >> m;

    Graph graph(n);
    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        graph.add_edge(u, v); 
    }

    vi path = graph.bfs(1, n);

    if(path.size() != 0) {
        cout << path.size() << endl; 
        for(int i=path.size() - 1; i>=0;i--) cout << path[i] << " ";
        cout << endl;
    } else 
        cout << "IMPOSSIBLE" << endl; 
}  

int main(int argc, char** argv) {
    SPEED; 

    solve();

    return 0;
}