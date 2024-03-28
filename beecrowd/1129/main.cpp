#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num_leituras;

    while (cin >> num_leituras, num_leituras) {
        for (int i = 0; i < num_leituras; ++i) {
            vector<int> respostas(5);
            int quantidade_marcadas = 0;
            char answer;

            cin >> respostas[0] >> respostas[1] >> respostas[2] >> respostas[3] >> respostas[4];

            for (int j = 0; j < 5; ++j) {
                if (respostas[j] <= 127) {
                    quantidade_marcadas++;
                    // 0 -> A
                    // 1 -> B
                    // 2 -> C
                    // 3 -> D
                    // 4 -> E
                    answer = j + 'A';
                }
            }

            if (quantidade_marcadas != 1) {
                cout << "*" << endl;
            } else {
                cout << answer << endl;
            }
        }
    }

    return 0;
}
