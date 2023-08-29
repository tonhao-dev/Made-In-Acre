/**
 * Fastminton
 * codeforces | 102861
 * https://codeforces.com/gym/102861/problem/F
 * Ad Hoc; Simulação
 */

#include <bits/stdc++.h>

using namespace std;

#define ESQ 0
#define DIR 1
#define NO_WINNER -1

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

ll verifica_vencedor(vll &pontos) {
    if (pontos[ESQ] == 10) return ESQ;
    if (pontos[DIR] == 10) return DIR;

    if (pontos[ESQ] >= 5 && pontos[ESQ] - pontos[DIR] >= 2) return ESQ;
    if (pontos[DIR] >= 5 && pontos[DIR] - pontos[ESQ] >= 2) return DIR;

    return NO_WINNER;
}

string placar(vll &games, vll &pontos, ll saque) {
    if (games[ESQ] == 2)
        return to_string(games[ESQ]) + " (winner) - " + to_string(games[DIR]) + endl;
    else if (games[DIR] == 2)
        return to_string(games[ESQ]) + " - " + to_string(games[DIR]) + " (winner)" + endl;

    if (saque == ESQ)
        return to_string(games[ESQ]) + " (" + to_string(pontos[ESQ]) + "*) - " + to_string(games[DIR]) + " (" + to_string(pontos[DIR]) + ")" + endl;
    else
        return to_string(games[ESQ]) + " (" + to_string(pontos[ESQ]) + ") - " + to_string(games[DIR]) + " (" + to_string(pontos[DIR]) + "*)" + endl;
}

int main(int argc, char **argv) {
    cin.tie(0)->sync_with_stdio(0);

    string eventos;
    cin >> eventos;

    vll games(2);
    vll pontos(2);
    ll saque = ESQ;
    foreach (evento, eventos) {
        if (evento == 'S')
            pontos[saque]++;
        else if (evento == 'R') {
            saque = saque == ESQ ? DIR : ESQ;
            pontos[saque]++;
        } else
            cout << placar(games, pontos, saque);

        ll winner = verifica_vencedor(pontos);

        if (winner == NO_WINNER) continue;

        if (winner == ESQ)
            games[ESQ]++;
        else
            games[DIR]++;

        fill(all(pontos), 0);
    }

    return 0;
}
