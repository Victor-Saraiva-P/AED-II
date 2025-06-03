#ifndef BST_H
#define BST_H

typedef struct Node {
  int num;
  struct Node *esquerda;
  struct Node *direita;
} Node;

Node *inicializar(void);
void inserir(int valorInserir, Node **raiz);
void pre_order(Node *raiz);
void in_order(Node *raiz);
void pos_order(Node *raiz);
void reverso(Node *raiz);
int qtd_folhas(Node *raiz);

#endif
