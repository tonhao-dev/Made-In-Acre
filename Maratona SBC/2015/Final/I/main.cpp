#include <iostream>
#include <vector>

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

int main(int argc, char **argv) {
    int respostaCorreta, respostaAtual, resp = 0;
    cin >> respostaCorreta;

    for (int i = 0; i < 5; i++) {
        cin >> respostaAtual;
        resp += respostaAtual == respostaCorreta;
    }

    cout << resp << "\n";

    return 0;
}
