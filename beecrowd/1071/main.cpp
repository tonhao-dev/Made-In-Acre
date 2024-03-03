#include <iostream>
#include <string>

using namespace std;

int main() {
    int x, y, soma = 0;
    cin >> x >> y;
    int maior = x > y ? x : y;
    int menor = x + y - maior;
    int aux = menor % 2 == 0 ? menor + 1 : menor + 2;
    for (int i = aux; i < maior; i += 2) soma += i;
    cout << soma << endl;
    return 0;
}
