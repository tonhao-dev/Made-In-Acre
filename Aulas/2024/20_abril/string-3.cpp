#include <bits/stdc++.h>

using namespace std;

int main() {
    //  012345
    string nome_completo = "luis antonio lima santiago";
    string sobrenome_mychelle = "rocha";
    string sobrenome_tonhao = "lima";

    // pega a partir de que posicao começa "santiago" na variavel "nome completo"
    int index_sobrenome = nome_completo.find(sobrenome_tonhao);

    // 1 -> a partir de que posição a string vai ser alterada
    // 2 -> quantidade de caracteres que serão apagados
    // 3 -> string que será inserida no lugar
    nome_completo.replace(index_sobrenome, sobrenome_tonhao.size(), sobrenome_mychelle);

    cout << nome_completo << endl;

    return 0;
}
