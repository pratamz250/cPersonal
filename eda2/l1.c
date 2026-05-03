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

int main(){
	Lista *l = criar();

	for(int i=0; i<=10; i++) inserir(l, i);

	imprimir(l);
	printf("\n");

	No *resultado = busca(l, 2);
	if(resultado == NULL) printf("Nao encontrado\n");
	else printf("%d encontrado\n", resultado->item);

	printf("Tamanho: %d\n", tamanho(l));

	printf("\n");
	return 0;
}
