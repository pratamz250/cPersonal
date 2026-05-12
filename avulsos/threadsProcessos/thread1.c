#include <stdio.h>
#include <pthread.h>

void *funcao(void *arg){
	printf("Thread executando\n");
	return NULL;
}

int main(){
	pthread_t t;

	pthread_create(&t, NULL, funcao, NULL);
	pthread_join(t, NULL);

	printf("\n");
	return 0;
}
