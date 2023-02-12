#include <iostream>
#include <vector>

using namespace std;

int maior(int a, int b) {
    return a > b ? a : b;
}

int main(int argc, char **argv) {
    int carta1, carta2;
    cin >> carta1 >> carta2;

    cout << maior(carta1, carta2) << endl;

    return 0;
}
