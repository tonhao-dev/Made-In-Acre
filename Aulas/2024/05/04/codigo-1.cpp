#include <bits/stdc++.h>

using namespace std;

// int, double, float, string, char, bool
// nome da função
// parâmetros: o que a função espera receber do mundo exterior
void somar(int num1, int num2, int& result) {
    result = num1 + num2;
}

int soma(int a, int b) {
    return a + b;
}

int main() {
    int a = 5;
    int b = 5;
    int resp = 0;

    somar(a, b, resp);

    cout << resp << endl;

    return 0;
}
