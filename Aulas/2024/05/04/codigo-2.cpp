#include <bits/stdc++.h>

using namespace std;

void sequencia(int n) {
    if (n == 0) {
        return;
    }

    cout << n << endl;

    sequencia(n - 1);
}

int main() {
    sequencia(10);

    return 0;
}
