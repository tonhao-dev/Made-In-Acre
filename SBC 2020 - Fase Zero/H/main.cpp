#include <iostream>
#include <vector>
#define debug(message, x) cout << message << x << endl;

using namespace std;

int main(int argc, char **argv)
{
    int num_testes;
    cin >> num_testes;

    vector<unsigned long long int> entrada(num_testes);
    unsigned long long int maior_qtd_cartas = -1;

    for (int i = 0; i < num_testes; i++)
    {
        cin >> entrada[i];

        debug("[i]", i);
        debug("entrada[i]", entrada[i]);

        if (entrada[i] > maior_qtd_cartas)
            maior_qtd_cartas = entrada[i];
    }

    unsigned long long int p_entrada = 0;

    vector<unsigned long long int> qtd_cartas_nivel(maior_qtd_cartas);
    unsigned long long int p_qtd_cartas_nivel = 1;

    while (entrada[p_entrada] != maior_qtd_cartas)
    {
        debug("p_entrada: ", p_entrada);
        debug("p_qtd_cartas_nivel: ", p_qtd_cartas_nivel);
        debug("entrada[p_entrada]: ", entrada[p_entrada]);

        if (p_qtd_cartas_nivel == entrada[p_entrada])
        {
            cout << "\n\nSaida: " << qtd_cartas_nivel[p_entrada] << endl;
            p_entrada++;
        }

        qtd_cartas_nivel[p_qtd_cartas_nivel] = qtd_cartas_nivel[p_qtd_cartas_nivel - 1] + p_qtd_cartas_nivel * 2 + p_qtd_cartas_nivel - 1;
        p_qtd_cartas_nivel++;
    }

    return 0;
}
