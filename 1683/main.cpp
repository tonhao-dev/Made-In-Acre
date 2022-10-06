// https://www.beecrowd.com.br/judge/pt/problems/view/1683
// pesquisa linear usando pilha

#include <iostream>
#include <vector>
#include <algorithm>

#define debug(message, x) cout << message << x << endl;

using namespace std;

long long int area_retangulo(vector<long long int> retangulos, long long int pos_barra_referencia)
{
    long long int pos_menor_retangulo_esquerda = max(pos_barra_referencia - 1, (long long int)0);
    long long int pos_menor_retangulo_direita = min(pos_barra_referencia + 1, (long long int)retangulos.size() - 1);

    while (pos_menor_retangulo_esquerda > 0 && retangulos[pos_menor_retangulo_esquerda] >= retangulos[pos_barra_referencia])
    {

        pos_menor_retangulo_esquerda--;
    }

    if (retangulos[pos_menor_retangulo_esquerda] < retangulos[pos_barra_referencia])
        pos_menor_retangulo_esquerda++;

    while (pos_menor_retangulo_direita < retangulos.size() && retangulos[pos_menor_retangulo_direita] >= retangulos[pos_barra_referencia])
    {

        pos_menor_retangulo_direita++;
    }

    if (retangulos[pos_menor_retangulo_direita] < retangulos[pos_barra_referencia])
        pos_menor_retangulo_direita--;

    return (long long int)(pos_menor_retangulo_direita - pos_menor_retangulo_esquerda + 1) * retangulos[pos_barra_referencia];
}

int main(int argc, char **argv)
{
    int num_retangulos = -1;

    while (cin >> num_retangulos)
    {
        if (num_retangulos == 0)
            break;

        vector<long long int> retangulos(num_retangulos);

        for (int i = 0; i < num_retangulos; i++)
        {
            cin >> retangulos[i];
        }

        long long int maior_area = 0;
        for (int i = 0; i < num_retangulos; i++)
        {

            maior_area = max(area_retangulo(retangulos, i), maior_area);
        }

        cout << maior_area << endl;
    }

    return 0;
}
