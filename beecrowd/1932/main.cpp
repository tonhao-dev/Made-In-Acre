#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    vector<int> cotacoes(N);

    for (int i = 0; i < N; i++) {
        cin >> cotacoes[i];
    }

    int lucro = 0;
    int ultimaComprada = cotacoes[0];
    int ultimaVendida = 0;

    for (int i=0; i<N; i++){
        if(cotacoes[i] < ultimaComprada){
            ultimaComprada = cotacoes[i];
        }
        else if((cotacoes[i] - ultimaComprada) - C > 0){
            lucro += (cotacoes[i] - ultimaComprada) - C;
            ultimaVendida = cotacoes[i];
            ultimaComprada = cotacoes[i + 1];
        } else if(cotacoes[i] > ultimaVendida && ultimaVendida != 0) {
            lucro += cotacoes[i] - ultimaVendida;
            ultimaVendida = cotacoes[i];
        }

    }

    cout << lucro << "\n";

    return 0;
}
