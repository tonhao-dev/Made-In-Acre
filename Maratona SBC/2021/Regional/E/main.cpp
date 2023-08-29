/**
 * E - Escada Rolante
 * Ad hoc
 */

#include <bits/stdc++.h>

using namespace std;

#define INICIO -1
#define ESQ2DIR 0
#define DIR2ESQ 1

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

    ll n;
    cin >> n;
    vector<pll> pessoas(n);
    rep(i, n) {
        cin >> pessoas[i].f >> pessoas[i].s;
    }

    ll i = 0;
    pll escada, espera = make_pair(-1, -1);
    bool escada_vazia = true;
    rep(tempo, 100000) {
        if (i == sz(pessoas)) break;

        if (tempo == pessoas[i].f && escada_vazia == true) {
            db(tempo);
            db_pair(pessoas[i]);
            db(i);
            escada = pessoas[i];
            i++;
            escada_vazia = false;
            continue;
        }

        if (tempo == pessoas[i].f && escada_vazia == false && escada.s == pessoas[i].s) {
            db(tempo);
            db_pair(pessoas[i]);
            db(i);
            db_pair(espera);
            db_pair(escada);
            escada = pessoas[i];
            i++;
            continue;
        }

        if (tempo == pessoas[i].f && escada_vazia == false && escada.s != pessoas[i].s) {
            db(tempo);
            db_pair(pessoas[i]);
            db(i);
            db_pair(espera);
            db_pair(escada);
            espera = pessoas[i];
            i++;
            continue;
        }

        if (tempo == escada.f + 10) {
            db(tempo);
            db_pair(pessoas[i]);
            db(i);
            db_pair(espera);
            db_pair(escada);
            if (espera.f != -1) {
                escada = make_pair(tempo, espera.s);
                espera = make_pair(-1, -1);
            } else {
                escada_vazia = true;
            }
        }
    }

    if (espera.f != -1) {
        cout << escada.f + 20 << endl;
    } else {
        cout << escada.f + 10 << endl;
    }

    return 0;
}
