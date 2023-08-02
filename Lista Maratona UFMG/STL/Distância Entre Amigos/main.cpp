/**
 * [Link]
 * [Assuntos]
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

ll distancia(ll i, ll j, ll hi, ll hj) {
    return hi + abs(i - j) + hj;
}

int main(int argc, char **argv) {
    SPEED;
    ll num_predios;
    cin >> num_predios;
    vll predios(num_predios);
    rep(i, num_predios) {
        cin >> predios[i];
    }

    ll resp = LLONG_MIN;
    rep(i, num_predios - 1) {
        FOR(j, i, num_predios) {
            resp = max(resp, distancia(i, j, predios[i], predios[j]));
        }
    }

    cout << resp << endl;

    return 0;
}
