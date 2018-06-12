#include<stdio.h>

int main(int argc, char *argv[]){
	for(int i = 1; i < 4; i++){
		if(fork()){
			int status;
			int pid = wait(&status);
			printf("status = %d, pid = %d\n", status, pid);
		}
		else{
			execlp(argv[i], argv[i], NULL);
		}
	}
}
