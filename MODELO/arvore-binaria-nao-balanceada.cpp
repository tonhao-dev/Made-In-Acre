#include <iostream>
#include <vector>
#include <string>

#define debug(message, x) cout << message << ": " << x << "\n"
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

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
            cout << "Visitando " << no_corrente->valor << endl;
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
            cout << "Visitando " << no_corrente->valor << endl;
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
            cout << "Visitando " << no_corrente->valor << endl;
        }
    }
};

int main(int argc, char **argv)
{
    Arvore *arvore = new Arvore();

    arvore->insere(6);
    arvore->insere(2);
    arvore->insere(8);
    arvore->insere(1);
    arvore->insere(4);
    arvore->insere(3);

    arvore->em_ordem(arvore->raiz);

    return 0;
}
