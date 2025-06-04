#ifndef BST_H
#define BST_H

typedef int T_elemento;

typedef struct No {
  T_elemento valor;
  struct No *esquerda;
  struct No *direita;
} No;

typedef No* Arvore;

Arvore inicializar(void);
Arvore inserir(int valorInserir, Arvore raiz);
void pre_order(Arvore raiz);
void in_order(Arvore raiz);
void pos_order(Arvore raiz);
void reverso(Arvore raiz);
int qtd_folhas(Arvore raiz);
int sucessor(int n, Arvore raiz);
int pai(int n, Arvore raiz);
Arvore remover(int n_remover, Arvore raiz);
int soma_intervalo(int a, int b, Arvore raiz);
Arvore limpar(Arvore raiz);
Arvore multiplicar_por(Arvore raiz, int n);
int busca(int chave_procura, Arvore raiz);
void descendentes(int n, Arvore raiz);
#endif
