#include <iostream>
#include <stack>  // Pilha genérica em C++

using namespace std;

class Fila2P {
   private:
    stack<char> p1;  // Pilha para ‘char’
    stack<char> p2;  // Pilha para ‘char’
    // SOMENTE espaço auxiliar CONSTANTE aqui (nenhum vetor, lista, etc)
    // implementar métodos do TAD Fila
    char front_fila;

   public:
    char front() {
        return front_fila;
    }

    char back() {
        if (p1.empty()) return ' ';
        return p1.top();
    }

    void pop() {
        while (p1.size() > 1) {
            p2.push(p1.top());
            p1.pop();
        }

        if (!p1.empty()) p1.pop();

        if (!p2.empty())
            front_fila = p2.top();
        else
            front_fila = ' ';

        while (!p2.empty()) {
            p1.push(p2.top());
            p2.pop();
        }
    }

    void push(char character) {
        if (p1.empty()) front_fila = character;
        p1.push(character);
    }
};

int main(int argc, char **argv) {
    Fila2P fila;

    fila.front();
    fila.back();
    fila.pop();

    fila.push('A');
    fila.push('B');
    fila.push('C');
    fila.push('D');

    cout << "Front da fila:" << fila.front() << endl;
    cout << "Back da fila:" << fila.back() << endl;

    fila.pop();

    cout << "Front da fila:" << fila.front() << endl;
    cout << "Back da fila:" << fila.back() << endl;

    fila.pop();

    cout << "Front da fila:" << fila.front() << endl;
    cout << "Back da fila:" << fila.back() << endl;

    fila.pop();

    cout << "Front da fila:" << fila.front() << endl;
    cout << "Back da fila:" << fila.back() << endl;

    fila.pop();

    cout << "Front da fila:" << fila.front() << endl;
    cout << "Back da fila:" << fila.back() << endl;

    fila.push('H');
    fila.push('I');
    fila.push('J');

    cout << "Front da fila:" << fila.front() << endl;
    cout << "Back da fila:" << fila.back() << endl;

    return 0;
}
