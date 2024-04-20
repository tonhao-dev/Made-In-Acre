#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void inverte_com_fila(std::stack<char>* p) {
    queue<char> f;  // somente essa fila e mais espaço auxiliar constante

    while (!p->empty()) {
        f.push(p->top());
        p->pop();
    }

    while (!f.empty()) {
        p->push(f.front());
        f.pop();
    }
}

void inverte_com_pilha(stack<char>* p) {
    stack<char> p1;  // primeira pilha auxiliar
    stack<char> p2;  // segunda pilha auxiliar
    // mais espaço auxiliar constante

    while (!p->empty()) {
        p1.push(p->top());
        p->pop();
    }

    while (!p1.empty()) {
        p2.push(p1.top());
        p1.pop();
    }

    while (!p2.empty()) {
        p->push(p2.top());
        p2.pop();
    }
}

int main(int argc, char** argv) {
    stack<char> pilha;

    pilha.push('A');
    pilha.push('B');
    pilha.push('C');
    pilha.push('D');

    cout << "topo: " << pilha.top() << endl;

    inverte_com_fila(&pilha);

    cout << "topo: " << pilha.top() << endl;

    inverte_com_pilha(&pilha);

    cout << "topo: " << pilha.top() << endl;

    while (!pilha.empty()) {
        cout << pilha.top() << endl;
        pilha.pop();
    }

    cout << endl;
}
