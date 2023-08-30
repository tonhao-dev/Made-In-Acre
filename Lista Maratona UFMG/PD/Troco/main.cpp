/**
 * https://www.beecrowd.com.br/judge/pt/problems/view/2446
 * Troco
 * Programação dinâmica, PD, DP
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

char ehPossivel(ll troco, vll& moedas) {
    vector<bool> memo(1e5 + 10);

    memo[0] = true;
    foreach (moeda, moedas) {
        for (ll valor = troco; valor >= moeda; valor--) {
            memo[valor] = memo[valor] || memo[valor - moeda];
        }
    }

    return memo[troco] ? 'S' : 'N';
}

int main(int argc, char** argv) {
    SPEED;

    ll valor_compra, n_moedas;
    read(valor_compra, n_moedas);

    vll moedas(n_moedas + 1);
    FOR(i, 1, n_moedas + 1) {
        read(moedas[i]);
    }

    log(ehPossivel(valor_compra, moedas));

    return 0;
}
