#include <iostream>
#define debug(message, x) cout << message << x << endl

using namespace std;

int main(int argc, char **argv)
{
  string enigma;
  string crib;

  cin >> enigma >> crib;
  int enigma_pointer = 0, crib_pointer=0, num_solucoes=0; 
  // a quantidade de iterações é a diferença de tamanho entre as duas cifras
  for (int i = 0; i <= enigma.size() - crib.size(); i++)
  {
    bool tem_sobreposicao = false;

    // a cada iteração o enigma_pointer anda 1 e o crib_pointer começa em 0
    // crib_pointer sempre percorre todo o crib
    // enigma_pointer percorre uma substring começando em i e terminando no tamanho de crib
    enigma_pointer = i;
    crib_pointer = 0;

    while(crib_pointer < crib.size()) {
      debug("\n\nenigma_pointer:", enigma_pointer);
      debug("crib_pointer:", crib_pointer);

      debug("\nenigma[enigma_pointer]", enigma[enigma_pointer]);
      debug("crib[crib_pointer]", crib[crib_pointer]);

      // se existe sobreposicao as proximas iteracoes nao precisam ocorrer
      if(enigma[enigma_pointer] == crib[crib_pointer]) {
        debug("\nentrou", "aqui");
        tem_sobreposicao = true;
        break;
      }

      enigma_pointer++;
      crib_pointer++;
    }

    // caso crib_pointer chegue ao final e NAO haja sobreposicao entao marcamos um ponto
    if(!tem_sobreposicao) {
      num_solucoes++;
    };
  }

  cout << num_solucoes << endl;

  return 0;
}