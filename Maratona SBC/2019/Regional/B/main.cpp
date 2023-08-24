/**
 * B - Bobo da Corte
 * Iniciante
 */

#include <iostream>

using namespace std;

int main()
{
  int qtd;
  cin >> qtd;

  bool ganhou = true;
  int meusVotos = 0;
  for (int i = 0; i < qtd; i++)
  {
    int votos;
    cin >> votos;

    if (i == 0)
    {
      meusVotos = votos;
      continue;
    }

    if (votos > meusVotos)
    {
      ganhou = false;
    }
  }

  cout << (ganhou ? "S" : "N") << endl;

  return 0;
}
