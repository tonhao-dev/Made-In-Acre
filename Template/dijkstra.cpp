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
typedef priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m, k;

class Graph {
   private:
    int num_vertex;
    vector<vector<pii>> edges;

   public:
    Graph(int n) {
        num_vertex = n + 1;
        edges.resize(num_vertex);
    }

    void add_edge(int u, int v, int weight) {
        edges[u].pb({v, weight});
        edges[v].pb({u, weight});
    }

    int dijkstra(int origin, int target) {
        vi distance(num_vertex);
        vi visited(num_vertex);

        min_pq pq;

        for (int i = 0; i < num_vertex; i++) {
            distance[i] = INF;
            visited[i] = false;
        }

        distance[origin] = 0;

        pq.push({distance[origin], origin});

        while (!pq.empty()) {
            int current = pq.top().s;

            pq.pop();

            if (visited[current]) continue;

            visited[current] = true;

            for (auto neighborEdge : edges[current]) {
                int neighbor = neighborEdge.f;
                int weight = neighborEdge.s;

                if (distance[current] + weight < distance[neighbor]) {
                    distance[neighbor] = distance[current] + weight;

                    pq.push({distance[neighbor], neighbor});
                }
            }
        }

        return distance[target];
    }
};

void solve() {
    cin >> n >> m;

    Graph graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        graph.add_edge(u, v, weight);
    }

    cout << graph.dijkstra(1, n) << endl;
}

int main(int argc, char** argv) {
    SPEED;

    solve();

    return 0;
}
