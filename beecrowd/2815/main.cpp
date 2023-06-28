#include <bits/stdc++.h>

using namespace std;

int main() {
    string frase, novaFrase = "";
    getline(cin, frase);
    int tamanho = frase.size();
    for (int i = 0; i < tamanho; i++) {
        if (i < tamanho - 3) {
            if (frase[i] == frase[i + 2] && frase[i + 1] == frase[i + 3]) {
                novaFrase = novaFrase + frase[i] + frase[i + 1];
                i += 3;
            } else {
                novaFrase = novaFrase + frase[i];
            }
        } else {
            novaFrase = novaFrase + frase[i];
        }
    }
    cout << novaFrase << endl;
    return 0;
}
