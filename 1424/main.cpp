#include <iostream>
#include <vector>
#include <map>
#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

int main(int argc, char **argv)
{
    int num_elementos, num_consultas, elemento;

    while (cin >> num_elementos >> num_consultas)
    {
        map<int, vector<int>> dicionario;

        for (int i = 1; i <= num_elementos; i++)
        {
            cin >> elemento;

            dicionario[elemento].push_back(i);
        }

        for (int i = 1; i <= num_consultas; i++)
        {
            int ocorrencia, num_procurado;
            cin >> ocorrencia >> num_procurado;

            if (dicionario[num_procurado].size() < ocorrencia)
            {
                cout << 0 << endl;
                continue;
            }
            cout << dicionario[num_procurado][ocorrencia - 1] << endl;
        }
    }

    return 0;
}
