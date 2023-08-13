/**
 * https://www.beecrowd.com.br/judge/pt/problems/view/1310
 * Kanade, soma maxima, Subsequência Máxima Contígua
 */

#include <algorithm>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

tuple<int, int, int> kadane(vector<int> &array, int custo_dia) {
    int max_so_far = -2147483647, max_ending_here = 0,
        start = 0, end = 0, s = 0;

    for (int i = 0; i < array.size(); i++) {
        max_ending_here += array[i] - custo_dia;

        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
            s = i + 1;
        }
    }

    return make_tuple(max_so_far, start, end);
}

int main(int argc, char *argv[]) {
    int num_dias, custo_circo;

    while (cin >> num_dias) {
        cin >> custo_circo;

        vector<int> custo_dia(num_dias);

        for (int i = 0; i < num_dias; i++) {
            cin >> custo_dia[i];
        }

        int lucro_total, dia_inicio, dia_fim;
        tie(lucro_total, dia_inicio, dia_fim) = kadane(custo_dia, custo_circo);

        cout << max(lucro_total, 0) << endl;
    }

    return 0;
}
