/**
 * 2779 - Álbum da Copa
 * Adhoc
 */


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> figurinhas;

    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;

        bool achou = true;
        for(auto figurinha : figurinhas) {
            if(figurinha == x) {
                achou = false;
                break;
            }
        }

        if(achou) {
            figurinhas.push_back(x);
        }
    }

    cout << (n - (int)figurinhas.size()) << endl;

    return 0;
}
