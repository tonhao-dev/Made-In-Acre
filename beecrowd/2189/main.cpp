#include <iostream>

using namespace std;

int main() {
    int num_participantes, num_teste = 1;

    while (cin >> num_participantes, num_participantes) {
        int participante, vencedor;
        for (int i = 1; i <= num_participantes; ++i) {
            cin >> participante;

            if (participante == i)
                vencedor = i;
        }

        cout << "Teste " << num_teste << endl;
        cout << vencedor << endl;

        cout << endl;

        num_teste++;
    }

    return 0;
}
