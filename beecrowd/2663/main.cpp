/**
 * 2663 - Fase
 * Adhoc
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> pontuacao(1001, 0);

  for(int i = 0; i < n; i++) {
    int ponto; cin >> ponto;
    pontuacao[ponto]++;
  }

  int ans = 0;
  for(int i = 1000; i >= 0; i--) {
    ans += pontuacao[i];
    if(ans >= k) break;
  }

  cout << ans << endl;

  return 0;
}
