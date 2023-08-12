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

int main(int argc, char** argv) {
    SPEED;

    ll N;
    read(N);

    map<ll, string> valor_acao;
    map<string, ll> acao_valor;

    rep(query, N) {
        ll tipo;
        read(tipo);
        cin.ignore();

        string nome;
        ll valor;
        if (tipo == 1) {
            read(nome, valor);
            valor_acao[valor] = nome;
            acao_valor[nome] = valor;
            continue;
        }

        // 1 XDC 54
        // 2 XDC 10
        // acao_valor[XDC] = 54
        // valor_acao[54] = XDC
        // valor_acao[acao_valor[XDC]] = XDC
        // valor_acao[10] = XDC
        if (tipo == 2) {
            read(nome, valor);
            valor_acao.erase(valor_acao.find(acao_valor[nome]));
            acao_valor[nome] = valor;
            valor_acao[valor] = nome;
            continue;
        }

        if (tipo == 3) {
            string buy;
            read(buy);

            cout << valor_acao.begin()->second << " " << query + 1 << endl;
            valor_acao.erase(valor_acao.begin());
            acao_valor[nome] = LLONG_MAX / 2;
        }
    }

    return 0;
}
