/**
 * Cabo de Guerra
 * beecrowd | 1586
 * https://www.beecrowd.com.br/judge/pt/problems/view/1586
 * Busca binária, comparação entre strings
 */

#include <bits/stdc++.h>

using namespace std;

#define db(message, x) cout << message << ": " << x << endl
#define cv(vector)        \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl
#define cm(map)                             \
    for (auto e : map)                      \
        cout << e.first << " " << e.second; \
    cout << endl
#define rep(i, a, b) for (ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

ll pegaValorNome(string nome) {
    ll total = 0;
    for (auto n : nome) {
        total += (ll)n;
    }
    return total;
}

ll forcaTimeA(vector<string> &nomes, ll inicio, ll fim) {
    ll soma = 0, mult = fim;
    rep(i, inicio, fim) {
        soma += pegaValorNome(nomes[i]) * mult--;
    }

    return soma;
}

ll forcaTimeB(vector<string> &nomes, ll inicio, ll fim) {
    ll soma = 0, mult = 1;
    rep(i, inicio, fim) {
        soma += pegaValorNome(nomes[i]) * mult++;
    }

    return soma;
}

string buscaBinaria(vector<string> &nomes) {
    ll n = nomes.size();
    ll l = 0, r = n;
    while (l < r) {
        ll mid = (l + r) / 2;
        ll forcaA = forcaTimeA(nomes, 0, mid);
        ll forcaB = forcaTimeB(nomes, mid, n);
        ll diferenca = abs(forcaA - forcaB);

        if (diferenca == 0) {
            return nomes[mid - 1];
        }

        if (forcaA < forcaB) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    return "Impossibilidade de empate.";
}

int main(int argc, char **argv) {
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    while (cin >> n) {
        if (n == 0) break;

        vector<string> nomes(n);
        rep(i, 0, n) {
            cin >> nomes[i];
        }

        cout << buscaBinaria(nomes) << endl;
    }

    return 0;
}
