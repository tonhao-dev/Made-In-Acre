/**
 * https://vjudge.net/contest/576477#problem/F
 * Problema da mochila, Knapsack, PD, programacao dinamica, dp
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define db(x) cout << #x << ": " << x << endl
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

class Item {
   public:
    ll peso;
    ll valor;
};

vector<vector<ll>> memo(100, vector<ll>(100005, -1));

ll valor_maximo(int item_atual, int capacidade_disponivel, vector<Item>& itens) {
    if (capacidade_disponivel < 0) return -LONG_MAX / 2;
    if (capacidade_disponivel == 0 || item_atual == itens.size()) return 0;

    if (memo[item_atual][capacidade_disponivel] != -1) return memo[item_atual][capacidade_disponivel];

    return memo[item_atual][capacidade_disponivel] = max(
               // Caso a capacidade se torne negativa o retorno será -LONG_MAX, dessa forma assumimos que o valor
               // retornado é tão pequeno que será desconsiderado pelo MAX()
               itens[item_atual].valor + valor_maximo(item_atual + 1, capacidade_disponivel - itens[item_atual].peso, itens),
               valor_maximo(item_atual + 1, capacidade_disponivel, itens));
}

int main(int argc, char** argv) {
    SPEED;

    ll capacidade, custo_fixo;
    while (cin >> capacidade >> custo_fixo) {
        ll n_itens;
        read(n_itens);

        vector<Item> itens(n_itens);
        rep(i, n_itens) {
            ll profundidade, ouro;
            read(profundidade, ouro);

            itens[i].valor = ouro;
            itens[i].peso = custo_fixo * profundidade + 2 * custo_fixo * profundidade;
        }

        log(valor_maximo(0, capacidade, itens));
    }

    return 0;
}
