#include <iostream>

using namespace std;

int main()
{
    int n, carlos, outros;
    bool perdeu = false;

    // leitura da quantidade dos candidatos
    cin >> n;
    // como carlos é sempre o primeiro já faço a leitura do valor do carlos
    cin >> carlos;


    // começa o laço decrementando -1 pois já leu o de carlos
    while (--n) {
        cin >> outros;
        if(outros > carlos) {
            perdeu = true;
        }
    }

    // faço a condição no ternário
    cout << (perdeu ? "N" : "S") << endl;

    return 0;
}