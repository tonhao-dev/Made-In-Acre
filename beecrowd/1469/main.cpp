/**
 * https://judge.beecrowd.com/pt/problems/view/1469
 * dfs, busca em profundidade, grafos, digrafos
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

class Graph {
   public:
    ll num_nodes;
    vector<ll> ages;
    vector<vector<bool>> matrix;
    ll resp = LLONG_MAX;

    Graph(ll quantity_nodes) {
        ll num_nodes = quantity_nodes + 1;

        this->ages.resize(num_nodes);
        this->matrix.resize(num_nodes);
        for (auto& row : matrix) {
            row.resize(num_nodes);
        }
    }

    void set_age(ll no, ll age) {
        this->ages[no] = age;
    }

    void add_edge(ll from, ll to) {
        this->matrix[from][to] = true;
    }

    void swap_command(ll a, ll b) {
        // troca as linhas entre a e b
        swap(this->matrix[a], this->matrix[b]);

        // troca as colunas entre a e b
        for (ll i = 1; i < this->matrix.size(); i++) {
            swap(this->matrix[i][a], this->matrix[i][b]);
        }
    }

    void dfs(ll node) {
        for (ll i = 1; i < this->matrix.size(); i++) {
            if (this->matrix[i][node] == false) continue;

            this->resp = min(this->resp, this->ages[i]);

            dfs(i);
        }
    }

    void print() {
        for (ll i = 1; i < this->matrix.size(); i++) {
            for (ll j = 1; j < this->matrix.size(); j++) {
                cout << this->matrix[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
    }
};

int main(int argc, char** argv) {
    SPEED;

    ll num_empregados, num_relacoes, queries;
    while (cin >> num_empregados >> num_relacoes >> queries) {
        Graph grafo(num_empregados);

        for (ll i = 1; i <= num_empregados; i++) {
            ll idade;
            read(idade);
            grafo.set_age(i, idade);
        }

        rep(i, num_relacoes) {
            ll from, to;
            read(from, to);
            grafo.add_edge(from, to);
        }

        rep(q, queries) {
            char id;
            cin >> id;

            if (id == 'T') {
                ll a, b;
                read(a, b);
                grafo.swap_command(a, b);
            } else {
                ll origin;
                read(origin);

                grafo.resp = LLONG_MAX;
                grafo.dfs(origin);

                if (grafo.resp == LLONG_MAX)
                    cout << "*" << endl;
                else
                    cout << grafo.resp << endl;
            }
        }
    }

    return 0;
}