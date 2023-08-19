
/**
 * https://vjudge.net/contest/576477#problem/D
 * guloso, ad hoc
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

int main(int argc, char** argv) {
    SPEED;
    ll value, qtdNotas = 0;
    read(value);

    if (value >= 100) {
        qtdNotas += value / 100;
        value = value % 100;
    }

    if (value >= 20) {
        qtdNotas += value / 20;
        value = value % 20;
    }

    if (value >= 10) {
        qtdNotas += value / 10;
        value = value % 10;
    }

    if (value >= 5) {
        qtdNotas += value / 5;
        value = value % 5;
    }

    if (value >= 1) {
        qtdNotas += value / 1;
        value = value % 1;
    }

    log(qtdNotas);

    return 0;
}
