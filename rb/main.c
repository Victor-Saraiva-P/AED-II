#include "rb.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

	Arvore arvore;
	inicializar(&arvore);

	int funcao, valor_iterativo_1, valor_iterativo_2, quantidade;

	srand(time(NULL));

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
			scanf("%d", &valor_iterativo_1);
			remover(valor_iterativo_1, &arvore);
			break;

		case 7:
			imprimir(arvore);
			printf("\n");
			break;

		case 8:
			scanf("%d", &valor_iterativo_1);
			scanf("%d", &valor_iterativo_2);
			inserir_sem_regra(valor_iterativo_1, valor_iterativo_2, &arvore);
			break;

		case 9:
            scanf("%d", &quantidade);

            for (int i = 0; i < quantidade; i++) {
                valor_iterativo_1 = rand() % 10000;
                adicionar(valor_iterativo_1, &arvore);
            }
            break;

		case 10:
            scanf("%d", &quantidade);

            for (int i = 0; i < quantidade; i++) {
                valor_iterativo_1 = rand() % 10000;
                remover(valor_iterativo_1, &arvore);
            }
            break;
		}
	} while (funcao != 99);
}
