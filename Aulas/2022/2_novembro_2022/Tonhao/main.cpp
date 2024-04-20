#include <iostream>
#include <queue>  // Fila genérica em C++

using namespace std;

class Pilha2F {
   private:
    std::queue<char> f1;  // Fila para ‘char’
    std::queue<char> f2;  // Fila para ‘char’
                          // SOMENTE espaço auxiliar CONSTANTE aqui (nenhum vetor, lista, etc)
                          // implementar métodos do TAD Pilha

   public:
    char top() {
        return f1.back();
    }

    void push(char character) {
        f1.push(character);
    }

    void pop() {
        while (f1.size() > 1) {
            f2.push(f1.front());
            f1.pop();
        }

        if (!f1.empty()) f1.pop();

        while (!f2.empty()) {
            f1.push(f2.front());
            f2.pop();
        }
    }
};

int main(int argc, char **argv) {
    Pilha2F pilha;

    pilha.pop();

    pilha.push('A');
    pilha.push('B');
    pilha.push('C');
    pilha.push('D');

    cout << "Pilha topo: " << pilha.top() << "\n";

    pilha.pop();
    pilha.pop();

    cout << "Pilha topo: " << pilha.top() << "\n";

    pilha.pop();

    cout << "Pilha topo: " << pilha.top() << "\n";

    pilha.push('E');
    pilha.push('F');

    cout << "Pilha topo: " << pilha.top() << "\n";

    return 0;
}
