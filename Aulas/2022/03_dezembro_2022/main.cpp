#include <iostream>

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)  \
  for (auto x : vector) \
    cout << x << " ";   \
  cout << endl

using namespace std;

int main(int argc, char **argv)
{
  long long int entrada;

  cin >> entrada;

  if (entrada == 2)
    cout << 3 << "\n";

  if (entrada % 2 == 0)
    cout << entrada - 1 << endl;
  else
    cout << entrada << endl;

  return 0;
}
