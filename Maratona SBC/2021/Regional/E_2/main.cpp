/**
 * E - Escada Rolante
 * Ad hoc
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
#define FOR(i, a, b) for (int i = a; i < (b); ++i)
#define foreach(a, b) for (auto &(a) : (b))
#define rep(i, n) FOR(i, 0, n)
#define Rep(i, a, b) for (int i = a; i >= (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
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

    int n;
    ll ans = 0, util = 0;
    vll v;
    cin >> n;
    bool flag = false;

    rep(i, n) {
        ll x, z;
        cin >> x >> z;

        if (x > ans) {
            if (sz(v)) {
                util ? util = 0 : util = 1;
                ans += 10;
                v.clear();
            } else {
                flag = true;
            }
        }
        if (util == z || flag) {
            flag = false;
            util = z;
            ans = x + 10;
        } else {
            v.pb(x);
        }
    }

    if (sz(v)) {
        cout << ans + 10 << endl;
    } else {
        cout << ans << endl;
    }



    return 0;
}
