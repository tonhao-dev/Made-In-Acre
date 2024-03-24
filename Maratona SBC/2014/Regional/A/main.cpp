/**
 * A - Volta
 * Adhoc
*/

#include <iostream>

using namespace std;

int main() {
  int x, y; cin >> x >> y;

  int ans = 1;
  int acumulador = y - x;
  while(y > acumulador) {
    acumulador += y - x;
    ans++;
  }


  cout << ans << endl;


  return 0;
}
