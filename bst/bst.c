#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

Arvore inicializar(void) { return NULL; }

Arvore inserir(int valorInserir, Arvore raiz) {

  if (raiz == NULL) {
    Arvore novo = (Arvore)malloc(sizeof(No));
    novo->valor = valorInserir;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
  } else if (valorInserir < raiz->valor) {
    raiz->esquerda = inserir(valorInserir, raiz->esquerda);

  } else {
    raiz->direita = inserir(valorInserir, raiz->direita);
  }
  
  return raiz;
}

void pre_order(Arvore raiz) {
  if (raiz != NULL) {
    // printa a raiz
    printf("[%d]", raiz->valor);

    // percorre a esquerda
    pre_order(raiz->esquerda);

    // percorre a direita
    pre_order(raiz->direita);
  }
}

void in_order(Arvore raiz) {
  if (raiz != NULL) {
    // percorre a esquerda
    in_order(raiz->esquerda);

    // printa a raiz
    printf("[%d]", raiz->valor);

    // percorre a direita
    in_order(raiz->direita);
  }
}

void pos_order(Arvore raiz) {
  if (raiz != NULL) {
    // percorre a esquerda
    pos_order(raiz->esquerda);

    // percorre a direita
    pos_order(raiz->direita);

    // printa a raizSS
    printf("[%d]", raiz->valor);
  }
}

void reverso(Arvore raiz) {
  if (raiz != NULL) {
    reverso(raiz->esquerda);

    printf("[%d]", raiz->valor);

    reverso(raiz->direita);
  }
}

int qtd_folhas(Arvore raiz) {
  if (raiz == NULL)
    return 0;

  if (raiz->esquerda == NULL && raiz->direita == NULL)
    return 1;

  return qtd_folhas(raiz->esquerda) + qtd_folhas(raiz->direita);
}
