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
	// eh filho esquerdo
	else if (valorInserir < pai_novo_no->valor)
	{
		pai_novo_no->esquerda = novo_no;
	}
	// eh filho direito
	else
	{
		pai_novo_no->direita = novo_no;
	}

	verificar(novo_no);

	// sempre pintar a raiz de preto
	(*raiz)->cor = PRETO;
}

void verificar(Arvore filho)
{
	while (!eh_raiz(filho) && pai(filho)->cor == VERMELHO)
	{
		// caso 01 recolorir
		if (tio(filho) != NULL)
		{
			if (tio(filho)->cor == VERMELHO)
			{
				// recolore;
				tio(filho)->cor = PRETO;
				pai(filho)->cor = PRETO;

				avo(filho)->cor = VERMELHO;
				filho = avo(filho);
			}
		}
	}
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
