#include <iostream>

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

int main(int argc, char **argv)
{
  int degree;
  while(cin >> degree) {
    if(degree % 6 == 0)  cout << "Y\n";
    else cout << "N\n";
  }

  return 0;
}
