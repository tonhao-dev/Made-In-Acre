/**
 * Problema C - Múltiplos saltos em distância
 * Programação dinâmica
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG true
#define db(x) \
    if (DEBUG) cout << #x << ": " << x << endl
#define dbpair(x) \
    if (DEBUG) cout << #x << ": " << x.f << ", " << x.s << endl
#define dbvector(vector)                           \
    {                                              \
        cout << #vector << " = ";                  \
        for (auto& it : vector) cout << it << " "; \
        cout << endl;                              \
    }
#define dbmap(map)                          \
    for (auto e : map)                      \
        cout << e.first << " " << e.second; \
    cout << endl
#define all(x) begin(x), end(x)
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second
#define MOD 1e9 + 7
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAXN = 262'200;

int n;
vector<int> moedas;
vector<int> memo;

int dp(int k) {
    if(k >= n) {
        if(k == n) return moedas[k];
        return 0;
    }

    auto &p = memo[k];
    if(p != -1) return p;

    auto dobro = moedas[k] + dp(2 * k);
    auto dobro_mais_um = moedas[k] + dp((2 * k) + 1);

    return p = max(dobro, dobro_mais_um);
}

int main(int argc, char** argv) {
    SPEED;

    int aux; cin >> aux;
    n = pow(2, aux) - 1;

    moedas.resize(MAXN);
    memo.assign(MAXN, -1);

    for(int i = 1; i <= n; i++) {
        cin >> moedas[i];
    }


    cout << dp(1) << endl;

    return 0;
}
