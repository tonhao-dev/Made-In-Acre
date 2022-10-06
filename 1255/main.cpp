// https://www.beecrowd.com.br/judge/pt/problems/view/1255
// String, contagem, frequência de letras em uma frase

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string minuscula(string frase)
{
    string retorno;

    for (auto x : frase)
    {
        retorno += tolower(x);
    }

    return retorno;
}

int main(int argc, char *argv[])
{
    int num_frases;
    cin >> num_frases;

    getchar();

    while (num_frases)
    {
        vector<int> letras(26, 0);
        string frase;

        getline(cin, frase);

        frase = minuscula(frase);
        for (auto letra : frase)
        {
            if (isalpha(letra))
            {
                letras[letra - 'a']++;
            }
        }

        int maior = letras[0];
        string saida;
        for (int i = 0; i < letras.size(); ++i)
        {
            if (letras[i] == maior)
            {
                saida += i + 'a';
            }
            if (letras[i] > maior)
            {
                saida = i + 'a';
                maior = letras[i];
            }
        }

        cout << saida << endl;

        --num_frases;
    }

    return 0;
}
