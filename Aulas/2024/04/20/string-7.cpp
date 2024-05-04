#include <bits/stdc++.h>

using namespace std;

int main() {
    string texto = "arara";

    int esquerda = 0;
    int direita = texto.size() - 1;
    bool ehPalindromo = true;

    while (esquerda < direita) {
        if (texto[esquerda] != texto[direita]) {
            ehPalindromo = false;
            break;
        }

        esquerda++;
        direita--;
    }

    cout << (ehPalindromo ? "Palindromo" : "Nao palindromo") << endl;

    return 0;
}
