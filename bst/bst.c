#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

Node *inicializar(void) { return NULL; }

void inserir(int valorInserir, Node **raiz) {

  if (*raiz == NULL) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->num = valorInserir;
    novo->esquerda = NULL;
    novo->direita = NULL;

    *raiz = novo;

  } else if (valorInserir < (*raiz)->num) {
    inserir(valorInserir, &(*raiz)->esquerda);

  } else {
    inserir(valorInserir, &(*raiz)->direita);
  }
}

void pre_order(Node *raiz) {
  if (raiz != NULL) {
    // printa a raiz
    printf("[%d]", raiz->num);

    // percorre a esquerda
    pre_order(raiz->esquerda);

    // percorre a direita
    pre_order(raiz->direita);
  }
}

void in_order(Node *raiz) {
  if (raiz != NULL) {
    // percorre a esquerda
    in_order(raiz->esquerda);

    // printa a raiz
    printf("[%d]", raiz->num);

    // percorre a direita
    in_order(raiz->direita);
  }
}

void pos_order(Node *raiz) {
  if (raiz != NULL) {
    // percorre a esquerda
    pos_order(raiz->esquerda);

    // percorre a direita
    pos_order(raiz->direita);

    // printa a raiz
    printf("[%d]", raiz->num);
  }
}

void reverso(Node *raiz) {
  if (raiz != NULL) {
    reverso(raiz->direita);

    printf("[%d]", raiz->num);

    reverso(raiz->esquerda);
  }
}

int qtd_folhas(Node *raiz) {
  if (raiz == NULL)
    return 0;

  if (raiz->esquerda == NULL && raiz->direita == NULL)
    return 1;

  return qtd_folhas(raiz->esquerda) + qtd_folhas(raiz->direita);
}
