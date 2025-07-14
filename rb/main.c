#include "rb.h"
#include <stdio.h>

int main(void)
{

	Arvore arvore;
	inicializar(&arvore);

	int funcao, valor_iterativo_1;

	do
	{
		scanf("%d", &funcao);

		switch (funcao)
		{
		case 1:
			scanf("%d", &valor_iterativo_1);
			adicionar(valor_iterativo_1, &arvore);
			break;

		case 2:
			pre_order(arvore);
			printf("\n");
			break;

		case 3:
			in_order(arvore);
			printf("\n");
			break;

		case 4:
			pos_order(arvore);
			printf("\n");
			break;

		case 5:
			arvore = limpar(arvore);
			break;
		
		case 6:
			remover(valor_iterativo_1, &arvore);
			break;
			
		case 7:
			imprimir(arvore);
		}
	} while (funcao != 99);
}
