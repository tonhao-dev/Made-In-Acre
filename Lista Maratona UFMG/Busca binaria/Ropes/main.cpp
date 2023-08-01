/**
 * https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B
 * Busca binaria, binary search, bissercao
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define db(x) cout << #x << ": " << x << endl
#define db_pair(x) cout << #x << ": " << x.f << ", " << x.s << endl
#define print_vector(vector) \
    for (auto x : vector)    \
        cout << x << " ";    \
    cout << endl
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
#define MAX_N 1e9

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef long double ld;

template <typename T>
void read(T& arg) {
    cin >> arg;
}

template <typename T, typename... Args>
void read(T& first, Args&... args) {
    cin >> first;
    read(args...);
}

// FIM DOS MACROS

ll pieces(vll& ropes, ld try_length) {
    ll count_pieces = 0;
    foreach (rope, ropes) {
        count_pieces += (ll)rope / try_length;
    }

    return count_pieces;
}

ld binary_search(vll& ropes, ll k_pieces, double max_n) {
    ld l = 1, r = max_n;
    ld m, resp;

    /**
     * Faça um loop ate 100 para nao ter que pensar muito sobre o erro absoluto
     * ou relativo
     */
    rep(i, 100) {
        m = (ld)(l + (ld)r) / (ld)2.0;

        if (k_pieces <= pieces(ropes, m)) {
            l = m;
            resp = m;
        } else {
            r = m;
        }
    }

    return resp;
}

int main(int argc, char** argv) {
    SPEED;
    ll n, k;
    read(n, k);

    vll ropes(n);
    rep(i, n) read(ropes[i]);

    cout << fixed;
    cout.precision(20);

    log(binary_search(ropes, k, MAX_N));

    return 0;
}
