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

int sucessor(int n, Arvore raiz){
  Arvore temp = raiz;
  Arvore ancestral = NULL;
  
  while (temp != NULL && temp->valor != n){
    if(n < temp->valor){
      ancestral = temp;
    	temp = temp->esquerda;		
    }
    
    else if(temp->valor < n){
    	temp = temp->direita;
    }
  }
  
  if (temp == NULL) return -1;
  if (temp->direita != NULL) return temp->direita->valor;
  if (ancestral != NULL) return ancestral->valor;
  
  return -1;
}

int pai(int n, Arvore raiz){
	if (raiz == NULL) return -1;
	Arvore pai_de_n = NULL;
	Arvore aux = raiz;
	
	
	while (aux != NULL && aux->valor != n){
		pai_de_n = aux;
		if(n < aux->valor){
			aux = aux->esquerda;
		}
		else if(aux->valor < n){
			aux = aux->direita;
		}
	}
	
	if (aux == NULL) return -1;
	if (pai_de_n == NULL) return -1;
	
	return pai_de_n->valor;
}

Arvore remover(int n_remover, Arvore raiz){
	if (raiz != NULL){
		if (n_remover == raiz->valor){
			// caso 1) 0 filhos
			if (raiz->esquerda == NULL && raiz->direita == NULL)
			{
				free(raiz);
				return NULL;
			}	
			
			// caso 2a) filho a esquerda
			if (raiz->direita == NULL){
				Arvore no_esquerdo = raiz->esquerda;
				free(raiz);
				return no_esquerdo;
			}
			
			// caso 2a) filho a direita
			if (raiz->esquerda == NULL){
				Arvore no_direito = raiz->direita;
				free(raiz);
				return no_direito;
			}
			
			// caso 3) filhos nos dois lados
			Arvore maior_esquerda = raiz->esquerda;
			while (maior_esquerda->direita != NULL){
				maior_esquerda = maior_esquerda->direita;
			}
			raiz->valor = maior_esquerda->valor;
			raiz->esquerda = remover(maior_esquerda->valor, raiz->esquerda);
		}
	
		if (n_remover < raiz->valor){
			raiz->esquerda = remover(n_remover, raiz->esquerda);
		}
		else {
			raiz->direita = remover(n_remover, raiz->direita);
		}
	}
	
	return raiz;
}


