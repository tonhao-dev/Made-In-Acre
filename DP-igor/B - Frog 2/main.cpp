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

ll k;
vll alturasPedras(1e5+10);
vll custos(1e5+10, LLONG_MAX);


ll calculaCusto(ll indexPedra) {
    if(indexPedra == 0) return 0;
    if(custos[indexPedra] != LLONG_MAX) return custos[indexPedra];
    for(ll i = 1; i <= k; i++) {
        if(i > indexPedra) break;
        custos[indexPedra] = min(custos[indexPedra],  calculaCusto(indexPedra-i) + abs(alturasPedras[indexPedra] - alturasPedras[indexPedra - i]));
    }
    return custos[indexPedra];
}


int main(int argc, char** argv) {
    SPEED;

    ll pedras;

    read(pedras, k);
    rep(i, pedras)
        read(alturasPedras[i]);

    log(calculaCusto(pedras-1));

    return 0;
}

