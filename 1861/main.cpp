#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Assassino
{
public:
    string nome;
    int num_mortes = 0;
    bool isVivo = true;
};

int main(int argc, char **argv)
{
    map<string, int> assassinos;
    map<string, bool> mortos;
    string nome_assassino, nome_morto;

    while (cin >> nome_assassino >> nome_morto)
    {
        assassinos[nome_assassino]++;
        mortos[nome_morto] = true;
    }

    cout << "HALL OF MURDERERS" << endl;

    for (auto ass : assassinos)
    {
        if (mortos[ass.first] == true)
            continue;
        cout << ass.first << " " << ass.second << endl;
    }

    return 0;
}