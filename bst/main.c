#include "bst.h"
#include <stdio.h>

int main(void) {

  Arvore arvore = inicializar();

  int funcao, valor_iterativo_1, valor_iterativo_2;

  do {
    scanf("%d", &funcao);

    switch (funcao) {
    case 1:
      scanf("%d", &valor_iterativo_1);
      arvore = inserir(valor_iterativo_1, arvore);
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
      reverso(arvore);
      printf("\n");
      break;

    case 6:
      printf("%d\n", qtd_folhas(arvore));
      break;
      
    case 7:
    	scanf("%d", &valor_iterativo_1);
			printf("%d\n", sucessor(valor_iterativo_1, arvore));
			break;
			
		case 8:
			scanf("%d", &valor_iterativo_1);
			printf("%d\n", pai(valor_iterativo_1, arvore));
			break;
    
    case 9:
    	scanf("%d", &valor_iterativo_1);
			arvore = remover(valor_iterativo_1, arvore);
			break;
		
		case 10:
    	scanf("%d", &valor_iterativo_1);
    	scanf("%d", &valor_iterativo_2);
			printf("%d\n", soma_intervalo(valor_iterativo_1, valor_iterativo_2, arvore));
			break;
			
		case 11:
			arvore = limpar(arvore);
			break;
			
		case 12:
			scanf("%d", &valor_iterativo_1);
			arvore = multiplicar_por(arvore, valor_iterativo_1);
			break;
			
		case 13:
			scanf("%d", &valor_iterativo_1);
			printf("%d\n", busca(valor_iterativo_1, arvore));
			break;
			
		case 14:
			scanf("%d", &valor_iterativo_1);
			descendentes(valor_iterativo_1, arvore);
			printf("\n");
			break;
    }
  } while (funcao != 99);
}
