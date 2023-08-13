/**
 * https://codeforces.com/contest/1342/problem/A
 * Guloso
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define db(x) cout << #x << ": " << x << endl
#define db_pair(x) cout << #x << ": " << x.f << ", " << x.s << endl
#define printv(vector)                             \
    {                                              \
        cout << #vector << " = ";                  \
        for (auto& it : vector) cout << it << " "; \
        cout << endl;                              \
    }
#define print_map(map)                      \
    for (auto e : map)                      \
        cout << e.first << " " << e.second; \
    cout << endl
#define FOR(i, a, b) for (ll i = a; i < (b); ++i)
#define foreach(a, b) for (auto&(a) : (b))
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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

template <typename T>

void read(T& arg) {
    std::cin >> arg;
}

template <typename T, typename... Args>
void read(T& first, Args&... args) {
    std::cin >> first;
    read(args...);
}

int main(int argc, char** argv) {
    SPEED;

    ll test_cases;
    read(test_cases);

    rep(test_case, test_cases) {
        ll x, y, a, b;
        read(x, y, a, b);

        if (y > x) swap(x, y);

        bool bothValeAPena = b <= a * 2;
        ull resp = 0;

        if (bothValeAPena) {
            if (x > y) {
                resp += a * abs(x - y);
                x = y;
            }

            if (x > 0) {
                resp += b * x;
                x = y = 0;
            }
        } else {
            if (x > 0) {
                resp += a * x;
                x = 0;
            }

            if (y > 0) {
                resp += a * y;
                y = 0;
            }
        }

        log(resp);
    }

    return 0;
}
