#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    int num_testes;
    cin >> num_testes;

    for (int teste = 0; teste < num_testes; teste++) {
        int no_inicio, vertices, arestas;
        cin >> no_inicio >> vertices >> arestas;

        // Cria uma matriz de vertices X vertices tamanho
        vector<vector<bool>> desenho(vertices, vector<bool>(vertices));
        for (int i = 0; i < arestas; i++) {
            int origem, destino;
            cin >> origem >> destino;

            desenho[origem][destino] = true;
            desenho[destino][origem] = true;
        }

        int resposta = 0;
        for (auto linha : desenho)
            for (auto valor : linha)
                resposta += valor;

        cout << resposta << endl;
    }

    return 0;
}
