/**
 * https://www.beecrowd.com.br/judge/pt/problems/view/1245
 * Ad hoc, map
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
#define MOD 1e9+7
#define log(x) cout << x << endl

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int main(int argc, char **argv) {
    SPEED;
    ll num_botas;
    while(cin >> num_botas) {
        unordered_map<ll, pll> pares;

        rep(i, num_botas) {
            ll numero; char lado;

            cin >> numero >> lado;

            if(lado == 'E') pares[numero].f++;
            else pares[numero].s++;
        }


        ll resp = 0;
        foreach(par, pares) {
            resp += min(par.s.f, par.s.s);
        }

        log(resp);
    }

    return 0;
}
