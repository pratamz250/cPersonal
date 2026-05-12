#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int n[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int ans = 0;

	pid_t pid = fork();

	if(pid == 0){
		for(int i=0; i<10; i++){
			ans += n[i];
		}
		printf("Soma: %d\n", ans);
	}else if(pid < 0){
		perror("Erro");
		return 1;
	}else{
		wait(NULL);
		printf("Soma: %d\n", ans);
	}

	printf("\n");
	return 0;
}
