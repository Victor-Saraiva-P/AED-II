// main
#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

int main(int argc, char *argv[])
{
    Arvore a1 = NULL;
    int opcao, valor, cresceu = 0, diminuiu = 0;

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

        // pre order
        case 2:
            pre_order(a1);
            printf("\n");
            break;

        // remover
        case 3:
            scanf("%d", &valor);
            diminuiu = 0;
            a1 = remover(a1, valor, &diminuiu);
            break;

        case 99:
            a1 = limpar(a1);
            exit(0);
        }
    }
    return 0;
}
