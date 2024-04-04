#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    while (true) {
        int num_bancos, num_debentures;
        cin >> num_bancos >> num_debentures;

        if (num_bancos == 0 and num_debentures == 0) break;

        vector<int> reservas_bancos(num_bancos);
        for (int i = 0; i < num_bancos; ++i) cin >> reservas_bancos.at(i);

        for (int i = 0; i < num_debentures; ++i) {
            int devedor, credor, valor;
            cin >> devedor >> credor >> valor;

            reservas_bancos[devedor - 1] -= valor;
            reservas_bancos[credor - 1] += valor;
        }

        if (all_of(reservas_bancos.begin(), reservas_bancos.end(), [](int i) { return i >= 0; }))
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }

    return 0;
}
