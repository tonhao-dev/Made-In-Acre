#include <bits/stdc++.h>

using namespace std;

int main() {
    string texto = "arara";
    string reverse_texto = texto;
    reverse(reverse_texto.begin(), reverse_texto.end());

    cout << texto << endl;
    cout << reverse_texto << endl;

    if (texto == reverse_texto) {
        cout << "eh palindromo" << endl;
    } else {
        cout << "nao eh palindromo" << endl;
    }

    return 0;
}
