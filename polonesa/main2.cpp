#include <bits/stdc++.h>

using namespace std;

char pop(queue q, char ultimo){
  for
}

int main()
{
    string entrada;
    char ultimo;
    cin >> entrada;

    queue<char> characteres;

    for(auto i: entrada){
      characteres.push(i);
      if(i == entrada[entrada.length()]){
        ultimo = i;
      }
    }
    return 0;
}


class Pilha2F{
public:
   std::queue<char> f1; // Fila para ‘char’
   std::queue<char> f2; // Fila para ‘char’

};
static_assert(PilhaTAD<Pilha2F, char>); // testa se Pilha está correta