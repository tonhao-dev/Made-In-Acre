// 1407 - LOTERIA DE FIM DE SEMANA | RESOLVIDO EM C++

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N = 1;
    int C = 1;
    int K = 1;
    int i = 0;
    int j = 0;
    int menor = 0;

    while (cin >> N >> C >> K, N) {
        vector<int> X(C);
        vector<int> A(K + 1);
        vector<int> RESP;

        menor = INT_MAX;

        for (i = 0; i < N; i++) {
            for (j = 0; j < C; j++) {
                cin >> X[j];
                A[X[j]] = A[X[j]] + 1;
            }
        }

        for (j = 1; j < A.size(); j++) {
            if (A[j] < menor) {
                menor = A[j];
                RESP.clear();
                RESP.push_back(j);
            } else if (A[j] == menor) {
                RESP.push_back(j);
            }
        }

        for (j = 0; j < RESP.size(); j++) {
            if (j == RESP.size() - 1) {
                cout << RESP[j] << endl;
            } else {
                cout << RESP[j] << " ";
            }
        }
    }

    return 0;
}
