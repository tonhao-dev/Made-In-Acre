#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_cartas;
    while (cin >> num_cartas, num_cartas) {
        vector<int> pilha_cartas;
        vector<int> descartes;

        for (int i = num_cartas; i >= 1; i--) {
            pilha_cartas.push_back(i);
        }

        while (pilha_cartas.size() > 1) {
            descartes.push_back(pilha_cartas.back());
            pilha_cartas.pop_back();
            pilha_cartas.insert(pilha_cartas.begin(), pilha_cartas.back());
            pilha_cartas.pop_back();
        }

        cout << "Discarded cards: ";
        for (int i = 0; i < descartes.size(); i++) {
            if (i == descartes.size() - 1) {
                cout << descartes[i] << endl;
            } else {
                cout << descartes[i] << ", ";
            }
        }

        cout << "Remaining card: " << pilha_cartas[0] << endl;
    }

    return 0;
}
