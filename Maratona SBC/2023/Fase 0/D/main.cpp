#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long int numero;
    cin >> numero;

    vector<long long int> passos;
    passos.push_back(numero);

    while (to_string(numero).length() > 1)
    {
        long long int ultimoDigito = numero % 10;
        numero = (numero / 10) * 3 + ultimoDigito;
        passos.push_back(numero);
    }

    for (long long int passo : passos)
    {
        cout << passo << endl;
    }

    return 0;
}
