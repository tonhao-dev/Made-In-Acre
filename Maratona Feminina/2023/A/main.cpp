/**
 *  Problema A - Troca de Bicicletas
 * Adhoc, implementação
 */

#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n; cin >> n;

    vector<int> trocas(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> trocas[i];
    }

    for(int pessoa = 1; pessoa <= n; pessoa++) {
        vector<int> passou;

        passou.push_back(pessoa);

        int pessoa_atual = trocas[pessoa];
        while(pessoa_atual != pessoa) {
            passou.push_back(pessoa_atual);
            pessoa_atual = trocas[pessoa_atual];
        }

        int flag = 0;
        for(auto p : passou) {
            if(flag) cout << " ";
            flag = 1;
            cout << p;
        }
        cout << endl;
    }
}

int main() {
    int t; cin >> t;

    while(t--) solve();

    return 0;
}
