/**
 * [Link]
 * [Assuntos]
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define db(x) cout << #x << ": " << x << endl
#define db_pair(x) cout << #x << ": " << x.f << ", " << x.s << endl
#define print_vector(vector) \
    for (auto x : vector)    \
        cout << x << " ";    \
    cout << endl
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

ll test_cases, n, k;

bool checaSeEstaProximoDoKth(ll x){
    ll divisiveisPorX = x/n;
    if((x - divisiveisPorX) >= k) return true;
    return false;
}

int buscaBinaria(){
    ll esquerda = 1, direita = 10e9;

    while(esquerda < direita) {
        ll meio = (esquerda + direita) / 2;

        if(checaSeEstaProximoDoKth(meio)){
            direita = meio;
        } else {
            esquerda = meio + 1;
        }
    }

    return esquerda;
}

int main(int argc, char** argv) {
    SPEED;
    read(test_cases);

    rep(test_case, test_cases) {
        read(n, k);
        log(buscaBinaria());
    }

    return 0;
}
