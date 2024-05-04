#include <bits/stdc++.h>

using namespace std;

int main() {
    string a = "impossivel";
    string b = "ssivelimpo";

    bool ehAnagrama = true;
    vector<int> contagem1(26);
    vector<int> contagem2(26);
    for (auto caracter : a) {
        // i -> 105
        // a -> 97
        // 105-97 -> 8, i é a 9° letra do alfabeto, posicao 8 no vetor
        contagem1[caracter - 'a']++;
    }
    for (int i = 0; i < contagem2.size(); i++) {
        contagem2[b[i] - 'a']++;
    }

    for (int i = 0; i < contagem1.size(); i++) {
        if (contagem1[i] != contagem2[i]) {
            ehAnagrama = false;
            break;
        }
    }

    cout << (ehAnagrama ? "Eh anagrama" : "Nao eh anagrama") << endl;

    return 0;
}
