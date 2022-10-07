#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional> // greater<int>() e less<int>()

#define lld long long int
#define MAX_BLOCO 1000002 // 10ˆ6

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

vector<lld> memoria(MAX_BLOCO);

// Atenção: valores deve ser um array nativo, não pode ser vector
lld min_quantidade_moedas(lld valores[], lld qtd_itens, lld troco)
{
    lld i, j, valor_moeda;

    // Aqui acontece uma otimização, é verificado
    // se é possível completar o valor que falta para o troco
    // apenas com a moeda atual
    if (troco % valores[qtd_itens - 1] == 0)
        return troco / valores[qtd_itens - 1];

    fill(memoria.begin(), memoria.end(), MAX_BLOCO);
    memoria[0] = 0;

    for (i = 0; i < qtd_itens; i++)
    {
        valor_moeda = valores[i];
        for (j = valor_moeda; j <= troco; j++)
        {
            memoria[j] = min(memoria[j], memoria[j - valor_moeda] + 1);
        }
    }

    return memoria[troco];
}

int main(int argc, char *argv[])
{
    lld num_instancias;

    cin >> num_instancias;

    for (lld i = 0; i < num_instancias; i++)
    {
        lld qtd_moedas, troco;
        cin >> qtd_moedas >> troco;

        lld valores[qtd_moedas];
        for (lld j = 0; j < qtd_moedas; j++)
            cin >> valores[j];

        // ordena os valores das moedas (ou blocos) em ordem crescente
        // MENORES moedas primeiro
        // ISSO É IMPORTANTE
        sort(valores, valores + qtd_moedas, less<lld>());

        cout << min_quantidade_moedas(valores, qtd_moedas, troco) << endl;
    }

    return 0;
}
