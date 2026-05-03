#ifndef LISTA_H
#define LISTA_h

typedef struct lista Lista;
typedef struct no No;

Lista *criar();
void inserir(Lista *l, int z);
int remover(Lista *l, int z);
int imprimir(Lista *l);
No *busca(Lista *l, int z);
int tamanho(Lista *l);

#endif
