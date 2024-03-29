/**
 * https://judge.beecrowd.com/pt/problems/view/1469
 * dfs, busca em profundidade, grafos, digrafos
 *
 * Dica para a resolução:
 * https://maratonapcauece.files.wordpress.com/2014/09/solucoes_regional_2013.pdf
 *
 * Quando se é realizado uma troca de vértices no grafo, a estrutura do grafo não muda.
 * Podemos ter um vetor posicao[i] que diz em que posicao do grafo o vertice i esta
 * Inicialmente cada posicao[i] vale i, ou seja, o vertice 1 esta na posicao 1,
 * vertice 2 esta na posicao 2 e assim sucessivamente, e quando fazemos a troca
 * basta alterar nesse vetor de posicao, sem precisar mexer na matriz ou lista de adjascencia
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG false
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
    map<ll, ll> ages;
    vector<ll> posicoes;
    vector<vector<bool>> matrix;
    set<ll> visitado;
    ll resp = LLONG_MAX;

    Graph(ll quantity_nodes) {
        this->num_nodes = quantity_nodes + 1;

        this->posicoes.resize(this->num_nodes);
        rep(i, sz(posicoes)) posicoes[i] = i;

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
        // executar com e sem o swap do age e entender o que acontece
        // swap(this->ages[a], this->ages[b]);
        // printv(posicoes);
        db(a);
        db(b);
        swap(this->posicoes[a], this->posicoes[b]);
        // printv(posicoes);
    }

    void dfs(ll pos) {
        if (this->visitado.find(pos) != this->visitado.end()) return;

        db(pos);
        this->visitado.insert(pos);
        // refazer essa logica
        for (ll i = 1; i < this->matrix.size(); i++) {
            // precisei chamar this->posicoes[i]
            if (this->matrix[this->posicoes[i]][this->posicoes[pos]] == false) continue;

            db(i);
            db(posicoes[i]);
            db(posicoes[pos]);
            db(resp);
            db(this->ages[posicoes[i]]);

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
                cin >> origin;

                grafo.resp = LLONG_MAX;
                grafo.visitado.clear();
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
