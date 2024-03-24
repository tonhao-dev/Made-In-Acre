#include <math.h>

#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    double raio = 0;
    double volume = 0;
    double pi = 3.14159;

    cin >> raio;

    volume = 4.0 / 3.0 * (pi * pow(raio, 3));

    cout << fixed << setprecision(3);
    cout << "VOLUME = " << volume << endl;

    return 0;
}
