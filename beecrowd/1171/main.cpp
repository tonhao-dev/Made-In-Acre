/**
 * 1171 - Frequência de Números
 * Adhoc
 */

#include <bits/stdc++.h>

using namespace std;

int main() {

  int t; cin >> t;
  vector<int> val(t);
  for(int i = 0; i < t; i++) {
    cin >> val[i];
  }

  for(int i = 1; i <= 2000; i++) {
    int contagem = 0;

    for(auto v : val)
      contagem += (v == i);
    // ou: count(val.begin(), val.end(), i)

    if(contagem == 0) continue;

    cout << i << " aparece " << contagem << " vez(es)" << endl;
  }

  return 0;
}
