#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define SPEED                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define MOD 1e9 + 7
#define FOR(i, a, b) for (ll i = a; i < (b); i++)
#define rep (i, n) FOR(i, 0, n)
#define Rep (i, a, b) for (ll i = a; i >= (b); i--)
#define all(x) begin(x), end(x)
#define log(x) cout << x << endl
#define endl "\n"

template <typename T>

void read(T& arg) {
    std::cin >> arg;
}

template <typename T, typename... Args>
void read(T& first, Args&... args) {
    std::cin >> first;
    read(args...);
}

int main() {
    SPEED;

    ll a, b, c, aux = 1;

    while (cin >> a && a != 0) {
        read(b, c);

        ll pit = (b * b) + (c * c);

        if (sqrt(pit) <= a * 2) {
            cout << "Pizza " << aux << " fits on the table." << endl;
        } else {
            cout << "Pizza " << aux << " does not fit on the table." << endl;
        }
        aux++;
    }

    return 0;
}
