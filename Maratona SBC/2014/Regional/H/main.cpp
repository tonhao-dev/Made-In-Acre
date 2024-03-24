/**
 * H - Handebol
 * Adhoc
*/

#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  bool fezTodos = true;
  int total = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int gols;
      cin >> gols;
      if (gols == 0) fezTodos = false;
    }

    if (fezTodos) total++;
    fezTodos = true;
  }

  cout << total << endl;

  return 0;
}
