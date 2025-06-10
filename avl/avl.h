//Definição de structs e funções
#ifndef AVL_H
#define AVL_H

typedef int T_ELEM;

typedef struct no {
    T_ELEM valor;
    int fb;
    struct no *esq, *dir;
} no;

typedef struct no* arvore;

arvore inserir(arvore raiz, T_ELEM valor, int *cresceu);
arvore remover(arvore raiz, T_ELEM valor);
int maiorElemento(arvore raiz);


void pre_order(arvore raiz);
int maximo(int a, int b);
int altura(arvore raiz);
arvore rotacao(arvore pivo);
arvore rotacao_simples_esquerda(arvore pivo);
arvore rotacao_simples_direita(arvore pivo);
arvore limpar(arvore raiz);

#endif
