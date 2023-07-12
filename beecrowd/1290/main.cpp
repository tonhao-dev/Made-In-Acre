/**
 * Caixas Muito Especiais
 * beecrowd | 1290
 * https://www.beecrowd.com.br/judge/pt/problems/view/1290
 * Ad Hoc, 3D, vector, sort, class
 */

#include <bits/stdc++.h>

#define speed                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define lll long long int
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second

class Caixa {
   public:
    ll volume;
    ll largura;
    ll altura;
    ll comprimento;
    Caixa(){};

    Caixa(ll larg, ll alt, ll comp) {
        largura = larg;
        altura = alt;
        comprimento = comp;
        volume = larg * alt * comp;
    }

    bool operator<(Caixa &caixa) {
        return volume < caixa.volume;
    }
};

bool verificar(Caixa &caixa1, ll &largura, ll &altura, ll &comprimento) {
    return (caixa1.largura >= largura && caixa1.altura >= altura && caixa1.comprimento >= comprimento);
}

bool encaixa(Caixa &caixa1, Caixa &caixa2) {
    if (caixa1.volume < caixa2.volume) {
        return false;
    }

    if (verificar(caixa1, caixa2.largura, caixa2.altura, caixa2.comprimento)) {
        return true;
    }
    if (verificar(caixa1, caixa2.largura, caixa2.comprimento, caixa2.altura)) {
        return true;
    }
    if (verificar(caixa1, caixa2.comprimento, caixa2.altura, caixa2.largura)) {
        return true;
    }
    if (verificar(caixa1, caixa2.comprimento, caixa2.largura, caixa2.altura)) {
        return true;
    }
    if (verificar(caixa1, caixa2.altura, caixa2.comprimento, caixa2.largura)) {
        return true;
    }
    if (verificar(caixa1, caixa2.altura, caixa2.largura, caixa2.comprimento)) {
        return true;
    }

    return false;
}

int main() {
    speed;
    ll n_itens, qtd;
    ll x, y, z;

    while (true) {
        cin >> n_itens >> qtd;
        if (n_itens == 0 && qtd == 0) {
            break;
        }

        cin >> x >> y >> z;

        Caixa *item = new Caixa(x, y, z);

        map<vector<ll>, ll> caixas;

        for (int i = 0; i < qtd; i++) {
            cin >> x >> y >> z;
            vector<ll> dimensoes = {x, y, z};
            sort(dimensoes.begin(), dimensoes.end());

            caixas[dimensoes]++;
        }

        ll ans = -1;
        for (auto caixa : caixas) {
            if (caixa.s < n_itens)
                continue;

            Caixa *c = new Caixa(caixa.f[0], caixa.f[1], caixa.f[2]);

            if (encaixa(*c, *item)) {
                if (ans == -1) {
                    ans = c->volume - item->volume;
                } else {
                    ans = min(c->volume - item->volume, ans);
                }
            }
        }

        if (ans == -1)
            cout << "impossible" << endl;
        else
            cout << ans << endl;
    }

    return 0;
}
