/**
 * 3428 - Estourando Balões
 * Adhoc, simulação
 */


#include <bits/stdc++.h>

using namespace std;

int const MAX_H = 1000001;

int main() {
  int qtd; cin >> qtd;
  int ans = 0;

  vector<int> h(MAX_H, 0);

  for (int i = 0; i < qtd; i++) {
    int x;
    cin >> x;

    if (h[x] > 0) h[x]--;
    else ans++;

    h[x - 1]++;
  }

  cout << ans << endl;

  return 0;
}
