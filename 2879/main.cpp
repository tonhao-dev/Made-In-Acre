#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  int numcasos, numvitorias = 0, portacarro;

  cin >> numcasos;

  for (int i = 0; i < numcasos; i++)
  {
    cin >> portacarro;

    // a porta escolhida sempre é a 1
    // o apresentador sempre abre a outra porta
    // o candidato sempre troca de porta
    // assim, basta ver quantas vezes a porta do carro != 1
    if (portacarro == 1)
      continue;

    numvitorias++;
  }

  cout << numvitorias << endl;

  return 0;
}