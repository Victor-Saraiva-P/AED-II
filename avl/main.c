// main
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "avl.h"

int main(int argc, char *argv[])
{
    Arvore a1 = NULL;
    int opcao, valor, cresceu = 0, diminuiu = 0, quantidade;  // Initialize variables

    srand(time(NULL));

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
            diminuiu = 0;  // Reset to consistent state
            a1 = remover(a1, valor, &diminuiu);
            break;
        case 4:
            a1 = limpar(a1);
            break;

        case 5:
            scanf("%d", &quantidade);

            for (int i = 0; i < quantidade; i++)
            {
                valor = rand() % 10000000;
                cresceu = 0;  // Reset for each insertion
                a1 = inserir(a1, valor, &cresceu);
            }
            break;

        case 6:
            scanf("%d", &quantidade);

            for (int i = 0; i < quantidade; i++)
            {
                valor = rand() % 10000000;
                diminuiu = 0;  // Reset for each removal
                a1 = remover(a1, valor, &diminuiu);
            }
            break;


        case 99:
            a1 = limpar(a1);  // Ensure memory is freed before exit
            exit(0);
        }
    }
    return 0;  // This is never reached but good practice
}
