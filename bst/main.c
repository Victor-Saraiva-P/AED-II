#include "bst.h"
#include <stdio.h>

int main(void) {

  Arvore arvore = inicializar();

  int valor_iterativo;

  int funcao;
  do {
    scanf("%d", &funcao);

    switch (funcao) {
    case 1:
      scanf("%d", &valor_iterativo);
      arvore = inserir(valor_iterativo, arvore);
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
      
    case 7:
    	scanf("%d", &valor_iterativo);
			printf("%d\n", sucessor(valor_iterativo, arvore));
			
		case 8:
			scanf("%d", &valor_iterativo);
			printf("%d\n", pai(valor_iterativo, arvore));
    }
  } while (funcao != 99);
}
