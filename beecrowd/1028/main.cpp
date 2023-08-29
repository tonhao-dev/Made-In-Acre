/**
 * Figurinhas - https://www.beecrowd.com.br/judge/pt/problems/view/1028
 * Matemática, MDC
 */

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

    ll test_cases, a, b;
    read(test_cases);

    for (ll test = 0; test < test_cases; ++test) {
        read(a, b);

        cout << __gcd(a, b) << endl;
    }

    return 0;
}
