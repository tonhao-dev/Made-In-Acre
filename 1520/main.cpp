// https://www.beecrowd.com.br/judge/pt/problems/view/1520
// algoritms de ordenacao
#include <iostream>
#include <vector>

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

int main(int argc, char **argv)
{
  int numIntervalos;

  while(cin >> numIntervalos) {
    vector<int> porcasParafusos(105);
    int inicio, fim, parametroDeBusca;
    long long int soma = 0;

    for(int i=0; i<numIntervalos; i++) {
      cin >> inicio >> fim;
      for(int i = inicio; i<=fim; i++) porcasParafusos[i]++;
    }

    cin >> parametroDeBusca;

    if(porcasParafusos[parametroDeBusca] == 0){
      cout << parametroDeBusca << " not found" << endl;
      continue;
    }

    for(int i=1; i<parametroDeBusca; i++) soma += porcasParafusos[i];

    cout << parametroDeBusca << " found from " << soma << " to " << soma + porcasParafusos[parametroDeBusca] - 1 << endl; 
  }
  return 0;
}
