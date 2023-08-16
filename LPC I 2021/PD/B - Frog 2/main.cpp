/**
 * https://atcoder.jp/contests/dp/tasks/dp_b
 * PD, programação dinâmica
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

ll jumps(vll& pedras, ll N, ll K) {
    vll dp(1e5 + 10, LLONG_MAX);

    dp[0] = dp[1] = 0;
    FOR(i, 1, N + 1) {
        FOR(j, i + 1, i + K + 1) {
            dp[j] = min(abs(pedras[i] - pedras[j]) + dp[i], dp[j]);
        }
    }

    return dp[N];
}

int main(int argc, char** argv) {
    SPEED;

    ll N, K;
    read(N, K);

    vll pedras(1e5 + 10);

    FOR(i, 1, N + 1) {
        read(pedras[i]);
    }

    log(jumps(pedras, N, K));

    return 0;
}
