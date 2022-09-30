#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
  int numEntradas, minutos, diferenca;
  string turno;

  cin >> numEntradas;

  for(int i=0; i<numEntradas;  i++){
    cin >> minutos;
    getline(cin, turno);
    if(minutos < 45 && turno.compare(" 1T") == 0){
      cout << minutos;
    }
    else if(minutos > 45 && turno.compare(" 1T") == 0){
      diferenca = minutos-45;
      cout << 45 << "+" << diferenca;
    }
    else if(minutos <= 45 && turno.compare(" 2T") == 0){
      cout << 45 + minutos;
    }
    else if(minutos > 45 && turno.compare(" 2T") == 0){
      diferenca = minutos-45;
      cout << 90 << "+" << diferenca;
    }
    cout << endl;
  }

  return 0;
}