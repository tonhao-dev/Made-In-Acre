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

    ll n;
    cin >> n;

    for (ll i = n; i != 1; i = i % 2 == 1 ? i * 3 + 1 : i / 2) cout << i << " ";

    cout << "1\n";

    return 0;
}
