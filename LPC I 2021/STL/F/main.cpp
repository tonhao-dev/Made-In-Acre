/**
 * https://vjudge.net/contest/433311#problem/F
 * Ad hoc, pilha, stack
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define db(x) cout << #x << ": " << x << endl
#define db_pair(x) cout << #x << ": " << x.f << ", " << x.s << endl
#define cv(vector)        \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl
#define cm(map)                             \
    for (auto e : map)                      \
        cout << e.first << " " << e.second; \
    cout << endl
#define FOR(i, a, b) for (ll i = a; i < (b); ++i)
#define foreach(a, b) for (auto &(a) : (b))
#define rep(i, n) FOR(i, 0, n)
#define Rep(i, a, b) for (ll i = a; i >= (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second
#define MOD 1e9 + 7
#define log(x) cout << x << endl

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int main(int argc, char **argv) {
    SPEED;
    ll n;

    while (cin >> n) {
        if (n == 0) break;

        ll number;
        ll caminhao_da_vez = 1;
        bool ehPossivel = true;
        stack<ll> pilha;

        rep(i, n) {
            cin >> number;

            if (number != caminhao_da_vez) {
                if (pilha.empty()) {
                    pilha.push(number);
                    continue;
                }

                while (!pilha.empty() && pilha.top() == caminhao_da_vez) {
                    pilha.pop();
                    caminhao_da_vez++;
                }

                // Faltou um else para essa condição na hora da prova
                // Não pensamos que depois de tirar os valores da pilha
                // podia ser que o valor lido fosse o caminhao da vez
                if (number != caminhao_da_vez) {
                    pilha.push(number);
                } else {
                    caminhao_da_vez++;
                }
            } else {
                caminhao_da_vez++;
            }
        }

        while (!pilha.empty() && pilha.top() == caminhao_da_vez) {
            pilha.pop();
            caminhao_da_vez++;
        }

        if (pilha.empty()) {
            log("yes");
        } else {
            log("no");
        }
    }

    return 0;
}
