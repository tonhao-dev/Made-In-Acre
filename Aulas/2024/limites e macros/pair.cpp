#include <bits/stdc++.h>

using namespace std;

#define speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

/*
 * motivação:
 * https://judge.beecrowd.com/pt/problems/view/1351
 * https://judge.beecrowd.com/pt/problems/view/2396
 * 
 * questão:
 * https://judge.beecrowd.com/pt/problems/view/2286
*/


int main() {
    speed;

    int n, caso = 1;
    while(true) {
        cin >> n;
        if(n == 0) break;

        pair<string, string> jogadores;
        cin >> jogadores.first >> jogadores.second;

        vector<pair<int, int>> jogadas(n);
        for(int i = 0; i < n; i++) {
            cin >> jogadas[i].first >> jogadas[i].second;
        }

        cout << "Teste " << caso << endl;
        for(auto jogada : jogadas) {
            int soma = jogada.first + jogada.second;
            if(soma % 2 == 0) {
                cout << jogadores.first << endl;
            } else {
                cout << jogadores.second << endl;
            }
        }

        cout << endl;
        caso++;
    }

    return 0;
}