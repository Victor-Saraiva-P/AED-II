#include <stdio.h>
#include <stdlib.h>

/* ---------------------------------------------------------
 *  Árvore Rubro‑Negra – rotações corrigidas
 *  Bell (2025‑07‑08)
 * ---------------------------------------------------------*/

typedef enum { PRETO, VERMELHO } Cor;

typedef struct No {
    int valor;
    Cor cor;
    struct No *esquerda, *direita, *pai;
} No;

typedef No *Arvore;

/* ───────── helpers ───────── */
static inline int   eh_raiz      (Arvore n) { return n && !n->pai; }
static inline Arvore pai         (Arvore n) { return n ? n->pai : NULL; }
static inline Arvore avo         (Arvore n) { return pai(pai(n)); }
static inline Arvore tio         (Arvore n) {
    Arvore p = pai(n), a = avo(n);
    if (!a) return NULL;
    return p == a->esquerda ? a->direita : a->esquerda;
}
static inline int   eh_esquerdo  (Arvore n) { return pai(n) && pai(n)->esquerda == n; }
static inline int   eh_direito   (Arvore n) { return pai(n) && pai(n)->direita  == n; }

/* ───────── protótipos ───────── */
void rotacao_simples_esquerda (Arvore *raiz_ref, Arvore pivo);
void rotacao_simples_direita (Arvore *raiz_ref, Arvore pivo);
void rotacao_dupla_esquerda  (Arvore *raiz_ref, Arvore pivo);
void rotacao_dupla_direita   (Arvore *raiz_ref, Arvore pivo);
void verificar               (Arvore *raiz_ref, Arvore n);
void inserir                 (int valor, Arvore *raiz_ref);

/* ───────── rotações ───────── */
void rotacao_simples_esquerda(Arvore *raiz_ref, Arvore pivo)
{
    Arvore u = pivo->direita;           /* filho à direita sobe */
    Arvore p = pai(pivo);               /* pode ser NULL */

    /* liga u ao lugar ocupado pelo pivô */
    if (eh_raiz(pivo)) {
        *raiz_ref = u;
        u->pai = NULL;
    } else {
        if (eh_esquerdo(pivo)) p->esquerda = u; else p->direita = u;
        u->pai = p;
    }

    /* transfere sub‑árvore esquerda de u para a direita do pivô */
    pivo->direita = u->esquerda;
    if (pivo->direita) pivo->direita->pai = pivo;

    /* conecta pivô como filho esquerdo de u */
    u->esquerda = pivo;
    pivo->pai = u;

    /* recoloração conforme CLRS */
    u->cor = PRETO;
    pivo->cor = VERMELHO;
}

void rotacao_simples_direita(Arvore *raiz_ref, Arvore pivo)
{
    Arvore u = pivo->esquerda;          /* filho à esquerda sobe */
    Arvore p = pai(pivo);

    if (eh_raiz(pivo)) {
        *raiz_ref = u;
        u->pai = NULL;
    } else {
        if (eh_esquerdo(pivo)) p->esquerda = u; else p->direita = u;
        u->pai = p;
    }

    /* transfere sub‑árvore direita de u para a esquerda do pivô */
    pivo->esquerda = u->direita;
    if (pivo->esquerda) pivo->esquerda->pai = pivo;

    /* conecta pivô como filho direito de u */
    u->direita = pivo;
    pivo->pai = u;

    u->cor = PRETO;
    pivo->cor = VERMELHO;
}

void rotacao_dupla_esquerda(Arvore *raiz_ref, Arvore pivo)
{
    /* RL →       rotateRight(p->right) + rotateLeft(p) */
    rotacao_simples_direita(raiz_ref, pivo->direita);
    rotacao_simples_esquerda(raiz_ref, pivo);
}

void rotacao_dupla_direita(Arvore *raiz_ref, Arvore pivo)
{
    /* LR →       rotateLeft(p->left)  + rotateRight(p) */
    rotacao_simples_esquerda(raiz_ref, pivo->esquerda);
    rotacao_simples_direita(raiz_ref, pivo);
}

/* ───────── balanceamento após inserção ───────── */
void verificar(Arvore *raiz_ref, Arvore n)
{
    while (!eh_raiz(n) && pai(n)->cor == VERMELHO) {
        if (eh_direito(pai(n))) {               /* caso espelhado – tio à esquerda */
            if (tio(n) && tio(n)->cor == VERMELHO) {
                tio(n)->cor  = PRETO;           /* recoloração */
                pai(n)->cor  = PRETO;
                avo(n)->cor  = VERMELHO;
                n = avo(n);
                continue;
            }
            if (eh_esquerdo(n)) {               /* caso RL → converte em RR */
                rotacao_simples_direita(raiz_ref, pai(n));
                n = pai(n);
            }
            rotacao_simples_esquerda(raiz_ref, avo(n));
        } else {                                /* p->é esquerdo – tio à direita */
            if (tio(n) && tio(n)->cor == VERMELHO) {
                tio(n)->cor  = PRETO;
                pai(n)->cor  = PRETO;
                avo(n)->cor  = VERMELHO;
                n = avo(n);
                continue;
            }
            if (eh_direito(n)) {                /* caso LR → converte em LL */
                rotacao_simples_esquerda(raiz_ref, pai(n));
                n = pai(n);
            }
            rotacao_simples_direita(raiz_ref, avo(n));
        }
    }
}

/* ───────── inserção ───────── */
void inserir(int valor, Arvore *raiz_ref)
{
    Arvore y = NULL;
    Arvore x = *raiz_ref;

    while (x) {
        y = x;
        x = (valor < x->valor) ? x->esquerda : x->direita;
    }

    Arvore z = malloc(sizeof(No));
    z->valor    = valor;
    z->cor      = VERMELHO;
    z->esquerda = z->direita = NULL;
    z->pai      = y;

    if (!y)                 *raiz_ref = z;          /* nova raiz */
    else if (valor < y->valor) y->esquerda = z;
    else                       y->direita  = z;

    verificar(raiz_ref, z);
    (*raiz_ref)->cor = PRETO;
}

/* ───────── demonstração mínima ───────── */
#ifdef DEMO
static void in_order(Arvore n) {
    if (!n) return;
    in_order(n->esquerda);
    printf("%d(%c) ", n->valor, n->cor == PRETO ? 'B' : 'R');
    in_order(n->direita);
}

int main(void)
{
    Arvore raiz = NULL;

    int v[] = {10, 5, 20, 15, 25, 30, 16};
    for (size_t i = 0; i < sizeof v/sizeof v[0]; ++i)
        inserir(v[i], &raiz);

    in_order(raiz);
    putchar('\n');
    return 0;
}
#endif
