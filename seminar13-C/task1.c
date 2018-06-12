#include<stdio.h>

int main(int argc, char *argv[]){
	if(fork()){
		int status;
		wait(&status);
		if(status == 0){
			printf("%s\n", argv[1]);
		}
	}
	else{
		execlp(argv[1], argv[1], NULL);
	}
}
