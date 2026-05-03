#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct lista Lista;
typedef struct no No;

struct lista{
	No *prim;
};

struct no{
	No *prox;
	int item;
};

Lista *criar();
void inserir(Lista *l, int z);
int remover(Lista *l, int z);
int imprimir(Lista *l);
No *busca(Lista *l, int z);
int tamanho(Lista *l);

Lista *criar(){
	Lista *l = (Lista*) malloc(sizeof(Lista));
	if(!l) exit(1);
	l->prim = NULL;

	return l;
}

void inserir(Lista *l, int z){
	No *novo = (No*) malloc(sizeof(No));
	if(!novo) exit(1);
	novo->item = z;
	novo->prox = NULL;

	if(l->prim == NULL){
		l->prim = novo;
	}else{
		No *atual = l->prim;
		while(atual->prox != NULL){
			atual = atual->prox;
		}
		atual->prox = novo;
	}
}

int remover(Lista *l, int z){
	No *atual = l->prim;
	No *anterior = NULL;

	while(atual != NULL){
		if(atual->item == z){
			if(anterior == NULL){
				l->prim = atual->prox;
			}else{
				anterior->prox = atual->prox;
			}
			free(atual);
			return 0;
		}
		anterior = atual;
		atual = atual->prox;
	}

	return 1;
}

int imprimir(Lista *l){
	No *atual = l->prim;
	
	if(atual == NULL) return -1;

	while(atual != NULL){
		printf("%d ", atual->item);
		atual = atual->prox;
	}

	return 0;
}

No *busca(Lista *l, int z){
	No *atual = l->prim;

	if(atual == NULL) return NULL;

	while(atual != NULL){
		if(atual->item == z){
			return atual;
		}else{
			atual = atual->prox;
		}
	}

	return NULL;
}

int tamanho(Lista *l){
	No *atual = l->prim;
	int count=0;

	if(atual == NULL) return 0;

	while(atual != NULL){
		atual = atual->prox;
		count++;
	}

	return count;
}
