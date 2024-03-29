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

int binarySearch(vector<ll> &vector, ll n) {
    ll esq = 0, dir = vector.size();

    while(esq < dir) {
        ll meio = (esq + dir) / 2;

        if(vector[meio] > n){
            dir = meio;
        } else if(vector[meio] < n) {
            esq = meio + 1;
        } else {
            return 1;
        }
    }
    return 0;
}


int main(int argc, char** argv) {
    SPEED;

    ll tamanho, buscas, number;
    read(tamanho, buscas);

    vector<ll> n(tamanho);

    rep(i, tamanho) {
        read(n[i]);
    }

    rep(i, buscas) {
        read(number);
        if(binarySearch(n, number)) {
            log("YES");
        } else {
            log("NO");
        }
    }
    return 0;
}
