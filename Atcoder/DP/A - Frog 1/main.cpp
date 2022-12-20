#include <climits>
#include <iostream>
#include <utility>
#include <vector>

#define NAO_CALCULADO -1

using namespace std;

vector<int> memo(100005, NAO_CALCULADO);

// É importante receber pedras por referência
int custo_pedra(int pedra_atual, int pedra_destino, vector<int>& pedras) {
    if (pedra_atual == pedra_destino) return 0;

    // Por que dividir INT_MAX por 2?
    // Para que no caso de somar 2 vezes o infinito não tenhamos um overflow de memória
    // Podemos substituir INT_MAX por 2ˆ30
    if (pedra_atual > pedra_destino) return INT_MAX / 2;

    if (memo[pedra_atual] != NAO_CALCULADO)
        return memo[pedra_atual];

    int custo_salta_um = abs(pedras[pedra_atual] - pedras[pedra_atual + 1]) + custo_pedra(pedra_atual + 1, pedra_destino, pedras);
    int custo_salta_dois = abs(pedras[pedra_atual] - pedras[pedra_atual + 2]) + custo_pedra(pedra_atual + 2, pedra_destino, pedras);

    memo[pedra_atual] = min(custo_salta_um, custo_salta_dois);

    return memo[pedra_atual];
}

int main() {
    int n;
    cin >> n;

    vector<int> pedras(n);
    for (int i = 0; i < n; i++) cin >> pedras[i];

    int custo = custo_pedra(0, n - 1, pedras);

    cout << custo << "\n";

    return 0;
}
