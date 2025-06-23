// main
#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

int main(int argc, char *argv[])
{
    arvore a1 = NULL;
    int opcao, valor, cresceu, diminuiu;

    while (1)
    {
        scanf("%d", &opcao);
        switch (opcao)
        {
        // inserir
        case 1:
            scanf("%d", &valor);
            cresceu = 0;
            a1 = inserir(a1, valor, &cresceu);
            break;
        case 2:
            pre_order(a1);
            printf("\n");
            break;
        case 3:
            scanf("%d", &valor);
            diminuiu = 1;
            a1 = remover(a1, valor, &diminuiu);
            break;
        case 4:
            a1 = limpar(a1);
            break;

        case 99:
            exit(0);
        }
    }
}
