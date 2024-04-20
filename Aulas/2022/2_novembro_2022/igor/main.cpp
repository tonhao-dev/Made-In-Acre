#include <iostream>
#include <queue>  // Fila genérica em C++
#include <stack>  // Fila genérica em C++

using namespace std;

void inverteFila(std::stack<char>* p) {
    std::queue<char> f;

    while(!p->empty()) {
        cout << p->top();
        f.push(p->top());
        p->pop();
    }
}   

void invertePilha(std::stack<char>* p) {
    std::stack<char> p1; // primeira pilha auxiliar
    std::stack<char> p2; // segunda pilha auxiliar

    while(!p->empty()) {

        p1.push(p->top());
        p->pop();
    }
}

int main(int argc, char **argv) {
    std::stack<char> pilha;  

    pilha.push('A');
    pilha.push('B');
    pilha.push('C');
    pilha.push('D');

    inverteFila(&pilha);

    cout << "topo" << pilha.top();

    return 0;
}
