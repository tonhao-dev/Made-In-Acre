
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{

  char numero[250];

} string;

string numeros[110000];

int main(int argc, char **argv)
{

  int qtdNumeros, i, j;
  while (scanf("%d", &qtdNumeros) != EOF)
  {

    i = 0;
    int aux = qtdNumeros;
    while (qtdNumeros--)
      scanf("%s", numeros[i++].numero);

    int resposta = 0;

    for (i = 1; i < aux; ++i)
      for (j = 0; numeros[i].numero[j]; ++j)
        if (numeros[i].numero[j] == numeros[i - 1].numero[j])
          ++resposta;
        else
          break;

    printf("%u\n", resposta);
  }

  return 0;
}