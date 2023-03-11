#include <iostream>
#include <vector>

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

int main(int argc, char **argv) {
    int numViewPoints, maxMeters;
    cin >> numViewPoints >> maxMeters;

    vector<int> altitudeViewPoints(numViewPoints);

    for (int i = 0; i < numViewPoints; i++) {
        cin >> altitudeViewPoints[i];
    }

    int sequencia = 1, maiorSequencia = 1;
    for (int i = 0; i < numViewPoints - 1; i++) {
        (altitudeViewPoints[i + 1] - altitudeViewPoints[i] <= maxMeters)
            ? sequencia++
            : sequencia = 1;

        if (maiorSequencia < sequencia) maiorSequencia = sequencia;
    }

    cout << maiorSequencia << "\n";
    return 0;
}
