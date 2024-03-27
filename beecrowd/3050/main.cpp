/**
 * 3050 - Distância Entre Amigos
 * Adhoc, simulação, implementação
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, i, j, distancia;

  cin >> N;
  int predios[N];

  for (i = 0; i < N; i++)
    cin >> predios[i];

  int maior = -1;
  for (i = 0; i < N - 1; i++)
  {
    for (j = i; j < N; j++)
    {
      distancia = predios[i] + (j - i) + predios[j];
      if (distancia > maior)
        maior = distancia;
    }
  }

  cout << maior << endl;

  return 0;
}
