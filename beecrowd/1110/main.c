#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct Cartas
{
  char carta;
  struct Cartas *prox;
} Carta;

typedef struct descrPilha
{
  Carta *topo, *final;
  int qtd;
} Pilha;

void pop(Pilha *p)
{
  Carta *aux;
  aux = p->topo;
  p->topo = aux->prox;

  free(aux);
  p->qtd--;
}

void jogaProFinal(Pilha *p)
{
  Carta *aux;
  aux = p->topo->prox;
  p->final->prox = p->topo;
  p->final = p->topo;
  p->topo = aux;
}

int main()
{
  int vDescart[55], Cqtd, c = 0, k = 0;
  Pilha PilhaPrincipal;
  Carta *aux;

  while (scanf("%d", &Cqtd) && Cqtd != 0)
  {
    for (c = 0; c < 55; c++)
      vDescart[c] = 0;

    k = 0;

    PilhaPrincipal.topo = NULL;
    PilhaPrincipal.qtd = 0;

    for (c = Cqtd; c > 0; c--)
    {
      aux = (Carta *)malloc(sizeof(Carta));

      if (aux == NULL)
        break;

      aux->carta = c;
      aux->prox = PilhaPrincipal.topo;

      PilhaPrincipal.topo = aux;
      PilhaPrincipal.qtd++;

      if (c == Cqtd)
        PilhaPrincipal.final = aux;
    }

    while (PilhaPrincipal.qtd >= 2)
    {
      vDescart[k] = PilhaPrincipal.topo->carta;
      k++;
      pop(&PilhaPrincipal);
      jogaProFinal(&PilhaPrincipal);
    }

    printf("Discarded cards:");
    for (c = 0; c < k; c++)
    {
      printf(" %d", vDescart[c]);
      if (c != k - 1)
        printf(",");
    }
    printf("\nRemaining card: %d\n", PilhaPrincipal.final->carta);
  }

  return 0;
}