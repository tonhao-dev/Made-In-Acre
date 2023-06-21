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

class Carro {
   public:
    ll placa;
    ll comprimento;
    ll index_estacionado;
    Carro() {}

    Carro(ll placa, ll comprimento) {
        this->placa = placa;
        this->comprimento = comprimento;
        this->index_estacionado = -1;
    }
};

ll pegarIndexEstacionado(Carro &carro, vector<ll> &estado_estacionamento) {
    ll contagem = 0;
    for (ll i = 0; i < estado_estacionamento.size(); i++) {
        if (estado_estacionamento[i] != 0) {
            contagem = 0;
            continue;
        }

        contagem++;

        if (contagem == carro.comprimento) {
            return abs(i - (carro.comprimento - 1));
        }
    }

    return -1;
}

ll estacionar(Carro &carro, vector<ll> &estado_estacionamento) {
    auto index = pegarIndexEstacionado(carro, estado_estacionamento);
    carro.index_estacionado = index;

    if (index == -1)
        return 0;

    fill(estado_estacionamento.begin() + index, estado_estacionamento.begin() + index + carro.comprimento, carro.placa);

    return 10;
}

void desestacionar(Carro &carro, vector<ll> &estado_estacionamento) {
    ll index = carro.index_estacionado;
    if (index == -1)
        return;

    fill(estado_estacionamento.begin() + index, estado_estacionamento.begin() + index + carro.comprimento, 0);
}

int main() {
    speed;

    ll comprimento_estacionamento, qtd;
    while (cin >> comprimento_estacionamento >> qtd) {
        unordered_map<ll, Carro> carros;
        vector<ll> estado_estacionamento(comprimento_estacionamento, 0);

        ll faturamento = 0;

        for (int i = 0; i < qtd; i++) {
            char tipo;
            cin >> tipo;

            ll placa, comprimento;
            cin >> placa;

            if (tipo == 'C') {
                cin >> comprimento;

                Carro *carro = new Carro(placa, comprimento);
                faturamento += estacionar(*carro, estado_estacionamento);

                if (carro->index_estacionado != -1) {
                    carros[carro->placa] = *carro;
                }
            } else {
                desestacionar(carros[placa], estado_estacionamento);
            }
        }

        cout << faturamento << endl;
    }

    return 0;
}
