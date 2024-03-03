#include <iostream>
using namespace std;

int main() {
    int n, numero;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numero;
        if (numero == 0) {
            cout << "NULL" << endl;
        } else {
            if (numero % 2 == 0)
                cout << "EVEN ";
            else
                cout << "ODD ";
            if (numero < 0)
                cout << "NEGATIVE" << endl;
            else
                cout << "POSITIVE" << endl;
        }
    }
    return 0;
}
