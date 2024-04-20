#include <iostream>

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)  \
  for (auto x : vector) \
    cout << x << " ";   \
  cout << endl

using namespace std;

int main(int argc, char **argv)
{

  int a, b, c, d, e, f, resp = 0;

  cin >> a >> b >> c >> d >> e >> f;

  if (d - a > 0)
    resp += d - a;
  if (e - b > 0)
    resp += e - b;
  if (f - c > 0)
    resp += f - c;

  cout << resp << endl;

  return 0;
}
