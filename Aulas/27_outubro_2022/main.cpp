#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    queue<char> fila;
    stack<char> pilha;

    string expressao;
    cin >> expressao;

    for (auto caracter : expressao) {
        if (caracter == '(')
            pilha.push(caracter);

        if (isalpha(caracter))
            fila.push(caracter);

        if (caracter == '+' || caracter == '-' || caracter == '/' || caracter == '*')
            pilha.push(caracter);

        if (caracter == ')') {
            while (fila.size() > 0) {
                cout << fila.front();
                fila.pop();
            }

            while (pilha.top() != '(') {
                cout << pilha.top();
                pilha.pop();
            }

            pilha.pop();
        }
    }

    while (pilha.size() > 0) {
        if (pilha.top() != '(')
            cout << pilha.top();

        pilha.pop();
    }

    cout << endl;

    return 0;
}
