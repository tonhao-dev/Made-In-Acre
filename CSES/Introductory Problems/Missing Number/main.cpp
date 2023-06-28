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
    vector<bool> numbers(n + 1, false);
    rep(i, 0, n - 1) {
        ll number;
        cin >> number;
        numbers[number] = true;
    }

    rep(i, 1, n + 1) {
        if (!numbers[i]) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
