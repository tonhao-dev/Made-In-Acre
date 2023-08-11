/**
 * https://www.beecrowd.com.br/judge/pt/problems/view/2463
 * Guloso, kadane
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

tuple<ll, ll, ll> kadane(vll& array) {
    ll max_so_far = LLONG_MIN, max_ending_here = 0;
    ll start = 0, end = 0, new_start = 0;

    rep(i, sz(array)) {
        max_ending_here += array[i];

        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = new_start;
            end = i;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
            new_start = i + 1;
        }
    }

    return make_tuple(max_so_far, start, end);
}

int main(int argc, char** argv) {
    SPEED;

    ll n;
    read(n);

    vll vidas(n);
    rep(i, n) {
        read(vidas[i]);
    }

    ll lucro_total, start, end;
    tie(lucro_total, start, end) = kadane(vidas);

    log(lucro_total);

    return 0;
}
