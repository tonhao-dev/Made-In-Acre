#include <iostream>
#include <string>

using namespace std;

int main() {
    int valor, soma = 0, contador = 0;
    for (int i = 0; i < 5; i++) {
        cin >> valor;
        if (valor % 2 == 0) contador++;
    }
    cout << contador << " valores pares\n";
    return 0;
}
