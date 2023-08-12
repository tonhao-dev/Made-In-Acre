/**
 * [Link]
 * [Assuntos]
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

vll elevatedNumbers;

void populateArray() {
    rep(i, 31) {
        elevatedNumbers.push_back(1 << i); // hack life
    }
}


int main(int argc, char** argv) {
    SPEED;

    populateArray();
    ll test_cases, n, a, b, mid;
    read(test_cases);
    rep(test_case, test_cases) {
        a = 0 , b = 0;
        read(n);
        b += elevatedNumbers[n];
        mid = n/2;
        for(ll i = n - 1; i >= mid; i--) {
            a+= elevatedNumbers[i];
        }
        for(ll i = 1; i < mid; i++) {
            b+= elevatedNumbers[i];
        }
        log(abs(a-b));
    }


    return 0;
}

