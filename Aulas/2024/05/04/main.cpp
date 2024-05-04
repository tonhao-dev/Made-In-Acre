#include <bits/stdc++.h>

using namespace std;

int soma(int n, int m) {
    if (n == m) return n;

    return n + soma(n + 1, m);
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n <= 0 || m <= 0) break;

        if (n > m) {
            // int aux = n;
            // n = m;
            // m = aux;
            swap(n, m);
        }

        for (int i = n; i <= m; i++) {
            cout << i << " ";
        }
        cout << "Sum=" << soma(n, m) << endl;
    }

    return 0;
}
