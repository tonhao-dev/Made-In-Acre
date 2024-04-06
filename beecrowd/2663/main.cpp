/**
 * 2663 - Fase
 * Adhoc
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_competidores, num_vagas;

    cin >> num_competidores;
    cin >> num_vagas;

    vector<int> pontuacoes(num_competidores);

    for (int i = 0; i < num_competidores; i++) {
        cin >> pontuacoes[i];
    }

    sort(pontuacoes.begin(), pontuacoes.end(), greater<int>());  // do maior para o menor

    int num_classificados = num_vagas - 1;
    int ultima_pontuacao = pontuacoes[num_vagas - 1];
    int i = num_vagas - 1;

    while (i < num_competidores && pontuacoes[i] == ultima_pontuacao) {
        num_classificados++;
        i++;
    }

    cout << num_classificados << endl;

    return 0;
}
