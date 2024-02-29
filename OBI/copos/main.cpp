/*
* OBI 2019 - Fase 2: Jogo dos copos
*/

#include <iostream>

using namespace std;

void movimento(int tipo, char &moeda)
{

  if (tipo == 1 && (moeda == 'A' || moeda == 'B'))
  {
    moeda = moeda == 'A' ? 'B' : 'A';
  }

  if (tipo == 2 && (moeda == 'B' || moeda == 'C'))
  {
    moeda = moeda == 'B' ? 'C' : 'B';
  }

  if (tipo == 3 && (moeda == 'A' || moeda == 'C'))
  {
    moeda = moeda == 'A' ? 'C' : 'A';
  }
}

int main()
{
  int n;
  char moeda;

  cin >> n >> moeda;

  for (int i = 0; i < n; i++)
  {
    int tipo;
    cin >> tipo;
    movimento(tipo, moeda);
  }

  cout << moeda << endl;

  return 0;
}
