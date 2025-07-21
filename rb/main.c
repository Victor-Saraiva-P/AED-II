#include "rb.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

	Arvore arvore;
	inicializar(&arvore);

	int funcao, valor_iterativo_1;

	srand(time(NULL));

	do
	{
		scanf("%d", &funcao);

		switch (funcao)
		{
		// inserir
		case 1:
			scanf("%d", &valor_iterativo_1);
			adicionar(valor_iterativo_1, &arvore);
			break;

		// pre order
		case 2:
			pre_order(arvore);
			printf("\n");
			break;

		// remover
		case 3:
			scanf("%d", &valor_iterativo_1);
			remover(valor_iterativo_1, &arvore);
			break;
		}
	} while (funcao != 99);
	arvore = limpar(arvore);
}
