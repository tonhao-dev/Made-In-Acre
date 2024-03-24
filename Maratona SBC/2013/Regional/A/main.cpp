/**
 * A - Zerinho ou Um
 * Adhoc
*/

#include <iostream>

using namespace std;

int main()
{
  int a, b, c;

  while (cin >> a >> b >> c)
  {
    if (a == b && b == c && a == c)
    {
      cout << "*" << endl;
    }

    if (a != b && b == c)
    {
      cout << "A" << endl;
      continue;
    }

    if (b != c && c == a)
    {
      cout << "B" << endl;
      continue;
    }

    if (c != b && b == a)
    {
      cout << "C" << endl;
      continue;
    }
  }

  return 0;
}
