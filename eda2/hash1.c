#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(){
	Hash *h = criarHash(10);

	for(int i=0; i<10; i++)
		inserirHash(h, i, 121+i);

	inserirHash(h, 12, 131);
	inserirHash(h, 22, 132);

	int resultado;
	if(buscarHash(h, 2, &resultado))
		printf("Encontrado. Valor: %d\n", resultado);
	else
		printf("Nao encontrado\n");

	imprimirHash(h);

	printf("\n");
	return 0;
}
