#include <iostream>
#include <vector>

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

int main(int argc, char **argv) {
    int numCartas;
    cin >> numCartas;

    vector<int> cartas(numCartas);
    for (int i = 0; i < numCartas; i++) {
        cin >> cartas[i];
    }

    for (int i = cartas.size() - 2; i >= 0; --i) {
        if (cartas[i] < cartas[i + 1]) continue;
        /* Este +1 tem a função de remover o elemento que será a base do pilar,
            pois somente a ultima carta adicionada precisa ser verificada.
        */
        cartas.erase(cartas.begin() + i + 1);
    }

    cout << cartas.size() << "\n";
    return 0;
}
