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

bool ehPossivel(string text, ll d) {
    ll ondeEstou = text.find('R'), tamanhoDoTexto = text.size();
    if (ondeEstou + 1 > d) {
        return false;
    }

    while ((ondeEstou + d) < tamanhoDoTexto) {
        bool achou = false;
        FOR(i, (ondeEstou + 1), tamanhoDoTexto) {
            if (text[i] == 'R') {
                achou = true;
                if ((i - ondeEstou) > d) {
                    return false;
                }
                ondeEstou = i;
                break;
            }
        }
        if (!achou) return false;
    }
    return true;
}

int buscaBinaria(string text) {
    ll esq = 1, dir = text.size() + 1, meio;
    while (esq < dir) {
        meio = (esq + dir) / 2;
        if (ehPossivel(text, meio)) {
            dir = meio;
        } else {
            esq = meio + 1;
        }
    }
    return esq;
}

int main(int argc, char** argv) {
    SPEED;

    ll test_cases;
    read(test_cases);

    rep(test_case, test_cases) {
        string texto;
        read(texto);
        log(buscaBinaria(texto));
    }

    return 0;
}
