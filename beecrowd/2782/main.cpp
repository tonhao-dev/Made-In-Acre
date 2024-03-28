#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> numeros(N);
    for (int i = 0; i < N; i++) cin >> numeros[i];

    if (N == 1 || N == 2) {
        cout << 1 << endl;
        return 0;
    }

    int resp = 1, ultima_dif = numeros[1] - numeros[0];
    for (int i = 1; i < N; i++) {
        if (numeros[i] - numeros[i - 1] == ultima_dif) continue;

        ultima_dif = numeros[i] - numeros[i - 1];
        resp++;
    }

    cout << resp << endl;

    return 0;
}
