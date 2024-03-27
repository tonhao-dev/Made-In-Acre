/**
 * 2399 - Campo Minado
 * Adhoc
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n; cin >> n;

  vector<int> bombas(n);
  for(auto &i : bombas) cin >> i;

  for(int i = 0; i < n; i++) {
    int b = 0;
    if(i > 0 && bombas[i - 1]) b++;
    if(bombas[i]) b++;
    if(i + 1 != n && bombas[i + 1]) b++;

    cout << b << endl;
  }

  return 0;
}
