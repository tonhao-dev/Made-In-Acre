// https://www.beecrowd.com.br/judge/pt/problems/view/1025
// Ordenação, Counting Sort

#include <iostream>
#include <vector>

#define debug(message, x) cout << message << x << endl

using namespace std;

int main(int argc, char **argv)
{
  int numMarmores, numConsultas, entrada, contador = 1;
  while(true){
    cin >> numMarmores >> numConsultas;
    if(numMarmores == 0 && numConsultas == 0) break;
    vector<int> marmores(10001);

    for(int i=0; i<numMarmores; i++){
      cin >> entrada;
      marmores[entrada]++;
    }

    cout << "CASE# " << contador << ":" << endl;

    for(int i=0; i<numConsultas; i++){
      int soma = 0;
      cin >> entrada;

      if(marmores[entrada] == 0){
        cout << entrada << " not found" <<  endl;
        continue;
      }

      for(int j=0; j<entrada; j++){
        soma+=marmores[j];
      }
      cout << entrada << " found at " << soma+1 << endl;
    }

    contador++;
  }

  return 0;
}