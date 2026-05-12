#include <stdio.h>
#include <pthread.h>

int ans = 1;

void *fac(void *arg){
	int *v = (int*) arg;

	for(int i=0; i<10; i++)
		ans *= v[i];

	return NULL;
}

int main(){
	int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	pthread_t t;

	pthread_create(&t, NULL, fac, v);
	pthread_join(t, NULL);

	printf("Fatorial: %d\n", ans);

	return 0;
}
