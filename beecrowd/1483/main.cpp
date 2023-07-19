/**
 * [Nome da questão]
 * beecrowd | [Número]
 * [Link]
 * [Assuntos]
 */

#include <bits/stdc++.h>

using namespace std;

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
    double aposta;
    string numeroApostado, valorSorteado;

    while (cin >> aposta >> numeroApostado >> valorSorteado) {
        if (aposta == 0 && numeroApostado == "0" && valorSorteado == "0") {
            return 0;
        }
        cout << fixed;
        cout << setprecision(2);
        while (sz(numeroApostado) < 4) {
            numeroApostado = "0" + numeroApostado;
        }

        while (sz(valorSorteado) < 4) {
            valorSorteado = "0" + valorSorteado;
        }

        if (numeroApostado.substr(sz(numeroApostado) - 4) == valorSorteado.substr(sz(valorSorteado) - 4)) {
            cout << aposta * 3000.00 << endl;
            continue;
        } else if (numeroApostado.substr(sz(numeroApostado) - 3) == valorSorteado.substr(sz(valorSorteado) - 3)) {
            cout << aposta * 500.00 << endl;
            continue;
        } else if (numeroApostado.substr(sz(numeroApostado) - 2) == valorSorteado.substr(sz(valorSorteado) - 2)) {
            cout << aposta * 50.00 << endl;
            continue;
        } else {
            string NumString1 = numeroApostado.substr(sz(numeroApostado) - 2);
            string NumString2 = valorSorteado.substr(sz(valorSorteado) - 2);
            if (NumString1 == "00") {
                NumString1 = "100";
            }

            if (NumString2 == "00") {
                NumString2 = "100";
            }

            if ((ceil(stof(NumString1) / 4)) == ceil(stof(NumString2) / 4)) {
                cout << aposta * 16.00 << endl;
                continue;
            }
        }
        cout << 0.00 << endl;
    }
    return 0;
}

