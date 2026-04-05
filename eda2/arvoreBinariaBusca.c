#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
	int dado;
	struct celula *esq, *dir;
}celula;

celula *buscar(celula *raiz, int x);
celula *inserir(celula *raiz, int x);
celula *remover(celula *raiz, int x);
celula *criaABB(int x);
celula *minimo(celula *raiz);
void destroiABB(celula *raiz);

celula *criaABB(int x){
	celula *raiz = malloc(sizeof(celula));
	raiz->esq = raiz->dir = NULL;
	raiz->dado = x;

	return raiz;
}

celula *buscar(celula *raiz, int x){
	if(raiz != NULL){
		if(x < raiz->dado) return buscar(raiz->esq, x);
		else if(x > raiz->dado) return buscar(raiz->dir, x);
		else return raiz;
	}

	return NULL;
}

celula *inserir(celula *raiz, int x){
	if(raiz != NULL){
		if(x < raiz->dado) raiz->esq = inserir(raiz->esq, x);
		else if(x > raiz->dado) raiz->dir = inserir(raiz->dir, x);
		return raiz;
	}

	return criaABB(x);
}

celula *minimo(celula *raiz){
	while(raiz && raiz->esq != NULL)
		raiz = raiz->esq;
	return raiz;
}

celula *remover(celula *raiz, int x){
	if(raiz == NULL) return NULL;

	if(x < raiz->dado){
		raiz->esq = remover(raiz->esq, x);
	} else if(x > raiz->dado){
		raiz->dir = remover(raiz->dir, x);
	} else {
		//Encontrou o nó

		//Caso 1: sem filhos
		if(raiz->esq == NULL && raiz->dir == NULL){
			free(raiz);
			return NULL;
		}

		//Caso 2: um filho
		else if(raiz->esq == NULL){
			celula *temp = raiz->dir;
			free(raiz);
			return temp;
		} else if(raiz->dir == NULL){
			celula *temp = raiz->esq;
			free(raiz);
			return temp;
		}

		//Caso 3: dois filhos
		else {
			celula *temp = minimo(raiz->dir);
			raiz->dado = temp->dado;
			raiz->dir = remover(raiz->dir, temp->dado);
		}
	}

	return raiz;
}

void destroiABB(celula *raiz){
	if(raiz != NULL){
		destroiABB(raiz->esq);
		destroiABB(raiz->dir);
		free(raiz);
	}
}

