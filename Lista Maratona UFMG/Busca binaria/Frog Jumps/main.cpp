/**
 * https://codeforces.com/contest/1324/problem/C
 * Ad hoc
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define db(x) cout << #x << ": " << x << endl
#define db_pair(x) cout << #x << ": " << x.f << ", " << x.s << endl
#define printv(vector)                             \
    {                                              \
        cout << #vector << " = ";                  \
        for (auto &it : vector) cout << it << " "; \
        cout << endl;                              \
    }
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
#define MOD 1e9 + 7
#define log(x) cout << x << endl
#define read(x) cin >> x

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int main(int argc, char **argv) {
    SPEED;
    ll tests;
    cin >> tests;
    cin.ignore();

    rep(test, tests) {
        string s;
        getline(cin, s);

        vll pos_direitas;

        pos_direitas.push_back(0);
        rep(i, sz(s)) {
            if (s[i] == 'R') {
                pos_direitas.push_back(i + 1);
            }
        }
        pos_direitas.push_back(sz(s) + 1);

        ll resp = LLONG_MIN;
        rep(i, sz(pos_direitas) - 1) {
            resp = max(resp, abs(pos_direitas[i] - pos_direitas[i + 1]));
        }

        log(resp);
    }

    return 0;
}
