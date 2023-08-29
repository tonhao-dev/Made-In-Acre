/**
 * https://vjudge.net/contest/438388#problem/E
 * PD, DP, programacao, programação dinamica
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

vll memo;

ll count_terms(ll number) {
    if (number == 0) return 0;

    if (memo[number] != LLONG_MAX) return memo[number];

    for (ll i = 1; i * i <= number; ++i) {
        memo[number] = min(memo[number], 1 + count_terms(number - i * i));
    }

    return memo[number];
}

int main(int argc, char** argv) {
    SPEED;

    ll test_cases;
    read(test_cases);

    vll numbers(test_cases);
    rep(test_case, test_cases) {
        read(numbers[test_case]);
    }

    memo.resize(1e4 + 10, LLONG_MAX);

    rep(i, test_cases) {
        log(count_terms(numbers[i]));
    }

    return 0;
}
