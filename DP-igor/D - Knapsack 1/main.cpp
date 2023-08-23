/**
 * [https://atcoder.jp/contests/dp/tasks/dp_d]
 * [Programaçao dinâmica]
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

vector<pll> wv;
ll N, W;
vector<vector<ll>> memo(100010, vector<ll>(110, LLONG_MIN));

ll maxW(ll weight, ll index) {
    if(weight < 0) return LLONG_MIN;
    if(weight == 0 || index == N) return 0;
    if(memo[weight][index] != LLONG_MIN) return memo[weight][index];

    ll naoPegaAtual = maxW(weight, index + 1);
    ll pegarAtual = wv[index].s + maxW(weight - wv[index].f, index + 1);
    return memo[weight][index] = max(naoPegaAtual, pegarAtual);
}

int main(int argc, char** argv) {
    SPEED;

    read(N, W);
    wv.assign(N, {0, 0});

    rep(i, N) read(wv[i].f, wv[i].s);
    log(maxW(W, 0));
    return 0;
}
