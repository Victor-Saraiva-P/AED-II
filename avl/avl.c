//implementação das funções

#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

//Implementação recursiva
arvore inserir(arvore raiz, T_ELEM valor, int *cresceu){
    //Caso base: instância mais simples do problema
    //Inserir em uma árvore vazia
    if(raiz == NULL) {
        //Alocar memória
        arvore novo_no = (arvore) malloc(sizeof(no));
        //Inicializar variáveis membro
        novo_no->valor = valor;
        novo_no->esq = NULL;
        novo_no->dir = NULL;
        novo_no->fb = 0;
        //retornar a (sub)árvore atualizada
        //Cresceu Retornar para chamada anterior
        *cresceu = 1;
        return novo_no;
    } else {
        //Caso recursivo -> Um passo em direção ao caso base
        //Decidir se vamos para sub-arvore esquerda ou direita
        if(valor > raiz->valor) {
              //chamada recursiva
              raiz->dir = inserir(raiz->dir, valor, cresceu);   
              //Atualizar FB
              if(*cresceu) {
                    switch(raiz->fb) {
                        case -1:
                            raiz->fb = 0;
                            *cresceu = 0;
                            break;
                        case 0:
                            raiz->fb = 1;
                            *cresceu = 1;
                            break;
                        case 1:
                        	raiz->fb = 2;
                            *cresceu = 0;
                            return rotacao(raiz);
                   }    
              }
        } else {
              raiz->esq = inserir(raiz->esq, valor, cresceu);
              //Atualizar FB
              if(*cresceu) {
                    switch(raiz->fb) {
                        case -1:
                        	raiz->fb = -2;
                            *cresceu = 0;
                            return rotacao(raiz);
                        case 0:
                            raiz->fb = -1;
                            *cresceu = 1;
                            break;
                        case 1:
                            raiz->fb = 0;
                            *cresceu = 0;
                            break;
                    }    
              }
        }
        return raiz;
    }
}

arvore rotacao(arvore pivo) {
    // rotação esquerda
    if(pivo->fb == 2) {
        arvore u = pivo->dir;
        
        if(u == NULL){
        }
        
        // rotação simples esquerda
        if(u->fb >= 0) {
            return rotacao_simples_esquerda(pivo);
        }
        // rotação dupla esquerda
        else{
        	//return rotacao_dupla_esquerda(pivo);
        }
    }
    //rotação direita
    else {
    	arvore u = pivo->esq;
    	
    	// rotação simples direita
    	if(u->fb <= 0){
    		return rotacao_simples_direita(pivo);
    	}
    	// rotação dupla direita
    	else{
    		// return rotacao_dupla_direita(pivo);
    	}
    }
    return pivo;
}

/*
Antes
       p(+2)
      /    \
     t1     u(0, +1)
           /  \
          t2  t3
Após
       | (return)
       u
     /   \-
    p    t3
  -/ \
  t1  t2
*/
arvore rotacao_simples_esquerda(arvore pivo) {
    //Declarar e inicializar os ponteiros
    arvore u, t2;
    u = pivo->dir;
    t2 = u->esq;

    //Atualizar ponteiros
    u->esq = pivo;
    pivo->dir = t2;

    //Atualizar o fator de balanço
    if(u->fb == 1) {
        pivo->fb = 0;
        u->fb = 0;
    } else {
        pivo->fb = 1;
        u->fb = -1;
    }
    return u;
}

arvore rotacao_simples_direita(arvore pivo){
	//Declarar e inicializar os ponteiros
	arvore u, t2;
	u = pivo->esq;
	t2 = u->dir;
			
	//Atualizar ponteiros
	u->dir = pivo;
	pivo->esq = t2;
	
	//Atualizar o fator de balanço
    if(u->fb == -1) {
        pivo->fb = 0;
        u->fb = 0;
    } else {
        pivo->fb = -1;
        u->fb = -1;
    }
	
	return u;
}

void pre_order(arvore raiz){
    if(raiz == NULL) {
        //caso base, "imprimir" uma árvore vazia = não fazer nada
    } else {
        printf("[%d | %d]", raiz->valor, raiz->fb);
        pre_order(raiz->esq);
        pre_order(raiz->dir);
    }
}

//retorna o maior valor entre os dois inteiros passados como parâmetro
int maximo(int a, int b){
    return (a > b)? a: b;
}

//Calcular recursivamente a altura da árvore (retorno)
int altura(arvore raiz){
    //caso base
    if(raiz == NULL) {
        return 0;
    } else {
        return 1 + maximo(altura(raiz->esq), altura(raiz->dir));
    }
}

arvore remover(arvore raiz, T_ELEM valor){
    if(raiz == NULL) {
        return NULL;
    } else {
        if(raiz->valor == valor) {
            //caso 1 - Zero Filhos
            if(raiz->esq == NULL && raiz->dir == NULL) {
                free(raiz);
                return NULL;
            } 
            //caso 2a - Exatamente um filho esquerdo
            if(raiz->esq != NULL && raiz->dir == NULL) {
                arvore filhoEsq = raiz->esq;
                free(raiz); 
                return filhoEsq;
                
            }
            //caso 2b - Exatamente um filho direito
            if(raiz->esq == NULL && raiz->dir != NULL) {
                arvore filhoDir = raiz->dir;
                free(raiz); 
                return filhoDir;     
            }
            //caso 3 - Possui 2 filhos não nulos
            if(raiz->esq != NULL && raiz->dir != NULL) {
                raiz->valor = maiorElemento(raiz->esq);
                raiz->esq = remover(raiz->esq, raiz->valor);
                return raiz;
            }
        } else {
            if(valor > raiz->valor) {
                raiz->dir = remover(raiz->dir, valor);
            } else {
                raiz->esq = remover(raiz->esq, valor);
            }
            return raiz; 
        }
   }
   return raiz;
}

int maiorElemento(arvore raiz) {
    arvore temp = raiz;
    while(temp->dir != NULL) {
        temp = temp->dir;
    }
    if(temp!=NULL)
        return temp->valor;
    else
        return -1;
}

arvore limpar(arvore raiz){
	if (raiz != NULL)
	{
		// limpa esquerda
		limpar(raiz->esq);
		
		// limpa direita
		limpar(raiz->dir);
		
		// limpa raiz
		free(raiz);
	}
	
	return NULL;
}



