// https://atcoder.jp/contests/dp/tasks/dp_c
// Programação dinâmica, memorização com matrizes, DP

#include <climits>
#include <initializer_list>
#include <iostream>
#include <utility>
#include <vector>

#define NAO_CALCULADO -1

using namespace std;

enum Atividade { Nadar = 0,
                 Insetos,
                 Estudar };

vector<vector<int>> memo(100005, vector<int>(3, NAO_CALCULADO));

int maior_pontuacao(int dia, Atividade ultima_atividade, vector<vector<int>>& atividades) {
    if (ultima_atividade == Atividade::Nadar) return max(atividades[dia][Atividade::Estudar], atividades[dia][Atividade::Insetos]);
    if (ultima_atividade == Atividade::Insetos) return max(atividades[dia][Atividade::Nadar], atividades[dia][Atividade::Estudar]);
    return max(atividades[dia][Atividade::Nadar], atividades[dia][Atividade::Insetos]);
}

int pontuacao(int dia_atual, int dia_destino, Atividade ultima_atividade, vector<vector<int>>& atividades) {
    if (dia_atual == dia_destino)
        return maior_pontuacao(dia_destino, ultima_atividade, atividades);

    if (memo[dia_atual][ultima_atividade] != NAO_CALCULADO) return memo[dia_atual][ultima_atividade];

    if (ultima_atividade == Atividade::Nadar) {
        memo[dia_atual][ultima_atividade] = max(pontuacao(dia_atual + 1, dia_destino, Atividade::Insetos, atividades) + atividades[dia_atual][Atividade::Insetos], pontuacao(dia_atual + 1, dia_destino, Atividade::Estudar, atividades) + atividades[dia_atual][Atividade::Estudar]);
    } else if (ultima_atividade == Atividade::Insetos) {
        memo[dia_atual][ultima_atividade] = max(pontuacao(dia_atual + 1, dia_destino, Atividade::Nadar, atividades) + atividades[dia_atual][Atividade::Nadar], pontuacao(dia_atual + 1, dia_destino, Atividade::Estudar, atividades) + atividades[dia_atual][Atividade::Estudar]);
    } else {
        memo[dia_atual][ultima_atividade] = max(pontuacao(dia_atual + 1, dia_destino, Atividade::Nadar, atividades) + atividades[dia_atual][Atividade::Nadar], pontuacao(dia_atual + 1, dia_destino, Atividade::Insetos, atividades) + atividades[dia_atual][Atividade::Insetos]);
    }

    return memo[dia_atual][ultima_atividade];
}

int main() {
    int num_dias;
    cin >> num_dias;

    vector<vector<int>> atividades(100005);

    for (int i = 0; i < num_dias; i++) {
        for (int j = 0; j < 3; j++) {
            int pontuacao;
            cin >> pontuacao;

            atividades[i].push_back(pontuacao);
        }
    }

    cout << max({pontuacao(0, num_dias - 1, Atividade::Nadar, atividades),
                 pontuacao(0, num_dias - 1, Atividade::Insetos, atividades),
                 pontuacao(0, num_dias - 1, Atividade::Estudar, atividades)})
         << "\n";

    return 0;
}
