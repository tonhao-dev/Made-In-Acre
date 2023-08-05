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

bool ehPossivel(vll& pipocas, ll count_competidores, ll velocidade_comer, ll tempo) {
    bool resp = true;
    ll num_competidores_necessarios = 1;
    ll capacidade_comer = velocidade_comer * tempo;
    ll capacidade_atual = capacidade_comer;

    foreach (pipoca, pipocas) {
        if (capacidade_atual >= pipoca) {
            capacidade_atual -= pipoca;
        } else if (capacidade_comer >= pipoca) {
            num_competidores_necessarios++;
            capacidade_atual = capacidade_comer - pipoca;
        } else {
            resp = false;
            break;
        }

        if (num_competidores_necessarios > count_competidores) {
            resp = false;
            break;
        }
    }

    return resp;
}

ll binary_search(vll& pipocas, ll count_competidores, ll velocidade_comer) {
    ll esquerda = 1, direita = 1e10 + 10;
    ll resp;

    while (esquerda < direita) {
        ll meio = (esquerda + direita) / 2;

        if (ehPossivel(pipocas, count_competidores, velocidade_comer, meio)) {
            resp = meio;
            direita = meio;
        } else {
            esquerda = meio + 1;
        }
    }

    return resp;
}

int main() {
    SPEED;

    ll n, c, t;
    read(n, c, t);

    vll pipocas(n);
    rep(i, n) read(pipocas[i]);

    log(binary_search(pipocas, c, t));

    return 0;
}
