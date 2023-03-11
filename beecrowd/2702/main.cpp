#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int frango_disponivel, bife_disponivel, massa_disponivel;
    int frango_pedido, bife_pedido, massa_pedido;

    cin >> frango_disponivel >> bife_disponivel >> massa_disponivel;
    cin >> frango_pedido >> bife_pedido >> massa_pedido;

    int resposta = 0;

    resposta += frango_disponivel > frango_pedido ? 0 : frango_pedido - frango_disponivel;
    resposta += bife_disponivel > bife_pedido ? 0 : bife_pedido - bife_disponivel;
    resposta += massa_disponivel > massa_pedido ? 0 : massa_pedido - massa_disponivel;

    cout << resposta << endl;

    return 0;
}
