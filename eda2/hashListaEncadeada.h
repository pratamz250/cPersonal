#ifndef HASHLISTAENCADEADA_H
#define HASHLISTAENCADEADA_H

typedef struct no No;

typedef struct lista{
	No *prim;
}Lista;

typedef struct no{
	int chave;
	int valor;
	No *prox;
}No;

Lista *criarLista();
void inserirLista(Lista *l, int chave, int valor);
int remover(Lista *l, int chave);
No *buscaLista(Lista *l, int chave);

#endif
