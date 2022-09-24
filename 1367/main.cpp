#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int num_submissoes=-1;

  while(num_submissoes != 0) {
    cin >> num_submissoes;

    if(num_submissoes == 0) {
      return 0;
    }

    vector<int> qtd_erros(26, 0);
    long long int tempo_total = 0;
    int qtd_questoes_resolvidas = 0;

    for(int i=0;i<num_submissoes;++i) {
      char questao;
      int tempo;
      string status;

      cin >> questao >> tempo >> status;

      if(status == "incorrect") {
        qtd_erros[questao - 'A']++;
      } else {
        qtd_questoes_resolvidas++;
        tempo_total += tempo + qtd_erros[questao - 'A'] * 20;
      }
    }

    cout << qtd_questoes_resolvidas << " " << tempo_total << endl;
  }


  return 0;
}