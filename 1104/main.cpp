#include <iostream>
#include <vector>

#define debug(message, x) ;

using namespace std;

int main() {


  while(true) {
    vector<bool> cartas_alice(200000, false);
    vector<bool> cartas_beatriz(200000, false);

    long long int qtd_cartas_alice=-1, qtd_cartas_beatriz=-1;

    cin >> qtd_cartas_alice >> qtd_cartas_beatriz;

    debug("qtd_cartas_alice: ", qtd_cartas_alice);
    debug("qtd_cartas_beatriz: ", qtd_cartas_beatriz);

    if(qtd_cartas_alice == 0 && qtd_cartas_beatriz == 0) return 0;

    long long int num_trocas = 0;
    long long int maior_carta = -1;

    for(long long int i=0; i<qtd_cartas_alice; i++) {
      long long int num_carta;
      cin >> num_carta;

      cartas_alice[num_carta] = true;

      if(num_carta > maior_carta) maior_carta = num_carta;
    }

    for(long long int i=0; i<qtd_cartas_beatriz; i++) {
      long long int num_carta;
      cin >> num_carta;

      cartas_beatriz[num_carta] = true;

      if(num_carta > maior_carta) maior_carta = num_carta;

    }

    long long int cartas_elegiveis_alice=0, cartas_elegiveis_bia=0;
    for(long long int i=0;i<=maior_carta; ++i) {
      if(cartas_alice[i] == true && cartas_beatriz[i] == false) {
        debug("cartas_alice[i]", cartas_alice[i]);
        debug("cartas_beatriz", cartas_beatriz[i]);
        cartas_elegiveis_alice++;
      }

      if(cartas_alice[i] == false && cartas_beatriz[i] == true) {
         debug("i: ", i);
         debug("cartas_alice[i]: ", cartas_alice[i]);
        debug("cartas_beatriz[i]: ", cartas_beatriz[i]);
        cartas_elegiveis_bia++;
      }
    }

    if(cartas_elegiveis_alice<cartas_elegiveis_bia) {
      cout << cartas_elegiveis_alice << endl;
    } else {
      cout << cartas_elegiveis_bia << endl;
    }
  }

  return 0;
}