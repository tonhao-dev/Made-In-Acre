/**
 *  Problema E -  Código
 * Adhoc
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int qtd = 0;

    for(int i = 1; i <= 7 ; i++) {
        int bit; cin >> bit;
        qtd += bit;
    }

    int seg; cin >> seg;

    if(qtd % 2 == seg) {
        cout << "N?" << endl;
    } else {
        cout << "S" << endl;
    }

    return 0;
}
