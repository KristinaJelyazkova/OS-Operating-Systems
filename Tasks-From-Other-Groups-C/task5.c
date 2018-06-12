#include<stdio.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
	printf("pid = %d, ppid = %d\n", getpid(), getppid());
	if(fork()){
		printf("pid = %d\n", getpid());
		int status;
		wait(&status);
		printf("%d\n", WEXITSTATUS(status));
	}
	else{
		int status = execlp("ps", "ps", NULL);
		exit(status);
	}
}
