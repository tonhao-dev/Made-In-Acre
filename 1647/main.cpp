// https://www.beecrowd.com.br/judge/pt/problems/view/1467
// ad-hoc
#include <iostream>
#include <vector>

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl
#define ulld unsigned long long int

using namespace std;

int main(int argc, char **argv)
{
    int num_bacias;
    while (true)
    {
        cin >> num_bacias;

        if (num_bacias == 0)
            break;

        vector<ulld> bacias(num_bacias);
        for (int i = 0; i < num_bacias; i++)
            cin >> bacias[i];

        ulld soma_agregada = 0;

        for (int i = bacias.size() - 1; i >= 0; i--)
        {
            bacias[i] += soma_agregada;
            soma_agregada += bacias[i];
        }

        cout << soma_agregada << endl;
    }

    return 0;
}
