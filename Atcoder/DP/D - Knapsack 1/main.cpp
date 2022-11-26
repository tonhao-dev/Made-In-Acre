// https://atcoder.jp/contests/dp/tasks/dp_d
// Programação dinâmica, memorização com matrizes, DP
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#define NAO_CALCULADO -1
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

class Item {
   public:
    int peso;
    ll valor;
};

vector<vector<ll>> memo(100, vector<ll>(100005, NAO_CALCULADO));

ll valor_maximo(int item_atual, int capacidade_disponivel, vector<Item>& itens) {
    if (capacidade_disponivel < 0) return -LONG_MAX / 2;
    if (capacidade_disponivel == 0 || item_atual == itens.size()) return 0;

    if (memo[item_atual][capacidade_disponivel] != NAO_CALCULADO) return memo[item_atual][capacidade_disponivel];

    return memo[item_atual][capacidade_disponivel] = max(
               // Caso a capacidade se torne negativa o retorno será -LONG_MAX, dessa forma assumimos que o valor
               // retornado é tão pequeno que será desconsiderado pelo MAX()
               itens[item_atual].valor + valor_maximo(item_atual + 1, capacidade_disponivel - itens[item_atual].peso, itens),
               valor_maximo(item_atual + 1, capacidade_disponivel, itens));
}

int main() {
    fastIO;

    int num_itens, capacidade;
    cin >> num_itens >> capacidade;

    vector<Item> itens(num_itens);

    for (int i = 0; i < num_itens; i++) {
        cin >> itens[i].peso >> itens[i].valor;
    }

    cout << valor_maximo(0, capacidade, itens) << "\n";

    return 0;
}
