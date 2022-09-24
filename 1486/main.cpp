#include <iostream>
#define debug(message, x) 

using namespace std;

int main() {
  int pontos_processamento, num_medicoes, tam_palito;

  cin >> pontos_processamento >> num_medicoes >> tam_palito;

  while(pontos_processamento != 0 && num_medicoes != 0 && tam_palito != 0) {
    int matriz[num_medicoes][pontos_processamento];
    int contador=0;
    int resultado=0;

    for(int i=0;i<num_medicoes;++i) {
      for(int j =0;j<pontos_processamento;++j) {
        cin >> matriz[i][j];
      }
    }

    for(int j=0; j<pontos_processamento; ++j) {
      for(int i=0;i<num_medicoes;++i) {
        debug("i", i);
        debug("j", j);
        debug("matriz[i][j]", matriz[i][j]);
        debug("contador", contador);

        if(matriz[i][j] == 1) {
          contador++;

          if(contador == tam_palito) {
            resultado++;
          }
        } else {
          contador = 0;
        }
      }

      contador = 0;
    }

    cout << resultado << endl;

    cin >> pontos_processamento >> num_medicoes >> tam_palito;
  }

  return 0;
}