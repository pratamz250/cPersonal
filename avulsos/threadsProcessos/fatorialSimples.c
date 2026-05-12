#include <stdio.h>

int main(){
	int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int ans = 1;

	for(int i=0; i<10; i++){
		ans *= v[i];
	}

	printf("Fatorial: %d\n", ans);

	return 0;
}
