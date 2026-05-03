#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int funcHash(int chave, int tam){
	return chave % tam;
}

Hash *criarHash(int tam){
	Hash *h = malloc(sizeof(Hash));
	if(!h) exit(1);

	h->tam = tam;
	h->tabela = malloc(sizeof(Lista*) * tam);

	if(!h->tabela) exit(1);

	for(int i=0; i<tam; i++){
		h->tabela[i] = criarLista();
	}

	return h;
}

void inserirHash(Hash *h, int chave, int valor){
	int idx = funcHash(chave, h->tam);

	No *n = buscaLista(h->tabela[idx], chave);

	if(n != NULL){
		n->valor = valor;
		return;
	}

	inserirLista(h->tabela[idx], chave, valor);
}

int buscarHash(Hash *h, int chave, int *valor){
	int idx = funcHash(chave, h->tam);

	No *n = buscaLista(h->tabela[idx], chave);

	if(n == NULL) return 0;

	*valor = n->valor;
	return 1;
}

void removerHash(Hash *h, int chave){
	int idx = funcHash(chave, h->tam);
	remover(h->tabela[idx], chave);
}

void imprimirHash(Hash *h){
	for(int i = 0; i < h->tam; i++){
		printf("[%d]: ", i);

		No *atual = h->tabela[i]->prim;

		if(atual == NULL){
			printf("NULL");
		}

		while(atual != NULL){
			printf("(%d, %d) -> ", atual->chave, atual->valor);
			atual = atual->prox;
		}

		printf("\n");
	}
}
