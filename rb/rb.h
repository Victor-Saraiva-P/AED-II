#ifndef RB_H
#define RB_H

enum Cor
{
	VERMELHO,
	PRETO,
	DUPLO_PRETO
};

typedef int tipo_dado;

typedef struct No_rb
{
	tipo_dado dado;
	enum Cor cor;
	struct No_rb *esq, *dir, *pai;
} No_rb;

typedef No_rb *Arvore;

void inicializar(Arvore *raiz);
void adicionar(int valor, Arvore *raiz);
void inserir_sem_regra(int valor1, int valor2, Arvore *raiz);
void remover(int valor, Arvore *raiz);

int altura(Arvore raiz);
int maior(int a, int b);
int maior_elemento(Arvore raiz);
int menor_elemento(Arvore raiz);
void pre_order(Arvore raiz);
void pos_order(Arvore raiz);
void in_order(Arvore raiz);

void imprimir_elemento(Arvore raiz);
void imprimir(Arvore raiz);

enum Cor cor(Arvore elemento);
void ajustar(Arvore *raiz, Arvore elemento);
void reajustar(Arvore *raiz, Arvore elemento);
void rotacao_simples_direita(Arvore *raiz, Arvore pivo);
void rotacao_simples_esquerda(Arvore *raiz, Arvore pivo);
void rotacao_dupla_direita(Arvore *raiz, Arvore pivo);
void rotacao_dupla_esquerda(Arvore *raiz, Arvore pivo);

int eh_raiz(Arvore elemento);
int eh_filho_esquerdo(Arvore elemento);
int eh_filho_direito(Arvore elemento);
Arvore irmao(Arvore elemento);
Arvore tio(Arvore elemento);

void retira_duplo_preto(Arvore *raiz, Arvore elemento);

Arvore limpar(Arvore raiz);

#endif
