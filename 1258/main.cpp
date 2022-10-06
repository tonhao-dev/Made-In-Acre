// https://www.beecrowd.com.br/judge/pt/problems/view/1258
// Ordenação de objetos, leitura de string, char e numero

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

#define debug(message, x) cout << message << x << endl

using namespace std;

class Pessoa
{
public:
    string nome;
    string cor;
    string tamanho;
};

bool compara(Pessoa pessoaA, Pessoa pessoaB)
{
    if (pessoaA.cor == "branco" && pessoaB.cor == "vermelho")
        return true;
    if (pessoaA.cor == "vermelho" && pessoaB.cor == "branco")
        return false;

    if (pessoaA.tamanho == "P" && (pessoaB.tamanho == "M" || pessoaB.tamanho == "G"))
        return true;
    if (pessoaB.tamanho == "P" && (pessoaA.tamanho == "M" || pessoaA.tamanho == "G"))
        return false;
    if (pessoaA.tamanho == "M" && pessoaB.tamanho == "G")
        return true;
    if (pessoaA.tamanho == "G" && pessoaB.tamanho == "M")
        return false;

    return pessoaA.nome < pessoaB.nome;
}

int main(int argc, char **argv)
{
    int casos;
    int num_caso = 1;

    while (cin >> casos)
    {
        if (casos == 0)
            break;

        if (num_caso != 1)
            cout << endl;

        num_caso++;
        vector<Pessoa> pessoas(casos);
        for (int i = 0; i < casos; i++)
        {
            string nome, entrada, cor, tamanho;

            cin.ignore();
            getline(cin, nome);
            cin >> cor >> tamanho;

            pessoas[i].nome = nome;
            pessoas[i].cor = cor;
            pessoas[i].tamanho = tamanho;
        }

        sort(pessoas.begin(), pessoas.end(), compara);

        for (auto pessoa : pessoas)
        {
            cout << pessoa.cor << " " << pessoa.tamanho << " " << pessoa.nome << endl;
        }
    }

    return 0;
}
