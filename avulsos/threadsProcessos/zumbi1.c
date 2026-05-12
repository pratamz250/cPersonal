#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	pid_t pid = fork();

	if(pid == 0){
		printf("Filho (PID: %d) terminado\n", getpid());
		exit(0);
	}else{
		printf("Pai (PID: %d) dormindo...\n", getpid());
		sleep(30);
	}
	
	return 0;
}
