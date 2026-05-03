#ifndef HASH_H
#define HASH_H
#include "hashListaEncadeada.h"

typedef struct{
	int tam;
	Lista **tabela;
}Hash;

Hash *criarHash(int tam);
void inserirHash(Hash *h, int chave, int valor);
int buscarHash(Hash *h, int chave, int *valor);
void removerHash(Hash *h, int chave);
void imprimirHash(Hash *h);

#endif
