#include<stdio.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
	printf("pid = %d, ppid = %d\n", getpid(), getppid());
	int pid = fork();
	if(pid > 0){
		int status;
		int Pid = wait(&status);
		printf("Parent: Pid = %d, status = %d\n", Pid, status);
		printf("Parent: pid = %d\n", pid);
		printf("Parent: pid = %d, ppid = %d\n", getpid(), getppid());
	}
	else{
		printf("Child: pid = %d\n", pid);
		printf("Child: pid = %d, ppid = %d\n", getpid(), getppid());
	}
}
