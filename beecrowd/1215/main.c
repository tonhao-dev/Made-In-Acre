#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

typedef struct
{
  char palavras[201];
} string;

int comparar(const void *a, const void *b)
{
  return strcmp(((string *)a)->palavras, ((string *)b)->palavras);
}

void classificarPalavras(string *palavras, int tamanho)
{
  qsort(palavras, tamanho, sizeof(string), comparar);

  for (int i = 0; i < tamanho; i++)
  {
    if (i == 0 || strcmp(palavras[i].palavras, palavras[i - 1].palavras) != 0)
    {
      printf("%s\n", palavras[i].palavras);
    }
  }
}

#define MAX_WORDS 200

int main(void)
{
  char espaco;
  setlocale(LC_ALL, "Portuguese");
  char text[MAX_WORDS];
  char *palavras[MAX_WORDS];
  int stringAtual = 0;
  string dicionario[5050];

  while (scanf(" %[^\n]", text) != EOF)
  {
    int auxiliar = 0;
    char textFinal[MAX_WORDS];

    for (int i = 0; i <= strlen(text); i++)
    {
      if (!isalpha(text[i]))
      {
        if (auxiliar != 0 && text[i] != '\0')
        {
          strcpy(dicionario[stringAtual].palavras, textFinal);
          memset(textFinal, 0, sizeof(textFinal));
          stringAtual++;
          auxiliar = 0;
        }
        continue;
      }
      textFinal[auxiliar++] = tolower(text[i]);
    }

    strcpy(dicionario[stringAtual].palavras, textFinal);
    stringAtual++;
  }
  string novo[5050];
  int contador = 0;

  for (int j = 0; j < stringAtual; j++)
  {
    if (isalpha(dicionario[j].palavras[0]) && dicionario[j].palavras[0] != ' ' && dicionario[j].palavras[0] != '\0')
    {
      strcpy(novo[contador].palavras, dicionario[j].palavras);
      contador++;
    }
  }

  classificarPalavras(novo, contador);
  return 0;
}