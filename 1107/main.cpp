#include <iostream>

using namespace std;

int main() {
  int linha, coluna;

  while(true) {
    cin >> linha >> coluna;
    if(linha == 0 || coluna == 0) return 0;

    int array[coluna];
    for(int i=0;i<coluna;++i) {
      cin >> array[i];
    }

    int resultado=0;

    for(int array_index=0; array_index < coluna; array_index++) {
      for(int i=0; i< linha; ++i) {
        resultado += 
      }
    }

    cout << resultado << endl;
  }

  return 0;
}