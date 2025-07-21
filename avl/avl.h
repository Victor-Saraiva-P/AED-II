// Definição de structs e funções
#ifndef AVL_H
#define AVL_H

typedef int T_ELEM;

typedef struct No_alv
{
    T_ELEM valor;
    int fb;
    struct No_alv *esq, *dir;
} No_alv;

typedef struct No_alv *Arvore;

Arvore inserir(Arvore raiz, T_ELEM valor, int *cresceu);
Arvore remover(Arvore raiz, T_ELEM valor, int *diminuiu);
int maiorElemento(Arvore raiz);

void pre_order(Arvore raiz);
int maximo(int a, int b);
int altura(Arvore raiz);
Arvore rotacao(Arvore pivo, int *diminuiu);
Arvore rotacao_simples_esquerda(Arvore pivo);
Arvore rotacao_simples_direita(Arvore pivo);
Arvore rotacao_dupla_direita(Arvore pivo);
Arvore rotacao_dupla_esquerda(Arvore pivo);

Arvore limpar(Arvore raiz);

#endif
