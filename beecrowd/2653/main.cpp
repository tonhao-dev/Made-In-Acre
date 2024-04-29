#include <bits/stdc++.h>

using namespace std;

int main() {
    set<string> lista_joias;
    int tipos_joias = 0;
    string joia;

    while (cin >> joia) {
        if (lista_joias.count(joia) == 1) continue;

        lista_joias.insert(joia);
        tipos_joias++;
    }

    cout << tipos_joias << endl;

    return 0;
}
