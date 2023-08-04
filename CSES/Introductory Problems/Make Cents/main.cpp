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

    ll casos, qtdMoedas, qtdCompeticoes ;
    double valorMoeda, valor, resp;
    string moeda;
    cin >> casos;

    rep(i, casos) {
        cin >> qtdMoedas >> qtdCompeticoes;

        unordered_map<string, double> map;

        rep(j, qtdMoedas) {
            cin >> moeda >> valorMoeda;
            map[moeda] = valorMoeda;
        }

        rep(k, qtdCompeticoes) {
            cin >> valor >> moeda;
            if(moeda != "JD") {
                resp += map[moeda] * valor;
            } else {
                resp += valor;
            }
        }
        cout << fixed;
        cout << setprecision(6);
        cout << resp << endl;
        resp = 0;
    }


    return 0;
}
