/**
 * https://codeforces.com/gym/101350/problem/M
 * Map, double, string
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

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int main(int argc, char **argv) {
    SPEED;
    ll t;
    cin >> t;
    rep(ti, t) {
        ll num_moedas, num_competicoes;
        cin >> num_moedas >> num_competicoes;

        unordered_map<string, double> cambio;
        cambio["JD"] = 1;
        rep(i, num_moedas) {
            string nome;
            double valor;
            cin >> nome >> valor;
            cambio[nome] = valor;
        }

        double resp = 0;
        rep(i, num_competicoes) {
            double valor;
            string nome;
            cin >> valor >> nome;

            resp += valor * cambio[nome];
        }

        cout << fixed;
        cout.precision(6);

        cout << resp << endl;
    }

    return 0;
}
