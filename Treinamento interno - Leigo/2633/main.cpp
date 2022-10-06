//2633

// ordenar uma tupla baseada em em um dos dados

#include <stdio.h>

typedef struct{
	char nome[20];
	unsigned short num;
}dado;

void ordena(dado *, unsigned short tam);

int main ()
{
	unsigned short qtd, i;
	while (scanf("%hu", &qtd) != EOF)
	{
		dado churrasco[qtd];
		for (i = 0; i < qtd; i++)
			scanf("%s %hu", churrasco[i].nome, &churrasco[i].num);
		ordena(churrasco, qtd);
		for (i = 0; i < qtd; i++)
		{
			if (i != 0 && i != qtd)
				printf(" ");
			printf("%s", churrasco[i].nome);
		}
		printf("\n");
	}
	return 0;
}

void ordena(dado *churrasco, unsigned short tam)
{
	short i = 1, j;
	dado pivo;
	while (i < tam)
	{
		j = i - 1;
		pivo = churrasco[i];
		while (j >= 0 && churrasco[j].num > pivo.num)
		{
			churrasco[j + 1] = churrasco[j];
			j--;
		}
		churrasco[j + 1] = pivo;
		i++;
	}
}