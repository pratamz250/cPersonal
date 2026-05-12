#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t pid = fork();

	int n = 10;
	while(n--){
		if(pid < 0){
			perror("fork falhou\n");
			return 1;
		}else if(pid == 0){
			printf("Sou o processo FILHO! PID: %d\n", getpid());
			execl("/bin/ls", "ls", NULL);
		}else{
			wait(NULL);
			printf("Pai executado depois do filho! PID: %d, filho: %d\n", getpid(), pid);
		}
	}

	return 0;
}
