#include <bits/stdc++.h>

using namespace std;

int main() {
    char opcao = 'S';
    string a = "a", b = "a";
    string c = a + b;
    cout << c[0] << endl;

    cout << "tamanho A: " << a.size() << endl;
    cout << "tamanho B: " << b.size() << endl;

    // Ordenação lexicográfica.
    if (a < b) {
        cout << "a menor b" << endl;
    } else if (a > b) {
        cout << "a maior b" << endl;
    } else {
        cout << "a igual b" << endl;
    }

    return 0;
}
