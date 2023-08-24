/**
 * E - Enigma
 * String, Simulação
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  string enigma, crib;
  cin >> enigma >> crib;

  int i = 0;
  int count = 0;
  while (enigma.size() - i > (crib.size() - 1))
  {
    for (int j = i; j < i + crib.size(); j++)
    {
      if (enigma[j] == crib[j - i])
        break;

      if (j + 1 == i + crib.size())
        count++;
    }

    i++;
  }

  cout << count << endl;

  return 0;
}
