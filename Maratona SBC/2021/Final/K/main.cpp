// Problem K – KIARA is a Recursive Acronym
// https://codeforces.com/blog/entry/101550
#include <iostream>
#include <vector>

#define MAX_ALFABETO 26
#define MAX_PALAVRAS 1000005

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

int main(int argc, char **argv) {
    int num_palavras;
    cin >> num_palavras;

    vector<bool> tem_letra(MAX_ALFABETO);
    vector<string> palavras(MAX_PALAVRAS);

    for (int i = 0; i < num_palavras; ++i) {
        cin >> palavras[i];
        tem_letra[palavras[i][0] - 'A'] = true;
    }

    for (int i = 0; i < num_palavras; ++i) {
        bool achou = true;

        for (auto letra : palavras[i]) {
            if (!tem_letra[letra - 'A']) {
                achou = false;

                break;
            }
        }

        if (achou) {
            cout << "Y" << endl;
            return 0;
        }
    }

    cout << "N" << endl;

    return 0;
}
