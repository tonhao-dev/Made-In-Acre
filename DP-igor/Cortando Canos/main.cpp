/**
 * [https://www.beecrowd.com.br/repository/UOJ_1798.html]
 * [programação dinâmica]
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
        cout << e.first << " " << e.second << endl; \
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
vector<pll> canos;
unordered_map<ll, ll> memo;

ll calculaMaximoCusto(ll tamanhoCano) {
    if (tamanhoCano == 0) return 0;
    if (memo.count(tamanhoCano)) return memo[tamanhoCano];

    for (auto e : canos) {
        if(e.first > tamanhoCano) continue;
        memo[tamanhoCano] = max(memo[tamanhoCano], calculaMaximoCusto(tamanhoCano - e.first) + e.second);
    }
    return memo[tamanhoCano];
}

int main(int argc, char** argv) {
    SPEED;
    ll qtdCanos, tamanhoCano, c, v;
    read(qtdCanos, tamanhoCano);
    canos.assign(qtdCanos, {0, 0});
    for(ll i = 0; i<qtdCanos; i++) cin >> canos[i].f >> canos[i].s;

    log(calculaMaximoCusto(tamanhoCano));

    return 0;
}
