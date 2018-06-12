#include<stdio.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
	if(fork()){
		int status;
		int Pid = wait(&status);
		printf("Parent: Pid = %d, status = %d\n", Pid, status);
	}
	else{
		execvp(argv[1], &argv[1]);
	}
}
