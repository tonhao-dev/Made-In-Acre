/**
 * https://codeforces.com/problemset/problem/1343/C
 * Guloso, multiset
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

#define POSITIVE true
#define NEGATIVE false

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

int main(int argc, char** argv) {
    SPEED;

    ll test_cases;
    read(test_cases);

    rep(test_case, test_cases) {
        ll n;
        read(n);

        vector<multiset<ll, greater<ll>>> segmentos(1);
        ll current = 0;
        bool sign;
        rep(i, n) {
            ll ai;
            read(ai);

            if (i == 0) sign = ai > 0;

            if ((ai > 0 && sign == POSITIVE) || (ai < 0 && sign == NEGATIVE)) {
                segmentos[current].insert(ai);
            } else {
                multiset<ll, greater<ll>> novo;
                novo.insert(ai);
                segmentos.push_back(novo);
                current++;
                sign = ai > 0;
            }
        }

        ll resp = 0;
        foreach (seg, segmentos) {
            resp += *seg.begin();
        }

        log(resp);
    }

    return 0;
}
