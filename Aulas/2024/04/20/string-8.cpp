#include <bits/stdc++.h>

using namespace std;

int main() {
    string texto = "Socorram-me subi no onibus em            Marrocos";
    int esquerda = 0;
    int direita = texto.size() - 1;
    bool ehPalindromo = true;
    while (esquerda < direita) {
        // islpha -> retorna verdadeiro se o caracter eh alfabetico/letra
        // enquanto na esquerda for direfente de letra anda esquerda
        while (!isalpha(texto[esquerda]) && esquerda < direita) {
            esquerda++;
        }
        while (!isalpha(texto[direita]) && esquerda < direita) {
            direita--;
        }
        // tolower -> converte de maiusculo para minusculo
        // A -> a
        // a -> a
        // nao altera a string original
        if (tolower(texto[esquerda]) != tolower(texto[direita])) {
            ehPalindromo = false;
            break;
        }
        esquerda++;
        direita--;
    }

    cout << (ehPalindromo ? "Palindromo" : "Nao palindromo") << endl;

    return 0;
}
