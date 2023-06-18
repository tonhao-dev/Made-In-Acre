#include <bits/stdc++.h>
using namespace std;

#define db(message, x) cout << message << ": " << x << endl
#define cv(vector)        \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(int argc, char **argv) {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m, s, saida = 0;
    cin >> n >> m >> s;

    for (ll i = 0; i < s; ++i) {
        ll x, y, r, area;
        cin >> x >> y >> r;

#ifndef ONLINE_JUDGE
        db("x", x);
        db("y", y);
        db("r", r);

        db("min(x + r + 1, n + 1)", min(x + r + 1, n + 1));
        db("max(x - r, 1LL)", max(x - r, 1LL));
        db("min(y + r + 1, m + 1)", min(y + r + 1, m + 1));
        db("max(y - r, 1LL)", max(y - r, 1LL));
#endif
        area = (min(x + r + 1, n + 1) - max(x - r, 1LL)) * (min(y + r + 1, m + 1) - max(y - r, 1LL));

        saida += area;
    }

    cout << floor(saida / (n * m)) << "\n";

    return 0;
}
