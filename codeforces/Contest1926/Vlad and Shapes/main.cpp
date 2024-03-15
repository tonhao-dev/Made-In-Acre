/**
 * [https://codeforces.com/contest/1926/problem/B]
 * [Assuntos]
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG false
#define db(x) \
    if (DEBUG) cout << #x << ": " << x << endl
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

int main(int argc, char** argv) {
    SPEED;
    ll test_cases;
    read(test_cases);
    rep(test_case, test_cases) {
        int order, m = 0, zeros = 0;
        string n;
        set<int> qtdUms;
        read(order);
        for(int i = 0; i<order; i++) {
            read(n);
            db(n);
            int ums = count(n.begin(), n.end(), '1');
            db(ums);
            qtdUms.insert(ums);
            zeros += n.size() - ums;
        }
        db(qtdUms.size());
        if(qtdUms.size() == 2 || zeros == 0) log("SQUARE");
        else log("TRIANGLE");
    }

    return 0;
}
