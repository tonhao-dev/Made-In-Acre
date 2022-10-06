#include <iostream>
#include <vector>

#define debug(message, x) cout << message << x << endl

using namespace std;

int main(int argc, char **argv)
{


  int casos, comandoEntrada, valorEntrada, contador = 0, maior = -1;
  string resultado;

  while(cin >> casos){
    if(casos == 2){
      cout << "impossible" << endl;
    }
    vector<int> comando(casos), valor(casos);
    for(int i=0; i<casos; i++){
      cin >> comandoEntrada >> valorEntrada;
      if(valorEntrada > maior) {
        maior = valorEntrada;
      }
      comando[i] = comandoEntrada;
      valor[i] = valorEntrada;
    }

    for(int i=0; i<casos; i++){
      if(comando[i] == 2){
        if(valor[i] == valor[i-1]){
          contador++;
          resultado = "stack";
        }
        if(valor[i] == valor[0]){
          contador++;
          resultado = "queue";
        }
        if(valor[i] == maior){
          contador++;
          resultado = "priority queue";
        }
        if(contador > 1){
          resultado = "not sure";
        } else if(contador == 0){
          resultado = "impossible";
        }
        continue;
      }
    }

    cout << resultado << endl;
  }

  return 0;
}

// stack
// o indice que sai é o ultimo que entrou

// queue

// o indice que sai e o primeiro que entrou

// priority queue

// o indice que sai é o maior de todos

// impossible

// nenhuma condicao

// not sure
// atendeu a mais de uma condicao
