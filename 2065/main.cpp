// https://www.beecrowd.com.br/judge/pt/problems/view/2065
// fila de prioridade
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <queue>
#include <algorithm>

#define debug(message, x) cout << message << x << endl

using namespace std;

int main(int argc, char **argv)
{
  int qtdCaixas, qtdClientes, entrada;

  cin >> qtdCaixas >> qtdClientes;
  vector<int> tempoCaixa(qtdCaixas);
  priority_queue<pair<int, int>> caixas; // [x*z: 1, x*z: 2, x*z: 3]

  for(int i = 1; i <= qtdCaixas; i++){
    cin >> entrada;
    caixas.push(make_pair(0, -i)); /// [0: -1, 0: -2, 0: -3]
    tempoCaixa[i] = entrada;
  }

  int resposta = 0;
  for(int i=1; i<=qtdClientes; i++){
    cin >> entrada;
    int id = caixas.top().second * -1;
    int tempoQueVaiFicarLivre = entrada * tempoCaixa[id] + (caixas.top().first * -1);
    caixas.pop();
    /* a fila de prioridade ordena pelo maior valor, por isso 
    foi multiplicado por -1, pois assim o menor valor se torna o maior */
    caixas.push(make_pair(tempoQueVaiFicarLivre * -1, id * -1));
    resposta = max(resposta, tempoQueVaiFicarLivre);
  }

  cout << resposta << endl;
  return 0;
}
