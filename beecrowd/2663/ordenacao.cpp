#include <algorithm>  // sort
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numeros = {5, 7, 2, 1, 10};

    for (int i = 0; i < numeros.size(); i++) {
        cout << i << ": " << numeros[i] << endl;
    }

    // sort(numeros.begin(), numeros.end());                  // do menor para o maior
    // sort(numeros.begin(), numeros.end(), greater<int>());  // maior para o menor

    cout << endl;

    for (int i = 0; i < numeros.size(); i++) {
        cout << i << ": " << numeros[i] << endl;
    }

    return 0;
}
