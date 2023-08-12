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

class Compare {
   public:
    bool operator()(pll p1, pll p2) {
        if (p1.s > p2.s) return true;
        return false;
    }
};

int main(int argc, char** argv) {
    SPEED;

    ll habitantes;
    while (cin >> habitantes) {
        if (habitantes == 0) break;

        priority_queue<pll, vector<pll>, Compare> vendedores;
        priority_queue<pll, vector<pll>, Compare> compradores;
        rep(i, habitantes) {
            ll habitante;
            read(habitante);

            if (habitante < 0) {
                vendedores.push(make_pair(abs(habitante), i));
            } else {
                compradores.push(make_pair(habitante, i));
            }
        };

        ll work = 0;
        while (!compradores.empty()) {
            pll comprador = compradores.top();
            pll vendedor = vendedores.top();

            // db_pair(comprador);
            // db_pair(vendedor);
            // db(min(abs(vendedor.f), comprador.f));
            // db(abs(comprador.s - vendedor.s));
            work += min(vendedor.f, comprador.f) * abs(comprador.s - vendedor.s);
            // db(work);

            if (comprador.f == vendedor.f) {
                compradores.pop();
                vendedores.pop();
            } else if (comprador.f > vendedor.f) {
                compradores.pop();
                vendedores.pop();

                compradores.push(make_pair(comprador.f - vendedor.f, comprador.s));
            } else if (vendedor.f > comprador.f) {
                compradores.pop();
                vendedores.pop();

                vendedores.push(make_pair(vendedor.f - comprador.f, vendedor.s));
            }
        }

        log(work);
    }

    return 0;
}
