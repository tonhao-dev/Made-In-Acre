/**
 * [Nome da questão]
 * beecrowd | [Número]
 * [Link]
 * [Assuntos]
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
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
    SPEED;

    ll N;
    while (cin >> N) {
        if (N == 0) break;

        vll postes(N + 1);
        ll resp = 0, postes_quebrados = 0;

        rep(i, N) {
            cin >> postes[i];
        }

        rep(i, N - 2) {
            if (postes[i] == 0)
                postes_quebrados++;
            else
                postes_quebrados = 0;
            if (postes_quebrados < 2) continue;

            postes_quebrados = 0;
            resp++;
        }

        cout << resp << endl;
    }

    return 0;
}
