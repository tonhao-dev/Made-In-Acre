#include <climits>
#include <iostream>
#include <utility>
#include <vector>

#define NAO_CALCULADO -1

using namespace std;

vector<int> memo(100005, NAO_CALCULADO);

// É importante receber pedras por referência
int custo_pedra(int pedra_atual, int pedra_destino, int max_salto, vector<int>& pedras) {
    if (pedra_atual == pedra_destino) return 0;

    // Por que dividir INT_MAX por 2?
    // Para que no caso de somar 2 vezes o infinito não tenhamos um overflow de memória
    // Podemos substituir INT_MAX por 2ˆ30
    if (pedra_atual > pedra_destino) return INT_MAX / 2;

    if (memo[pedra_atual] != NAO_CALCULADO)
        return memo[pedra_atual];

    for (int i = 1; i <= max_salto; ++i) {
        int custo = abs(pedras[pedra_atual] - pedras[pedra_atual + i]) + custo_pedra(pedra_atual + i, pedra_destino, max_salto, pedras);

        if (memo[pedra_atual] == NAO_CALCULADO)
            memo[pedra_atual] = custo;
        else
            memo[pedra_atual] = min(memo[pedra_atual], custo);
    }

    return memo[pedra_atual];
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> pedras(n);
    for (int i = 0; i < n; i++) cin >> pedras[i];

    int custo = custo_pedra(0, n - 1, k, pedras);

    cout << custo << "\n";

    return 0;
}
