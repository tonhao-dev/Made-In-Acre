#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


#define debug(message, x) cout << message << x << endl

using namespace std;

int main(int argc, char **argv)
{
  int baloes, alturaDaFlecha, maiorAltura = -1, resp = 0;
  cin >> baloes;
  vector<int> alturas(baloes+5);
  vector<bool> vivos(baloes+5, true);

  for(int i=1; i<=baloes; i++){
     cin >> alturas[i];
     maiorAltura = max(alturas[i], maiorAltura);
  } 

  for(int i=maiorAltura; i>=1; i--){
    alturaDaFlecha = i;
    bool matou = false;

    for(int j=1; j<=baloes; j++){
      if(alturas[j] == alturaDaFlecha && vivos[j]){
        matou = true;
        vivos[j] = false;
        alturaDaFlecha--;
      }
    }

    if(!matou) continue;

    resp++;
    i++;
  }

  cout << resp << endl;
  return 0;
}
