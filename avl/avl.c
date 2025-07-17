// implementação das funções

#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

// Implementação recursiva
Arvore inserir(Arvore raiz, T_ELEM valor, int *cresceu)
{
    // Caso base: instância mais simples do problema
    // Inserir em uma árvore vazia
    if (raiz == NULL)
    {
        // Alocar memória
        Arvore novo_no = (Arvore)malloc(sizeof(No_alv));
        // Inicializar variáveis membro
        novo_no->valor = valor;
        novo_no->esq = NULL;
        novo_no->dir = NULL;
        novo_no->fb = 0;
        // retornar a (sub)árvore atualizada
        // Cresceu Retornar para chamada anterior
        *cresceu = 1;
        return novo_no;
    }
    else
    {
        // Caso recursivo -> Um passo em direção ao caso base
        // Decidir se vamos para sub-Arvore esquerda ou direita
        if (valor > raiz->valor)
        {
            // chamada recursiva
            raiz->dir = inserir(raiz->dir, valor, cresceu);
            // Atualizar FB
            if (*cresceu)
            {
                switch (raiz->fb)
                {
                case -1:
                    raiz->fb = 0;
                    *cresceu = 0;
                    break;
                case 0:
                    raiz->fb = 1;
                    *cresceu = 1;
                    break;
                case 1:
                    raiz->fb = 2;
                    *cresceu = 0;
                    return rotacao(raiz, NULL);
                }
            }
        }
        else
        {
            raiz->esq = inserir(raiz->esq, valor, cresceu);
            // Atualizar FB
            if (*cresceu)
            {
                switch (raiz->fb)
                {
                case -1:
                    raiz->fb = -2;
                    *cresceu = 0;
                    return rotacao(raiz, NULL);
                case 0:
                    raiz->fb = -1;
                    *cresceu = 1;
                    break;
                case 1:
                    raiz->fb = 0;
                    *cresceu = 0;
                    break;
                }
            }
        }
        return raiz;
    }
}

Arvore rotacao(Arvore pivo, int *diminuiu)
{
    // rotação esquerda
    if (pivo->fb == 2)
    {
        Arvore u = pivo->dir;

        // rotação simples esquerda
        if (u->fb >= 0)
        {
            if (diminuiu != NULL)
            {
                // só cai se u->fb==0
                if (u->fb == 0)
                    *diminuiu = 0;
            }

            return rotacao_simples_esquerda(pivo);
        }
        // rotação dupla esquerda
        else
        {
            return rotacao_dupla_esquerda(pivo);
        }
    }
    // rotação direita
    else
    {
        Arvore u = pivo->esq;

        // rotação simples direita
        if (u->fb <= 0)
        {
            if (diminuiu != NULL)
            {
                // só cai se u->fb==0
                if (u->fb == 0)
                    *diminuiu = 0;
            }

            return rotacao_simples_direita(pivo);
        }
        // rotação dupla direita
        else
        {
            return rotacao_dupla_direita(pivo);
        }
    }
    return pivo;
}

Arvore rotacao_simples_esquerda(Arvore pivo)
{
    // Declarar e inicializar os ponteiros
    Arvore u, t2;
    u = pivo->dir;
    t2 = u->esq;

    // Atualizar ponteiros
    u->esq = pivo;
    pivo->dir = t2;

    // Atualizar o fator de balanço
    if (u->fb == 1)
    {
        pivo->fb = 0;
        u->fb = 0;
    }
    else
    {
        pivo->fb = 1;
        u->fb = -1;
    }
    return u;
}

Arvore rotacao_simples_direita(Arvore pivo)
{
    // Declarar e inicializar os ponteiros
    Arvore u, t2;
    u = pivo->esq;
    t2 = u->dir;

    // Atualizar ponteiros
    u->dir = pivo;
    pivo->esq = t2;

    // Atualizar o fator de balanço
    if (u->fb == -1)
    {
        pivo->fb = 0;
        u->fb = 0;
    }
    else
    {
        pivo->fb = -1;
        u->fb = 1;
    }

    return u;
}

Arvore rotacao_dupla_direita(Arvore pivo)
{
    // Declarar e inicializar os ponteiros
    Arvore u, v, t2, t3;
    u = pivo->esq;
    v = u->dir;
    t2 = v->esq;
    t3 = v->dir;

    // Atualizar ponteiros
    v->dir = pivo;
    v->esq = u;
    u->dir = t2;
    pivo->esq = t3;

    // Atualizar o fator de balanço
    if (v->fb == 1)
    {
        pivo->fb = 0;
        u->fb = -1;
    }
    else if (v->fb == -1)
    {
        pivo->fb = 1;
        u->fb = 0;
    }
    else
    {
        pivo->fb = 0;
        u->fb = 0;
    }

    v->fb = 0;

    return v;
}

