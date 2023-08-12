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

ll madeiraResultados(vll &alturaArvores, ll alturaH) {
    ll soma = 0;
    if(alturaH > alturaArvores[sz(alturaArvores)-1]) return 0;

    auto it = lower_bound(all(alturaArvores), alturaH);
    ll index = it - alturaArvores.begin();
    FOR(i, index, sz(alturaArvores)) {
        soma+= alturaArvores[i] - alturaH;
    }
    return soma;
}


ll binarySearch(vll &alturaArvores, ll madeiraNecessaria) {
    ll esq = 0, dir = 10e11, resp = 0;
    while(esq < dir ) {
        ll mid = (esq + dir)/2;
        if(madeiraResultados(alturaArvores, mid) < madeiraNecessaria) {
            dir = mid;
        } else {
            esq = mid + 1;
            resp = mid;
        }
    }
    return resp;
}



int main(int argc, char** argv) {
    SPEED;

    ll arvores, madeiraMetros;
    read(arvores, madeiraMetros);
    vll alturasArvores(arvores);

    rep(i, arvores) {
        read(alturasArvores[i]);
    }

    sort(all(alturasArvores));

    log(binarySearch(alturasArvores, madeiraMetros));

    return 0;
}
