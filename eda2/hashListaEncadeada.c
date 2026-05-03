#include <stdio.h>
#include <stdlib.h>
#include "hashListaEncadeada.h"

Lista *criarLista(){
	Lista *l = malloc(sizeof(Lista));
	if(!l) exit(1);
	l->prim = NULL;

	return l;
}

void inserirLista(Lista *l, int chave, int valor){
	No *novo = malloc(sizeof(No));
	if(!novo) exit(1);

	novo->chave = chave;
	novo->valor = valor;

	novo->prox = l->prim;
	l->prim = novo;
}

int remover(Lista *l, int chave){
	No *atual = l->prim;
	No *anterior = NULL;

	while(atual != NULL){
		if(atual->chave == chave){
			if(anterior == NULL){
				l->prim = atual->prox;
			}else{
				anterior->prox = atual->prox;
			}
			free(atual);
			return 1;
		}
		anterior = atual;
		atual = atual->prox;
	}

	return 0;
}

No *buscaLista(Lista *l, int chave){
	No *atual = l->prim;

	while(atual != NULL){
		if(atual->chave == chave){
			return atual;
		}
		atual = atual->prox;
	}

	return NULL;
}
