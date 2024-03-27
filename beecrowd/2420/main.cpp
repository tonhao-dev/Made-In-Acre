/**
 * 2420 - Guerra por Território
 * Adhoc
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int qtd; cin >> qtd;

  vector<int> territorios(qtd);
  int acumulador = 0;
  for(int i = 0; i < qtd; i++) {
    cin >> territorios[i];
    acumulador += territorios[i];
  }

  int divisao = acumulador / 2;
  int soma = 0;
  for(int i = 0; i < qtd; i++) {
    soma += territorios[i];
    if(soma == divisao) {
      cout << i + 1 << endl;
      break;
    }
  }

  return 0;
}
