#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct regNo
{
  struct regNo *esq;
  int valor;
  struct regNo *dir;
} TArvore;

int tipo;

TArvore *AchaPai(TArvore *r, int v)
{
  if (r == NULL)
    return NULL;
  else if (v <= r->valor)
    if (r->esq == NULL)
      return r;
    else
      return AchaPai(r->esq, v);
  else if (r->dir == NULL)
    return r;
  else
    return AchaPai(r->dir, v);
}

int ImprimeArvore(TArvore *r)
{
  if (r != NULL)
  {
    if (tipo == 1)
    {
      printf(" %d", r->valor);
      ImprimeArvore(r->esq);
      ImprimeArvore(r->dir);
    }
    if (tipo == 2)
    {
      ImprimeArvore(r->esq);
      printf(" %d", r->valor);
      ImprimeArvore(r->dir);
    }
    if (tipo == 3)
    {
      ImprimeArvore(r->esq);
      ImprimeArvore(r->dir);
      printf(" %d", r->valor);
    }
  }

  return 0;
}

int main()
{
  TArvore *raiz, *pai, *aux;
  int Tam, Ncasos, c, d, noh;

  raiz = NULL;
  scanf("%d", &Ncasos);

  for (c = 1; c <= Ncasos; c++)
  {
    raiz = NULL;

    scanf("%d", &Tam);
    for (d = 0; d < Tam; d++)
    {
      scanf("%d", &noh);

      aux = (TArvore *)malloc(sizeof(TArvore));
      aux->valor = noh;
      aux->esq = NULL;
      aux->dir = NULL;

      pai = AchaPai(raiz, noh);
      if (pai == NULL)
        raiz = aux;
      else if (noh <= pai->valor)
        pai->esq = aux;
      else
        pai->dir = aux;
    }

    printf("Case %d:", c);

    printf("\nPre.:");
    tipo = 1;
    ImprimeArvore(raiz);

    printf("\nIn..:");
    tipo = 2;
    ImprimeArvore(raiz);

    printf("\nPost:");
    tipo = 3;
    ImprimeArvore(raiz);

    printf("\n\n");
  }

  return 0;
}