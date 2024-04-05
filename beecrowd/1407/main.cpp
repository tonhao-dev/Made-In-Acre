#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, c, k;

    while(true) {
        cin >> n >> c >> k;
        if(n == 0 && c == 0 && k == 0) break;

        vector<int> sorteados(k + 1, 0);

        while(n--) {
            for(int i = 0; i < c; i++) {
                int sorteado; cin >> sorteado;
                sorteados[sorteado]++;
            }
        }

        int minimo_sorteado = sorteados[1];
        for(int i = 1; i <= k; i++) {
            minimo_sorteado = min(minimo_sorteado, sorteados[i]);
        }

        int flag = 0;
        for(int i = 1; i <= k; i++) {
            if(sorteados[i] == minimo_sorteado) {
                if(flag) cout << " ";
                flag = 1;
                cout << i;
            }
        }
        cout << endl;
    }

    return 0;
}
