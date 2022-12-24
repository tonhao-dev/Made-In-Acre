#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

int main() {
    int num_revistas, num_linhas;
    string linha;
    string mensagem = "merrychristmas";

    cin >> num_revistas;

    for (int i = 0; i < num_revistas; ++i) {
        cin >> num_linhas;
        getchar();  // para ler o \n e ele não ser pego no getline

        vector<int> letras(26);

        for (int j = 0; j < num_linhas; ++j) {
            getline(cin, linha);

            for (auto letra : linha) {
                if (!isalpha(letra)) continue;
                letras[tolower(letra) - 'a']++;
            }
        }

        int qtd_mensagens = INT_MAX / 2;
        for (int j = 0; j < mensagem.size(); j++) {
            qtd_mensagens = min(letras[mensagem[j] - 'a'], qtd_mensagens);
        }

        cout << qtd_mensagens << "\n";
    }

    return 0;
}
