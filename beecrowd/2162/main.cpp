#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    int num_medidas;
    cin >> num_medidas;

    vector<int> medidas(num_medidas);
    for (int i = 0; i < num_medidas; i++) cin >> medidas[i];

    // Se existe apenas 1 medida, a resposta é sempre 1
    if (num_medidas == 1) {
        cout << 1 << endl;
        // return 0 faz com que o programa já seja encerrado
        return 0;
    }

    // Se existem 2 medidas a resposta depende da igualdade entre as medidas
    if (num_medidas == 2) {
        cout << (int)(medidas[0] != medidas[1]) << endl;
        return 0;
    }

    // 100 [99 112 -8] -7
    // Nesse exemplo queremos olhar apenas para as medidas destacadas
    // Para cada medida, ela deve ser maior que o anterior e o proximo
    // Ou menor que o anterior e o proximo, se isso NÃO acontecer a qualquer momento
    // Então a resposta é 0
    int resposta = 1;
    for (int i = 1; i < num_medidas - 1; i++) {
        // Pico
        if (medidas[i - 1] < medidas[i] && medidas[i] > medidas[i + 1]) continue;

        // Vale
        if (medidas[i - 1] > medidas[i] && medidas[i] < medidas[i + 1]) continue;

        // Se não é pico nem vale então quebra o padrão
        resposta = 0;
        break;
    }

    cout << resposta << endl;
}
