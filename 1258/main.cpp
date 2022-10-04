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
        return -1;
    if (pessoaA.cor == "vermelho" && pessoaB.cor == "branco")
        return 1;

    if (pessoaA.tamanho == "P" && (pessoaB.tamanho == "M" || pessoaB.tamanho == "G"))
        return -1;
    if (pessoaB.tamanho == "P" && (pessoaA.tamanho == "M" || pessoaA.tamanho == "G"))
        return 1;
    if (pessoaA.tamanho == "M" && pessoaB.tamanho == "G")
        return -1;
    if (pessoaA.tamanho == "G" && pessoaB.tamanho == "M")
        return 1;

    if (pessoaA.nome < pessoaB.nome)
        return -1;
    if (pessoaA.nome > pessoaB.nome)
        return 1;

    return 0;
}

int main(int argc, char **argv)
{
    int casos;

    while (cin >> casos)
    {
        cout << casos << endl;
        if (casos == 0)
            break;

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

        cout << endl;
    }

    return 0;
}