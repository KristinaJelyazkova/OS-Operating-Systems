#include<stdio.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
	printf("pid = %d, ppid = %d\n", getpid(), getppid());
	int pid = fork();
	if(pid > 0){
		printf("pid = %d\n", pid);
		printf("pid = %d, ppid = %d\n", getpid(), getppid());
	}
	else{
		printf("pid = %d\n", pid);
		printf("pid = %d, ppid = %d\n", getpid(), getppid());
	}
}
