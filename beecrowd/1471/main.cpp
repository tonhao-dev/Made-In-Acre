/**
 * 1471 - Mergulho
 * Adhoc, simulação
 */

#include <iostream>

using namespace std;

int main(){
    int n, r;
    int sobrevivente;
    // a questão diz que é 10 à quarta
    int todos[10000];

    while(cin >> n >> r) {


        // verificar se são iguais
        if (n == r) {
            for (int i = 0; i < r; i++) {
                cin >> sobrevivente;
            }
            cout << "*" << endl;
        }

        else {
            // setar tudo que vai ser utlizado com 0
            for (int i = 0; i < n; i++) {
                todos[i] = 0;
            }

            // adicionar 1 na posição dos que estao vivos
            for (int i = 0; i < r; i++) {
                cin >> sobrevivente;
                todos[sobrevivente-1]++;
            }

            for (int i = 0; i < n; i++) {
                // se for 0 mostra a posição + 1 pois estou utilizando 0 no for,
                // pois a numeração dos vonlutários começa em 1
                if (todos[i] == 0) {
                    cout << i+1 << ' ';
                }
            }
            cout << endl;
        }
    }

    return 0;
}
