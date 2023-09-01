#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  string risada;

  getline(cin, risada);

  string risadaSemConsoante;
  for (auto r : risada)
  {
    if (r == 'a' || r == 'e' || r == 'i' || r == 'o' || r == 'u')
    {
      risadaSemConsoante += r;
    }
  }

  string risadaAoContrario = risadaSemConsoante;
  reverse(risadaAoContrario.begin(), risadaAoContrario.end());

  cout << (risadaSemConsoante == risadaAoContrario ? "S" : "N") << endl;

  return 0;
}
