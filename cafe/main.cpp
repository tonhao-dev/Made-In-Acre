#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
  float estudantes, litros, mililitros, quantidadeLitros;
  cin >> estudantes >> litros >> mililitros;
  quantidadeLitros =  estudantes * mililitros / 1000 / litros;
  cout << ceil(quantidadeLitros) * litros << endl;
  return 0;
}