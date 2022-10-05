#include <iostream>
#include <vector>
#include <string>
#include <map>

#define debug(message, x) cout << message << ": " << x << "\n"
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

map<char, int> letra_valor;
map<int, char> valor_letra;

class No
{
public:
    No *esquerda;
    No *direita;
    int valor;
    bool visitado;

    No()
    {
        this->esquerda = NULL;
        this->direita = NULL;
        this->valor = 0;
        this->visitado = false;
    }
};

class Arvore
{
public:
    No *raiz;

    Arvore()
    {
        this->raiz = NULL;
    }

    void insere(int valor)
    {
        No *novo_no = new No();
        novo_no->valor = valor;

        if (this->raiz == NULL)
        {
            this->raiz = novo_no;
            return;
        }

        insereNo(this->raiz, novo_no);
    }

    void insereNo(No *no_corrente, No *novo_no)
    {
        if (novo_no->valor < no_corrente->valor)
        {
            if (no_corrente->esquerda == NULL)
            {
                no_corrente->esquerda = novo_no;
            }
            else
            {
                insereNo(no_corrente->esquerda, novo_no);
            }
        }
        else
        {
            if (no_corrente->direita == NULL)
            {
                no_corrente->direita = novo_no;
            }
            else
            {
                insereNo(no_corrente->direita, novo_no);
            }
        }
    }

    void pre_ordem(No *no_corrente)
    {
        if (no_corrente->visitado == false)
        {
            no_corrente->visitado = true;
        }

        if (no_corrente->esquerda != NULL)
            pre_ordem(no_corrente->esquerda);
        if (no_corrente->direita != NULL)
            pre_ordem(no_corrente->direita);
    }

    void em_ordem(No *no_corrente)
    {
        if (no_corrente->esquerda != NULL)
            em_ordem(no_corrente->esquerda);

        if (no_corrente->visitado == false)
        {
            no_corrente->visitado = true;
        }

        if (no_corrente->direita != NULL)
            em_ordem(no_corrente->direita);
    }

    void pos_ordem(No *no_corrente)
    {
        if (no_corrente->esquerda != NULL)
            pos_ordem(no_corrente->esquerda);

        if (no_corrente->direita != NULL)
            pos_ordem(no_corrente->direita);

        if (no_corrente->visitado == false)
        {
            no_corrente->visitado = true;
            cout << valor_letra[no_corrente->valor];
        }
    }
};

int main(int argc, char **argv)
{
    int num_casos, num_nos;
    string pre_ordem, em_ordem;

    cin >> num_casos;

    for (int caso = 0; caso < num_casos; caso++)
    {
        Arvore *arvore = new Arvore();

        letra_valor.clear();
        valor_letra.clear();

        cin >> num_nos >> pre_ordem >> em_ordem;

        for (int i = 0; i < num_nos; i++)
        {
            letra_valor[em_ordem[i]] = i;
            valor_letra[i] = em_ordem[i];
        }

        for (auto letra : pre_ordem)
        {

            arvore->insere(letra_valor[letra]);
        }

        arvore->pos_ordem(arvore->raiz);

        cout << endl;
    }

    return 0;
}
