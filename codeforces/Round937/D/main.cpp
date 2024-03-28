/**
 * https://codeforces.com/contest/1950/problem/A
 * Ad hoc
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG true
#define db(x) \
    if (DEBUG) cout << #x << ": " << x << endl
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

vector<ll> onzes = {10, 11, 100, 101, 110, 111, 1000, 1001, 1011, 1101, 1100, 1110, 1111};

bool verifica(ll produtoAtual, ll alvo) {
    if (produtoAtual > alvo) return false;
    if (produtoAtual == alvo) return true;

    bool resp = false;
    for (auto prod : onzes) {
        resp = resp || verifica(prod * produtoAtual, alvo);
    }

    return resp;
}

int main(int argc, char** argv) {
    SPEED;

    ll test_cases;
    read(test_cases);

    rep(test_case, test_cases) {
        string entrada;
        read(entrada);

        bool ehBinario = true;
        for (auto character : entrada) {
            if (character != '1' && character != '0') {
                ehBinario = false;
                break;
            }
        }

        if (ehBinario) {
            cout << "YES" << endl;
        } else {
            ll alvo = stoll(entrada);
            cout << (verifica(1, alvo) ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
