#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000

typedef struct
{
  int vetor[MAX];
  int topo;
} Pilha;

void push(Pilha *p, int id)
{
  p->vetor[++p->topo] = id;
}

void pop(Pilha *p)
{
  p->topo--;
}

int main()
{

  int fora, vagao, i, erro, entrou, zero;
  Pilha p;

  while (scanf("%d", &vagao) && vagao)
  {
    while (1)
    {
      p.topo = -1;
      for (i = 0, entrou = 1, erro = 0, zero = 0; i < vagao && !erro && !zero; i++)
      {
        scanf("%d", &fora);
        if (!fora)
        {
          zero = 1;
          break;
        }
        while (1)
        {
          if (fora == entrou)
          {
            entrou++;
            break;
          }
          else if (fora > entrou)
          {
            push(&p, entrou);
            entrou++;
          }
          else
          {
            if (p.vetor[p.topo] == fora)
              pop(&p);
            else
            {
              erro = 1;
              for (; i < vagao - 1; i++)
                scanf("%d", &fora);
            }
            break;
          }
        }
      }
      if (!zero)
        if (!erro)
          printf("Yes\n");
        else
          printf("No\n");
      else
        break;
    }
    printf("\n");
  }
  return 0;
}
