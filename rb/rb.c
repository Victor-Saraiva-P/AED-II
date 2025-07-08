#include "rb.h"
#include <stdio.h>
#include <stdlib.h>

Arvore inicializar(void) { return NULL; }

void inserir(int valorInserir, Arvore *raiz)
{
	Arvore pai_novo_no = NULL;
	Arvore iterativa = *raiz;

	while (iterativa != NULL)
	{
		pai_novo_no = iterativa;

		// Vai para esquerda
		if (valorInserir < iterativa->valor)
			iterativa = iterativa->esquerda;

		// Vai para direita
		else
			iterativa = iterativa->direita;
	}

	// Inicializa o novo no com malloc
	Arvore novo_no = (Arvore)malloc(sizeof(No));
	novo_no->pai = pai_novo_no;
	novo_no->esquerda = NULL;
	novo_no->direita = NULL;
	novo_no->cor = VERMELHO; // por padrão
	novo_no->valor = valorInserir;

	// eh a raiz
	if (eh_raiz(novo_no))
	{
		novo_no->cor = PRETO; // exceção quando é raiz
		*raiz = novo_no;
		return;
	}
	// eh elemento esquerdo
	else if (valorInserir < pai_novo_no->valor)
	{
		pai_novo_no->esquerda = novo_no;
	}
	// eh elemento direito
	else
	{
		pai_novo_no->direita = novo_no;
	}

	ajustar(novo_no, raiz);
}

void ajustar(Arvore elemento, Arvore *raiz)
{
	while (!eh_raiz(elemento) && pai(elemento)->cor == VERMELHO)
	{
		// caso 01 recolorir
		if (tio(elemento) != NULL)
		{
			if (tio(elemento)->cor == VERMELHO)
			{
				// recolore;
				tio(elemento)->cor = PRETO;
				pai(elemento)->cor = PRETO;

				avo(elemento)->cor = VERMELHO;
				elemento = avo(elemento);
				continue;
			}
		}

		// Define o pivo como o avo do elemento
		Arvore pivo = avo(elemento);

		// caso 2 rotação esquerda
		if (eh_direito(pai(elemento)))
		{
			// rotação simples esquerda
			if (eh_direito(elemento))
			{
				rotacao_simples_esquerda(pivo, raiz, 0);
			}
			else
			{
				// rotação dupla esquerda
				rotacao_dupla_esquerda(pivo, raiz);
			}

			// encerra a verificação
			break;
		}
		// Caso 3 rotação direita
		else
		{
			// rotação simples direita
			if (eh_esquerdo(elemento))
			{
				rotacao_simples_direita(pivo, raiz, 0);
			}
			else
			{
				// rotação dupla direita
				rotacao_dupla_direita(pivo, raiz);
			}

			// encerra a verificação
			break;
		}
	}

	//  sempre pintar a raiz de preto
	(*raiz)->cor = PRETO;
}

void rotacao_simples_esquerda(Arvore pivo, Arvore *raiz, int dupla)
{

	Arvore u = pivo->direita;

	// subir u
	if (!eh_raiz(pivo))
	{	
		if (dupla) (*raiz)->esquerda = u;
		else (*raiz)->direita = u;
		
		u->pai = *raiz;
	}
	else{
		*raiz = u;
	}


	// pivo irá para esquerda do u
	pivo->pai = u;
	pivo->direita = NULL;
	u->esquerda = pivo;

	// recolorir
	u->cor = PRETO;
	pivo->cor = VERMELHO;
}

void rotacao_simples_direita(Arvore pivo, Arvore *raiz, int dupla)
{
	Arvore u = pivo->esquerda;

	// subir u
	if (!eh_raiz(pivo))
	{	
		if (dupla) (*raiz)->direita = u;
		else (*raiz)->esquerda = u;
		
		u->pai = *raiz;
	}
	else{
		*raiz = u;
	}

	// pivo irá para esquerda do u
	pivo->pai = u;
	pivo->esquerda = NULL;
	u->direita = pivo;

	// recolorir
	u->cor = PRETO;
	pivo->cor = VERMELHO;
}

void rotacao_dupla_esquerda(Arvore pivo, Arvore *raiz)
{
	rotacao_simples_direita(pivo->direita, raiz, 1);
	rotacao_simples_esquerda(pivo, raiz, 0);
}

void rotacao_dupla_direita(Arvore pivo, Arvore *raiz)
{
	rotacao_simples_esquerda(pivo->esquerda, raiz, 1);
	rotacao_simples_direita(pivo, raiz, 0);
}


Arvore pai(Arvore filho)
{
	return filho->pai;
}

int eh_raiz(Arvore raiz)
{
	if (pai(raiz) == NULL)
	{
		return 1;
	}
	else
		return 0;
}

int eh_direito(Arvore filho)
{
	if (pai(filho)->valor < filho->valor)
	{
		return 1;
	}

	return 0;
}

int eh_esquerdo(Arvore filho)
{
	if (filho->valor < pai(filho)->valor)
	{
		return 1;
	}

	return 0;
}

Arvore irmao(Arvore filho)
{
	if (eh_direito(filho))
		return pai(filho)->esquerda;
	else
		return pai(filho)->direita;
}

Arvore tio(Arvore filho)
{
	return irmao(pai(filho));
}

Arvore avo(Arvore filho)
{
	return pai(pai(filho));
}

void pre_order(Arvore raiz)
{
	if (raiz != NULL)
	{
		char *nome_cor;
		if (raiz->cor == PRETO)
		{
			nome_cor = "PRETO";
		}
		else if (raiz->cor == VERMELHO)
		{
			nome_cor = "VERMELHO";
		}
		else
		{
			nome_cor = "DUPLO_PRETO";
		}
		printf("[%d | %s]", raiz->valor, nome_cor);

		// percorre a esquerda
		pre_order(raiz->esquerda);

		// percorre a direita
		pre_order(raiz->direita);
	}
}

void in_order(Arvore raiz)
{
	if (raiz != NULL)
	{
		// percorre a esquerda
		in_order(raiz->esquerda);

		// printa a raiz
		printf("[%d]", raiz->valor);

		// percorre a direita
		in_order(raiz->direita);
	}
}

void pos_order(Arvore raiz)
{
	if (raiz != NULL)
	{
		// percorre a esquerda
		pos_order(raiz->esquerda);

		// percorre a direita
		pos_order(raiz->direita);

		// printa a raiz
		printf("[%d]", raiz->valor);
	}
}

Arvore limpar(Arvore raiz)
{
	if (raiz != NULL)
	{
		// limpa esquerda
		limpar(raiz->esquerda);

		// limpa direita
		limpar(raiz->direita);

		// limpa raiz
		free(raiz);
	}

	return NULL;
}
