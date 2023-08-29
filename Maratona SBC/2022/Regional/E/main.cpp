/**
 * E - Estourando Balões
 * Adhoc
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define lld long long int

#define debug(message, x) cout << message << x << endl

using namespace std;

int main(int argc, char **argv)
{
  lld baloes, resp = 0, altura;
  cin >> baloes;
  vector<lld> flechas(1000006);

  for(lld i=1; i<=baloes; i++) {
    cin >> altura;
    if(flechas[altura] > 0) {
      flechas[altura]--;
      flechas[altura-1]++;
    } else {
      flechas[altura-1]++;
      resp++;
    }
  }
  cout << resp << endl;
  return 0;
}
