#ifndef RB_H
#define RB_H

typedef int T_elemento;

enum Cor
{
	VERMELHO,
	PRETO,
	DUPLO_PRETO
};

typedef struct No
{
	T_elemento valor;
	enum Cor cor;
	struct No *pai;
	struct No *esquerda;
	struct No *direita;

} No;

typedef No *Arvore;

Arvore inicializar(void);
void inserir(int valorInserir, Arvore *raiz);
void pre_order(Arvore raiz);
void in_order(Arvore raiz);
void pos_order(Arvore raiz);
Arvore limpar(Arvore raiz);

// funções auxiliares
void verificar(Arvore filho);
int eh_raiz(Arvore raiz);
int eh_direito(Arvore filho);
int eh_esquerdo(Arvore filho);

void rotacao_simples_esquerda(Arvore pivo, int dupla);
void rotacao_dupla_esquerda(Arvore pivo);
void rotacao_simples_direita(Arvore pivo, int dupla);

Arvore pai(Arvore filho);
Arvore irmao(Arvore filho);
Arvore tio(Arvore filho);
Arvore avo(Arvore filho);

#endif
