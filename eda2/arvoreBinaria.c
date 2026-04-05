#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no *esq, *dir;
}no;

no *criar(int x);
no *inserir(no *raiz, int x);
no *buscar(no *raiz, int x);

void preOrdem(no *raiz);
void emOrdem(no *raiz);
void posOrdem(no *raiz);

int altura(no *raiz);
int contarNos(no *raiz);

void destruir(no *raiz);

no *criar(int x){
	no *novo = (no*) malloc(sizeof(no));
	novo->dado = x;
	novo->esq = novo->dir = NULL;

	return novo;
}

no* inserir(no *raiz, int x){
	if(raiz == NULL){
		exit(1);
	}

	if(raiz->esq == NULL){
		raiz->esq = inserir(raiz->esq, x);
	}else if(raiz->dir == NULL){
		raiz->dir = inserir(raiz->dir, x);
	}else{
		raiz->esq = inserir(raiz->esq, x);
	}

	return raiz;
}

no *buscar(no *raiz, int x){
	if(raiz == NULL) exit(1);

	if(raiz->dado == x) return raiz;

	no *esq = buscar(raiz->esq, x);
	if(esq != NULL) return esq;

	return buscar(raiz->dir, x);
}

void preOrdem(no *raiz){
	if(raiz != NULL){
		printf("%d ", raiz->dado);
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
}

void emOrdem(no *raiz){
	if(raiz != NULL){
		emOrdem(raiz->esq);
		printf("%d ", raiz->dado);
		emOrdem(raiz->dir);
	}
}

void posOrdem(no *raiz){
	if(raiz != NULL){
		posOrdem(raiz->esq);
		posOrdem(raiz->dir);
		printf("%d ", raiz->dado);
	}
}

int altura(no *raiz){
	if(raiz == NULL) return -1;

	int h_esq = altura(raiz->esq);
	int h_dir = altura(raiz->dir);

	return (h_esq > h_dir ? h_esq : h_dir)+1;
}

int contaNos(no *raiz){
	if(raiz == NULL) return 0;

	return contaNos(raiz->esq) + contaNos(raiz->dir) + 1;
}

void destruir(no *raiz){
	if(raiz != NULL){
		destruir(raiz->esq);
		destruir(raiz->dir);
		free(raiz);
	}
}

























































