#include <iostream>
#include <string>

using namespace std;

int main() {
    int valor, positivo = 0, negativo = 0, pares = 0;
    for (int i = 0; i < 5; i++) {
        cin >> valor;
        if (valor % 2 == 0) pares++;
        if (valor > 0)
            positivo++;
        else if (valor < 0)
            negativo++;
    }
    cout << pares << " valor(es) par(es)\n";
    cout << 5 - pares << " valor(es) impar(es)\n";
    cout << positivo << " valor(es) positivo(s)\n";
    cout << negativo << " valor(es) negativo(s)\n";
    return 0;
}