Arvore rotacao_dupla_esquerda(Arvore pivo)
{
    // Declarar e inicializar os ponteiros
    Arvore u, v, t2, t3;
    u = pivo->dir;
    v = u->esq;
    t2 = v->esq;
    t3 = v->dir;

    // Atualizar ponteiros
    v->dir = u;
    v->esq = pivo;
    pivo->dir = t2;
    u->esq = t3;

    // Atualizar o fator de balanço
    if (v->fb == 1)
    {
        pivo->fb = -1;
        u->fb = 0;
    }
    else if (v->fb == -1)
    {
        pivo->fb = 0;
        u->fb = 1;
    }
    else
    {
        pivo->fb = 0;
        u->fb = 0;
    }

    v->fb = 0;

    return v;
}

void pre_order(Arvore raiz)
{
    if (raiz == NULL)
    {
        // caso base, "imprimir" uma árvore vazia = não fazer nada
    }
    else
    {
        printf("[%d | %d]", raiz->valor, raiz->fb);
        pre_order(raiz->esq);
        pre_order(raiz->dir);
    }
}

// retorna o maior valor entre os dois inteiros passados como parâmetro
int maximo(int a, int b)
{
    return (a > b) ? a : b;
}

Arvore remover(Arvore raiz, T_ELEM valor, int *diminuiu)
{
    if (raiz == NULL)
    {
        return NULL;
    }
    else
    {
        if (raiz->valor == valor)
        {
            // caso 1 - Zero Filhos
            if (raiz->esq == NULL && raiz->dir == NULL)
            {
                free(raiz);
                *diminuiu = 1;
                return NULL;
            }
            // caso 2a - Exatamente um filho esquerdo
            if (raiz->esq != NULL && raiz->dir == NULL)
            {
                Arvore filhoEsq = raiz->esq;
                free(raiz);
                *diminuiu = 1;
                return filhoEsq;
            }
            // caso 2b - Exatamente um filho direito
            if (raiz->esq == NULL && raiz->dir != NULL)
            {
                Arvore filhoDir = raiz->dir;
                free(raiz);
                *diminuiu = 1;
                return filhoDir;
            }
            // caso 3 - Possui 2 filhos não nulos
            if (raiz->esq != NULL && raiz->dir != NULL)
            {
                raiz->valor = maiorElemento(raiz->esq);
                raiz->esq = remover(raiz->esq, raiz->valor, diminuiu);
                // ajuste do FB e chamada da rotação
                if (*diminuiu)
                {
                    switch (raiz->fb)
                    {
                    case -1:
                        raiz->fb = 0;
                        *diminuiu = 1;
                        break;
                    case 0:
                        raiz->fb = +1;
                        *diminuiu = 0;
                        break;
                    case +1:
                        raiz->fb = +2;
                        return rotacao(raiz, diminuiu);
                        break;
                    }
                }
            }
            return raiz;
        }

        else
        {
            if (valor > raiz->valor)
            {
                raiz->dir = remover(raiz->dir, valor, diminuiu);
                // ajuste do FB e chamada da rotação
                if (*diminuiu)
                {
                    switch (raiz->fb)
                    {
                    case -1:
                        raiz->fb = -2;
                        return rotacao(raiz, diminuiu);
                        break;
                    case 0:
                        raiz->fb = -1;
                        *diminuiu = 0;
                        break;
                    case +1:
                        raiz->fb = 0;
                        *diminuiu = 1;
                        break;
                    }
                }
            }
            else
            {
                raiz->esq = remover(raiz->esq, valor, diminuiu);
                // ajuste do FB e chamada da rotação
                if (*diminuiu)
                {
                    switch (raiz->fb)
                    {
                    case -1:
                        raiz->fb = 0;
                        *diminuiu = 1;
                        break;
                    case 0:
                        raiz->fb = +1;
                        *diminuiu = 0;
                        break;
                    case +1:
                        raiz->fb = +2;
                        return rotacao(raiz, diminuiu);
                        break;
                    }
                }
            }
            return raiz;
        }
        return raiz;
    }
}

int maiorElemento(Arvore raiz)
{
    Arvore temp = raiz;
    while (temp->dir != NULL)
    {
        temp = temp->dir;
    }
    if (temp != NULL)
        return temp->valor;
    else
        return -1;
}

Arvore limpar(Arvore raiz)
{
    if (raiz != NULL)
    {
        // limpa esquerda
        limpar(raiz->esq);

        // limpa direita
        limpar(raiz->dir);

        // limpa raiz
        free(raiz);
    }

    return NULL;
}
