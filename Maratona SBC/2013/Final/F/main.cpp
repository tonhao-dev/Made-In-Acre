#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

int main(int argc, char **argv) {
    int numPartidas, numGolsComprar;

    while (cin >> numPartidas >> numGolsComprar) {
        int resp = 0;

        vector<int> saldos;

        for (int i = 0; i < numPartidas; i++) {
            int s, r;
            cin >> s >> r;

            if (s > r) {
                resp += 3;
                continue;
            }

            saldos.push_back(r - s);
        }

        sort(saldos.begin(), saldos.end());

        int partidaAtual = 0;
        while (numGolsComprar > 0 && partidaAtual < saldos.size()) {
            if (numGolsComprar < saldos[partidaAtual]) break;
            if (numGolsComprar == saldos[partidaAtual]) {
                resp += 1;
                partidaAtual++;
                break;
            }

            numGolsComprar -= saldos[partidaAtual] + 1;
            resp += 3;

            partidaAtual++;
        }

        for (int i = partidaAtual; i < saldos.size(); i++) {
            if (saldos[i] > 0) continue;
            resp++;
        }

        cout << resp << "\n";
    }

    return 0;
}
