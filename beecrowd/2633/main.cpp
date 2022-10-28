#include <iostream>
#include <vector>
#include <algorithm>

#define debug(message, x) cout << message << x << endl

using namespace std;

class Carne
{
public:
    int dias;
    string nome;
};

bool comparaCarne(Carne carne1, Carne carne2)
{
    return carne1.dias < carne2.dias;
}

int main(int argc, char **argv)
{
    int num_carnes = 0;

    while (cin >> num_carnes)
    {
        vector<Carne> carnes(num_carnes);
        for (int i = 0; i < num_carnes; i++)
        {
            cin >> carnes[i].nome >> carnes[i].dias;
        }

        sort(carnes.begin(), carnes.end(), comparaCarne);

        for (int i = 0; i < carnes.size() - 1; i++)
        {
            cout << carnes[i].nome << " ";
        }

        cout << carnes[carnes.size() - 1].nome << endl;
    }

    return 0;
}