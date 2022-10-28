#include <iostream>
#include <vector>

#define debug(message, x) cout << message << x << endl

using namespace std;

int main(int argc, char **argv)
{
  int casos, comandoEntrada, valorEntrada, maior = -1;
  string resultado;

  while(cin >> casos) {
    vector<int> comando(casos), valor(casos);
    for(int i=0; i<casos; i++){
      cin >> comandoEntrada >> valorEntrada;
      if(valorEntrada > maior) {
        maior = valorEntrada;
      }
      comando[i] = comandoEntrada;
      valor[i] = valorEntrada;
    }

    if(casos == 2){
      cout << "impossible" << endl;
      continue;
    }

    for(int i=0; i<casos; i++) {
      int contador = 0;
      if(comando[i] == 2) {
        cout << " maior = " << maior;
        if(valor[i] == valor[i-1]) {
          contador++;
          resultado = "stack";
        }
        if(valor[i] == valor[0]) {
          contador++;
          resultado = "queue";
        }
        if(valor[i] == maior) {
          contador++;
          resultado = "priority queue";
        }
        if(contador > 1) {
          resultado = "not sure";
        } else if(contador == 0) {
          resultado = "impossible";
        }
        break;
      }
    }

    comando.clear();
    valor.clear();
    cout << resultado << endl;
  }
  return 0;
}