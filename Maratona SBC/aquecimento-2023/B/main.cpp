#include <iostream>
using namespace std;

int main() {
    long long int A, B, C;
    cin >> A >> B >> C;

    char tipoDesejado;
    cin >> tipoDesejado;

    long long int maximo = 0;
    if (tipoDesejado == 'A') {
        maximo+= C/2*5;
        C = C%2;
        maximo+= B/2*3;
        B = B%2;
        maximo+=A;
    } else if (tipoDesejado == 'B') {
       maximo += A/2*3;
    } else if (tipoDesejado == 'C') {
        maximo+= C/5*2;
        C = C%5;
        maximo+= B/3*2;
        B = B%3;
        maximo+=A;
    }

    cout << maximo << endl;

    return 0;
}
