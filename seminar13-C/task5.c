#include<stdio.h>

int main(int argc, char *argv[]){
	if(fork()){
		int status;
		wait(&status);
		if(status == 0){
			execlp(argv[2], argv[2], 0);
		}
		else{
			exit(54);
		}
	}
	else{
		execlp(argv[1], argv[1], 0);
	}
}
