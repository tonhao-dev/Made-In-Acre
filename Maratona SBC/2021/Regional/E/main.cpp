/**
 * Escalator
 * codeforces | 103388
 * https://codeforces.com/gym/103388/problem/E
 * [Assuntos]
 */

#include <bits/stdc++.h>

using namespace std;

#define INICIO -1
#define ESQ2DIR 0
#define DIR2ESQ 1

#define db(x) cout << #x << ": " << x << endl
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

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int main(int argc, char **argv) {
    cin.tie(0)->sync_with_stdio(0);
    ll N;
    cin >> N;

    ll agora, direcao_escada;
    cin >> agora >> direcao_escada;
    priority_queue<ll, vector<ll>, greater<ll>> esq, dir;

    FOR(i, 1, N) {
        ll tempo, direcao;
        cin >> tempo >> direcao;

        if (direcao == ESQ2DIR)
            esq.push(tempo);
        else
            dir.push(tempo);
    }

    agora += 10;
    while (esq.size() > 0 || dir.size() > 0) {
        if (direcao_escada == ESQ2DIR) {
            if (agora > esq.top()) {
                agora = esq.top() + 10;
                esq.pop();
            } else {
                agora = max(agora, dir.top()) + 10;
                dir.pop();
                direcao_escada = DIR2ESQ;
            }
        } else {
            if (agora > dir.top()) {
                agora = dir.top() + 10;
                dir.pop();
            } else {
                agora = max(agora, esq.top()) + 10;
                esq.pop();
                direcao_escada = ESQ2DIR;
            }
        }

        if (esq.size() == 0 && dir.size() > 0 && direcao_escada == ESQ2DIR) {
            agora = max(agora, dir.top()) + 10;
            dir.pop();
        } else if (dir.size() == 0 && esq.size() > 0 && direcao_escada == DIR2ESQ) {
            agora = max(agora, esq.top()) + 10;
            esq.pop();
        }
    }

    cout << agora << endl;

    return 0;
}
