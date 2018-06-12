#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
	int fd = open("file2", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fork()){
		int status;
		wait(&status);
		write(fd, "bar\n", 4);
	}
	else{
		write(fd, "foo", 3);
	}
}
