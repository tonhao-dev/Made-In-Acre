/**
 * Tornado
 * beecrowd | 1266
 * https://www.beecrowd.com.br/judge/pt/problems/view/1266
 * Ad hoc
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

        vll postes(N);
        ll index_primeiro_poste = -1;

        rep(i, N) {
            cin >> postes[i];
            if (postes[i] == 1) index_primeiro_poste = i;
        }

        if (index_primeiro_poste == -1) {
            cout << ceil(N / 2.0) << endl;
            continue;
        }

        ll num_passos = N, i = index_primeiro_poste, quebrados = 0;
        ll resp = 0;
        while (num_passos > 0) {
            if (postes[i] == 0) {
                quebrados++;
            } else {
                quebrados = 0;
            }

            if (quebrados == 2) {
                postes[i] = 1;
                resp++;
                quebrados = 0;
            }

            i++;
            num_passos--;

            if (i == sz(postes)) i = 0;
        }

        cout << resp << endl;
    }

    return 0;
}
